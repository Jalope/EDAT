#include<iostream>

using namespace std;

void mostrar(int i){
    cout << i;
}

template<typename T>

struct Nodo_lista{
      T dato;
      Nodo_lista<T> * sig = NULL , * ant=NULL;
};

template<typename T>
struct Lista {
      int longitud = 0;
      Nodo_lista<T> * primero = NULL, * ultimo = NULL;     
};

template<typename T>
int longitud(Lista<T> l){
    return l.longitud;
}

template<typename T>
void mostrar(Lista<T> l){
     Nodo_lista<T> * actual = l.primero;
     while(actual!=NULL){
         mostrar(actual->dato);
         cout << " ";
         actual = actual->sig;
     }
     cout << endl;
}

template<typename T>
void aniadir_dcha(Lista<T> & l,T e){
     
}

template<typename T>
void eliminar_dcha(Lista<T> & l){
     
}



template<typename T>
void aniadir_izda(Lista<T> & l,T e){
     
}



int main(){
    Lista<int> l;
    for(int i = 0; i< 10 ;i++){
         aniadir_dcha(l,i);
         aniadir_izda(l,i);
    }
    for(int i = 0;i<3; i++){
         eliminar_dcha(l);
    }
    mostrar(l);
    
}
