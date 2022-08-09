#include<iostream>

using namespace std;

# include "secuencias.cpp"

struct entrada{
       char letra;
       int frec;
};

bool operator <=(entrada e1, entrada e2){
     return e1.letra <= e2.letra;
}

bool operator ==(entrada e1, entrada e2){
     return e1.letra == e2.letra;
}

ostream &  operator <<(ostream & o, entrada e){
  o << e.letra << ":" << e.frec;
  return o;
}


#include "abb.cpp"


//template <>      //modifica insertar de los Abb de entradas, de forma que si está añada la frecuencia
void insertar(Abb<entrada> & a, entrada e);


typedef  ?????? Tabla_frec;

void aniadir(Tabla_frec  & t, char c){


}

Tabla_frec tabla_vacia();



int main(){
     string mensaje;
     getline(cin,mensaje);
     Tabla_frec a=tabla_vacia();
     for(int i = 0;i<mensaje.length();++i){
       aniadir(a,mensaje[i]);
     }
     cout <<in_orden(a);
     return 0;
}
