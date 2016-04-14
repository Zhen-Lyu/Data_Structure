#include "Tree.h"

int main(){
	SearchTree T = NULL;
	T = Insert( 1, T);
	T = Insert( 2, T);
	T = Insert( 5, T);
	T = Insert( 3, T);
	T = Insert( 6, T);
	T = Delete( 5, T );
	MakeEmpty( T );
	return 0;
}