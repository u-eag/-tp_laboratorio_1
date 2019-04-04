#include <stdio.h>
#include <stdlib.h>
#include "bibi.h"

int main()
{
    int boton;

    // botón 1:
    int operando1;
    int flagBotonUno = 0; // para saber si se ingresó el primer operando

    // botón 2:
    int operando2;
    int flagBotonDos = 0; // para saber si se ingresó el segundo operando

    // botón 3:
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoMultiplicacion;
    int resultadoFactorialUno;
    int resultadoFactorialDos;

    int flagDivision = 0; // para saber si se intenta dividir por cero
    int flagBotonTres = 0; // para saber si se calcularon las operaciones

    // botón 5:
    int flagSalir = 1; // para mostrar los botones de la calculadora hasta que el usuario quiera

    do {
        printf("Seleccione un boton de la calculadora:\n");
        if (flagBotonUno) {
            printf("1. Ingresar primer operando (A=%d)\n", operando1);
        } else {
            printf("1. Ingresar primer operando (A=x)\n");
        }
        if (flagBotonDos) {
            printf("2. Ingresar segundo operando (B=%d)\n", operando2);
        } else {
            printf("2. Ingresar segundo operando (B=y)\n");
        }
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");
        scanf("%d", &boton);
        printf("\n");

        switch (boton) {

            case 1:
            // 1) Solicito el ingreso del primer operando:
                printf("Ingrese un numero entero como primer operando (A): ");
                scanf("%d",&operando1);
                printf("\nEl operando ingresado es: %d\n\n", operando1);
                flagBotonUno = 1;
                break;

            case 2:
            // 1) Solicito el ingreso del segundo operando:
                printf("Ingrese un numero entero como segundo operando (B): ");
                scanf("%d",&operando2);
                printf("\nEl operando ingresado es: %d\n\n", operando2);
                flagBotonDos = 1;
                break;

            case 3:
                if (flagBotonUno && flagBotonDos) {
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

                    flagBotonTres = 1;
                    printf("Las operaciones fueron calculadas.\n\n");
                } else {
                    printf("No es posible calcular las operaciones. Revise los operandos ingresados.\n\n");
                }
                break;

            case 4:
                if (flagBotonTres) {
                // 4-a) informo el resultado de la suma:
                    printf("El resultado de %d+%d es: %d\n", operando1, operando2, resultadoSuma);

                // 4-b) informo el resultado de la resta:
                    printf("El resultado de %d-%d es: %d\n", operando1, operando2, resultadoResta);

                // 4-c) informo el resultado de la división:
                    if (flagDivision) {
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
                        printf(" y El factorial de %d es: inexistente\n", operando2);
                    } else {
                        printf(" y El factorial de %d es: %d\n\n", operando2, resultadoFactorialDos);
                    }
                } else {
                    printf("No es posible mostrar los resultados. Revise los botones 1 a 3.\n\n");
                }
                break;

            case 5:
            // 5) salir de la calculadora
                flagSalir = 0;
                break;

            default:
            // al seleccionar un botón inválido
            printf("Boton invalido.\n\n");
        }
    } while (flagSalir);

    return 0;
}
