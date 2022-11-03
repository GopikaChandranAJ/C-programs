#include<stdio.h>
#define size 50
int s[size],top=0,ch,ele;

int isfull()
{
 if(top==size)
  return(1);
 else
  return(0);
}

void push(int ele)
{ 
 if(top==size)
 printf("stack is full");
 else
 s[top++]=ele;
}

int isempty()
{
 if(top==0)
 return(1);
 else
 return(0);
}

int pop()
{
 if(top==0)
 printf("\nStack is empty"); 
 else
 {
  top=top-1;
 return(s[top]);
 }
}

int peek()
{
 if(top==0)
 printf("\nStack is empty");
 else
 return(s[top-1]);
}

int displaystack()
{
 int i;
 for(i=0;i<top;i++)
 printf("\n%d",s[i]);
}

void main()
{
 do{
    printf("\n1.push\n2.pop\n3.peek\n4.isfull\n5.isempty\n6.displaystack\n7.exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:
     
      printf("\nEnter the element to be pushed:");
      scanf("%d",&ele);
      push(ele);
     
      break;
     case 2:     
      ele=pop();
      printf("\nElement is %d",ele);     
      break;
     case 3:peek();
      printf("\nElement is %d",ele);     
      break;
     case 4:if(isfull()==1)
            printf("stack is full");
            else
            printf("stack is not full");
            break;
     case 5:if(isempty()==1)
            printf("stack is empty");
            else
            printf("stack is not empty");
            break;
     case 6:displaystack();
            break;
     case 7:break;
     default:printf("\ninvalid choice");
    }
   }while(ch!=7);
}


