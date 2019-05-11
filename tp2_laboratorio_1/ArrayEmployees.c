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
    int emptyIndex; // guarda el indice vario encontrado y es donde se asentaran los datos del alta
    int flagIndex=0; // para saber si se encontró un índice libre
    Employee aux; // para guardar provisoriamente los datos ingresados

    // primero busco un lugar libre:
    if(list!=NULL && len>0 && (findEmptyIndex(list,len,&emptyIndex))==0)
    {
        flagIndex=1;
    }
    else
    {
        printf("\nNo hay lugares disponibles para una nueva alta\n\n");
    }

    // si encuentro un lugar libre: pido los datos, los valido y los guardo
    if(flagIndex)
    {
        // solicito los datos de los campos de la estructura Employee:

        // char nombre[51]
        if(getString(aux.name,"\nIngrese el nombre: ","\nIngreso invalido",1,51,2)==0)
        {
            // char apellido[51]
            if(getString(aux.lastName,"\nIngrese el apellido: ","\nIngreso invalido\n",1,51,2)==0)
            {
                // float sueldo
                if(getFloat(&aux.salary,"\nIngrese el sueldo: ","\nIngreso invalido\n",0,3000000,2)==0)
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
    int index=-1; // devuelve -1 si hay error y el índice del empleado buscado si está todo ok
    int i;

    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].idEmployee == id)
            {
                index=id;
                break;
            }
        }
    }

    return index;
}

int removeEmployee(Employee* list, int len, int id)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok

    // busco al empleado por id:
    if(list!=NULL && len>0 && list[id].isEmpty==0 && findEmployeeById(list, len, id)==0)
    {
        // si lo encuentro lo doy de baja (lógica)
        list[id].isEmpty = 1; // 1 es vacío, 0 es que está ocupado
        printf("\nSe proceso exitosamente la baja de %s %s\n\n", list[id].name, list[id].lastName);
        result=0;
    }
    else
    {
        printf("\nNo se procesó exitosamente la baja de %s %s\n\n", list[id].name, list[id].lastName);
    }

    return result;
}

int sortEmployees(Employee* list, int len, int order) // ordenados alfabéticamente por Apellido y Sector
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    Employee aux;
    int i;
    int j;

    if (list!=NULL && len>0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(list[i].sector > list[j].sector)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }

        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(strcmp(list[i].lastName, list[j].lastName)>0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
        result=0;
    }

    return result;
}

int printEmployees(Employee* list, int length)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int i;

    printf("\n\tid    \tNombre    \tApellido    \tSueldo    \tSector \n");

    if(list!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(list[i].isEmpty==0)
            {
                printf("\n\t%d    \t%s    \t%s    \t%.2f    \t%d\n\n", list[i].idEmployee, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            }
        }
        result=0;
    }

    return result;
}

int findEmptyIndex(Employee* list, int length, int* index)
{
    int result=-1;
    int i;

    if(list!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(list[i].isEmpty==1)
            {
                *index=i;
                result=0;
                break;
            }
        }
    }

    return result;
}

// 2. Modificar (ingresando id, modificar: nombre, apellido, salario, sector)
int modifyEmployee(Employee* list, int length, Sector* listSector, int lengthSector)
{
    int result=-1;
    int idEmpleadoBuscado;
    int i;
    int indiceEmpleadoEncontrado;
    int flagEmpleadoEncontrado=0; // para indicar que se encontró al empleado buscado
    int idSectorEncontrado; // para mostrar la descripcion correspondiente al numero de sector del empleado
    int botonModificar=0; // para elegir una opcion del menu modificar
    Employee aux;

    // solicito el id del empleado a modificar:
    getInt(&idEmpleadoBuscado, "\nIngrese el id del empleado a modificar: ", "\nIngreso invalido\n\n", 0, 1000, 2);

    // chequeo que ese id pertenezca a un empleado existente:
    if(list!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(list[i].isEmpty == 0 && list[i].idEmployee == idEmpleadoBuscado)
            {
                indiceEmpleadoEncontrado = i;
                flagEmpleadoEncontrado = 1;
                idSectorEncontrado = list[i].sector-1; // porque el array arranca en 0 pero los sectores en 1
                break;
            }
            else
            {
                printf("\nEl id ingresado no pertenece a ningun empleado\n\n");
            }
        }
    }

    if(flagEmpleadoEncontrado)
    {
        do{
            fflush(stdin);
            system("cls");

            printf("*** MENU MODIFICAR - EMPLEADO ID: %d ***\n\n", list[indiceEmpleadoEncontrado].idEmployee);
            printf("\tNombre    \tApellido    \tSalario    \tSector    \tDescripcion\n\n");
            printf("\t%s    \t%s    \t%.2f    \t%d       \t%s\n\n", list[indiceEmpleadoEncontrado].name, list[indiceEmpleadoEncontrado].lastName,
                   list[indiceEmpleadoEncontrado].salary, list[indiceEmpleadoEncontrado].sector,
                   listSector[idSectorEncontrado].description);
            printf("1. Nombre\n");
            printf("2. Apellido\n");
            printf("3. Salario\n");
            printf("4. Sector\n");
            printf("5. Volver al menu principal\n\n");

            printf("Seleccione el campo a modificar: ");
            scanf("%d",&botonModificar);

            switch(botonModificar)
            {
                case 1: // nombre[51]
                    if(getString(aux.name, "\nIngrese nuevo nombre: ", "\nIngreso invalido \n\n", 1, 51, 2)==0)
                    {
                        strcpy(list[indiceEmpleadoEncontrado].name, aux.name);
                        printf("\nEl nombre modificado exitosamente\n\n");
                        result=0;
                    }
                    else
                    {
                        printf("\nEl nombre no pudo modificarse\n\n");
                    }
                    system("pause");
                    break;

                case 2: // apellido[]51
                    if(getString(aux.lastName, "\nIngrese nuevo apellido: ", "\nIngreso invalido \n\n", 1, 51, 2)==0)
                    {
                        strcpy(list[indiceEmpleadoEncontrado].lastName, aux.lastName);
                        printf("El apellido fue modificado exitosamente\n\n");
                        result=0;
                    }
                    else
                    {
                        printf("El apellido no pudo modificarse\n\n");
                    }
                    system("pause");
                    break;

                case 3: // float salario
                    if(getFloat(&aux.salary, "\nIngrese nuevo salario: ", "\nIngreso invalido \n\n", 0, 3000000, 2)==0)
                    {
                        list[indiceEmpleadoEncontrado].salary = aux.salary;
                        printf("El salario fue modificado exitosamente\n\n");
                        result=0;
                    }
                    else
                    {
                        printf("El salario no pudo modificarse\n\n");
                    }
                    system("pause");
                    break;

                case 4: // sector
                    printSector(listSector, 5);
                    if(getInt(&aux.sector, "\nIngrese nuevo sector: ", "\nIngreso invalido \n\n", 1, 5, 2)==0)
                    {
                        list[indiceEmpleadoEncontrado].sector = aux.sector;
                        printf("El sector fue modificado exitosamente\n\n");
                        result=0;
                    }
                    else
                    {
                        printf("El sector no pudo modificarse\n\n");
                    }
                    system("pause");
                    break;

                case 5: // salir
                    break;

                default:
                    printf("\nOpcion invalida\n\n");
                    system("pause");
            }
        }while(botonModificar!=5);

    }

    return result;

}

