#ifndef 403_HPP_INCLUDED
#define 403_HPP_INCLUDED

using namespace std;


class Arista;
class Nodo {

    Nodo *sig;
    Arista *ady;
    int etiqueta;
};
class Arsita{

    Arista *sig;
    Nodo *ady;
};

class Grafo{

    Nodo *n;
    public:
        void Inicializa();
        bool Vacio();
        int Tamano();



};

#endif // 403_HPP_INCLUDED
