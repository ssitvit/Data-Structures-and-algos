//Author Tejas K Mukherjee (C code)
#include <stdio.h>
#define max 100
char stack[max];
int top = -1;
int
isempty ()
{
  if (top == -1)
    return 1;
  else
    return 0;
}

int
isfull ()
{
  if (top == max - 1)
    return 1;
  else
    return 0;
}

void
pop ()
{
  if (isempty ())
    printf("stack underflow");
  else
    top = top - 1;
}

void
display ()
{
  int i;
  for (i = top; i >= 0; i--)
    {
      printf ("%c", stack[i]);
    }
}

int
push (int x)
{
  if (isfull ())
    printf ("stack overflow");
  else
    {
      stack[++top] = x;
    }
}

int
precedence (char x)
{
  if (x == '^')
  return 4;
  else if (x == '/')
    return 3;
  else if (x == '*')
    return 3;
  else if (x == '+')
    return 2;
  else if (x == '-')
    return 2;
  else if (x == '(')
    return 0;
}

int
main ()
{
  char f[30];
  int len = 0;
  printf ("enter infix statement : ");
  gets (f);
  printf("postfix statement : ");
  while (f[len] != '\0')
    {
      char sam = f[len++];
      if (sam == '(' || sam == '+' || sam == '-' || sam == '*' || sam == '/'
	  || sam == '^' || sam == ')')
	{
	  if (sam == '(')
	    push (sam);
	  else if (sam == ')')
	    {
	      while (stack[top] != '(')
		{
		  printf ("%c", stack[top]);
		  pop();
		}
	      pop ();
	    }
	  else
	    {
	    A:
	      if (top == -1)
		push (sam);
	      else if (precedence (sam) > precedence (stack[top]))
		push (sam);
	      else
		{ 
		  printf ("%c", stack[top]);
		  pop();
		  goto A;
		}
	    }
	}
      else
	printf ("%c", sam);
    }
  display ();
  return 0;
}


