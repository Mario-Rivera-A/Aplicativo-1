#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_char_por_linea 1000
#define max_largo_nom_pizza 1000
#define max_orders 1000
typedef struct {
    char nombre[max_largo_nom_pizza];
    int cont;
} PizzaCount;

// Definición de la estructura Order
typedef struct {
    int pizza_id;
    int order_id;
    char pizza_name_id[max_largo_nom_pizza];
    int quantity;
    char order_date[11];
    char order_time[9];
    float unit_price;
    float total_price;
    char pizza_size;
    char pizza_category[max_largo_nom_pizza];
    char pizza_ingredients[500];
    char pizza_name[max_largo_nom_pizza];
} Order;

int pls() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    PizzaCount pizzas[max_char_por_linea];
    int num_pizzas = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener el nombre de la pizza
        token = strtok(line, ";");
        token = strtok(NULL, ";"); // Ignorar order_id
        token = strtok(NULL, ";"); // Ignorar pizza_name_id
        token = strtok(NULL, ";"); // Ignorar quantity
        token = strtok(NULL, ";"); // Ignorar order_date
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        token = strtok(NULL, ";"); // Ignorar total_price
        token = strtok(NULL, ";"); // Ignorar pizza_size
        token = strtok(NULL, ";"); // Ignorar pizza_category
        token = strtok(NULL, ";"); // Ignorar pizza_ingredients
        token = strtok(NULL, ";"); // Obtener pizza_name

        // Quitar el salto de línea del nombre
        token[strcspn(token, "\n")] = 0;

        // Verificar si la pizza ya está en la lista
        int found = 0;
        for (int i = 0; i < num_pizzas; i++) {
            if (strcmp(pizzas[i].nombre, token) == 0) {
                pizzas[i].cont++;
                found = 1;
                break; 
            }
        }

        // Si no está en la lista, añadirlo
        if (!found) {
            strcpy(pizzas[num_pizzas].nombre, token);
            pizzas[num_pizzas].cont = 1;
            num_pizzas++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    // Encontrar la cantidad mínima de ventas
    int min_ventas = pizzas[0].cont;
    for (int i = 1; i < num_pizzas; i++) {
        if (pizzas[i].cont < min_ventas) {
            min_ventas = pizzas[i].cont;
        }
    }

    // Imprimir las pizzas menos vendidas
    printf("Pizzas menos vendidas: ");
    for (int i = 1; i < num_pizzas; i++) {
        if (pizzas[i].cont == min_ventas) {
            printf("%s\n", pizzas[i].nombre);
        }
    }

    return 0;
}

int pms() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    PizzaCount pizzas[max_char_por_linea];
    int num_pizzas = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener el nombre de la pizza
        token = strtok(line, ";");
        token = strtok(NULL, ";"); // Ignorar order_id
        token = strtok(NULL, ";"); // Ignorar pizza_name_id
        token = strtok(NULL, ";"); // Ignorar quantity
        token = strtok(NULL, ";"); // Ignorar order_date
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        token = strtok(NULL, ";"); // Ignorar total_price
        token = strtok(NULL, ";"); // Ignorar pizza_size
        token = strtok(NULL, ";"); // Ignorar pizza_category
        token = strtok(NULL, ";"); // Ignorar pizza_ingredients
        token = strtok(NULL, ";"); // Obtener pizza_name

        // Quitar el salto de línea del nombre
        token[strcspn(token, "\n")] = 0;

        // Verificar si la pizza ya está en la lista
        int found = 0;
        for (int i = 0; i < num_pizzas; i++) {
            if (strcmp(pizzas[i].nombre, token) == 0) {
                pizzas[i].cont++;
                found = 1;
                break;
            }
        }

        // Si no está en la lista, añadirlo
        if (!found) {
            strcpy(pizzas[num_pizzas].nombre, token);
            pizzas[num_pizzas].cont = 1;
            num_pizzas++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    // Encontrar la cantidad máxima de ventas
    int max_ventas = pizzas[0].cont;
    for (int i = 1; i < num_pizzas; i++) {
        if (pizzas[i].cont > max_ventas) {
            max_ventas = pizzas[i].cont;
        }
    }

    // Imprimir las pizzas más vendidas
    printf("Pizzas mas vendidas: ");
    for (int i = 0; i < num_pizzas; i++) {
        if (pizzas[i].cont == max_ventas) {
            printf("%s\n", pizzas[i].nombre);
        }
    }

    return 0;
}
#define max_fecha 10000
#define DATE_LENGTH 11

