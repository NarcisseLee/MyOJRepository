// OJ_CPPMOOC_019
#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char *s) {
  int i = 0;
  for (; s[i]; ++i);
  return i;
}
void strcpy(char *d, const char *s) {
  int i = 0;
  for (i = 0; s[i]; ++i)
    d[i] = s[i];
  d[i] = 0;
}
int strcmp(const char *s1, const char *s2) {
  for (int i = 0; s1[i] && s2[i]; ++i) {
    if (s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
  }
  return 0;
}
void strcat(char *d, const char *s) {
  int len = strlen(d);
  strcpy(d + len, s);
}
class MyString {
 public:
  char *string_;
  int length_;
  MyString() {
    string_ = NULL;
    length_ = 0;
  }
  MyString(const char * s1) {
    length_ = strlen(s1);
    string_ = new char[length_+1];
    strcpy(string_, s1);
    string_[length_] = '\0';
  }
  MyString(const MyString &ms1) {
    if (ms1.string_) {
      length_ = ms1.length_;
      string_ = new char[length_ + 1];
      strcpy(string_, ms1.string_);
    } else {
      length_ = 0;
      string_ = NULL;
    }
  }

  friend ostream &operator<<(ostream &os, const MyString &ms1) {
    if (ms1.length_) {
      os << ms1.string_;
    }
    return os;
  }
  MyString &operator=(const MyString &ms_src) {
    if (this == &ms_src) {
      return *this;
    }
    if (this->length_) {
      delete []this->string_;
    }
    this->length_ = ms_src.length_;
    this->string_ = new char[ms_src.length_ + 1];
    strcpy(this->string_, ms_src.string_);
    return *this;
  }
  friend MyString operator+(const MyString &ms1, const MyString &ms2) {
    MyString ms3;
    if (ms1.length_ || ms2.length_) {
      ms3.length_ = ms1.length_ + ms2.length_;
      ms3.string_ = new char[ms3.length_ + 1];
      if (ms1.length_) {
        strcpy(ms3.string_, ms1.string_);
        strcat(ms3.string_, ms2.string_);
      } else {
        strcpy(ms3.string_, ms2.string_);
      }
    }
    return ms3;
  }
  MyString &operator+=(const char *s) {
    if (s) {
      this->length_ += strlen(s);
      strcat(this->string_, s);
    }
    return *this;
  }
  friend int operator<(const MyString &ms1, const MyString &ms2) {
    if (strcmp(ms1.string_, ms2.string_) == -1) {
      return 1;
    }
    return 0;
  }
  friend int operator>(const MyString &ms1, const MyString &ms2) {
    if (strcmp(ms1.string_, ms2.string_) == 1) {
      return 1;
    }
    return 0;
  }
  friend int operator==(const MyString &ms1, const MyString &ms2) {
    if (strcmp(ms1.string_, ms2.string_) == 0) {
      return 1;
    }
    return 0;
  }
  char &operator[](const int index) {
    return (this->string_[index]);
  }
  MyString operator()(const int index, const int length) {
    MyString ms;
    int i;
    if ((index >= 0) && (index < this->length_)
        && (this->length_ >= (index + length))) {
      ms.length_ = length;
      ms.string_ = new char[ms.length_ + 1];
      for (i = 0; i < length; ++i) {
        ms.string_[i] = this->string_[i+index];
      }
      ms.string_[i] = '\0';
    }
    return ms;
  }

  ~MyString() {
    if (length_) {
      delete []string_;
      string_ = NULL;
    }
  }

};

int CompareString(const void *e1, const void *e2) {
  MyString *s1 = (MyString *) e1;
  MyString *s2 = (MyString *) e2;
  if (*s1 < *s2)  // overloading <
    return -1;
  else if (*s1 == *s2)  // overloading ==
    return 0;
  else if (*s1 > *s2)  // overloading >
    return 1;
}
int main() {
  MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);  // constructor
  MyString SArray[4] = {"big", "me", "about", "take"};
  cout << "1. " << s1 << s2 << s3 << s4 << endl;  // 1. abcd-efgh-abcd-  // overloading <<
  s4 = s3;
  s3 = s1 + s3;  // overloading +
  cout << "2. " << s1 << endl;  // 2. abcd-
  cout << "3. " << s2 << endl;  // 3.
  cout << "4. " << s3 << endl;  // 4. abcd-efgh-
  cout << "5. " << s4 << endl;  // 5. efgh-
  cout << "6. " << s1[2] << endl;  // 6. c  // overloading[]
  s2 = s1;  // overloading =
  s1 = "ijkl-";
  s1[2] = 'A';  // overloading = ?
  cout << "7. " << s2 << endl;  // 7. abcd-
  cout << "8. " << s1 << endl;  // 8. ijAl-
  s1 += "mnop";  // overloading +=
  cout << "9. " << s1 << endl;  // 9. ijAl-mnop
  s4 = "qrst-" + s2;  // notice overloading +
  cout << "10. " << s4 << endl;  // 10. qrst-abcd-
  s1 = s2 + s4 + " uvw " + "xyz";
  cout << "11. " << s1 << endl;  // 11. abcd-qrst-abcd- uvw xyz
  qsort(SArray, 4, sizeof(MyString), CompareString);
  for (int i = 0; i < 4; i++)
    cout << SArray[i] << endl; // about big me take
  //s1的从下标0开始长度为4的子串
  cout << s1(0, 4) << endl;  // abcd  // overloading ()
  //s1的从下标5开始长度为10的子串
  cout << s1(5, 10) << endl;  // qrst-abcd-
  return 0;
}