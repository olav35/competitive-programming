#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int l = 1;
  int ll = 1;
  char prevChar = '_';
  for(auto c : s) {
    if(prevChar == c){
      l++;
    } else {
      l = 1;
    }
    if(l > ll){
      ll = l;
    }
    prevChar = c;
  }
  cout << ll;
}
