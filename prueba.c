#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo
{
       int info;
       nodo *sig;
};

void inicializar(nodo *&frente);
void insertar(nodo *&frente,int x);
int borrar(nodo *&frente);

main()
{
    nodo *frente,*p;
    int i,n,x;

    inicializar(frente);

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d",&n);

    for (i=0;i<n;i++)
    {
        printf("\n");
        printf("Numero: ");
        scanf("%d",&x);
        insertar(frente,x);
    }


    printf("\n\nSE BORRA EL REGISTRO :%d\n\n",borrar(frente));


    p=frente;
    while (p!=NULL)
    {
          printf("\n%d",p->info);
          p=p->sig;
    }

    getch();

}

void inicializar(nodo *&frente)
{
     frente=NULL;
}

void insertar(nodo *&frente,int x)
{
     nodo *p;
     p=new nodo;

     if (p!=NULL)
     {
           p->info=x;
           p->sig=frente;
           frente=p;
     }
     else
            printf("ERROR - PILA LLENA");
}

int borrar(nodo *&frente)
{
     if (frente!=NULL)
     {
             nodo *p;
             int x;
             p=frente;
             x=frente->info;
             frente=frente->sig;
             delete p;
             return x;
     }
     else
     {
             printf("ERROR - PILA VACIA");
             return 0;
     }
}
