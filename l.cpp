#include <iostream>
#include <string>

using namespace std;

struct nodo {
string nombres; 
string cedulas;
nodo* siguiente;
};

void insertarcola(nodo *&, nodo *&, string, string);
bool cola_vacia(nodo *);

int main() {
nodo *frente = NULL;
nodo *fin = NULL;
int contador = 1; 
int opcs;
string nombres; 
string cedulas;
nodo *temp = NULL;

do {
cout << "Menu\n";
cout << "1. Insertar nombre\n";
cout << "2. Mostrar los pacientes\n";
cout << "3. Finalizar\n";
cout << "Opcion: ";
cin >> opcs;

switch (opcs) {
case 1:
cout << "Ingrese el nombre del paciente: ";
cin.ignore(); 
getline(cin, nombres); 
cout<<"Ingrese el numero del paciente :";
cin >> cedulas;
insertarcola(frente, fin, nombres, cedulas);
    break;

case 2:
cout << "Mostrando datos:\n";
temp = frente;
while (temp != NULL) {
cout << contador++ << " Nombre: " << temp->nombres << ", Cedula: " << temp->cedulas << endl;
temp = temp->siguiente;
}
    break;

case 3:
cout << "Final\n";
    break;

default:
cout << "Opcion invalida\n";
    }
}while (opcs != 3);
return 0;
}

void insertarcola(nodo *&frente, nodo *&fin, string n, string s) {
nodo *nuevo_nodo = new nodo();
nuevo_nodo->nombres = n;
nuevo_nodo->cedulas = s;
nuevo_nodo->siguiente = NULL;

if (cola_vacia(frente)) {
frente = nuevo_nodo;
    }else{
fin->siguiente = nuevo_nodo;
}

fin = nuevo_nodo;

}

bool cola_vacia(nodo *frente) {
return (frente == NULL);
}