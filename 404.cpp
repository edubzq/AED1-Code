#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
using namespace std;

#define MAX_N 2000
#define V_MAX 9999


int nnodos, naristas;
int coste[MAX_N][MAX_N];
bool visitados[MAX_N];
int dist[MAX_N];
int a, b, c;


void leeGrafo (){
	cin >> nnodos;
 	cin >> naristas;
	cin >> a >> b >> c;
	a -= 1;
	b -= 1;
	c -= 1;
  	if (nnodos<0 || nnodos>MAX_N) {
    		cerr << "Numero de nodos (" << nnodos << ") no valido\n";
    		exit(0);
  	}

  	memset(coste, 0, sizeof(coste)); //Pone los pivotes de la matriz de costes a 0 y las demás posiciones a infinito
  	for(int i=0;i<MAX_N;i++){
		for(int j=0;j<MAX_N;j++){
			coste[i][j] = V_MAX;
		}
	}
  	int u, v, c;
  	for (int i= 0; i<naristas; i++) {
    		cin >> u >> v >> c;
    		coste[u-1][v-1]= c;
    		coste[v-1][u-1] = c;
  	}
}

int dijkstra (int u, int v){
	for(int i=0;i<MAX_N;i++){ //Inicializa
			dist[i]=coste[u][i];
			visitados[i]=false;
	}
	int min_nodo = 0;
	visitados[u] = true;
	for(int i=0;i<MAX_N;i++){ //Esta parte calcula el nodo de menor distancia y no visitado
        int valor_min = V_MAX;
		for(int k=0;k<MAX_N;k++){
			if(dist[k]<valor_min && !visitados[k]){
				valor_min = dist[k];
				min_nodo = k;
			}
		}
		if(min_nodo != v){  //Actualiza los demás nodos
			visitados[min_nodo]=true;
			for(int w=0;w<MAX_N;w++){
				if(!visitados[w] && (coste[min_nodo][w] != V_MAX)){
					if(dist[w] > coste[min_nodo][w] + dist[min_nodo]){
						dist[w] = coste[min_nodo][w] + dist[min_nodo];
					}
				}
			}
		}
		else return valor_min;
	}
	return -1;
}


int main (){
	int ncasos;
	cin >> ncasos;
  	for(int i= 0; i<ncasos; i++) {
    	leeGrafo();
    	int cf;
    	int c1 = dijkstra(a,c);
    	int c2 = dijkstra (c, b);
    	if(c1 < 0 || c2 < 0 ){
            cout << "IMPOSIBLE" << endl;
	    }
        else{
            cf= c1 + c2;
            cout << cf << endl;
        }
	}

}
