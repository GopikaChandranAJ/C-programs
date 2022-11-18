#include<stdio.h>

 void selectionsort(int a[],int n)
 {
  int i,j,small,t,ind;
  for(int i=0;i<n-1;i++)
  {
   small=a[i];
   ind=i;
  for(j=i+1;j<n;j++)
   if(a[j]<small)
    {
     small=a[j];
     ind=j;
    }
    t=a[i];
    a[i]=a[ind];
    a[ind]=t;
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
 printf("%d",a[i]);
}

void main()
{
 int x[100],n;
 printf("Enter the number of elements:");
 scanf("%d",&n);
 readnum(x,n);
 selectionsort(x,n);
 printnum(x,n);
 printf("\n");
}

 
  
