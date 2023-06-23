#include<stdio.h>

void bestfit(int[],int[],int,int);
void print(int[],int[],int);

int main()
{
 int np,nm,i;
 printf("Enter the number of blocks:");
 scanf("%d",&nm);
 printf("Enter the number of files:");
 scanf("%d",&np);
 int block[nm],file[np];
 printf("Enter the block size:");
 for(i=0;i<nm;i++)
 scanf("%d",&block[i]);
 printf("Enter the file size:");
 for(i=0;i<np;i++)
    scanf("%d",&file[i]);
 bestfit(block,file,nm,np);
}
void bestfit(int block[],int file[],int nm,int np)
 {
  int i,j;
  int allocate[np];
  for(i=0;i<np;i++)
     allocate[i]=-1;
  for(i=0;i<np;i++)
  {
   int best=-1;
   for(j=0;j<nm;j++)
   {
    if(block[j]>=file[i])
      {
       if(best==-1)
       best=j;
       else if(block[best]>block[j])
       best=j;
      }
   }
   if(best!=-1)
     {
      allocate[i]=best;
      block[best]-=file[i];
     }
   }
   print(file,allocate,np);
  }
  void print(int p[],int allocate[],int n)
  {
   printf("\nBEST FIT\nFILE NO:\tFILE SIZE\tBLOCK NO");
   for(int i=0;i<n;i++)
     {
      printf("\n%d\t\t%d\t\t",i+1,p[i]);
      if(allocate[i]!=-1)
      printf("%d\n",allocate[i]+1);
   else
      printf("NOT ALLOCATED\n");
     }
  }

