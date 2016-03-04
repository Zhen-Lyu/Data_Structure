/*Stack implementation*/
#include <stdio.h>
#include "stack.h"
#include "errorHandle.h"

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty( Stack S )
{
    return S->Next == NULL;
}
Stack CreateStack( void )
{
    Stack S = malloc( sizeof( struct Node ) );
    if( S == NULL )
        FatalError( "Out of space" );
    S->Next = NULL;
    MakeEmpty( S );
    return S;
}
void DisposeStack( Stack S )
{
    MakeEmpty( S );
    free( S );
}
void MakeEmpty( Stack S )
{
    if( S == NULL)
        Error( "Must use CreateStack First!" );
    else 
        while( !IsEmpty( S ) )
            Pop( S );
}
void Push( ElementType X, Stack S )
{
    PtrToNode TmpCell;
    
    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of Space" );
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}
ElementType Top( Stack S )
{
    if( !IsEmpty( S ) )
        return S->Next->Element;
    Error( "Empty Stack" );
    return 0;
}
void Pop( Stack S )
{
    Stack FirstCell;
    
    if( IsEmpty( S ) )
        Error( "Empty Stack" );
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free( FirstCell );
    }
}
void PrintStack( Stack S )
{
	if( IsEmpty( S ) )
		Error( "Empty Stack" );
	else
		printf( "Printing Stack...\n" );
		while( S->Next != NULL)
		{
			S = S->Next;
			printf( "%d\n", S->Element );
		}		
}