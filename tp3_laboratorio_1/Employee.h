#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/*
Employee* employee_new(); // maloc: construimos espacio para el sizeof de ese empleado
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id); // tip: hacer un setId que soporte un char (para todos las funcines que reciben int y float)
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
*/
#endif // employee_H_INCLUDED

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
int employee_delete();

int employee_setId(Employee* this, char* value);
int employee_getId(Employee* this,int* value);

int employee_setNombre(Employee* this,char* value);
int employee_getNombre(Employee* this,char* value);

int employee_setHorasTrabajadas(Employee* this,char* value);
int employee_getHorasTrabajadas(Employee* this,int* value);

int employee_setSueldo(Employee* this,char* value);
int employee_getSueldo(Employee* this,int* value);
