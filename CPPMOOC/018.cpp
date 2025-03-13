// OJ_CPPMOOC_018
// TODO
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt {
// 在此处补充你的代码
 public:
//  char *str_[201] = {"0"};
  char *str_ = nullptr;
  CHugeInt() {
    str_ = new char[2];
    str_[0] = '0';
    str_[1] = '\0';
  }
  CHugeInt(const char *s) {
    int length = 0, i = 0;
    length = strlen(s);
    str_ = new char[length + 1];
    for (i = 0; i < length; ++i) {
      str_[i] = s[i];
    }
    str_[i] = '\0';
  }
  CHugeInt(const int n) {
    int length = 0, i = 0, t;
    t = n;
    for (i = 0; t >= 10 ; ++i) {
      t /= 10;
    }
    length = i + 1;
    str_ = new char[length + 1];
    t = n;
    for (int j = length; j > 0; --j) {
      str_[j-1] = '0' + (t % 10);
      t /= 10;
    }
    str_[length] = '\0';
  }

  friend CHugeInt &operator+(const CHugeInt &a, const CHugeInt &b) {
    CHugeInt c;
    int carry_flag = 0;
    int length_min =
        (strlen(a.str_) > strlen(b.str_) ? strlen(b.str_) : strlen(a.str_));
    int length_max =
        (strlen(a.str_) > strlen(b.str_) ? strlen(a.str_) : strlen(b.str_));
    c.str_ = new char[length_max + 2];
    if (strlen(a.str_) > strlen(b.str_)) {
      strcpy(c.str_ + 1, a.str_);
      c.str_[0] = '0';
      c.str_[length_max + 1] = '\0';
      for (int i = length_min - 1; i >= 0; --i) {
        if (carry_flag == 1) {
          // TODO
        }
      }
    }
    for (int i = length_min - 1; i >= 0; --i) {

    }
  }

  ~CHugeInt() {
    if (str_) {
      delete []str_;
    }
  }

};
int  main()
{
  char s[210];
  int n;

  while (cin >> s >> n) {
    CHugeInt a(s);
    CHugeInt b(n);

    cout << a + b << endl;  // overloading +
    cout << n + a << endl;  // overloading +
    cout << a + n << endl;  // overloading +
    b += n;  // overloading +=
    cout  << ++ b << endl;  // overloading ++
    cout << b++ << endl;  // overloading ++
    cout << b << endl;  // overloading <<
  }
  return 0;

// test code
//  cin >> s >> n;
//  cout << s << n;
}
