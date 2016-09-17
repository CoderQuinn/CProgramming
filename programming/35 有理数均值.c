#include <stdio.h>
#define Max 100
typedef struct
{
    int mole;
    int deno;
} Fraction;

int GCD(int a, int b)
{
    int R;
    a = a>=0 ? a : (-a);
    b = a>=0 ? b : (-b);
    
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
    if (f->mole == 0)
        printf("0");
    else if (f->deno == 1)
        printf("%d", f->mole);
    else
    {
        if (f->mole*f->deno < 0 && f->deno <0)
        {
            f->deno = -f->deno;
            f->mole = -f->mole;
        }
        printf("%d/%d", f->mole, f->deno);
    }
}

Fraction *Average(Fraction *average, Fraction fra[], int n)
{
    int i, divisor;
    Fraction sum, *f;
    
    sum = fra[0];
    f = &sum;
    
    for (i = 1; i < n; i++)
        f = Add(f, &fra[i]);
        
    f->deno *= n;
    divisor = GCD(f->mole, f->deno);
    f->mole = f->mole / divisor;
    f->deno = f->deno / divisor;
    
    average->mole = f->mole;
    average->deno = f->deno;
    return average;
}

int main()
{
    int i, n;
    Fraction fra[Max];
    Fraction ave, *f;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d/%d", &fra[i].mole, &fra[i].deno);
    f = Average(&ave, fra, n);
    Print(f);
    return 0;
}