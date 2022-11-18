#include<stdio.h>

 void insertionsort(int a[],int n)
{
 int i,j,key;
  for(i=1;i<n;i++)
  {
   key=a[i];
   j=i-1;
   while(j>=0&&a[j]>key)
   {
    a[j+1]=a[j];
    j--;
   }
  a[j+1]=key;
  }
}

void readnum(int a[],int n)
{
 int i;
 printf("The %d elements are:",n);
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
}

void printnum(int a[],int n)
{
 int i;
 printf("The sorted array is:");
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
}

void main()
{
 int x[100],n;
 printf("Enter the number of elements:");
 scanf("%d",&n);
 readnum(x,n);
 insertionsort(x,n);
 printnum(x,n);
 printf("\n");
}

 
  
