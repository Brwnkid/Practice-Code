#include <iostream>
#include <cstdlib>

using namespace std;

template<class G> class Node{
public:
  Node(){};
  ~Node(){delete next;};
  G value;
  Node<G>* next;
};

template <class T> class Llist{
public:
	Llist(){
  head = NULL;
  tail = NULL;
  mySize = 0;
  }

  ~Llist(){
    delete head;
  }

  void prepend(T &value){
    if(head == NULL){ //list is empty
      head = new Node<T>;
      head->next = NULL;
      head->value = value;
      tail = head;
      mySize++;
      return;
    }
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
    mySize++;
  }

	void push_back(T &value){
    if(tail == NULL){
      tail = new Node<T>;
      tail->next = NULL;
      tail->value = value;
      head = tail;
      mySize++;
      return;
    }
    Node<T>* newNode = new Node<T>;
    newNode->next = NULL;
    newNode->value = value;
    tail->next = newNode;
    tail = newNode;
    mySize++;
  }

	bool isEmpty(){
    return (mySize > 0);
  }

  T getAt(int location){
    if(location < 0){
      location += mySize;
    }else if(location >= mySize){
      return 0;
    }
    Node<T>* loc = head;
    for(int i = 0; i < location; i++){
      loc = loc->next;
    }
    return loc->value;
  }

  T setAt(int location, T value){
    if(location < 0){
      location += mySize;
    }else if(location >= mySize){
      return 0;
    }
    Node<T>* loc = head;
    for(int i = 1; i < location; i++){
      loc = loc->next;
    }
    loc->value = value;
  }

  unsigned int size(){
    return mySize;
  }

private:
	Node<T>* head;
  Node<T>* tail;
  unsigned int mySize;
};