typedef struct {
    char date[DATE_LENGTH];
    float total_sales;
} DateSales;

int dms() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    DateSales dates[max_fecha];
    int num_dates = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Inicializar total de ventas para cada fecha
    for (int i = 0; i < max_fecha; i++) {
        dates[i].total_sales = 0.0f;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener la fecha y el total de ventas
        token = strtok(line, ";"); // Ignorar pizza_id
        token = strtok(NULL, ";"); // Ignorar order_id
        token = strtok(NULL, ";"); // Ignorar pizza_name_id
        token = strtok(NULL, ";"); // Ignorar quantity
        token = strtok(NULL, ";"); // Obtener order_date
        char *date = token;
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        float total_price = atof(strtok(NULL, ";")); // Obtener total_price

        // Quitar el salto de línea de la fecha
        date[strcspn(date, "\n")] = 0;

        // Actualizar el total de ventas para cada fecha
        int found = 0;
        for (int i = 0; i < num_dates; i++) {
            if (strcmp(dates[i].date, date) == 0) {
                dates[i].total_sales += total_price;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(dates[num_dates].date, date);
            dates[num_dates].total_sales = total_price;
            num_dates++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    // Encontrar la fecha con más ventas
    float max_ventas = dates[0].total_sales;
    char *best_selling_date = dates[0].date;
    for (int i = 1; i < num_dates; i++) {
        if (dates[i].total_sales > max_ventas) {
            max_ventas = dates[i].total_sales;
            best_selling_date = dates[i].date;
        }
    }

    // Imprimir la fecha con más ventas en términos de dinero
    printf("La fecha con menos ventas en terminos de dinero es: %s\nCon el monto vendido: %f\n", best_selling_date, max_ventas);

    return 0;
}

int dls() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    DateSales dates[max_fecha];
    int num_dates = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Inicializar total de ventas para cada fecha
    for (int i = 0; i < max_fecha; i++) {
        dates[i].total_sales = 0.0f;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener la fecha y el total de ventas
        token = strtok(line, ";"); // Ignorar pizza_id
        token = strtok(NULL, ";"); // Ignorar order_id
        token = strtok(NULL, ";"); // Ignorar pizza_name_id
        token = strtok(NULL, ";"); // Ignorar quantity
        token = strtok(NULL, ";"); // Obtener order_date
        char *date = token;
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        float total_price = atof(strtok(NULL, ";")); // Obtener total_price

        // Quitar el salto de línea de la fecha
        date[strcspn(date, "\n")] = 0;

        // Actualizar el total de ventas para cada fecha
        int found = 0;
        for (int i = 0; i < num_dates; i++) {
            if (strcmp(dates[i].date, date) == 0) {
                dates[i].total_sales += total_price;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(dates[num_dates].date, date);
            dates[num_dates].total_sales = total_price;
            num_dates++;
        }
    }

    // Cerrar archivo
    fclose(archivo);
    for(int i = 0; i < num_dates - 1; i++) {
        dates[i] = dates[i + 1];
    }
    num_dates--;

   // Encontrar la fecha con menos ventas
    float min_ventas = dates[0].total_sales;
    char *worst_selling_date = dates[0].date;
    for (int i = 1; i < num_dates; i++) {
        if (dates[i].total_sales < min_ventas) {
            min_ventas = dates[i].total_sales;
            worst_selling_date = dates[i].date;
        }
    }
    // Imprimir la fecha con más ventas en términos de dinero
    printf("La fecha con menos ventas en terminos de dinero es: %s\nCon el monto vendido: %f\n", worst_selling_date, min_ventas);

    return 0;
}

#define DATE_LENGTH 11 // Longitud máxima de una fecha en formato DD-MM-YYYY
#define max_fechas 10000
typedef struct {
    char date[DATE_LENGTH];
    int total_quantity;
} DateSales_pizza;

char dmsp() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    DateSales_pizza dates[max_fechas];
    int num_dates = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return NULL;
    }

    // Inicializar total de cantidad de pizzas vendidas para cada fecha
    for (int i = 0; i < max_fechas; i++) {
        dates[i].total_quantity = 0;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Ignorar las primeras 3 columnas
        token = strtok(line, ";");
        for (int i = 0; i < 3; i++) {
            token = strtok(NULL, ";");
        }
        // Nos quedamos con la cantidad de pizzas vendidas
        int quantity = atoi(token);
        // Obtener la fecha y la cantidad de pizzas vendidas
        token = strtok(NULL, ";"); // Ignorar quantity
        char *date = token;
        // printf("En la fecha %s se vendieron %d pizzas\n", date, quantity);
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        token = strtok(NULL, ";"); // Ignorar total_price
        token = strtok(NULL, ";"); // Ignorar pizza_size
        token = strtok(NULL, ";"); // Ignorar pizza_category
        token = strtok(NULL, ";"); // Ignorar pizza_ingredients
        token = strtok(NULL, ";"); // Ignorar pizza_name

        // Quitar el salto de línea de la fecha
        date[strcspn(date, "\n")] = 0;

        // Buscar si ya existe una entrada para esta fecha y actualizarla
        int found = 0;
        for (int i = 0; i < num_dates; i++) {
            if (strcmp(dates[i].date, date) == 0) {
                dates[i].total_quantity += quantity;
                found = 1;
                break;
            }
        }
        // Si no se encuentra, agregar una nueva entrada
        if (!found) {
            strcpy(dates[num_dates].date, date);
            dates[num_dates].total_quantity = quantity;
            num_dates++;
            
        }
    }

    // Cerrar archivo
    fclose(archivo);
    
    for(int i = 0; i < num_dates - 1; i++) {
        dates[i] = dates[i + 1];
    }
    num_dates--;

    char *date_with_most_pizzas = dates[0].date;
    int max_quantity = dates[0].total_quantity;
    for (int i = 1; i < num_dates; i++) {
        if (dates[i].total_quantity > max_quantity) {
            max_quantity = dates[i].total_quantity;
            date_with_most_pizzas = dates[i].date;
        }
    }

    // Devolver la fecha con más pizzas vendidas
    printf("La fecha con mas pizzas vendidas es: %s\n", date_with_most_pizzas);
    printf("Cantidad de pizzas vendidas: %d\n", max_quantity);



    return 0;
}

