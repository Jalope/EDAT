#include <iostream>

using namespace std; 

int main(){

    int * p; // Todavía sin una dirección válida
    p = new int; // Ya tiene una dirección válida
    *p = 12; //asignamos valor

    int * valor = new int; 
    *valor = 17; 

    //Para borrar y devolver al monton la memoria utilizada. Esto se hace por ejemplo después de imprimir sus valores.  

    delete p; 
    p = nullptr; 

    delete valor; 
    valor = nullptr; 
}

