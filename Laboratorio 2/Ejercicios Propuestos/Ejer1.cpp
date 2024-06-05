// ejercicio1.cpp
#include <iostream>
#include <cstring>

class Persona {
private:
    char nombre[50]; // Propiedad para almacenar el nombre de la persona

public:
    // Constructor por defecto
    Persona() {
        strcpy(nombre, ""); // Inicializa el nombre a una cadena vacía
    }

    // Métodos de la clase
    void dormir() {
        std::cout << "Estoy durmiendo." << std::endl;
    }

    void hablar() {
        std::cout << "Estoy hablando." << std::endl;
    }

    void contar() {
        std::cout << "Estoy contando." << std::endl;
    }

    void adquirirNombre() {
        std::cout << "Ingrese su nombre: ";
        std::cin.getline(nombre, 50); // Lee una línea de texto y la almacena en 'nombre'
    }

    void decirNombre() {
        std::cout << "Mi nombre es: " << nombre << std::endl;
    }
};

int main() {
    Persona persona; // Crear una instancia de la clase Persona

    persona.adquirirNombre(); // Adquirir el nombre del usuario
    persona.decirNombre();    // Decir el nombre del usuario
    persona.hablar();         // Llamar al método hablar
    persona.dormir();         // Llamar al método dormir
    persona.contar();         // Llamar al método contar

    return 0;
}
