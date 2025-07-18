
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono> // For time-based piece dropping
#include <thread> // For sleep

// Platform-specific includes for console control
// Using ncurses for cross-platform (macOS/Linux) console operations
#include <ncurses.h> // Or <curses.h> on some systems

// --- Constants ---
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int BLOCK_SIZE = 2; // For drawing, e.g., "[]" per block
const int START_X = 2;    // Console X offset for drawing board
const int START_Y = 2;    // Console Y offset for drawing board

// Colors (using ncurses color pairs)
enum ConsoleColor {
    COLOR_BLACK_ID = 0, // Placeholder, ncurses usually maps 0-7
    COLOR_CYAN_ID,
    COLOR_BLUE_ID,
    COLOR_YELLOW_ID,
    COLOR_MAGENTA_ID,
    COLOR_GREEN_ID,
    COLOR_RED_ID,
    COLOR_DARK_YELLOW_ID, // Use regular YELLOW or a custom pair combination
    // Add more as needed, ensure unique IDs
    COLOR_WHITE_ID // For score, lines, and frame
};

// --- Console Utility Functions (using ncurses) ---
void SetConsoleColor(ConsoleColor console_color_id, ConsoleColor /*background_color_id - ncurses pairs fix background*/) {
    attron(COLOR_PAIR(console_color_id));
}

void GoToXY(int x, int y) {
    move(y, x);
}

void ClearScreen() {
    clear(); // ncurses function to clear the screen
}

// --- Tetromino Definition ---
struct Tetromino {
    // Each piece type has 4 rotations. Each rotation is a 4x4 grid (some shapes fit 3x3)
    std::vector<std::vector<std::vector<int>>> shapes; // [rotation_state][row][col]
    int type; // A numeric ID for the piece type (e.g., 0 for I, 1 for J, etc.)
    int color_id; // ncurses color pair ID associated with the piece type
    int x, y; // Current position (top-left of its 4x4 bounding box)
    int rotationState; // 0, 1, 2, 3

    // Constructor
    Tetromino(int t, int c_id, std::vector<std::vector<std::vector<int>>> s)
        : type(t), color_id(c_id), shapes(s), x(BOARD_WIDTH / 2 - 2), y(0), rotationState(0) {}

    const std::vector<std::vector<int>>& getCurrentShape() const {
        return shapes[rotationState];
    }
};

// All Tetromino definitions (S_SHAPES, J_SHAPES, etc.)
// These are 4x4 matrices representing the block. 1 = block, 0 = empty.

// I-Piece
const std::vector<std::vector<std::vector<int>>> I_SHAPES = {
    {{0,0,0,0}, {1,1,1,1}, {0,0,0,0}, {0,0,0,0}}, // 0 deg
    {{0,0,1,0}, {0,0,1,0}, {0,0,1,0}, {0,0,1,0}}, // 90 deg
    {{0,0,0,0}, {1,1,1,1}, {0,0,0,0}, {0,0,0,0}}, // 180 deg (same as 0)
    {{0,0,1,0}, {0,0,1,0}, {0,0,1,0}, {0,0,1,0}}  // 270 deg (same as 90)
};

// J-Piece
const std::vector<std::vector<std::vector<int>>> J_SHAPES = {
    {{1,0,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}},
    {{0,1,1,0}, {0,1,0,0}, {0,1,0,0}, {0,0,0,0}},
    {{0,0,0,0}, {1,1,1,0}, {0,0,1,0}, {0,0,0,0}},
    {{0,1,0,0}, {0,1,0,0}, {1,1,0,0}, {0,0,0,0}}
};

// L-Piece
const std::vector<std::vector<std::vector<int>>> L_SHAPES = {
    {{0,0,1,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}},
    {{0,1,0,0}, {0,1,0,0}, {0,1,1,0}, {0,0,0,0}},
    {{0,0,0,0}, {1,1,1,0}, {1,0,0,0}, {0,0,0,0}},
    {{1,1,0,0}, {0,1,0,0}, {0,1,0,0}, {0,0,0,0}}
};

// O-Piece
const std::vector<std::vector<std::vector<int>>> O_SHAPES = {
    {{0,1,1,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}},
    {{0,1,1,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}}, // All rotations are same
    {{0,1,1,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}},
    {{0,1,1,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}}
};

