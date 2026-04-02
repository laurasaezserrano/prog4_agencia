#ifndef ALOJAMIENTO_H_
#define ALOJAMIENTO_H_

typedef struct {
    char codigo[10];
    char nombre[50];
    char direccion[100];
    char tipo[20];
    char cod_ciudad[10];
    int  activo;
} Alojamiento;

void guardarAlojamiento(Alojamiento a);
void altaAlojamiento(void);
void bajaAlojamiento(void);
void consultarAlojamiento(void);
void listadoAlojamientos(void);
void menuAlojamiento(void);

#endif
