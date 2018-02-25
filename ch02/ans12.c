# include <stdio.h>
# include <stdlib.h>

int Min3(int a, int b, int c)
{
    if(a <= b && a <= c)  /* Base Case */
        return a;
    else
        return Min3(b, c, a);
}

// T(n)=O(NlogN)
int MinSubsequenceSum(const int A[], int Left, int Right)
{
    int MinLeftSum, MinRightSum;
    int MinLeftBorderSum, MinRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;

    if(Left == Right)  /* Base Case */
        return A[Left];

    Center = (Left + Right) / 2;
    MinLeftSum = MinSubsequenceSum(A, Left, Center);
    MinRightSum = MinSubsequenceSum(A, Center+1, Right);

    MinLeftBorderSum = A[Center]; LeftBorderSum = 0;
    for(i=Center; i>=Left; i--)
    {
        LeftBorderSum += A[i];
        if(LeftBorderSum < MinLeftBorderSum)
            MinLeftBorderSum = LeftBorderSum;
    }

    MinRightBorderSum = A[Center+1]; RightBorderSum = 0;
    for(i=Center+1; i<=Right; i++)
    {
        RightBorderSum += A[i];
        if(RightBorderSum < MinRightBorderSum)
            MinRightBorderSum = RightBorderSum;
    }

    return Min3(MinRightSum, MinLeftSum, MinRightBorderSum+MinLeftBorderSum);
}

int MinSubsequencePositiveSum()
{
    return 0;
}

int MaxSubsequenceMuti()
{
    return 0;
}

int main(int argc, char *argv[])
{
    int a[] = {4, -7, 5, -2, -4, 2, 6, -2};
    int result;  // -8
    result = MinSubsequenceSum(a, 0, 7);
    printf("exec MinSubsequenceSum have result = %d\n", result);
    return 0;
}
