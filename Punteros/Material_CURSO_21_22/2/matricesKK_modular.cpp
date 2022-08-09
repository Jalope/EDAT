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

//escribe e en cout (sin salto de linea al final)
void mostrar(Mat_elem e);


typedef Mat_elem Array_elems[MAX_ELEMS];

Mat_elem new_Mat_elem(double d, int i, int j);

struct Lista_elems{
    Array_elems entradas;
    int num_entradas = 0;
};

bool aniadir(Lista_elems & l, Mat_elem & e);

struct MatrizKK{
    Lista_elems m;
    double k;
    int f;
    int c;
};


//escribe en cout mat 
void mostrar(MatrizKK mat);

bool leer(string file_name, MatrizKK & mat);


MatrizKK suma(MatrizKK m1,MatrizKK m2);

MatrizKK traspuesta(MatrizKK m);



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

//añade e a la lista l
bool aniadir(Lista_elems & l, Mat_elem & e){
     bool result = true;
     if(l.num_entradas<MAX_ELEMS){
         l.entradas[l.num_entradas] = e;
         l.num_entradas++;
     }
     else{
         result = false;
     }
     return result;
}

bool leer(string file_name, MatrizKK  & mat){
     ifstream archivo;
     int f,c;
     double k,valor;
     bool result = true;
     archivo.open(file_name);
     archivo >> k >> f >> c;
     mat.k = k;
     mat.f = f;
     mat.c = c;
     for(int i = 0; i < f ; i ++){
       for(int j = 0; j < c; j ++){
          archivo >> valor;
          if(valor!=k){
               Mat_elem e;
               e = new_Mat_elem(valor,i,j);
               result = aniadir(mat.m,e);
               if(!result){
                   return false;
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
    cout << "[";
    for(int i = 0; i < mat.m.num_entradas ; i ++){
          if(i!=0){cout << ",";}
          mostrar(mat.m.entradas[i]);
    }
    cout << "],"<< mat.k << "," << mat.f << "," << mat.c;
    cout << endl;
}

Mat_elem new_Mat_elem(double d, int i, int j){
         Mat_elem result;
         result.valor = d;
         result.i = i;
         result.j = j;
         return result;   
}

