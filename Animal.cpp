#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal(string nombre) {
  this->nombre = nombre;
  this->next = NULL;
}

void Animal::setNext(Animal* next) {
  this->next = next;
}

Animal* Animal::getNext() {
  return this->next;
}

void Animal::sayName() {
  cout<<"Yo soy un: "<<nombre<<endl;
}

string Animal::getName() {
  return this->nombre;
}