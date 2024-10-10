#include <cmath>
#include <cstdio>

double f(double x) {
    //return pow(4 * x, 3) + 7 * x + 3;
    return x + pow(exp(1), x);
};

void line() {
    printf("+---------+----------+----------+----------+----------+----------+----------+---------------+\n");
}

void display(int iterasi, double a, double b, double x, double galat) {
    printf("|%9d|%10.5f|%10.5f|%10.5f|%10.5f|%10.5f|%10.5f|%15.10f|\n", 
        iterasi, a, b, x, f(a), f(b), f(x), galat);
    line();
}

void header() {
    line();
    printf("|%9s|%10s|%10s|%10s|%10s|%10s|%10s|%15s|\n",
        "Iterasi ", "a    ", "b    ", "x    ", "f(a)   ", "f(b)   ", "f(x)   ", "Galat          ");
    line();
}

void bisection(double a, double b, int max) {
    double x = (a + b) / 2;
    double galat = b - a;
    printf("BISECTION\n");
    header();
    for (int i = 0; i < max; i++)
    {
        display(i+1, a, b, x, galat);

        a = f(a) * f(x) < 0 ? a : x;
        b = f(a) * f(x) < 0 ? x : b;
        x = (a + b) / 2;
        galat = b - a;
    }
    printf("x = %.5f\n", x);
}

void regulaFalsi(double a, double b, int max) {
    double x = b - (f(b) * ((b - a)/(f(b) - f(a))));
    double x1 = x;
    double galat = (x1 - x) / x;
    printf("REGULA FALSI\n");
    header();
    for (int i = 0; i < max; i++)
    {
        display(i + 1, a, b, x, galat);

        x1 = x;
        a = f(a) * f(x) < 0 ? a : x;
        b = f(b) * f(x) < 0 ? b : x;
        x = b - (f(b) * ((b - a)/(f(b) - f(a))));
        galat = (x1 - x) / x;
    }
    printf("x = %.5f\n", x);
}

int main() {
    //bisection(-0.5, 0, 17);
    bisection(-1, 0, 20);

    printf("\n\n");

    //regulaFalsi(-0.5, 0, 15);
    regulaFalsi(-1, 0, 7);

    system("pause");

    return 0;
}