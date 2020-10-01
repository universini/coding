#include <bits/stdc++.h>
using namespace std;

struct DLL{
  int data;
  DLL *next;
  DLL *prev;
};

void insertAtBeginning(struct DLL **head, int X)
{
  struct DLL * curr = new DLL;
  curr->data = X;
  curr->prev = NULL;
  curr->next = *head;
  if(*head != NULL)
  (*head)->prev = curr;
  *head = curr;
  
}

void deleteNode(struct DLL **head, struct DLL *ptr)
{
  if(*head == NULL || ptr == NULL)
    return;
 
 //if the node is head
  if(*head == ptr)
    *head = ptr->next;
 
  //change the next and prev only if they are not null
  if(ptr->next != NULL)
    ptr->next->prev = ptr->prev;
 
  if(ptr->prev != NULL)
    ptr->prev->next = ptr->next;     
 
   delete(ptr); //delete the node
 
}

void display(struct DLL**head)
{
  struct DLL*temp=*head;
  while(temp!=NULL)
    {
      if(temp->next!=NULL)
      cout<<temp->data<<" ->";
      else
      cout<<temp->data;
      
      temp=temp->next; //move to next node
    }
    //O(number of nodes)
  cout<<endl;
}

int main()
{
  struct DLL *head = NULL;
  insertAtBeginning(&head,6);
  insertAtBeginning(&head,16);
  insertAtBeginning(&head,15);
  insertAtBeginning(&head,50);
  insertAtBeginning(&head,1);
  insertAtBeginning(&head,23);
  cout<<"Current list is :- \n";
  display(&head);
  
  deleteNode(&head,head->next->next->next);
  
  cout<<"\nAfter deleting the node doubly linked list it became :- \n";
  display(&head);
}
