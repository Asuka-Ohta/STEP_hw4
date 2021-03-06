// sample
#include <iostream>
#include <vector>
using namespace std;

const double EPS = 1e-9;
typedef float number;
typedef vector<vector<int> > adj_t; // 隣接リスト方式で作る
class PageRank {
private:
  int n; // ページ数
  adj_t a; // リンクデータ
  number alpha; // ランダムに飛ぶ確率
  vector<int> initial; // 最初に値を振るノード
  
  inline double sq(double x) { return x*x; }
  double diff(const vector<number>& prev, const vector<number>& cur) {
    double ret = 0.0;
    for (int i = 0; i < n; i++)
      ret += sq(cur[i]-prev[i]);
    return ret;
  }
public:
  PageRank(int n, number alpha): n(n), a(n), alpha(alpha) {
    for (int i = 0; i < n; i++) initial.push_back(i);
  }
  PageRank(int n, number alpha, vector<int> initial): n(n), a(n), alpha(alpha), initial(initial) {}
  void add_link(int from, int to) {
    a[from].push_back(to);
  }
  vector<number> calc() {
    //シーケンシャルアクセス用にソートしておく。(HDでは重要、今回はほぼ意味なし)
    for (int i = 0; i < n; i++) sort(a[i].begin(), a[i].end());
    
    const int ini_size = initial.size();
    const number beta = 1.0/ini_size; // ベータはつまりこういう意味
    vector<number> prev(n), cur(n, beta);
    do {
      cur.swap(prev);
      cur.clear();
      cur.resize(n);
      for (int i = 0; i < n; i++) {
        const int size = a[i].size();
        const double val = 1.0/size * (1.0-alpha);
        for (int j = 0 ; j < size; j++)
          cur[a[i][j]] += prev[i]*val;
      }
      const number alphabeta = alpha*beta;
      for (int i = 0; i < ini_size; i++)
        cur[initial[i]] += alphabeta;
      
      //for debug
      for (int i = 0; i < n; i++) cerr<<prev[i]<<" "; cerr<<endl;
    } while (diff(prev,cur) > EPS);
    return cur;
  }
};

int main() {
  const number alpha = 0.15;
  int n;
  cin>>n; // ノード数
  PageRank pr(n, alpha);
  for (int i = 0; i < n; i++) {
    int m; 
    cin>>m;
    //assert(m > 0); // 終端ノードがないことを保障
    for (int j = 0; j < m; j++) {
      int k; 
      cin>>k;
      pr.add_link(i,k);
    }
  }
  vector<number> result = pr.calc();
  number sum = 0.0;
  cout<<"\nresult:"<<endl;
  for (int i = 0; i < result.size(); i++) {
    sum += result[i];
    cout<<result[i]<<endl;
  }
  cout<<"sum="<<sum<<endl; // 1にならないとおかしい
  return 0;
}
