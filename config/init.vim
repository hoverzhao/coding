set exrc
set relativenumber
set nu
set nohlsearch
set hidden
set noerrorbells
set tabstop=4 softtabstop=4
set shiftwidth=4
" set expandtab
" set list
set smartindent
set nowrap
set noswapfile
set nobackup
set undodir=~/.vim/undodir
set undofile
set incsearch
"set termguicolors
set noshowmode
" --------------------
" set completeopt=menuone,noinsert,noselect
" --------------------
" ++++++++++++++++++++
set ignorecase
" ++++++++++++++++++++
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936,big5
set termencoding=utf-8
set encoding=utf-8

set signcolumn=yes
set updatetime=50
set shortmess+=c
set encoding=utf-8

set foldmethod=marker
" set foldmethod=indent
set foldlevelstart=1


if has("patch-8.1.1564")
  set signcolumn=number
else
  set signcolumn=yes
endif

call plug#begin('~/.vim/plugged')

" Plug 'nvim-lua/popup.nvim'
" Plug 'nvim-lua/plenary.nvim'
" Plug 'nvim-telescope/telescope.nvim'

Plug 'morhetz/gruvbox'

Plug 'fatih/vim-go'
" Plug 'neoclide/coc.nvim', {'branch': 'release'}

Plug 'junegunn/fzf', { 'do': { -> fzf#install() }}
Plug 'junegunn/fzf.vim'

Plug 'voldikss/vim-translator'
" Plug 'yianwillis/vimcdoc'
Plug 'rhysd/devdocs.vim'
Plug 'rizzatti/dash.vim'

Plug 'tpope/vim-commentary'
" Plug 'tpope/vim-surround'
" Plug 'jiangmiao/auto-pairs'
" Plug 'michaeljsmith/vim-indent-object'
" Plug 'justinmk/vim-sneak'

call plug#end()
let g:solarized_use16=1
set background=dark
colorscheme solarized8_flat
" colorscheme gruvbox
"
" hi HighlightedyankRegion cterm=bold gui=bold ctermbg=0 guibg=#13354A
" highlight Normal guibg=none
"mode lhs rhs
let mapleader = " "
nnoremap <leader>rc :vsp $MYVIMRC<CR>
nnoremap <leader>rs :so $MYVIMRC<CR>
nnoremap <leader>rr :vsp ~/ml.sh<CR>
nnoremap <leader>rt :vsp	 ~/.config/nvim/templates/skeleton.c<CR>
nnoremap <leader>ry <leader>y ggVG"+y'' 

nnoremap <leader>w :w!<CR>
set pastetoggle=<F2>
" Searching
" vnoremap / /\v
" Move up/down editor lines
nnoremap j gj
nnoremap k gk
" noremap H ^
" noremap L g_
" noremap p p=`]
inoremap jk <esc>
" inoremap <c-j> <esc>
nnoremap n nzz
nnoremap N Nzz
nnoremap * *zz
nnoremap # #zz
nnoremap g* g*zz
nnoremap g# g#zz
"=====================ACM=======================

if !exists("g:os")
    if has("win64") || has("win32") || has("win16")
        let g:os = "Windows"
    else
        let g:os = substitute(system('uname'), '\n', '', '')
    endif
endif

let g:showdebugwindows=0
function! Runss(command)
	if bufexists('in.txt')
		exec 'bw! in.txt'
	endif
	if bufexists('out.txt')
		exec 'bw! out.txt'
	endif
	
	exec ':w! %'
	" exec '!g++ -O2 -std=c++11 % -fsanitize=undefined -Wall -Wextra -Wshadow -Wno-unused-result'
	exec a:command

	exec 'vnew in.txt' | wincmd r
	exec 'vertical resize 40'
	exec 'new out.txt' | wincmd x 
	let g:showdebugwindows=1
endfunction

function! Showss(bshow)
	if bufexists('in.txt')
		exec 'bw! in.txt'
	endif
	if bufexists('out.txt')
		exec 'bw! out.txt'
	endif
	if !a:bshow
		let g:showdebugwindows=1
		exec 'vnew in.txt' | wincmd r
		exec 'vertical resize 40'
		exec 'new out.txt' | wincmd x 
	else
		let g:showdebugwindows=0
	endif
endfunction

"-----------------------python----------------------------------
"function! Crpython()
"	exec ':!ctags -R *.py'
"	exec ':!find . -name *.py > cscope.files'
"	exec ':!cscope -Rbqk cscope.files'
"	exec ':!python3 ./TypeMaster.py'
"endfunction
"command! -nargs=0 Compilepython call Crpython()
"autocmd FileType python nnoremap <F6> :Compilepython

"-----------------------luogu----------------------------------
command! -nargs=0 Runaa call Runss(printf('!g++ -std=c++17 -fsanitize=undefined -g -Wall -Wextra -Wl,-stack_size -Wl,0x8000000 %s && ./a.out', expand('%')))
command! -nargs=0 Showaa call Showss(showdebugwindows)
autocmd FileType cpp nnoremap <F9> :w!<CR>:Runaa<CR>
autocmd FileType cpp nnoremap <F10> :Showaa<CR>
:autocmd BufNewFile *.cpp 0r ~/.config/nvim/templates/skeleton_luogu.cpp

"-----------------------noip-----------------------------------
"autocmd FileType cpp noremap <F9> <esc>:!g++ % -o %< -std=c++17 -Wall -Wextra -fsanitize=undefined -g <CR>
"autocmd FileType cpp noremap <F10> <esc>:vsplit<CR>:term ./%<<CR>
"autocmd FileType cpp noremap <F5> <esc>:packadd termdebug<cr>:Termdebug %< <cr>
"let g:termdebug_wide = 163
":autocmd BufNewFile *.cpp 0r ~/.config/nvim/templates/skeleton_noip.cpp


"=====================================dash help==========================================
:nmap <silent> <leader>d <Plug>DashSearch
"=====================================translate==========================================
" Display translation in a window
nmap <silent> <Leader>tw <Plug>TranslateW
vmap <silent> <Leader>tw <Plug>TranslateWV
nnoremap <silent><expr> <M-f> translator#window#float#has_scroll() ?
                            \ translator#window#float#scroll(1) : "\<M-f>"
nnoremap <silent><expr> <M-b> translator#window#float#has_scroll() ?
                            \ translator#window#float#scroll(0) : "\<M-f>"
" Replace the text with translation
nmap <silent> <Leader>tr <Plug>TranslateR
vmap <silent> <Leader>tr <Plug>TranslateRV
"=====================================make session==========================================
let g:sessions_dir = '~/vim-sessions'
exec 'nnoremap <leader>ss :mks! ' . g:sessions_dir . '/'
exec 'nnoremap <leader>sr :so ' . g:sessions_dir . '/'
"=====================================auto pairs==========================================
let g:AutoPairsFlyMode = 1
let g:AutoPairsShortcutBackInsert= '<M-b>'
au FileType php     let b:AutoPairs = AutoPairsDefine({'<?' : '?>', '<?php': '?>'})
au FileType html    let b:AutoPairs = AutoPairsDefine({'<!--' : '-->'}, ['{'])

"=====================================FZF==========================================
let g:fzf_action = {
  \ 'ctrl-t': 'tab split',
  \ 'ctrl-x': 'split',
  \ 'ctrl-v': 'vsplit' }

let g:fzf_history_dir = '~/.local/share/fzf-history'
map <leader><C-f> :Files<CR>
map <leader>b :Buffers<CR>
"git files list
nnoremap <leader><C-g> :GFiles<CR>

"=====================================Rg && Ag==========================================
map K <Plug>(devdocs-under-cursor)
augroup plugin-devdocs
  autocmd!
  autocmd FileType c,cpp,rust,haskell,python nmap <buffer>K <Plug>(devdocs-under-cursor)
augroup END
"=====================================Rg && Ag==========================================
nnoremap <leader>G :Rg <c-r><c-w><CR>
nnoremap <silent> <leader>ag :Ag <C-R><C-W><CR>

"=====================================coc.vim==========================================
""{{{
"let g:coc_global_extensions = [
"    \ 'coc-cmake',
"    \ 'coc-diagnostic',
"    \ 'coc-explorer',
"    \ 'coc-fzf-preview',
"    \ 'coc-go',
"    \ 'coc-git',
"    \ 'coc-gitignore',
"    \ 'coc-html',
"    \ 'coc-json',
"    \ 'coc-lists',
"    \ 'coc-markdownlint',
"    \ 'coc-marketplace',
"    \ 'coc-prettier',
"    \ 'coc-pyright',
"    \ 'coc-python',
"    \ 'coc-snippets',
"    \ 'coc-stylelint',
"    \ 'coc-syntax',
"    \ 'coc-tasks',
"    \ 'coc-translator',
"    \ 'coc-tsserver',
"    \ 'coc-vimlsp',
"    \ 'coc-yank']


"nmap tt :CocCommand explorer<CR>
"" coc-translator
"nmap ts <Plug>(coc-translator-p)

""===tab补全===
"inoremap <silent><expr> <TAB>
"      \ pumvisible() ? "\<C-n>" :
"      \ <SID>check_back_space() ? "\<TAB>" :
"      \ coc#refresh()
"inoremap <expr><S-TAB> pumvisible() ? "\<C-p>" : "\<C-h>"

"function! s:check_back_space() abort
"  let col = col('.') - 1
"  return !col || getline('.')[col - 1]  =~# '\s'
"endfunction


"inoremap <silent><expr> <C-p> coc#refresh()
"nnoremap <silent> <space>y  :<C-u>CocList -A --normal yank<cr>
"inoremap <silent><expr> <cr> pumvisible() ? coc#_select_confirm()
"                              \: "\<C-g>u\<CR>\<c-r>=coc#on_enter()\<CR>"

"nmap <silent> [g <Plug>(coc-diagnostic-prev)
"nmap <silent> ]g <Plug>(coc-diagnostic-next)

"" GoTo code navigation.
"nmap <silent> gd <Plug>(coc-definition)
"nmap <silent> gy <Plug>(coc-type-definition)
"nmap <silent> gi <Plug>(coc-implementation)
"nmap <silent> gr <Plug>(coc-references)

"" Use K to show documentation in preview window.
"nnoremap <silent> K :call <SID>show_documentation()<CR>

"function! s:show_documentation()
"  if (index(['vim','help'], &filetype) >= 0)
"    execute 'h '.expand('<cword>')
"  elseif (coc#rpc#ready())
"    call CocActionAsync('doHover')
"  else
"    execute '!' . &keywordprg . " " . expand('<cword>')
"  endif
"endfunction
"autocmd CursorHold * silent call CocActionAsync('highlight')
"nmap <leader>rn <Plug>(coc-rename)
"xmap <leader>f  <Plug>(coc-format-selected)
"nmap <leader>f  <Plug>(coc-format-selected)

"augroup mygroup
"autocmd!
"" Setup formatexpr specified filetype(s).
"autocmd FileType typescript,json setl formatexpr=CocAction('formatSelected')
"" Update signature help on jump placeholder.
"autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')
"augroup end

"xmap <leader>a  <Plug>(coc-codeaction-selected)
"nmap <leader>a  <Plug>(coc-codeaction-selected)


"" Remap keys for applying codeAction to the current buffer.
"nmap <leader>ac  <Plug>(coc-codeaction)
"" Apply AutoFix to problem on the current line.
"nmap <leader>qf  <Plug>(coc-fix-current)

"" Map function and class text objects
"" NOTE: Requires 'textDocument.documentSymbol' support from the language server.
"xmap if <Plug>(coc-funcobj-i)
"omap if <Plug>(coc-funcobj-i)
"xmap af <Plug>(coc-funcobj-a)
"omap af <Plug>(coc-funcobj-a)
"xmap ic <Plug>(coc-classobj-i)
"omap ic <Plug>(coc-classobj-i)
"xmap ac <Plug>(coc-classobj-a)
"omap ac <Plug>(coc-classobj-a)

"nmap <silent> <C-s> <Plug>(coc-range-select)
"xmap <silent> <C-s> <Plug>(coc-range-select)
""}}}

"nnoremap <leader>ps :lua require('telescope.builtin').grep_string({ search = vim.fn.input("Grep For > ")}}}}}kkkkjjj)<CR>
" " Find files using Telescope command-line sugar.
" nnoremap <leader>ff <cmd>lua require('telescope.builtin').find_files()<cr>
" nnoremap <leader>fg <cmd>lua require('telescope.builtin').live_grep()<cr>
" nnoremap <leader>fb <cmd>lua require('telescope.builtin').buffers()<cr>
" nnoremap <leader>fh <cmd>lua require('telescope.builtin').help_tags()<cr>

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" CSCOPE settings for vim           
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"
" This file contains some boilerplate settings for vim's cscope interface,
" plus some keyboard mappings that I've found useful.
"
" USAGE: 
" -- vim 6:     Stick this file in your ~/.vim/plugin directory (or in a
"               'plugin' directory in some other directory that is in your
"               'runtimepath'.
"
" -- vim 5:     Stick this file somewhere and 'source cscope.vim' it from
"               your ~/.vimrc file (or cut and paste it into your .vimrc).
"
" NOTE: 
" These key maps use multiple keystrokes (2 or 3 keys).  If you find that vim
" keeps timing you out before you can complete them, try changing your timeout
" settings, as explained below.
"
" Happy cscoping,
"
" Jason Duell       jduell@alumni.princeton.edu     2002/3/7
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


" This tests to see if vim was configured with the '--enable-cscope' option
" when it was compiled.  If it wasn't, time to recompile vim... 
if has("cscope")

    """"""""""""" Standard cscope/vim boilerplate

	set csprg=/usr/local/bin/cscope
    " use both cscope and ctag for 'ctrl-]', ':ta', and 'vim -t'
    set cscopetag
	set cscopequickfix=s-,c-,d-,i-,t-,e-

    " check cscope for definition of a symbol before checking ctags: set to 1
    " if you want the reverse search order.
    set csto=0

    " add any cscope database in current directory
    if filereadable("cscope.out")
        cs add cscope.out  
    " else add the database pointed to by environment variable 
    elseif $CSCOPE_DB != ""
        cs add $CSCOPE_DB
    endif

    " show msg when any other cscope db added
    set cscopeverbose  


    """"""""""""" My cscope/vim key mappings
    "
    " The following maps all invoke one of the following cscope search types:
    "
    "   's'   symbol: find all references to the token under cursor
    "   'g'   global: find global definition(s) of the token under cursor
    "   'c'   calls:  find all calls to the function name under cursor
    "   't'   text:   find all instances of the text under cursor
    "   'e'   egrep:  egrep search for the word under cursor
    "   'f'   file:   open the filename under cursor
    "   'i'   includes: find files that include the filename under cursor
    "   'd'   called: find functions that function under cursor calls
    "
    " Below are three sets of the maps: one set that just jumps to your
    " search result, one that splits the existing vim window horizontally and
    " diplays your search result in the new window, and one that does the same
    " thing, but does a vertical split instead (vim 6 only).
    "
    " I've used CTRL-\ and CTRL-@ as the starting keys for these maps, as it's
    " unlikely that you need their default mappings (CTRL-\'s default use is
    " as part of CTRL-\ CTRL-N typemap, which basically just does the same
    " thing as hitting 'escape': CTRL-@ doesn't seem to have any default use).
    " If you don't like using 'CTRL-@' or CTRL-\, , you can change some or all
    " of these maps to use other keys.  One likely candidate is 'CTRL-_'
    " (which also maps to CTRL-/, which is easier to type).  By default it is
    " used to switch between Hebrew and English keyboard mode.
    "
    " All of the maps involving the <cfile> macro use '^<cfile>$': this is so
    " that searches over '#include <time.h>" return only references to
    " 'time.h', and not 'sys/time.h', etc. (by default cscope will return all
    " files that contain 'time.h' as part of their name).


    " To do the first type of search, hit 'CTRL-\', followed by one of the
    " cscope search types above (s,g,c,t,e,f,i,d).  The result of your cscope
    " search will be displayed in the current window.  You can use CTRL-T to
    " go back to where you were before the search.  
    "

    nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>	
    nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
    nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>	


    " Using 'CTRL-spacebar' (intepreted as CTRL-@ by vim) then a search type
    " makes the vim window split horizontally, with search result displayed in
    " the new window.
    "
    " (Note: earlier versions of vim may not have the :scs command, but it
    " can be simulated roughly via:
    "    nmap <C-@>s <C-W><C-S> :cs find s <C-R>=expand("<cword>")<CR><CR>	

    nmap <C-@>s :scs find s <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-@>g :scs find g <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-@>c :scs find c <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-@>t :scs find t <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-@>e :scs find e <C-R>=expand("<cword>")<CR><CR>	
    nmap <C-@>f :scs find f <C-R>=expand("<cfile>")<CR><CR>	
    nmap <C-@>i :scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>	
    nmap <C-@>d :scs find d <C-R>=expand("<cword>")<CR><CR>	


    " Hitting CTRL-space *twice* before the search type does a vertical 
    " split instead of a horizontal one (vim 6 and up only)
    "
    " (Note: you may wish to put a 'set splitright' in your .vimrc
    " if you prefer the new window on the right instead of the left

    nmap <C-@><C-@>s :vert scs find s <C-R>=expand("<cword>")<CR><CR>
    nmap <C-@><C-@>g :vert scs find g <C-R>=expand("<cword>")<CR><CR>
    nmap <C-@><C-@>c :vert scs find c <C-R>=expand("<cword>")<CR><CR>
    nmap <C-@><C-@>t :vert scs find t <C-R>=expand("<cword>")<CR><CR>
    nmap <C-@><C-@>e :vert scs find e <C-R>=expand("<cword>")<CR><CR>
    nmap <C-@><C-@>f :vert scs find f <C-R>=expand("<cfile>")<CR><CR>	
    nmap <C-@><C-@>i :vert scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>	
    nmap <C-@><C-@>d :vert scs find d <C-R>=expand("<cword>")<CR><CR>


    """"""""""""" key map timeouts
    "
    " By default Vim will only wait 1 second for each keystroke in a mapping.
    " You may find that too short with the above typemaps.  If so, you should
    " either turn off mapping timeouts via 'notimeout'.
    "
    "set notimeout 
    "
    " Or, you can keep timeouts, by uncommenting the timeoutlen line below,
    " with your own personal favorite value (in milliseconds):
    "
    "set timeoutlen=4000
    "
    " Either way, since mapping timeout settings by default also set the
    " timeouts for multicharacter 'keys codes' (like <F1>), you should also
    " set ttimeout and ttimeoutlen: otherwise, you will experience strange
    " delays as vim waits for a keystroke after you hit ESC (it will be
    " waiting to see if the ESC is actually part of a key code like <F1>).
    "
    "set ttimeout 
    "
    " personally, I find a tenth of a second to work well for key code
    " timeouts. If you experience problems and have a slow terminal or network
    " connection, set it higher.  If you don't set ttimeoutlen, the value for
    " timeoutlent (default: 1000 = 1 second, which is sluggish) is used.
    "
    "set ttimeoutlen=100

endif


fun! TrimWhitespace()
    " let l:save = winsaveview()
    " keeppatterns %s/\s\+$//e
    " call winrestview(l:save)
endfun

augroup THE_PRIMEAGEN
    autocmd!
    autocmd BufWritePre * :call TrimWhitespace()
augroup END


imap <silent><script><expr> <C-J> copilot#Accept("\<CR>")
let g:copilot_no_tab_map = v:true
" highlight CopilotSuggestion guifg=#555555 ctermfg=8
" vim:tw=78:et:ft=help:norl:
