// PILAS.CPP Ejemplo 1

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define STACKSIZE 5

// Definicion de tipos de datos 
typedef char STACKELEMENT;
typedef struct {
    int top;
    STACKELEMENT items[STACKSIZE];
} STACK;

// prototipos de las funciones de la pila 
void Clear(STACK *);
int Empty(STACK *);
STACKELEMENT Pop(STACK *);
void Push(STACK*, STACKELEMENT);


int main()
{
    STACKELEMENT a;
    int p, i;
    STACK b;
    STACK *c = &b;
    b.top = -1;
    system("cls");

    // da la oportunidad de introducir o sacar elementos de la pila 5 veces 
    for (i = 0; i <= 0; i++){
        printf("Introducir o sacar de la pila (1. ingresar / 2. sacar / 3. salir) : ");
        scanf("%d", &p);
        fflush(stdin);

        if (p == 1) {
            printf("Elemento a indroducir: ");
            scanf("%c", &a);
            Push(c, a);
            printf("Elemento introducido con exito\n");
            getch();
        }
        //2. Sacar el elemento de la pila
        else {
            if (p == 2) {
                if (Empty(c)) {
                    printf("Error: pila vacia.\n");
                    getch();
                    exit(1);
                }
                else {
                    a = Pop(c);
                    printf("Elemento sacado de la pila: %c \n", a);
                    getch();
                }
            }// fin del if p == 2
            else
            {// salir
                if (p == 3) {
                    exit(1);
                }
                else
                {
                    printf("La proxima vez debe digitar 1, 2 o 3 \n", a);
                    getch();
                }
            }//Fin else (p==2)
        }// fin del else principal
    }// fin del for
}//fin del main


// Limpia la pila
void Clear(STACK * ps) {
    ps->top = -1;
}

// Verifica que la pila esta vacia
int Empty(STACK* ps) {
    if (ps -> top == 1) {
        return(TRUE);
    }
    else
    {
        return(FALSE);
    }
}

// verificar si la pila esta llena, si ya no pueden introducir mas elementos en el arreglo
int Full(STACK* ps) {
    if (ps->top == STACKSIZE - 1)
        return(TRUE);
    else
        return(FALSE);
}

// introduce un elemento en la pila
void Push(STACK* ps, STACKELEMENT x) {
    if (Full(ps)) {
        printf("%s", "pila desbordada");
        exit(1);
    }
    else {
        ps->items[++(ps->top)] = x;
    }
}

//quita un elento de la pila y lo devuelve
STACKELEMENT Pop(STACK* ps) {
    if (Empty(ps)) {
        printf("%s", "Pila subdesarrollada");
        exit(1);
    }
    return(ps->items[(ps->top)--]);
}
