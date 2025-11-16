#include "agenda.h"
#include<stdio.h>

int main(int argc, char **argv){
    Agenda ag_1;
    int dec;
    printf("Cuenta con una agenda\n 1.Si 2.No");
    scanf("%d",&dec);
    if(dec%2){
        if(argc<2){ printf("no se añadio el archivo junto con el ejecutable");return 0;}

        FILE *ag_ex= fopen(argv[1], "rb");
        if (!datos) {
            printf("Error fatal: no existe el archivo o el directorio \"%s\"\n", argv[1]);
            return EXIT_FAILURE;
        }

        cargar_contactos(/*&ag_ex*/);
    }else{
        iniciar_agenda(&ag_1);
    }
    while(true){
        printf("\tMENU \n1.Agregar contacto\n 2.Mostrar Agenda\n3.Buscar Contacto \n4.Guardar Contactos\n5.Salir\n");
        scanf("%d"&dec);

        switch (dec)
        {
        case 1:
            agregar_contacto(&ag_1);
            break;
        case 2:
            imprimir_agenda(ag_1);
            break;
        case 3:
            char buscador[];
            printf("ingresa el nombre del contacto a buscar");
            scanf("%s"&buscador);
            agregar_contacto(&ag_1, &buscador);
            break;
        case 4:
            char archivo[];
            printf("ingresa el nombre del archivo a crear");
            scanf("%s"&archivo);
            agregar_contacto(archivo);
            break;
        case 5:
            return 0;
        break;
    
        default:
        break;
    }

    }
}