#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for(int i = 0; i < t; i++) {
    int x; // init hp
    cin >> x;

    int n; // void | hp := floor(hp/2)+19
    cin >> n;

    int m; // light | hp := hp - 10
    cin >> m;

    while(true) {
      if(x<=0)break;
      if(n>0 && x > 20){
        x = x / 2 + 10;
        n--;
      } else if(m>0){
        x -= 10;
        m--;
      } else {
        break;
      }
    }
    cout << ((x <= 0) ? "YES" : "NO") << "\n";
    }
}
