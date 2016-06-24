#include <map>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef map<int, vector<int> > AdjacentMatrix; //隣接行列

class PageRank {
private:
  AdjacentMatrix graph_; //リンクデータ
  map<int, double> pagerank_; //
  map<int, double> temprank_; //
  int N_; //ページ数
  double damping_; //

public:
  PageRank(AdjacentMatrix graph, int n, double damping = 0.85) {
	graph_ = graph;
	N_ = n;
	damping_ = damping;
	
	for (AdjacentMatrix::iterator it = graph_.begin(); it != graph_.end(); it++) {
// 	  cout << it->first << ": ";
// 	  for (vector<int>::iterator jit = it->second.begin(); jit != it->second.end(); jit++) {
// 		cout << *jit << " ";
// 	  }
	  cout << endl;
	  pagerank_[it->first] = 1.0 / N_;
	  temprank_[it->first] = 0.0;
	}

	for (int iter = 0; iter < 100; iter++) {
	  double change = 0.0;
	  double total = 0.0;

	  for (AdjacentMatrix::iterator it = graph_.begin(); it != graph_.end(); it++) {
		int node = it->first;
		vector<int> out_edges = it->second;
		int out = out_edges.size();
		for (vector<int>::iterator jit = out_edges.begin(); jit != out_edges.end(); jit++) {
		  temprank_[*jit] += pagerank_[node] / out;
		}
	  }

	  for (AdjacentMatrix::iterator it = graph_.begin(); it != graph_.end(); it++) {
		int node = it->first;
		temprank_[node] = (1.0 - damping_) / N_ + damping * temprank_[node];
		change += fabs(pagerank_[node] - temprank_[node]);
		pagerank_[node] = temprank_[node];
		temprank_[node] = 0.0;
		total += pagerank_[node];
	  }

	  for (AdjacentMatrix::iterator it = graph_.begin(); it != graph_.end(); it++) {
		int node = it->first;	  
		pagerank_[node] /= total;
	  }
	  cout << "Convergence: " << change << endl;
	}
	for (map<int, double>::iterator it = pagerank_.begin(); it != pagerank_.end(); it++) {
	  cout << it->first << "\t" << it->second << endl;
	}
  };
};

int main(int argc, char **argv) {
  AdjacentMatrix g;
  vector<int> v;
  
  v.push_back(3);
  v.push_back(4);
  g[1] = v;
  v.clear();

  v.push_back(3);
  v.push_back(4);
  g[2] = v;
  v.clear();

  v.push_back(1);
  v.push_back(2);
  g[3] = v;
  v.clear();

  v.push_back(2);
  v.push_back(3);
  g[4] = v;
  v.clear();

  PageRank(g, 4, 0.8);

  return 0;
}

/*
[4]
1
2
3
4
[8]
13
14
23
24
31
32
42
43
*/
