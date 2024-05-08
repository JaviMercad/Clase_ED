#include <iostream>
#include <string>

using namespace std;

struct nodo {
    string placa;
    int movimientos;
    string tipo;
    nodo *sig;
};

nodo *frente = NULL;

bool ExistePlaca(string placa) {
    nodo *temp = frente;
    while (temp != NULL) {
        if (temp->placa == placa) {
            return true;
        }
        temp = temp->sig;
    }
    return false;
}

void Registrarvehiculo() {
    nodo *aux = new nodo;
    cout << "Registrar placa: ";
    cin >> aux->placa;

    if (ExistePlaca(aux->placa)) {
        cout << "La placa ya existe en el parqueadero." << endl;
        delete aux;
        return;
    }

    cout << "Registrar tipo (Carro o Moto): ";
    cin >> aux->tipo;
    aux->movimientos = 0;

    aux->sig = frente;
    frente = aux;
}

void Mostrar() {
    if (frente == NULL) {
        cout << "El parqueadero esta vacio." << endl;
        return;
    }

    nodo *temp = frente;
    while (temp != NULL) {
        cout << "Placa: " << temp->placa << ", Tipo: " << temp->tipo << ", Movimientos: " << temp->movimientos << endl;
        temp = temp->sig;
    }
}

void CalcularCostoMovimientos(string placa) {
    nodo *temp = frente;
    nodo *prev = NULL;
    while (temp != NULL) {
        if (temp->placa == placa) {
            int costoBase, costoPorMovimiento;

            if (temp->tipo == "Carro" || temp->tipo == "carro") {
                costoBase = 1000;
                costoPorMovimiento = 100;
            } else if (temp->tipo == "Moto" || temp->tipo == "moto") {
                costoBase = 500;
                costoPorMovimiento = 50;
            } else {
                cout << "Tipo de vehiculo no valido." << endl;
                return;
            }

            int numMovimientos = temp->placa.length();
            int costoTotal = costoBase + (numMovimientos * costoPorMovimiento); 

            cout << "El valor a pagar para el vehiculo con placa " << placa << " es: " << costoTotal << endl;

            if (prev == NULL) {
                frente = temp->sig;
            } else {
                prev->sig = temp->sig;
            }
            delete temp;

            return;
        }
        prev = temp;
        temp = temp->sig;
    }
    cout << "No se encontro ningun vehiculo con la placa " << placa << endl;
}

void Ingreseelnumerodeplaca() {
    string placa;
    cout << "Ingrese su numero de placa: ";
    cin >> placa;

    nodo *temp = frente;
    while (temp != NULL) {
        if (temp->placa == placa) {
            CalcularCostoMovimientos(placa);
            return;
        }
        temp = temp->sig;
    }
    cout << "El vehiculo con placa " << placa << " no esta registrado en el parqueadero." << endl;
}

int main() {
    int opcs = 0;
    do {
        cout << "\n     Menu      " << endl;
        cout << "1. Registrar vehiculo" << endl;
        cout << "2. Mostrar registro del parqueadero" << endl;
        cout << "3. Ingrese el numero de placa" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcs;

        switch (opcs) {
            case 1:
                Registrarvehiculo();
                break;
            case 2:
                Mostrar();
                break;
            case 3:
                Ingreseelnumerodeplaca();
                break;
            case 4:
                cout << "Finalizacion del programa." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcs != 4);

    return 0;
}
