#ifndef animal_h
#define animal_h
#include<string>
using namespace std;

class Animal {
  public:
    Animal(string);
    void setNext(Animal* next);
    Animal* getNext();
    void sayName();
    string getName();
  private:
    string nombre;
    Animal* next;
};

#endif