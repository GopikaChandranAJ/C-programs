#include<stdio.h>
 int binarysearch(int a[],int n,int ele)
 {
  int top=0,bot=n-1,m;
  while(top<=bot)
  {
  m=(top+bot)/2;
  if(a[m]==ele)
     return(m+1);
  else if(a[m]>ele)
     bot=m-1;
  else
     top=m+1;
  }
  return 0;
 }
 
 int readnum(int a[],int n,int ele)
 {
  int i;
  printf("The %d elements are:",n);
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 }
 
 int main()
 {
  int i,x[100],n,e,p;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   readnum(x,n,e);
   printf("enter the element to be searched:");
   scanf("%d",&e);
   p=binarysearch(x,n,e);
   if(p==0)
   printf("The element is not present");
   else
   printf("The element is found at position %d",p);
   printf("\n");
 }   

