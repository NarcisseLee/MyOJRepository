// OJ_CPPMOOC_027
#include <iostream>
#include <string>
using namespace std;
template<class T>
T SumArray(const T *arg1, const T *arg2) {
  T sum = T();  // T constructor initial sum
  for (; arg1 != arg2; ++arg1) {
    sum += *arg1;
  }
  return sum;
}
int main() {
  string array[4] = {"Tom", "Jack", "Mary", "John"};
  cout << SumArray(array, array + 4) << endl;
  int a[4] = {1, 2, 3, 4};  //提示：1+2+3+4 = 10
  cout << SumArray(a, a + 4) << endl;
  return 0;
}