// S-Piece
const std::vector<std::vector<std::vector<int>>> S_SHAPES = {
    {{0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}},
    {{1,0,0,0}, {1,1,0,0}, {0,1,0,0}, {0,0,0,0}},
    {{0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}}, // Same as 0
    {{1,0,0,0}, {1,1,0,0}, {0,1,0,0}, {0,0,0,0}}  // Same as 90
};

// T-Piece
const std::vector<std::vector<std::vector<int>>> T_SHAPES = {
    {{0,1,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}},
    {{0,1,0,0}, {0,1,1,0}, {0,1,0,0}, {0,0,0,0}},
    {{0,0,0,0}, {1,1,1,0}, {0,1,0,0}, {0,0,0,0}},
    {{0,1,0,0}, {1,1,0,0}, {0,1,0,0}, {0,0,0,0}}
};

// Z-Piece
const std::vector<std::vector<std::vector<int>>> Z_SHAPES = {
    {{1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}},
    {{0,0,1,0}, {0,1,1,0}, {0,1,0,0}, {0,0,0,0}},
    {{1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}}, // Same as 0
    {{0,0,1,0}, {0,1,1,0}, {0,1,0,0}, {0,0,0,0}}  // Same as 90
};


// --- Game State and Logic ---
std::vector<std::vector<int>> board_grid(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0));
Tetromino* currentPiece = nullptr;
Tetromino* nextPiece = nullptr;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> pieceDist(0, 6); // 7 types of pieces

long long score = 0;
int linesCleared = 0;
bool gameOver = false;
int fallSpeedMs = 500; // Milliseconds per square drop

// Function to create a random Tetromino
Tetromino* createRandomPiece() {
    int type = pieceDist(gen);
    switch (type) {
        case 0: return new Tetromino(0, COLOR_CYAN_ID, I_SHAPES); // I
        case 1: return new Tetromino(1, COLOR_BLUE_ID, J_SHAPES);    // J
        case 2: return new Tetromino(2, COLOR_YELLOW_ID, L_SHAPES);   // L
        case 3: return new Tetromino(3, COLOR_MAGENTA_ID, O_SHAPES); // O
        case 4: return new Tetromino(4, COLOR_GREEN_ID, S_SHAPES);   // S
        case 5: return new Tetromino(5, COLOR_RED_ID, T_SHAPES);     // T
        case 6: return new Tetromino(6, COLOR_DARK_YELLOW_ID, Z_SHAPES); // Z
        default: return nullptr;
    }
}

// Check if a piece can move to a new position/rotation
bool checkCollision(const Tetromino& piece, int dx, int dy, const std::vector<std::vector<int>>& newShape) {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (newShape[r][c] != 0) { // If it's a block
                int boardX = piece.x + c + dx;
                int boardY = piece.y + r + dy;

                // Check boundaries
                if (boardX < 0 || boardX >= BOARD_WIDTH || boardY >= BOARD_HEIGHT) {
                    return true; // Collision with wall or bottom
                }
                // Check collision with existing blocks on board (only if within vertical bounds)
                if (boardY >= 0 && board_grid[boardY][boardX] != 0) {
                    return true; // Collision with existing block
                }
            }
        }
    }
    return false; // No collision
}

// Lock the current piece onto the board
void lockPiece() {
    const auto& shape = currentPiece->getCurrentShape();
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (shape[r][c] != 0) {
                int boardX = currentPiece->x + c;
                int boardY = currentPiece->y + r;
                if (boardY >= 0 && boardY < BOARD_HEIGHT && boardX >= 0 && boardX < BOARD_WIDTH) { // Ensure within bounds
                    board_grid[boardY][boardX] = currentPiece->color_id;
                }
            }
        }
    }
}

