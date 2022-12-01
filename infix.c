#include<stdio.h>
#include<string.h>
#define max 100
char ss[max];
int top=0;

int isfull()
{
 if(top==max)
   return(1);
 else
   return(0);
}

int isempty()
{
 if(top==0)
  return(1);
 else
  return(0);
}

void push(char a)
{
 if(!isfull())
  ss[top++]=a;
}

void displaystack()
{
 int i;
 printf("\tstack:");
 for(i=0;i<top;i++)
  printf("%c",ss[i]);
}

void displaypost(char a[],int k)
{
 int i;
 printf("\tpostfix:");
 for(i=0;i<k;i++)
  printf("%c",a[i]);
}

char peek()
 {return(ss[top-1]);}

char pop()
 {return(ss[--top]);}
 
int inprio(char e)
{
 switch(e)
 {
  case'-':
  case'+':return(1);
          break;
  case'*':
  case'/':return(3);
          break;
  case'^':return(6);
          break;
 }
}

int instack(char e)
{
 switch(e)
 {
  case'-':
  case'+':return(2);
          break;
  case'*':
  case'/':return(4);
          break;
  case'^':return(5);
          break;
  case'(':return(0);
          break;
 }
}

void main()
{
 char in[50],post[50],token,c;
 int i,j=0;
 printf("Enter the infix expression:");
 scanf("%[^\n]",&in);
 printf("\n%s",in);
 for(i=0;in[i]!='\0';i++)
 {
  token=in[i];
  switch(token)
  {
    case'(': push(token);
             break;
    case'*':
    case'/':
    case'+':
    case'-':
    case'^': while(!isempty()&&instack(peek())>inprio(token))
            {
 	     post[j++]=pop();
             push(token);
             break;
            } 
    case')': while(c=pop()!='(')
            {
             post[j++]=c;
             break;
            }
    default: post[j++]=token;
   }
    printf("Token: %c",token);
    displaystack();
    displaypost(post,j); 
 }
  while(!isempty())
  post[j++]=pop();
  post[j]='\0';
  printf("\nPostfix: %s\n",post);
}

