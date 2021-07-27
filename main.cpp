#include <iostream>
#include <stdio.h>
#include "ListaEnc.h"
#include "grafo.h"
//#include "grafo.cpp"
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

grafo* leituraArquivo()
{
    cout << "Inicio leitura do arquivo" << endl;
    ifstream entrada;
    grafo *g;
    entrada.open("teste.txt");
    if(!entrada){
        abort();
    }
    string linha;
    int l = 0;
    for(getline(entrada, linha);!entrada.eof();getline(entrada, linha), l++){
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
                int n = num.length();
                char *numero = new char[n];
                strcpy(numero, num.c_str());
                fila.push(atoi(numero));
                num = "";
            }
        }

            if(fila.size() == 1){
                g = new grafo(fila.front());
                fila.pop();}
            else {
                int no1, no2;
                no1 = fila.front();
                fila.pop();
                no2 = fila.front();
                fila.pop();
                g->adicionaAresta(no1,no2);
            }
            cout << l << endl;
        }
    cout << "Fim leitura arquivo" << endl;
    entrada.close();
    return g;
}

int main(int argc, char ** argv)
{
    /*
    int arnaldo=2;
    grafo teste(10);

    teste.adicionaAresta(0,1);
    teste.adicionaAresta(4,3);
    teste.adicionaAresta(2,3);
    teste.imprime();
    teste.removeAresta(3,4);
    teste.imprime();

    cout << endl;
    */



    grafo *teste2 = leituraArquivo();
    teste2->imprime();
    cout << "\t--/--"<<endl;

    cout << "Inicio escrita arquivo" << endl;
    ofstream saida;
    saida.open("Arquivo_Saida.txt");
    if(saida.is_open())
    {
        saida << "Tamanho: " << teste2->getTam() << endl;
        ListaEnc *v = teste2->getVert();
        for(int i = 0; i < teste2->getTam(); i++){
            if(!v[i].vazia()){
                cout << i << " -- ";
                for(int k = 0, tam = v[i].tamanho(); k < tam; k++)
                {
                    int item = v[i].get(k);
                    cout << item;
                    saida << item;
                    if(k != tam-1){
                        cout << " --> ";
                        saida << " --> ";
                    }
                }
                cout << endl;
                saida << endl;
            }
        }
    }
    else cout << "Problema ao criar arquivo" << endl;
    saida.close();
    cout << "Fim escrita arquivo" << endl;
    delete teste2;
    return 0;
}
