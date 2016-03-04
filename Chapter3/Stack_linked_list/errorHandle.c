#include"errorHandle.h"

void FatalError( char* errorMessage )
{
	printf( "%s", errorMessage );
	printf( "\n" );
}
void Error( char* errorMessage )
{
	printf( "%s", errorMessage );
	printf( "\n" );
}