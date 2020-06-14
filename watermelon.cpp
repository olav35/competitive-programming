#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int w;
  cin >> w;

  cout << ((w > 2 && w % 2 == 0) ? "YES" : "NO") << "\n";
}
