#include <stdlib.h>
#include "polynomial.c"
#include <stdio.h>

int Max(int a, int b)
{
    if( a > b )
        return a;
    else
        return b;
}

Polynomial AddPolynomial( const Polynomial Poly1, const Polynomial Poly2)
{
    int i;
    PtrToNode PNode1, PNode2, PSNode, Tail;
    Polynomial PolySum;
    PolySum = malloc( sizeof( struct Node ) );
    Tail = Header(PolySum);

    PNode1 = First(Poly1);
    PNode2 = First(Poly2);
    while( PNode1 != NULL && PNode2 !=NULL )
    {
        PSNode = malloc( sizeof( struct Node ) );
        if( PNode1->Exponent > PNode2->Exponent )
        {
            PSNode->Exponent = PNode1->Exponent;
            PSNode->Coefficient = PNode1->Coefficient;
            PNode1 = Advance( PNode1 );
        } else if( PNode1->Exponent < PNode2->Exponent )
        {
            PSNode->Exponent = PNode2->Exponent;
            PSNode->Coefficient = PNode2->Coefficient;
            PNode2 = Advance( PNode2 );
        } else
        {
            PSNode->Exponent = PNode1->Exponent;
            PSNode->Coefficient = PNode1->Coefficient + PNode2->Coefficient;
            PNode1 = Advance( PNode1 );
            PNode2 = Advance( PNode2 );
        }
        Tail->Next = PSNode;
        Tail = Tail->Next;
    }
    while( PNode1 != NULL )
    {
        PSNode = malloc( sizeof( struct Node ) );
        PSNode->Exponent = PNode1->Exponent;
        PSNode->Coefficient = PNode1->Coefficient;
        PNode1 = Advance( PNode1 );
        Tail->Next = PSNode;
        Tail = Tail->Next;
    }
    while( PNode2 != NULL )
    {
        PSNode = malloc( sizeof( struct Node ) );
        PSNode->Exponent = PNode2->Exponent;
        PSNode->Coefficient = PNode2->Coefficient;
        PNode2 = Advance( PNode2 );
        Tail->Next = PSNode;
        Tail = Tail->Next;
    }
    return PolySum;
}
