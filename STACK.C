#include<stdio.h>
#include<conio.h>
#define size 50
int top=-1;
int a[size];
void push();
void pop();
void s_top();
void display();
int main()
   {
     int choice;
     while(1)
     {
       printf("\n OPERATIONS PERFORMED BY STACK");
       printf("\n 1.push\n2.pop\n3.top element \n4.dispaly stack\n 5.exit");
       printf("\n ENTER YOUR CHOICE:\n");
       scanf("%d",&choice);
       switch(choice)
       {
	 case 1: push();
		 break;
	 case 2:pop();
		break;
	 case 3:s_top();
		break;
	 case 4:display();
		break;
	 case 5:exit(0);
	 default:printf("\n invalid choice");
       }
     }
  }
  void push()
   {
     int x;
     if(top>=size-1)
     {
       printf("\n overflow");
     }
     else
     {
     printf("\n ENTER THE ELEMENT INSERTED INTO STACK");
     scanf("%d",&x);
     top=top+1;
     a[top]=x;
     }
   }
   void pop()
    {
      if(top==-1)
      {
	printf("\n underflow");
      }
      else
      {
      printf("\n popped element is %d",a[top]);
      top=top-1;
      }
    }
    void s_top()
    {
      int x;
      if(top==-1)
      {
	printf("\n underflow");
      }
      else
      {
      x=a[top];
      printf("top element is %d:",x);
    }
  }
    void display()
     {
       int i;
       if(top==-1)
	{
	  printf("\n underflow");
	}
	else
	{
	 printf("\n element present in the stack:\n");
	 for( i=top;i>=0;--i)
	 printf("%d \n",a[i]);
       }
    }

