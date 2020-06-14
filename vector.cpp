#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<char> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  v.push_back("a");
}
