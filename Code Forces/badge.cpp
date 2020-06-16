#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n; // number of naughty students

  vector<int> students(n);
  for(int i = 0; i < n; i++){
    cin >> students[i];
  }

  for(int i = 0; i < n; i++) { // fix fup
    vector<int> holes (n, 0);
    int studentIndex = i;
    while (holes[studentIndex] != 2) {
      holes[studentIndex]++;
      studentIndex = students[studentIndex] - 1;
    }
    cout << studentIndex + 1 << " ";
  }
}
