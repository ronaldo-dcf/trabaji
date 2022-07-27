#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

//Prototipo de funciones.
void Anadir();
void Eliminar();
void Editar();
void Ver();
void VerTodo();

//Definicion de estructura.
struct informacion
{
   char cedula [25];
   char nombre[25];
   char apellido[25];
   char nacimiento[25];
   char direccion[100];
   char telefono[25];
   char celular[25];

   }
persona[25];

//Declaracion de variables.
int opcion;
int registro = 0;
char sn[10];


int main()
{

   cout << "1. Anadir un contacto." << endl << endl;
   cout << "2. Eliminar un contacto." << endl << endl;
   cout << "3. Editar un contacto." << endl << endl;
   cout << "4. Ver informacion de un contacto." << endl << endl;
   cout << "5. Ver todos los contactos." << endl << endl;
   cout << "6. Ver registro en Agenda.txt" << endl << endl;
cout << "7. Salir." << endl << endl;
   cout << "Numero de operacion a realizar: ";
   cin >> opcion;
   switch (opcion)
   {
      case 1:
      Anadir();
      break;

      case 2:
      Eliminar();
      break;

      case 3:
      Editar();
      break;

      case 4:
      Ver();
      break;

      case 5:
      VerTodo();
      break;

      case 6:
      system("Agenda.txt");
      main();
      break;

      case 7:
      exit(0);
      break;

      default:
      cout << "Operacion incorrecta. Escriba nuevamente la operacion a realizar";
      main();
      break;
   }
return 0;
}
//Fin main.

//Definicion de funciones.
void Anadir()
{
   cout << "Escriba la siguiente informacion del contacto.";
   cout << "1. Cedula: ";
   cin >> persona[registro].cedula;
   cout << "2. Nombre: ";
   cin >> persona[registro].nombre;
   cout << "3. Apellido: ";
   cin >> persona[registro].apellido;
   cout << "4. Fecha nacimiento: ";
   cin >> persona[registro].nacimiento;
   cout << "5. Direccion: ";
   cin >> persona[registro].direccion;
   cout << "6. Telefono: ";
   cin >> persona[registro].telefono;
   cout << "7. Celular: ";
   cin >> persona[registro].celular;
   {
////// Entrada/Salida a archivo de texto "Agenda.txt"
   ofstream archivo;
   archivo.open("Agenda.txt", ios::app);
   archivo << "Cedula: " << persona[registro].cedula << endl;
   archivo << "Nombre: " << persona[registro].nombre << endl;
   archivo << "Apellido: " << persona[registro].apellido << endl;
   archivo << "Fecha nacimiento: " << persona[registro].nacimiento << endl;
   archivo << "Direccion: " << persona[registro].direccion << endl;
   archivo << "Telefono: " << persona[registro].telefono << endl;
   archivo << "Celular: " << persona[registro].celular << endl;
   archivo.close();
   ////// Fin de Entrada/Salida a archivo de texto "Agenda.txt"
   registro++;
   cout << endl << "Contacto anadido." << endl;
   }
}

void Eliminar()
{
   int opcionEliminar;
   cout << "Numero de registro a eliminar: ";
   cin >> opcionEliminar;
   opcionEliminar--;
if (opcionEliminar < registro)
   {
   cout << "1. Cedula: ";
   cout << persona[opcionEliminar].cedula;
   cout << "2. Nombre: ";
   cout << persona[opcionEliminar].nombre;
   cout << "3. Apellido: ";
   cout << persona[opcionEliminar].apellido;
   cout << "4. Fecha nacimiento: ";
   cout << persona[opcionEliminar].nacimiento;
   cout << "5. Direccion: ";
   cout << persona[opcionEliminar].direccion;
   cout << "6. Telefono: ";
   cout << persona[opcionEliminar].telefono;
   cout << "7. Celular: ";
   cout << persona[opcionEliminar].celular;
   do{
   cout << "Eliminar contacto de la agenda? [S/N]: ";
   cin >> sn;
   if((strcmp(sn,"s")==0)||(strcmp(sn,"S")==0))
   {
   persona[opcionEliminar]=persona[registro];
   cout << endl << "Contacto eliminado." << endl;
   main();
   }
   if((strcmp(sn,"n")==0)||(strcmp(sn,"N")==0))
   {
   cout << "Contacto no eliminado.";
   main();
   }
   }while ((sn!="S")||(sn!="s")||(sn!="N")||(sn!="n"));
   }

   else
   {
   cout << "Numero de registro no existente.";
   main();
   }
}

