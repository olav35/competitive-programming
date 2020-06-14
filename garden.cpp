#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; // num of buckets
  cin >> n;

  int k; // garden length
  cin >> k;

  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  // print min amount of hours
  // find MIN HOURS
  int bestBucketIndex = 0;
  int bestHours = 1000000;
  for(int i = 0; i < n; i++) {
    // figure out how many hours it taks to fill with a bucker
    int hours = 0;
    int wateringLeft = k;
    int capacity = v[i];
    int wateringInBucket = capacity;
    if(k % capacity != 0) {
     continue;
    }
    while (wateringLeft > 0){
      wateringLeft-= capacity;
      hours++;
    }
    if(hours < bestHours){
      bestHours = hours;
    }
    }

  cout << bestHours;
}
