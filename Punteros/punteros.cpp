#include <iostream>

using namespace std; 

int main(){
    //int * punt = nullptr; // punt inicialmente está indefinida, 
                // contiene una dirección que n
                // no es válida, por eso la asignamos 
                // a nullptr

    int i; 

    cout << &i << endl; // Muestra la dirección de memoria de i

    int j = 5; 
    int * punt = nullptr; 
    punt = &j; 

    int * punt22 = &j; 

    int var; 
    // int * punteroI = nullptr;
    int * punteroI = &var; 
    var = 5; 

    cout << "La variable de nombre var está almacenada en: " << &var << "Podemos llamar a su valor directamente: " << var << "o podemos hacer una llamada a la variable que apunta a su dirección de memoría: " << *punteroI << endl; 

    cout << "La variable j tiene como valor " << j<< " y su dirección de memoria es: " << &j << endl;

    /*DIRECCIONAMIENTO INDIRECTO:
    También podemos hacer esta misma impresión llamando al valor de j 
    desde su puntero con el operador "*"  */

    cout << "La variable j tiene como valor " << *punt << " y su dirección de memoria es: " << &j << endl;

    int x = 5;
    int * punt1 = nullptr; // punt1 apunta a nada
    int * punt2 = &x; // punt2 apunta a la variable x
    punt1 = punt2; // ambos apuntan a la variable x
    *punt1 = 8; // *punt1, *punt2 y x son la misma variable

    /* Podemos crear una definición de tipo que engloble a todos los punteros de tipo entero por ejemplo o todos los de tipo char.  
    */
    typedef int * intPtr; //intPtr son punteros a   enteros
   
    intPtr punt21 = &x;  // es lo mismo que: int * punt2 = &x; 

    typedef double * doublePtr; 

    double var_double = 2.7;
    doublePtr punt_double = &var_double;

    struct coche // Los struct ya no hace falta que tenga la palabra typedeff delante.
    {
        int matricula;
        string color; 
        int pid; 
    };

    coche tesla; 
    tesla.matricula = 12345;
    tesla.color = "Rojo";
    tesla.pid = 01;

    coche * puntero_coche = &tesla; 

    cout << "Mi coche tiene matricula: " << puntero_coche -> matricula << " y es de color: " << puntero_coche -> color << endl; 
     


    


    typedef struct tRegistro
    {
        int codigo; 
        string nombre; 
        double sueldo; 
    };

    tRegistro registro;
    registro.codigo = 123;
    registro.nombre = "Juan";
    registro.sueldo = 2543;

    tRegistro * punteror = &registro;
    
    //Para acceder: 
    punteror -> codigo; // equiv (*puntero).codigo
    punteror -> nombre; // equiv (*puntero).nombre
    punteror -> sueldo; // equiv (*puntero).sueldo 
}