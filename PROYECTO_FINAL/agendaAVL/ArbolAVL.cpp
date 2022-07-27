#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "ArbolAVL.h"
using namespace std;

int main()
{

  arbol A;
  tarbol b;
  char nombre[50];
  char telefono[10];
  char direccion[50];
  char email[50];
  char op;
  int t;
 
  do{
	  fflush(stdin);
      system("cls");
	  cout<<"\tMenu\n\n";
	  cout<<"\t1- Agregar\n";
	  cout<<"\t2- Buscar\n";
	  cout<<"\t3- Eliminar\n";
	  cout<<"\t4- Mostrar\n";
	  cout<<"\t5- Estadistica\n";
	  cout<<"\t6- Salir\n\n";
	  cout<<"Ingrese la opcion: ";
	  cin>>op;
	  fflush(stdin);
	  switch(op)
	  {
		case '1':	{
			fflush(stdin);
		    system("cls");
			cout<<"\nIngrese Nombre: ";
			gets(nombre);
			fflush(stdin);
			do{
			cout<<"\nIngrese Telefono 0000-0000: ";
			gets(telefono);
			fflush(stdin);
			t=strlen(telefono);
			  }while(t!=9);
			cout<<"\nIngrese Direccion: ";
			gets(direccion);
			fflush(stdin);
			cout<<"\nIngrese Email: ";
			gets(email);
			fflush(stdin);
			A.insertar(A.miarbolito,nombre,telefono,direccion,email);
			break;
					}
		case '2':{
			fflush(stdin);
			system("cls");
			cout<<"\nNombre: ";
			gets(nombre);
			fflush(stdin);
			b=A.buscar(A.miarbolito,nombre);
			if(b!=NULL)
			{
			fflush(stdin);
			system("cls");
			cout<<"\nContacto encontrado:";
			cout<<"\n\nNombre: "<<b->nombre;
			cout<<"\nTelefono: "<<b->telefono;
			cout<<"\nEmail: "<<b->email;
			cout<<"\nDireccion: "<<b->direccion;
			system("pause");
			}
			  break;
			     }
		case '3':{
			system("cls");fflush(stdin);
			cout<<"\nNombre: ";
			gets(nombre);
			fflush(stdin);
			A.borrar(A.miarbolito,nombre);
			system("pause");
			break;
				 }
		case '4':{
			system("cls");
            cout<<"\n\n";
			A.IDN(A.miarbolito);system("pause");
			break; 
			     }
		case '5':{
		    system("cls");
            A.pe=0;
			cout<<"\nNumero de contactos: "<<A.Peso(A.miarbolito)<<"\n\n";
			system("pause");
			break;
			     }
    }
  }while(op!='6');
  return 0;    
}
void arbol::insertar( tarbol &aux,char nom[50],char tel[10],char dir[50],char em[50])
{
	if(aux==NULL)
	{			
	aux=new nodo(nom,tel,dir,em);
    balance(aux,nom);	    
	}
	else 
	{
		if (strcmpi(nom,aux->nombre)<0)
			{
			insertar(aux->Izdo,nom,tel,dir,em); 
			}
			else 
			{	if(strcmpi(nom,aux->nombre)>0)
				{
				insertar(aux->Dcho,nom,tel,dir,em);
				}
			}
	}
}
tarbol arbol::buscar(tarbol aux,char nom[50])
{  
	if (aux==NULL)
	{  
		return NULL;
	}
	else
	{
		if (strcmpi(nom,aux->nombre)==0)
		{
			return aux;
		}
		else
		{	if (strcmpi(nom,aux->nombre)<0)
			{
				return buscar(aux->Izdo, nom);
			}
			else
			{
				return buscar(aux->Dcho, nom);
			}
		}
	}
}
void arbol::borrar(tarbol &aux,char nom[50])
{
	if (aux==NULL)
	{
		cout<<"contacto no encontrado no encontrado !!\n\n";
	}
	else
	{if (strcmpi(nom,aux->nombre)<0)
	  {
		  borrar(aux->Izdo, nom);
	  }
	   else 
	   {
		   if (strcmpi(nom,aux->nombre)>0)
		   {
				borrar(aux->Dcho,nom);
		   }
				else
				{ 
				tarbol temp=aux;
				if (aux->Izdo== NULL)
					{
					aux = aux->Dcho;
					}
					else 
					{
						if (aux->Dcho == NULL)
						{
								aux = aux->Izdo;
						}
						else 
						{
							actualizar(temp,temp->Izdo);
						}
						delete  temp;
					
					}
				}
	  }
	}
}
void arbol::actualizar(tarbol &temp, tarbol &aux)
{ 
	if(aux->Dcho!=NULL)
	{
		actualizar(temp,aux->Dcho);}

	else
	{
		strcpy(temp->nombre,aux->nombre);
		strcpy(temp->telefono,aux->telefono);
		strcpy(temp->email,aux->email);
		strcpy(temp->direccion,aux->direccion);
	    temp=aux;
		aux=temp->Izdo;
	}
}
void arbol::IDN( tarbol aux)
{
     if(aux!=NULL)
	 { 
          IDN(aux->Izdo);
          if(strcmpi(aux->nombre,"M")!=0)
		  {
              cout<<"Nombre: "<< aux->nombre<<" "<<endl;
	          cout<<"Telefono: "<< aux->telefono<<" "<<endl;
              cout<<"Email: "<< aux->email<<" "<<endl;
              cout<<"Direccion: "<< aux->direccion<<" "<<endl<<endl;
              cout<<"\n\n";
	       }
           IDN(aux->Dcho);
      }
}

