#ifndef LABEXERCISE7_H_INCLUDED

#define LABEXERCISE7_H_INCLUDED





//Student Name: Nhat Nguyen

//Student ID: 1793410

//Peer's name: Shifa

template <typename V>



class Stack{



  struct Node
  {
    V value;
    Node* next;
  };

  Node* firstNode; // the head pointer
  int siz; // tracking the number of nodes
  V dummy = V();



public:

    Stack(); /**/

    Stack(const Stack<V>&); /**/

    ~Stack(); /**/

    Stack<V>& operator=(const Stack<V>&);

    void push(const V&); /**/

    const V& peek() const; /**/

    void pop() ; /**/

    void clear() ;/**/

    int size() const {return siz;} /**/

    bool empty() const {return siz == 0 ? true : false ;} /**/





};



template<typename V>

Stack<V>::Stack(){

    siz = 0;

    firstNode = NULL;

}




template <typename V>
Stack<V>::~Stack( )
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}




template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
  firstNode = 0;
  Node* lastNode = 0; // temporary tail
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->value = p->value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

template<typename V>
void Stack<V>::push(const V& val){
  Node* temp = new Node;
  temp->value = val;
  temp->next = firstNode;
  firstNode = temp;
  ++siz;

}

template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
  if (this != &original)
  {
    // deallocate existing list
    while (firstNode)
    {
      Node* p = firstNode;
      firstNode = firstNode->next;
      delete p;
    }

    // build new queue
    Node* lastNode = 0; // temporary tail
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->value = p->value;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}





template <typename V>
void Stack<V>::pop( )
{
  if (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
}


template <typename V>
void Stack<V>::clear( )
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
}



template<typename V>
const V& Stack<V>::peek() const{

    if(firstNode == 0){
        return dummy;
    }
    return firstNode->value;

}













#endif // LABEXERCISE7_H_INCLUDED

