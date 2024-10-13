#include <iostream>
#include <string>
using namespace std;

// Estructura para un empleado
struct nodo {
    int codigo;
    string nombre;
    float salario;
    nodo* siguiente;
    nodo* atras;
};

// Funcion para crear un nuevo nodo de empleado
nodo* crearEmpleado(int codigo, string nombre, float salario) {
    nodo* nuevo = new nodo();
    nuevo->codigo = codigo;
    nuevo->nombre = nombre;
    nuevo->salario = salario;
    nuevo->siguiente = nullptr;
    nuevo->atras = nullptr;
    return nuevo;
}


void insertarOrdenado(nodo*& cabeza, nodo* nuevo) {
    if (cabeza == nullptr) {
        
        cabeza = nuevo;
    }
    else if (nuevo->codigo < cabeza->codigo) {
        
        nuevo->siguiente = cabeza;
        cabeza->atras = nuevo;
        cabeza = nuevo;
    }
    else {
        // Buscar la posición correcta para insertar el nuevo empleado
        nodo* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->codigo < nuevo->codigo) {
            actual = actual->siguiente;
        }
        // Insertar el nuevo empleado en la posición correcta
        nuevo->siguiente = actual->siguiente;
        if (actual->siguiente != nullptr) {
            actual->siguiente->atras = nuevo;
        }
        actual->siguiente = nuevo;
        nuevo->atras = actual;
    }
}


void imprimirLista(nodo* cabeza) {
    nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << "Codigo: " << actual->codigo << ", Nombre: " << actual->nombre << ", Salario: $" << actual->salario << endl;
        actual = actual->siguiente;
    }
}

int main() {
    nodo* cabeza = nullptr;

    int codigo;
    string nombre;
    float salario;
    char opcion;

    do {
        cout << "Ingrese el codigo del empleado: ";
        cin >> codigo;
        cout << "Ingrese el nombre del empleado: ";
        cin >> nombre;
        cout << "Ingrese el salario del empleado: $";
        cin >> salario;

        nodo* nuevo = crearEmpleado(codigo, nombre, salario);
        insertarOrdenado(cabeza, nuevo);

        cout << "Desea ingresar otro empleado? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    // muesta la lista de empleados
    cout << "\nLista de empleados:\n";
    imprimirLista(cabeza);

    return 0;
}
