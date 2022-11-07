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

bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            cout<<"Present on element "<< temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

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

    if (detectLoop(head))
    {
        cout<<"Cycle is present "<<endl;
    }
    else 
    {
        cout<<"No cycle is present";
    }

}
