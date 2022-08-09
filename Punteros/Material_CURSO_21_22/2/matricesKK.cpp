#include<iostream> //para usar cin, cout ...
#include<fstream> // para poder leer archivos
#include<string> // para usar el tipo string

using namespace std;


const int MAX_ELEMS = 20;


struct Mat_elem{
     double valor;
     int i; // fila
     int j; // columna
};

typedef Mat_elem Array_elems[MAX_ELEMS];

struct Lista_elems{
    Array_elems entradas;
    int num_entradas = 0;
};

struct MatrizKK{
    Lista_elems m;
    double k;
    int f;
    int c;
};


MatrizKK suma(MatrizKK m1,MatrizKK m2);

MatrizKK traspuesta(MatrizKK m);

bool leer(string file_name, MatrizKK & mat);
void mostrar(MatrizKK mat);
void mostrar(Mat_elem e);

int main(){
     string nombre_arch;
     MatrizKK mat;
     cout << "Nombre del archivo:";
     cin >> nombre_arch;
     if(leer(nombre_arch,mat)){
       cout<< mat.k<<endl<<mat.c << endl<<mat.f<<endl;
       mostrar(mat);
     }
     return 0;
}

bool leer(string file_name, MatrizKK  & mat){
     fstream archivo;
     int f,c;
     double k,valor;
     archivo.open(file_name);
    archivo >> k >> f >> c;
    mat.k = k;
    mat.f = f;
    mat.c = c;
    for(int i = 0; i < f ; i ++){
      for(int j = 0; j < c; j ++){
         archivo >> valor;
         if(valor!=k){
           if(mat.m.num_entradas >= MAX_ELEMS){
             archivo.close();
             return false;
           }
           else{
               mat.m.entradas[mat.m.num_entradas].valor = valor;
               mat.m.entradas[mat.m.num_entradas].i = i;
               mat.m.entradas[mat.m.num_entradas].j = j;
               mat.m.num_entradas++;
          }
         }
      }
    }
    archivo.close();
    return true;
}
void mostrar(Mat_elem e){
  cout << "("<< e.valor << "," << e.i<< ","<<e.j<<")";
}
void mostrar(MatrizKK mat){
    for(int i = 0; i < mat.m.num_entradas ; i ++){
          if(i!=0){cout << ",";}
          mostrar(mat.m.entradas[i]);

    }
    cout << endl;
}
