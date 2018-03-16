#include <stdlib.h>
#include <stdio.h>
#include "fatal.h"
#include "adjust_list_cursor.h"

struct Node
{
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[ SpaceSize ];

// 必须先初始化所有空间
void InitializeCursorSpace()
{
    int i;

    for( i = 0; i < SpaceSize; i++ )
        CursorSpace[ i ].Next = i + 1;
    CursorSpace[ SpaceSize - 1 ].Next = 0;
}

static Position CursorAlloc()
{
    Position P;

    P = CursorSpace[ 0 ].Next;
    CursorSpace[ 0 ].Next = CursorSpace[ P ].Next;

    return P;
}

static void CursorFree( Position P )
{
    CursorSpace[ P ].Next = CursorSpace[ 0 ].Next;
    CursorSpace[ 0 ].Next = P;
}

void Insert( ElementType X, List L )
{
    Position P, H;
    P = CursorAlloc();
    if( P == 0 )
        FatalError( "Out of space!!!" );
    H = Header( L );
    CursorSpace[ P ].Element = X;
    CursorSpace[ P ].Next = CursorSpace[ H ].Next;
    CursorSpace[ H ].Next = P;
}

Position Find( ElementType X, List L )
{
    Position P, Pprev;
    P = First( L );
    Pprev = Header( L );
    while( P && CursorSpace[ P ].Element != X )
    {
        Pprev = P;
        P = CursorSpace[ P ].Next;
    }
    // 存在P则移到表头
    if( P )
    {
        CursorSpace[ Pprev ].Next = CursorSpace[ P ].Next;
        CursorSpace[ P ].Next = CursorSpace[ L ].Next;
        CursorSpace[ L ].Next = P;
    }
    return P
}

Position Header( List L )
{
    return L;
}

Position First( List L )
{
    return CursorSpace[ L ].Next;
}