char dlsp() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    DateSales_pizza dates[max_fechas];
    int num_dates = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return NULL;
    }

    // Inicializar total de cantidad de pizzas vendidas para cada fecha
    for (int i = 0; i < max_fechas; i++) {
        dates[i].total_quantity = 0;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Ignorar las primeras 3 columnas
        token = strtok(line, ";");
        for (int i = 0; i < 3; i++) {
            token = strtok(NULL, ";");
        }
        // Nos quedamos con la cantidad de pizzas vendidas
        int quantity = atoi(token);
        // Obtener la fecha y la cantidad de pizzas vendidas
        token = strtok(NULL, ";"); // Ignorar quantity
        char *date = token;
        // printf("En la fecha %s se vendieron %d pizzas\n", date, quantity);
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        token = strtok(NULL, ";"); // Ignorar total_price
        token = strtok(NULL, ";"); // Ignorar pizza_size
        token = strtok(NULL, ";"); // Ignorar pizza_category
        token = strtok(NULL, ";"); // Ignorar pizza_ingredients
        token = strtok(NULL, ";"); // Ignorar pizza_name

        // Quitar el salto de línea de la fecha
        date[strcspn(date, "\n")] = 0;

        // Buscar si ya existe una entrada para esta fecha y actualizarla
        int found = 0;
        for (int i = 0; i < num_dates; i++) {
            if (strcmp(dates[i].date, date) == 0) {
                dates[i].total_quantity += quantity;
                found = 1;
                break;
            }
        }
        // Si no se encuentra, agregar una nueva entrada
        if (!found) {
            strcpy(dates[num_dates].date, date);
            dates[num_dates].total_quantity = quantity;
            num_dates++;
            
        }
    }

    // Cerrar archivo
    fclose(archivo);
    
    for(int i = 0; i < num_dates - 1; i++) {
        dates[i] = dates[i + 1];
    }
    num_dates--;

    char *date_with_less_pizzas = dates[0].date;
    int min_quantity = dates[0].total_quantity;
    // Encontrar la fecha con menos pizzas vendidas
    for (int i = 0; i < num_dates; i++) {
        // Your code here
        // printf("En la fecha %s se vendieron %d pizzas\n", dates[i].date, dates[i].total_quantity);
        if (dates[i].total_quantity < min_quantity) {
            min_quantity = dates[i].total_quantity;
            date_with_less_pizzas = dates[i].date;
        }
    }
    printf("La fecha con menos pizzas vendidas es: %s\n", date_with_less_pizzas);
    printf("Cantidad de pizzas vendidas: %d\n", min_quantity);
    
    return 0;
}

#define MAX_INGREDIENTS 1000

typedef struct {
    char nombre[max_char_por_linea];
    int cont;
} IngredientCount;