int printSector(Sector* list, int length) // int idSector, char description[20]
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int i;

    if(list!=NULL && length>0)
    {
        printf("\n\tid \tSector \n");

        for(i=0;i<length;i++)
        {
            if(list[i].isEmpty==0)
            {
                printf("\n\t%d \t%s\n", list[i].idSector, list[i].description);
            }
        }
        result=0;
    }

    return result;
}

int revisarExistanAltas(Employee* list, int length)
{
    int result=-1; // devuelve -1 si el array de empleados está vacío y 1 si existe aunque sea un empleado dado de alta
    int i;

    if(list!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(list[i].isEmpty == 0)
            {
                result=0;
                break;
            }
        }
    }

    return result;
}

int informarOrdenarPromediar(Employee* list, int length)
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int botonInformar=0;

    if(list!=NULL && length>0)
    {
        do{
            fflush(stdin);
            system("cls");

            printf("*** MENU INFORMAR - ABM EMPLEADOS ***\n\n");
            printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n");
            printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n");
            printf("3. Volver al menu principal\n\n");

            printf("Seleccione una opcion del menu: ");
            scanf("%d",&botonInformar);

            switch(botonInformar)
            {
                case 1: // Listado de los empleados ordenados alfabéticamente por Apellido y Sector
                    sortEmployees(list, length, 1); // order: [1]=ascendente y [0]=descendente
                    printEmployees(list, length);
                    result=0;
                    system("pause");
                    break;

                case 2: // Total y promedio de los salarios, y cuántos empleados superan el salario promedio
                    promediarSalarios(list, length);
                    result=0;
                    system("pause");
                    break;

                case 3: // salir
                    break;

                default:
                    printf("\nOpcion invalida\n\n");
                    system("pause");
                }
            }while(botonInformar!=3);
    }
        return result;
}

int promediarSalarios(Employee* list, int length) // Total y promedio de los salarios, y cuántos empleados superan el salario promedio
{
    int result=-1; // devuelve -1 si hay error y 0 si está todo ok
    int contadorSalarios=0; // para saber cuántos salarios hay ingresados
    float acumuladorSalarios=0; // para sumar todos los salarios ingresados
    int i;
    float promedioSalarios;
    int contadorSalariosPorEncimaDelPromedio=0;

    if(list!=NULL && length>0)
        {
        for(i=0;i<length;i++)
        {
            if(list[i].isEmpty==0)
            {
                contadorSalarios++;
                acumuladorSalarios=acumuladorSalarios + list[i].salary;
            }
        }

        if(contadorSalarios != 0)
        {
            promedioSalarios = acumuladorSalarios / (float)contadorSalarios;

            for(i=0;i<length;i++)
            {
                if(list[i].isEmpty==0 && list[i].salary > promedioSalarios)
                {
                    contadorSalariosPorEncimaDelPromedio++;
                }
            }

            printf("\nEl total de los salarios es: $%.2f\n", acumuladorSalarios);
            printf("\nEl salario promedio es: $%.2f\n", promedioSalarios);
            printf("\nLa cantidad de empleados que superan el salario promedio es de: %d\n\n", contadorSalariosPorEncimaDelPromedio);

            result=0;
        }
    }

    return result;
}
