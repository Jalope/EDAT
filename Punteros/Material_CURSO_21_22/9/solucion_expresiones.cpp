#include<iostream>
#include<string>
#include<exception>

#include "pilas_tam_char.cpp"
#include "pilas_tam_float.cpp"

using namespace std;

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

int precedencia(char c){
     if(c == '*' || c == '/'){
       return 2;
     }
     else if( c=='+' || c == '-'){
       return 1;
     }
     else{
       return 0;
     }
}

int es_operador(char c){
  return c == '*' || c == '-' || c == '+' || c == '/';
}


elemento aplica_op(char op,elemento op1, elemento op2){
         if(op == '*'){
           return op1*op2;
         }
         else if(op == '/'){
           return op1/op2;
         }
         else if(op == '+'){
           return op1+op2;
         }
         else if(op == '-'){
           return op1-op2;
         }
         return 0;
}


void aplica_op(pilaf& p,char op){
         elemento e1,e2;
         e1 = pop(p);
         e2 = pop(p);
         apilar(aplica_op(op,e2,e1),p);
}


elemento evaluar(const tabla_valores & t,string s){
       pilaf pila_valores=pilaf_vacia();
       pilac pila_op = pilac_vacia();
       for(int i = 0;i<s.length();i++){
           char c = s[i];
           if(c == '('){
             apilar(c,pila_op);
           }
           else if(c == ')'){
             while(cima(pila_op)!='('){
               aplica_op(pila_valores,pop(pila_op));
             }
             des_apilar(pila_op);
           }
           else if(es_operador(c)){
             while(!es_vacia(pila_op) && cima(pila_op)!='(' && precedencia(cima(pila_op)) >= precedencia(c)){
               aplica_op(pila_valores,pop(pila_op));
             }
             apilar(c,pila_op);
           }
           else{
             apilar(get_value(t,c),pila_valores);
           }
       }
       while(!es_vacia(pila_op)){
         aplica_op(pila_valores,pop(pila_op));
       }
       elemento result = pop(pila_valores);
       return result;
}


int main(){
    tabla_valores t;
    inicializa(t);
    string s;
    cin >> s;
    while(s!="exit"){
       char v=s[0];
       float valor;
       if(s.find("<-")!=-1){
            valor = stof(s.substr(3));
            put_value(t,v,valor);
       }
       else if (s.find("=")!=-1){
            valor = evaluar(t,s.substr(2));
            put_value(t,v,valor);
       }
       else{
            cout << get_value(t,v) << endl;
       }
       cin >> s;
     }
    
    return 0;
}
