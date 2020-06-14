#include <bits/stdc++.h>

using namespace std;

int main() {
  // https://stackoverflow.com/questions/31162367
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // secret message
  // each half permutation of size n
  // parts called a and b
  // permutation of n is sequence of n numbers in which every number
  // fro 1 to n appears once
  //
  // They can be decoded by arranging them so that the number of matching pairs
  // of elements is maxed
  //
  // a pair a_i and b_j max if
  //   i = j // same index
  //   a_i = b_j // same value
  //
  // the operation permitted is
  //  swift the one of the permutations k times to left or right
  //

  int n;
  cin >> n;

  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  vector<int> w(n);
  for(int i = 0; i < n; i++){
    cin >> w[i];
  }

  int bestLShift;
  int bestMatchingPairs = 0;
  for(int i = 0; i < n; i++) {
    // shift by i
    int matchingPairs = 0;
    for(int i = 0; i < n; i++) {
      matchingPairs += v[i] == w[i];
    }
    bestMatchingPairs = max(matchingPairs, bestMatchingPairs);

    // shifting w
    int lastValue = w[n-1];
    int prev = w[0];
    for(int i = 1; i < n; i++) {
      int temp = w[i];
      w[i] = prev;
      prev = temp;

    }
    w[0] = lastValue;

  }

  cout << bestMatchingPairs;
}
