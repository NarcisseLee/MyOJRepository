//OJ_CPPMOOC_006
#include <iostream>
using namespace std;
class Sample {
public:
    int v;
    Sample(void) {
        v = 0;
    }
    Sample(int vi) {
        v = vi;
    }
    Sample(Sample & S) {
        if (S.v == 5) {
            v = 9;
        }
        else if (S.v == 20) {
            v = 22;
        }
        else {
            v = S.v;
        }
    }
};
void PrintAndDouble(Sample o)
{
    cout << o.v;
    cout << endl;
}
int main()
{
    Sample a(5);
    Sample b = a;
    PrintAndDouble(b);
    Sample c = 20;
    PrintAndDouble(c);
    Sample d;
    d = a;
    cout << d.v;
    return 0;
}