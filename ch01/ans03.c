# include <stdio.h>
# include <stdlib.h>

// print 一个数字
void PrintDigit(unsigned int a)
{
    printf("%d", a);
}

// 递归处理一个数
void PrintOut(unsigned int N)
{
    if(N >= 10)
        PrintOut(N / 10);
    PrintDigit(N % 10);
}

unsigned int IntPart(double N)
{
    return (int)N;
}

double DecPart(double N)
{
    return N - IntPart(N);
}

// 处理精度，进一
double RoundUp(double N, int DecPlaces)
{
    int i;
    double AmountToAdd = 0.5;

    for(i=0; i<DecPlaces; i++)
        AmountToAdd /= 10;
    return N + AmountToAdd;
}

void PrintFractionPart(double FractionPart, int DecPlaces)
{
    int i, Adigit;

    for (i=0; i<DecPlaces; i++)
    {
        FractionPart *= 10;
        Adigit = IntPart(FractionPart);
        PrintDigit(Adigit);
        FractionPart = DecPart(FractionPart);
    }
}

void PrintReal(double N, int DecPlaces)
{
    int IntergerPart;
    double FractionPart;

    if(N < 0)
    {
        putchar('-');
        N = -N;
    }
    N = RoundUp(N, DecPlaces);
    IntergerPart = IntPart(N); FractionPart = DecPart(N);
    PrintOut(IntergerPart);
    if(DecPlaces > 0)
        putchar('.');
    PrintFractionPart(FractionPart, DecPlaces);
}


int main(int argc,char *argv[ ])
{
    if(argc != 3)
        printf("usage:\n    %s 123.456789 3", argv[0]);
    else
    {
        PrintReal(atof(argv[1]), atoi(argv[2]));
    }

    printf("\nPress enter to continue...\n");
    getchar();
    return 0;
}
