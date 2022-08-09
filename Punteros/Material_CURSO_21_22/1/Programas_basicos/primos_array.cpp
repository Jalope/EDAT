#include <iostream>

using namespace std;

const int MAX_PRIMOS = 100;
typedef int Lista_int[MAX_PRIMOS];


int main(){
    int n,num_primos;
    int p = 2;
    Lista_int primos;
    cout << "Dame un nÃºmero:";
    cin >> n;
    num_primos = 0;
    while(n!=1){
         if(n % p == 0){
              primos[num_primos] = p;
              num_primos ++;
              n = n / p;
         }
         else{
             p++;
         }
    }
    // Escribimos desde primos
    for(int i = 0;i<num_primos;i++){
         cout << primos[i] << endl;
    }
}

