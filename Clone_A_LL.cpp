
/// APPROACH 1

class Solution
{
    private:
    void insertAtTail(Node* &head, Node* &tail, int d)
    {
        Node* newNode = new Node(d);
        if (head == newNode)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else 
        {
            tail -> next = newNode;
            tail = newNode;
        }

    }

    public:

    Node* copyList(Node* head)
    {

        // steps 1: create a clone linkedList
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;

        while (temp != NULL)
        {
            insertAtTail(cloneHead , cloneTail , temp->data);
            temp = temp -> next;
        }

        // step : 2 Create a Map
        unordered_map<Node* , Node*> oldToNewNode;

        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;  
        }

        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL )
        {
            cloneNode -> random = oldToNew[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }

        return cloneHead;

    }
};


***************************************************************************************************

// APPROACH 2

class Solution
{
   private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    void print(Node* head) {
        while(head != NULL) {
            cout << head -> data << " ";
            head = head -> next;
        }cout << endl;
    }

    void printRandom(Node* head) {
        while(head != NULL) {
            cout << " head data: " << head->data <<" ";
            if(head ->arb != NULL) {
                cout << " head random data" << head -> arb ->data;
            }
            else
            {
                cout << " head random data: NULL";
            }
            head = head -> next;
            cout << endl;
        }
    }

    public:
    Node *copyList(Node *head)
    {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // step 2: insert nodes of Clone List in between originalList
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        // step 3: Random pointer copy
        temp = head;

        while(temp != NULL)
        {
        if(temp -> next != NULL)
        {
            temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
        }
        temp = temp -> next -> next;
        }
        
        //step 4: revert step 2 changes
        originalNode = head;
        cloneNode = cloneHead;
        
        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode -> next = cloneNode -> next;
            originalNode -> originalNode -> next;

            if(originalNode != NULL)
            {
                cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }
        
        // step 5 answer return
        return cloneHead;
    }
};
