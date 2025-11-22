#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};
enum Mes{ENERO, FEBERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE};
enum TipoContacto {AMIGO, FAMILIA, TRABAJO, CONOCIDO};

struct Persona{
    char nombre[30];
    char apellido[30];
    enum Mes mes_nac;
    char dia_nac[3];
    enum TipoContacto tip_cont;
    char num_tel[11];
    enum TipoTelefono tip_tel;
};

typedef struct Persona Contacto;

typedef struct Agenda{
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos; //Lleva la cuenta de cuantos contactos están en la agenda
} Agenda;


void iniciar_agenda(Agenda *agenda);
int agregar_contacto(Agenda *agenda);
int imprimir_agenda(Agenda agenda);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char *telefono);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);
void mostrar_contacto(Contacto);
void leer_contacto(Contacto *c);
void cargar_contactos(char *filename, Agenda *agenda);
void guardar_contactos(char *filename, Agenda);

#endif // __AGENDA_H_