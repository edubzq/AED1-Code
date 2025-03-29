/*#include <iostream>
using namespace std;


#define INF INT_MAX
#define MAX_N 200
int n = 17;
string ciudades[MAX_N];
int coste[MAX_N][MAX_N];

int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}


void dijkstra(int graph[MAX_N][MAX_N], int src)
{
    int dist[MAX_N];

    bool sptSet[MAX_N];

    for (int i = 0; i < n; i++)
        dist[i] = graph[src][i], sptSet[i] = true;

    for (int count = 0; count < n - 1; count++) {

        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }


    printSolution(dist);
}

void leerGrafo(){


    int a ,b, cst;
    while (cin>>a>>b>>cst){
        if (a == 0 && b == 0 && cst == 0) break;
        coste[a][b] = cst;

    }
}

int main(){
    leerGrafo();
    dijkstra(coste, 0);
}*/



