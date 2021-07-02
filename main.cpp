#include <iostream>
#include <stdio.h>
#include "ListaEnc.h"
#include "grafo.h"
using namespace std;

int main()
{
    int arnaldo=2;
    grafo teste(10);
    cout << "Hello world!" << endl;
    teste.adicionaAresta(0,1);
    teste.adicionaAresta(4,3);
    teste.adicionaAresta(2,3);
    teste.imprime();


    return 0;
}
