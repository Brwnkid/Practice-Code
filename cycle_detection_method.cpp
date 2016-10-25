bool has_cycle(Node* head) {
  Node* slow = head;
  Node* fast = head;
  while(fast && fast->next){
    if(fast->next == slow || fast->next->next == slow){
      return true;
    }
    fast=fast->next->next;
    slow=slow->next;
  }
  return false;
  
}
