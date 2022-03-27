//Implementación del TAD Lista enlazadas simples
#include <iostream>
#include <assert.h> 
using namespace std; 

class ListaEnlazadaSimple {
    public: 
        ListaEnlazadaSimple(): head(nullptr) {}

        ~ListaEnlazadaSimple() {
            delete_list(head);
        }

        void push_front(const string &elem);
        void pop_front(); 
        void push_back(const string &elem); 
        void pop_back(const string &elem); 

        //primer elemento
        const string & front() const {
            assert(head != nullptr); 
            return head -> value; 
        }
        
        string & front() {
            assert(head != nullptr); 
            return head -> value; 
        }

        //ultimo elemento
        const string & back() const {
            assert(head != nullptr); 
            return last_nodo() -> value; 
        }

        string & back() {
            assert(head != nullptr); 
            return last_nodo() -> value; 
        }
    
        const string & at(int indice) const {
            Nodo *nodo_resultado = indice_nodo(indice);
            assert (nodo_resultado != nullptr);
            return nodo_resultado -> value;
        }

        //esta version permite alterar la lista
        string & at(int indice) {
            Nodo *nodo_resultado = indice_nodo(indice);
            assert (nodo_resultado != nullptr);
            return nodo_resultado -> value;
        }


        int size() const; 
        
        bool empty() const {
            return head == nullptr;
        }

        void display() const; 

    private:
        struct Nodo {
            string value; 
            Nodo *next;
        }; 
        
        Nodo *head; //unico atributo con un puntero al primer nodo de la lista llamado cabeza. Si la lista está vacía head no apunta a nada y vale nullptr.  

        //Dentro de mis diferentes metodos, a menudo necesito llegar al ultimo nodo, para no repetir codigo, creamos un metodo privado que haga esto y pueda ser invocado. 
        Nodo *last_nodo() const; 
        Nodo *indice_nodo(int indice) const; 

        void delete_list(Nodo *nodo_inicial) {
            if (nodo_inicial != nullptr) {
                delete_list(nodo_inicial -> next); 
                delete nodo_inicial; 
            }
        }

};


ListaEnlazadaSimple :: Nodo * ListaEnlazadaSimple :: last_nodo() const {
    assert (head != nullptr); //no es vacía
    Nodo *actual = head; 
    while (actual -> next != nullptr) {
        actual = actual -> next; 
    }
    return actual; 
}



ListaEnlazadaSimple :: Nodo * ListaEnlazadaSimple :: indice_nodo(int indice) const {
    assert(indice >= 0); 
    int indice_actual = 0; 
    Nodo *actual = head; 

    while(actual != nullptr && indice_actual < indice) {
        indice_actual++; 
        actual = actual -> next; 
    }
    return actual;
}


int ListaEnlazadaSimple :: size() const {
    assert(head != nullptr);
    int len = 0; 
    Nodo *actual = head; 

    while (actual -> next != nullptr) {
        len++;
        actual = actual -> next;
    }
    
    return len; 
}


//pone un nuevo elemento al principio de la lista
void ListaEnlazadaSimple :: push_front(const string &elem) {
    Nodo *new_nodo = new Nodo { elem, head }; 
    head = new_nodo; 
}

//elimina el primer elemento
void ListaEnlazadaSimple :: pop_front() {
    assert (head != nullptr);
    Nodo *old_head = head; 
    head = head -> next; //actualizamos el atributo head para que apunte a next
    delete old_head; 
}


//añadir elemento al final de la lista 
void ListaEnlazadaSimple :: push_back(const string &elem) {
    Nodo *new_nodo = new Nodo {elem, nullptr}; //creamos un nuevo nodo con el elemento nuevo y apuntando a nullptr pues debe ser el nuevo último. 
    if (head == nullptr) { //si la lista es vacía, pues asignamos a la cabeza este nuevo nodo
        head = new_nodo;
    } else {
        last_nodo() -> next = new_nodo; 
    } 
}

void ListaEnlazadaSimple :: pop_back(const string &elem) {
    assert (head != nullptr); 
    if (head -> next == nullptr) {
        delete head; 
        head = nullptr; 
    } else {
        Nodo *previo = head; 
        Nodo *actual = head -> next; 

        while (actual -> next != nullptr) {
            previo = actual; 
            actual = actual -> next;
        }

        delete actual; 
        previo -> next = nullptr; 
    }
}

/*
void ListaEnlazadaSimple :: display() const {
    cout << "[" ; 
    if (head == nullptr) {
        cout << "]";
    } else {
        cout << head -> value; 
        Nodo *actual = head; 
        while(head -> next != nullptr) {
            cout << "," << actual -> value; 
            actual = actual -> next; 
        }
        cout << "]";
    }
}
*/

void ListaEnlazadaSimple :: display() const {
    cout << "[";
    if (head != nullptr) {
        cout << head -> value; 
        Nodo *actual = head -> next; 
        while (actual != nullptr) {
            cout << "," << actual -> value; 
            actual = actual -> next; 
        }
    }
    cout << "]" << endl;
}


int main(){
    
    //declaramos un objeto de la clase
    ListaEnlazadaSimple l; 
    
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