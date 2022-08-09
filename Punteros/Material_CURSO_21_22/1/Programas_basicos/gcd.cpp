#include <iostream>

using namespace std;


struct Triple_int{
    int d;
    int x;
    int y;
};

// devuelve el maximo común divisor de a y b
int gcd(int a, int b);

// devuelve un triple_int t de forma que t.d = gcd(a,b) y t.d = t.x * a + t.y * b
Triple_int bezout(int a, int b);

int main(){
    int n,m,d;
    Triple_int t;
    cout << "Dame un número:" << endl;
    cin >> n;
    cout << "Dame otro número:" << endl;
    cin >> m;
    t = bezout(n,m);
    cout << "el mcd de "<< n << " y " << m << " es:" << t.d << endl;
    cout << t.d << " = " << t.x << "*" << n << "+" << t.y << "*" << m << endl;
    
} 

int gcd(int a, int b){
    int r;
    while (b!=0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

Triple_int bezout(int a, int b){
    Triple_int result;
    if(b == 0){
       result.d = a;
       result.x = 1;
       result.y = 0;
    }
    else{
       int c = a / b;
       int r = a % b;
       Triple_int result1 = bezout(b,r);
       // d = result1.x * b + result1.y * r  además a = c * b + r
       // una sencilla cuenta (despejar r en la segunda ecuación y sustituirlo en la primera) nos convence de que:
       // d = result1.y * a + (result1.x - c * result1.y) * b, así que ya tenemos resuelto el problema para a y b
       result.d = result1.d;
       result.x = result1.y;
       result.y = (result1.x - c * result1.y);
    }
    return result;
}

