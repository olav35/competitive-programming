#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  for(int i = 0; i < t; i++) {
    int n; // rows
    cin >> n;

    int m; // columns
    cin >> m;

    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++){
      vector<int> w(m);
      for(int i = 0; i < n; i++){
        cin >> w[i];
      }
      v.push_back(w);
    }


  }
}
