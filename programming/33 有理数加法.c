#include <stdio.h>
typedef struct
{
    int mole;
    int deno;
} Fraction;

int GCD(int a, int b)
{
    int R;
    do
    {
        R = a % b;
        a = b;
        b = R;
    } while (R != 0);
    return a;
}

Fraction *Add(Fraction *f1, Fraction *f2)
{
    int divisor;
    divisor = GCD(f1->deno, f2->deno);
    
    f1->mole = (f2->deno * f1->mole + f2->mole * f1->deno ) / divisor;
    f1->deno = f1->deno * f2->deno / divisor;
    
    divisor = GCD(f1->mole, f1->deno);
    f1->mole = f1->mole / divisor;
    f1->deno = f1->deno / divisor;
    return f1;
}

void Print(Fraction *f)
{
    if (f->deno == 1)
        printf("%d", f->mole);
    else
        printf("%d/%d", f->mole, f->deno);
}

int main()
{
    Fraction f1, f2, *f;
    int divisor;
    
    scanf("%d/%d %d/%d", &f1.mole, &f1.deno, &f2.mole, &f2.deno);
    
    f = &f1;
    f = Add(f, &f2);
    Print(f);
    return 0;
}