#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  if(n == 1){
    cout << "1";
    return 0;
  }

  // Greedy
  // Starting with 2 always append the number with the lowest distance from current number in either direction
  //
  vector<int> solution;
  vector<bool> used (n, false);
  solution.push_back(2);
  used[1] = true;

  int prevIndex = 1;
  while(solution.size() < n){
    int lowerIndex = prevIndex - 2;
    int upperIndex = prevIndex + 2;
    bool innerValid = false;
    while(lowerIndex >= 0 || upperIndex < n){
      if(lowerIndex >= 0 && !used[lowerIndex]) {
        used[lowerIndex] = true;
        prevIndex = lowerIndex;
        solution.push_back(lowerIndex+1);
        innerValid = true;
        break;
      } else if (upperIndex < n && !used[upperIndex]) {
        used[upperIndex] = true;
        prevIndex = upperIndex;
        solution.push_back(upperIndex+1);
        innerValid = true;
        break;
      }
      lowerIndex--;
      upperIndex++;
    }
    if(!innerValid){
      cout << "NO SOLUTION";
      return 0;
    }
  }
  for(int i = 0; i < n; i++) cout << solution[i] << " ";
}
