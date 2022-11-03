#include<stdio.h>
 
int partition(int a[],int l,int r)
 {
  int i,j,key,t;
  key=a[l];
  i=l+1;
  j=r;
 do
   {
    while(i<r && a[i]<key)
     i++;
    while(j>l && a[j]>key)
     j--;
     if(i<j)
     {
      t=a[i];
      a[i]=a[j];
      a[j]=t;
     }
   }while(i<j);
   t=a[j];
   a[j]=a[l];
   a[l]=t;
  return (j);
 }

int qsort(int a[],int l,int r)
 {
  int p;
  if(l<r)
  {
   p=partition(a,l,r);
   qsort(a,l,p-1);
   qsort(a,p+1,r);
   }
 }

int readnum(int a[],int n)
 {
   int i;
   printf("The %d elements are:",n);
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
 }
 

int printnum(int a[],int n)
 {
  int i;
  printf("The sorted array is:\n");
  for(i=0;i<n;i++)
  printf("%d\t",a[i]);
  printf("\n");
 }

int main()
 {
  int x[100],l=0,n;
  printf("Enter the number of elements:");
  scanf("%d",&n);
  readnum(x,n);
  qsort(x,0,n-1);
  printnum(x,n);
 }

