#include <stdlib.h>
#include <stdio.h>
#include "fatal.h"


struct Node
{
    ElementType Element;
    Position Next;
};

// 表头插入
void Insert( ElementType X, List L )
{
    Position P;
    P = malloc( sizeof( struct Node ) );
    P->Element = X;

    P->Next = L->Next;
    L->Next = P;
}

Position Find( ElementType X, List L )
{
    Position P, Pprev;
    P = First( L );
    Pprev = Header( L );
    while( P && P->Element != X )
    {
        Pprev = P;
        P = P->Next;
    }
    if( P )
    {
        Pprev->Next = P->Next;
        P->Next = L->Next;
        L->Next = P;
    }
    return P;
}

Position Header( List L )
{
    return L;
}

Position First( List L )
{
    return L->Next;
}
