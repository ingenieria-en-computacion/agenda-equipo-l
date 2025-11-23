#include "agenda.h"


int main(int argc, char **argv){
    Agenda ag_1;
    int dec;
    int n;
    Contacto temp;
    printf("Cuenta con una agenda\n 1.Si 2.No\n");
    scanf("%d",&dec);
    if(dec%2){
        cargar_contactos("imprimir.txt", &ag_1);
    }else{
        iniciar_agenda(&ag_1);
        printf("Cuantos contactos desea agregar para comenzar su agenda:\n");
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            leer_contacto(&temp);
            agregar_contacto(&ag_1, temp);
        }
    }
    while(true){
        printf("\tMENU \n1.Agregar contacto\n2.Mostrar Agenda\n3.Buscar Contacto por nombre\n4. Buscar Contacto por telefono\n5.Guardar Contactos\n6.Orden\n7.Salir");
        scanf("%d", &dec);

        switch (dec)
        {
        case 1:
            leer_contacto(&temp);
            agregar_contacto(&ag_1, temp);
            break;
        case 2:
            imprimir_agenda(ag_1);
            break;
        case 3:
            char buscador[30];
            printf("ingresa el nombre del contacto a buscar\n");
            scanf("%s", &buscador);
            n = buscar_contacto(&ag_1, buscador);
            printf("Su contacto es el numero %i\n", n);
            break;
        case 4:
            char buscador_num[11];
            printf("ingresa el telefono del contacto a buscar\n");
            scanf("%s", &buscador);
            n =buscar_contacto_x_telefono(&ag_1, buscador_num);
            printf("Su contacto es el numero %i\n", n);
            break;
        case 5:
            char archivo[30];
            printf("ingresa el nombre del archivo a crear\n");
            scanf("%s", &archivo);
            guardar_contactos(archivo, ag_1);
            break;
        case 6:
            printf("De que manera desea ordenar la lista:\n 1.A-Z\n 2.Z-A\n 3.Salir\n");
            scanf("%d",&dec);
            switch (dec)
            {
            case 1:
                ordenar_contactos(&ag_1);
                break;
            case 2:
                ordenar_contactos_inv(&ag_1);
                break;
            case 3:
                
                break;
            }
        
        break;
        default:
            return 0;
        break;
        }

    }
}
