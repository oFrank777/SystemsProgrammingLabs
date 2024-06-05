#include <iostream>

const int NUM_TORRES = 7;
const int NUM_PISOS = 20;
const int NUM_DEPARTAMENTOS = 6;

// Función para calcular la cantidad total de habitantes
int calcularTotalHabitantes(int complejo[NUM_TORRES][NUM_PISOS][NUM_DEPARTAMENTOS]) {
    int total = 0;
    for (int torre = 0; torre < NUM_TORRES; ++torre) {
        for (int piso = 0; piso < NUM_PISOS; ++piso) {
            for (int departamento = 0; departamento < NUM_DEPARTAMENTOS; ++departamento) {
                total += complejo[torre][piso][departamento];
            }
        }
    }
    return total;
}

// Función para calcular la cantidad promedio de habitantes por piso de cada torre
void calcularPromedioHabitantesPorPiso(int complejo[NUM_TORRES][NUM_PISOS][NUM_DEPARTAMENTOS]) {
    for (int torre = 0; torre < NUM_TORRES; ++torre) {
        int totalPisos = 0;
        int totalHabitantesPorTorre = 0;
        for (int piso = 0; piso < NUM_PISOS; ++piso) {
            int totalHabitantesPorPiso = 0;
            for (int departamento = 0; departamento < NUM_DEPARTAMENTOS; ++departamento) {
                totalHabitantesPorPiso += complejo[torre][piso][departamento];
            }
            totalHabitantesPorTorre += totalHabitantesPorPiso;
            totalPisos++;
        }
        double promedio = static_cast<double>(totalHabitantesPorTorre) / totalPisos;
        std::cout << "Promedio de habitantes por piso de la torre " << torre + 1 << ": " << promedio << std::endl;
    }
}

// Función para calcular la cantidad promedio de habitantes por torre
void calcularPromedioHabitantesPorTorre(int complejo[NUM_TORRES][NUM_PISOS][NUM_DEPARTAMENTOS]) {
    int totalHabitantes = calcularTotalHabitantes(complejo);
    double promedio = static_cast<double>(totalHabitantes) / NUM_TORRES;
    std::cout << "Promedio de habitantes por torre: " << promedio << std::endl;
}

int main() {
    int complejo[NUM_TORRES][NUM_PISOS][NUM_DEPARTAMENTOS] = {0}; // Inicializa todos los elementos del arreglo en 0

    // Aquí se llenarían los datos del complejo habitacional con la cantidad de habitantes en cada departamento

    // Inicialización de datos de prueba
    complejo[0][0][0] = 2; complejo[0][0][1] = 8; 
    complejo[0][1][0] = 3; complejo[0][1][1] = 2; 
    complejo[0][2][0] = 1; complejo[0][2][1] = 4; 

    complejo[1][0][0] = 4; complejo[1][0][1] = 10; 
    complejo[1][1][0] = 5; complejo[1][1][1] = 3; 
    complejo[1][2][0] = 7; complejo[1][2][1] = 2; 

    complejo[2][0][0] = 3; complejo[2][0][1] = 9; 
    complejo[2][1][0] = 5; complejo[2][1][1] = 9; 
    complejo[2][2][0] = 5; complejo[2][2][1] = 1; 

    /*
    // Ejemplo de datos aleatorios
    for (int torre = 0; torre < NUM_TORRES; ++torre) {
        for (int piso = 0; piso < NUM_PISOS; ++piso) {
            for (int departamento = 0; departamento < NUM_DEPARTAMENTOS; ++departamento) {
                complejo[torre][piso][departamento] = rand() % 5 + 1; // Se asigna un número aleatorio de habitantes
            }
        }
    }
    */
   
    // Calcular y mostrar resultados
    int totalHabitantes = calcularTotalHabitantes(complejo);
    std::cout << "Cantidad total de habitantes del complejo: " << totalHabitantes << std::endl;

    calcularPromedioHabitantesPorPiso(complejo);
    calcularPromedioHabitantesPorTorre(complejo);

    return 0;
}
