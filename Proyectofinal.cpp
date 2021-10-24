#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "proyecto.dat";

struct Proyecto{
	
	char ing[50];
	char esp[50];
	char concepto[2000];
};
	
	
	void ingresar();
	void abrir();
 	void modificar();
 	void buscar();
 	void eliminar();

int main (){
 	int menu;
 	
 	do{
 		
		system("cls");
	 	cout<<"      ***************************"<<endl;
		cout<<"                 MENU"<<endl<<endl;
		cout<<"        1. INGRESAR REGISTRO"<<endl;
		cout<<"        2. ABRIR BASE DE DATOS"<<endl;
		cout<<"        3. MODIFICAR REGISTRO"<<endl;
		cout<<"        4. ELIMINAR REGISTRO"<<endl;
		cout<<"        5. BUSCAR REGISTRO"<<endl;
		cout<<"        0. SALIR"<<endl;
		cout<<"      ***************************"<<endl<<endl;
		cin>>menu;
		system("cls");
		
		if (menu==1){
		ingresar();		
		}
		else if(menu==2){
		abrir();	
		}	 
		else if(menu==3){
		modificar();		
		}
		else if(menu==4){
		cout<<"TRABAJANDO EN ELLO";
		} 
		else if(menu==5){
		buscar();
    	}
    	
    }while(menu>0);
	return 0;	
}

//INGRESAR REGISTRO 
void ingresar(){
	
	char otro;
	FILE* archivo = fopen(nombe_archivo, "ab");
		
		 Proyecto proyecto;
		 string ingl,espa, concep;
		do{
			fflush(stdin);
			
			cout<<"INGRESE PALABRA:       ";
			getline(cin,ingl);
    		strcpy(proyecto.ing, ingl.c_str()); 
			
			cout<<"INGRESE TRADUCCION:    ";
			getline(cin,espa);
			strcpy(proyecto.esp, espa.c_str()); 
		
			cout<<"INGRESE FUNCIONALIDAD: ";
			getline(cin,concep);
			strcpy(proyecto.concepto, concep.c_str());
		
		fwrite( &proyecto, sizeof(Proyecto), 1, archivo );
		
			cout<<"DESEA AGREGAR OTRO REGISTRO S/N : ";
			cin>>otro;
			
		} while((otro=='S') || (otro=='s') );
		
	
	fclose(archivo);
	system("cls");
}

//ABRIR MENU
void abrir(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Proyecto proyecto;
	int cont;
	fread ( &proyecto, sizeof(Proyecto), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout<<"                     BASE DE DATOS                                  "<<endl;
		do{
		cout <<"____________________________________________________________________"<<endl;
		cout <<"       ID:           "<<cont<<endl<<cont<<"PALABRA:      "<<proyecto.ing<<endl<<"TRADUCCION:   "<<proyecto.esp<<endl<<"DEFINICION:   "<<proyecto.concepto<<endl;
        
        
		fread ( &proyecto, sizeof(Proyecto), 1, archivo );
		cont++;
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
		system("pause");
		system("cls");
	}

void modificar(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int busca;
		string  ingle, espa, concep;	
    	Proyecto proyecto;
    
			cout <<"INGRESE EL ID DE REGISTRO A MODIFICAR: ";
    		cin >> busca;
    		fseek ( archivo, busca * sizeof(Proyecto), SEEK_SET ); 
	
			
			cout<<"INGRESE PALABRA:       ";
			getline(cin,ingle);
    		strcpy(proyecto.ing, ingle.c_str()); 
			
			cout<<"INGRESE TRADUCCION:    ";
			getline(cin,espa);
			strcpy(proyecto.esp, espa.c_str()); 
		
			cout<<"INGRESE FUNCIONALIDAD: ";
			getline(cin,concep);
			strcpy(proyecto.concepto, concep.c_str());
		
		fwrite( &proyecto, sizeof(Proyecto), 1, archivo );
		
	fclose(archivo);
		cout<<"\n\n";
		abrir();
		system("pause");
}

//BUSCAR REGISTRO	

void buscar(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int busca;
	cout<<"INGRESE ID DE REGISTRO A BUSCAR: ";
	cin>>busca;
	cout<<"************** ID: "<<busca<<" ******************"<<endl;
	fseek ( archivo, busca * sizeof(Proyecto), SEEK_SET );
	
	Proyecto proyecto;
	
    fread ( &proyecto, sizeof( Proyecto ), 1, archivo );

    	
	   	cout<<"PALABRA:    "<<proyecto.ing<<endl;
	   	cout<<"TRADUCCION: "<<proyecto.esp<<endl;
	   	cout<<"DEFINICION: "<<proyecto.concepto<<endl<<endl;
	
	fclose(archivo);
	system("pause");
	
}
/*
//ELIMINAR REGISTRO
void eliminar(){
	const char *archivo_prov= "prov.dat";
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	FILE* archivop = fopen(archivo_prov, "ab");
		
		int busca;
		
    	Proyecto proyecto;
    
			cout <<"INGRESE EL ID DE REGISTRO A MODIFICAR: ";
    		cin >> busca;
    		
    		for(int i; i)
    		
			fseek ( archivo, busca * sizeof(Proyecto), SEEK_SET ); 
			
	    	fwrite( &proyecto, sizeof(Proyecto), 1, archivo );
		
	fclose(archivo);
		cout<<"\n\n";
		abrir();
		system("pause");
}*/
