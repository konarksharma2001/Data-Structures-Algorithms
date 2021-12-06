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

node* reverseRecursive(node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head-> next =  NULL;

    return newhead;
}

int main()
{
   node* head = NULL;
   insertAtTail(head,1);
   insertAtTail(head,2);
   insertAtTail(head,3);
   insertAtTail(head,4);
   display(head);
   node* newhead = reverseRecursive(head);
   display(newhead);

   
    return 0;
}