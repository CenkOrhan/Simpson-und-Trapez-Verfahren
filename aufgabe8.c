//
// Created by Cenk Orhan on 24.11.22.
//
#include <stdio.h>
#include <math.h>
#include "ausgabe.h"
#include <limits.h>



double funktion(double x);
double trapez(double (*funktion)(double ), double a, double b, double eps, int index, int print);
double simpson(double (*funktion)(double ), double a, double b, double eps);
double gausL4(double(*funktion)(double ), double a, double b);
double gausL5(double(*funktion)(double ), double a, double b);

int main()
{
    double const a = 0.0;
    double const b = 1.0;
    double eps = 1e-12;
    trapez(funktion,a,b,eps, INT_MAX,1);

    printf("-----------------------------------------------------------------------------\n");
    printf("die exakte Lösung ist:\n\t%.15f\n",(M_E-2)/2);
    printf("-----------------------------------------------------------------------------\n");
    simpson(funktion,a,b,eps);
    printf("-----------------------------------------------------------------------------\n");
    printf("die exakte Lösung ist:\n\t%.15f\n",(M_E-2)/2);
    printf("-----------------------------------------------------------------------------\n\n");
    printf("Ausgabe für Gauß-Legendre-Quadratur: \n\n");
    double ergebnis_fuer_4 =  gausL4(funktion, a, b);
    double ergebnis_fuer_5  =  gausL5(funktion, a, b);
    ausgabe_gaussLegendre(4, ergebnis_fuer_4);
    ausgabe_gaussLegendre(5, ergebnis_fuer_5);

}


double funktion(double x)
{
    return (x*pow(exp(1.0),x))/pow((x+1.0),2.0);
}


double trapez(double (*funktion)(double ), double a, double b, double eps, int index, int print) {

    double h;
    double t[2];
    t[0] = 0;
    t[1] = 0;
    double s;
    int i = 0;
    int n = 1;

    h = b - a;
    s = (0.5 * funktion(a)) + (0.5 * funktion(b));

    do{

        t[0] = t[1];
        h /=2;
        for (int j = 1; j <= n; ++j)
        {
            s += funktion(a + ((2 * j) - 1) * h);
        }
        t[1]= s*h;
        n *=2;
        if(print == 1){
            ausgabe('t',i+1,t[1]);}
        if(i == index)break;
        i++;
    }while(fabs(t[1] - t[0]) > fabs(t[1]) * eps + eps);

    return t[1];
}


double simpson(double (*funktion)(double ), double a, double b, double e)
{

    double s[2];
    s[0] = 0;
    s[1] = 1;

    int i = 0;

    do{
        s[0] = s[1];
        s[1] = (4*trapez(funktion,a,b,e, i+1,0) -trapez(funktion,a,b,e, i,0))/3;

        if(i == 0)
        {
            printf("s( 1) = 0.357516745919146\n");
        }
        ausgabe('s', i+2, s[1] );
        i++;
    }while(fabs(s[1] - s[0]) > fabs(s[1]) * e + e);
    return 0;

}

double gausL4(double(*funktion)(double ), double a, double b)
{


    static const double x[] = {
            3.39981043584856264792e-01,    8.61136311594052575248e-01
    };

    static const double A[] = {
            6.52145154862546142644e-01,    3.47854845137453857383e-01
    };

    double integral, dum;

    double c = 0.5 * (b - a);
    double d = 0.5 * (b + a);

    dum = c * x[1];
    integral = A[1] * ((*funktion)(d - dum) + (*funktion)(d + dum));
    dum = c * x[0];
    integral += A[0] * ((*funktion)(d - dum) + (*funktion)(d + dum));

    return c * integral;

}


double gausL5(double(*funktion)(double ), double a, double b)
{


    static const double x[] = {
            0.00000000000000000000e+00,    5.38469310105683091018e-01,
            9.06179845938663992811e-01
    };

    static const double A[] = {
            5.68888888888888888883e-01,    4.78628670499366468030e-01,
            2.36926885056189087515e-01
    };

    double integral, dum;

    double c = 0.5 * (b - a);
    double d = 0.5 * (b + a);

    dum = c * x[2];
    integral = A[2] * ((*funktion)(d - dum) + (*funktion)(d + dum));
    dum = c * x[1];
    integral += A[1] * ((*funktion)(d - dum) + (*funktion)(d + dum));
    integral += A[0] * (*funktion)(d);

    return c * integral;

}



