#include <iostream> //Librerias a usar
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// Estructura para almacenar los datos de un contacto
struct Contacto
{
    string nombres;
    string apellidos;
    string telefono;
    string correo;
};

// Función para ingresar en tiempo de ejeución los datos de los contactos
void ingresarContactos(vector<Contacto> &contactos)
{
    for (int i = 0; i < 5; ++i)
    {
        Contacto nuevoContacto;
        cout << "\nIngrese los datos del contacto " << i + 1 << ":" << endl;

        cout << "Nombres: ";
        getline(cin, nuevoContacto.nombres);

        cout << "Apellidos: ";
        getline(cin, nuevoContacto.apellidos);

        cout << "Número de Teléfono: ";
        getline(cin, nuevoContacto.telefono);

        cout << "Correo Electrónico: ";
        getline(cin, nuevoContacto.correo);
        contactos.push_back(nuevoContacto);
    }
}

// Función para guardar los contactos en el archivo "Contactos.txt"
void guardarContactos(const vector<Contacto> &contactos)
{
    ofstream archivo("Contactos.txt"); // Libreria para escribir datos en el archivo
    if (!archivo)
    {
        cerr << "Error: No se pudo abrir el archivo para escribir." << endl;
        return;
    }
    for (const auto &contacto : contactos)
    {
        // Al mostrar la información de los contactos irá separado por ";"
        archivo << contacto.nombres << "; "
                << contacto.apellidos << "; "
                << contacto.telefono << "; "
                << contacto.correo << endl;
    }
    archivo.close();
    cout << "\nLos contactos se han guardado exitosamente en el archivo 'Contactos.txt'.\n"
         << endl;
}

// Función para mostrar los contactos desde el archivo
void mostrarContactos()
{
    ifstream archivo("Contactos.txt"); // Libreria para leer los datos del archivo
    if (!archivo)
    {
        cerr << "Error: No se pudo abrir el archivo para leer." << endl;
        return;
    }
    string linea;
    cout << "Mostrando los contactos almacenados en el archivo 'Contactos.txt':" << endl;
    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }
    archivo.close();
}

int main()
{
    SetConsoleOutputCP(65001);

    vector<Contacto> contactos;

    // Ingresar los contactos
    ingresarContactos(contactos);

    // Guardar los contactos en el archivo
    guardarContactos(contactos);

    // Mostrar los contactos desde el archivo
    mostrarContactos();

    return 0;
}
