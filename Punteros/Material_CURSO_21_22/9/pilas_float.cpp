#include<iostream>

using namespace std;

typedef float elemento2;

struct nodo_pilaf {
       elemento2 dato;
       nodo_pilaf * sig;
};

struct pilaf{
  nodo_pilaf * ultimo = NULL;
  int profundidad = 0;
};

//typedef nodo_pilaf* pilaf;

pilaf pilaf_vacia();
nodo_pilaf * nuevo_nodo(elemento2 e,nodo_pilaf* s);
void apilar(elemento2 e, pilaf & p);
void des_apilar(pilaf & p);
elemento2 cima(pilaf p);
bool es_vacia(pilaf p);
void liberar(pilaf p);
void mostrar(pilaf p);
int profundidad(pilaf p);


/*int main(){
    pilaf p = pilaf_vacia();
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

pilaf pilaf_vacia(){
     pilaf result;
     return result;
}

nodo_pilaf * nuevo_nodo(elemento2 e,nodo_pilaf* s){
       nodo_pilaf* result = new nodo_pilaf;
       result->dato = e;
       result->sig = s;
       return result;
}

void apilar(elemento2 e, pilaf & p){
     nodo_pilaf* aux = nuevo_nodo(e,p.ultimo);
     p.ultimo = aux;
     p.profundidad++;
}

void des_apilar(pilaf & p){
     nodo_pilaf* aux = p.ultimo->sig;
     delete p.ultimo;
     p.ultimo = aux;
     p.profundidad--;
}

elemento2 cima(pilaf p){
       return p.ultimo->dato;
}
bool es_vacia(pilaf p){
     return p.profundidad == 0;
}

void liberar(pilaf p){
     while(!es_vacia(p)){
          des_apilar(p);
     }
}

void mostrar(pilaf p){
     nodo_pilaf * act= p.ultimo;
     while(act != NULL){
            cout << act->dato << endl;
            act = act->sig;
     }
}


elemento2 pop(pilaf & p){
    elemento2 result = cima(p);
    des_apilar(p);
    return result;
}

int profundidad(pilaf p){
   return p.profundidad;
}

