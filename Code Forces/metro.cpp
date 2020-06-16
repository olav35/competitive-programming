#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int s;
  cin >> s;

  // construct adjacency array
  vector<vector<int> > adj(n);

  int prevIndex = -1;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(x == 1) {
      if(prevIndex != -1) {
        adj[prevIndex].push_back(i);
      }
      prevIndex = i;
    }
  }

  prevIndex = -1;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
   
    if(x==1) {
      if(prevIndex != -1) {
        // point to previousindex
        adj[i].push_back(prevIndex);
      }
      prevIndex = i;
    }
  }

  /*
  for(auto x : adj) {
    for(auto y : x) {
      cout << y << " ";
    }
    cout << "\n";
  }
  */

  // use vector + bfs


  vector<bool> visited (n, false);
  queue<int> q;
  q.push(0);
  visited[0] = true;
  while(!q.empty()) {
    int popie = q.front(); q.pop();
    // process
    if(popie == s - 1) {
      cout << "YES";
      return 0;
    }
    for(auto x : adj[popie]) {
      if(visited[x]) continue;
      visited[x] = true;
      q.push(x);
    }
  }

  cout << "NO";
  return 0;
}
