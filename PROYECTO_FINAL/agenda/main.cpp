#include <iostream>
#include <fstream>
using namespace std;
string convertirMinusculas(string cad){

    int largo = cad.size();
    for(int i=0;i<largo;i++){
        cad[i] = toupper(cad[i]);
    }
    return cad;
}

class Correo{
string correo;

public:
    void setCorreo(string valor)
    {
        correo = valor;
    }
    string getCorreo()
    {
        return correo;
    }
};
class Persona
{
    //atributos
    string dni;
    string nombre;
    string apellidos;
    string sexo;
    string fecha;
    string correos;
    string telefonos;
    string direcciones;
public:
    //constructor
    Persona() {}
    //Metodos - setters and getters
    void setDni(string valor)
    {
        dni = valor;
    }
    void setNombre(string valor)
    {
        nombre = valor;
    }
    void setApellidos(string valor)
    {
        apellidos = valor;
    }
    void setSexo(string valor)
    {
       sexo= valor;
    }
     void setFecha(string valor)
    {
       fecha= valor;
    }
    void setCorreos(string valor)
    {
        correos = valor;
    }
    void setTelefonos(string valor)
    {
        telefonos = valor;
    }
    void setDirecciones(string valor)
    {
        direcciones = valor;
    }
    string getDni()
    {
        return dni;
    }
    string getNombre()
    {
        return nombre;
    }
    string getApellidos()
    {
        return apellidos;
    }
    string getSexo()
    {
        return sexo;
    }
    string getFecha()
    {
        return fecha;
    }
    string getCorreos()
    {
        return correos;
    }
    string getTelefonos()
    {
        return telefonos;
    }
    string getDirecciones()
    {
        return direcciones;
    }

};

class NodoAuxiliar {
    //Atributos
    string correo; //char, float, string, objeto
    NodoAuxiliar* enlace;//puntero..
public:
    //Constructor - inicializar los atributos
    NodoAuxiliar(string correo)
    {
        this->correo= correo;
        enlace = NULL;//por que no apuntamos a ningun nodo
    }
    //getter and setter
    string getCorreo()
    {
        return correo;
    }
    void setCorreo(string correo)
    {
        this->correo= correo;
    }
    NodoAuxiliar* getEnlace()
    {
        return this->enlace;
    }
    void setEnlace(NodoAuxiliar* enlace)
    {
        this->enlace = enlace;
    }
    void imprimir()
    {
        cout << "/-------------------\\" << endl;
        cout << "|Dato: " << correo << endl;
        cout << "|-------------------" << endl;
        cout << "|Enlace: " << enlace << endl;
        cout << "\\------------------/" << endl;
    }



};

class ListaAuxiliar{

NodoAuxiliar* inicio;

public:
friend Nodo();
    ListaAuxiliar(){

    this->inicio = NULL;
    }
void insertar(string dato)
{
    NodoAuxiliar* temp = new NodoAuxiliar(dato);
    if(EstaVacia())
    {
        inicio=temp;
    }
    else{

       NodoAuxiliar* recorrido = this->inicio;
       while(recorrido->getEnlace() != NULL)
       {
           recorrido = recorrido->getEnlace();
       }
       recorrido->setEnlace(temp);
    }
}
 bool EstaVacia()
    {
        if (inicio == NULL)
            return true;
        else
            return false;
    }
    void ingresaOtro(string dato){
        NodoAuxiliar* temp = new NodoAuxiliar(dato);
        if(EstaVacia())
        {
            inicio = temp;
        }
        else
        {
            NodoAuxiliar* recorrido = inicio;
                //insertar izquierda
                if(inicio->getEnlace()==NULL)
                    inicio->setEnlace(temp);
                else{
                    recorrido = recorrido->getEnlace();
                }

        }
    }
void ImprimeOtro()
{
   if(EstaVacia())
       {
           cout<<" No hay elementos guardado"<<endl;
       }
    else{
        NodoAuxiliar* recorrido= this->inicio;

         while (recorrido != NULL)
        {
            cout<<recorrido->getEnlace();
            recorrido = recorrido->getEnlace();
        }
}
}
};
class Nodo{
    Persona dato;
    ListaAuxiliar ll;
    int datos;
    Nodo* hijoDerecho;
    Nodo* hijoIzquierdo;
public:
    //Constructor - inicializar los atributos
    Nodo(Persona dato)
    {
        this->dato = dato;
        hijoDerecho = NULL;//por que no apuntamos a ningun nodo
        hijoIzquierdo = NULL;//por que no apuntamos a ningun nodo
    }
    Nodo(int datos)
    {
        this->datos = datos;
        hijoDerecho = NULL;//por que no apuntamos a ningun nodo
        hijoIzquierdo = NULL;//por que no apuntamos a ningun nodo
    }
     //getter and setter
    Persona getDato()
    {
        return dato;
    }
    void setDato(Persona dato)
    {
        this->dato = dato;
    }
    int getDatos()
    {
        return datos;
    }
    void setDatos(int datos)
    {
        this->datos = datos;
    }
    Nodo* getHijoIzquierdo()
    {
        return this->hijoIzquierdo;
    }
    void setHijoIzquierdo(Nodo* enlace)
    {
        this->hijoIzquierdo = enlace;
    }
    Nodo* getHijoDerecho()
    {
        return this->hijoDerecho;
    }
    void setHijoDerecho(Nodo* enlace)
    {
        this->hijoDerecho = enlace;
    }

