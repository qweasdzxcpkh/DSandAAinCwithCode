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


int main(int argc, char *argv[])
{
    printf("dynamicPlanPow 3^5 = %lld\n\n", dynamicPlanPow(3, 5));
    printf("pow 3^5 = %f\n\n", pow(3, 5));
    return 1;
}
