#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> coins = {1, 5, 10, 20, 100};
  int coinsCount = 0;

  coinsCount += n / 100;
  n %= 100;

  coinsCount += n / 20;
  n %= 20;

  coinsCount += n / 10;
  n %= 10;

  coinsCount += n / 5;
  n %= 5;

  coinsCount += n / 1;
  n %= 1;

  cout << coinsCount;
}