// Clear full lines and shift blocks down
void clearLines() {
    int linesClearedThisTurn = 0;
    for (int r = BOARD_HEIGHT - 1; r >= 0; --r) {
        bool fullLine = true;
        for (int c = 0; c < BOARD_WIDTH; ++c) {
            if (board_grid[r][c] == 0) {
                fullLine = false;
                break;
            }
        }

        if (fullLine) {
            linesClearedThisTurn++;
            // Shift all lines above down
            for (int r2 = r; r2 > 0; --r2) {
                for (int c = 0; c < BOARD_WIDTH; ++c) {
                    board_grid[r2][c] = board_grid[r2 - 1][c];
                }
            }
            // Clear the very top line
            for (int c = 0; c < BOARD_WIDTH; ++c) {
                board_grid[0][c] = 0;
            }
            r++; // Check the new line at this row position again
        }
    }

    if (linesClearedThisTurn > 0) {
        // Scoring (e.g., 100 per line, bonus for multiple lines)
        switch (linesClearedThisTurn) {
            case 1: score += 100; break;
            case 2: score += 300; break;
            case 3: score += 500; break;
            case 4: score += 800; break; // Tetris!
        }
        linesCleared += linesClearedThisTurn;

        // Increase difficulty (fall speed)
        if (linesCleared % 10 == 0 && fallSpeedMs > 100) { // Every 10 lines
            fallSpeedMs -= 50;
        }
    }
}

// --- Drawing Functions ---
void drawBlock(int x, int y, int color_id) {
    GoToXY(START_X + x * BLOCK_SIZE, START_Y + y);
    SetConsoleColor((ConsoleColor)color_id, COLOR_BLACK_ID);
    printw("[]"); // ncurses equivalent of std::cout << "[]"
    attroff(COLOR_PAIR(color_id)); // Turn off color after drawing
}

void drawEmptyBlock(int x, int y) {
    GoToXY(START_X + x * BLOCK_SIZE, START_Y + y);
    SetConsoleColor(COLOR_WHITE_ID, COLOR_BLACK_ID); // Default color for empty space, or specific empty pair
    printw("  ");
    attroff(COLOR_PAIR(COLOR_WHITE_ID)); // Turn off color after drawing
}

void drawBoard() {
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            if (board_grid[y][x] != 0) {
                drawBlock(x, y, board_grid[y][x]);
            } else {
                drawEmptyBlock(x, y);
            }
        }
    }
}

void drawCurrentPiece() {
    const auto& shape = currentPiece->getCurrentShape();
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (shape[r][c] != 0) {
                drawBlock(currentPiece->x + c, currentPiece->y + r, currentPiece->color_id);
            }
        }
    }
}

void eraseCurrentPiece() {
    const auto& shape = currentPiece->getCurrentShape();
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (shape[r][c] != 0) {
                // Only erase if it's within the board boundaries, to avoid writing outside
                if (currentPiece->x + c >= 0 && currentPiece->x + c < BOARD_WIDTH &&
                    currentPiece->y + r >= 0 && currentPiece->y + r < BOARD_HEIGHT) {
                    drawEmptyBlock(currentPiece->x + c, currentPiece->y + r);
                }
            }
        }
    }
}

void drawFrame() {
    SetConsoleColor(COLOR_WHITE_ID, COLOR_BLACK_ID);

    // Top border
    GoToXY(START_X - 1, START_Y - 1);
    printw("+");
    for (int i = 0; i < BOARD_WIDTH * BLOCK_SIZE; ++i) printw("-");
    printw("+");

    // Side borders
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        GoToXY(START_X - 1, START_Y + y);
        printw("|");
        GoToXY(START_X + BOARD_WIDTH * BLOCK_SIZE, START_Y + y);
        printw("|");
    }

    // Bottom border
    GoToXY(START_X - 1, START_Y + BOARD_HEIGHT);
    printw("+");
    for (int i = 0; i < BOARD_WIDTH * BLOCK_SIZE; ++i) printw("-");
    printw("+");

    attroff(COLOR_PAIR(COLOR_WHITE_ID)); // Turn off color
}

