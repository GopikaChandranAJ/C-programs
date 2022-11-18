#include<stdio.h>
void bubblesort(int a[],int n)
{
 int c,p,t;
 for(c=1;c<n;c++)
 for(p=0;p<n-c;p++)
 if(a[p]>a[p+1])
  {
   t=a[p];
   a[p]=a[p+1];
   a[p+1]=t;
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
 printf("\t%d",a[i]);
}

void main()
{
 int x[100],n;
 printf("Enter the number of elements:");
 scanf("%d",&n);
 readnum(x,n);
 bubblesort(x,n);
 printnum(x,n);
 printf("\n");
}
