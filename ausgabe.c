#include<stdio.h>

/**
  * Methode zum Ausgeben der Approximation der Integration mit der Trapez- und Simpson-Regel.
  * 
  * @param	c		char zum Erkennen der Integration-Methode (t = Trapez, s = Simpson)
  * @param	i		gibt die Iteration an
  * @param	value	Wert der Approximation des Integrals
  */
void ausgabe(char c, int i, double value)
{
	printf("%c(%2i) = %.15f\n", c, i, value );

}

/**
  * Methode zum Ausgeben der Approximation der Integration mit der Gauss-Quadratur.
  * 
  * @param	n		gibt die Ordnung des Legendre-Polynoms an
  * @param	value	Wert der Approximation des Integrals
  */
void ausgabe_gaussLegendre(int n, double value)
{
	printf("gq(%i) = %.15f\n", n, value );

}

