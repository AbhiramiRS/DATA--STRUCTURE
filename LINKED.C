#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
  {
    int data;
    struct node *link;
  };
 typedef struct node node;
 node *getnode();
 int main()
       {
	 int choice, n,item;
	 node *first;
	 clrscr();
	 initializelist(&first);
	 printf("ENTER NO OF NODES:");
	 scanf("%d",&n);
	 Llistcreate(&first,n);
	 while(1)
	     {
	       printf("OPERTAIONS ON LINKED LIST");
	       printf("\n \t 1. insert at first:"  );
	       printf("\n \t 2. insert at last:");
	       printf("\n \t 3. insert at specific position");
	       printf("\n \t 4.del first");
	       printf("\n \t 5. del last");
	       printf("\n \t 6. del at specific position");
	       printf("\n \t 7.display list");
	       printf("\n \t 8.search ");
	       printf("\n \t 9 exit");
	       printf("\n \t ENTER YOUR CHOICE:");
	       scanf("%d",&choice);
	       switch(choice)
		 {
		case 1:insertfirst(&first);
		       break;
		case 2:insertlast(&first);
			break;
		case 3:insertatany(&first);
			break;
		case 4:delfirst(&first);
		       break;
		case 5:dellast(&first);
		       break;
		case 6: delany(&first) ;
			break;
		case 7:display(first);
		       break;
		case 8:printf("\n enter element to be searched:");
		       scanf("%d",&item);
		       Lsearch(first,item) ;
		       break;
		case 9:exit(0);
		default:printf("\n invalid choice");
		 }
	     }
       }
initializelist(node **first)
  {
    (*first)=NULL;
  }
Llistcreate(node **f,int n)
{
  node *temp,*current;
  int i, item;
  for(i=1;i<=n;i++)
   {
     printf("\n enter the data field of node #%d:",i);
     scanf("%d",&item);
     temp=getnode();
     temp->data=item;
     temp->link=NULL;
     if(*f==NULL)
	*f=temp;
     else
     current->link=temp;
     current=temp;
   }
 }
 node *getnode()
   {
     node *p;
     p=(node *)malloc(sizeof(node));
     return(p);
   }
 display(node *first)
 {
   printf("\n start->");
   while(first!=NULL)
     {
	printf("%d->",first->data);
	 first=first->link;
     }
 printf("end \n");
 }
 insertfirst(node **first)
  {
   int item;
   node *temp;
   temp=getnode();
   if(temp==NULL)
   {
   printf("\n unable to create a new node");
   return;
   }
 printf("enter item:");
 scanf("%d",&item);
 temp->data=item;
 temp->link=(*first);
 (*first)=temp;
 }
insertlast(node **first)
{
  node *temp,*current;
  int item;
  temp=getnode();
  if(temp==NULL)
  {
   printf("\n unable to create new node");
   return;
   }
   printf("\n enter item:");
   scanf("%d",&item);
   temp->data=item;
   temp->link=NULL;
   if(*first==NULL)
      (*first)=temp;
   else
   {
    current=(*first);
    while(current->link!=NULL)
    current=current->link;
    current->link=temp;
   }
  }
  insertatany(node **first)
  {
    node *current ,*previous,*temp;
    int i;
    int item,pos;
    temp=getnode();
    if(temp==NULL)
    {
       printf("\n unable to create new node");
       return;
    }
       printf(" \n enter item:");
       scanf("%d",&item);
       printf(" \n enter pos:");
       scanf("%d",&pos);

       if((*first==NULL)||(pos==1))
       {
     temp->data=item;
     temp->link=(*first);
     (*first)=temp;
     return;
     }

     current=(*first)->link;
     previous=(*first);
     i=1;
     while(current!=NULL)
       {
       if((i+1)==pos)
       break;
       else
       {
	  previous=current;
	  current=current->link;
	  i++;
	 }
     }
     temp->data=item;
     temp->link=current;
     previous->link=temp;
     }

  delfirst(node **first)
  {
  node *current;
  int item;
  if(*first==NULL)
  {
  printf("\n list is empty");
  return;
  }
  current=(*first);
  item=current->data;
  (*first)=(*first)->link;
  free(current);
  printf("\n deleted item is =%d",item);
  }
  freenode(node *p)
  {
  free(p);
  }
   dellast(node **first)
   {
   node *current,*previous;
   int item;
   if(*first==NULL)
      {
		 printf("\n list empty");
		 return;
      }
      current=(*first);
   previous=NULL;
   if((*first)->link==NULL)
   (*first)=(*first)->link;
   else
   {
   while(current->link!=NULL)
     {
     previous=current;
     current=current->link;
     }
     previous->link=current->link;
     }
   item=current->data;
   freenode(current);
   printf("\n deleted  item is=%d",item);
   }
   delany(node **first)
   {
   node *current,*previous;
   int item,pos,i;
    if(*first==NULL)
    {
    printf("\n list is empty");
    return;
    }
    printf("\n enter position:");
    scanf("%d",&pos);
    if(pos==1)
    {
    current=(*first);
    item=current->data;
    (*first)=(*first)->link;
    freenode(current);
    printf("\n del item is %d",item);
    }
    current=(*first)->link;
    previous=(*first);
    i=2;
    while(current!=NULL)
       {
       if(i==pos)
       {
       previous->link=current->link;
       item=current->data;
       freenode(current);
       printf("\n del item is %d",item);
       }
      else
	  {
	    previous=current;
	    current=current->link;
	   }
	  i++;
	}
     }

Lsearch(node *first,int item)
{
int flag=0,i=1;
if(first==NULL)
{
printf("\n list empty");
return;
}
while(first!=NULL)
{
if(first->data==item)
  {
  flag=1;
  break;
}
else
 first=first->link;
 i++;
}
if(flag==1)
printf("%d found",item);
else
printf("%d not found in list",item);
}

































































































