#include <iostream>

using namespace std;




int main(){
    int n = 0;
    int p = 2;
    Lista_int primos;
    cout << "Dame un nÃºmero:";
    cin >> lect;
    n= lect;
    while(n!=1){
         if(n % p == 0){
              cout << p << endl;
              n = n / p;
         }
         else{
             p++;
         }
    }
    
}
