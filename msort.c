#include<stdio.h>
 void Simplemerge(int a[],int f,int s,int t)
 {
  int i=f,j=s,k=0,b[100];
  while(i<s && j<=t)
  {
   if(a[i]<a[j])
   b[k++]=a[i++];
   else
   b[k++]=a[j++];
  }
  while(i<s)
  b[k++]=a[i++];
  while(j<=t)
  b[k++]=a[j++];
  for(i=f,k=0;i<=t;)
  a[i++]=b[k++];
 }

void msort(int a[],int l,int r)
 {
  int m;
  if(l<r)
  {
   m=(l+r)/2;
   msort(a,l,m);
   msort(a,m+1,r);
   Simplemerge(a,l,m+1,r);
   
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
 int x[100],l=0,n;
 printf("Enter the number of elements:");
 scanf("%d",&n);
 readnum(x,n);
 msort(x,l,n-1);
 printnum(x,n);
}

Zq!
