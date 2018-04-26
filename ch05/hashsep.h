// 散列表 分离链接法实现
typedef int ElementType;

typedef unsigned int Index;

#ifndef _HashSep_H

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

struct ListNode
{
    ElementType Element;
    Position    Next;
};

struct HashTbl
{
    int TableSize;
    List *TheLists;
};

typedef Position List;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( ElementType Key, HashTable H );
void Insert( ElementType Key, HashTable H );
ElementType Retrieve( Position P );

#endif  /* _HashSep_H */