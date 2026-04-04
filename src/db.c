#include <stdio.h>
#include "../include/sqlite3.h"
#include "../include/db.h"

int db_abrir(sqlite3 **db, const char *ruta) {
    if (sqlite3_open(ruta, db) != SQLITE_OK) {
        printf("Error al abrir la base de datos: %s\n", sqlite3_errmsg(*db));
        return 1;
    }
    return 0;
}

void db_cerrar(sqlite3 *db) {
    if (db != NULL) {
        sqlite3_close(db);
    }
}

int db_crear_tablas(sqlite3 *db) {
    char *err = NULL;

    const char *sql_admin =
        "CREATE TABLE IF NOT EXISTS administradores ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "usuario TEXT NOT NULL UNIQUE, "
        "clave TEXT NOT NULL"
        ");";

    const char *sql_clientes =
        "CREATE TABLE IF NOT EXISTS clientes ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "dni TEXT NOT NULL UNIQUE, "
        "nombre TEXT NOT NULL, "
        "apellidos TEXT NOT NULL, "
        "telefono TEXT, "
        "email TEXT, "
        "fecha_nacimiento TEXT, "
        "activo INTEGER NOT NULL DEFAULT 1"
        ");";

    const char *sql_alojamientos =
<<<<<<< HEAD
        "CREATE TABLE IF NOT EXISTS alojamientos ("
        "codigo TEXT PRIMARY KEY, "
        "nombre TEXT NOT NULL, "
        "direccion TEXT, "
        "tipo TEXT, "
        "cod_ciudad TEXT, "
        "activo INTEGER DEFAULT 1";
    	");";
=======
            "CREATE TABLE IF NOT EXISTS alojamientos ("
            "codigo TEXT PRIMARY KEY, "
            "nombre TEXT NOT NULL, "
            "direccion TEXT, "
            "tipo TEXT, "
            "cod_ciudad TEXT, "
            "activo INTEGER DEFAULT 1"
    		");";
>>>>>>> branch 'main' of git@github.com:laurasaezserrano/prog4_agencia.git

    const char *sql_paquetes =
<<<<<<< HEAD
        "CREATE TABLE IF NOT EXISTS paquetes ("
        "codigo INTEGER PRIMARY KEY, "
        "nombre TEXT NOT NULL, "
        "precio REAL, "
        "destino TEXT, "
        "origen TEXT, "
        "plazas_totales INTEGER, "
        "plazas_disponibles INTEGER, "
        "activo INTEGER DEFAULT 1";
    	");";
=======
            "CREATE TABLE IF NOT EXISTS paquetes ("
            "codigo INTEGER PRIMARY KEY, "
            "nombre TEXT NOT NULL, "
            "precio REAL, "
            "destino TEXT, "
            "origen TEXT, "
            "plazas_totales INTEGER, "
            "plazas_disponibles INTEGER, "
            "activo INTEGER DEFAULT 1"
    		");";
>>>>>>> branch 'main' of git@github.com:laurasaezserrano/prog4_agencia.git

    const char *sql_transportes =
<<<<<<< HEAD
        "CREATE TABLE IF NOT EXISTS transportes ("
        "codigo TEXT PRIMARY KEY, "
        "tipo TEXT, "
        "fecha_salida TEXT, "
        "fecha_llegada TEXT, "
        "id_paquete INTEGER, "
        "activo INTEGER DEFAULT 1, "
        "FOREIGN KEY(id_paquete) REFERENCES paquetes(codigo)";
        ");";
=======
            "CREATE TABLE IF NOT EXISTS transportes ("
            "codigo TEXT PRIMARY KEY, "
            "tipo TEXT, "
            "fecha_salida TEXT, "
            "fecha_llegada TEXT, "
            "id_paquete INTEGER, "
            "activo INTEGER DEFAULT 1, "
            "FOREIGN KEY(id_paquete) REFERENCES paquetes(codigo)"
            ");";
>>>>>>> branch 'main' of git@github.com:laurasaezserrano/prog4_agencia.git

    /* Admin por defecto */
    const char *sql_insert_admin =
        "INSERT OR IGNORE INTO administradores (id, usuario, clave) "
        "VALUES (1, 'admin', '1234');";

    if (sqlite3_exec(db, sql_admin, 0, 0, &err) != SQLITE_OK) {
        printf("Error SQL al crear administradores: %s\n", err);
        sqlite3_free(err);
        return 1;
    }

    if (sqlite3_exec(db, sql_clientes, 0, 0, &err) != SQLITE_OK) {
        printf("Error SQL al crear clientes: %s\n", err);
        sqlite3_free(err);
        return 1;
    }

    if (sqlite3_exec(db, sql_alojamientos, 0, 0, &err) != SQLITE_OK) {
            printf("Error SQL al crear alojamientos: %s\n", err);
            sqlite3_free(err);
            return 1;
        }

    if (sqlite3_exec(db, sql_paquetes, 0, 0, &err) != SQLITE_OK) {
            printf("Error SQL al crear paquetes: %s\n", err);
            sqlite3_free(err);
            return 1;
        }

    if (sqlite3_exec(db, sql_transportes, 0, 0, &err) != SQLITE_OK) {
            printf("Error SQL al crear transportes: %s\n", err);
            sqlite3_free(err);
            return 1;
        }

    if (sqlite3_exec(db, sql_insert_admin, 0, 0, &err) != SQLITE_OK) {
        printf("Error SQL al insertar admin: %s\n", err);
        sqlite3_free(err);
        return 1;
    }

    return 0;
}
