// OJ_CPPMOOC_030
#include <iostream>
using namespace std;
class MyCin {
 public:
  MyCin &operator>>(int &t) {
    cin >> t;
    if (t == -1) {
      status_ = false;
    }
    return *this;
  }
  explicit operator bool() const {
    return status_;
  }
  MyCin() : status_(true) {}
 private:
  bool status_;
};
int main() {
  MyCin m;
  int n1, n2;
  while (m >> n1 >> n2)
    cout << n1 << " " << n2 << endl;
  return 0;
}