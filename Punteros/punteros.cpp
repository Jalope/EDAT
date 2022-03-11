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

    int * punt2 = &j; 

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
   
    intPtr punt2 = &x;  // es lo mismo que: int * punt2 = &x; 

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