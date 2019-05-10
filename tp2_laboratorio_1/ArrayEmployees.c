#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int i;

    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }
        result=0;
    }

    return result;
}

int addEmployee(Employee* list, int len, Sector* listSector, int lenSector) // int idEmployee, char name[51],char lastName[51],float salary,int sector);
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int emptyIndex;
    int flagIndex=0; // para saber si se encontró un índice libre
    Employee aux; // para guardar los datos ingresados

    // primero busco un lugar libre:
    if((findEmptyIndex(list,len,&emptyIndex))==0)
    {
        flagIndex=1;
    }
    else
    {
        printf("\nNo hay lugares disponibles para una nueva alta\n\n");
    }

    // si encuentro un lugar libre pido los datos, los valido y los guardo
    if(flagIndex)
    {
        // solicito los datos de los campos de la estructura Employee:

        // char nombre[51]
        if(getString(aux.name,"\nIngrese el nombre: ","\nIngreso invalido\n",1,51,2)==0)
        {
            // char apellido[51]
            if(getString(aux.lastName,"\nIngrese el apellido: ","\nIngreso invalido\n",1,51,2)==0)
            {
                // float sueldo
                if(getFloat(&aux.salary,"\nIngrese el sueldo: ","\nIngreso invalido\n",0,300000,2)==0)
                {
                    // int sector
                    printSector(listSector, lenSector);
                    if(getInt(&aux.sector,"\nIngrese el sector: ","\nIngreso invalido\n",1,5,2)==0)
                    {
                        // int idEmployee
                        aux.idEmployee=emptyIndex;

                        // int isEmpty
                        aux.isEmpty=0; // ya no está más vacío

                        // si está todo bien, asigno los datos:
                        list[emptyIndex]=aux;

                        result=0;
                    }
                }
            }
        }
    }

    return result;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int result=-1; // devuelve -1 si hay error y el índice libre si está todo ok



    return result;
}

int removeEmployee(Employee* list, int len, int id)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok



    return result;
}

int sortEmployees(Employee* list, int len, int order)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok



    return result;
}

int printEmployees(Employee* list, int length)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int i;

    for(i=0;i<length;i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("\n\tid \tNombre \tApellido \tSueldo \tSector \n");
            printf("\n\t%d \t%s \t%s \t%.2f \t%d\n\n",list[i].idEmployee,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }

    return result;
}

int findEmptyIndex(Employee* list, int length, int* index)
{
    int result=-1;
    int i;

    for(i=0;i<length;i++)
    {
        if(list[i].isEmpty==1)
        {
            *index=i;
            result=0;
            break;
        }
    }

    return result;
}

// 2. Modificar (ingresando id, modificar: nombre, apellido, salario, sector)
int modifyEmployee(Employee* list, int length)
{
    int result=-1;
    int idEmpleadoBuscado;
    int botonModificar=0;

    // solicito el id del empleado a modificar


    do{
        system("cls");

        printf("*** MENU MODIFICAR - ABM EMPLEADOS ***\n\n");
        printf("1. Nombre\n");
        printf("2. Apellido\n");
        printf("3. Salario\n");
        printf("4. Sector\n");
        printf("5. Volver al menu principal\n\n");

        printf("Seleccione una opcion del menu: ");
        scanf("%d",&botonModificar);

        switch(botonModificar)
        {
            case 1: // nombre[51]
                system("pause");
                break;

            case 2: // apellido[]51
                system("pause");
                break;

            case 3: // float salario
                system("pause");
                break;

            case 4: // sector
                system("pause");
                break;

            case 5: // salir
                break;

            default:
                printf("\nOpcion invalida\n\n");
                system("pause");
        }
    }while(botonModificar!=5);

    return result;

}

int printSector(Sector* list, int length) // int idSector, char description[20]
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int i;

    printf("\n\tid \tSector \n");

    for(i=0;i<length;i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("\n\t%d \t%s\n", list[i].idSector, list[i].description);
            result=0;
        }
    }

    return result;
}
