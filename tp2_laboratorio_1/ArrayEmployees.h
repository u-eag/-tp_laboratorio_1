#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct
{
    int idEmployee;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

typedef struct
{
    int idSector;
    int isEmpty;
    char description[20];
}Sector;

#endif // EMPLOYEE_H_INCLUDED

/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE(1) in all
 *          position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
 *         in the first empty position
 * \param list Employee* Pointer to array of employees
 * \param len int Array Employee length
 * \param listSector Array Sector* Pointer to array of sectors
 * \param lenSector Array Sector length
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, Sector* listSector, int lenSector);

/** \brief find an Employee by Id en returns the index position in array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Id of the employee to be found
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 0)
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int Id of the employee to be removed
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* list, int length);

/** \brief  To find an empty position in the array of employees
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int findEmptyIndex(Employee* list, int length, int* index);

/** \brief  To change an employee data (name, last name, salary, sector)
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int modifyEmployee(Employee* list, int length, Sector* listSector, int lengthSector);

/** \brief  To show the existing sectors by id and description
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printSector(Sector* list, int length);

/** \brief  To indicate if at least on position in the array is not empty (0)
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int revisarExistanAltas(Employee* list, int length);

/** \brief  To show an ordered list of employees (by last name and sector),
 *          and the average salary
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informarOrdenarPromediar(Employee* list, int length);

/** \brief  To calculate the total amount of salaries,
 *          the total quantity of employees and
 *          the average salary between them
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int promediarSalarios(Employee* list, int length);
