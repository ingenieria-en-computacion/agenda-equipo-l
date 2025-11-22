#include "agenda.h"
#include<stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    Agenda ag_1;
    int dec;
    int n;
    printf("Cuenta con una agenda\n 1.Si 2.No");
    scanf("%d",&dec);
    if(dec%2){
        if(argc<2){ printf("no se añadio el archivo junto con el ejecutable");return 0;}

        FILE *ag_ex= fopen(argv[1], "rb");
        if (!ag_ex) {
            printf("Error fatal: no existe el archivo o el directorio \"%s\"\n", argv[1]);
            return EXIT_FAILURE;
        }

        //cargar_contactos(/*&ag_ex*/);
    }else{
        iniciar_agenda(&ag_1);
    }
    while(true){
        printf("\tMENU \n1.Agregar contacto\n 2.Mostrar Agenda\n3.Buscar Contacto por nombre\n4. Buscar Contacto por telefono\n5.Guardar Contactos\n6.Salir\n");
        scanf("%d", &dec);

        switch (dec)
        {
        case 1:
            agregar_contacto(&ag_1);
            break;
        case 2:
            imprimir_agenda(ag_1);
            break;
        case 3:
            char buscador[30];
            printf("ingresa el nombre del contacto a buscar");
            scanf("%s", &buscador);
            n = buscar_contacto(&ag_1, buscador);
            printf("Su contacto es el numero %i", n);
            break;
        case 4:
            char buscador_num[11];
            printf("ingresa el telefono del contacto a buscar");
            scanf("%s", &buscador);
            n =buscar_contacto_x_telefono(&ag_1, buscador_num);
            printf("Su contacto es el numero %i", n);
            break;
        case 5:
            char archivo[30];
            printf("ingresa el nombre del archivo a crear");
            scanf("%s", &archivo);
            guardar_contactos(archivo, ag_1);
            break;
        case 6:
            return 0;
        break;
    
        default:
        break;
        }

    }
}