#include<stdio.h>
void worstfit(int[],int[],int,int);
void print(int[],int[],int);
int main()
{
int np,nm,i;
printf("ENTER THE NUMBER OF BLOCKS:");
scanf("%d",&nm);
printf("ENTER NUMBER OF FILES:");
scanf("%d",&np);
int block[nm],file[np];
printf("ENTER THE BLOCK SIZE:");
for(i=0;i<nm;i++)
scanf("%d",&block[i]);
printf("ENTER THE FILE SIZE:");
for(i=0;i<np;i++)
scanf("%d",&file[i]);
worstfit(block,file,nm,np);
}
void worstfit(int block[],int file[],int nm,int np)
{
int i,j;
int allocate[np];
for(i=0;i<np;i++)
allocate[i]=-1;
for(i=0;i<np;i++)
{
int worst=-1;
for(j=0;j<nm;j++)
{
if(block[j]>=file[i])
{
if(worst==-1)
worst=j;
else if(block[worst]<=block[j])
worst=j;
}
}
if(worst!=-1)
{
allocate[i]=worst;
block[worst]-=file[i];
}
}
print(file,allocate,np);
}
void print(int p[],int allocate[],int n)
{
printf("\nWORST FIT\nFILE NO:\tFILE SIZE\tBLOCK NO");
for(int i=0;i<n;i++)
{
printf("\n%d\t\t%d\t\t",i+1,p[i]);
if(allocate[i]!=-1)
printf("%d\n",allocate[i]+1);
else
printf("NOT ALLOCATED\n");
}
}

