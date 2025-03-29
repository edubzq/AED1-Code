#include <stdlib.h>  		// Funcion exit
#include <string.h>  		// Funcion memset
#include <iostream>  	// Variables cin y cout
using namespace std;

#define MAX_NODOS 9999

//////////////////////////////////////////////////////////////
////////////        VARIABLES GLOBALES        ////////////////
//////////////////////////////////////////////////////////////

int nnodos;                   // Numero de nodos del grafo
int naristas;                 // Numero de aristas del grafo
bool G[MAX_NODOS][MAX_NODOS]; // Matriz de adyacencia
bool visitado[MAX_NODOS];     // Marcas de nodos visitados
int Nislas=0;
int isAct=0;
int R[MAX_NODOS];

//////////////////////////////////////////////////////////////
////////////     FUNCIONES DEL PROGRAMA       ////////////////
//////////////////////////////////////////////////////////////

void leeGrafo (void)
// Procedimiento para leer un grafo de la entrada
{
  cin >> nnodos >> naristas;
  if (nnodos<0 || nnodos>MAX_NODOS) {
    cerr << "Numero de nodos (" << nnodos << ") no valido\n";
    exit(0);
  }
  memset(G, 0, sizeof(G));
  int c1, c2;
  for (int i= 0; i<naristas; i++) {
    cin >> c1 >> c2;
    G[c1-1][c2-1]= true;
    G[c2-1][c1-1] = true;
  }
}

void bpp(int v)
// Procedimiento recursivo de la busqueda primero en profundidad
//   v - primer nodo visitado en la bpp
{
  visitado[v]= true;
  R[v]=isAct;
  for (int w= 0; w<nnodos; w++)
    if (!visitado[w] && G[v][w]) bpp(w);
}

void busquedaPP ()
// Procedimiento principal de la busqueda en profundidad
{
  memset(visitado, 0, sizeof(visitado));
  for (int v= 0; v<nnodos; v++){
	  if (!visitado[v]){
		   isAct++;
		   bpp(v);
		  }
}
  cout << endl;
}

void replicabpp(int v){
  visitado[v]= true;
  for (int w= 0; w<nnodos; w++) if (!visitado[w] && G[v][w]) replicabpp(w);
}

void replicaPP (){
  memset(visitado, 0, sizeof(visitado));
  for(int v= 0; v<nnodos; v++){
	  if(!visitado[v]){
		  Nislas++;
		   replicabpp(v);
	   }
  }
}

//////////////////////////////////////////////////////////////
////////////        PROGRAMA PRINCIPAL        ////////////////
//////////////////////////////////////////////////////////////

int main (void)
{
	int ncasos;
	cin >> ncasos;
	
	for (int i= 0; i<ncasos; i++) {
		Nislas=0;
	isAct=0;
	for(int h=0; h<MAX_NODOS; h++) R[h]=0;
		for (int j= 1; j<ncasos+1; j++) {
		leeGrafo();
		int cont=i+1;
		cout << "Caso " << cont << endl;
		replicaPP();
	}
	cout << Nislas;
		busquedaPP();
		for(int c=0;R[c]!=0;c++){
			cout << R[c] << endl;
		}
	}
	
}
