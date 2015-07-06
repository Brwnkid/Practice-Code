template<class G> class Node{
public:
  Node();
  ~Node(delete next);
  G value;
  Node*<G> next;
}

template <class T>
class Llist{
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
      head = new Node*<T>;
      head.next = NULL;
      head.value = value;
      tail = head;
      mySize++;
      return;
    }
    Node*<T> newNode = new Node*<T>;
    newNode.value = value;
    newNode.next = head;
    head = newNode;
  }
	void pop();
	bool isEmpty();
	T top() const;
private:
	Node*<T> head;
  Node*<T> tail;
  unsigned int mySize = 0;
};
