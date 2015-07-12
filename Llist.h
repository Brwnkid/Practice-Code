#include <iostream>
#include <cstdlib>

using namespace std;

template<class G> class Node{  //Node class for Linked list
public:                        //Everything is public so it can be accessed by the linked list class
  Node(){};
  ~Node(){delete next;};       //Can delete the entire linked list from head node!
  G value;                     //Value in the current node
  Node<G>* next;               //Pointer to the next node in the list
};

template <class T> class Llist{
public:
	Llist(){ //Constructor
  head = NULL;  //Sets head and tail to NULL and size to 0
  tail = NULL;
  mySize = 0;
  }

  ~Llist(){   //deconstructor - Deletes head node, which will delete the entire linked list
    delete head;
  }

  void prepend(T &value){           //places value at the head of the linked list
    if(head == NULL){               //If list is empty
      head = new Node<T>;
      head->next = NULL;
      head->value = value;
      tail = head;                  //Sets tail to point to head node if list is empty
      mySize++;
      return;                       //ends prepend
    }
    Node<T>* newNode = new Node<T>; //If list is not empty
    newNode->value = value;
    newNode->next = head;           //points newNode next to the current head of list
    head = newNode;                 //newNode becomes head of the list
    mySize++;                       //size of list goes up.
  }

	void push_back(T &value){        //adds new node at the end of the list
    if(tail == NULL){              //if list is empty
      tail = new Node<T>;          //creates new tail node
      tail->next = NULL;
      tail->value = value;
      head = tail;                 //list is empty so tail node is the same as head
      mySize++;                    //increases size
      return;
    }
    Node<T>* newNode = new Node<T>;   //if list is not empty creates new node at tail
    newNode->next = NULL;             //sets next pointer to NULL
    newNode->value = value;
    tail->next = newNode;             //sets current tail node next to be the new node
    tail = newNode;                   //sets tail to new node
    mySize++;
  }

	bool isEmpty(){                    //Returns if list is empty or not;
    return (mySize <= 0);
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

  void printList(){ //Prints entire linked list
    Node<T>* cur = head;
    while(cur!=NULL){
      cout << cur->value << " ";
      cur = cur->next;
    }
    cout << endl;
  }

  unsigned int size(){
    return mySize;
  }

private:
	Node<T>* head;
  Node<T>* tail;
  unsigned int mySize;
};
