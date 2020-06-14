#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // maze n x m grid
  //
  // gric cells one of
  // empty - .
  // wall - #
  // good person - g
  // bad person - b
  //
  // the *only escape from the amze is a t cell (n,n)
  //
  // a person can move to a cell if it shares a side with their current cell and
  // does not contain a wall
  //
  // vivek wants to replace some onf the walls such athat all good people can escape
  // but none of the bad persons can
  //
  // figure out if it is possible to satify his conditions
  //
  // (n,m) is empty

  int t;
  cin >> t;

  for(int i = 0; i < t; i++) {
    int n; // rows
    cin >> n;

    int m; // columns
    cin >> m;

    // stenge inne alle bad person i 1x1??
    // Kjøre bfs for å finne om de gode kan komme seg ut?

    // TODO get matrix
    //cout << "44 : " << 44 << "\n";

    vector<vector<char>> v(n);



    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        char x;
        cin >> x;
        //cout << "51 : " << 51 << "\n";

        v[i].push_back(x); // i skulle aldri blitt 1 her
        //cout << "53 : " << 53 << "\n";
      }
    }
    //cout << "54 : " << 54 << "\n";


    // TODO account for the possibily of a bad person being right next ot the escape

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(v[i][j] == 'B') {
          // -1 +1 0
          //cout << "61 : " << 61 << "\n";

          vector<int> rowIndicies;
          if(i-1>=0)rowIndicies.push_back(i-1);
          if(i+1<n)rowIndicies.push_back(i+1);
          rowIndicies.push_back(i);

          //cout << "65 : " << 65 << "\n";

          vector<int> colIndicies;
          if(j-1>=0)rowIndicies.push_back(j-1);
          if(j+1<m)rowIndicies.push_back(j+1);
          rowIndicies.push_back(j);

          for(int ri = 0; ri < n; ri++) {
            for(int coli = 0; coli  < m; coli ++) {
              if(v[ri][coli] == '.') v[ri][coli] = '#';
            }
          }
        }
      }
    }

    //cout << "80 : " << 80 << "\n";

    bool allCanEscape = true;


    vector<vector<bool>> succesFull (n); // samme hvem som har besøkt
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        succesFull[i].push_back(false);
      }
    }
    // feiler alle hvor en good er tilstede

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(v[i][j] == 'G'){ // for hver good guy G
vector<vector<bool>> visitedRows (n); // samme hvem som har besøkt
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        visitedRows[i].push_back(false);
      }
    }
          int initI = i;
          int initJ = j;

          queue<vector<int>> q;
          //visitedRows[i][j] = true;
          q.push({i, j});
          // hvis besøkt så sann
          // TODO Bli comfy med pairs
          bool fantUtVeien = false;
          while(!q.empty()) {
            auto s = q.front(); q.pop();

            // process this one
            // process er test om den fant utveien
            /*
            cout << "s[0] : " << s[0] << "\n";
            cout << "s[1] : " << s[1] << "\n";
            */


            // PROBLEMET ER AT DEN IKKE QUER SKIKELIG
            if((s[0] == n - 1 && s[1] == m - 1) || succesFull[s[0]][s[1]]){

              fantUtVeien = true;
              succesFull[initI][initJ] = true;
              //cout << "fantUtVeien : " << fantUtVeien << "\n";
              break;
            }
            // queue and set visited adjacent and open squares
            if(visitedRows[s[0]][s[1]]) continue; // WAAAH
            vector<int> rowIndicies;
            if(i-1>=0)rowIndicies.push_back(i-1);
            if(i+1<n)rowIndicies.push_back(i+1);
            rowIndicies.push_back(i);

            vector<int> colIndicies;
            if(j-1>=0)rowIndicies.push_back(j-1);
            if(j+1<m)rowIndicies.push_back(j+1);
            rowIndicies.push_back(j);

            for(int ri = 0; ri < n; ri++) {
              for(int coli = 0; coli  < m; coli ++) {
                if(v[ri][coli] == '.' || v[ri][coli] == 'G') {
                  // TODO les igjennom
                  visitedRows[ri][coli] = true;
                  q.push({ri, coli});
                  // queue og visited
                }
              }
            }

          }
          if(!fantUtVeien){
            allCanEscape = false;
            goto end;
          }
        }
      }
    }
    end: cout << ((allCanEscape) ? "YES" : "NO") << "\n";

  }
}
