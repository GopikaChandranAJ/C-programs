#include<stdio.h>
int process;
int memory;
int pros[20];
int mems[20];
int remain;
int blocknum[20];
int prosize[20];

int main()
{
 printf("Enter the number of processes: ");
 scanf("%d",&process);
 printf("Enter the number of memory partitions available: ");
 scanf("%d",&memory);
 printf("Enter the Processes: ");
 for(int i=0;i<process;i++)
 {
  scanf("%d",&pros[i]);
  prosize[i]=pros[i];
 }   
 printf("Enter the memory partitions: ");
 for(int j=0;j<memory;j++)
 {
  scanf("%d",&mems[j]);
 }
 
 for(int i=0;i<process;i++)
 {
  for(int j=0;j<memory;j++)
  {
   if(pros[i]<mems[j])
   {
    printf("\nP[%d] assigned to %d memory space\n",i+1,j+1);
    remain=mems[j]-pros[i];
    pros[i]=0;
    blocknum[i]=j+1;
    printf("Remaining memory from %d is %d\n\n",mems[j],remain);
    mems[j]=remain;
    break;
   }
  }
 }

  for(int i=0;i<memory;i++)
 {
  if(pros[i]!=0)
    {
     printf("\nP[%d] cannot be assigned. Hence obtained value is 0....\n",i+1);
    }
 }
  
  printf("..................FIRST FIT...................\n\n");
  printf("Process\t\tProcess size\t\tBlock assigned\n");
  for(int i=0;i<process;i++)
  {
   printf(" %d   \t\t     %d     \t\t      %d      \n",i+1,prosize[i],blocknum[i]);
  }
  
 
}
   
  
 
