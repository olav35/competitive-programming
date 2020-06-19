#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  long long prevInt = 0;
  long long steps = 0;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    steps += (long long) max((long long) 0, prevInt - a);
    prevInt = (long long) a + max((long long) 0, prevInt - a);
  }

  cout << steps;
}
