#include <iostream>
#include <time.h>



using namespace std;

const string FLECHA = "↓";


struct par_int{
  int primero ;
  int segundo ;
};

par_int new_par(int p,int s){
    par_int result;
    result.primero = p;
    result.segundo = s;
    return result;
};

bool operator <=(par_int e1,par_int e2){
  return e1.segundo<=e2.segundo;
};

void mostrar(par_int e){
    cout << "("<<e.primero<<","<<e.segundo<<")";
};




template <typename T>
struct Nodo_sec{
       T dato;
       Nodo_sec<T> * sig = NULL;
};

template <typename T>
struct Secuencia{
  Nodo_sec<T> * primero;
  Nodo_sec<T> * anterior; //puntero al anterior al actual
};

template <typename T>
Secuencia<T> crear(){
  Secuencia<T> s;
  s.primero = new Nodo_sec<T>;
  s.anterior = s.primero;
  return s;
};

template <typename T>
void insertar(Secuencia<T>& s,T e){
  Nodo_sec<T> * new_node = new Nodo_sec<T>;
  new_node->dato = e;
  new_node->sig = s.anterior->sig;
  s.anterior->sig = new_node;
  s.anterior = new_node;
};


template <typename T>
void eliminar(Secuencia<T>& s){
  if(s.anterior->sig != NULL){
    Nodo_sec<T> * aux = s.anterior->sig;
    s.anterior->sig = aux->sig;
    delete aux;
  }
  else{
    throw runtime_error(" final de la  secuencia");
  }
};

template <typename T>
T actual(const Secuencia<T>& s){
  if(s.anterior->sig != NULL){
    return s.anterior->sig->dato;
  }
  else{
    throw runtime_error(" final de la  secuencia");
  }
};

template<typename T>
void avanzar(Secuencia<T>& s){
  if(s.anterior->sig != NULL){
    s.anterior = s.anterior->sig;
  }
  else{
    throw runtime_error("final de la  secuencia");
  }
}


template<typename T>
void reiniciar(Secuencia<T>& s){
  s.anterior = s.primero;
}

template<typename T>
bool fin(Secuencia<T> s){
  return s.anterior->sig == NULL;
}

template<typename T>
void liberar(Secuencia<T> s){
     reiniciar(s);
     while(!fin(s)){
         eliminar(s);
     }
     delete s.primero;
}

template<typename T>  // debe existir una procedimiento void mostrar(T dato) que mande
                      //la representación de dato a cout
void mostrar(Secuencia<T> s){
    Nodo_sec<T> * aux = s.primero;
    while(aux->sig != NULL){
      if(aux == s.anterior){
        cout << FLECHA;
      }
      mostrar(aux->sig->dato);
      cout <<  " ";
      aux = aux->sig;
    }
    cout << endl;
}

template <typename T>
bool es_vacia(Secuencia<T> s){
    return s.primero->sig == NULL;
}


template<typename T>
void ordenar_burbuja(Secuencia<T> s){
      //s es no vacía
      reiniciar(s);
      bool changed = true;
      while(changed){
        changed = false;
        reiniciar(s);
        T anterior = actual(s);
        eliminar(s);
        while(!fin(s)){
          if(anterior<=actual(s)){
            insertar(s,anterior);
            anterior = actual(s);
            eliminar(s);
          }
          else{
            avanzar(s);
            changed = true;
          }
        }
        insertar(s,anterior);
        //mostrar(s);
      }
      reiniciar(s);
}

template<typename T>
Secuencia<T> quick_sort(Secuencia<T> s){
    if(!es_vacia(s)){
      Secuencia<T> menores = crear<par_int>();
      Secuencia<T> mayores = crear<par_int>();
      Secuencia<T> iguales = crear<par_int>();
      Secuencia<T> result = crear<par_int>();
      reiniciar(s);
      T pivote = actual(s);
      while(!fin(s)){
        if(!(actual(s)<=pivote)){
          insertar(mayores,actual(s));
        }
        else if (!(pivote <= actual(s))){
           insertar(menores,actual(s));
        }
        else{
          insertar(iguales,actual(s));
        }
        avanzar(s);
      }
      Secuencia<T> menores_ord = quick_sort(menores);
      Secuencia<T> mayores_ord = quick_sort(mayores);
      while(!fin(menores_ord)){
        insertar(result,actual(menores_ord));
        avanzar(menores_ord);
      }
      reiniciar(iguales);
      while(!fin(iguales)){
        insertar(result,actual(iguales));
        avanzar(iguales);
      }
      while(!fin(mayores_ord)){
        insertar(result,actual(mayores_ord));
        avanzar(mayores_ord);
      }
      reiniciar(result);
      liberar(menores);
      liberar(mayores);
      liberar(iguales);
      liberar(menores_ord);
      liberar(mayores_ord);
      return result;
    }
    else{
    return crear<par_int>();
    }
}

int main(){
    Secuencia<par_int> s = crear<par_int>();
    Secuencia<par_int> s1 = crear<par_int>();
    Secuencia<par_int> s2 ;

    for(int i = 0; i< 30000; i++){
      int n = rand() %10000;
      insertar(s,new_par(i,n));
      insertar(s1,new_par(i,n));
    }
    reiniciar(s);
    reiniciar(s1);
    mostrar(s);
    time_t t0 = clock();
    s2 = quick_sort(s);
    time_t t1 = clock();
    cout<<"quick_sort ejecutado en "<< ((float)(t1-t0))/CLOCKS_PER_SEC<<" segundos"<< endl;
    //quick_sort_in_situ(s,s.primero,(Nodo_sec<par_int> *) NULL);
    time_t t2 = clock();
    //cout<<"quick_sort_in_situ ejecutado en "<< ((float)(t2-t1))/CLOCKS_PER_SEC<<" segundos"<< endl;
    ordenar_burbuja(s1);
    time_t t3 = clock();
    cout<<"burbuja ejecutado en "<< ((float)(t3-t2))/CLOCKS_PER_SEC<<" segundos"<< endl;
    mostrar(s2);
    cout<<"quick_sort ejecutado en "<< ((float)(t1-t0))/CLOCKS_PER_SEC<<" segundos"<< endl;
    //cout<<"quick_sort_in_situ ejecutado en "<< ((float)(t2-t1))/CLOCKS_PER_SEC<<" segundos"<< endl;
    cout<<"burbuja ejecutado en "<< ((float)(t3-t2))/CLOCKS_PER_SEC<<" segundos"<< endl;
    liberar(s);
    liberar(s1);
    liberar(s2);
    return 0;
}
