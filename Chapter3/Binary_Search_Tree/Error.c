#include"Error.h"
void FatalError( char* errorMessage )
{
	printf( "%s", errorMessage );
}
void Error( char* errorMessage )
{
	printf( "%s", errorMessage );
}