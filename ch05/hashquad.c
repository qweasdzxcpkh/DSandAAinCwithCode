#include "fatal.h"
#include "hashquad.h"
#include <stdlib.h>

#define MinTableSize (10)

/* Return next prime; assume N >= 10 */
// N的下一个素数
static int
NextPrime( int N )
{
    int i;

    if( N % 2 == 0 )
        N++;
    for( ; ; N += 2 )
    {
        for( i = 3; i * i <= N; i += 2 )
            if( N % i == 0 )
                goto ContOuter;  /* Sorry about this! */
        return N;
      ContOuter: ;
    }
}

// 散列函数
Index
Hash( ElementType Key, int TableSize )
{
    return Key % TableSize;
}

HashTable
InitializeTable( int TableSize )
{
    HashTable H;
    int i;

    if( TableSize < MinTableSize )
    {
        Error( "Table size too small" );
        return NULL;
    }

    /* Allocate table */
    H = malloc( sizeof( struct HashTbl ) );
    if( H == NULL )
        FatalError( "Out of space!!!" );

    H->TableSize = NextPrime( TableSize );

    /* Allocate array of Cells */
    H->TheCells = malloc( sizeof( Cell ) * H->TableSize );
    if( H->TheCells == NULL )
        FatalError( "Out of space!!!" );

    for( i = 0; i < H->TableSize; i++ )
        H->TheCells[ i ].Info = Empty;

    return H;
}


Position
Find( ElementType Key, HashTable H )
{
    Position CurrentPos;
    int CollisionNum;

    CollisionNum = 0;
    CurrentPos = Hash( Key, H->TableSize );
    while( H->TheCells[ CurrentPos ].Info != Empty &&
           H->TheCells[ CurrentPos ].Element != Key )
                    /* Probably need strcmp!! */
    {
        CurrentPos += 2 * ++CollisionNum - 1;
        if( CurrentPos >= H->TableSize )
            CurrentPos -= H->TableSize;
    }
    return CurrentPos;
}


void
Insert( ElementType Key, HashTable H )
{
    Position Pos;

    Pos = Find( Key, H );
    if( H->TheCells[ Pos ].Info != Legitimate )
    {
        /* OK to insert here */
        H->TheCells[ Pos ].Info = Legitimate;
        H->TheCells[ Pos ].Element = Key;
                 /* Probably need strcpy! */
    }
}


HashTable
Rehash( HashTable H )
{
    int i, OldSize;
    Cell *OldCells;

    OldCells = H->TheCells;
    OldSize  = H->TableSize;

    /* Get a new, empty table */
    H = InitializeTable( 2 * OldSize );

    /* Scan through old table, reinserting into new */
    for( i = 0; i < OldSize; i++ )
        if( OldCells[ i ].Info == Legitimate )
            Insert( OldCells[ i ].Element, H );

    free( OldCells );

    return H;
}


ElementType
Retrieve( Position P, HashTable H )
{
    return H->TheCells[ P ].Element;
}

void
DestroyTable( HashTable H )
{
    free( H->TheCells );
    free( H );
}
