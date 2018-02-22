# include <stdio.h>
# include <stdlib.h>

// T(n)=N
int ExistUnderEqual_0(int *A, int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        if(*(A+i) == i)
            return i;
    }
    return -1;
}

// T(n)=logN recursive
int ExistUnderEqual_1(int *A, int Left, int Right)
{
    if(Left > Right)  /* Base case */
        return -1;

    int Center = (Left + Right) / 2;
    if(*(A+Center) < Center)
        return ExistUnderEqual_1(A, Center+1, Right);
    else if(*(A+Center) > Center)
        return ExistUnderEqual_1(A, Left, Center-1);
    else
        return Center;
}

// T(n)=logN loop
int ExistUnderEqual_2(int *A, int N)
{
    int Center;
    int Left = 0; int Right = N - 1;
    while(Left <= Right)
    {
        Center = (Left + Right) / 2;
        if(*(A+Center) < Center)
            Left = Center + 1;
        else if(*(A+Center) > Center)
            Right = Center - 1;
        else
            return Center;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int a[] = {-4, -2, 0, 1, 4, 6, 9, 12, 34, 42, 80};
    int result_0, result_1, result_2;

    result_0 = ExistUnderEqual_0(a, 11);
    result_1 = ExistUnderEqual_1(a, 0, 10);
    result_2 = ExistUnderEqual_2(a, 11);
    // -1 means have not equal
    printf("find i = %d in ExistUnderEqual_0\n", result_0);
    printf("find i = %d in ExistUnderEqual_1\n", result_1);
    printf("find i = %d in ExistUnderEqual_2\n", result_2);
    return 0;
}
