#include <stdio.h>
void swap(int* a, int* b)
{ int temp = *a;
  *a = *b;
  *b = temp;}

void heapify(int arr[], int N, int i)
{ int large,lc,rc;
  large = i;
  lc = 2*i + 1;
  rc = 2 * i + 2;
if (lc < N && arr[lc] > arr[large])
     large = lc;
if (rc < N && arr[rc] > arr[large])
     large = rc;
if (large != i)
{swap(&arr[i], &arr[large]);
   heapify(arr, N, large);}}

void heapsort(int arr[], int N)
{ for (int i = N / 2 - 1; i >= 0; i--)
     heapify(arr, N, i);
  for (int i = N - 1; i >= 0; i--) 
   {   swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);}}

void printnum(int a[], int N)
{ int i ;
 printf("The sorted array is: ");
 for(i=0;i<N;i++)
 printf("\t%d",a[i]);
printf("\n");  }

void main()
{ int N,a[100],i;
 printf("Enter the number of elements: ");
 scanf("%d",&N);
 printf("The %d elements are: ",N);
 for(i=0;i<N;i++)
 scanf("%d",&a[i]);
 heapsort(a, N);
 printnum(a, N);
 printf("\n"); }