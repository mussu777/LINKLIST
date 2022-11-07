#include<iostream>
using namespace std;

/**********************************************************************


following is the class structure of the Node code:

class Node 
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this-> data = data;
        this-> next = NULL;
    }
};

************************************************************************/
      
  //    ITERATION SOLUTION (APPROACH 1)

Node* reverseLinkedList(Node* head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head;

    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr != NULL)
    {
        forward = curr-> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}


//  RECURRSION (APPROACH 2)

void reverse (Node* &head , Node* curr , Node* prev)
{
    // base case 
    if(curr == NULL)
    {
        head = prev;
        return ;
    }

    Node* forward = curr ->next;
    reverse(head , forward , curr);
    curr -> next = prev;
} 

/// RECURRSION (APPROACH 3)

Node* reverse1 (Node* head)
{
    //BASE CASE 
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node* chotaHead = reverse1(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return chotaHead;
}