#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define MAX_NODOS 20000
#define MAX_ADY 10

int nnodos;
bool G[MAX_NODOS][MAX_NODOS];
bool visitado[MAX_NODOS];

void leerGrafo (void)
{
  cin >> nnodos;
  if (nnodos<0 || nnodos>MAX_NODOS) {
    cerr << "Numero de nodos (" << nnodos << ") no valido\n";
    exit(0);
  }

  memset(G, 0, sizeof(G));
  string line; getline(cin, line);
  for (int u = 1; u<=nnodos; u++) {
        string line;
        getline(cin,line);
        istringstream aux(line);
        int v;
        while (aux >> v){
            v--;
            G[u][v] = true;
            cout<< u << v <<endl;
        }


  }

}




void bpp (int v)
{
  visitado[v]= true;
  cout<<v;
  for (int w = 1; w<=nnodos; w++){
    if (!visitado[w] && G[v][w])
      bpp(w);
  }
}

void busquedaPP (void)
{
  memset(visitado, 0, sizeof(visitado));
  for (int v = 1; v <= nnodos; v++){
    if (!visitado[v]){
      bpp(v);
      cout << endl;
    }
  }
  }

int main (void)
{

    leerGrafo();


}
