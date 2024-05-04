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
