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
bool menor(Mat_elem e1,Mat_elem e2);

typedef Mat_elem Array_elems[MAX_ELEMS];

Mat_elem new_Mat_elem(double d, int i, int j);

struct Lista_elems{
    Array_elems entradas;
    int num_entradas = 0;
};

bool aniadir(Lista_elems & l, Mat_elem  e); // aniade el elemento e a l, si está llena devuelve false
bool aniadir_ord(Lista_elems & l, Mat_elem  e); // l está ordenada (según el orden lexicográfico de los pares i,j en Mat_elem) e1 < e2 si y sólo si:
                                                 //  e1.i < e2.i || ((e1.i == e2.i) && e1.j < e2.j).
                                                 // inserta e en l ordenadamente,
int len(const Lista_elems & l); // número de elementos en l
Mat_elem get_elem(const Lista_elems & l, int i); // i <len(l)

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
       Mat_elem e = new_Mat_elem(4,1,2);
       aniadir_ord(mat.m,e);
       mostrar(mat);
       e = new_Mat_elem(8,3,3);
       aniadir_ord(mat.m,e);
       mostrar(mat);
     }
     return 0;
}

Mat_elem new_Mat_elem(double d, int i, int j){
         Mat_elem result;
         result.valor = d;
         result.i = i;
         result.j = j;
         return result;
}

bool menor(Mat_elem e1,Mat_elem e2){
     return e1.i < e2.i || ((e1.i == e2.i) && e1.j < e2.j);
}
//añade e a la lista l
bool aniadir(Lista_elems & l, Mat_elem  e){
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

bool aniadir_ord(Lista_elems & l, Mat_elem  e){
  bool result = true;
  if(l.num_entradas<MAX_ELEMS){
     int pos = 0;
     while(pos < l.num_entradas && menor(l.entradas[pos],e)){
       pos++;
     }
     for(int i=l.num_entradas;i >=  pos;i--){
       l.entradas[i+1] = l.entradas[i];
     }
     l.entradas[pos] = e;
     l.num_entradas++;
  }
  else{
      result = false;
  }
  return result;
}

int len(const Lista_elems & l){
    return l.num_entradas;
}

Mat_elem get_elem(const Lista_elems & l, int i){
    return l.entradas[i];
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
    for(int i = 0; i < len(mat.m) ; i ++){
          if(i!=0){cout << ",";}
          mostrar(get_elem(mat.m,i));
    }
    cout << "],"<< mat.k << "," << mat.f << "," << mat.c;
    cout << endl;
}

