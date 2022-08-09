#include <iostream>

using namespace std;


// devuelve el maximo común divisor de a y b
int gcd(int a, int b);



//devuelve por variable en d,x,y el gcd de a y b. Así como x,y t.q d = x*a+y*b
void bezout_var(int a, int b, int & d, int & x, int & y);

int main(){
    int n,m,d;
    int x,y;
    cout << "Dame un número:" << endl;
    cin >> n;
    cout << "Dame otro número:" << endl;
    cin >> m;
    bezout_var(n,m,d,x,y);
    cout << "el mcd de "<< n << " y " << m << " es:" << d << endl;
    cout << d << " = " << x << "*" << n << "+" << y << "*" << m << endl;
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

void bezout_var(int a, int b, int & d, int & x, int & y){
  if(b == 0){
     d = a;
     x = 1;
     y = 0;
  }
  else{
     int c = a / b;
     int r = a % b;
     int x1,y1;
     bezout_var(b,r,d,x1,y1);
     // d =  x1 * b + y1 * r  además a = c * b + r
     // una sencilla cuenta (despejar r en la segunda ecuación y sustituirlo en la primera) nos convence de que:
     // d = y1 * a + (x1 - c * y1) * b, así que ya tenemos resuelto el problema para a y b
     x = y1;
     y = (x1 - c * y1);
  }
}
