#include <stdio.h>
#include "../include/config.h"
#include "../include/db.h"
#include "../include/auth.h"
#include "../include/menu.h"

int main() {
    setbuf(stdout, NULL);

    printf("Inicio del programa...\n");

    Config cfg;
    sqlite3 *db;

    if (cargar_config("data/config.ini", &cfg) != 0) {
        printf("Error cargando configuración\n");
        return 1;
    }

    printf("Config cargada\n");

    if (db_abrir(&db, cfg.db_path) != 0) {
        printf("Error abriendo base de datos\n");
        return 1;
    }

    printf("BD abierta\n");

    db_crear_tablas(db);

    printf("Entrando en login...\n");

    if (!login_admin(db)) {
        printf("Acceso denegado\n");
        db_cerrar(db);
        return 1;
    }

    printf("Login correcto\n");

    mostrar_menu(db);

    db_cerrar(db);

    printf("Fin del programa\n");

    return 0;
}
