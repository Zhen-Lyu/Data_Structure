//SearchTree Implement
#include "Tree.h"
#include "Error.h"
struct TreeNode{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};
SearchTree MakeEmpty( SearchTree T ){
	if( T != NULL ){
		MakeEmpty( T->Left );
		MakeEmpty( T->Right );
		free( T );
	}
	return NULL;
}
Position Find( ElementType X, SearchTree T ){
	if( T == NULL ){
		return NULL;
	}
	if( X < T->Element ){
		return Find( X, T->Left );
	}
	else
	if( X > T->Element ){
		return Find( X, T->Right );
	}
	else
	if( X == T->Element ){
		return T;
	}
}
/*FindMin Iteratively*/
Position FindMin( SearchTree T ){
	Position P;
	P = T;
	while( P->Left != NULL ){
		P = P->Left;
	}
	return P;
}
/*FindMin Recursively*/
Position FindMin_R( SearchTree T ){
	if( T == NULL ){
		return NULL;
	}
	if( T->Left == NULL ){
		return T;
	}
	else{
		return FindMin( T->Left );
	}
}
/*FindMax Iteratively*/
Position FindMax( SearchTree T ){
	Position P;
	P = T;
	while( P->Right != NULL ){
		P = P->Right;
	}
	return P;
}
/*FindMax Recursively*/
Position FindMax_R( SearchTree T ){
	if( T == NULL ){
		return NULL;
	}
	if( T->Right == NULL ){
		return T;
	}
	else{
		return FindMax( T->Right );
	}
}
SearchTree Insert( ElementType X, SearchTree T ){
	if( T == NULL ){
		T = (SearchTree)malloc( sizeof( struct TreeNode ) );
		if( T == NULL ){
			FatalError( "Out of Space" );
		}
		else{
			T->Element = X;
			T->Left = NULL;
			T->Right = NULL;
		}
	}
	else 
	if( X < T->Element ){
		T->Left = Insert( X, T->Left );
	}
	else 
	if( X > T->Element ){
		T->Right = Insert( X, T->Right );
	}
	return T;
}
SearchTree Delete( ElementType X, SearchTree T ){
	Position TmpCell;
	if( T == NULL ){
		Error( "Element not found in the tree" );
	}
	else
	if( X < T->Element ){
		T->Left = Delete( X, T->Left );
	}
	else
	if( X > T->Element ){
		T->Right = Delete( X, T->Right );
	}
	else 
	if( T->Left && T->Right ){
		TmpCell = FindMin( T->Right );
		T->Element = TmpCell->Element;
		T->Right = Delete( T->Element, T->Right );
	}
	else{
		TmpCell = T;
		if( T->Right == NULL ){
			T = T->Left;
		}
		else if( T->Left == NULL ){
			T = T->Right;
		}
		free( TmpCell );
	}
	return T;
}
ElementType Retrieve( Position P ){
	if( P != NULL ){
		return P->Element;
	}
	else{
		Error( "Null Pointer!" );
	}
}