#include<iostream>

using namespace std;

//typedef int elemento;

template <typename elemento>
struct nodo_pila {
       elemento dato;
       nodo_pila<elemento> * sig;
};

template <typename elemento>
struct pila{
  nodo_pila<elemento> * ultimo = NULL;
  int profundidad = 0;
};

//typedef nodo_pila* pila;
template <typename elemento>
pila<elemento> pila_vacia(){
     pila<elemento> result;
     return result;
}

template <typename elemento>
nodo_pila<elemento> * nuevo_nodo(elemento e,nodo_pila<elemento>* s){
       nodo_pila<elemento>* result = new nodo_pila<elemento>;
       result->dato = e;
       result->sig = s;
       return result;
}

template <typename elemento>
void apilar(elemento e, pila<elemento> & p){
     nodo_pila<elemento>* aux = nuevo_nodo(e,p.ultimo);
     p.ultimo = aux;
     p.profundidad++;
}

template <typename elemento>
void des_apilar(pila<elemento> & p){
     nodo_pila<elemento>* aux = p.ultimo->sig;
     delete p.ultimo;
     p.ultimo = aux;
     p.profundidad--;
}

template <typename elemento>
elemento cima(pila<elemento> p){
       return p.ultimo->dato;
}

template <typename elemento>
elemento pop(pila<elemento> & p){
     elemento result = cima(p);
     des_apilar(p);
     return result;
}

template <typename elemento>
bool es_vacia(pila<elemento> p){
     return p.profundidad == 0;
}

template <typename elemento>
void liberar(pila<elemento> & p){
     while(!es_vacia(p)){
          des_apilar(p);
     }
}

template <typename elemento>
void mostrar(pila<elemento> p){
     nodo_pila<elemento> * act= p.ultimo;
     while(act != NULL){
            //cout << act->dato << endl;
            act = act->sig;
     }
}

template <typename elemento>
int profundidad(pila<elemento> p){
   return p.profundidad;
}


/*int main(){
    pila<int> p;
    for(int i = 0; i<10;i++){
         cout << i << endl;
         apilar(i,p);
    }
    mostrar(p);
    cout << cima(p)<< endl;
    des_apilar(p);
    apilar(100,p);
    mostrar(p);
    liberar(p);
    return 0;
}*/

