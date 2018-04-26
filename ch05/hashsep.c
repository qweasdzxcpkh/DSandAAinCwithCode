#include "fatal.h"
#include "hashsep.h"
#include <stdlib.h>

#define MinTableSize (10)

// N的下一个素数
static int NextPrime( int N )
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
Index Hash( ElementType Key, int TableSize )
{
    return Key % TableSize;
}

HashTable InitializeTable( int TableSize )
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

    /* Allocate array of lists */
    H->TheLists = malloc( sizeof( List ) * H->TableSize );
    if( H->TheLists == NULL )
        FatalError( "Out of space!!!" );

    // 散列表每个单元增加一个表头
    for( i = 0; i < H->TableSize; i++ )
    {
        H->TheLists[ i ] = malloc( sizeof( struct ListNode ) );  // 这句应该移动到for之前，并且一次过申请足够的空间：malloc( sizeof( struct ListNode ) * H->TableSize )
        if( H->TheLists[ i ] == NULL )
            FatalError( "Out of space!!!" );
        else
            H->TheLists[ i ]->Next = NULL;
    }

    return H;
}

Position Find( ElementType Key, HashTable H )
{
    Position P;
    List L;

    L = H->TheLists[ Hash( Key, H->TableSize ) ];
    P = L->Next;
    while( P != NULL && P->Element != Key )
                        // 如果是字符串需要用strcmp
        P = P->Next;
    return P;
}

void Insert( ElementType Key, HashTable H )
{
    Position Pos, NewCell;
    List L;

    Pos = Find( Key, H );
    if( Pos == NULL )   /* key不存在才插入 */
    {
        NewCell = malloc( sizeof( struct ListNode ) );
        if( NewCell == NULL )
            FatalError( "Out of space!!!" );
        else
        {
            L = H->TheLists[ Hash( Key, H->TableSize ) ];
            NewCell->Next = L->Next;
            NewCell->Element = Key;  /* 如果字符串需要用strcpy */
            L->Next = NewCell;
        }
    }
}

ElementType Retrieve( Position P )
{
    return P->Element;
}

void DestroyTable( HashTable H )
{
    int i;

    for( i = 0; i < H->TableSize; i++ )
    {
        Position P = H->TheLists[ i ];
        Position Tmp;

        while( P != NULL )
        {
            Tmp = P->Next;
            free( P );
            P = Tmp;
        }
    }

    free( H->TheLists );
    free( H );
}
