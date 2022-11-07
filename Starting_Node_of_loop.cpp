#include<iostream>
#include<map>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
    // constructor 
    Node (int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor 
    ~Node ()
    {
        int value = this -> data;
        if( this-> next != NULL)
        {
            delete next;
           this-> next = NULL;
        }
        cout<<"memory is free for node with data "<< value <<endl;
    }

};

void insertAtHead (Node* &head , int d)
{
    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail (Node* &tail , int d)
{
    // new node create
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;

}

void print(Node* &head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

void insertAtPosition (Node* &tail , Node* &head , int position , int d)
{
    // insert at start
    if (position == 1)
    {
        insertAtHead(head , d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }

    /// inserting at last position 
    if (temp -> next == NULL)
    {
        insertAtTail(tail , d);
        return ;
    }

    //creating a node for d 
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp ->next;
    temp -> next = nodeToInsert;
}

void deleteNode(Node* &tail , int position , Node* &head)
{
    // deleting first or start node 
    if(position == 1)
    {
        Node* temp = head;
        head = head -> next;

        // memory free start node 
        temp -> next = NULL;
        delete temp;
    }
    else 
    {
        // deleting any middle node or last node 
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if (curr-> next == NULL)
        {
            // prev -> next = NULL;
            prev -> next = curr -> next;
            tail = prev;
        }
        else
        {
            prev -> next = curr -> next;
            curr -> next = NULL;
        }

        delete curr;

    }

}


Node* floydDetectLoop(Node* head)
{
    if (head == NULL)
    return NULL;

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
        if(slow == fast)
        {
            cout<<"Present at "<< slow->data <<endl;
            return slow;
        }
    }

    return NULL;
}


Node*getStartingNode(Node* head)
{
    if(head == NULL)
    return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection)
    {
        slow = slow-> next;
        intersection = intersection -> next;
    }

    return slow;
}


int main()
{
    Node* node1 = new Node(10);
    // cout<< node1->data <<endl;
    // cout<< node1->next <<endl;

    Node* head = node1;    
    Node* tail = node1;
    print (head);

    insertAtTail(tail , 12);
    print (head);

    insertAtTail(tail , 15);
    print (head);

    cout<<"head is in : "<< head->data <<endl;
    cout<<"tail is in : "<< tail->data <<endl;

    insertAtPosition(tail , head , 4, 22);
    print(head);

    cout<<"head is in : "<< head->data <<endl;
    cout<<"tail is in : "<< tail->data <<endl;

    // deleteNode(tail , 3, head);
    // print(head);

    tail-> next = head->next;

    // cout<<"head is in : "<< head->data <<endl;
    // cout<<"tail is in : "<< tail->data <<endl;
    // print(head);

    if (floydDetectLoop(head) != NULL)
    {
        cout<<"Cycle is present "<<endl;
    }
    else 
    {
        cout<<"No cycle is present";
    }
    
    Node* loop = getStartingNode(head);
    cout<< "loop starts at "<<loop -> data <<endl;
}
