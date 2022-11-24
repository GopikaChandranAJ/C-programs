#include<stdlib.h>
#include<stdio.h>
struct node
{
 int info;
 struct node *link;
 };
struct node *head;

void display()
{
 struct node *curr;
 if(head==NULL)
 printf("list is empty"); 
 else
 {
  curr=head;
  printf("list elements are:");
  while(curr!=NULL)
  {
   printf("%d \t",curr->info);
   curr=curr->link;
  }
 }
}

void insertfront(int ele)
{
 struct node *p;
 p=(struct node*)malloc(sizeof(struct node));
 p->info=ele;
 if(head==NULL)
 {
  head=p;
  p->link=NULL;
 }
 else
 p->link=head;
 head=p;
}

void insertlast(int ele)
{
 struct node *p,*curr;
 p=(struct node*)malloc(sizeof(struct node));
 p->info=ele;
 p->link=NULL;
 if(head==NULL)
  head=p;
 else
  curr=head;
 while(curr->link!=NULL)
 curr=curr->link;
 curr->link=p;
}

void insertafter(int val,int ele)
{
 struct node *p,*curr;
 curr=head;
 while(curr!=NULL && curr->info!=val)
 curr=curr->link;
 if(curr==NULL)
 printf("No such element");
 else
 p=(struct node*)malloc(sizeof(struct node));
 p->info=ele;
 p->link=curr->link;
 curr->link=p;
}

void insertbefore(int val,int ele)
{
 struct node *p,*curr,*prev;
 curr=head;
 while(curr->info!=val && curr->link!=NULL)
 {
  prev=curr;
 curr=curr->link;
 }
 if(curr->info!=val)
 printf("No such element present");
 else
 {
 p=(struct node*)malloc(sizeof(struct node));
 p->info=ele;
 p->link=curr;
 }
 if(curr==head)
 head=p;
 else
 prev->link=p;
}

void deletefront()
{
 struct node*temp;
 if(head==NULL)
 printf("Deletion not possible");
 else
 {
  temp=head;
  head=head->link;
  free(temp);
 }
  display();
}

void deleteend()
{
 struct node*temp,*prev,*curr;
 if(head==NULL)
 printf("Deletion not possible");
 else if(head->link==NULL)
 {
  temp=head;
  head=NULL;
  free(temp);
 }
 else
 {
  prev=head;
  curr=head->link;
  while(curr->link!=NULL)
  {
   prev=curr;
   curr=curr->link;
  }
  prev->link=NULL;
  free(curr);
 }
 display();
}

void deleteany(int key)
{
 struct node*temp,*prev,*curr;
 if(head==NULL)
 printf("Deletion not possible");
 else if(head->info==key)
 {
  temp=head;
  head=head->link;
  free(temp);
 }
 else
 {
  prev=head;
  curr=head;
  while(curr->info!=key && curr->link!=NULL)
  {
   prev=curr;
   curr=curr->link;
  }
  if(curr->info!=key)
  printf("Deletion not possible");
  else
  {
   prev->link=curr->link;
   free(curr);
  }
 }
 display();
}

void main()
{
 int ch,ele,key;
 do{
    printf("\n1.Insertfront\n2.Insertlast\n3.Insertafter\n4.Insertbefore\n5.Deletefront\n6.Deleteend\n7.Deleteany\n8.Display\n9.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:
            printf("\nEnter the info:");
            scanf("%d",&ele);
            insertfront(ele);
            break;
     case 2:   
            printf("\nEnter the info:");  
            scanf("%d",&ele);
            insertlast(ele);
            break;
     case 3:
           printf("\nEnter the element:");
           scanf("%d",&key);
           printf("\nEnter the info:");
           scanf("%d",&ele);
           insertafter(key,ele);
           break;
     case 4:
           printf("\nEnter the element:");
           scanf("%d",&key);
           printf("\nEnter the info:");
           scanf("%d",&ele);
           insertbefore(key,ele);
           break;
     case 5:deletefront();
            break;
     case 6:deleteend();
            break;
     case 7:printf("Enter the element to be deleted :");
            scanf("%d",&key);
            deleteany(key);
            break;
     case 8:display();
            break;
     case 9:break;
     default:printf("\ninvalid choice");
     }
    }while(ch!=9);
} 
        













































