#include<stdio.h>

int p[30],bt[30],tot_tat=0,wt[30],n,tot_wt=0,tat[30],FCFS_wt=0,FCFS_tat=0,pri[30];
float awt,avg_tat,avg_wt;

void main()
{
 int i;
 printf("\n Enter the no. of processes: ");
 scanf("%d", &n);
 printf("Enter burst time for each process: \n");
 
 for(i=0;i<n;i++)
 {
  scanf("%d",&bt[i]);
  p[i]=i;
 }

printf("Enter priority of each process: \n");
 
 for(i=0;i<n;i++)
 {
  scanf("%d",&pri[i]);
 }
int WT_TAT(int *a,int *b)
{
 int i;
 for(i=0;i<n-1;i++)
  for(int j=i+1;j<n;j++)
  {
  if(pri[j]<pri[i])
  {
    int temp=p[i];
    p[i]=p[j];
    p[j]=temp; 
    int tempy=bt[i];
    bt[i]=bt[j];
    bt[j]=tempy;
  }  
 }
for(i=0;i<n;i++)
 {
  if(i==0)
   tat[i]=bt[i];
  else
   tat[i]=tat[i-1]+bt[i];
   tot_tat=tot_tat+tat[i];
 }
*a=tot_tat;
wt[0]=0;

for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tot_wt=tot_wt+wt[i];
}
*b=tot_wt;
printf("\n process \t\t Burst Time \t Priority \t Turn Around Time \t Waiting Time ");
for(i=0;i<n;i++)
printf("\n process [%d] \t\t %d  \t\t %d  \t\t %d \t\t\t %d",p[i],bt[i],i+1,tat[i],wt[i]);

return 0;

}

printf("*********************************************************************************");
printf("\n \t \t \t \t Priority Algorithm \n");
WT_TAT(&FCFS_tat,&FCFS_wt);
printf("\n Total Turn around time: %d\n",FCFS_tat);
printf("\n Average Turn around time: %d\n",FCFS_tat/n);
printf("\nTotal waiting time: %d\n",FCFS_wt);
printf("\n Total average waiting time: %d\n",FCFS_wt/n);
}
  


