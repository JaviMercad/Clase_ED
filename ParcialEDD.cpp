#include <iostream>
#include <conio.h>
#include <stdlib.h>


using namespace std;

struct nodo{
    int id;
    string nombre;
    int cantidad;
    double precio;
    nodo *sig;

};

// prototipos de las funciones
void registrarProducto(nodo *&, nodo *&, int, string, int, double);
bool cola_vacia(nodo *);
void mostrarInventario(nodo *, nodo *);
void buscarProductoPorID(nodo *frente, int id);
void eliminarProducto(nodo *&frente, nodo *&fin, int id);
double calcularValorTotalInventario(nodo *frente);
double calcularPromedioPrecios(nodo *frente);
void venderProducto(nodo*& frente, nodo*& fin);
bool idRepetido(nodo *frente, int id) {
    nodo *temp = frente;
    while (temp != NULL) {
        if (temp->id == id) {
            return true; 
        }
        temp = temp->sig;
    }
    return false; 
}
int main(){ 
    nodo *frente = NULL;
    nodo *fin = NULL;
    nodo *temp = NULL;
    nodo* buscarProductoPoriD(nodo* frente, int id);
    

    int id;
    string nombre;
    int cantidad;
    double precio;
    
    

    int opc = 0;
    int rpt = 0;
    double valorTotalInventario = 0.0;
    double promedioPrecios;
    


    do{

    cout<<"----------------Menu--------------"<<endl;
    cout<<"¿Que desea realizar?"<<endl;
    cout<<""<<endl;
    cout<<"1) Registrar producto"<<endl;
    cout<<"2) Mostrar inventario"<<endl;
    cout<<"3) Buscar producto"<<endl;
    cout<<"4) Eliminar producto"<<endl;
    cout<<"5) Calcular el valor total del inventario"<<endl;
    cout<<"6) Calcular el promedio de los precios"<<endl;
    cout<<"7) Vender productos"<<endl;
    cout<<"8) Salir del sistema"<<endl;
    cin>>rpt;


    switch(rpt){

        case 1:
        
     do {
        cout << "Ingrese el id del producto: "<<endl;
        cin >> id;

        if (idRepetido(frente, id)) {
            cout << "Error: El ID ingresado ya ha sido utilizado. Por favor, ingrese un nuevo ID." << endl;
        }
    } while (idRepetido(frente, id));
     cout<<"Ingrese el nombre del producto: "<<endl;
     cin>>nombre;
     cout<<"Ingrese la cantidad del producto "<<nombre<<":"<<endl;
     cin>>cantidad;
     cout<<"Ingrese el precio del producto "<<nombre<<":"<<endl;
     cin>>precio;

     registrarProducto(frente, fin, id, nombre, cantidad, precio);
     cout<<""<<endl;
            break;

        case 2: 
        cout<<"\nMostrando los elementos de la cola: "<<endl;
            mostrarInventario(frente, fin);
            break;
        
        case 3: 
             int idBuscar;
             cout << "Ingrese el ID del producto que desea buscar: ";
             cin >> idBuscar;
             buscarProductoPorID(frente, idBuscar);
             break;

        case 4: 
             int idEliminar;
             cout << "Ingrese el ID del producto que desea eliminar: ";
             cin >> idEliminar;
             eliminarProducto(frente, fin, idEliminar);

             break;

        case 5:
        
        valorTotalInventario = calcularValorTotalInventario(frente);
        cout << "El valor total del inventario es: $" << valorTotalInventario << endl;
        break;

        case 6:
        
        promedioPrecios = calcularPromedioPrecios(frente);
        cout << "El precio promedio por unidad de todos los productos en el inventario es: $" << promedioPrecios << endl;
         break;

        case 7:
            venderProducto(frente, fin);
            break;

        case 8: 
        cout<<"Final\n"<<endl;
            break;

                default:
                 cout<<"Opcion incorrecta, ingrese nuevamente otra opcion."<<endl;
    }

    }while(rpt != 8);
getch();
    return 0;
}

