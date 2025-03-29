#include <iostream>
#include <string.h>
using namespace std;


#define INF INT_MAX
#define MAX_N 200

int V, src;
int C[MAX_N][MAX_N];
int D[MAX_N];
int P[MAX_N] ;
bool S[MAX_N];
string ciudades[MAX_N];


int getCercano(){
    int minval= INF;
    int minnodo = 0;
    for (int i = 0; i < V; i++){
        if(!S[i] && D[i] < minval){
            minval = D[i];
            minnodo = i;
        }
    }
    return minnodo;

}
void printSolution(int D[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<<D[i]<< endl;
}
void leerGrafo(){

    string c;
    cin>>V;
    cin>>ws;
    int a ,b, cst;
    for(int k = 0; k < V; k++){

            getline(cin, c, '\n');
            ciudades[k]= c;
    }
    memset(C, 0, sizeof(C));
    while (cin>>a>>b>>cst){
        if (a == 0 && b == 0 && cst == 0) break;
        C[a][b] = cst;
        cout<<a<<b<<cst;

    }
}

void inicializa(){
      for (int v = 0; v < V; v++){
        D[v] = INF;
        P[v] = v;
    }
    D[src] = 0;
}

void dijkstra(){

    for(int i = 1; i< V; i++){
        int cercano = getCercano();
        S[cercano] = true;
        for(int ady = 0; ady < V; ady++){
            if(C[cercano][ady] != INF &&
            D[cercano]+C[cercano][ady]<D[ady]){
                D[ady] =  D[cercano]+C[cercano][ady];
                P[ady] = cercano;
            }
        }
    }
}


int mayorCamino(){
    dijkstra();
    int mayor = 0;
    for(int d = 0; d<V; d++){
        if(D[d] > mayor) mayor = D[d];
    }
    return mayor;
}



int main(void){
    src = 1;
    leerGrafo();
    inicializa();
    dijkstra();
    cout<<D[2];
}

