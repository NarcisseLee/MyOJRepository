// OJ_CPPMOOC_026
#include <iostream>
using namespace std;
class Animal {
 public:
  static unsigned int number;
  Animal() {
    number++;
  }
  virtual ~Animal() {
    number--;
  }
};
class Dog : public Animal {
 public:
  static unsigned int number;
  Dog() {
    number++;
  }
  ~Dog() {
    number--;
  }
};
class Cat : public Animal {
 public:
  static unsigned int number;
  Cat() {
    number++;
  }
  ~Cat() {
    number--;
  }
};

unsigned int Animal::number = 0;
unsigned int Dog::number = 0;
unsigned int Cat::number = 0;

void print() {
  cout << Animal::number << " animals in the zoo, " << Dog::number
       << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
  print();
  Dog d1, d2;
  Cat c1;
  print();
  Dog *d3 = new Dog();
  Animal *c2 = new Cat;
  Cat *c3 = new Cat;
  print();
  delete c3;
  delete c2;
  delete d3;
  print();
}