#include <stdlib.h>
#include "list.c"

void Union( List L, List P )
{
    Position Lpos, Ppos;
    Lpos = First( L );
    Ppos = First( P );

    while( Lpos != NULL && Ppos != NULL )
    {
        if( Retrieve( Lpos ) < Retrieve( Ppos ) )
        {
            printf( "%d ", Retrieve( Lpos ) );
            Lpos = Advance( Lpos );
        }
        else if( Retrieve( Lpos ) > Retrieve( Ppos ) )
        {
            printf( "%d ", Retrieve( Ppos ) );
            Ppos = Advance( Ppos );
        }
        else
        {
            printf( "%d ", Retrieve( Lpos ) );
            Lpos = Advance( Lpos );
            Ppos = Advance( Ppos );
        }
    }
    while( Lpos != NULL )
    {
        printf( "%d ", Lpos );
        Lpos = Advance( Lpos );
    }
    while( Ppos != NULL )
    {
        printf( "%d ", Ppos );
        Ppos = Advance( Ppos );
    }
    printf( "\n" );
}
