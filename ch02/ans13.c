# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>


// T(n)=O(sqrt(N))
bool is_prime(int N)
{
    if(N == 2)
        return true;

    // 奇数
    if(N % 2 == 1)  /* faster judge: (N / 2) < N - (N / 2) */
    {
        int N_sqrt = (int)sqrt(N);
        for(int i = 3; i <= N_sqrt; i += 2)
            if(N % i == 0)
                return false;
    }
    return true;
}

// 返回N的二进制数的位数
int binary_digit(int N)
{
    return (int)log2(N) + 1;
}


int main(int argc, char *argv[])
{
    bool result;
    result = is_prime(5);
    printf("is prime of 5? %d\n", result);

    result = is_prime(25);
    printf("is prime of 25? %d\n", result);

    result = is_prime(1993);
    printf("is prime of 1993? %d\n", result);

    printf("%d\n", binary_digit(37));
}
