/*--POLYNOMIAL ADDITION--*/
#include<stdio.h>
#include<stdlib.h>
typedef struct poly
{
  int coff, powr;
  struct poly * next;
}pl;

void addnode(pl ** , int, int);
void creatpoly(pl ** );
void addpoly(pl * , pl * , pl ** );
void display(pl * );

void main()
{
  int n;
  pl * pl1, * pl2, * pl3;
  pl1 = pl2 = pl3 = NULL;
  printf("\n Enter 1st Polynomial : ");
  creatpoly( & pl1);

  printf("\n Enter 2nd Polynomial : ");
  creatpoly( & pl2);

  printf("\n\n First Polynomial : ");
  display(pl1);
  printf("\n\n Second Polynomial : ");
  display(pl2);
  printf("\n\n After Addition Resulatnt Polynomial : ");
  addpoly(pl1, pl2, & pl3);
  display(pl3);
}

void creatpoly(pl ** ptr)
{
  int cof, pow, temp = 10;
  char ch;
  while (1)
  {
    printf("\n Enter Coff of X : ");
    scanf("%d", & cof);
    printf("\n Enter Powr of X : ");
    scanf("%d", & pow);
    if (pow < temp)
    {
      addnode(ptr, cof, pow);
    }
    else 
    {
      printf("\n Power must be lesser than the previous term :");
      continue;
    }
    temp = pow;
    printf("\n Do you have more nodes?(y/n): ");
    fflush(stdin);
    scanf(" %c", & ch);
    if (ch == 'n' || ch == 'N')
    {
      break;
    }
  }
}

void addnode(pl ** ptr, int c, int p)
{
  pl * temp, * t1;
  temp = (pl * ) malloc(sizeof(pl));
  temp -> coff = c;
  temp -> powr = p;
  temp -> next = NULL;
  if ( * ptr == NULL)
  {
    * ptr = temp;
  } 
  else
  {
    t1 = * ptr;
    while (t1 -> next != NULL)
    {
      t1 = t1 -> next;
    }
    t1 -> next = temp;
  }
}

void addpoly(pl * ptr1, pl * ptr2, pl ** ptr3)
{
  pl * p3, * temp;
  while (ptr1 != NULL && ptr2 != NULL)
  {
    if ((ptr1 -> powr) > (ptr2 -> powr))
    {
      p3 = ptr1;
      ptr1 = ptr1 -> next;
    }
    else if (ptr1 -> powr < ptr2 -> powr)
    {
      p3 = ptr2;
      ptr2 = ptr2 -> next;
    }
    else
    {
      ptr1 -> coff = ptr1 -> coff + ptr2 -> coff;
      p3 = ptr1;
      ptr1 = ptr1 -> next;
      ptr2 = ptr2 -> next;
    }

    if ( * ptr3 == NULL)
      *ptr3 = p3;
    else
      temp -> next = p3;
    temp = p3;
  }

  if (ptr1 == NULL && ptr2 != NULL)
    temp -> next = ptr2;
  if (ptr1 != NULL && ptr2 == NULL)
    temp -> next = ptr1;
}

void display(pl * h)
{
  while (h -> next != NULL)
  {
    printf("%dx^%d+", h -> coff, h -> powr);
    h = h -> next;
  }
  printf("%dx^%d", h -> coff, h -> powr);

}