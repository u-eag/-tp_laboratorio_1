#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "ArrayEmployees.h"

#define QTY_EMP 1 // cantidad máxima de empleados
            // 1000

int main()
{
    Employee arrayEmpleados[QTY_EMP];

    Sector arraySectores[5] =
    {
        {1, 0, "Sistemas"},
        {2, 0, "RRHH"},
        {3, 0, "Compras"},
        {4, 0, "Ventas"},
        {5, 0, "Legales"},
    };

    int botonMenu=0; // indica el botón seleccionado del menu principal

    // boton 1:
    int flagBotonUno; // para saber si se realizó aunque sea un alta

    initEmployees(arrayEmpleados,QTY_EMP); // inicializa el array de empleados

    do{
        system("cls");

        printf("*** MENU PRINCIPAL - ABM EMPLEADOS ***\n\n");
        printf("1. Alta\n");
        printf("2. Modificar\n");
        printf("3. Baja\n");
        printf("4. Informar\n");
        printf("5. Salir\n\n");

        printf("Seleccione una opcion del menu: ");
        scanf("%d",&botonMenu);

        switch(botonMenu)
        {
            case 1: // 1. Alta
                if(addEmployee(arrayEmpleados, QTY_EMP, arraySectores, 5)==0)
                {
                    flagBotonUno=1;
                    printf("\nEl alta se ingreso exitosamente\n\n");
                }
                else
                {
                    printf("\nEl alta no pudo procesarse\n\n");
                }
                system("pause");
                break;

            case 2: // 2. Modificar (ingresando id, modificar: nombre, apellido, salario, sector)
                if(flagBotonUno)
                {

                }
                system("pause");
                break;

            case 3: // 3. Baja
                system("pause");
                break;

            case 4: // 4. Informar
                if(flagBotonUno)
                {
                    printEmployees(arrayEmpleados,QTY_EMP);
                }
                system("pause");
                break;

            case 5: // salir
                break;

            default:
                printf("\nOpcion invalida\n\n");
                system("pause");
        }

    }while(botonMenu!=5);

    return 0;
}
