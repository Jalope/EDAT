#include<iostream>
#include<string>
#include<exception>


using namespace std;

#include "pilas_tam_template.cpp"

template <typename elemento>
struct tabla_valores{
      elemento valores[256];
      bool asignado[256];
};

template <typename elemento>
void inicializa(tabla_valores<elemento> & t){
     for(int i = 0;i < 256;i++){
       t.asignado[i] = false;
     }
}

template <typename elemento>
bool asignado(const tabla_valores<elemento> & t, char  c){
     return t.asignado[c];
}

template <typename elemento>
elemento get_value(const tabla_valores<elemento> & t, char c){
    if(t.asignado[c]){
      return t.valores[c];
    }
    else{
      throw runtime_error(c+" no está asignado");
    }
}

template <typename elemento>
void put_value(tabla_valores<elemento>  & t,char c,elemento val){
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

bool es_operador(char c){
  return c == '*' || c == '-' || c == '+' || c == '/';
}

template <typename elemento>
elemento aplica_op(char op,elemento op1, elemento op2){
         if(op == '*'){
           return op1*op2;
         }
         else if(op == '/'){
           cout<<op1<<","<<op2<<endl;
           return op1/op2;
         }
         else if(op == '+'){
           return op1+op2;
         }
         else if(op == '-'){
           return op1-op2;
         }
         else{
           return 0;
         }
}

template <typename elemento>
void aplica_op(pila<elemento> & p,char op){
         elemento e1,e2;
         e1 = pop(p);
         e2 = pop(p);
         apilar(aplica_op(op,e2,e1),p);
}

template<typename elemento>
elemento evaluar(const tabla_valores<elemento> & t,string s){
       pila<elemento> pila_valores;
       pila<char> pila_op;
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
    tabla_valores<float> t;
    inicializa(t);
    string s;
    cin >> s;
    while(s!="exit"){

       if(s.find("<-")!=-1){
            int pos=s.find("<-");
            char var = s[0];
            //cout << s.substr(3)<<endl;
            put_value(t,s[0],stof(s.substr(3)));
       }
       else if (s.find("=")!=-1){
            float  valor = evaluar(t,s.substr(2));
            put_value(t,s[0],valor);
       }
       else{
            cout << s << ":" << get_value(t,s[0]) <<endl;
       }
       cin >> s;
     }
    return 0;
}

