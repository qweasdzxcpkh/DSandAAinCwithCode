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

// T(n)=O(N)
int MinSubsequenceSum_linear(const int A[], int N)
{
    int ThisSum, MinSum;
    int i;

    ThisSum = 0; MinSum = 0;
    for(i=0; i<N; i++)
    {
        ThisSum += A[i];
        if(ThisSum < MinSum)
            MinSum = ThisSum;
        if(ThisSum >= 0)
            ThisSum = 0;
    }

    return MinSum;
}


struct Item
{
    int value;
    int rank;
};

int MinSubsequencePositiveSum(const int A[], int N)
{
    /*
    思路：
    0、求出以A[0]为开头的所有子序列和，这个和可以通过相减获得所有子序列和
    1、以i为数组下标，求出一个S(i)数组，里面是数组的前i项和
    2、使用一个结构体(S, i)
    */

    struct Item S[N+1];
    struct Item tempItem;
    int TempSum, i, j, MinPosSum;

    TempSum = 0;
    S[0].value = S[0].rank = 0;
    for(i=0; i<N; i++)
    {
        TempSum += A[i];
        S[i+1].value = TempSum;
        S[i+1].rank = i + 1;
    }

    // 插入排序
    for(i=1; i<N+1; i++)
    {
        tempItem.value = S[i].value;
        tempItem.rank = S[i].rank;
        j = i - 1;
        while(j >= 0)
        {
            if(S[j].value > S[j+1].value)
            {
                S[j+1].value = S[j].value; S[j+1].rank = S[j].rank;
                S[j].value = tempItem.value; S[j].rank = tempItem.rank;
            }
            j -= 1;
        }
    }

    // for(i=0; i<N+1; i++)
    //     printf("%d ", S[i].value);

    MinPosSum = 0;
    for(i=0; i<N+1-1; i++)
    {
        if(S[i+1].rank > S[i].rank)
        {
            if((S[i+1].value - S[i].value) < MinPosSum && (S[i+1].value - S[i].value) > 0)
            {
                MinPosSum = (S[i+1].value - S[i].value);
            }
            else if(MinPosSum <= 0)
                MinPosSum = (S[i+1].value - S[i].value);
            // printf("fuxk rank: %d - %d and MInPosSum = %d, %d\n", S[i+1].rank, S[i].rank, MinPosSum, (S[i+1].value - S[i].value));
        }
    }

    return MinPosSum;
}

int MaxSubsequenceMuti()
{
    return 0;
}

int main(int argc, char *argv[])
{
    int a[] = {4, -7, 5, -2, -4, 2, 6, -2};
    int result;
    result = MinSubsequenceSum(a, 0, 7);
    printf("exec MinSubsequenceSum have result = %d\n\n", result);  /* =-8 */

    result = MinSubsequenceSum_linear(a, 8);
    printf("exec MinSubsequenceSum_linear have result = %d\n\n", result);  /* =-8 */

    result = MinSubsequencePositiveSum(a, 8);
    printf("exec MinSubsequencePositiveSum have result = %d\n\n", result);  /* =1 */

    return 0;
}
