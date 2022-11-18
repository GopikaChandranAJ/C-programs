#include<stdio.h>
int linearsearch(int a[],int n,int key)
{
 int i;
 for(i=0;i<n;i++)
 if(a[i]==key)
    return(i+1);
 return 0;
}

int readnum(int a[],int n,int key)
{
 int i;
 printf("The %d elements are:",n);
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
}

int main()
{
 int x[100],n,k,p;
 printf("Enter the number of elements:");
 scanf("%d",&n);
 readnum(x,n,k);
 printf("Enter the key element to be found:");
 scanf("%d",&k);
 p=linearsearch(x,n,k);
 if(p==0)
 printf("Element not found");
 else
 printf("Element found at position %d",p);
 printf("\n");
}



