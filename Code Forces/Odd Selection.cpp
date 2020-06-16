#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for(int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int x;
    cin >> x;

    int partall = 0;
    int oddetall = 0;
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      if(x % 2 == 0){
        partall++;
      } else {
        oddetall++;
      }
    }

    int sum = 0;
    while(x > 1){
      if(partall > oddetall){
        sum += 2;
        partall--;
      } else {
        sum += 1;
        oddetall--;
      }
      x--;
    }
    // gjør slik at x er 1 i konstant time
    int differanse = abs(partall - oddetall);
    if(partall > oddetall){
      partall -= differanse;
    } else {
      oddetall -= differanse;
    }




   cout << (((sum % 2 == 0 && oddetall > 0) || (sum % 2 == 1 && partall >0)) ? "YES" : "NO") << "\n";


  }
}
