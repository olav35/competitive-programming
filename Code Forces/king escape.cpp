#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n; // dimension of chess board

  int ax;
  cin >> ax;
  ax--;

  int ay;
  cin >> ay;
  ay--;

  int bx;
  cin >> bx;
  bx--;

  int by;
  cin >> by;
  by--;

  int cx;
  cin >> cx;
  cx--;

  int cy;
  cin >> cy;
  cy--;
  // process of by one as we go

  // generate board with red squares
  // [row][column]
  vector<vector<bool> > legalSquares (n, vector<bool> (n)); // not sure this is correct

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if (ax == i || ay == j) {
        legalSquares[i][j] = false;
      } else if (abs(ay - ax) == abs(i - j)){ // this might be incorrect
        // same diagonal
        legalSquares[i][j] = false;
      } else {
        legalSquares[i][j] = true;
      }
    }
  }

  vector<vector<bool>> visited(n, vector<bool> (n, false));
  queue<pair<int, int>> q;
  q.push({bx, by});

  while(!q.empty()){
    auto s = q.front(); q.pop();
    if(s.first == cx && s.second == cy) {
      //cout << "s.first : " << s.first << "\n";
      //cout << "s.second : " << s.second << "\n";
      cout << "YES";
      return 0;
    }
    for(int i = -1; i <= 1; i++) {
      int newX = s.first + i;
      for(int j = -1; j <= 1; j++) {
        int newY = s.second + j;
        if(newX < n && newY < n && newX >= 0 && newY >= 0 && legalSquares[newX][newY] && !visited[newX][newY]) {
          visited[newX][newY] = true;
          // cout << "added" << "\n";
          // cout << "newX : " << newX << "\n";
          //cout << "newY : " << newY << "\n";
          q.push({newX, newY});
        }
      }
    }
  }
  cout << "NO";
  return 0;
}