int arbol::Peso( tarbol aux)
{
   	if(aux!=NULL)
	{
		pe++; 
		Peso(aux->Izdo); 
		Peso(aux->Dcho);
		return  pe;
	}
	else
	{
		return -1;
    }
}
int arbol::maximo(int a, int b)
{ 
	if(a > b)
	return a;
	else return b;
}
int arbol::altura(tarbol &aux)
{
	if(aux)
	return	aux->eq;
	else return -1;		  
}
void arbol::balance (tarbol &aux, char nom[50])
{ 
 	if (aux)
	{       
		if (strcmpi(nom,(aux)->nombre)>0)
		{balance(aux->Dcho,nom);
		}
		else {if (strcmpi(nom,(aux)->nombre)<0)
				{
					balance(aux->Dcho,nom);
				}
			 }
        int fe=altura(aux->Dcho)-altura(aux->Izdo);
		switch (fe)
		{
		case -2:
			{
				if (altura(aux->Izdo->Izdo) > altura(aux->Izdo->Dcho))
				RII(aux);
				else RID(aux);
				break;
			}
		case 2:
			{
			if (altura(aux->Dcho->Dcho) > altura(aux->Dcho->Izdo))
				RDD(aux);
			else 
				  RDI(aux);
			break;
			}
		default:
			aux->eq = maximo(altura(aux->Izdo),altura(aux->Dcho)) +1;
		}
	}
}
void arbol::RII(tarbol &aux){
        tarbol n1=aux->Izdo;
		aux->Izdo=n1->Dcho;
		n1->Dcho=aux;
		aux=n1;
		n1 = aux->Dcho;
		if(n1)
		n1->eq = maximo(altura(n1->Izdo),altura(n1->Dcho))+1;
		aux->eq = maximo(altura(aux->Izdo),altura(aux->Dcho))+1; 
}
void arbol::RDD(tarbol &aux){
     tarbol temp;
     temp=aux->Dcho;
     aux->Dcho=temp->Izdo;
     temp->Izdo=aux;
     aux=temp;
     temp = aux->Izdo;
     if(temp)
     temp->eq = maximo(altura(temp->Izdo),altura(temp->Dcho))+1;
     aux->eq = maximo(altura(aux->Izdo),altura(aux->Dcho))+1;
}
void arbol::RID(tarbol &aux){
	 RDD(aux->Izdo);
     RII(aux);
}
void arbol::RDI(tarbol &aux){
	RII(aux->Dcho);
	RDD(aux);
}
