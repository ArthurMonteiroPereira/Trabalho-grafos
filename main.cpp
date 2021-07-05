#include <iostream>
#include <stdio.h>
#include "ListaEnc.h"
#include "grafo.h"
using namespace std;

int main()
{
    FILE *arquivo = fopen("teste.txt", "r");
    char linha[100];
    if(arquivo != NULL){
    
    while (!feof(arquivo))
    {
        string resultado(fgets(linha,100,arquivo)); 

        if(!resultado.empty()){
            string lin(linha);
            cout << lin << endl;
        }
    }
    
    int arnaldo=2;
    grafo teste(10);
    cout << "Hello world!" << endl;
    teste.adicionaAresta(0,1);
    teste.adicionaAresta(4,3);
    teste.adicionaAresta(2,3);
    teste.imprime();
    }
    else cout<<"Problemas ao abrir arquivo!" << endl;
    return 0;
}
