#include <bits/stdc++.h>

using namespace std;

int TimTongLonNhatCoGioiHan(int*arr, int songuoichoi, int gioihan){
  int hmm = (int)(songuoichoi*songuoichoi/2);
  int map[hmm];
  
  int dem = 0, i, j, ox = songuoichoi - 1, oy = 0, result = 0, sum;
  for(i = ox; i > oy; --i){
    for(j = oy; j < ox; ++j){
      map[dem] = arr[i] + arr[j];
      
      // tinh tong lon nhat cua 3 so
      for(int k = 0; k < songuoichoi; ++k){
        if(k == j || k == i)
          continue;
        sum = map[dem] + arr[k];
        if(sum > result && sum <= gioihan)
          result = sum;
      }
      dem++;
    }
    -- ox;
  }
  
  return result;
}

int main() {
  int sophantu = 0, songuoichoi = 0, gioihan = 0;
  cin>>sophantu;
  while(sophantu-->0){
    cin>>songuoichoi;
    int i = 0;
    int arrCanNang[songuoichoi];
    for(; i<songuoichoi; ++i){
      cin>>arrCanNang[i];
    }
    cin>>gioihan;
    
    cout<<TimTongLonNhatCoGioiHan(arrCanNang, songuoichoi, gioihan)<<"\n";
  }
  return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

int ssp(vector<int>& v, int& N) {

  vector< vector<int> > m( v.size() + 1 , // 1-based
                         vector<int>(N + 1 , 0) );//1-based

  // The line above also took care of the initialization for base
  // cases f(i,0) = 0 and f(0,b) = 0

  for (int i = 1; i <= v.size(); ++i) { // Đối với mỗi tập hợp con của các phần tử
    for (int b = 1; b <= N; ++b) { // Đối với mỗi subcapacity
      int opt1 = m[i - 1][b];
      int opt2 = -1;
      if (b - v[i - 1] >= 0) { // No caching to keep this readable
        opt2 = m[i - 1][b - v[i - 1]] + v[i - 1];
        if (opt2 > b)
          opt2 = -1; // Not allowed
      }
      m[i][b] = max(opt1, opt2);
    }
  }

  return m[v.size()][N];
}

int main() {

  vector<int> v ;//= { 40, 50, 60, 80 };
  v.push_back(40);
  v.push_back(50);
  v.push_back(60);
  v.push_back(80);
  int N = 160;
  int result = ssp(v, N);

  cout << "Subset sum problem can be solved with the given input: "
       << boolalpha << (bool)(N==result)<<": "<<result; // true

  return 0;
}
*/