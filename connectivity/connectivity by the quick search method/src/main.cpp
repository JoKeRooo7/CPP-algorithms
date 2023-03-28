#include <iostream>
#include <ctime>

#define NMAX 100

using namespace std;

typedef struct net {
  int num;
  int *quantity_links;
} net;

void null_array(net *a, int N);
int input(int i, int *number);
void record_links(net *a, int num1, int num2);
void output(net *a, int N);
void clear(net *a);

int main() {
  int N, num1, num2;
  cout << "Enter the number N = ";
  cin >> N;
  net a[N];
  srand(time(0));
  for (int i = 0; i < N && i < NMAX; i++) {
    a[i].num = rand() % 101 + 0;
    a[i].quantity_links = new int[N];
    if (i % 5 == 0 && i != 0) cout << endl;
    cout << i + 1 << ": " << a[i].num << "  ";
  }
  cout << endl;
  for (int i = 0; i < N && i < NMAX; i++) {
    null_array(&a[i], N);
  }
  while (true) {
    if (input(0, &num1) == 1 || num1 >= N || input(1, &num2) == 1 ||
        num2 >= N) {
      break;
    } else if (num1 == num2) {
      continue;
    } else if (num1 < num2) {
      record_links(a, num1, num2);
    } else {
      record_links(a, num2, num1);
    }
  }
  output(a, N);
  for (int i = 0; i < N; i++) {
    clear(&a[i]);
  }
}

void null_array(net *a, int N) {
  for (int j = 0; j < N; j++) {
    a->quantity_links[j] = -1;
  }
}

int input(int i, int *number) {
  int flag_break = 0;
  if (i == 0) {
    cout << "Enter the number of the first number for communication (negative "
            "number for the end): ";
  } else {
    cout << "Enter the number of the second number for communication (negative "
            "number for the end) ";
  }
  cin >> *number;
  *number -= 1;
  if (*number < 0) {
    flag_break = 1;
  }
  return flag_break;
}

void record_links(net *a, int num1, int num2) {
  int i = 0;
  while (i < NMAX && a[num1].quantity_links[i] != -1 &&
         a[num1].quantity_links[i] != num2) {
    i++;
  }
  a[num1].quantity_links[i] = num2;
}

void output(net *a, int N) {
  for (int i = 0; i < NMAX && i < N; i++) {
    for (int j = 0; j < NMAX && a[i].quantity_links[j] != -1; j++) {
      cout << i + 1 << " - " << a[i].quantity_links[j] + 1 << " (";
      cout << a[i].num << " - " << a[a[i].quantity_links[j]].num << ");"
           << endl;
    }
  }
}

void clear(net *a) { delete[] a->quantity_links; }