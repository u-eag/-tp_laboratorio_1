#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit, int tries)
{
    int result=-1; // si obtuvo el número devuelve [0] si no [-1]
    int aux; // almacena temporalmente el numero ingresado

    do{
        tries--;

        printf("%s",message);
        scanf("%d",&aux);

        if(aux>=lowLimit && aux<=hiLimit)
        {
            *input=aux; // si el número ingresado cumple los requisitos se lo carga en la variable pasada por parámetro
            result=0;
        }
        else
        {
            printf("%s",eMessage);
        }
    }while(result!=0 && tries>0);

    return result;
}

int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit, int tries)
{
    int result=-1; // si obtuvo el número devuelve [0] si no [-1]
    float aux;

    do{
        tries--;

        printf("%s",message);
        scanf("%f",&aux);

        if(aux>=lowLimit && aux<=hiLimit)
        {
            *input=aux;
            result=0;
        }
        else
        {
            printf("%s",eMessage);
        }
    }while(result!=0 && tries>0);

    return result;
}

int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit, int tries)
{
    int result=-1; // si obtuvo el caracter [0] si no [-1]
    char aux;

    do{
        tries--;

        printf("%s",message);
        fflush(stdin); // fpurge(stdin) para Linux y OSx
        scanf("%c",&aux);

        if(aux>=lowLimit && aux<=hiLimit)
        {
            *input=aux;
            result=0;
        }
        else
        {
            printf("%s",eMessage);
        }

    }while(result!=0 && tries>0);

    return result;
}

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit, int tries)
{
    int result=-1; // si obtuvo la cadena [0] si no [-1]
    char aux[hiLimit];
    int length; // para saber cuánto mide la cadena ingresada

    do{
        tries--;

        printf("%s",message);
        fflush(stdin); //fpurge(stdin) para Linux y OSx
        gets(aux);

        length=strlen(aux);

        if(length>=lowLimit && length<=hiLimit)
        {
            strcpy(input,aux);
            result=0;
        }
        else
        {
            printf("%s",eMessage);
        }
    }while(result!=0 && tries>0);

    return result;
}


