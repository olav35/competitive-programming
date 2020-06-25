#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // First iteration shall sum the number by char

  int steps = 0;
  bool firstIteration = true;
  int n = 10;
  while(n/10 != 0){
    int sum = 0;
    if(firstIteration){
      firstIteration = false;
      char digit;
      int count = 0;
      while(cin>>digit){
        count++;
        sum+= digit -'0';
      }
      if(count == 1){
        cout << 0;return 0;
      }
    } else {
      while(n > 0){
        sum+= n % 10;
        // n-= n%10; may be unnecesary due to the way integer division works
        n/= 10;
      }
    }
    n = sum;
    steps++;
  }
  cout << steps;
}
