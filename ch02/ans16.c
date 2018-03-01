# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

#ifndef LL
#define LL long long
#endif


// 二进制，动态规划，快速求幂
LL dynamicPlanPow(LL x, int pow)
{
    LL result = 1;
    while(pow > 0)
    {
        if(pow & 1)
            result *= x;
        x *= x;
        pow >>= 1;
    }

    return result;
}

// 递归快速求幂
LL quickPowRecursive(LL x, int pow)
{
    if(pow == 0)  /* Base Case */
        return 1;

    if(pow & 1)
        return x * quickPowRecursive(x * x, pow >>= 1);
    else
        return quickPowRecursive(x * x, pow >>= 1);
}


int main(int argc, char *argv[])
{
    printf("dynamicPlanPow 3^5 = %lld\n\n", dynamicPlanPow(3, 5));
    printf("quickPowRecursive 3^5 = %lld\n\n", quickPowRecursive(3, 5));
    printf("pow 3^5 = %f\n\n", pow(3, 5));
    return 1;
}
