#include<iostream>

using namespace std;

typedef char elemento1;

struct nodo_pilac {
       elemento1 dato;
       nodo_pilac * sig;
};

struct pilac{
  nodo_pilac * ultimo = NULL;
  int profundidad = 0;
};

//typedef nodo_pilac* pilac;

pilac pilac_vacia();
nodo_pilac * nuevo_nodo(elemento1 e,nodo_pilac* s);
void apilar(elemento1 e, pilac & p);
void des_apilar(pilac & p);
elemento1 cima(pilac p);
bool es_vacia(pilac p);
void liberar(pilac p);
void mostrar(pilac p);
int profundidad(pilac p);
elemento1 pop(pilac & p);


/*int main(){
    pilac p = pilac_vacia();
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

pilac pilac_vacia(){
     pilac result;
     return result;
}

nodo_pilac * nuevo_nodo(elemento1 e,nodo_pilac* s){
       nodo_pilac* result = new nodo_pilac;
       result->dato = e;
       result->sig = s;
       return result;
}

void apilar(elemento1 e, pilac & p){
     nodo_pilac* aux = nuevo_nodo(e,p.ultimo);
     p.ultimo = aux;
     p.profundidad++;
}

void des_apilar(pilac & p){
     nodo_pilac* aux = p.ultimo->sig;
     delete p.ultimo;
     p.ultimo = aux;
     p.profundidad--;
}

elemento1 cima(pilac p){
       return p.ultimo->dato;
}
bool es_vacia(pilac p){
     return p.profundidad == 0;
}

void liberar(pilac p){
     while(!es_vacia(p)){
          des_apilar(p);
     }
}

void mostrar(pilac p){
     nodo_pilac * act= p.ultimo;
     while(act != NULL){
            cout << act->dato << endl;
            act = act->sig;
     }
}

elemento1 pop(pilac & p){
    elemento1 result = cima(p);
    des_apilar(p);
    return result;
}

int profundidad(pilac p){
   return p.profundidad;
}

