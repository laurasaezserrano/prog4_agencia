#include <stdio.h>
#include "config.h"
#include "db.h"
#include "auth.h"
#include "menu.h"

int main() {
    Config cfg;
    sqlite3 *db;

    if (cargar_config("data/config.ini", &cfg) != 0) {
        printf("Error cargando configuración\n");
        return 1;
    }

    if (db_abrir(&db, cfg.db_path) != 0) {
        printf("Error abriendo base de datos\n");
        return 1;
    }

    db_crear_tablas(db);

    if (!login_admin(db)) {
        printf("Acceso denegado\n");
        return 1;
    }

    mostrar_menu(db);

    db_cerrar(db);

    return 0;
}
