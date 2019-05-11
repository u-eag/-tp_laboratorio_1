#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "ArrayEmployees.h"

#define QTY_EMP 1000 // cantidad máxima de empleados
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

    int idBajaLogica; // para tomar el id del empleado a dar de baja

    int r_hayAltas; // para guardar el retorno de la funcion que revisa si existe aunque sea un empleado dado de alta

    initEmployees(arrayEmpleados,QTY_EMP); // inicializa el array de empleados

    do{
        fflush(stdin);
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
                    r_hayAltas = revisarExistanAltas(arrayEmpleados, QTY_EMP);
                    printf("\nEl alta se ingreso exitosamente\n\n");
                }
                else
                {
                    printf("\nEl alta no pudo procesarse\n\n");
                }

                system("pause");
                break;

            case 2: // 2. Modificar (ingresando id, modificar: nombre, apellido, salario, sector)

                r_hayAltas = revisarExistanAltas(arrayEmpleados, QTY_EMP);

                if(r_hayAltas==0)
                {
                    modifyEmployee(arrayEmpleados, QTY_EMP, arraySectores, 5);
                }
                else
                {
                    printf("\nAntes de modificar es necesario que exista al menos un empleado dado de alta\n\n");
                }

                system("pause");
                break;

            case 3: // 3. Baja

                r_hayAltas = revisarExistanAltas(arrayEmpleados, QTY_EMP);

                if(r_hayAltas==0)
                {
                    getInt(&idBajaLogica, "\nIngrese el id del empleado a eliminar: ", "\nIngreso invalido\n\n", 0, 1000, 2);
                    removeEmployee(arrayEmpleados, QTY_EMP, idBajaLogica);
                }
                else
                {
                    printf("\nAntes de procesar una baja es necesario que exista al menos un empleado dado de alta\n\n");
                }

                system("pause");
                break;

            case 4: // 4. Informar

                r_hayAltas = revisarExistanAltas(arrayEmpleados, QTY_EMP);

                if(r_hayAltas==0)
                {
                    informarOrdenarPromediar(arrayEmpleados, QTY_EMP);
                }
                else
                {
                    printf("\nAntes de realizar informes es necesario que exista al menos un empleado dado de alta\n\n");
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
