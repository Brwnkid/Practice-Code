Node* MergeLists(Node *headA, Node* headB)
{
  Node* newHead = NULL;
  Node* newTail = NULL;
  Node* curA = headA;
  Node* curB = headB;
  if(curA == NULL && curB == NULL){
    return newHead; 
  }else if(curA == NULL){
    newHead = curB;
    curB=curB->next;
  }else if(curB == NULL){
    newHead = curA;
    curA = curA->next;
  }else if(curA->data <= curB->data){
    newHead = curA;
    curA=curA->next;    
  }else{
    newHead = curB;
    curB=curB->next;
  }
  newTail = newHead;
  while(curA != NULL || curB != NULL){
    if(curA == NULL){
      newTail->next = curB;
      curB=curB->next;
      newTail=newTail->next;
    }else if(curB == NULL){
      newTail->next = curA;
      curA=curA->next;
      newTail=newTail->next;
    }else if(curA->data <= curB->data){
      newTail->next = curA;
      curA=curA->next;
      newTail=newTail->next;      
    }else{
      newTail->next = curB;
      curB=curB->next;
      newTail=newTail->next;
    }
  }
  newTail->next = NULL;
  return newHead;
}
