#include <iostream>

using namespace std;


template <typename T>
void swap(T * array, int  i, int  j){
     T aux = array[i];
     array[i] = array[j];
     array[j] = aux;
}

template <typename T>
void pivotar(T * array,T p, int primero, int ultimo, int & ultimo_menor, int & primer_mayor){
     if(primero<ultimo){
          int primero_desc = primero;
          int ultimo_desc = ultimo;
          int primer_igual = primero ;
          //int ultimo_menor = primero -1;
          while(primero_desc <= ultimo_desc){
                if(! (array[primero_desc] <= p)){
                        swap(array,primero_desc,ultimo_desc);
                        ultimo_desc--;
                }
                else if(! (p<= array[primero_desc])){
                       swap(array,primero_desc,primer_igual);
                       primer_igual++;
                       primero_desc++;
                }
                else{
                      primero_desc++;
                }
          }
          ultimo_menor = primer_igual - 1;
          primer_mayor = ultimo_desc + 1;
     }

}

template <typename T>
void quicksort_in_situ(T * array,int primero, int ultimo){
          if(primero < ultimo){
                int new_ultimo,new_primero;
                pivotar(array,array[primero],primero, ultimo,new_ultimo,new_primero);
                quicksort_in_situ(array,primero,new_ultimo);
                quicksort_in_situ(array,new_primero,ultimo);
          }

}

template <typename T>
void mostrar(T* array,int primero, int ultimo){
  for(int i = primero;i<=ultimo;i++){
    mostrar(array[i]);
    cout <<  " ";
  }
  cout <<endl;
}

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


int main(){
    par_int  pares[100];
    for(int i = 0; i< 100; i++){
      int n = rand() % 50;
      pares[i] = new_par(i,n);
    }
    mostrar(pares,0,99);
    cout<<endl;
    quicksort_in_situ(pares,0,99);
    mostrar(pares,0,99);
    return 0;
}
