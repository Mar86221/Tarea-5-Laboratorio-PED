//Luis Mario Valencia 
#include "Cliinica.hpp"
//Usea lista circular simple porque me base en el de el ingeniero Cortez y nunca
//se explico el doblemente enlazada

int menu()
{
    int opcion; //Menu de seleccion
    cout << endl;
    cout << "1) Agregar datos de nuevo cliente. " << endl;
    cout << "2) Mostrar datos. " << endl;
    cout << "3) Eliminar un perfil. " << endl;
    cout << "4) Eliminar todos los datos. " << endl;
    cout << "5) Salir. " << endl;
    cout << "Opcion ";
    cin >> opcion;
    cin.ignore();
    return opcion;
}

cliente C;
int main(int argc, char const *argv[])
{
    ListaCircSimple infoCliente;
    int id=0;

    bool continuar = true;
    
    do
    {
        switch (menu())
        {
        case 1: //Insertar datos
            cout<< "Digite el perfil del cliente: " <<endl;
            C = solidatos();
            infoCliente.insInicio(C);
            cout<<"\n Perfil almacenado exitosamente! \n"<<endl;
            break;
        case 2: //Mostrar datos
            if (infoCliente.empty())
            {
                cout<<"\n No hay ningun dato aun \n"<<endl;
            }
            else
            {
                infoCliente.mostrarlistaiter();
            }
            break;
        case 3: //Eliminar
            C = solidatos();
            if (infoCliente.empty())
            {
                cout<<"\n No hay ningun dato aun \n"<<endl;
            }
            else
            {
                //Aqui en la funcion eliminar si elimina el primer nodo ingresado y los de enmedio pero 
                //no borra cuando cuando solo hay un nodo ni borrar el primero que se muestra en la lista de forma descendente
                //no encontre ilumnacion en lo que mas o menos me explicaron F
                cout<<"\n Eliminando el nodo \n"<<endl;
                infoCliente.borrado(C);
                cout<<"\n Nodo eliminado exitosamente! \n"<<endl;
            }
            break;
        case 4: //Salir
            infoCliente.~ListaCircSimple();
            cout<<"\n Eliminando todos los datos \n"<<endl;
            break;
        case 5: //Salir
            continuar = false;
            break;
        default: //Opcion no valida
            cout<<"\n La opcion no es valida, favor intente denuevo. \n"<<endl;
            break;
        } 
    }while(continuar);

    return 0;
}
