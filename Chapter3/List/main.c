#include "linked_list.h"

int main()
{
	int num;
	List L = NULL;
	
	printf( "Enter the number of element you want to create\n" );
	scanf( "%d", &num );
	
	L = createList( L, num );
	printList( L );
	system( "pause" );
	return 0;
}
