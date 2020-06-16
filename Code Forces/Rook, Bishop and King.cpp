#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int r1;
  cin >> r1;
  r1--;

  int c1;
  cin >> c1;
  c1--;

  int r2;
  cin >> r2;
  r2--;

  int c2;
  cin >> c2;
  c2--;

  // minimum amount of moves to move rook, bishop, king
  int rMoves = 0;
  if(r1 != r2){
    rMoves++;
  }
  if(c1 != c2){
    rMoves++;
  }

  int bMoves;
  if(r1 == r2 && c1 == c2){
    bMoves = 0;
  } else if(abs(r1 - r2) == abs(c1 - c2)) {
    bMoves = 1;
  } else if((r1 + c1) % 2 == (r2 + c2) % 2) { // detect if pn same color
     // 4 5 6 7 8 9 10 11
    // 3 4 5 6 7 8 9 10
    // 2 3 4 5 6 7 8 9

    // håndter tilfellet hvor de er på nullte
    // 2 3 4 5 6 7 8 9
    // 1 2 3 4 5 6 7 8
    // 0 1 2 3 4 5 6 7
   bMoves = 2;
  } else {
    bMoves = 0;
  }

  int kMoves = max(abs(r1 - r2), abs(c1 - c2));

  cout << " " << rMoves << " " << bMoves << " " << kMoves;
}
