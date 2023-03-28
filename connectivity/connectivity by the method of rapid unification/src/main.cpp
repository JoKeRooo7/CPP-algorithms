#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void write(vector<vector<int>>& id, int num1, int num2);
void output(vector<vector<int>>& id, int N);

int main() {
  int N, num1, num2;
  cout << "Enter the number of characters: ";
  cin >> N;
  vector<vector<int>> id(N, vector<int>(1));
  srand(time(0));
  for (int i = 0; i < N; i++) {
    id[i][0] = rand() % 101 + 0;
    if (i % 5 == 0 && i != 0) cout << endl;
    cout << i + 1 << ": " << id[i][0] << "  ";
  }
  cout << endl;
  while (true) {
    cout << "enter in turn the first and second number of numbers to link "
            "(negative numbers to delete)\n";
    cin >> num1;
    if (!num1 || num1 < 0) break;
    cin >> num2;
    if (!num2 || num2 < 0 || num2 == num1) break;
    if (num2 > num1) {
      write(id, num1, num2);
    } else {
      write(id, num2, num1);
    }
  }
  output(id, N);
  id.clear();
}

void write(vector<vector<int>>& id, int num1, int num2) {
  int j = 0;
  while (id[num1 - 1][j] && id[num1 - 1][j] != num2 - 1) {
    j++;
  }
  if (id[num1 - 1][j] != num2 - 1) {
    id[num1 - 1].push_back(num2 - 1);
  }
}

void output(vector<vector<int>>& id, int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 1; id[i][j]; j++) {
      cout << i + 1 << " - " << id[i][j] + 1 << " (";
      cout << id[i][0] << " - " << id[id[i][j]][0] << ")\n";
    }
  }
}