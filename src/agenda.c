#include "agenda.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Esta función se encarga de iniciar el número de contactos a cero.
 */
void iniciar_agenda(Agenda *agenda){

    int n;
    *agenda->num_contactos = 0;
    printf("Cuantos contactos desea agregar para comenzar su agenda:\n");
    scanf("%d",&n);
    for(int i; i<n; i++){
        agregar_contacto(agenda);
    }
}



// Varible que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos;

/**
 * Esta función sirve para agregar un contacto nuevo en la agenda
 */
void agregar_contacto(Agenda *agenda){
    Contacto c;
    *agenda->num_contactos ++;
    if(agenda->num_contactos>MAX_CONTACTOS){
        printf("Se ha alcanzado el numero maximo");
        return EXIT_FAILURE;
    }
    leer_contacto(&c);
    memcpy(agenda->contactos[MAX_CONTACTOS-1], &c, sizeof(c));
}


/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si exisite
 * En caso contrario retorna -1
 */
int buscar_contacto(Agenda *agenda, char *nombre){
     for(int i = 0; i < agenda->cantidad; i++) {
        if(strcmp(agenda->contactos[i].nombre, nombre) == 0) {
            mostrar_contacto(agenda->contactos[i]);
            return i;
        }
    }
    return -1;

}


/**
 * Esta función  sirve para buscar un contacto por su número de telefono en la agenda
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){
    for(int i = 0; i < agenda->cantidad; i++) {
        if(strcmp(agenda->contactos[i].telefono, telefono) == 0) {
            mostrar_contacto(agenda->contactos[i]);
            return i;
        }
    }
    return -1;
}


/**
 * Esta función sirve para ordenar los contactos por nombres de forma ascendente
 */
void ordenar_contactos(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)>0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma descendente
 */
void ordenar_contactos_inv(Agenda *a){
    Contacto temp;
    
    for(int i = 0; i < agenda->cantidad - 1; i++) {
        for(int j = 0; j < agenda->cantidad - 1 - i; j++) {
            if(strcasecmp(agenda->contactos[j].apellido, 
                         agenda->contactos[j+1].apellido) < 0) {
                temp = agenda->contactos[j];
                agenda->contactos[j] = agenda->contactos[j+1];
                agenda->contactos[j+1] = temp;
            }
        }
    }

}


/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contacto(Contacto){

}


/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c){


}

/**
 * Función que imprime todos los contactos de la agenda en pantalla
 */
void imprimir_agenda(Agenda agenda){

}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
void cargar_contactos(char *filename, Agenda *agenda){

}


/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda agenda){

}