     void imprimir()
    {
        cout << "/-------------------\\" << endl;
        cout << "|Edad: "<< datos<<endl;
        cout << "|DNI: " << dato.getDni() << endl;
        cout << "|Nombre: " << dato.getNombre() << endl;
        cout << "|Apellidos: " << dato.getApellidos() << endl;
        cout << "|Sexo: " << dato.getSexo() << endl;
        cout << "|Fecha: " << dato.getFecha() << endl;
        cout << "|Correo: "<<endl;
        ll.ImprimeOtro();
        cout << "|Telefonos: " << dato.getTelefonos() << endl;
        cout << "|Direcciones: " << dato.getDirecciones() << endl;
        cout << "|-------------------" << endl;
        cout << "|Izquierdo: " << hijoIzquierdo << "\tDerecho: " << hijoDerecho << endl;
        cout << "\\------------------/" << endl;
    }
void basico()
    {
        cout << "/-------------------\\" << endl;
        cout << "|Nombre: " << dato.getNombre() << endl;
        cout << "|Apellidos: " << dato.getApellidos() << endl;
        cout << "|Sexo: " << dato.getSexo() << endl;
        cout << "|Fecha: " << dato.getFecha() << endl;
        cout << "|-------------------" << endl;
        cout << "|Izquierdo: " << hijoIzquierdo << "\tDerecho: " << hijoDerecho << endl;
        cout << "\\------------------/" << endl;
    }

};
class Lista {

    Nodo* raiz;
public:
    Lista()
    {
        this->raiz = NULL;
    }
 Nodo* getRaiz()
    {
        return raiz;
    }
bool EstaVacia()
    {
        if (raiz == NULL)
            return true;
        else
            return false;
    }
void Insertarmos(Nodo* inicial, Persona dato)
{
    Nodo* temp = new Nodo(dato);
        if(EstaVacia())
        {
            raiz = temp;
        }
        else
        {
                //insertar izquierda
                if(inicial->getHijoIzquierdo()==NULL)
                    inicial->setHijoIzquierdo(temp);
                else
                    Insertarmos(inicial->getHijoIzquierdo(), dato);


                //insertar derecha
                if(inicial->getHijoDerecho()==NULL)
                    inicial->setHijoDerecho(temp);
                else
                    Insertarmos(inicial->getHijoDerecho(), dato);
        }
}

void Insertarmos(Persona dato){
        Insertarmos(raiz, dato);
    }

  void Imprimir()
    {
        int i = 1;
        Nodo* recorrido = this->raiz;
        cout << "Agenda****************************" << endl;
        while (recorrido != NULL)
        {
            cout << endl << "---> Nodo " << i++ << " -> DM: " << recorrido << endl;
            recorrido->imprimir();
           recorrido=recorrido->getHijoDerecho();
        }
        cout << "****************************" << endl << endl;
    }

