#include <stdlib.h>
#include "list.c"

void Intersect( List L, List P )
{
    Position Lpos, Ppos;
    Lpos = First( L );
    Ppos = First( P );

    while( Lpos != NULL && Ppos != NULL )
    {
        if( Retrieve( Lpos ) < Retrieve( Ppos ) )
            Lpos = Advance( Lpos );
        else if( Retrieve( Lpos ) > Retrieve( Ppos ) )
            Ppos = Advance( Ppos );
        else
            printf( "%d ", Retrieve( Lpos ) );
    }
    printf( "\n" );
}
