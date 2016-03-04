#include<stdio.h>
#include"stack.h"

int main()
{
	ElementType X;
	Stack S = CreateStack();
	scanf("%d", &X);
	while( X != -1 )
	{
		Push( X, S);
		scanf("%d", &X);
	}
	//DisposeStack( S );
	PrintStack( S );
	return 0;
}