 void Impri()
    {
        int i = 1;
        Nodo* recorrido = this->raiz;
        cout << "Agenda****************************" << endl;
        while (recorrido != NULL)
        {
            cout << endl << "---> Nodo " << i++ << " -> DM: " << recorrido << endl;
            recorrido->basico();
           recorrido=recorrido->getHijoDerecho();
        }
        cout << "****************************" << endl << endl;
    }
     void Vaciar()
    {
        raiz = NULL;
    }

  void InsertarAlFinal(Persona dato)
    {
        Nodo* temp = new Nodo(dato);
        if (EstaVacia())//lista vacia
        {
            raiz = temp;
        }
        else
        {
            Nodo* recorrido = this->raiz;
            while (recorrido->getHijoIzquierdo() != NULL)
            {
                recorrido = recorrido->getHijoIzquierdo();
            }
            recorrido->setHijoIzquierdo(temp);
        }
    }
    void InsertarAlInicio(Persona dato)
    {
        Nodo* temp = new Nodo(dato);
        if (EstaVacia())//lista vacia
        {
            raiz = temp;
        }
        else
        {
            Nodo* recorrido = this->raiz;
            this->raiz = temp;
            this->raiz->setHijoIzquierdo(recorrido);
        }
    }


    void InsertarAlFinal1(Persona dato)
    {
        Nodo* temp = new Nodo(dato);
        if (EstaVacia())//lista vacia
        {
            raiz = temp;
        }
        else
        {
            Nodo* recorrido = this->raiz;
            while (recorrido->getHijoDerecho() != NULL)
            {
                recorrido = recorrido->getHijoDerecho();
            }
            recorrido->setHijoDerecho(temp);
        }
    }
    void InsertarAlInicio1(Persona dato)
    {
        Nodo* temp = new Nodo(dato);
        if (EstaVacia())//lista vacia
        {
            raiz = temp;
        }
        else
        {
            Nodo* recorrido = this->raiz;
            this->raiz = temp;
            this->raiz->setHijoDerecho(recorrido);
        }
    }

    void BuscarHI(string dni)
    {
        bool encontrado = false;
        Nodo* recorrido = raiz;
        while (recorrido != NULL)
        {
            if (recorrido->getDato().getDni() == dni)
            {
                recorrido->imprimir();
                encontrado = true;
                break;
            }
            else
            {
                recorrido = recorrido->getHijoIzquierdo();
            }
        }
        if (encontrado == false)
        {
            cout << "El elemento buscado no fue encontrado." << endl;
        }
    }

    void BuscarNo(string nombre)
    {
        bool encontrado = false;
        Nodo* recorrido = raiz;
        while (recorrido != NULL)
        {
            if (recorrido->getDato().getNombre() == nombre)
            {
                recorrido->imprimir();
                encontrado = true;
                break;
            }
            else
            {
                 recorrido = recorrido->getHijoIzquierdo();
            }
        }
        if (encontrado == false)
        {
            cout << "El elemento buscado no fue encontrado." << endl;
        }
    }

  void BuscarAP(string apellido)
    {
        bool encontrado = false;
        Nodo* recorrido = raiz;
        while (recorrido != NULL)
        {
            if (recorrido->getDato().getApellidos() == apellido)
            {
                recorrido->imprimir();
                encontrado = true;
                break;
            }
            else
            {
                 recorrido = recorrido->getHijoIzquierdo();
            }
        }
        if (encontrado == false)
        {
            cout << "El elemento buscado no fue encontrado." << endl;
        }
    }

     void BuscarFE(string fenacimiento)
    {
        bool encontrado = false;
        Nodo* recorrido = raiz;
        while (recorrido != NULL)
        {
            if (recorrido->getDato().getFecha() == fenacimiento)
            {
                recorrido->imprimir();
                encontrado = true;
                break;
            }
            else
            {
                 recorrido = recorrido->getHijoIzquierdo();
            }
        }
        if (encontrado == false)
        {
            cout << "El elemento buscado no fue encontrado." << endl;
        }
    }

