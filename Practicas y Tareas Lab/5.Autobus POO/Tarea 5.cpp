#include <iostream>
using namespace std;
class Autobus{
private:
	double combustible;
	int asientos;
public:
	double tarifa;
	int pasajeros;
	Autobus(){
		combustible=0;
		asientos=50;
		tarifa=1;
		pasajeros=0;
	}
	Autobus(double c, int a, double t) {
		combustible = c;
		asientos = a;
		tarifa = t;
		pasajeros = 0;
	}
	void recogerPasajeros(int nroPasjeros){
		if(pasajeros+nroPasjeros<asientos){
			pasajeros+=nroPasjeros;
		}
		else{
			cout<<"ERROR: No se pueden subir mas pasajeros que asientos"<<endl;
		}
	}
	void recargarGasolina(int cantidad){
		if(combustible+cantidad<=100){
			combustible+=cantidad;
			cout<<"Combustible actual: "<<combustible;
		}
		else{
			combustible=100;
			cout<<"(Tanque lleno)Combustible Actual: "<<combustible;
		}
	}
	int cantAsientosDisponible(){
		return asientos-pasajeros;
		
	}
	bool hayEspacio(){
		if(pasajeros<asientos){
			return true;
		}
		return false;
	}
	bool estaVacio(){
		if(pasajeros==0){
			cout<<"Esta vacio?  Si";
			return true;
		}
		return false;
	}
		
	int calcularMontoRecaudado(){
		return pasajeros * tarifa;
	}
		
	double getCombustible(){ return combustible; }
	int getAsientos(){ return asientos; }
	
	void setCombustible(double newCombustible) { combustible=newCombustible; }
	void setAsiento(int newAsiento) { asientos=newAsiento; }
};



int main(int argc, char *argv[]) {
	Autobus A1,A2(70,75,2);
	cout<<"Autobus 1"<<endl;
	A1.recogerPasajeros(17);
	cout<<"Asientos disponibles: "<<A1.cantAsientosDisponible()<<endl;
	cout<<"Hay espacio? "<<(A1.hayEspacio()? "Si" : "No")<<endl;
	A1.recargarGasolina(20);
	cout<<endl<<"Monto Recaudado: "<<A1.calcularMontoRecaudado()<<endl;
	
	cout<<endl<<"Autobus 2"<<endl;
	A2.recogerPasajeros(80);
	cout<<"Asientos disponibles: "<<A2.cantAsientosDisponible()<<endl;
	cout<<"Hay espacio? "<<(A2.hayEspacio()? "Si" : "No")<<endl;
	A2.recargarGasolina(20);
	cout<<endl<<"Monto Recaudado: "<<A2.calcularMontoRecaudado();
	
	return 0;
}


