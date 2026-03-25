#ifndef PAQUETE_H_
#define PAQUETE_H_

typedef struct {
    int  cod;
    char nombre[50];
    float precio;
    char cod_ciudad_origen[10];
    char cod_ciudad_destino[10];
    int  plazas_totales;
    int  plazas_disponibles;
    int  activo;
} Paquete;


#endif /* PAQUETE_H_ */
