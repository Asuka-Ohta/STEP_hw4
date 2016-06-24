// r1.cpp
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

typedef map<string, vector<int> > adj_matrix; //隣接行列
typedef float number = 100.; // 各要素にはじめに与えられる値

class Pagerank {
private:
  adj_matrix matrix; // リンクデータ
  map<string, double> paderank;
  map<string, double> temprank;
  int N; // 要素数

public:
  PageRank(int n): 
    N(n), matrix(n) {
    for (int i = 0; i < n; i++) initial.push_back(i);
  }
};
 
int main(){
  adj_matrix g; // 隣接行列
  adj_matrix::iterator gv;

  string filename;
  cout << "ファイル名：";
  getline(cin,filename);
  ifstream ifs(filename.c_str());
  string str;
  if(ifs.fail()){
    cerr << "失敗" << endl;
    return -1;
  }
  getline(ifs, str);
  int elements = atoi(str.c_str());
  int p[elements];
  for (int i=0; i<elements; i++) {
    getline(ifs, str);
    w.push_back(str);
    //cout << str << endl;
  }
  for(int j=0; j<elements; j++){
    cout << "v[" << j << "] = " << v[j] << endl;
  }
  /*  gv = g.begin();
  while(gv != g.end()){
    cout << g << endl;
    ++gv;
    }*/
  return 0;
}
