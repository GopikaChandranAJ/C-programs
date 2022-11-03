#include<stdio.h>
#define size 10
 int a[size],f=-1,r=-1,ch,ele;

void insertrear(ele)
{ 
if(f==(r+1)%size)
 printf("Queue is full");
else 
 r=(r+1)%size;
  if(f==-1)
   f=0;
  a[r]=ele;
  t++;
}

int deletefront(ele)
{
 if(f==r==-1)
 printf("Queue is empty");
 else
 {
  ele=a[f];
  t--;
  if(f==r)
  f=r=-1;
  else
  {
   f=(f+1)%size;
   return(ele);
  }
 }
}

void insertfront(ele)
{ 
if(f==(r+1)%size)
 printf("Queue is full");
else 
 {
  if(f==-1)
  f=r=0;
  else
  {
   if(f==0)
   f=size-1;
   else
   f=f-1;
  }
   a[f]=ele;
   t++;
 }
}
int deleterear(ele)
{
 t--;
 if(f==r==-1)
 printf("Queue is empty");
 else
 {
  ele=a[r];
  if(f==r)
  f=r=-1;
  else
  {
   if(r==0)
   r=size-1;
   else
   {
    r=r-1;
    return(ele);
   }
  }
 }
}

void displaystack()
{
 int i,c=1;
 for(i=f;c<=t;i=(i+1)%size,c++)
 printf("\n%d",a[i]);
}

void main()
{
 do{
    printf("\n1.insertrear\n2.deletefront\n3.insertfront\n4.deleterear\n5.display\n6.exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:
      printf("\nEnter the element:");
      scanf("%d",&ele);
      insertrear(ele);
      break;
     case 2:     
      ele=deletefront();
      printf("\nElement is %d",ele);     
      break;
     case 3:
      printf("\nEnter the element:");
      scanf("%d",&ele);
      insertfront(ele);
      break;
     case 4:     
      ele=deleterear();
      printf("\nElement is %d",ele);     
      break;
 
     case 5:displaystack();
            break;
     case 6:break;
     default:printf("\ninvalid choice");
     }
    }while(ch!=6);
} 
        
