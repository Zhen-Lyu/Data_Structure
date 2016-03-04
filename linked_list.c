#include"linked_list.h"
#include"errorHandle.h"
struct Node
{
	ElementType Element;
	Position    Next;
};

List MakeEmpty( List L )
{
	L = malloc( sizeof( struct Node ) );
	L->Next = NULL;
	return L;
}

int IsEmpty( List L )
{
	return L->Next == NULL;
}

int isLast( Position P, List L )
{
	return P->Next == NULL;
}

/*Find Position of X in L, return NULL if not found*/
Position Find( ElementType X, List L )
{
	Position P;
	P = L->Next;
	// Using && so that if first half is false
	// second half will not be executed
	while( P != NULL && P->Element !=X )
		P = P->Next;
	return P;
}

void Delete( ElementType X, List L )
{
	Position P, TmpCell;
	
	P = FindPrevious( X, L);
	
	if( !isLast( P, L ) )
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free( TmpCell );
	}
}

/*Return the previous position of X*/
/*If X is not found, return the last position*/
/*Whose Next field is NULL*/
Position FindPrevious( ElementType X, List L )
{
	Position P;
	P = L;
	
	while( P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}
	return P;
}

void Insert( ElementType X, List L, Position P)
{
	Position TmpCell;
	TmpCell = malloc( sizeof( struct Node ) );
	if( TmpCell == NULL )
		FatalError( "Out of Memory!");
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void DeleteList( List L )
{
	Position P, Tmp;
	P = L->Next;
	L->Next = NULL;
	while( P != NULL )
	{
		Tmp = P->Next;
		free( P );
		P = Tmp;
	}
}

Position Header( List L )
{
	return L;
}

Position First( List L )
{
	Position P;
	P = L->Next;
	return P;
}

ElementType Retrieve( Position P )
{
	return P->Element;
}

void printList( List L )
{
	Position P;
	P = L->Next;
	
	printf( "Printing List...\n" );
	while( P != NULL )
	{
		printf( "%d\n", P->Element );
		P = P->Next;
	}
}
/*Create a linked list with n random element*/
List createList( List L, int num )
{
	int i;
	time_t t;
	
	ElementType X;
	Position P,TmpCell;
	
	
	L = MakeEmpty( L );
	P = L;
	
	srand( ( unsigned ) time( &t ) );
	
	for( i = 0; i < num; i++ )
	{
		X = rand() % 100;
		TmpCell = malloc( sizeof( struct Node ) );
		TmpCell->Element = X;
		TmpCell->Next = NULL;
		P->Next = TmpCell;
		P = P->Next;
	}		
	return L;
}