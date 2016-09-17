/*
 
 */
#include <stdio.h>
#include <math.h>
#define ZERO 0.1

typedef struct
{
    double Re;
    double Im;
} Complex;

void AComplex(Complex x)
{
    if (x.Im>=0)
        printf("(%.1f+%.1fi)", x.Re, x.Im);
    else
        printf("(%.1f%.1fi)", x.Re, x.Im);
}

void OperatorOut(Complex a, Complex b, char c)
{
    AComplex(a);
    printf(" %c ", c);
    AComplex(b);
    printf(" = ");
}

void Result(Complex x)
{
    if (fabs(x.Re)<ZERO && fabs(x.Im)<ZERO)
        printf("0.0\n");
    else if(fabs(x.Re)>ZERO && fabs(x.Im)<ZERO)
        printf("%.1f\n", x.Re);
    else if(fabs(x.Re)<ZERO && fabs(x.Im)>ZERO)
        printf("%.1fi\n", x.Im);
    else
    {
        if (x.Im > 0)
            printf("%.1f+%.1fi\n",x.Re, x.Im);
        else
            printf("%.1f%.1fi\n", x.Re, x.Im);
    }
}

void Add(Complex a, Complex b)
{
    Complex c;
    c.Re = a.Re + b.Re;
    c.Im = a.Im + b.Im;
    OperatorOut(a, b, '+');
    Result(c);
}

void Sub(Complex a, Complex b)
{
    Complex c;
    c.Re = a.Re - b.Re;
    c.Im = a.Im - b.Im;
    OperatorOut(a, b, '-');
    Result(c);
}

void Mult(Complex a, Complex b)
{
    Complex c;
    c.Re = a.Re*b.Re - a.Im*b.Im;
    c.Im = a.Re*b.Im + b.Re*a.Im;
    OperatorOut(a, b, '*');
    Result(c);
}

void Div(Complex a, Complex b)
{
    Complex c;
    c.Re = (a.Re*b.Re + a.Im*b.Im) / (b.Re*b.Re+b.Im*b.Im);
    c.Im = (a.Im*b.Re-a.Re*b.Im) / (b.Re*b.Re+b.Im*b.Im);
    OperatorOut(a, b, '/');
    Result(c);
}

int main()
{
    Complex a, b;
    scanf("%lf %lf %lf %lf", &a.Re, &a.Im, &b.Re, &b.Im);
    Add(a, b);
    Sub(a, b);
    Mult(a, b);
    Div(a, b);
    return 0;
}