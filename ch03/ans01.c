#include <stdio.h>
#include "list.c"

void PrintList( const List L)
{
    Position P = Header( L );
    while ( !IsLast( P, L ) )
    {
        P = Advance( P );
        printf( "%d ", Retrieve( P ) );
    }
    printf( "\n" );
}

int main( int argc, char *argv[] )
{
    List L;
    Position P;
    // int i;
    L = MakeEmpty( NULL );
    P = Header(L);
    Insert( 580, L, P );
    P = Advance( P );
    Insert( 581, L, P );
    P = Advance( P );
    Insert( 58, L, P );
    P = Advance( P );

    PrintList( L );

    DeleteList( L );
    return 0;
}
