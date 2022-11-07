/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

// FROM SORTED LIST CODE
Node * uniqueSortedList(Node * head) {
   	//empty List
    if(head == NULL)
        return NULL;
    
    //non empty list
    Node* curr = head;
    
    while(curr != NULL) {
        
        if( (curr -> next != NULL) && (curr -> data == curr -> next -> data)) {
            Node* next_next = curr ->next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else //not equal
        {
            curr = curr -> next;
        }   
    }
    
    return head; 
}


//    FROM UNSORTED LIST  CODE
Node* RemoveDuplicatesFromUnsortedList(Node* head) {
    Node* current = head;
    Node* prev = NULL;

    if(current == NULL) {
        cout << "Node not created!\n";
        return NULL;
    }

    unordered_map<int, int> visited;
    while (current != NULL)
    {
        if(!visited[current->val]) {
            visited[current->val] = 1;

            prev = current;
            current = current->next;
        }
        else {
            Node* nextNode = current->next;
            prev->next = nextNode;

            delete(current);
            current = nextNode;
        }
    }
    
    return head;
}




