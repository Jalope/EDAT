#include<iostream>
#include<string>
#include<exception>


using namespace std;

//las dos lineas siguientes son equivalentes a poner aquí el contenido de los dos archivos
#include "pilas_tam_char.cpp" 
#include "pilas_tam_float.cpp"


typedef float elemento; // cambiar float por el tipo de datos adecuado

struct tabla_valores{
      elemento valores[256];
      bool asignado[256];
};

void inicializa(tabla_valores & t){
     for(int i = 0;i < 256;i++){
       t.asignado[i] = false;
     }
}

bool asignado(const tabla_valores & t, char  c){
     return t.asignado[c];
}

elemento get_value(const tabla_valores & t, char c){
    if(t.asignado[c]){
      return t.valores[c];
    }
    else{
      throw runtime_error(c+" no está asignado");
    }
}

void put_value(tabla_valores  & t,char c,elemento val){
     t.valores[c] = val;
     t.asignado[c] = true;
}


int main(){
    string s;
    cin >> s;
    while(s!="exit"){
       if(<s contiene <- >){
            <separa variable y número>
            <procesa asignación>
       }
       else if (< s contiene = >){
            <separa variable y expresión>
            <evalua expresión>
            <procesa asignación>
       }
       else{
            <muestra el valor de la variable>
       }
       cin >> s;
     }
    return 0;
}

