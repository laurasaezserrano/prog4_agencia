#include <stdio.h>
#include "../include/config.h"
#include "../include/db.h"
#include "../include/auth.h"
#include "../include/menu.h"

int main() {
    printf("Inicio del programa...\n");

    Config cfg;
    sqlite3 *db;

    printf("Cargando configuración...\n");
    if (cargar_config("data/config.ini", &cfg) != 0) {
        printf("Error cargando configuración\n");
        getchar();
        return 1;
    }
    printf("Configuración cargada\n");
    printf("DB_PATH=[%s]\n", cfg.db_path);

    printf("Abriendo base de datos...\n");
    if (db_abrir(&db, cfg.db_path) != 0) {
        printf("Error abriendo base de datos\n");
        getchar();
        return 1;
    }
    printf("Base de datos abierta\n");

    printf("Creando tablas...\n");
    db_crear_tablas(db);
    printf("Tablas listas\n");

    printf("Entrando en login...\n");
    if (!login_admin(db)) {
        printf("Acceso denegado\n");
        db_cerrar(db);
        getchar();
        return 1;
    }
    printf("Login correcto\n");

    printf("Mostrando menú...\n");
    mostrar_menu(db);

    printf("Cerrando base de datos...\n");
    db_cerrar(db);

    printf("Fin del programa\n");
    getchar();
    return 0;
}
