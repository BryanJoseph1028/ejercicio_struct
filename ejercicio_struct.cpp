#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
const char *nombre_archivo = "regristro_struct.txt";

void abrir_archivo();
void ingresar_empleado();

struct empleado{
	string nombre;
	string apellidos;
	string profesion;
	string sueldo;
	string bonif;	
};
int main(){
	abrir_archivo();
	ingresar_empleado();
}
void abrir_archivo(){
	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivo,ios::in);
	
	if(archivo.fail()){
		cout<<"no se puede abrir el archivo";
		exit(1);
	}
	else{
		do{getline(archivo,contenido);
		cout<<contenido<<endl;
		}while(archivo.eof()==false);
	}
} 
void ingresar_empleado(){
	ofstream archivo;
	char continuar;
	empleado obj_empleado;
	archivo.open(nombre_archivo,ios::out);
		if(archivo.fail()){
		cout<<"no se puede abrir el archivo";
		exit(1);
	}
	else{
		do{
			fflush(stdin);
			cout<<"ingrese el nombre del empleado: ";
			getline(cin,obj_empleado.nombre);
			archivo<<obj_empleado.nombre<<endl;
			cout<<"ingrese el apellido del empleado: ";
			getline(cin,obj_empleado.apellidos);
			archivo<<obj_empleado.apellidos<<endl;
			cout<<"ingrese la profesion del empleado: ";
			getline(cin,obj_empleado.profesion);
			archivo<<obj_empleado.profesion<<endl;
			cout<<"ingrese el sueldo del empleado: ";
			getline(cin,obj_empleado.sueldo);
			archivo<<obj_empleado.sueldo<<endl;
			cout<<"ingrese la bonificacion del empleado: ";
			getline(cin,obj_empleado.bonif);
			archivo<<obj_empleado.bonif<<endl;
			
			cout<<"desea agregar oto campo?";
			cin>>continuar;
		}while((continuar=='s')||(continuar=='S'));
	}
	archivo.close();
	abrir_archivo;
}

