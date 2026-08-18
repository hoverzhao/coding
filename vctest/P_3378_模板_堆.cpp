#include <bits/stdc++.h>
using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();

const int N = 1e6 + 5;
struct minheap {
  int len = 0;
  int heap[N] = {0};
  void push(int x) {
    heap[++len] = x;
    int i = len;
    while (i > 1 && heap[i] < heap[i / 2]) {
      swap(heap[i], heap[i / 2]);
      i = i / 2;
    }
  }
  void pop() {
    heap[1] = heap[len--];
    int i = 1;
    while (i * 2 <= len) {
      int son = i * 2;
      if (son < len && heap[son + 1] < heap[son]) {
        son++;
      }
      if (heap[i] > heap[son]) {
        swap(heap[i], heap[son]);
        i = son;
      } else
        break;
    }
  }

  int top() { return heap[1]; }
};

minheap mh;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      mh.push(x);
    } else if (op == 2) {
		cout << mh.top() << '\n';
    } else
      mh.pop();
  }
  return 0;
}