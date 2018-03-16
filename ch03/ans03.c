#include <stdlib.h>
#include "list.c"

void SwapWithNext( Position BeforeP, List L )
{
    // 单链表
    // 已省略错误检测
    Position P, AfterP;
    AfterP = Advance( P );

    P = BeforeP->Next;
    AfterP = P->Next;

    // 交换
    P->Next = AfterP->Next;
    AfterP->Next = P;
    BeforeP->Next = AfterP;
}

void SwapWithNext_DoubleList( Position P, List L )
{
    // 双向链表
    // 省略错误检测
    Position BeforeP, AfterP;
    BeforeP = P->Prev;
    AfterP = P->Next;

    // 交换
    AfterP->Next->Prev = P;
    P->Next = AfterP->Next;
    AfterP->Next = P;
    P->Prev = AfterP;
    AfterP->Prev = BeforeP;
    BeforeP->Next = AfterP;
}
