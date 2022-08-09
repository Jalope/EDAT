#include<iostream> //para usar cin, cout ...
#include<fstream> // para poder leer archivos
#include<string> // para usar el tipo string

using namespace std;


const int CAP_INIC = 20;


struct Mat_elem{
     double valor;
     int i; // fila
     int j; // columna
};

Mat_elem transpuesto(Mat_elem e);
//escribe e en cout (sin salto de linea al final)
void mostrar(Mat_elem e);
bool menor(Mat_elem e1,Mat_elem e2);

//typedef Mat_elem Array_elems[MAX_ELEMS];

Mat_elem new_Mat_elem(double d, int i, int j);

struct Lista_elems{
    Mat_elem* entradas;
    int num_entradas = 0;
    int cap = 0;

};

void aniadir(Lista_elems & l, Mat_elem  e); // aniade el elemento e a l, si está llena devuelve false
void aniadir_ord(Lista_elems & l, Mat_elem  e); // l está ordenada (según el orden lexicográfico de los pares i,j en Mat_elem) e1 < e2 si y sólo si:
                                                 //  e1.i < e2.i || ((e1.i == e2.i) && e1.j < e2.j).
                                                 // inserta e en l ordenadamente,
void inicializa(Lista_elems & l);
void libera(Lista_elems &l);
void duplica_cap(Lista_elems & l); // duplica la capacidad de la lista
int len(const Lista_elems & l); // número de elementos en l
Mat_elem get_elem(const Lista_elems & l, int i); // i <len(l)

struct MatrizKK{

    double k;
    int f;
    int c;
    Lista_elems m;
};

void inicializa(MatrizKK & mat, int i, int j, double k);
void libera(MatrizKK & mat);
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
       MatrizKK trans = traspuesta(mat);

       mostrar(trans);
       MatrizKK mat_suma = suma(mat,trans);
       mostrar(mat_suma);
       libera(mat);
       libera(trans);
       libera(mat_suma);

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

void inicializa(Lista_elems &l){
     l.entradas = new Mat_elem[CAP_INIC];
     l.num_entradas = 0;
     l.cap = CAP_INIC;
}

void libera(Lista_elems &l){
     delete[] l.entradas;
     l.entradas = NULL;
     l.cap = 0;
     l.num_entradas = 0;
}

void duplica_cap(Lista_elems & l){
     Mat_elem* new_lista = new Mat_elem[2*l.cap];
     for(int i = 0;i<l.num_entradas;i++){
       new_lista[i] = l.entradas[i];
     }
     delete[] l.entradas;
     l.entradas = new_lista;
}

//añade e a la lista l
void aniadir(Lista_elems & l, Mat_elem  e){
     if(len(l) >= l.cap){
       duplica_cap(l);
     }
     l.entradas[l.num_entradas] = e;
     l.num_entradas++;
}

void aniadir_ord(Lista_elems & l, Mat_elem  e){
  bool result = true;
  if(len(l) >= l.cap){
    duplica_cap(l);
  }

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
     inicializa(mat,f,c,k);
     for(int i = 0; i < f ; i ++){
       for(int j = 0; j < c; j ++){
          archivo >> valor;
          if(valor!=k){
               Mat_elem e;
               e = new_Mat_elem(valor,i,j);
               aniadir(mat.m,e);

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

Mat_elem transpuesto(Mat_elem e){
  return new_Mat_elem(e.valor,e.j,e.i);
}

void inicializa(MatrizKK & mat, int f, int c, double k){
  inicializa(mat.m);
  mat.f = f;
  mat.c = c;
  mat.k = k;
}

void libera(MatrizKK & mat){
  libera(mat.m);
  mat.f = 0;
  mat.c = 0;
  mat.k = 0;
}

MatrizKK traspuesta(MatrizKK mat){
      MatrizKK result;
      inicializa(result, mat.f, mat.c, mat.k);
      for(int i = 0;i<len(mat.m);i++){
          aniadir_ord(result.m,transpuesto(get_elem(mat.m,i)));
      }
      return result;
}

MatrizKK suma(MatrizKK mat1, MatrizKK mat2){
      MatrizKK result;
      int k1 = mat1.k;
      int k2 = mat2.k;
      int k = k1 + k2;
      int pos1=0, pos2 = 0;
      inicializa(result,mat1.f,mat1.c, k);
      while(pos1 < len(mat1.m) && pos2 < len(mat2.m)){
          Mat_elem e1 = get_elem(mat1.m,pos1);
          Mat_elem e2 = get_elem(mat2.m,pos2);
          if(e1.i == e2.i && e1.j == e2.j){
            if(e1.valor + e2.valor != k){
              aniadir(result.m,new_Mat_elem(e1.valor+e2.valor,e1.i,e1.j));
            }
            pos1++;
            pos2++;
          }
          else if(menor(e1,e2)){
            aniadir(result.m,new_Mat_elem(e1.valor + k2, e1.i,e1.j));
            pos1++;
          }
          else{
            aniadir(result.m,new_Mat_elem(k1 + e2.valor, e2.i,e2.j));
            pos2++;
          }
      }
      while(pos1 < len(mat1.m)){
        aniadir(result.m,get_elem(mat1.m,pos1));
        pos1++;
      }
      while(pos2 < len(mat2.m)){
        aniadir(result.m,get_elem(mat2.m,pos2));
        pos2++;
      }
      return result;
}

