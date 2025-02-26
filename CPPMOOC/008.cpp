///OJ_CPPMOOC_008
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    Complex() {
        r = 0;
        i = 0;
    }
    Complex(char a[]) {
        r = a[0] - '0';
        i = a[2] - '0';
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}