    void BuscarTo(string dni, string nombre, string apellido, string fe_nacimiento)
    {
        bool encontrado = false;
        Nodo* recorrido = raiz;
        while (recorrido != NULL)
        {
            if (recorrido->getDato().getDni() == dni && recorrido->getDato().getNombre() == nombre && recorrido->getDato().getApellidos() == apellido && recorrido->getDato().getFecha() == fe_nacimiento)
            {
                recorrido->imprimir();
                encontrado = true;
                break;
            }
            else
            {
                 recorrido = recorrido->getHijoIzquierdo();
            }
        }
        if (encontrado == false)
        {
            cout << "El elemento buscado no fue encontrado." << endl;
        }
    }
};




void MostrarMenu()
{
    cout<<endl;
     cout<< "                     ______________________________________________________"<< endl;
    cout<< "                    |                                                      |"<< endl;
    cout << "                    |               ********* MENU*********                |"<< endl;
     cout<< "                    |______________________________________________________|"<< endl;
    cout << "                    |   1.- |          Ver el contenido de la agenda       |" << endl;
     cout<< "                    |______________________________________________________|"<< endl;
    cout << "                    |   2.- |          Insertar contacto                   |" << endl;
    cout<< "                    |______________________________________________________|"<< endl;
    //cout << "                    |   3.- |          Insertar al inicio Hijo_Derecho     |" << endl;
     //cout<< "                    |______________________________________________________|"<< endl;
    //cout << "                    |   4.- |          Insertar al final Hijo_Derecho      |" << endl;
     //cout<< "                    |______________________________________________________|"<< endl;
    //cout << "                    |   5.- |          Insertar al inicio Hijo_Izquierdo   |" << endl;
     //cout<< "                    |______________________________________________________|"<< endl;
    //cout << "                    |   5.- |          Insertar al Final Hijo_Izquierdo    |" << endl;
     //cout<< "                    |______________________________________________________|"<< endl;
    cout << "                    |   3.- |          Buscar un elemento DNI              |" << endl;
    cout<< "                    |______________________________________________________|"<< endl;
    cout << "                    |   4.- |          Buscar un elemento NOMBRE           |" << endl;
      cout<< "                    |______________________________________________________|"<< endl;
    cout << "                    |   5.- |          Buscar un elemento APELLIDO         |" << endl;
      cout<< "                    |______________________________________________________|"<< endl;
    cout << "                    |   6.- |         Buscar un elemento FECHA_NACIMIENTO |" << endl;
      cout<< "                    |______________________________________________________|"<< endl;
    cout << "                    |   7.- |         Buscar un elemento D, N, F          |" << endl;
     cout<< "                    |______________________________________________________|"<< endl;
    cout << "                    |   8.- |         Modificar                           |" << endl;
     cout<< "                    |______________________________________________________|"<< endl;
    cout << "                    |   9.- |         Datos resumidos                     |" << endl;
     cout<< "                    |______________________________________________________|"<< endl;
    cout << "                    |   10.- |         Eliminar todos los contactos        |" << endl;
     cout<< "                    |______________________________________________________|"<< endl;
     cout << "                    |   11.- |         Ver registro en Agenda.txt          |" << endl;
     cout<< "                    |______________________________________________________|"<< endl;
    cout << "                    |   0.- |          Salir                               |" << endl;
    cout<< "                    |______________________________________________________|"<< endl;

    cout<<endl;
    cout<<endl;
    cout<<"      Digite una opcion del menu: ";
}
int opcion;
int registro = 0;
char sn[10];
void Editar()
{
   int opcionEditar;
   int hola;
   int informacionEditar;
   cout << "Numero de registro a editar: ";
   cin >> opcionEditar;
   Persona elemento = Persona();
   opcionEditar--;
   if (opcionEditar < registro)
   {
   cout << "2. DNI: ";
   cout << elemento.getNombre();
    cout << "3. Nombre: ";
    cout << elemento.getNombre();
   cout << "4. Apellido: ";
  cout << elemento.getNombre();
   cout << "5. Fecha nacimiento : ";
  cout << elemento.getNombre();
   cout << "5. Direccion: ";
  cout << elemento.getNombre();
   cout << "6. Telefono: ";
    cout << elemento.getNombre();
   cout << "7. Celular: ";
    cout << elemento.getNombre();
   cout << "8. Todo. ";
   cout << "9. Nada. ";
   cout << "Informacion a editar: ";
   cin >> informacionEditar;
   switch (informacionEditar)
   {
   case 1:
   break;
   case 2:
   break;
   case 3:

   break;
   case 4:
    cout << "1. Cedula: ";
   cin >> hola;

   break;
   case 5:
   cout << "1. Cedula: ";
   cin >> hola;

   break;
   case 6:
   cout << "6. Telefono: ";
   cout << "1. Cedula: ";
   cin >> hola;

   break;
   case 7:
    cout << "1. Cedula: ";
   cin >> hola;

   break;
   case 8:
   break;
   case 9:

   break;
   default:
   cout << "Operacion incorrecta. Escriba nuevamente la informacion a editar.";
   Editar();
   break;
   }

   }

   else
   {
   cout << "Numero de registro no existente.";

   }
}
class ArbolBinario{
    Nodo* raiz;
public:
    ArbolBinario(){
        raiz = NULL;
    }
    Nodo* getRaiz()
    {
        return raiz;
    }

