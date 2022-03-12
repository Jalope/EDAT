#include <iostream>

using namespace std; 

int main(){
    typedef char tCadena[81]; 
    struct tRegistro; 
    {
        int codigo; 
        tCadena nombre; 
        double valor; 
    };
    
    // Array de punteros a registros:

    const int TM = 12; //tamaño fijo del array

    struct tLista;
    {
        /* Lista con variables dinámicas */
        tRegistro * registro[TM];
        int cont; 
    };

    //Metodos
    void iniciar(tLista & lista);
    
    void mostrar(const tLista & lista);
    
    bool insertar(tLista & lista, const tRegistro & registro);
    
    bool eliminar(tLista & lista, int code);
    
    bool buscar(const tLista & lista, int code, int & pos); 
    
    bool cargar(tLista & lista); 

    void guardar(const tLista & lista);

    void destruir(tLista & lista);    
}

#ifndef LISTADD_H
#define LISTADD_H

void iniciar(tLista & lista){
    lista.cont = 0;
    for (int c = 0; c <TM; c++)
        lista.registros[lista.cont] = new tRegistro;
}

void mostrar(const tLista & lista){
    cout << endl << "Elementos de la lista: " << endl << "---------------------" << endl; 

    for (int i = 0; i < lista.cont; i++)
        mostrar(*(lista.registros[i]));
}

bool insertar(tLista & lista, const tRegistro & registro){
    bool ok = true; 
    if (lista.cont == TM)
        ok = false; 
    else{
        *(lista.registros[lista.cont]) = registro; 
    }
    return ok; 
}

bool eliminar(tLista & lista, int code){
    int pos; bool ok = true; 
    if (buscar(lista, code, pos)){
        delete lista.registros[pos]; 
        desplazarIzq(lista, pos); 
        lista.cont--; 
    } else ok = false; 
    return ok;
}

void destruir(tLista & lista) {
    for (int i = 0; i < TM; i++)
        delete lista.registros[i];
    lista.cont = 0;
}

bool buscar(const tLista & lista, int code, int & pos) {
pos = 0; int ini = 0, fin = lista.cont -1, mitad;
bool encontrado = false;
while ((ini < = fin) && !encontrado) {
    mitad = (ini + fin) / 2;
    if (code < lista.registros[pos]->codigo) ini = mitad - 1;
    else if(lista.registros[pos]->codigo < code) fin = mitad+1;
    else encontrado = true;
}
if (encontrado) pos = mitad; else pos = ini;
return encontrado;
}