//Implementación del TAD Lista mediante arrays
#include <iostream>
#include <assert.h> 
using namespace std; 

/*Tipos de longitud: 
    - Capacidad de una lista: tamaño del array que contiene los elementos.
    - Tamaño de una lista: Número de posiciones ocupada por elementos. 
siempre se cumple: 
    tamaño <= capacidad 
*/
const int DEFAULT_CAPACITY = 10; 

class ListArray {
    public: 
        //metodos constructores con 0 elementos (vacía), capacidad inicial de hasta la constante default_capacity y creación de la varible puntero con el array. 
        ListArray(int initial_capacity)
            : num_elems(0), capacity(initial_capacity), elems (new string[capacity]) {}
        
        //constructor por defecto. genera una lista vacía llamando a initicial_capacity con DEFAULT_CAPACITY
        ListArray()
            : ListArray(DEFAULT_CAPACITY) {}
        /* El segundo constructor lo que hace es llamar al primero tomando initial_capacity = DEFAULT_CAPACITY. Esto lo podemos resumir en un unico constructuro 
        ListArray(int initial_capacity = DEFAULT_CAPCITY)
            : num_elems(0), capacity(initial_capacity), elems (new string[capacity]) {}
        estamos diciendo que el constructor recibe un parametro opcional, si este parametro no se indica, se tomara como valor por defecto DEFAULT_CAPACITY
        */

        //Destructor 
        ~ListArray() {delete[] elems;}

        void push_back(const string &elem);
        void push_front(const string &elem); 
        void pop_back(); 
        void pop_front();
        int size() const {
            return num_elems;
        }
        bool empty() const {
            return num_elems == 0; 
        } 
        string front() const {
            assert(num_elems > 0);
            return elems[0];
        }
        string back() const {
            assert(num_elems > 0);
            return elems[num_elems - 1];
        }

        /*Creamos un metodo que devuelve el elemento que está en la posicion pasada como parametro. Si lo hacemos como está implementado en aT (version primera), tenemos un metodo constante que no va a mutar nuestra lista. Pero, si lo hacemos como en at (segunda version) tenemos algo mucho más potente y peligroso. Pues este metodo no sólo devuelve el elemento que está en la posicion index, si no que nos permite mutarlo. El tipo de la función es "string & at..." es decir la salida es una REFERENCIA a un string, es decir, además de mirar estamos creando un hilo. Por ejemplo si hacemos: 
        l = ["David", "Maria", "Elvira"]
            string m = l.at[1]
            m = "Javier"
        l = ["David", "Javier", "Elvira"]
        HEMOS CAMBIADO LA LISTA!! 
        
        Si esto lo hacemos con aT, el resultado visual es el mismo, pero la lista no habrá cambiado: 
        l = ["David", "Maria", "Elvira"]
            string m = l.aT[1]
            m = "Javier"
        l = ["David", "Maria", "Elvira"]  
        ver imagen: "Modficar elemento lista por referencia"*/ 
        
        /* 
        string aT(int index) const {
            assert(0 <= index && index <= num_elems -1);
            return elems[index];
        }
     
        
        string & at(int index) {
            assert(0 <= index && index <= num_elems -1);
            return elems[index];
        }*/

        /* Si ahora en otro metodo pasamos la lista como algo constante y utilizamos at que está trabajando con referencias obtendremos errores. Por ejemplo con la función contar_caracteres. Esta debe llamar a la version cte at. */

        /* La solución es tener dos versiones. La primera es constante y devuelve una referencia constante (la referencia no puede ser modificada desde fuera). La segunda, será una versión no contaste devolviendo una referencia no constante. El compilador sabrá diferenciar. Si por ejemplo hacemos <lista.at(1) = "Javier">, sabrá que tiene que llamar al no constante. 
        
        Finalmente hay que tener cuidado con esto. Si se obtiene una referencia a un elemento de la lista, debe hacerse uso de esa referencia ANTES de añadir, eliminar, etc. otros elementos de la lista. Para asi, no enerar llamadas a cosas borradas. Por ejemplo:  
        string &primero = l.front(); 

        l.push_back("David"); 

        primero = "Javier Francisco" --> Hace referencia a una memoria liberada dentro del metodo push_back. ERROR!! 

        Lo correcto sería 
        l.front() = "Javier Francisco"  */
        
        //Versión cte. 
        const string & at(int index) const {
            assert(0 <= index && index <= num_elems -1);
            return elems[index];
        }
        //Versión NO cte. 
        string & at(int index) {
            assert(0 <= index && index <= num_elems -1);
            return elems[index];
        }


        void display() const;
 

    private: 
        //Definimios 3 atributos: 

        int num_elems; //(tamaño) longitud de la lista. INDICE DE LA PRIMERA POSICION VACIA.(La lista va de 0 a n-1 tendrá longitud n).
        
