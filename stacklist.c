#include <stdlib.h>
#include <stdio.h>
struct node
 {
  int info;
  struct node *next;
 };
struct node *head=NULL;
void display()
{
 struct node *ptr;
 if(head==NULL)
 printf("List is empty");
 else
 {
  ptr=head;
  printf("\nElements are:\t");
  while(ptr!=NULL)
  {
   printf("%d\t",ptr->info);
   ptr=ptr->next;
  }
 }
}
void push(int ele)
{
 struct node *new,*ptr;
 new=(struct node *)malloc(sizeof(struct node));
 new->info=ele;
 new->next=NULL;
 if(head==NULL)
   head=new;
 else
 {
  ptr=head;
  while(ptr->next!=NULL)
  ptr=ptr->next;
  ptr->next=new;
 }
  display();
}    
void pop()
    {
     struct node *prev,*curr,*temp;
     if(head==NULL)
     printf("Stack is empty");
     else if(head->next==NULL)
     {
     temp=head;
     head=NULL;
     free(temp);
     }
    else
    { 
     prev=head;
     curr=head->next;
     while(curr->next!=NULL)
     {
      prev=curr;
      curr=curr->next;
     }
      prev->next=NULL;
      free(curr);
     }
    display();
    } 
void main()
{
 int ele,ch,key;
  do
  {
   printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
   printf("Enter your choice:");
   scanf("%d",&ch);
   switch(ch)
    {
     case 1: printf("Enter the element to be pushed:");
             scanf("%d",&ele);
             push(ele);
             break;  
     case 2: pop();
             break;
     case 3: display();
             break;
     case 4: break;
    default: printf("\nInvalid choice\n");
      }
     }while(ch!=4);
   }


