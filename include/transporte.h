#ifndef TRANSPORTE_H_
#define TRANSPORTE_H_

typedef struct {
    char codigo[10];
    char tipo[20];        // avion, tren, autobus...
    char fecha_salida[11];
    char fecha_llegada[11];
    int  cod_paquete;
    int  activo;
} Transporte;


#endif /* TRANSPORTE_H_ */