void drawScoreAndInfo() {
    SetConsoleColor(COLOR_WHITE_ID, COLOR_BLACK_ID);

    GoToXY(START_X + BOARD_WIDTH * BLOCK_SIZE + 5, START_Y);
    printw("Score: %lld", score);

    GoToXY(START_X + BOARD_WIDTH * BLOCK_SIZE + 5, START_Y + 1);
    printw("Lines: %d", linesCleared);

    GoToXY(START_X + BOARD_WIDTH * BLOCK_SIZE + 5, START_Y + 2);
    printw("Speed: %dms", fallSpeedMs);

    GoToXY(START_X + BOARD_WIDTH * BLOCK_SIZE + 5, START_Y + 4);
    printw("Next Piece:");

    // Draw next piece
    if (nextPiece) {
        for (int r = 0; r < 4; ++r) {
            for (int c = 0; c < 4; ++c) {
                GoToXY(START_X + BOARD_WIDTH * BLOCK_SIZE + 5 + c * BLOCK_SIZE, START_Y + 5 + r);
                if (nextPiece->getCurrentShape()[r][c] != 0) {
                    SetConsoleColor((ConsoleColor)nextPiece->color_id, COLOR_BLACK_ID);
                    printw("[]");
                    attroff(COLOR_PAIR(nextPiece->color_id));
                } else {
                    printw("  "); // Empty block
                }
            }
        }
    }
    attroff(COLOR_PAIR(COLOR_WHITE_ID)); // Turn off color
}


void drawGameOver() {
    SetConsoleColor(COLOR_RED_ID, COLOR_BLACK_ID);
    GoToXY(START_X + BOARD_WIDTH / 2 * BLOCK_SIZE - 5, START_Y + BOARD_HEIGHT / 2);
    printw("GAME OVER!");
    GoToXY(START_X + BOARD_WIDTH / 2 * BLOCK_SIZE - 9, START_Y + BOARD_HEIGHT / 2 + 1);
    printw("Final Score: %lld", score);
    attroff(COLOR_PAIR(COLOR_RED_ID)); // Turn off color
}


