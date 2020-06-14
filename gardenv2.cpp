#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int k;
  cin >> k;

  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  int bestHours = 1000000;
  for(int i = 0; i < n; i++) {
    int capacity = v[i];
    if(k % capacity != 0) {
      break;
    }
    int hours = k / capacity;
    if(hours < bestHours){
      bestHours = hours;
    }
  }

  cout << bestHours;
}
