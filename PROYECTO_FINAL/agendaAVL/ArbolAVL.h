#include<string.h>

class nodo{
public:
	char nombre[50];
	char telefono[10];
	char direccion[50];
	char email[50];
	int eq;
	nodo *Izdo, *Dcho;
	nodo(char nom[50],char tel[10],char dir[50],char em[50], nodo* Iz=NULL, nodo* Dr=NULL,int t=0){
	strcpy(nombre,nom);
	strcpy(telefono,tel);
	strcpy(direccion,dir);
	strcpy(email,em);
	eq=t;
	Izdo=Iz;
	Dcho=Dr;
	}
 class arbol;
};
typedef nodo* tarbol;
class arbol{
public:
      tarbol miarbolito;
    	int pe;
		int a;
			arbol(){
			miarbolito=NULL;
			pe=0;
			a=0;
	  		  }
      void insertar(tarbol &aux,char nom[50],char tel[10],char dir[50],char em[50]);
      tarbol buscar(tarbol aux,char nom[50]);
      void borrar(tarbol &aux,char nom[50]);
      void actualizar(tarbol &temp, tarbol &aux);
      void balance(tarbol &aux, char nom[50]);
      int maximo(int a, int b);
      void IDN(tarbol aux);
      void RDD(tarbol &aux);
      void RDI(tarbol &aux);
      void RID(tarbol &aux);
      void RII(tarbol &aux);
      int Peso(tarbol aux);
      int altura(tarbol &aux);
};