// --- Game Initialization & Loop ---
void initializeGame() {
    // ncurses initialization
    initscr();           // Start curses mode
    noecho();            // Don't echo input characters
    cbreak();            // Line buffering disabled, Pass every key press to program, no wait for Enter
    keypad(stdscr, TRUE); // Enable special keys (like arrow keys)
    curs_set(0);         // Hide the cursor

    // Initialize colors
    if (has_colors()) {
        start_color();
        init_pair(COLOR_WHITE_ID, COLOR_WHITE, COLOR_BLACK);
        init_pair(COLOR_CYAN_ID, COLOR_CYAN, COLOR_BLACK);
        init_pair(COLOR_BLUE_ID, COLOR_BLUE, COLOR_BLACK);
        init_pair(COLOR_YELLOW_ID, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COLOR_MAGENTA_ID, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(COLOR_GREEN_ID, COLOR_GREEN, COLOR_BLACK);
        init_pair(COLOR_RED_ID, COLOR_RED, COLOR_BLACK);
        init_pair(COLOR_DARK_YELLOW_ID, COLOR_YELLOW, COLOR_BLACK); // ncurses might not have DARK_YELLOW, use YELLOW
    } else {
        // Fallback for terminals that don't support colors
        // You might want to print a message to stderr or exit.
    }

    ClearScreen();
    // Initialize board
    for (int r = 0; r < BOARD_HEIGHT; ++r) {
        for (int c = 0; c < BOARD_WIDTH; ++c) {
            board_grid[r][c] = 0;
        }
    }
    score = 0;
    linesCleared = 0;
    gameOver = false;
    currentPiece = nullptr;
    nextPiece = nullptr;
    fallSpeedMs = 500;

    // Initial draw of static elements
    drawFrame();
    drawScoreAndInfo(); // Initial info
    drawBoard(); // Initial empty board
    refresh(); // Update the screen
}

void cleanupGame() {
    delete currentPiece;
    delete nextPiece;
    currentPiece = nullptr;
    nextPiece = nullptr;

    endwin(); // End curses mode, restore terminal
}

int main() {
    initializeGame();

    std::chrono::high_resolution_clock::time_point lastFallTime = std::chrono::high_resolution_clock::now();

    currentPiece = createRandomPiece();
    nextPiece = createRandomPiece(); // Pre-spawn next piece

    // Game Loop
    while (!gameOver) {
        // Set timeout for getch(). This makes getch() non-blocking and defines the minimum loop interval.
        // We use a small timeout (e.g., 50ms) to ensure responsiveness,
        // and manage automatic fall separately with chrono.
        timeout(50); // getch will wait 50ms for input, then return ERR

        int ch = getch(); // Get input, potentially blocking for 'timeout' ms

        // --- 1. Handle Input ---
        if (ch != ERR) { // If a key was pressed
            eraseCurrentPiece(); // Erase old position before moving/rotating

            switch (ch) {
                case KEY_LEFT:
                    if (!checkCollision(*currentPiece, -1, 0, currentPiece->getCurrentShape())) {
                        currentPiece->x--;
                    }
                    break;
                case KEY_RIGHT:
                    if (!checkCollision(*currentPiece, 1, 0, currentPiece->getCurrentShape())) {
                        currentPiece->x++;
                    }
                    break;
                case KEY_DOWN: // Soft drop
                    // Reset timer for immediate drop and next fall
                    lastFallTime = std::chrono::high_resolution_clock::now();
                    if (!checkCollision(*currentPiece, 0, 1, currentPiece->getCurrentShape())) {
                        currentPiece->y++;
                    } else {
                        // Piece landed, lock it
                        lockPiece();
                        clearLines();
                        delete currentPiece;
                        currentPiece = nextPiece;
                        nextPiece = createRandomPiece();
                        if (checkCollision(*currentPiece, 0, 0, currentPiece->getCurrentShape())) {
                            gameOver = true; // New piece spawns in collision -> Game Over
                        }
                    }
                    break;
                case KEY_UP: // Rotate
                    {
                        int originalRotation = currentPiece->rotationState;
                        currentPiece->rotationState = (currentPiece->rotationState + 1) % 4;
                        if (checkCollision(*currentPiece, 0, 0, currentPiece->getCurrentShape())) {
                            currentPiece->rotationState = originalRotation; // Revert if collision
                        }
                    }
                    break;
                case ' ': // Spacebar (Hard drop)
                    // Erase before drops
                    while (!checkCollision(*currentPiece, 0, 1, currentPiece->getCurrentShape())) {
                        currentPiece->y++;
                    }
                    // Piece landed after hard drop
                    lockPiece();
                    clearLines();
                    delete currentPiece;
                    currentPiece = nextPiece;
                    nextPiece = createRandomPiece();
                    if (checkCollision(*currentPiece, 0, 0, currentPiece->getCurrentShape())) {
                        gameOver = true; // New piece spawns in collision -> Game Over
                    }
                    lastFallTime = std::chrono::high_resolution_clock::now(); // Reset fall timer
                    break;
                case 27: // ESC key
                    gameOver = true; // Exit game
                    break;
            }
            // Redraw everything that might have changed due to input
            drawBoard(); // Redraw static blocks after piece might have been locked
            drawCurrentPiece(); // Redraw piece in new position
            drawScoreAndInfo(); // Update info display (next piece might have changed)
        }

        // --- 2. Automatic Fall ---
        auto currentTime = std::chrono::high_resolution_clock::now();
        long long duration = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastFallTime).count();

        if (duration >= fallSpeedMs) {
            eraseCurrentPiece(); // Erase old position
            if (!checkCollision(*currentPiece, 0, 1, currentPiece->getCurrentShape())) {
                currentPiece->y++; // Move down
            } else {
                // Piece landed, lock it
                lockPiece();
                clearLines(); // Check and clear lines
                delete currentPiece; // Delete old piece
                currentPiece = nextPiece; // Set next piece as current
                nextPiece = createRandomPiece(); // Spawn new next piece
                
                // Check for game over
                if (!currentPiece || checkCollision(*currentPiece, 0, 0, currentPiece->getCurrentShape())) {
                    gameOver = true;
                }
            }
            // Redraw everything that might have changed due to automatic fall
            drawBoard(); // Redraw static blocks after piece might have been locked
            drawCurrentPiece(); // Redraw piece in new position
            drawScoreAndInfo(); // Update info display (next piece might have changed)
            lastFallTime = currentTime; // Reset timer
        }

        // --- 3. Render ---
        refresh(); // Update the physical screen with buffered changes
    }
    
    // Game Over screen
    drawGameOver();
    refresh(); // Make sure game over message is shown
    
    // Wait for a key press before exiting after game over
    timeout(-1); // Make getch() block indefinitely
    getch(); // Wait for any key press

    cleanupGame(); // Restore terminal settings
    return 0;
}