    bool EstaVacia()
    {
        if (raiz == NULL)
            return true;
        else
            return false;
    }
    void Insertar(Nodo* inicial, int datos){
        Nodo* temp = new Nodo(datos);
        if(EstaVacia())
        {
            raiz = temp;
        }
        else
        {
            if(datos < inicial->getDatos())
            {
                //insertar izquierda
                if(inicial->getHijoIzquierdo()==NULL)
                    inicial->setHijoIzquierdo(temp);
                else
                    Insertar(inicial->getHijoIzquierdo(), datos);
            }
            else
            {
                //insertar derecha
                if(inicial->getHijoDerecho()==NULL)
                    inicial->setHijoDerecho(temp);
                else
                    Insertar(inicial->getHijoDerecho(), datos);
            }
        }
    }
    void Insertar(int datos){
        Insertar(raiz, datos);
    }
    //preorder, inorder, postorder
    //-> impresión del arbol tal como se creo
    void PreOrden(Nodo* inicial){
        //condición de finalización
        if(inicial==NULL){
            return;
        }
        else{
            cout<<inicial->getDatos()<<" ";
            PreOrden(inicial->getHijoIzquierdo());
            PreOrden(inicial->getHijoDerecho());
        }
    }
    void InOrden(Nodo* inicial){
        //condición de finalización
        if(inicial==NULL){
            return;
        }
        else{
            InOrden(inicial->getHijoIzquierdo());
            cout<<inicial->getDatos()<<" ";//raiz
            InOrden(inicial->getHijoDerecho());
        }
    }

