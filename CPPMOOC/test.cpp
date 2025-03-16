//int ArraySort(int *p, int length) {
//  for (int i = 0; i < length - 1; ++i) {
//    int temp = 0;
//    for (int j = i+1; j < length; ++j) {
//      if(p[i] > p[j]) {
//        p[j] = temp;
//        p[j] = p[i];
//        p[i] = temp;
//      }
//    }
//  }
//}


//#include <cstdlib>
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//  string s1 = "1", s2 = "3";
//  string s3 = "987";
//  s3[0] = "a";
//  s3[1] = "5";
//  cout << s1 << endl << s2 << endl;
//  s3 = s1 + s2;
//  cout << s3[1] << endl;
//  char *s;
//  s = new char[10];
//  s[0] = '1';
//  s[1] = '2';
//  cout << strlen(s) << endl;
//}



//
//// OJ_CPPMOOC_028
//#include <iostream>
//#include <string>
//using namespace std;
//// 在此处补充你的代码
//
//template<class T1, class T2>
//void MyForeach(T1 arg1, T1 arg2, T2 op) {
//  for (; arg1 != arg2; ++arg1) {
//    op(*arg1);
//  }
//}
//
//void Print(string s) {
//  cout << s;
//}
//void Inc(int &n) {
//  ++n;
//}
//string array_[100];
//int a[100];
//int main() {
//  int m, n;
//  while (cin >> m >> n) {
//    for (int i = 0; i < m; ++i)
//      cin >> array_[i];
//    for (int j = 0; j < n; ++j)
//      cin >> a[j];
//    MyForeach(array_, array_ + m, Print);
//    cout << endl;
//    MyForeach(a, a + n, Inc);
//    for (int i = 0; i < n; ++i)
//      cout << a[i] << ",";
//    cout << endl;
//  }
//  return 0;
//}


#include <iostream>
using namespace std;
int main() {
  int *p;
  int a = 1;
  p = &a;
  *p = 2;
  cout << a << endl;
}

