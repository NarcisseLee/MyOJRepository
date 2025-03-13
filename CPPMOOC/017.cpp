// OJ_CPPMOOC_017
#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
 public:
  int **p;
  int row, col;

  Array2() {
    p = NULL;
    row = 0;
    col = 0;
  }
  Array2(int i, int j) {
    if (i && j) {
      row = i;
      col = j;
      p = (int **) malloc(row * sizeof(int *));
      for (int k = 0; k < row; ++k) {
        p[k] = (int *) malloc(col * sizeof(int));
      }
    } else {
      row = 0;
      col = 0;
      p = NULL;
    }
  }

  int *operator[](int i) {
    return p[i];
  }
  int &operator()(int i, int j) {
    return p[i][j];
  }
  Array2 &operator=(Array2 &b) {
    if (p == b.p) {
      return *this;
    }
    if (b.p == NULL) {
      if (p) {
        for (int i = 0; i < row; ++i) {
          free(p[i]);
        }
        free(p);
      }
      p = NULL;
      row = 0;
      col = 0;
      return *this;
    }
    if (p) {
      for (int i = 0; i < row; ++i) {
        free(p[i]);
      }
      free(p);
    }
    row = b.row;
    col = b.col;
    p = (int **) malloc(row * sizeof(int *));
    for (int k = 0; k < row; ++k) {
      p[k] = (int *) malloc(col * sizeof(int));
    }
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        p[i][j] = b.p[i][j];
      }
    }
    b.p[0][0] = 1;
    return *this;
  }

  ~Array2() {
    if (p) {
      for (int i = 0; i < row; ++i) {
        free(p[i]);
      }
      free(p);
    }
  }
};

int main() {
  Array2 a(3, 4);  // new constructor
  int i, j;
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 4; j++)
      a[i][j] = i * 4 + j;  // []
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 4; j++) {
      cout << a(i, j) << ",";  // a()
    }
    cout << endl;
  }
  cout << "next" << endl;
  Array2 b;
  b = a;  //  new constructor; =：with the destructor， notice deep copy
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 4; j++) {
      cout << b[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}