int ims() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[max_char_por_linea];
    char *token;
    IngredientCount ingredients[MAX_INGREDIENTS];
    int num_ingredients = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener los ingredientes de la pizza
        token = strtok(line, ";");
        for (int i = 0; i < 9; i++) {
            token = strtok(NULL, ";"); // Ignorar las primeras 9 columnas
        }
        token = strtok(NULL, ";"); // Obtener los ingredientes

        // Tokenizar los ingredientes
        char *ingredient = strtok(token, ",");
        while (ingredient != NULL) {
            // Quitar espacios en blanco al principio y al final del ingrediente
            while (*ingredient == ' ') {
                ingredient++;
            }
            char *end = ingredient + strlen(ingredient) - 1;
            while (end > ingredient && *end == ' ') {
                *end-- = '\0';
            }

            // Verificar si el ingrediente ya está en la lista
            int found = -1;
            for (int i = 0; i < num_ingredients; i++) {
                if (strcmp(ingredients[i].nombre, ingredient) == 0) {
                    found = i;
                    break;
                }
            }

            // Si el ingrediente no está en la lista, añadirlo
            if (found == -1) {
                strcpy(ingredients[num_ingredients].nombre, ingredient);
                ingredients[num_ingredients].cont = 1;
                num_ingredients++;
            } else {
                ingredients[found].cont++;
            }

            // Obtener el siguiente ingrediente
            ingredient = strtok(NULL, ",");
        }
    }

    // Cerrar archivo
    fclose(archivo);

    // Encontrar la cantidad máxima de ventas de un ingrediente
    int max_sales = 0;
    for (int i = 0; i < num_ingredients; i++) {
        if (ingredients[i].cont > max_sales) {
            max_sales = ingredients[i].cont;
        }
    }

    // Imprimir los ingredientes más vendidos
    printf("Ingredientes mas vendidos:\n");
    for (int i = 0; i < num_ingredients; i++) {
        if (ingredients[i].cont == max_sales) {
            printf("%s\n", ingredients[i].nombre);
        }
    }

    return 0;
}

typedef struct {
    char category[max_char_por_linea];
    int cont;
} PizzaCategoryCount;

int hp() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[max_char_por_linea];
    char *token;
    PizzaCategoryCount categories[max_char_por_linea];
    int num_categories = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener la categoría de la pizza
        token = strtok(line, ";"); // Ignorar la primera columna
        token = strtok(NULL, ";"); // Ignorar las siguientes 2 columnas
        token = strtok(NULL, ";");
        token = strtok(NULL, ";"); // Ignorar las siguientes 6 columnas
        token = strtok(NULL, ";");
        token = strtok(NULL, ";");
        token = strtok(NULL, ";");
        token = strtok(NULL, ";");
        token = strtok(NULL, ";"); // Obtener la categoría
        token = strtok(NULL, ";"); // Obtener la categoría


        // Quitar el salto de línea de la categoría
        token[strcspn(token, "\n")] = 0;

        // Verificar si la categoría ya está en la lista
        int found = -1;
        for (int i = 0; i < num_categories; i++) {
            if (strcmp(categories[i].category, token) == 0) {
                found = i;
                break;
            }
        }
        
   
        // Si la categoría no está en la lista, añadirla
        if (found == -1) {
            strcpy(categories[num_categories].category, token);
            categories[num_categories].cont = 1;
            num_categories++;
        } else {
            categories[found].cont++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    for(int i = 0; i < num_categories - 1; i++) {
        categories[i] = categories[i + 1];
    }
    num_categories--;

    // Imprimir la cantidad de pizzas vendidas por categoría
    printf("Cantidad de pizzas vendidas por categoria:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %d\n", categories[i].category, categories[i].cont);
    }

    return 0;
}

typedef struct {
    int order_id;
    int total_pizzas;
    int num_orders;
} OrderPizzaCount;