void Editar()
{
   int opcionEditar;
   int informacionEditar;
   cout << "Numero de registro a editar: ";
   cin >> opcionEditar;
   opcionEditar--;
   if (opcionEditar < registro)
   {
   cout << "1. Cedula: ";
   cout << persona[opcionEditar].cedula;
   cout << "2. Nombre: ";
   cout << persona[opcionEditar].nombre;
   cout << "3. Apellido: ";
   cout << persona[opcionEditar].apellido;
   cout << "4. Fecha nacimiento : ";
   cout << persona[opcionEditar].nacimiento;
   cout << "5. Direccion: ";
   cout << persona[opcionEditar].direccion;
   cout << "6. Telefono: ";
   cout << persona[opcionEditar].telefono;
   cout << "7. Celular: ";
   cout << persona[opcionEditar].celular;
   cout << "8. Todo. ";
   cout << "9. Nada. ";
   cout << "Informacion a editar: ";
   cin >> informacionEditar;
   switch (informacionEditar)
   {
   case 1:
   cout << "1. Cedula: ";
   cin >> persona[opcionEditar].cedula;
   break;
   case 2:
   cout << "2. Nombre: ";
   cin >> persona[opcionEditar].nombre;
   break;
   case 3:
   cout << "3. Apellido: ";
   cin >> persona[opcionEditar].apellido;
   break;
   case 4:
   cout << "4. Fecha nacimiento: ";
   cin >> persona[opcionEditar].nacimiento;
   break;
   case 5:
   cout << "5. Direccion: ";
   cin >> persona[opcionEditar].direccion;
   break;
   case 6:
   cout << "6. Telefono: ";
   cin >> persona[opcionEditar].telefono;
   break;
   case 7:
   cout << "7. Celular: ";
   cin >> persona[opcionEditar].celular;
   break;
   case 8:
   cout << "1. Cedula: ";
   cin >> persona[opcionEditar].cedula;
   cout << "2. Nombre: ";
   cin >> persona[opcionEditar].nombre;
   cout << "3. Apellido: ";
   cin >> persona[opcionEditar].apellido;
   cout << "4. Fecha nacimiento: ";
   cin >> persona[opcionEditar].nacimiento;
   cout << "5. Direccion: ";
   cin >> persona[opcionEditar].direccion;
   cout << "6. Telefono: ";
   cin >> persona[opcionEditar].telefono;
   cout << "7. Celular: ";
   cin >> persona[opcionEditar].celular;
   break;
   case 9:
   main();
   break;
   default:
   cout << "Operacion incorrecta. Escriba nuevamente la informacion a editar.";
   Editar();
   break;
   }
   main();
   }

   else
   {
   cout << "Numero de registro no existente.";
   main();
   }
}

void Ver()
{
   int ver;
   cout << "Numero de registro a ver: ";
   cin >> ver;
   ver--;
   if (ver < registro)
   {
   cout << "1. Cedula: ";
   cout << persona[ver].cedula;
   cout << "2. Nombre: ";
   cout << persona[ver].nombre;
   cout << "3. Apellido: ";
   cout << persona[ver].apellido;
   cout << "4. Fecha nacimiento: ";
   cout << persona[ver].nacimiento;
   cout << "5. Direccion: ";
   cout << persona[ver].direccion;
   cout << "6. Telefono: ";
   cout << persona[ver].telefono;
   cout << "7. Celular: ";
   cout << persona[ver].celular;
   main();
   }
   else
   {
   cout << "Numero de registro no existente.";
   main();
   }
}

void VerTodo()
{
   int verTodo;
   for (verTodo = 0; verTodo < registro; verTodo++)
   {
   cout << "1. Cedula: ";
   cout << persona[verTodo].cedula;
   cout << "2. Nombre: ";
   cout << persona[verTodo].nombre;
   cout << "3. Apellido: ";
   cout << persona[verTodo].apellido;
   cout << "4. Fecha nacimiento: ";
   cout << persona[verTodo].nacimiento;
   cout << "5. Direccion: ";
   cout << persona[verTodo].direccion;
   cout << "6. Telefono: ";
   cout << persona[verTodo].telefono;
   cout << "7. Celular: ";
   cout << persona[verTodo].celular;
   system("pause > nul");
   }
   main();
}
