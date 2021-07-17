#include <iostream>
#include <stdio.h>
#include "ListaEnc.h"
#include "grafo.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <list>

using namespace std;

typedef list<int, allocator<int> > ListInt;

void leArquivo(grafo *g){
    ifstream arquivo;
    arquivo.open("teste.txt");
    if(!arquivo){
        abort();
    }
    string linha;
    for(getline(arquivo, linha);!arquivo.eof();getline(arquivo, linha)){
        ListInt lista;
        string num = "";
        char aux;
        bool flag;
        for(int j = 0,aux = linha.at(j);aux != '\n' && aux != NULL &&j < linha.length();){
            int n;
            if(aux == '-'){
                j++;
                aux = linha.at(j);
                n = (-1)*(aux-'0');
            }
            else n = (aux-'0');
            if(n>=-9 && n <=9){
                num+=to_string(n);
            }
            j++;
            if(j < linha.length()) aux = linha.at(j);

            if(aux == ' ' || j >= linha.length()) flag = false;

            else flag = true;
            if(!flag){
            int n = num.length();
            char *numero = new char[n+1];
            strcpy(numero, num.c_str());
            lista.insert(lista.end(), atoi(numero));
            num = "";
            }
        }
        if(lista.max_size() == 1){
            ListInt::iterator i = lista.begin();
            cout << *i << "";
        }
        else
        for(ListInt::iterator i = lista.begin(); i != lista.end(); ++i){
                cout << *i << " ";
        }
        cout << endl;
    }
    arquivo.close();
}

int main()
{
    int arnaldo=2;
    grafo teste(10);

    teste.adicionaAresta(0,1);
    teste.adicionaAresta(4,3);
    teste.adicionaAresta(2,3);
    teste.imprime();
    teste.removeAresta(3,4);
    teste.imprime();

    cout << endl;
    grafo teste2(10);
    leArquivo(&teste2);
    return 0;
}
