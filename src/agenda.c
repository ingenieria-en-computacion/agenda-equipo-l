#include "agenda.h"

const char * nom_TipoTelefono[] = {"CASA", "MOVIL", "OFICINA", "OTRO"};
const char * nom_mes[]={"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMPBRE"};

/**
 * Esta función se encarga de iniciar el número de contactos a cero.
 */
void iniciar_agenda(Agenda *agenda){
    agenda->num_contactos = 0;
}



// Varible que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos;

/**
 * Esta función sirve para agregar un contacto nuevo en la agenda
 */
int agregar_contacto(Agenda *agenda, Contacto c){
    agenda->num_contactos ++;
    if(agenda->num_contactos>MAX_CONTACTOS){
        printf("Se ha alcanzado el numero maximo");
        return EXIT_FAILURE;
    }
    agenda->contactos[agenda->num_contactos-1] = c;
    return 0;
}


/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si exisite
 * En caso contrario retorna -1
 */
int buscar_contacto(Agenda *agenda, char *nombre){
    for(int i = 0; i < agenda->num_contactos; i++) {
        if(strcmp(agenda->contactos[i].nombre, nombre) == 0) {
            mostrar_contacto(agenda->contactos[i]);
            return i;
        }
    }
    return -1;

}


/**
 * Esta función  sirve para buscar un contacto por su número de telefono en la agenda
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){
    for(int i = 0; i < agenda->num_contactos; i++) {
        if(strcmp(agenda->contactos[i].telefono, telefono) == 0) {
            mostrar_contacto(agenda->contactos[i]);
            return i;
        }
    }
    return -1;
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
    
    for(int i = 0; i < a->num_contactos - 1; i++) {
        for(int j = 0; j < a->num_contactos - 1 - i; j++) {
            if(strcasecmp(a->contactos[j].nombre, a->contactos[j+1].nombre) < 0) {
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }

}


/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contacto(Contacto c){
    printf("%s\t", c.nombre);
    printf("%s\t", c.apellido);
    
    
    printf("%s/%s \t", nom_mes[c.mes_nac - 1], c.dia_nac);
    /* printf("%i \t", c.tip_cont);*/
    printf("%s: %s \t\n", nom_TipoTelefono[c.tip_tel - 1], c.telefono);

}


/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c){
    int n;
    printf("Ingrese el nombre del contacto:\n");
    scanf("%s",&c->nombre);
    
    printf("Ingrese el apellido del contacto:\n");
    scanf("%s",&c->apellido);

    printf("Ingrese el mes de nacimiento del contacto:\n");
    scanf("%d",&n);
    c->mes_nac = n;
    

    printf("Ingrese el dia de nacimiento del contacto:\n");
    scanf("%s",&c->dia_nac);

    /*printf("Que tipo de contacto es:\n1.Amigo\n2.Familia\n3.Trabajo\n4.Conocido\n");
    scanf("%d",&n);
    c->tip_cont = n;*/

    printf("Ingrese el numero de telefono del contacto:\n");
    scanf("%s",&c->telefono);

    printf("Que tipo de telefono es:\n1.Casa\n2.Movil\n3.Oficina\n4.Otro\n");
    scanf("%d",&c->tip_tel);

}

/**
 * Función que imprime todos los contactos de la agenda en pantalla
 */
int imprimir_agenda(Agenda agenda){
    int dec;
    if(agenda.num_contactos == 0){
        printf("\n[!] No hay contactos en la agenda.\n");
        return EXIT_FAILURE;
    }
    

    
    printf("\n LISTA DE CONTACTOS \n");
    printf("Total de contactos: %d\n\n", agenda.num_contactos);
    
    for(int i = 0; i < agenda.num_contactos; i++){
        printf("#%d", i + 1);
        mostrar_contacto(agenda.contactos[i]);
    }

    
    return 0;
}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
int cargar_contactos(char *filename, Agenda *agenda){
    FILE *archivo = fopen(filename, "r");

    if(archivo == NULL){
        printf("\n Error: No se pudo abrir el archivo '%s'\n", filename);
        return EXIT_FAILURE;

}

    if(fscanf(archivo, "%d\n", &agenda->num_contactos) != 1){
        printf("\n Error al leer el archivo.\n");
        fclose(archivo);
        return EXIT_FAILURE;
    }

    if(agenda->num_contactos > MAX_CONTACTOS){
        printf("\n[!] El archivo contiene mas contactos que el maximo permitido.\n");
        agenda->num_contactos = MAX_CONTACTOS;
    }


    for(int i = 0; i < agenda->num_contactos; i++){
        fscanf(archivo, "%s\n", agenda->contactos[i].nombre);
        fscanf(archivo, "%s\n", agenda->contactos[i].apellido);
        fscanf(archivo, "%d\n", (int*)&agenda->contactos[i].mes_nac);
        fscanf(archivo, "%s\n", agenda->contactos[i].dia_nac);
        fscanf(archivo, "%s\n", agenda->contactos[i].telefono);
        fscanf(archivo, "%d\n", (int*)&agenda->contactos[i].tip_tel);
    }

    fclose(archivo);
    printf("\n[+] %d contactos cargados exitosamente desde '%s'\n", 
    agenda->num_contactos, filename);


}


/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda a){

}
