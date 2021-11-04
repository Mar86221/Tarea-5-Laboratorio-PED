#include <iostream>
#include <string>
using namespace std;

struct cliente
{
    int ID;
    string nombre;
    string raza;
    double peso;
    int edad;
};

cliente solidatos(void)
{
    cliente C;
    cout<<"ID: ";
    cin>>C.ID;
    cout<<"Nombre del cliente/duenio: ";
    cin>> C.nombre;
    cin.ignore();
    cout<<"Raza o tipo de mazcota: ";
    cin>> C.raza;
    cin.ignore();
    cout<<"Peso de la mascota (en kilogramos): ";
    cin>> C.peso; 
    cout<<"Edad de la mascota: ";
    cin>> C.edad;
    return C;
}

void mostrardata(cliente C)
{
    cout<<"\n -#"<<C.ID<<endl;
    cout<<" --Nombre cliente: "<<C.nombre<<endl;
    cout<<" --Raza: "<<C.raza<<endl;
    cout<<" --Peso: "<<C.peso<<" kg"<<endl;
    cout<<" --Edad: "<<C.edad<<" anios"<<endl;
    cout<<endl;
}

typedef cliente cl;
const cl noValidad = {0 , " " , " " , 0 , 0};

struct nodo{
    cl dato;
    nodo *sig;
};

class ListaCircSimple
{
    private:
        nodo *pInicio;
    
    public:
        ListaCircSimple();
        ~ListaCircSimple();
        void eliminarlistcircularrec(nodo *);
        void insInicio(cl);
        void mostrarlistaiter(void);
        bool borrado(cl);
        bool empty(void);

};

ListaCircSimple::ListaCircSimple()
{
    pInicio = NULL;
}

ListaCircSimple::~ListaCircSimple()
{
    if(pInicio)
    {
        eliminarlistcircularrec(pInicio);
        pInicio=NULL;
    }
}   

void ListaCircSimple::eliminarlistcircularrec(nodo *p)
{
    if(p->sig != pInicio)
    {
        eliminarlistcircularrec(p->sig);
    }
    delete p;
}

void ListaCircSimple::insInicio(cl dato)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato=dato;
    if (!pInicio)
    {
        pInicio=nuevo;
        pInicio->sig=pInicio;
    }else{
        nuevo->sig=pInicio;
        nodo *saltarin=pInicio;
        while (saltarin->sig !=pInicio)
        {
            saltarin=saltarin->sig;
        }
        saltarin->sig=nuevo;
        pInicio=nuevo; 
    }
}

void ListaCircSimple::mostrarlistaiter(void)
{
    nodo *saltarin;
    
    cout<<endl;
    if(pInicio)
    {
        saltarin=pInicio;
        do 
        {
            mostrardata(saltarin->dato);
            saltarin=saltarin->sig;
        }while (saltarin !=pInicio);
    }  
    
}

bool ListaCircSimple::empty(void)
{
    return pInicio==NULL;
}

bool ListaCircSimple::borrado(cl datoB)

{
    //Aqui en la funcion eliminar si elimina el primer nodo ingresado y los de enmedio pero 
    //no borra cuando cuando solo hay un nodo ni borrar el primero que se muestra en la lista de forma descendente
    //no encontre ilumnacion en lo que mas o menos me explicaron F
    nodo *borrar = pInicio, *aux;
    if (!pInicio)
    { 
        cout<<"\n No se encontro el nodo \n"<<endl;
        return false;
    }else 
    {                              
        while ((borrar->sig->dato).nombre.compare(datoB.nombre)!=0) 
            borrar = borrar->sig;
            
            if ((borrar->dato).nombre.compare(datoB.nombre)==0)
            {                              
                delete borrar;
                return true;
            }
            else 
            {
                if (!borrar->sig)
                { 
                    cout<<"\n No se encontro el nodo \n"<<endl;
                    return false;
                }else 
                {
                    aux = borrar->sig; 
                    borrar->sig = borrar->sig->sig;
                    delete aux;
                    return true;
                }
            }
        
    }
}


