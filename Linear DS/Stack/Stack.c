#include<stdio.h>
#include<stdlib.h>
#define size 10
int top=-1, i, stack[size];
void push(int x)
{
	if(top==size)
		printf("cannot push\n");
	else
	{
		top++;
		stack[top]=x;
		
	}
}
void pop()
{
	if(top==-1)
		printf("Stack is empty\n");
	else
	{
		printf("%d\n", stack[top]);
		top--;
	}
}
void display()
{
	for(i=top;i>=0;i--)
		printf("elements are: %d\n", stack[i]);
}
int main()
{
	int ch, x, f=0;
	while(f==0)
	{
		printf("1.Push \n2.Pop\n3.Display\n4.exit\n");
		scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			scanf("%d",&x);
			push(x);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(1);
	}
}
return 0;
}
