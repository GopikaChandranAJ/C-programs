#include<stdio.h>
#include<stdlib.h>
struct node
{
 int coef,expo;
 struct node*next;
 struct node*head;
};
struct node*P1head,*P2head,*P3head;
struct node*ReadPoly()
{
 struct node*new,*ptr,*head=NULL;
 int n,i;
 printf("Enter the number of terms: ");
 scanf("%d",&n);
 printf("Enter the coefficients and exponents: ");
 for(i=1;i<=n;i++)
 {
  new=(struct node*)malloc(sizeof(struct node));
  scanf("%d",&new->coef);
  scanf("%d",&new->expo);
  new->next=NULL;
  if(head==NULL)
  {
   head=new;
   ptr=head;
  }
  else
  {
   ptr->next=new;
   ptr=new;
  }
 }
 return(head);
}
 void DisplayPoly(struct node*head)
{
 struct node*ptr;
 if(head==NULL)
  printf("Polynomial is empty");
  else
  {
   ptr=head;
   while(ptr->next!=NULL)
   {
    printf("%dx^%d\t",ptr->coef,ptr->expo);
    ptr=ptr->next;
   }
   printf("%dx^%d\t",ptr->coef,ptr->expo);
  }
}

struct node*AddPoly()
{
 struct node *new,*P1,*P2,*P3,*head=NULL;
 P1=P1head;
 P2=P2head;
 while(P1!=NULL && P2!=NULL)
 {
  if(P1->expo==P2->expo)
  {
   new=(struct node *)malloc(sizeof(struct node));
   new->coef=P1->coef+P2->coef;
   new->expo=P1->expo;
   new->next=NULL;
   P1=P1->next;
   P2=P2->next;
  }
   else if(P1->expo>P2->expo)
   {
    new=(struct node *)malloc(sizeof(struct node));
    new->coef=P1->coef;
    new->expo=P1->expo;
    new->next=NULL;
    P1=P1->next;
   }
   else
  {
  new=(struct node *)malloc(sizeof(struct node));
               new->coef=P2->coef;
               new->expo=P2->expo;
               new->next=NULL;
               P2=P2->next;
              }
         if(head==NULL)
              {
               head=new;
               P3=head;
              }
         else
               {
                P3->next=new;
                P3=new;
               }
        }
    while(P1!=NULL)
        {
         new=(struct node *)malloc(sizeof(struct node));
         new->coef=P1->coef;
         new->expo=P1->expo;
         new->next=NULL;
         if(head==NULL)
             {
              head=new;
              P3=head;
             }
         else
             {
              P3->next=new;
              P3=new;
             }
         P1=P1->next;
        }
    while(P2!=NULL)
        {
         new=(struct node *)malloc(sizeof(struct node));
         new->coef=P2->coef;
         new->expo=P2->expo;
         new->next=NULL;
         if(head==NULL)
             {
              head=new;
              P3=head;
             }
         else
             {
              P3->next=new;
              P3=new;
             }
         P2=P2->next;
        }
    return(head);
   }
 

void main()
{
 printf("Enter the details of first polynomial\n");
 P1head=ReadPoly();
 printf("Enter the details of second polynomial\n");
 P2head=ReadPoly();
 printf("\nThe first polynomial is");
 DisplayPoly(P1head);
 printf("\nThe second polynomial is");
 DisplayPoly(P2head);
 P3head=AddPoly();
 printf("\nThe resultant polynomial is");
 DisplayPoly(P3head);
}
 
  
