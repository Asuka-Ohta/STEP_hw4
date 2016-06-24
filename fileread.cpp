// fileread
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
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
    if(str == "G")
      cout << str << endl;
  }
  return 0;
}
