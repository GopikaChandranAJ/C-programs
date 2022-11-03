#include<stdio.h>
#define size 50
 int a[size],f=-1,r=-1,ch,ele;

void insert(ele)
{ 
if(f==(r+1)%size)
 printf("Queue is full");
else 
 r=(r+1)%size;
  if(f==-1)
   f=0;
  a[r]=ele;
}

int delete(ele)
{
 if(f==r==-1)
 printf("Queue is empty");
 else
 {
  ele=a[f];
  if(f==r)
  f=r=-1;
  else
  {
   f=(f+1)%size;
   return(ele);
  }
 }
}

void displaystack()
{
 int i;
 for(i=0;i<=r;i++)
 printf("\n%d",a[i]);
}

void main()
{
 do{
    printf("\n1.insert\n2.delete\n3.display\n4.exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:
      printf("\nEnter the element:");
      scanf("%d",&ele);
      insert(ele);
      break;
     case 2:     
      ele=delete();
      printf("\nElement is %d",ele);     
      break;
     case 3:displaystack();
            break;
     case 4:break;
     default:printf("\ninvalid choice");
     }
    }while(ch!=4);
} 
        
