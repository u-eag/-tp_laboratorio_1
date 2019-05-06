#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "ArrayEmployees.h"

#define QTY_EMP 1 // cantidad máxima de empleados
            // 1000

int main()
{
    Employee arrayEmpleados[QTY_EMP];

    // varibales para guardar el retorno de las funciones:
    int r_initEmployees; // guarda el retorno de la inicialización: [-1] indica error y [0] ok
    int r_addEmployee;
/*    int r_findEmployeeById;
    int r_removeEmployee;
    int r_sortEmployees;
    int r_printEmployees;*/

    int botonMenu=0; // indica el botón seleccionado del menu principal

    // boton 1:
    int flagBotonUno; // para saber si se realizó un alta

    r_initEmployees=initEmployees(arrayEmpleados,QTY_EMP); // inicializa el array y guarda el return de la funcion

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
                r_addEmployee=addEmployee(arrayEmpleados,QTY_EMP);

                if(r_initEmployees==0 && r_addEmployee==0)
                {
                    printf("\nEmpleado ingresado exitosamente\n\n");
                    flagBotonUno=1;
                }
                else
                {
                    printf("\nNo hay lugar en el sistema\n\n");
                }

                system("pause");
                break;

            case 2: // 2. Modificar
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
