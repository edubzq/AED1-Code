#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>
#include <list>
using namespace std;

#define MAX_N 26


int nnodos, naristas; //Variables para almacenar el numero de nodos y aristas
bool coste[MAX_N][MAX_N]; //Matriz de adyacencia
bool visitados[MAX_N]; //Array de booleanos para llevar el registro de los nodos visitados


void leeGrafo (void){
  cin >> nnodos >> naristas;
  if (nnodos < 0 || nnodos > MAX_N) {
    cerr << "Numero de nodos (" << nnodos << ") no valido\n";
    exit(0);
  }
  memset(coste, 0, sizeof(coste));
  char a, b;
  for (int i= 0; i < naristas; i++) {
    cin >> a >> b;
    coste[a-'A'][b-'A']= true;
  }
}

void bpa(int v){
	int c;
	list<int> cola;
	visitados[v]= true;
	cola.push_back(v);
	cout << char(v+'A');
	while(!cola.empty()){
		list<int>::iterator it = cola.begin();
		c = (*it);
		cola.erase(it);
		for(int i = 0; i<MAX_N; i++){
			if(coste[c][i] && visitados[i]==false){
				visitados[i] = true;
				cola.push_back(i);
				cout << char(i+'A');
			}
		}
	}
}

void busquedaPA (){
  memset(visitados, 0, sizeof(visitados));
  for (int v = 0; v < nnodos; v++)
    if (!visitados[v]) bpa(v);
  cout << endl;
}

int main ()
{
  int ncasos;
  cin >> ncasos;
  for (int i = 0; i < ncasos; i++) {
    leeGrafo();
    busquedaPA();
  }
}
