void splitCLL(Node* head, Node** head1, Node** head2){
    
    Node* slow = head;
    Node* fast = head;

    while(fast -> next != head && fast -> next -> next != head){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    // After above steps slow is pointing mid and fast is pointing last node
    if(fast -> next -> next == head){
        fast = fast -> next;
    }
    // Set the head pointer of first half 
    *head1 = head;

    // Set the head pointer of second half
    if (head -> next != head){
        *head2 = slow -> next;
    }

    // Make second half circular
    fast -> next = slow -> next;
    
    // Make first half circular
    slow -> next = head;
    
}