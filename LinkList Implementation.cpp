#include<iostream>
using namespace std;

// Creating Node Class For linklist
class node{
    public:
    int data;
    node* next; 
   // Iniatializing a constructor to send val
    node(int val)
    {
        data = val;
        next =NULL;
    }
};

void insertAtHead(node* &head,int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}

// Taking head by reference here , not by value
void insertAtTail(node* &head,int val)
{
   node* n = new node(val);
   node* temp = head;
   if(head == NULL)
   {
       head = n;
       return;
   }
   while(temp->next != NULL)
   {
    temp = temp->next;
   }
   temp->next = n;
}

// Taking head by value here
void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

bool search(node* head,int key)
{
    node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;

    delete todelete;
}


// Taking head by reference here ,
void deletion(node* &head,int val)
{
    //Handling corner cases
    if(head == NULL)
    {
        cout<<"LinkList Is Empty"<<endl;
        return;
    }
    if(head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while(temp->next->data != val)
    {
        temp = temp->next;
    }
    // Assigning N th node ie node to be deleted to todelete node 
    node* todelete = temp->next;
    // Shifting the link from (N-1)th node to (N +1)th node
    temp->next = temp->next->next;

    delete todelete;
}


int main()
{
   node* head = NULL;
   insertAtTail(head,1);
   insertAtTail(head,2);
   insertAtTail(head,3);
   insertAtTail(head,4);
   display(head);
//    insertAtHead(head,0);
//    display(head);
//    cout<<search(head,4)<<endl;
//    cout<<search(head,5)<<endl;
//deletion(head,3);
   deleteAtHead(head);
   display(head);
    return 0;
}