#include <iostream>
using namespace std;
bool EsTrio(int d1, int d2, int d3);
bool EsEscalera(int d1, int d2, int d3);
int CalcularPuntaje(int d1, int d2, int d3);
void ImprimirMarcador(int ronda, int puntosRonda, int puntosAcumulados);
void JugarPartida(int cantidadRondas);

int main(int argc, char *argv[]){
    int partidas=0;
    cout<<"Bienvenido a Mini cacho"<<endl;
    cout<<"Cuantas rondas desea jugar: ";
    cin>>partidas;
    JugarPartida(partidas);
	return 0;	
}

bool EsTrio(int d1, int d2, int d3){
    return ((d1==d2) && (d2==d3));
}

bool EsEscalera(int d1, int d2, int d3){
    return ((d1+1==d2) && (d2+1==d3));
}

int CalcularPuntaje(int d1, int d2, int d3){
    if(EsTrio(d1,d2,d3)==true){
        return 50;
    }
    else if(EsEscalera(d1,d2,d3)==true){
        return 25;
    }
    else{
        return d1+d2+d3;
    }
}

void ImprimirMarcador(int ronda, int puntosRonda, int puntosAcumulados){
    cout<<"Ronda: "<<ronda<<"| Puntos ganados: "<<puntosRonda<<" | Puntos acumulados: "<<puntosAcumulados<<endl;
}

void JugarPartida(int cantidadRondas){
    int puntajetotal=0;
    short d1,d2,d3;
    for(int i=0;i<cantidadRondas;i++){
        cout<<"Ingrese el valor de los dados de menor a mayor"<<endl;
        cin>>d1>>d2>>d3;
		int puntajeronda=CalcularPuntaje(d1,d2,d3);
        puntajetotal+=puntajeronda;
        ImprimirMarcador(i+1,puntajeronda,puntajetotal);
    }
    cout<<endl<<"Puntaje Total Obtenido: "<<puntajetotal;
}
