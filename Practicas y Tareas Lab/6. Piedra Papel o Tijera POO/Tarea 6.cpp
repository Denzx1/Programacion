#include <iostream>
#include <string>

using namespace std;

class Player {
private:
	short opcionjugada;
	int puntaje;
	
	// Retorna 1 si gana this, -1 si gana p2, 0 si hay empate
	int evaluar(Player &p2) {
		if (this->opcionjugada == p2.opcionjugada) {
			return 0;
		}
		if ((this->opcionjugada == 1 && p2.opcionjugada == 3) ||
			(this->opcionjugada == 2 && p2.opcionjugada == 1) ||
			(this->opcionjugada == 3 && p2.opcionjugada == 2)) {
			return 1;
		}
			return -1;
	}
	
public:
		string nombre;
		
		Player() {
			nombre = "Jugador";
			puntaje = 0;
		}
		
		void seleccionar() {
			cout << nombre << " elija (1: Piedra, 2: Papel, 3: Tijera): ";
			cin >> opcionjugada;
		}
		
		string traducir(int opcion) {
			switch (opcion) {
			case 1: return "()";
			case 2: return "[]";
			case 3: return "8<";
			default: return "Error";
			}
		}
		
		void jugar(Player &p2) {
			cout << "\n--- Enfrentamiento ---" << endl;
			cout << this->nombre << " (" << traducir(this->opcionjugada) << ") VS "
				<< p2.nombre << " (" << traducir(p2.opcionjugada) << ")" << endl;
			
			int resultado = evaluar(p2);
			
			if (resultado == 1) {
				this->puntaje++;
				cout << ">> Gano el jugador: " << this->nombre << endl;
			} else if (resultado == -1) {
				p2.puntaje++;
				cout << ">> Gano el jugador: " << p2.nombre << endl;
			} else {
				cout << ">> ¡Empate!" << endl;
			}
		}
		
		float obtenerEficiencia(int nroPartidas) {
			if (nroPartidas == 0) return 0;
			// Casteo a float para evitar que la división de enteros de siempre 0
			return ((float)puntaje / nroPartidas) * 100;
		}
		
		int getPuntaje() { return puntaje; }
};

int main() {
	Player p1, p2,p3;
	int rondas = 3;
	p1.nombre = "Juan";
	p2.nombre = "Ramiro";
	p3.nombre = "Ana";
	
	for (int i = 0; i < rondas; i++) {
		cout << "\n--- Ronda " << i + 1 << " ---" << endl;
		p1.seleccionar();
		p2.seleccionar();
		p1.jugar(p2);
	
		p2.seleccionar();
		p3.seleccionar();
		p2.jugar(p3);
	}
	
	cout << "\n      RESULTADOS FINALES     " << endl;
	cout << p1.nombre << ": " << p1.getPuntaje() << " pts (" << p1.obtenerEficiencia(rondas) << "%)" << endl;
	cout << p2.nombre << ": " << p2.getPuntaje() << " pts (" << p2.obtenerEficiencia(rondas) << "%)" << endl;
	cout << p3.nombre << ": " << p3.getPuntaje() << " pts (" << p3.obtenerEficiencia(rondas) << "%)" << endl;
	
	return 0;
}

