#include <stdlib.h>
#include "list.c"

void PrintLots( const List L, const List P )
{
    int i = 1;
    Position p, l;
    p = First( P );  /* First element or NULL */
    l = First( L );  /* First element or NULL */
    while( p != NULL && l != NULL )
    {
        if( Retrieve( p ) == i++ )
        {
            printf( "%d ", Retrieve( l ) );
            p = Advance( p );
        }

        l = Advance( l );
    }
    printf( "\n" );
}

int main( int argc, char *argv[] )
{
    int i;
    List L, P;
    Position Lpos, Ppos;

    L = MakeEmpty( NULL );
    Lpos = Header( L );
    for(i = 50; i <= 70; i++)
    {
        Insert( i, L, Lpos );
        Lpos = Advance( Lpos );
    }

    P = MakeEmpty( NULL );
    Ppos = Header( P );
    Insert( 28, P, Ppos );
    Insert( 7, P, Ppos );
    Insert( 6, P, Ppos );
    Insert( 4, P, Ppos );
    Insert( 1, P, Ppos );

    PrintLots( L, P );
    DeleteList( L );
    DeleteList( P );
    return 1;
}
