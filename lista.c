#include <stdio.h>
#include <stdlib.h>

/*
LISTAS ENLAZADAS




Funciones de la lista

1- Añadir nodo (principio o final);
2- Añadir nodo en posición específica
3- Imprimir la la lista
4- Borrar nodo en específico







*/

/*___________________ESTRUCTURAS_____________________*/
//Acá van las estruccturas

//Elemento 
typedef struct Pelicula{
    char *title;
    char *gender;
    int year;
    
}Peli;

//Creamos la estrucctura nodo

typedef struct Nodo{
    Peli *peli;
    struct Nodo *sig;
}Nodo;

//Creamos la estrucctura lista

typedef struct Lista{
    Nodo *cabeza;
    char *nombre;
    int longitud;
}Lista;


/*___________________________________________________*/


/*___________________PROTOTIPOS______________________*/

//Acá van los prototipos
void iniciarLista(Lista *lista);
Lista *crearLista(char *nombre);
Nodo *crearNodo(Peli *peli);
Peli *crearPeli(char *title, char *gender, int year);
void insertarNodo(Lista *lista, Peli *peli);
void imprimir(Lista *lista);
void eliminarNodo(Lista *lista, int pos);
void destruirNodo(Nodo *nodo);
void contar(Lista *lista);
void imprimirNodo(Lista *lista, int pos);


/*__________________________________________________*/


/*___________________________________________________*/


int main() {
      //creamos la lista y la iniciamos
    
    Lista *lista1=crearLista("Lista de prueba");
    Lista *lista2=crearLista("Peliculas Favoritas");
    Lista *pAction=crearLista("Películas de acción");
    
    
    //Creamos un nuevo elemento
    
    Peli *p1=crearPeli("Avengers End Game","Acción",2019);
    Peli *p2=crearPeli("Shrek 1","Comedia",2002);
    Peli *p3=crearPeli("El círculo","Terror",2015);
    Peli *p4=crearPeli("The Lord of Rings","Fantasía",2003);
    Peli *p5=crearPeli("The Jocker","Drama",2019);
    Peli *p6=crearPeli("John Wick","Acción",2017);
    
    //Añadimos los nodos a la lista
    
    insertarNodo(lista1,p1);
    insertarNodo(lista1,p2);
    insertarNodo(lista1,p3);
    insertarNodo(lista1,p4);
    insertarNodo(lista1,p5);
    
    insertarNodo(lista2,p1);
    insertarNodo(lista2,p2);
    insertarNodo(lista2,p4);
    
    insertarNodo(pAction,p6);
    
    
    //Imprimimos la lista
    
    imprimir(lista1);
    imprimir(pAction);
    
    //puts("_____________________________________\n\n");
    
    //eliminarNodo(lista1,4);
    
    //imprimir(lista1);
    //imprimirNodo(lista1,1);
    


    return 0;
}


/*___________________________________________________*/


/*______________FUNCIONES Y PROCEDIMIENTOS__________*/

//Desarrollo de los prototipos
//Inicia la lista
void iniciarLista(Lista *lista){
    lista->cabeza=NULL;
}

//Crea un nodo
Nodo *crearNodo(Peli *peli){
    Nodo *nodo=(Nodo*)malloc(sizeof(Nodo));
    
    nodo->peli=peli;
    
    return nodo;
}

//Crea un elemento

Peli *crearPeli(char *title, char *gender, int year){
    Peli *nPeli=(Peli*)malloc(sizeof(Peli));
    
    nPeli->title=title;
    nPeli->gender=gender;
    nPeli->year=year;
    
    
    return nPeli;
}

//Insertar un elemento

void insertarNodo(Lista *lista, Peli *peli){
    Nodo *nodo=crearNodo(peli);
    
    if(lista->cabeza==NULL){
        lista->cabeza=nodo;
        nodo->sig=NULL;
    }else{
        Nodo *puntero=lista->cabeza;
        
        while(puntero->sig){
            puntero=puntero->sig;
        }
        puntero->sig=nodo;
        nodo->sig=NULL;
    }
    lista->longitud++;
}
//Contar lista
void contar(Lista *lista){
    printf("Longitud de la lista: %i\n\n", lista->longitud);
}




//Destruir nodo
void destruirNodo(Nodo *nodo){
    free(nodo);
}

//Elimina un nodo
void eliminarNodo(Lista *lista, int pos){
    if(lista->cabeza==NULL){
        printf("La lista está vacía\n");
    }else if(lista->longitud==1){
        Nodo *eliminado=lista->cabeza;
        lista->cabeza=lista->cabeza->sig;
        destruirNodo(eliminado);
        lista->longitud--;
    }else if(pos==lista->longitud){
        Nodo *puntero=lista->cabeza;
        int nodoAnterior=lista->longitud-1;
        int posicion=1;
        while(posicion!=nodoAnterior){
            puntero=puntero->sig;
            posicion++;
        }
        Nodo *eliminado=puntero->sig;
        puntero->sig=NULL;
        destruirNodo(eliminado);
        
        lista->longitud--;
        
    }else if(pos>lista->longitud){
        printf("La lista no tiene tantos nodos\n");
        contar(lista);
    }else{
       Nodo *puntero=lista->cabeza;
       int posicion=1;
       if (pos-1==0){
           Nodo *eliminado=puntero;
           lista->cabeza=puntero->sig;
           destruirNodo(eliminado);
           lista->longitud--;
       }else if(pos==0){
           printf("La posición empieza a contar desde uno\n\n");
       }else{
           
           while(posicion!=pos-1){
           puntero=puntero->sig;
           posicion++;
           
           }
           if(pos==posicion){
               Nodo *eliminado=puntero;
               lista->cabeza=puntero->sig;
               destruirNodo(eliminado);
               lista->longitud--;
           }else{
               Nodo *eliminado=puntero->sig;
               puntero->sig=puntero->sig->sig;
               destruirNodo(eliminado);
               lista->longitud--;
           }
           
       }
       
    }
    
}




//imprime la lista
void imprimir(Lista *lista){
    if (lista->cabeza==NULL){
        printf("La lista está vacía\n");
    }else{
        Nodo *puntero=lista->cabeza;
        int i=1;
        puts("-------------------------------");
        printf("%s",lista->nombre);
        while(puntero!=NULL){
            //puts("-------------------------------");
            printf("\n\nNodo:%i\nPelícula: %s\nAño: %i\nGénero:%s\n\n",i,puntero->peli->title, puntero->peli->year,puntero->peli->gender);
            puts("-------------------------------");
            puntero=puntero->sig;
            i++;
        }
    }
}

//Crea Lista
Lista *crearLista(char *nombre){
    Lista *nlista=(Lista*)malloc(sizeof(Lista));
    nlista->nombre=nombre;
    iniciarLista(nlista);
    
    return nlista;
}

//Imprime nodo específico
void imprimirNodo(Lista *lista, int pos){
    if(lista->cabeza==NULL){
        printf("Nodo no encontrado\n\nLISTA VACIA");
    }else if(pos>lista->longitud || pos<=0){
        printf("La lista no tiene tantos nodos, ni tiene nodo 0. Empieza a contar del nodo 1\n\n");
        contar(lista);
    }else{
        Nodo *puntero=lista->cabeza;
        int contador=1;
        
        while(contador!=pos){
            puntero=puntero->sig;
            contador++;
        }
        puts("-------------------------------");
        printf("\n\nNodo:%i\nPelícula: %s\nAño: %i\n\n",pos,puntero->peli->title, puntero->peli->year);
        puts("-------------------------------");
    }
}


/*___________________________________________________*/


