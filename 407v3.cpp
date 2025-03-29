#include<iostream>
#include <string.h>
#include<climits>
using namespace std;

#define MAX_N 200


int nnodos, src;
int coste[MAX_N][MAX_N]; //C
int dist[MAX_N]; //D
int paso[MAX_N]; //P
bool visitados[MAX_N];//S

int getCercano(){ //Calcula el nodo cercano con menor distancia

    int valor_min = INT_MAX;
    int min_nodo = 0;
    for (int i = 0; i < nnodos; i++){
        if(!visitados[i]&& dist[i] < valor_min){
            valor_min = dist[i];
            min_nodo = i;
        }
    }
    return min_nodo;

}

void dijkstra(int scr){ // Algoritmo de dijkstra, hecho siguiendo el pseudocogido

    for(int v = 0; v < MAX_N; v++){ //Inicializa
        dist[v] = coste[scr][v];
        paso[v] = v;

        visitados[v] = false;
    }
    visitados[src] = true;

    for (int i = 0; i < MAX_N-1; i++){ //Actualiza
        int v = getCercano();
        visitados[v] = true;

        for(int w = 0; w<MAX_N; w++){
            if(!visitados[w] && (dist[w] + coste[v][w] < dist[w])){
               dist[w] = dist[w] + coste[v][w];
               paso[w] = v;
            }
        }
    }


    cout<<"Nodo\t\tDistancia al origen"<<endl;
    for(int k = 0; k<nnodos; k++)
    {

        cout<<k<<"\t\t\t"<<dist[k]<<endl;
        cout <<paso[k]<<endl;
    }
}
void leerGrafo(){

    string c;
    cin>>nnodos;
    cin>>ws; //quitar espacio en blanco
    int a ,b, cst;
    for(int k = 0; k < nnodos; k++){ //lee las ciudades
            getline(cin, c, '\n');

    }

    memset(coste, 0, sizeof(coste));
  	for(int i=0;i<MAX_N;i++){
		for(int j=0;j<MAX_N;j++){
			coste[i][j] = INT_MAX;
		}
	}
    while (cin>>a>>b>>cst){ //añade los valores a la matriz de costes
        if (a == 0 && b == 0 && cst == 0) break;
        coste[a][b] = cst;
    }
}



int main(){

    leerGrafo();
    dijkstra(0);


}

