#include <iostream>
#include <stdlib.h>

using namespace std;


int main () {
    int entrada;
    while (cin >> entrada){

        int A, M, N, a, b, c, d, e, x, y;
        A = entrada;
        N = 5;
        M = 24;
        a = A % 19;
        b = A % 4;
        c = A % 7;
        d = (19*a + M) % 30;
        e = (2*b + 4*c + 6*d + N) % 7;

        if ( (d + e) < 10) {

            x = d + e + 22;
            cout << x;
            cout << " de marzo" <<endl;
        }

        else {

            y = d + e - 9;
            cout << y;
            cout << " de abril"<< endl;
        }
    }
    return 0;

}