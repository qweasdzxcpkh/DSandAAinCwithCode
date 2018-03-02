# include <stdio.h>
# include <stdlib.h>


struct ListAndSize
{
    int (*list)[];
    int size;
};

struct ListAndSize getMainElement(struct ListAndSize A)
{
    if(A.size == 2)
    {
        if((*(A.list))[0] == (*(A.list))[1])
        {
            A.size = 1;
            return A;
        }
        else
        {
            A.size = 0;
            return A;
        }
    }
    if(A.size == 1)
        return A;
    if(A.size == 0)
        return A;

    int i;
    struct ListAndSize B;
    struct ListAndSize C;
    int B_list[A.size];
    B.list = &B_list; B.size = 0;
    for(i = 0; i + 1 < A.size; i += 2)
        if((*(A.list))[i] == (*(A.list))[i+1])
        {
            (*(B.list))[B.size] = (*(A.list))[i];
            B.size += 1;
        }

    C = getMainElement(B);
    // N为奇数且i是最后一个元素下标
    if(i == A.size - 1)
    {
        if(C.size == 1)
        {
            if((*(C.list))[0] != (*(A.list))[i])
                C.size = -1;
        }
        else if(C.size == 2)
        {
            if((*(C.list))[0] == (*(A.list))[i])
                C.size = 1;
            else if((*(C.list))[1] == (*(A.list))[i])
            {
                (*(C.list))[0] = (*(C.list))[1];
                C.size = 1;
            }
            else
                C.size = -1;
        }
        else if(C.size == 0)  // 遇到这种情况就认命遍历吧
        {
            int j, count = 0;
            for(j = 0; j < A.size; j++)
                if((*(A.list))[i] == (*(A.list))[j])
                    count++;
            if(count > A.size/2)
            {
                (*(C.list))[0] = (*(A.list))[i];
                C.size = 1;
            }
        }
    }
    return C;
}

int enter(int lists[], int N)
{
    struct ListAndSize A, result;
    A.list = (int (*)[])lists;
    A.size = N;
    result = getMainElement(A);
    if(result.size == 0)
        return -1;  // 无主元素
    else if(result.size == 1)
        return (*(result.list))[0];
    else
        return -2;  // 程序错误
}

int main(int argc, char *argv[])
{
    int result;
    int a[] = {5,5,5,7,7,5,0,0,5,5};  // 主元素 = 5
    int b[] = {7,5,5,7,7,7,5,5,7};  // 主元素 = 7
    int c[] = {0,1,1,0,0};  // 主元素 = 0
    result = enter(a, 10);
    printf("main element of a[]: %d\n", result);
    result = enter(b, 9);
    printf("main element of b[]: %d\n", result);
    result = enter(c, 5);
    printf("main element of c[]: %d\n", result);
    return 1;
}