int apo() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[max_char_por_linea];
    char *token;
    OrderPizzaCount orders[max_char_por_linea];
    int num_orders = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener el ID de orden y la cantidad de pizzas
        token = strtok(line, ";"); // Ignorar la primera columna
        int order_id = atoi(strtok(NULL, ";")); // Obtener el ID de orden
        strtok(NULL, ";"); // Ignorar la siguiente columna
        int quantity = atoi(strtok(NULL, ";")); // Obtener la cantidad de pizzas

        // Buscar si el ID de orden ya está registrado
        int found = -1;
        for (int i = 0; i < num_orders; i++) {
            if (orders[i].order_id == order_id) {
                found = i;
                break;
            }
        }

        // Si el ID de orden no está registrado, añadirlo
        if (found == -1) {
            orders[num_orders].order_id = order_id;
            orders[num_orders].total_pizzas = quantity;
            orders[num_orders].num_orders = 1;
            num_orders++;
        } else {
            orders[found].total_pizzas += quantity;
            orders[found].num_orders++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    for(int i = 0; i < num_orders - 1; i++) {
        orders[i] = orders[i + 1];
    }
    num_orders--;
    // Calcular el promedio de pizzas por orden
    float total_pizzas = 0;
    for (int i = 0; i < num_orders; i++) {
        total_pizzas += (float)orders[i].total_pizzas / orders[i].num_orders;
    }
    
    float average_pizzas_per_order = total_pizzas / num_orders;

    // Imprimir el promedio de pizzas por orden
    printf("Promedio de pizzas por orden: %.2f\n", average_pizzas_per_order);

    return 0;
}

#define max_fechas 100

typedef struct {
    char date[11];
    int num_pizzas;
} DatePizzas;

int apd() {
    FILE *archivo;
    char nombre_archivo[] = "ventas.csv";
    char line[1024];
    char *token;
    DatePizzas dates[max_fechas];
    int num_dates = 0;

    // Abrir archivo
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_archivo);
        return 1;
    }

    // Inicializar total de pizzas para cada fecha
    for (int i = 0; i < max_fechas; i++) {
        dates[i].num_pizzas = 0;
    }

    // Leer archivo línea por línea
    while (fgets(line, sizeof(line), archivo)) {
        // Obtener la fecha y el número de pizzas
        token = strtok(line, ";"); // Ignorar pizza_id
        token = strtok(NULL, ";"); // Ignorar order_id
        token = strtok(NULL, ";"); // Ignorar pizza_name_id
        int quantity = atoi(strtok(NULL, ";")); // Obtener quantity
        token = strtok(NULL, ";"); // Obtener order_date
        char *date = token;
        token = strtok(NULL, ";"); // Ignorar order_time
        token = strtok(NULL, ";"); // Ignorar unit_price
        token = strtok(NULL, ";"); // Ignorar total_price
        token = strtok(NULL, ";"); // Ignorar pizza_size
        token = strtok(NULL, ";"); // Ignorar pizza_category
        token = strtok(NULL, ";"); // Ignorar pizza_ingredients
        token = strtok(NULL, ";"); // Ignorar pizza_name

        // Quitar el salto de línea de la fecha
        date[strcspn(date, "\n")] = 0;

        // Actualizar el número total de pizzas para cada fecha
        int found = 0;
        for (int i = 0; i < num_dates; i++) {
            if (strcmp(dates[i].date, date) == 0) {
                dates[i].num_pizzas += quantity;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(dates[num_dates].date, date);
            dates[num_dates].num_pizzas = quantity;
            num_dates++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    for(int i = 0; i < num_dates - 1; i++) {
        dates[i] = dates[i + 1];
    }
    num_dates--;

    // Calcular el promedio de pizzas por día
    int total_pizzas = 0;
    for (int i = 0; i < num_dates; i++) {
        total_pizzas += dates[i].num_pizzas;
    }
    float average_pizzas = (float)total_pizzas / num_dates;

    // Imprimir el promedio de pizzas por día
    printf("Promedio de pizzas por dia es: %.2f\n", average_pizzas);

    return 0;
}


int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s [nombre_archivo.csv] [funcion1] [funcion2] ...\n", argv[0]);
        return 1;
    }

    // Llama a las funciones especificadas en los argumentos de la línea de comandos
    for (int i = 2; i < argc; i++) {
        char *function_name = argv[i];
        char *result = NULL;

        // Llama a la función correspondiente
        if (strcmp(function_name, "pls") == 0) {
            result = pls();
        } else if (strcmp(function_name, "pms") == 0) {
            result = pms();
        } else if (strcmp(function_name, "dms") == 0) {
            result = dms(); 
        } else if (strcmp(function_name, "dls") == 0) {
            result = dls(); 
        } else if (strcmp(function_name, "dmsp") == 0) {
            result = dmsp();
        } else if (strcmp(function_name, "dlsp") == 0) {
            result = dlsp();
        } else if (strcmp(function_name, "apo") == 0) {
            result = apo(); 
        } else if (strcmp(function_name, "apd") == 0) {
            result = apd(); 
        }  else if (strcmp(function_name, "ims") == 0) {
            result = ims(); 
        } else if (strcmp(function_name, "hp") == 0) {
            result = hp(); 
        } 
         
        if (result != NULL) {
            printf("%s\n", result);
            free(result);
        }
    }

    return 0;
}