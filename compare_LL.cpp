int CompareLists(Node *headA, Node* headB)
{
  Node* curA = headA;
  Node* curB = headB;
  while(curA != NULL && curB != NULL){
    if(curA->data != curB->data){
      return false;
    }
    curA = curA->next;
    curB = curB->next;
  }
  if(curA != curB){
    return false;
  }
  return true;
  
}
