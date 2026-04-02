#ifndef MENU_H_
#define MENU_H_

#include "sqlite3.h"

// Menú principal
void mostrar_menu(sqlite3 *db);

// Submenú Clientes
void menu_clientes(sqlite3 *db);
void listar_clientes(sqlite3 *db);
void agregar_cliente(sqlite3 *db);
void eliminar_cliente(sqlite3 *db);

// Submenú Paquetes
void listar_paquetes(sqlite3 *db);
void agregar_paquete(sqlite3 *db);
void eliminar_paquete(sqlite3 *db);

// Base de datos
void inicializar_db(sqlite3 *db);

#endif /* MENU_H_ */
