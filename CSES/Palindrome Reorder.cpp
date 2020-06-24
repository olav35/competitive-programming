#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string word;
  cin >> word;

  map<char, int> occurences; // what is default value??


  for(auto c : word) {
    occurences[c]++; // assumes default value is false
  }

  int oddChars = 0;
  for(auto x : occurences) {
    oddChars += x.second % 2 == 1;
  }

  if(oddChars > 1){
    printf("NO SOLUTION");
    return 0;
  } else {
    string start = "";
    char middle;
    string end;
    for(auto x : occurences) {
      if(x.second == 1){
        middle = x.first;
        // insert 1 instances of x.first at position solution.length() / 2
      } else {
        int instances = x.second / 2;
        start.insert(0, instances, x.first);
        end.insert(end.length(), instances, x.first);
      }
    }

    // Test 9 will not pass if I iterative backwards
    // No idea why that is the case

    /*
    for(auto x : occurences) {
      if(x.second == 1){
        solution.insert(solution.length() / 2, 1, x.first);
        // insert 1 instances of x.first at position solution.length() / 2
      } else {
        int instances = x.second / 2;
        solution.insert(0, instances, x.first);
        solution.insert(solution.length(), instances, x.first);
      }
    }
    */
    cout << start << middle << end;
  }
}
