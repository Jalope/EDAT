#include <iostream>

using namespace std;

const int CAP_INIC = 2;

typedef int *  Lista_int;

//pone en el array primos los factores primos de n.
//devuelve en num_primos el nÃºmero de factores primos
void descomponer (int n, Lista_int & primos, int & num_primos); // ojo!!! pasamos primos por valor porque
                                                                // puede que tengamos que cambiar el array al que se refiere (ver la implementación)


int num_factors (int n);


void mostrar (Lista_int l, int num_elems);

int main(){
    int n, num_primos;
    Lista_int primos;
    cout << "Dame un nÃºmero:";
    cin >> n;
    //num_primos = num_factors(n);
    primos = new int[CAP_INIC];
    // Descomponemos en primos
    descomponer(n,primos,num_primos);
    // Escribimos desde primos
    mostrar(primos,num_primos);
    delete[] primos; // si no lo hacemos todo funciona, pero queda memoria "colgada"
    return 0;
}

int num_factors (int n){
  int num_primos = 0;
  int p = 2;
  while(n!=1){
       if(n % p == 0){
            num_primos++;
            n = n / p;
       }
       else{
           p++;
       }
  }
  return num_primos;
}

void descomponer (int n, Lista_int &  primos, int & num_primos){
    num_primos = 0;
    int cap = CAP_INIC;
    int p = 2;
    while(n!=1){
         if(n % p == 0){
              if(num_primos == cap){
                int* aux = new int[cap*2];
                cap = cap * 2;
                for(int i = 0;i<num_primos;i++){
                  aux[i] = primos[i];
                }
                delete[] primos;
                primos = aux;
              }
              primos[num_primos] = p;
              n = n / p;
              num_primos++;
         }
         else{
             p++;
         }
    }
}

void mostrar (Lista_int l, int num_elems){
    for(int i = 0; i< num_elems; i++){
        cout << l[i] << endl;
    }
}

