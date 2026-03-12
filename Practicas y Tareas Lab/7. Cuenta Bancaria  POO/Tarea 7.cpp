#include <iostream>
using namespace std;

class CuentaBancaria{
private:
	int id;
	string nroCuenta;
	double saldo;
public:
	string propietario;
	
	CuentaBancaria(int id,string nro,string prop){
		this->id = id;
		this->nroCuenta = nro;
		this->propietario = prop;
		this->saldo = 0.0;
	}

	void depositar(double monto){
		if(monto>0){
			saldo+=monto;
		}
		else{
			cout<<"Error! no se permiten montos negativos o nulos"<<endl;
		}
	}
	bool retirar(double monto){
		if(monto>0){
			if(monto<=saldo){
				saldo-=monto;
				return true;
			}
			return false;
		}
		return false;
	}
		
	void transferir(CuentaBancaria &destino, double monto){
		if (this == &destino) {
			return;
		}
		if (this->retirar(monto)) {
			destino.depositar(monto);
			cout << "Transferencia exitosa de " << monto << " a " << destino.propietario << endl;
		} else {
			cout << "Transferencia fallida: Saldo insuficiente." << endl;
		}
	}
	void verEstado(){
		cout<<" Titular: "<<propietario<<"| Saldo: "<<saldo<<endl;
	}
};


int main(int argc, char *argv[]) {
	// Instancia de cuentas
	CuentaBancaria cuentaA(1001, "1-35642347", "Juan Enrique Torrez");
	CuentaBancaria cuentaB(1002, "1-13245123", "Maria Luz Quispe");
	
	cout << "--- REPORTE BANCARIO INICIAL ---" << endl;
	cuentaA.verEstado();
	cuentaB.verEstado();
	cout << "--------------------------------" << endl << endl;
	
	// Operación de depósito
	cout << "> Deposito"<<endl;
	cuentaA.depositar(1000);
	cuentaA.verEstado();
	cout << endl;
	
	// Operación de transferencia
	cout << "> Tranfiriendo"<<endl;
	cuentaA.transferir(cuentaB, 450);
	
	cout << endl << "--- ESTADO FINAL DE CUENTAS ---" << endl;
	cuentaA.verEstado();
	cuentaB.verEstado();
	cout << "-------------------------------" << endl;
	
	return 0;
}

