#include <iostream>

using namespace std; 

int main() {
    int n = 100;
    cout << n << endl; 
    int *p = new int[n];
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < n; i++) cout << p[i] << endl;
    delete [] p;
    return 0;
}