#include <cstdlib>
#include <string>
#include <iostream>
#include "Animal.h"
using namespace std;

typedef Animal* Animl;

Animl root;

void insertAnimal(Animl animal);
void deleteAnimal(string nombre);
void printList();

int main() {

  insertAnimal(new Animal("gato"));
  insertAnimal(new Animal("perro"));
  insertAnimal(new Animal("pato"));
  insertAnimal(new Animal("pollo"));
  insertAnimal(new Animal("cerdo"));
  printList();

  deleteAnimal("perro");
  deleteAnimal("cerdo");
  deleteAnimal("pato");


  printList();
  return 0;
}

// Insertar nuevo animal
void insertAnimal(Animl animal) {
  if(!root) {
    root = animal;
  } else {
    Animl node = root;
    while(node->getNext()) {
      node = node->getNext();
    }
    node->setNext(animal);
  }
}

// Eliminar animal
void deleteAnimal(string nombre) {
  if(!root) {
    cout<<"Lista vacia\n";
    return;
  } else {
    if(root->getName() == nombre) {
      Animl del = root;
      root = root->getNext();
      cout<<"Se elimino a: "<<del->getName()<<endl;
      delete(del);
      return;
    } else {
      Animl node = root;
      while(node->getNext()) {
        if(node->getNext()->getName() == nombre) {
          Animl del = node->getNext();
          node->setNext(del->getNext());
          cout<<"Se elimino a: "<<del->getName()<<endl;
          delete(del);
          return;
        }
        node = node->getNext();
      }
      cout<<"Animal no encontrado"<<endl;
    }
  }
}

// Imprimir lista de animales
void printList() {
  if(!root) {
    cout<<"Lista vacia"<<endl;
  } else {
    Animl node = root;
    cout<<"Listado de animales:"<<endl;
    do {
      node->sayName();
      node = node->getNext();
    }while(node);
  }
  cout<<endl;
}