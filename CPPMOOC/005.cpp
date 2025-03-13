//OJ_CPPMOOC_005
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
 public:
  void input() {
    int comma_index = 0;
    // get_info_ sample:Tom Hanks,18,7817,80,80,90,70
    getline(cin, get_info_);
    comma_index = get_info_.find(",");
    name_ = get_info_.substr(0, comma_index);
    get_info_.replace(0, comma_index + 1, "");
    comma_index = get_info_.find(",");
    age_ = stoi(get_info_.substr(0, comma_index));
    get_info_.replace(0, comma_index + 1, "");
    comma_index = get_info_.find(",");
    student_id_ = stoi(get_info_.substr(0, comma_index));
    get_info_.replace(0, comma_index + 1, "");
    comma_index = get_info_.find(",");
    avg_score_1_ = stoi(get_info_.substr(0, comma_index));
    get_info_.replace(0, comma_index + 1, "");
    comma_index = get_info_.find(",");
    avg_score_2_ = stoi(get_info_.substr(0, comma_index));
    get_info_.replace(0, comma_index + 1, "");
    comma_index = get_info_.find(",");
    avg_score_3_ = stoi(get_info_.substr(0, comma_index));
    get_info_.replace(0, comma_index + 1, "");
    avg_score_4_ = stoi(get_info_);
  }
  void calculate() {
    avg_score_all_ = float(avg_score_1_ + avg_score_2_ + avg_score_3_ +avg_score_4_) / 4;
  }
  void output() {
    // Sample:Tom Hanks,18,7817,80
    cout << name_ << "," << age_ << "," << student_id_ << "," << avg_score_all_
         << endl;
  }
 private:
  string name_, get_info_;
  unsigned int age_, student_id_;
  unsigned int avg_score_1_, avg_score_2_, avg_score_3_, avg_score_4_;
  float avg_score_all_;
};
//void Student::input() {
//  int comma_index = 0;
//  // get_info_ sample:Tom Hanks,18,7817,80,80,90,70
//  getline(cin, get_info_);
//  comma_index = get_info_.find(",");
//  name_ = get_info_.substr(0, comma_index);
//  get_info_.replace(0, comma_index + 1, "");
//  comma_index = get_info_.find(",");
//  age_ = stoi(get_info_.substr(0, comma_index));
//  get_info_.replace(0, comma_index + 1, "");
//  comma_index = get_info_.find(",");
//  student_id_ = stoi(get_info_.substr(0, comma_index));
//  get_info_.replace(0, comma_index + 1, "");
//  comma_index = get_info_.find(",");
//  avg_score_1_ = stoi(get_info_.substr(0, comma_index));
//  get_info_.replace(0, comma_index + 1, "");
//  comma_index = get_info_.find(",");
//  avg_score_2_ = stoi(get_info_.substr(0, comma_index));
//  get_info_.replace(0, comma_index + 1, "");
//  comma_index = get_info_.find(",");
//  avg_score_3_ = stoi(get_info_.substr(0, comma_index));
//  get_info_.replace(0, comma_index + 1, "");
//  avg_score_4_ = stoi(get_info_);
//}
//void Student::calculate() {
//  avg_score_all_ = float(avg_score_1_ + avg_score_2_ + avg_score_3_ +avg_score_4_) / 4;
//}
//void Student::output() {
//  // Sample:Tom Hanks,18,7817,80
//  cout << name_ << "," << age_ << "," << student_id_ << "," << avg_score_all_
//       << endl;
//}

int main() {
  Student student;        // 定义类的对象
  student.input();        // 输入数据
  student.calculate();    // 计算平均成绩
  student.output();       // 输出数据
}