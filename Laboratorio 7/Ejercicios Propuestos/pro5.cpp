#include <iostream>
#include <string>
#include <exception>

// Clase base para todas las excepciones del simulador
class ComputerException : public std::exception {
protected:
    std::string message;  // Mensaje de la excepción

public:
    explicit ComputerException(const std::string& msg) : message(msg) {}  // Constructor con mensaje

    const char* what() const noexcept override {  // Método what para obtener el mensaje de la excepción
        return message.c_str();
    }
};

// Excepción para errores del módulo de entrada
class InputException : public ComputerException {
public:
    explicit InputException(const std::string& msg) : ComputerException(msg) {}
};

// Excepción para errores del módulo de procesamiento
class ProcessorException : public ComputerException {
public:
    explicit ProcessorException(const std::string& msg) : ComputerException(msg) {}
};

// Excepción para errores del módulo de salida
class OutputException : public ComputerException {
public:
    explicit OutputException(const std::string& msg) : ComputerException(msg) {}
};

// Función de ejemplo que puede lanzar una InputException
void readFile(const std::string& filePath) {
    // Simulación de un error al leer un archivo
    throw InputException("Error al leer el archivo: " + filePath);
}

// Función de ejemplo que puede lanzar una ProcessorException
void processData() {
    // Simulación de un error en el procesamiento
    throw ProcessorException("Error en el procesamiento de datos");
}

// Función de ejemplo que puede lanzar una OutputException
void writeFile(const std::string& filePath) {
    // Simulación de un error al escribir un archivo
    throw OutputException("Error al escribir en el archivo: " + filePath);
}

int main() {
    try {
        readFile("input.txt");
    } catch (const InputException& e) {
        std::cerr << e.what() << std::endl;
        // Intentar recuperarse del error (por ejemplo, pidiendo otra ruta de archivo)
    }

    try {
        processData();
    } catch (const ProcessorException& e) {
        std::cerr << e.what() << std::endl;
        // Intentar recuperarse del error (por ejemplo, reintentando el procesamiento)
    }

    try {
        writeFile("input.txt");
    } catch (const OutputException& e) {
        std::cerr << e.what() << std::endl;
        // Intentar recuperarse del error (por ejemplo, pidiendo otra ruta de archivo)
    }

    return 0;
}
