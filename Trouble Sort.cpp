#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  // TODO lag test case snippet

  for(int i = 0; i < t; i++) {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }

    vector<int> w(n);
    for(int i = 0; i < n; i++){
      cin >> w[i];
    }

    bool pairOfTypes = false;
    int zeros = 0;
    int ones = 0;
    for(int i = 0; i < n; i++) {
      if(w[i] == 1){
        ones++;
      } else {
        zeros++;
      }
      if(zeros >= 1 && ones >= 1){
        pairOfTypes = true;
        break;
      }
    }

    if(pairOfTypes){
      cout << "YES" << "\n";
      continue;
    } else {
      int prevNum = v[0];
      bool sorted = true;
      for(int i = 1; i < n; i++) {
        if(prevNum > v[i]){
            sorted = false;
            break;
        }
      }
      if(sorted) {cout << "YES" << "\n";
                   continue;}

      cout << "NO" << "\n";
    }
  }
}
