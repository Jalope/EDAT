#include<iostream>

using namespace std;

typedef int elemento;

struct nodo_pila {
       elemento dato;
       nodo_pila * sig;
};

struct pila{
  nodo_pila * ultimo = NULL;
  int profundidad = 0;
};

//typedef nodo_pila* pila;

pila pila_vacia();
nodo_pila * nuevo_nodo(elemento e,nodo_pila* s);
void apilar(elemento e, pila & p);
void des_apilar(pila & p);
elemento cima(pila p);
bool es_vacia(pila p);
void liberar(pila p);
void mostrar(pila p);
int profundidad(pila p);


int main(){
    pila p = pila_vacia();
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
}

pila pila_vacia(){
     pila result;
     return result;
}

nodo_pila * nuevo_nodo(elemento e,nodo_pila* s){
       nodo_pila* result = new nodo_pila;
       result->dato = e;
       result->sig = s;
       return result;
}

void apilar(elemento e, pila & p){
     nodo_pila* aux = nuevo_nodo(e,p.ultimo);
     p.ultimo = aux;
     p.profundidad++;
}

void des_apilar(pila & p){
     nodo_pila* aux = p.ultimo->sig;
     delete p.ultimo;
     p.ultimo = aux;
     p.profundidad--;
}

elemento cima(pila p){
       return p.ultimo->dato;
}
bool es_vacia(pila p){
     return p.profundidad == 0;
}

void liberar(pila p){
     while(!es_vacia(p)){
          des_apilar(p);
     }
}

void mostrar(pila p){
     nodo_pila * act= p.ultimo;
     while(act != NULL){
            cout << act->dato << endl;
            act = act->sig;
     }
}

int profundidad(pila p){
   return p.profundidad;
}

