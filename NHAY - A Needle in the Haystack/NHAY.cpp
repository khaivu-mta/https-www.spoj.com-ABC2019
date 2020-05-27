#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int len;
  string s, t;
  while (cin >> len) {
    cin >> s >> t;
    string p = s + "#" + t;
    int n = p.length();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
      if (i>r) {
        l = r = i;
        while (r < n && p[r - l] == p[r]) r++;
        z[i] = r - l;
        r--;
      }
      else {
        int k = i - l;
        if (z[k] < r - i + 1) z[i] = z[k];
        else {
          l = i;
          while (r>0 && p[r - l] == p[r]) r++;
          z[i] = r - l;
          r--;
        }
      }
      //cerr << z[i] << ' ';
    }
    //cerr << endl;
    bool q = true;
    for (int i = len; i < n; i++) if (z[i] == len) {
      cout << i - len - 1 << '\n';
      q = false;
    }
    if (q) cout << '\n';
  }
}
