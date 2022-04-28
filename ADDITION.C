#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct nodetype{
int coef;
int power;
struct nodetype *next;
}node;
void readPolynomial(node **p);
void addPolynomial(node *ptr1,node *ptr2,node **ptr3);
void addNode(node **ptr,int coef,int powe);
void printPolynomial(node *);

void main()
{
 node *poly1,*poly2, *poly3;
 int choice, element,after,before;
 poly1=poly2=poly3=NULL;
 clrscr();
 printf("\nProgram to aded two polynomial");
 printf("\nEnter first polynomial");
 readPolynomial(&poly1);
 printf("\nEnter second polynomial");
 readPolynomial(&poly2);
 addPolynomial(poly1,poly2,&poly3);
 printf("\nSum of polynomials\n");
 printPolynomial(poly1);
 printf("\nand\n");
 printPolynomial(poly2);
 printf("\nis\n");
 printPolynomial(poly3);
 getch();
}

void addNode(node **ptr,int coef,int power)
{
 node *tempPtr;
 tempPtr=(node *)malloc(sizeof(node));
 tempPtr->coef = coef;
 tempPtr->power = power;
 if(*ptr == NULL){
 tempPtr -> next =NULL;
 *ptr = tempPtr;
 }
 else {
 tempPtr -> next =*ptr;
 *ptr = tempPtr;
 }
}
void readPolynomial(node **p)
{
 int coef, powe;
 printf("\nEnter the terms in the ascending order of power");
 while(1)
 {
 printf("\nEnter the degree of x: ");
 scanf("%d",&powe);
 printf("Enter its coefficient :");
 scanf("%d", &coef);
 addNode(p,coef,powe);
 printf("\nAny more term (Y/N)? :");
 if(toupper(getch()) == 'Y')
     break;
 }
}

void printPolynomial(node *ptr)
{
  if(ptr != NULL)
    printf("%dx^%d", ptr->coef, ptr->power);
  for(ptr = ptr->next; ptr != NULL; ptr = ptr->next)
  {
   if(ptr->coef > 0)
   printf( " + " );
   if(ptr->power == 0)
     printf("%d", ptr->coef);
   else if(ptr->power == 1)
     printf("%dx", ptr->coef);
   else
     printf("%dx^%d", ptr->coef, ptr->power);
  }
}

void addPolynomial(node *ptr1, node *ptr2, node **ptr3)
{
  int powe;
  float coef;

  while ((ptr1 != NULL) && (ptr2 != NULL))
  {
    if (ptr1->power > ptr2->power){
      powe = ptr1 -> power;
      coef = ptr1 -> coef;
      ptr1 = ptr1 -> next;
  }

    else if (ptr1 -> power < ptr2 -> power){
    powe = ptr2 -> power;
    coef = ptr2 -> coef;
    ptr2 = ptr2 -> next;
  }

    else {
    powe = ptr1 -> coef + ptr2 -> coef;
    coef = ptr1 -> power;
    ptr1 = ptr1 -> next;
    ptr2 = ptr2 -> next;
   }

    if(coef != 0)
   {
	addNode(ptr3,coef,powe);
   }

    if(ptr1 == NULL)
   {
      for( ;ptr2 != NULL; ptr2 = ptr2 -> next)
	addNode (ptr3, ptr2 -> coef,ptr2 -> power);
   }

    else if(ptr2 == NULL)
   {
      for( ; ptr1 != NULL; ptr1 = ptr1 -> next)
	addNode (ptr3, ptr1 -> coef, ptr1 -> power);
   }
}


}
