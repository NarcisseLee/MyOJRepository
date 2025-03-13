// OJ_CPPMOOC_015
#include <iostream>
using namespace std;
class MyInt {
  int nVal;
 public:
  MyInt(int n) { nVal = n; }
  friend MyInt &operator-(MyInt &cn, const int n) {
    cn.nVal -= n;
    return cn;
  }
  friend int Inc(MyInt &cn) {
    return cn.nVal + 1;
  }
};
int Inc(int n) {
  return n + 1;
}
int main() {
  int n;
  while (cin >> n) {
    MyInt objInt(n);
    objInt - 2 - 1 - 3;
    cout << Inc(objInt);
    cout << ",";
    objInt - 2 - 1;
    cout << Inc(objInt) << endl;
  }
  return 0;
}
