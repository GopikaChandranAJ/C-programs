#include<stdio.h>
void main()
{
 int b[10],c[10],t[10],w[10],r,d,s,k=0,m=0,n,i;
 printf("enter the number of processes: ");
 scanf("%d",&n);
 printf("enter the processes\n: ");
 for(i=1;i<=n;i++)
  {
   printf("p%d:",i);
   scanf("%d",&b[i]);
  }
 d=b[1];
 c[1]=d;
 for(i=2;i<=n;i++)
  {
    c[i]=c[i-1]+b[i];
  }
 for(i=1;i<=n;i++)
  {
    t[i]=c[i];
  }
 for(i=1;i<=n;i++)
  {
    w[i]=t[i]-b[i];
  }
 printf("\n----------------------------------------\n");
printf("\npro no\tburts time\twaiting time\tturnaroundtime\t");
for(i=1;i<=n;i++)
{
  printf("\np%d \t%d \t\t%d \t\t%d\t",i,b[i],w[i],t[i]);
}
for(i=1;i<=n;i++)
  {
    k=k+w[i];
  }
 s=k/n;
 printf("\n\naverage waiting time= %d",s);
 for(i=1;i<=n;i++)
  {
    m=m+t[i];
  }
 r=m/n;
 printf("\n\naverage turnaround time= %d",r);
}
  