    void PostOrden(Nodo* inicial){
        //condición de finalización
        if(inicial==NULL){
            return;
        }
        else{
            PostOrden(inicial->getHijoIzquierdo());
            PostOrden(inicial->getHijoDerecho());
            cout<<inicial->getDatos()<<" ";//raiz
        }
    }
    void PreOrden(){
        PreOrden(raiz);
    }
    void InOrden(){
        InOrden(raiz);
    }
    void PostOrden(){
        PostOrden(raiz);
    }

};
Persona LeerDatosPersona()
{

    Persona persona = Persona();
    ListaAuxiliar l1;
    string temporal;
    string tempora2;
    int temp;
    cout<<endl;
    cout<<"     REGISTRANDO EN LA AGENDA"<<endl;
    cout<<"     ------------------------";
    cout<<endl;
    cout << "Ingrese DNI: ";
    fflush(stdin);
    cin >> temporal;
    persona.setDni(temporal);
    cout<<endl;
    cout << "Ingrese Nombre: ";
    fflush(stdin);
    getline(cin,temporal);
    temporal=convertirMinusculas(temporal);
    persona.setNombre(temporal);
    cout<<endl;
    cout << "Ingrese Apellidos: ";
     fflush(stdin);
    getline(cin,temporal);
    temporal=convertirMinusculas(temporal);
    persona.setApellidos(temporal);
    cout<<endl;
    cout << "Ingrese el Genero: ";
    fflush(stdin);
    getline(cin,temporal);
    temporal=convertirMinusculas(temporal);
    persona.setSexo(temporal);
    cout<<endl;
    cout << "Ingrese la Fecha de Nacimiento: ";
     fflush(stdin);
    getline(cin,temporal);
    temporal=convertirMinusculas(temporal);
    persona.setFecha(temporal);
   cout<<endl;
    cout << "Ingrese el Correo: ";
    fflush(stdin);
    temporal=convertirMinusculas(temporal);
    int op=1;
    while(op!=2)
    {
        if(op==1)
        {
        fflush(stdin);
        cout<<"Ingrese Su Correo"<<endl;
        getline(cin,temporal);
        l1.ingresaOtro(temporal);
        cout<<endl;
        }
       cout<<"Desea Ingresar Otro Correo? "<<endl;
        cout<<"1.- SI"<<endl;
        cout<<"2.- NO"<<endl;
        cin>>op;

    }


  cout<<endl;
    cout << "Ingrese su Telefono: ";
    fflush(stdin);
    cin >> temporal;
    persona.setTelefonos(temporal);
    cout<<endl;
    cout << "Ingrese su Direccion: ";
     fflush(stdin);
    cin >> temporal;
    persona.setDirecciones(temporal);
    cout<<endl;
    {
////// Entrada/Salida a archivo de texto "Agenda.txt"
   ofstream archivo;
   archivo.open("prueva.txt", ios::app);

    archivo << "DNI: " << persona.getDni()<< endl;
     archivo << "Nombre: " << persona.getNombre()<< endl;
      archivo << "Apellidos: " << persona.getApellidos()<< endl;
       archivo << "Genero: " << persona.getSexo()<< endl;
        archivo << "Fecha nacimiento: " << persona.getFecha()<< endl;
         archivo << "Correo: " << persona.getCorreos()<< endl;
          archivo << "Telefono: " << persona.getTelefonos()<< endl;
           archivo << "Direccion: " << persona.getDirecciones()<< endl;
   archivo.close();
   ////// Fin de Entrada/Salida a archivo de texto "Agenda.txt"
   cout << endl << "Contacto anadido." << endl;
   }

    return persona;
    /*
    Persona persona = Persona();
    string temporal;
    int temp;
     cout<<endl;
    cout<<"     REGISTRANDO EN LA AGENDA"<<endl;
    cout<<"     ------------------------";
    cout<<endl;
  cout<<"      _______________________________________________________________"<<endl;
    cout << "    |       Ingrese Edad:                 |";
    cin >> temp;
   cout<<"      ---------------------------------------------------------------"<<endl;
    persona.setEdad(temp);
    cout<<endl;
cout<<"      _______________________________________________________________"<<endl;
    cout << "    |      Ingrese DNI:                   | ";
    cin >> temporal;
cout<<"      ---------------------------------------------------------------"<<endl;
    persona.setDni(temporal);
    cout<<endl;
cout<<"      _______________________________________________________________"<<endl;
    cout << "    |     Ingrese Nombre:                 | ";
    cin >> temporal;
cout<<"      ---------------------------------------------------------------"<<endl;
    persona.setNombre(temporal);
    cout<<endl;
cout<<"      _______________________________________________________________"<<endl;
    cout << "          Ingrese Apellidos:              | ";
    cin >> temporal;
 cout<<"      ---------------------------------------------------------------"<<endl;
    persona.setApellidos(temporal);
    cout<<endl;
cout<<"      _______________________________________________________________"<<endl;
    cout << "          Ingrese el Genero:              | ";
    cin >> temporal;
cout<<"      ---------------------------------------------------------------"<<endl;
    persona.setSexo(temporal);
    cout<<endl;
cout<<"      _______________________________________________________________"<<endl;
    cout << "          Ingrese la Fecha de Nacimiento: | ";
    cin >> temporal;
cout<<"      ---------------------------------------------------------------"<<endl;
    persona.setFecha(temporal);
   cout<<endl;

cout<<"      _______________________________________________________________"<<endl;
    cout << "           Ingrese el Correo:             | ";
    cin >> temporal;
cout<<"      ---------------------------------------------------------------"<<endl;
    persona.setCorreos(temporal);
  cout<<endl;

cout<<"      _______________________________________________________________"<<endl;
    cout << "           Ingrese su Telefono:           | ";
    cin >> temporal;
cout<<"      ---------------------------------------------------------------"<<endl;
    persona.setTelefonos(temporal);
    cout<<endl;
cout<<"      _______________________________________________________________"<<endl;
    cout << "           Ingrese su Direccion:          | ";
    cin >> temporal;
  cout<<"      ---------------------------------------------------------------"<<endl;
    persona.setDirecciones(temporal);
    cout<<endl;
    cout<<endl;
    cout << endl << "  Contacto anadido." << endl;
    cout<<endl;
    return persona;
    */
}