void registrarProducto(nodo *&frente, nodo *&fin, int i, string n, int c, double p){
    nodo *nuevo_nodo = new nodo();
  
    
    nuevo_nodo->id = i;
    nuevo_nodo->nombre = n;
    nuevo_nodo->cantidad = c;
    nuevo_nodo->precio = p;
    nuevo_nodo->sig = NULL;
   

    if(cola_vacia(frente)){
        frente = nuevo_nodo;
    }else{
        fin->sig = nuevo_nodo;
    }

    fin = nuevo_nodo;

    cout<<"Producto "<<n<<" agregado exitosamente"<<endl;
}
bool cola_vacia(nodo *frente){
    return (frente == NULL)? true : false;
}
void mostrarInventario(nodo *frente, nodo *fin) {
    nodo *temp = frente;

    while (temp != NULL) {
        cout << "ID: " << temp->id << endl;
        cout << "Nombre: " << temp->nombre << endl;
        cout << "Cantidad: " << temp->cantidad << endl;
        cout << "Precio por unidad: " << temp->precio << endl;
        cout << endl;

        temp = temp->sig;
    }
}
void buscarProductoPorID(nodo *frente, int id) {
    nodo *temp = frente;
    bool encontrado = false;

    
    while (temp != NULL) {
        if (temp->id == id) {
            encontrado = true;
            cout << "Informacion del producto con ID " << id << ":" << endl;
            cout << "Nombre: " << temp->nombre << endl;
            cout << "Cantidad: " << temp->cantidad << endl;
            cout << "Precio por unidad: " << temp->precio << endl;
            break;  
        }
        temp = temp->sig;
    }

    
    if (!encontrado) {
        cout << "No se encontro ningún producto con el ID proporcionado." << endl;
    }
}
void eliminarProducto(nodo *&frente, nodo *&fin, int id) {
    if (frente == NULL) {
        cout << "El inventario está vacío, no se puede eliminar ningún producto." << endl;
        return;
    }

    nodo *temp = frente;
    nodo *anterior = NULL;

    
    while (temp != NULL && temp->id != id) {
        anterior = temp;
        temp = temp->sig;
    }

    
    if (temp == NULL) {
        cout << "No se encontro ningun producto con el ID proporcionado." << endl;
        return;
    }

    
    if (temp == frente) {
        frente = frente->sig;
    } else {
        anterior->sig = temp->sig;
    }

    
    if (temp == fin) {
        fin = anterior;
    }

    
    delete temp;

    cout << "Producto eliminado del inventario." << endl;
}
double calcularValorTotalInventario(nodo *frente) {
    double valorTotal = 0.0;
    nodo *temp = frente;
    while (temp != NULL) {
        valorTotal += temp->cantidad * temp->precio;
        temp = temp->sig;
    }

    return valorTotal;
}
double calcularPromedioPrecios(nodo *frente) {
    double sumaPrecios = 0.0;
    int totalProductos = 0;

    
    nodo *temp = frente;
    while (temp != NULL) {
        sumaPrecios += temp->precio;
        totalProductos++;
        temp = temp->sig;
    }

    
    double promedioPrecios = (totalProductos > 0) ? (sumaPrecios / totalProductos) : 0.0;

    return promedioPrecios;
}
nodo* buscarProductoPoriD(nodo* frente, int id) {
    nodo* temp = frente;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp; 
        }
        temp = temp->sig;
    }
    return NULL; 
}
void venderProducto(nodo*& frente, nodo*& fin) {
    int idVenta;
    cout << "Ingrese el ID del producto a vender: ";
    cin >> idVenta;

    
    nodo *productoVenta = buscarProductoPoriD(frente, idVenta);
    if (productoVenta != NULL) {
        cout << "Información del producto:\n";
        cout << "ID: " << productoVenta->id << endl;
        cout << "Nombre: " << productoVenta->nombre << endl;
        cout << "Cantidad en inventario: " << productoVenta->cantidad << endl;
        cout << "Precio por unidad: $" << productoVenta->precio << endl;

        int cantidadVenta;
        cout << "Ingrese la cantidad de unidades que desea comprar: ";
        cin >> cantidadVenta;

        // Verificar si hay existencias suficientes
        if (cantidadVenta <= productoVenta->cantidad) {
            // Calcular el total a pagar y descontar la cantidad vendida del inventario
            double totalPagar = cantidadVenta * productoVenta->precio;
            productoVenta->cantidad -= cantidadVenta;

            cout << "Total a pagar: $" << totalPagar << endl;
        } else {
            cout << "No hay suficientes existencias de este producto. Venta cancelada." << endl;
        }
    } else {
        cout << "Producto no encontrado. Venta cancelada." << endl;
    }
}
