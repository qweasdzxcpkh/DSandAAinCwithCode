#include <stdlib.h>

// 最大项只能20次方
#define MaxDegree 20

typedef struct Node *PtrToNode;
typedef PtrToNode Polynomial;
struct Node
{
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
