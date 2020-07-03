#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  int steps = 0;
  while(true){
    if(n==1){
      return steps;
    } else if (n % 6 == 0){
      n/=6;
      steps++;
    } else if (n % 3 == 0){
      n/=3;
      steps+=2;
    } else {
      return -1;
    }
  }
}

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // multiply by 2 or divide by (6 if it is divisible)
  int t;
  cin >> t;

  for(int i = 0; i < t; i++) {
    int n;
    cin >> n;
    cout << solve(n) << "\n";
  }
}
