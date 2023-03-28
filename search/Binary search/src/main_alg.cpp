#include <ctime>
#include <iostream>

using namespace std;

void init(int *a, int N);
void buble_sort(int *a, int N);
int search(int *a, int v, int N);

int main() {
  int N, v;
  cin >> N;
  int *a = new int[N];
  init(a, N);
  buble_sort(a, N);
  v = rand() % 101 + 0;
  cout << " need to find " << v << endl;
  int index = search(a, v, N);
  if (index != -1) {
    cout << "match found, a[" << index << "] = " << a[index] << endl;
  } else {
    cout << "no match found";
  }
  delete[] a;
}

void init(int *a, int N) {
  srand(time(0));
  for (int i = 0; i < N; i++) {
    a[i] = rand() % 101 + 0;
    if (i % 15 == 0 && i != 0) {
      cout << endl;
    }
    cout << a[i] << " ";
  }
}

void buble_sort(int *a, int N) {
  int k = 0;
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j != -1; j--) {
      if (a[i] > a[j]) {
        k = a[i];
        a[i] = a[j];
        a[j] = k;
      }
    }
  }
}

int search(int *a, int v, int N) {
  int left = 0;
  int right = N;
  while (right >= left) {
    int difference = ((left + right) / 2);
    if (v == a[difference]) return difference;
    if (v < a[difference])
      right = difference - 1;
    else
      left = difference + 1;
  }
  return -1;
}
