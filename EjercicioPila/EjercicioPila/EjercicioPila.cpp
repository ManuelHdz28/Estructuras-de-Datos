#include <iostream>
#include <conio.h>
#define longitud 5 //longitud de la pila
#define cantidad 20

using namespace std;

//definiendo la estructura de la pila
typedef struct {
    int numero;
    char placa[cantidad];
    char lugar[cantidad];
    char tipoInfraccion[cantidad];
    float monto;
    char fecha[cantidad];
}Pila;

//definiciendo la estructura de la pila
typedef struct {
    int tope;
    Pila arreglo[longitud];
}Pila;

//prototipo de la funcion
void iniciarPila(Pila* p);
void agregarElemento(Pila *p);
void pilaLlena(Pila* p);
void pilaVacia(Pila* p);
void MostrarMultas(Pila* p);

int main()
{
    Pila p;
    iniciarPila(&p);
    int opcion;

    void iniciarPila(Pila * p){ // se inicializa la pila
        p->tope = -1;
    }

    bool pilaVacia(Pila* p) {
        return p->tope == -1;
    }

    bool pilaLlena(Pila* p) {
        return p->tope == (lomgitud - 1);
    }

    void agregarElemento(pila* p) {
        
    }

    
}
