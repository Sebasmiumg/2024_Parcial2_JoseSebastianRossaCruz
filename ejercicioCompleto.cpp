#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace std;

void agregarTexto(const string& rutaArchivo) {
    ofstream archivo(rutaArchivo, ios::app); // Abre el archivo en modo de añadir al final
    if (archivo.is_open()) {
        cout << "Ingrese el texto que desea agregar al archivo (presione Enter para finalizar):" << endl;
        string texto;
        while (true) {
            getline(cin, texto);
            if (texto.empty()) // Si se presiona Enter sin escribir texto, se detiene la entrada
                break;
            archivo << texto << endl;
        }
        archivo.close();
        cout << "Texto agregado al archivo exitosamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }
}

void crearArchivos(int cantidad) {
    string nombreArchivo = "documento";
    for (int i = 0; i < cantidad; ++i) {
        string ruta;
        if (i % 2 == 0) {
            ruta = "C:/Users/Sebas/OneDrive/Escritorio/ARCHIVOS PAR";
        } else {
            ruta = "C:/Users/Sebas/OneDrive/Escritorio/ARCHIVOS IMPAR";
        }
        ofstream file(ruta + nombreArchivo + to_string(i + 1) + ".txt");
        if (file.is_open()) {
            agregarTexto(ruta + nombreArchivo + to_string(i + 1) + ".txt");
            for (int j = 0; j < i + 1; ++j) {
                file << "linea de texto" << endl;
            }
            file.close();
            cout << "Archivo " << ruta << nombreArchivo << i + 1 << ".txt creado con éxito." << endl;
        } else {
            cout << "No se pudo abrir el archivo " << ruta << nombreArchivo << i + 1 << ".txt" << endl;
        }
    }
}

void mostrarMenu() {
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Crear archivos" << endl;
    cout << "2. Salir" << endl;
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1: {
                int cantidad;
                cout << "Ingrese la cantidad de archivos a crear: ";
                cin >> cantidad;
                crearArchivos(cantidad);
                break;
            }
            case 2:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcion != 2);
    return 0;
}

