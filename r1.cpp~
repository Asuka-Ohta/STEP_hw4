// r1.cpp
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
using namespace std;

typedef map<string, vector<int> > adj_matrix; //隣接行列

class Pagerank {
private:
  adj_matrix matrix; // 隣接行列
  int N; // 要素数
public:
  int set_N();
  PageRank(int n, number alpha): n(n), a(n), alpha(alpha) {
    for (int i = 0; i < n; i++) initial.push_back(i);
  }
};

int Pagerank::set_N(int x) {
  x > N;
}
  
int main(){
  adj_matrix g; // 隣接行列
  adj_matrix::iterator gv;
  vector<int> v; 
  vector<string> w; // 要素の配列
  float number = 100.; // 各要素にはじめに与えられる値

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
