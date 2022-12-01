#include<stdlib.h>
#include<stdio.h>
struct node
{
 int info;
 struct node *prev;
 struct node *next;
};
struct node *head;
struct node *tail;

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
   curr=curr->next;
  }
 }
}

void insertfront(int ele)
{
 struct node *p;
 p=(struct node*)malloc(sizeof(struct node));
 p->info=ele;
 p->prev=NULL;
 p->next=head;
 if(head==NULL)
   head=tail=p;
 else
   head->prev=p;
 head=p;
}

void insertlast(int ele)
{
 struct node *p,*curr;
 p=(struct node*)malloc(sizeof(struct node));
 p->info=ele;
 p->next=NULL;
 p->prev=tail;
 if(tail==NULL)
  head=tail=p;
 else
  tail->next=p;
  tail=p;
 }
void insertafter(int val,int ele)
{
 struct node *p,*curr;
 curr=head;
 while(curr!=NULL && curr->info!=val)
 curr=curr->next;
 if(curr==NULL)
 printf("No such element");
 else
 {
 p=(struct node*)malloc(sizeof(struct node));
 p->info=ele;
 p->prev=curr;
 p->next=curr->next;
 if(curr->next==NULL)
 tail=p;
 else
 curr->next->prev=p;
 curr->next=p;
 }
}

void insertbefore(int val,int ele)
{
 struct node *p,*curr;
 curr=head;
 while(curr->info!=val && curr!=NULL)
   curr=curr->next;
 if(curr==NULL)
   printf("No such element present");
 else
 {
   p=(struct node*)malloc(sizeof(struct node));
   p->info=ele;
   p->prev=curr->prev;
   p->next=curr;
 }
 if(curr->prev==NULL)
   head=p;
 else
   curr->prev->next=p;
   curr->prev=p;
}

void deletenode(int val)
{
 struct node*curr;
 curr=head;
 while(curr!=NULL && curr->info!=val )
     curr=curr->next;
  if(curr==NULL)
      printf("No such node");
  else
   {
    if(curr->prev==NULL)
        head=curr->next;
    else
        curr->prev->next=curr->next;
    if(curr->next==NULL)
        tail=curr->prev;
    else
       curr->next->prev=curr->prev;
  free(curr);
  }
}
 

void main()
{
 int ch,val,ele;
 do{
    printf("\n1.Insertfront\n2.Insertlast\n3.Insertafter\n4.Insertbefore\n5.Deletenode\n6.Display\n7.Exit");
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
           scanf("%d",&val);
           printf("\nEnter the info:");
           scanf("%d",&ele);
           insertafter(val,ele);
           break;
     case 4:
           printf("\nEnter the element:");
           scanf("%d",&val);
           printf("\nEnter the info:");
           scanf("%d",&ele);
           insertbefore(val,ele);
           break;
     case 5:printf("Enter the element to be deleted :");
            scanf("%d",&ele);
            deletenode(ele);
            break;
     case 6:
            display();
            break;
     case 7:break;
     default:printf("\ninvalid choice");
     }
    }while(ch!=7);
}  
