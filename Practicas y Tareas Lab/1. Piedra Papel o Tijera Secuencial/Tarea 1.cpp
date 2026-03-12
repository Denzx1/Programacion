#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	short j1;
	short j2;
	string equi1;
	string equi2;
	
	cout<<"Ingrese la opcion del jugador 1: ";
	cin>>j1;
	cout<<"Ingrese la opcion del jugador 2: ";
	cin>>j2;
	
	if(j1==1){
		equi1="()";
	}
	else if(j1==2){
		equi1="[]";
	}
	else{
		equi1="8<";
	}
	
	if(j2==1){
		equi2="()";
	}
	else if(j2==2){
		equi2="[]";
	}
	else{
		equi2="8<";
	}
	
	cout<<endl<<equi1<<" vs "<<equi2<<endl;
	
	if(j1==j2){
		cout<<"Empate";
	}
	else if((j1==1 && j2==3)||(j1==2 && j2==1)||(j2==3 && j2==2) ){
		cout<<"Gana el Jugador 1 ";
	}
	else{
		cout<<"Gana el Jugador 2 ";
	}
	return 0;
}

