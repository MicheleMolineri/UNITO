#include <stdio.h>
#include <stdlib.h>

/*
Ingresso: x̸= 0 reale, n≥0 intero.
Uscita: il reale xn
.
Si scrivano una versione ricorsiva ed una iterativa dell’algoritmo che calcola x^n sulla base delle seguenti
equazioni:
x^2k = x^k·x^k , x^2k+1 =x^k·x^k·x
Suggerimento: si basi la versione iterativa sull’invariante xn = yk·xk·x.·z, dove y,k,z sono variabili di programma.
 */

double esponenziale_veloce_rec(double x, int n)
{
    int y = 0;
    // caso base n == 0
    if (n == 0)
    {
        return 1;
    }
    //
    y = esponenziale_veloce_rec(x, n / 2);
    if (y % 2 == 0)
    {
        return y * y;
    }
    else
    {
        return y * y * x;
    }
}

double esponenziale_veloce(double x, int n)
{
    double res = 1;

    for (int i = 0; i < n; i++)
    {
        res = res * x;
    }

    return res;
}

int main()
{

    double a = 2;
    double b = 2;
    double res = 0;

    // res = esponenziale_veloce(a, b);
    res = esponenziale_veloce_rec(a, b);

    printf("il risultato di %.2f ** %.2f fa : %.2f", a, b, res);

    return 0;
}