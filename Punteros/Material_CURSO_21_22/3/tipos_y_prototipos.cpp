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

