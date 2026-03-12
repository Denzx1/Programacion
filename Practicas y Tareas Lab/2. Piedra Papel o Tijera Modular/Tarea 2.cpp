#include <iostream>
using namespace std;

short evaluar(short p1,short p2);
string traducir(short p);
void imprimir(short p1, short p2);
void detGanador(short resultado);

int main(int argc, char *argv[]) {
	short p1,p2;
	cout<<"Ingrese la opcion del jugador 1: ";
	cin>>p1;
	cout<<"Ingrese la opcion del jugador 2: ";
	cin>>p2;
	imprimir(p1,p2);
	detGanador(evaluar(p1,p2));
	return 0;
}

short evaluar(short p1,short p2){
	short eval=0;
	if(p1==p2){
		eval=0;
	}
	else if((p1==1 && p2==3)||(p1==2 && p2==1)||(p2==3 && p2==2)){
		eval=1;
	}
	else{
		eval=-1;
	}
	return eval;
}
	
string traducir(short p){
	switch(p){
		case 1: 
		return "()";
		case 2: 
		return "[]";
		case 3: 
		return "8<";
		default:
		return "Error";
	}
}
	
void imprimir(short p1, short p2){
	cout<<endl<<traducir(p1)<<" VS "<<traducir(p2)<<endl;
}
	
void detGanador(short resultado){
	
	if(resultado==0){
		cout<<"Empate";
	}
	else if(resultado==1){
		cout<<"Gana el Jugador 1 ";
	}
	else{
		cout<<"Gana el Jugador 2 ";
	}
	
}
