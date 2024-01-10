//*--Infix to postfix evalution--*//
#include<stdio.h>
#include<stdlib.h>
#define max 50
typedef struct stack
{
  char ar[max];
  int top;
}st;


typedef struct stack1
{
  float res[max];
  int top;
}st1;
void push(st *,char);
void push1(st1 *,float);
char pop(st *);
float pop1(st1 *);
char peek(st);
int isfull(st);
int isempty(st);
float pfixeval(char []);
void intopost(char [],char []);
int getpriority(char);
int main()
{
  char expr[max],res[max];
  float p;
  printf("\nEnter the expression (in digits only) to be evaluated in Infix form and rest is our responsibility : ");
  fgets(expr,max,stdin);

  intopost(expr,res); 
  printf("\nThe postfix expression is : ");
  puts(res);

  p=pfixeval(res);
  printf("\nEvaluated result is : %f",p);

}


void intopost(char expr[],char res[])
{
  st s;
  char ch;
 int i,j;
 s.top=-1;
 for(i=0,j=0;expr[i]!='\0';i++)
 {
   if(expr[i]==' ')
      continue;
   else if(expr[i]=='(' || expr[i]=='{' || expr[i]=='[')
      push(&s,expr[i]);
   else if((expr[i]>=48 && expr[i]<=57) || (expr[i]>=65 && expr[i]<=90) || (expr[i]>=97 && expr[i]<=122))
      res[j++]=expr[i];
   else if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/')
  {
     while(!isempty(s) && getpriority(expr[i])<=getpriority(peek(s)) && peek(s)!='(')
     {
        res[j++]=pop(&s);
     }
     push(&s,expr[i]);
  }
  else if(expr[i]==')' || expr[i]=='}' || expr[i]==']')
  {
    while(!isempty(s) && (ch=pop(&s))!='(')
   {
     res[j++]=ch;
   }
  }
  else
  {
    //printf("Expression not ok");
   break;
  }
 }
 if(!isempty(s))
 {
  while(!isempty(s) && (ch=peek(s))!='(')
  res[j++]=pop(&s);
 }
 res[j]='\0';
}


void push(st *s,char ch)
{
s->ar[++s->top]=ch;
}


char pop(st *s)
{
return s->ar[s->top--];
}


char peek(st s)
{
return s.ar[s.top];
}


int isempty(st s)
{
if(s.top==-1)
return 1;
else
return 0;
}


int isfull(st s)
{
if(s.top==max-1)
return 1;
else
return 0;
}


int getpriority(char ch)
{
switch(ch)
{
case '+':
case '-': return 0;
case '*':
case '/':return 1;
}
}
//postfix evaluation taking place
float pfixeval(char str[])
{
  float val1,val2,res;
  int i;
  st1 s;
  s.top=-1;
  for(i=0;str[i]!='\0';i++)
  {
     if(str[i]>=48 && str[i]<=57)
     {
        push1(&s,str[i]-'0');
     }
     else
     { 
        val1=pop1(&s);
        val2=pop1(&s);
        switch(str[i])
        {
          case '+':res=val2+val1;
                  break;
          case '-':res=val2-val1;
                  break;
          case '*':res=val2*val1;
                  break;
          case '/':res=(val2*1.0)/val1;
                  break;
        }
        push1(&s,res);
     }
  }
  return pop1(&s);
}


float pop1(st1 *s)
{
  return s->res[s->top--];
}


void push1(st1 *s,float p)
{
  s->res[++s->top]=p;
}