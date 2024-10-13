#include <iostream>
#include <string>

using namespace std;

struct Cliente //definicion de la estructura cliente
{
    string nombre;
    int numeroCuenta;
    string dui;
    char tipoTransaccion; // se usara un determinante "a" para abonar y "c" para el cargo
    double montoTransaccion;
};

//definicion de las constantes (las colas y el maximo de elementos)
const int MAX_COLA1 = 6;
const int MAX_COLA2 = 3;
Cliente cola1[MAX_COLA1];
Cliente cola2[MAX_COLA2];
int frente1 = 0, final1 = 0, frente2 = 0, final2 = 0;
int elementosCola1 = 0, elementosCola2 = 0; // Contadores de elementos en cada cola


bool colaVacia(int elementos) { // funcion para verificar si la cola esta vacia
    return elementos == 0;
}

bool colaLlena(int elementos, int maxCola) {// funcion para verificar si la cola esta llena
    return elementos == maxCola;
}

void ingresarClienteaCola1() { // funcion que ingresa un cliente a la cola 1
    if (colaLlena(final1, MAX_COLA1))
    {
        cout << "la cola 1 esta llena, se transladara a los clientes a la cola 2 \n ";

        //translado a la cola 2
        int clientesATransladar = 3 - elementosCola2; // numero de clientes a transladar
        for (int i = 0; i < clientesATransladar && !colaLlena(elementosCola2, MAX_COLA2); i++)
        {
            cola2[final2++] = cola1[frente1++];
            frente1 = (frente1 + 1) % MAX_COLA1;
            final2 = (final2 + 1) % MAX_COLA2;
            elementosCola1 --;
            elementosCola2 ++;
        }
    }

    if (!colaLlena(elementosCola1, MAX_COLA1))
    {
        Cliente nuevo;
        cout << "Ingrese el nombre del cliente: ";
        cin >> nuevo.nombre;
        cout << "Ingrese el numero de cuenta: ";
        cin >> nuevo.numeroCuenta;
        cout << "Ingrese el DUI: ";
        cin >> nuevo.dui;
        cout << "Ingrese el tipo de transaccion (a para abono, c para cargo): ";
        cin >> nuevo.tipoTransaccion;
        cout << "Ingrese el monto de la transaccion: $";
        cin >> nuevo.montoTransaccion;
        cola1[final1++] = nuevo;
        final1 = (final1 + 1) % MAX_COLA1;
        elementosCola1++;
        cout << "Cliente ingresado en la Cola 1. \n";
    }
    else
    {
        cout << "La cola 1 sigue llena y no se pueden ingresar mas clientes. \n";
    }

}

// Funcion para rerirar un cliente de la cola 1
void retirarClienteDeCola1() {
    if (!colaVacia(elementosCola1)) {
        cout << "Retirando al cliente " << cola1[frente1].nombre << " de la cola 1.\n";
        frente1 = (frente1 + 1) % MAX_COLA1;
        elementosCola1--;
    }
    else {
        cout << "La cola 1 está vacía, no hay clientes para retirar.\n";
    }
}

// Funcion para rerirar un cliente de la cola 2
void retirarClienteDeCola2() {
    if (!colaVacia(elementosCola2)) { 
        cout << "Retirando al cliente " << cola2[frente2].nombre << " de la cola 2.\n"; 
        frente2 = (frente2 + 1) % MAX_COLA2; 
        elementosCola2--; 
    }
    else {
        cout << "La cola 2 está vacía, no hay clientes para retirar.\n"; 
    }
}


// funcion para mostrar clientes en la cola
void mostrarClientes(Cliente cola[], int frente, int elementos, int maxCola) { 
    if (colaVacia(elementos)) { 
        cout << "La cola está vacía.\n"; 
    }
    else {
        for (int i = 0; i < elementos; i++) { 
            int index = (frente + i) % maxCola; 
            cout << "Cliente: " << cola[index].nombre << ", Cuenta: " << cola[index].numeroCuenta << ", DUI: " << cola[index].dui << "\n";
            cout << "Tipo de Transaccion: " << (cola[index].tipoTransaccion == 'a' ? "Abono" : "Cargo") << ", Monto: $" << cola[index].montoTransaccion << "\n";
        }
    }
}


// menu prinsipal de la aplicacionn
void mostrarMenu() {
    cout << "Menu Principal. \n";
    cout << "1) Ingresar un Cliente en la Cola 1. \n";
    cout << "2) Retirar un Cliente en la Cola 1. \n";
    cout << "3) Retirar un Cliente en la Cola 2. \n";
    cout << "4) Mostrar Clientes en la cola 1. \n";
    cout << "5) Mostrar Clientes en la cola 2. \n";
    cout << "6) Salir. \n";
}


int main()
{
    int opcion;

    do
    {
        mostrarMenu();
        cout << "Seleccione Una Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1: 
            ingresarClienteaCola1();
            break;
        case 2:
            retirarClienteDeCola1();
            break;
        case 3:
            retirarClienteDeCola2();
            break;
        case 4:
            mostrarClientes(cola1, frente1, elementosCola1, MAX_COLA1); // muestra los clientes de la cola 1
            break;
        case 5:
            mostrarClientes(cola2, frente2, elementosCola2, MAX_COLA2); // muestra los clientes de la cola 2
            break;
        case 6:
            cout << "Saliendo del programa....... \n";
            break;
        default:
            cout << "Opcion NO Valida Ingrese de Nuevo. \n";
            break;
        }

    } while (opcion != 6);

    return 0;
}

