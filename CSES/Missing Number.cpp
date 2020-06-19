#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  long long sum = 0;

  for(int i = 0; i < n-1; i++) {
    int x;
    cin >> x;
    sum+=x;
  }

  cout << (long long) n*(1+n)/2 - sum;
}
