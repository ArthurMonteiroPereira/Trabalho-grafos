#include <iostream>
#include <stdio.h>
#include "ListaEnc.h"
//#include "grafo.h"
#include "grafo.cpp"
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

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
    cout << "Inicio leitura do arquivo" << endl;
    ifstream arquivo;
    arquivo.open("teste.txt");
    if(!arquivo){
        abort();
    }
    grafo *teste2;
    string linha;
    int l = 0;
    for(getline(arquivo, linha);!arquivo.eof();getline(arquivo, linha), l++){
        queue<int> fila;
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
            if(j < linha.length()) {aux = linha.at(j);}

            if(aux == ' ' || j >= linha.length()) {flag = false;}

            else {flag = true;}
            if(!flag){
                int n = num.length(), m;
                char *numero = new char[n];
                strcpy(numero, num.c_str());
                fila.push(atoi(numero));
                num = "";
            }
        }

            if(fila.size() == 1){
                teste2 = new grafo(fila.front());
                fila.pop();}
            else {
                int no1, no2;
                no1 = fila.front();
                fila.pop();
                no2 = fila.front();
                teste2->adicionaAresta(no1,no2);
            }
            cout << l << endl;
        }

    arquivo.close();
    teste2->imprime();

    cout << "Fim leitura do arquivo"<<endl;
    delete teste2;

    return 0;
}