int main()
{
    ArbolBinario arbol = ArbolBinario();
    Lista agenda = Lista();
    int posicion;
    string dni;
    int edad;
    int auxiliar;
     string nombre;
      string apellido;
       string fenacimiento;
    Persona elemento = Persona();
    int opcion;
    do
    {
        MostrarMenu();
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
            system("cls");
        case 0:
            cout << "Ingeniería de Sistemas, hasta luego." << endl;
            break;
        case 1:
            agenda.Imprimir();
            system("pause");
            system("cls");
            break;
        case 2:
            cout<<"Digite su edad: ";
            cin>>edad;
            while(edad<12 || edad>80){
                cout<<"Edad No valida Digite nuevamente "<<endl;
                cin>>edad;
            }
            arbol.Insertar(edad);
            cout<<endl;
            cout<<"  ***Mostrando menu*** "<<endl;
            cout<<"1.   PostOrden "<<endl;
            cout<<"2.   InOrder "<<endl;
            cout<<"3.   Preorden "<<endl;
            cout<<"3.   Registrar persona "<<endl;
            int vamos;
            cout<<"Dite un aopcion: "; cin>>vamos;
            if(vamos==1)
              arbol.PostOrden();
            else if(vamos==2)
                arbol.InOrden();
            else if(vamos==3)
                arbol.PreOrden();
            else if(vamos==4)
                agenda.Insertarmos(LeerDatosPersona());
            cout<<endl;

            system("pause");
            system("cls");
            break;
            /*
        case 3:
            agenda.InsertarAlInicio(LeerDatosPersona());
             system("pause");
            system("cls");
            break;

        case 2:
            agenda.InsertarAlFinal(LeerDatosPersona());
             system("pause");
            system("cls");
            break;
        case 3:
            agenda.InsertarAlInicio1(LeerDatosPersona());
            system("pause");
            system("cls");
            break;
        case 4:
            agenda.InsertarAlFinal1(LeerDatosPersona());
            system("pause");
            system("cls");
            break;
            */
         case 3:
            cout << "Digite el numero de dni: " << endl;
            cin >> dni;
            agenda.BuscarHI(dni);
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "Digite el nombre: " << endl;
            cin >> nombre;
            agenda.BuscarNo(nombre);
            system("pause");
            system("cls");
            break;
         case 5:
            cout << "Digite el Apellido: " << endl;
            cin >> apellido;
            agenda.BuscarAP(apellido);
            system("pause");
            system("cls");
            break;
         case 6:
            cout << "Digite el Fecha_nacimiento: " << endl;
            cin >> fenacimiento;
            agenda.BuscarFE(fenacimiento);
            system("pause");
            system("cls");
             break;
        case 7:
            cout << "Digite el todo: " << endl;
            cout<< "Dni:";cin>>dni;
            cout<<endl;
             cout<< "Nombre:";cin>>nombre;
            cout<<endl;
            cout<< "Apellido:";cin>>apellido;
            cout<<endl;
            cout<< "FECHa:";cin>>fenacimiento;
            cout<<endl;
            agenda.BuscarTo(dni, nombre,apellido,fenacimiento);
            system("pause");
            system("cls");
             break;
        case 9:
            agenda.Impri();
            system("pause");
            system("cls");
            break;

        case 10:
            agenda.Vaciar();
            cout<<endl;
            cout<<endl;
            cout<<" ** Se elemino con exito todos los contactos**"<<endl;
            system("pause");
            system("cls");
            break;
        case 11:
            system("prueva.txt");
            break;
        default:
            cout << "Opción no valida." << endl;
            break;
        }

    } while (opcion != 0);


    /*Nodo nodo = Nodo(5);
    nodo.imprimir();
    Nodo* nodo2 = new Nodo(15);
    nodo2->imprimir();
    nodo.setHijoDerecho(nodo2);
    nodo.imprimir();*/
    //ArbolBinario arbol = ArbolBinario();

    return 0;
}