        int capacity; // tamaño del array que contra los elementos de la lista (capacidad)
        
        //PUNTERO AL ARRAY.  string elems[MAX_CAPACITY]; variable de tipo puntero a array con un límite de capacidad. Los elementos en este caso son sólo de tipo cadena de caracteres. La definimos con un puntero
        string *elems;

        void resize_array(int new_capacity);
};



// Constructoras

//Mutadoras: 
/*  {L = [x_0, ..., x_(n-1)]}
    push_back(z: elem, L: list)
    {[L = [x_0, ... x_(n-1), z]}    */
void ListArray :: push_back(const string &elem) {//????????????xq no se pasa la lista y xq el elemento se pasa por ref.
    if (num_elems == capacity) { //en caso de que la lista no admita más elemento tenemos que hacerla más grande
        resize_array(capacity * 2); //metodo privado para agrandar el array
    }

    elems[num_elems] = elem; //en la lista elems, en la posicion num_elems metemetos el elemento elem. 
    num_elems++; 
}

void ListArray :: resize_array(int new_capacity) {
    string *new_elems = new string[new_capacity]; //creamos una nueva variable puntero de tipo array con la nueva capacidad
    for(int i = 0; i < num_elems; i++) {
        new_elems[i] = elems[i]; //copiamos lo que teniamos en la vieja lista
    }

    delete[] elems; //liberamos memoria del puntero de la lista antigua 
    elems = new_elems; //guardamos la nueva lista 
    //??????????????????????xq no eliminamos new_elems una vez copiada en elems.
    capacity = new_capacity;  //actualizamos capacidad 
}

/*  {L = [x_0, ..., x_(n-1)]}
    push_front(z: elem, L: list)
    {[L = [z, x_0, ... x_(n-1)]}    */
void ListArray :: push_front(const string &elem) {
    if (num_elems == capacity) {
        resize_array(capacity * 2); 
    }
    //desplazamos todos los elementos una posición a la derecha
    for (int i = num_elems -1; i >= 0; i--) {
        elems[i + 1] = elems[i];
    }
    //guardamos el elemento
    elems[0] = elem; 
    num_elems++;
}

/*  {L = [x_0, x_1, ..., x_(n-2) x_(n-1)], n >= 1}
    pop_back(L: list)
    {[L = [x_0, x_1, ... x_(n-2)]}  */
void ListArray :: pop_back() {
    assert(num_elems > 0);
    num_elems--; 
}

/*  {L = [x_0, x_1, ..., x_(n-1)] ^ n >= 1}
    pop_front(L: list)
    {[L = [x_1, ... x_(n-1)]}   */ 
void ListArray :: pop_front() {
    assert(num_elems > 0);

    //vamos a dejar un hueco por lo que tenemos que desplazar todos los elementos una posición a su izq. 
    for (int i=1; i < num_elems; i++) {
        elems[i - 1] = elems[i];
    }

    //diminuimos el número de elementos
    num_elems--;
}
//Observadoras: 
//se def. dentro de la clase xq solo es una linea de codigo
/*  {L = [x_0, ..., x_(n-1)]}
    size(L: list) -> (tamaño: int)
    {tamaño = n}    */ 

/*  {L = [x_0, ..., x_(n-1)]}
    empty(L: list) -> (b: bool)
    {b = true <-> n = 0}    */

/*  {L = [x_0, ..., x_(n-1)] ^ n >= 1}
    front(L: list) -> (e: elem)
    {e = x_0}   */ 

/*   {L = [x_0, ..., x_(n-1)] ^ n >= 1}
    back(L: list) -> (e: elem)
    {e = x_(n-1)}   */

/*   {L = [x_0, ..., x_(n-1)] ^ 0 <= i <= n}
    at(i : int, L: list) -> (e: elem)
    {e = x_i}   */

//Adicional: 

int contar_caracteres(const ListArray &l) {
    int suma = 0; 
    for (int i = 0; i < l.size(); i++) {
        suma += l.at(i).length(); 
        }
            return suma; 
    }


void ListArray :: display() const {
    cout << "["; 
    if (num_elems > 0) {
        cout << elems[0]; 
        for (int i = 1; i < num_elems; i++) {
            cout << ", " << elems[i]; 
        }
    }
    cout << "]" << endl; 
}

int main(){
    //declaramos un objeto de la clase
    ListArray l; 

    l.display();

    //introducimos elementos en el array
    l.push_back("David"); 
    l.push_back("Maria");
    l.push_back("Elvira");

    //Ahora podemos trabajar con ello 

    //imprimirla entera
    l.display(); 

    //llamar a un elemento cualquiera
    cout << "El segundo elemento de la lista es: " << l.at(1) << endl; 

    //eliminar el primer elemento
    l.pop_front(); 
    l.display(); 

    return 0; 
}