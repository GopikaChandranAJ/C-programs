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
 printf("Queue is empty");
 else
 {
  ptr=head;
  printf("Elements are:\t");
  while(ptr!=NULL)
  {
   printf("%d\t",ptr->info);
   ptr=ptr->next;
  }
 }
}
void insert(int ele)
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
void delete()
{
 struct node *prev,*curr,*temp;
 if(head==NULL)
 printf("Queue is empty");
 else if(head->next==NULL)
 {
  temp=head;
  head=NULL;
  free(temp);
 }
else
{ 
 curr=head;
 head=curr->next;
 free(curr);
} 
 display();
}
void main()
{
 int ele,ch,key;
  do
   {
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:printf("Enter the element to be pushed:");
            scanf("%d",&ele);
            insert(ele);
            break;  
     case 2:delete();
            break;
     case 3:display();
            break;
     case 4:break;
    default: printf("Invalid choice");
    }
   }while(ch!=4);
}
