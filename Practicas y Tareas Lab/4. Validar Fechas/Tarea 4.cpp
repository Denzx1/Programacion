#include <iostream>
using namespace std;
bool Esbisiesto(int anio);
int obtenerDiadelMes(int mes,int anio);
bool EsFechavalida(int dia,int mes,int anio);
void EjecutarSimulacion(int cantidadRondas);

int main(int argc, char *argv[]) {
	int rondas;
	cin>>rondas;
	EjecutarSimulacion(rondas);
	return 0;
}

bool Esbisiesto(int anio){
	return (anio%4==0 && anio%100!=0)||(anio%400==0);
}
	
int obtenerDiadelMes(int mes,int anio){
	if(mes==2){
		if (Esbisiesto(anio)) {
			return 29;
		} else {
			return 28;
		}
	}
	if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
		return 30;
	}
	else{
		return 31;
	}
}
	
bool EsFechavalida(int dia,int mes,int anio){
	if(mes<1 ||mes>12){
		return false;
	}
	int maxDias = obtenerDiadelMes(mes,anio);
	return (dia >= 1 && dia <= maxDias);
}
	
void EjecutarSimulacion(int cantidadRondas){
	int dia,mes,anio;
	int saltos=0;
	for(int i=0;i<cantidadRondas;i++){
		cin>>dia>>mes>>anio;
		if(EsFechavalida(dia,mes,anio)==true){
			cout<<"Salto temporal completado"<<endl;
			saltos++;
		}
		else{
			cout<<"Falla catastrofica: Fecha inexistente"<<endl;
		}
	}
	cout<<"Saltos exitosos: "<<saltos<<"/"<<cantidadRondas<<endl;
}

