#include<stdio.h>
void main()
{
 int n,m, available[10],need[10][10],allocation[10][10],max[10][10],i,j,k,p[10],work[10],finish[10],index=0,flag,y;
 printf("Enter the number of resource types: ");
 scanf("%d",&m);
 printf("Enter the number of process: ");
 scanf("%d",&n);
 printf("Enter the number of instances in each resource types: ");
 for(i=0;i<m;i++)
    {
     printf("Enter the number of instances in each resource types %d :",i+1);
     scanf("%d",&available[i]);
     work[i]=available[i];
    }
 printf("Enter the number allocated instances for each process: ");
 for(i=0;i<n;i++)
    {
     printf("\nProcess %d :",i+1);
     for(j=0;j<m;j++)
     {
      printf("\nResource Type %d :",j+1);
      scanf("%d",&allocation[i][j]);
     }
    }
 printf("Enter the number of max instances for each process: ");
 for(i=0;i<n;i++)

    {
       printf("\nProcess %d :",i+1);
       for(j=0;j<m;j++)
         {
          printf("\nResource Type %d :",j+1);
          scanf("%d",&max[i][j]);
         }
    }
       for(i=0;i<n;i++)
         {
          finish[i]=0;
         }
       for(i=0;i<n;i++)
         {
          for(j=0;j<m;j++)
             {
              need[i][j]=max[i][j]-allocation[i][j];
             }
         }
       for(i=0;i<n;i++)
          {
           for(j=0;j<n;j++)
             {
              if(finish[j]==0)
                {
                 flag=0;
                 for(k=0;k<m;k++)
                    {
                     if(need[j][k]>available[k])
                       {
                        flag=1;
                        break;
                       }
                    }
                 if(flag==0)
                   {
                    p[index++]=j;
                    for(y=0;y<m;y++)
                      {
                       available[y]+=allocation[j][y];
                      }
                    finish[j]=1;
                   }
                }
             }
         }
    printf("\nsafe sequence");
    for(i=0;i<n-1;i++)
    {
     printf("p%d->",p[i]);
    }
   printf("p%d",p[n-1]);
    
  
}



 





