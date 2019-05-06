#include <stdio.h>
#include <stdlib.h>
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

int addEmployee(Employee* list, int len) //, int id, char name[],char lastName[],float salary,int sector)
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

    // si encuentro un lugar libre pido los datos, los valido y los guardo
    if(flagIndex)
    {
        // asigno los datos a los 6 campos de la estructura Employee:

        // 1. id
        aux.id=emptyIndex;

        // 2. nombre
        getString(aux.name,"\nIngrese el nombre: \n","\nIngreso invalido\n",1,51,2);

        // 3. apellido
        getString(aux.lastName,"\nIngrese el apellido: \n","\nIngreso invalido\n",1,51,2);

        // 4. sueldo
        getFloat(&aux.salary,"\nIngrese el sueldo: \n","\nIngreso invalido\n",0,300000,2);

        // 5. sector
        getInt(&aux.sector,"\nIngrese el sector: \n","\nIngreso invalido\n",0,10,2);

        // 6. campo isEmpty
        aux.isEmpty=0; // ya no está más vacío

        // si está todo bien, asigno los datos:
        list[emptyIndex]=aux;

        result=0;
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
            printf("\n\t%d \t%s \t%s \t%.2f \t%d\n\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
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
