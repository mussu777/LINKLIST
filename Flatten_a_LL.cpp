Node* merge(Node* left, Node* right){
    
    Node* ans = new Node(0);
    Node* temp = ans;
    while(left != NULL && right != NULL){
        if(left-> data <= right->data){
            temp -> child = left;
            left = left-> child;
            temp = temp->child;
            temp-> next = NULL;
        }else{
            temp-> child = right;
            right= right-> child;
            temp = temp->child;
            temp->next = NULL;
          
      }
    }
    if(left){
        temp-> child = left;
    }else{
        temp-> child = right;
    }
    
    return ans-> child;
    
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head == NULL || head-> next == NULL){
        return head;
    }
    Node* down = head;
    Node* right = flattenLinkedList(head->next);
    Node* res = merge(down, right);
    return res;
}