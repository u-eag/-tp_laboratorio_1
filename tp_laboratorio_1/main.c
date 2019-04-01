#include <stdio.h>
#include <stdlib.h>
#include "bibi.h"

int main()
{
    int operando1;
    int operando2;

    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoMultiplicacion;
    int resultadoFactorialUno;
    int resultadoFactorialDos;

    int flagDivision = 0; // para mostrar mensaje de error al intentar dividir por cero

    // 1-2) Solicito el ingreso de los operandos:
    printf("Ingrese el primer operando: ");
    scanf("%d",&operando1);

    printf("Ingrese el segundo operando: ");
    scanf("%d",&operando2);

    // 3-a) calculo la suma:
    resultadoSuma = suma(operando1, operando2);

    // 3-b) calculo la resta:
    resultadoResta = resta(operando1, operando2);

    // 3-c) calculo la división:
    if (operando2 == 0) {
        flagDivision = 1;
    } else {
        resultadoDivision = division(operando1, operando2);
    }

    // 3-d) calculo la multiplicación:
    resultadoMultiplicacion = multiplicacion(operando1, operando2);

    // 3-e) calculo los factoriales:
    resultadoFactorialUno = factorial(operando1);
    resultadoFactorialDos = factorial(operando2);

    // 4-a) informo el resultado de la suma:
    printf("\nEl resultado de %d+%d es: %d\n", operando1, operando2, resultadoSuma);

    // 4-b) informo el resultado de la resta:
    printf("El resultado de %d-%d es: %d\n", operando1, operando2, resultadoResta);

    // 4-c) informo el resultado de la división:
    if (flagDivision == 1) {
        printf("No es posible dividir por cero\n");
    } else {
        printf("El resultado de %d/%d es: %.2f\n", operando1, operando2, resultadoDivision);
    }

    // 4-d) informo el resultado de la multiplicación:
    printf("El resultado de %d*%d es: %d\n", operando1, operando2, resultadoMultiplicacion);

    // 4-e) informo el resultado de los factoriales:
    if (resultadoFactorialUno == -1) {
        printf("El factorial de %d es: inexistente", operando1);
    } else {
        printf("El factorial de %d es: %d", operando1, resultadoFactorialUno);
    }

    if (resultadoFactorialDos == -1) {
        printf(" y el factorial de %d es: inexistente\n", operando2);
    } else {
        printf(" y el factorial de %d es: %d\n", operando2, resultadoFactorialDos);
    }

    return 0;
}
