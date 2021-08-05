#include <iostream>
#include <stdio.h>
#include "ListaEnc.h"
#include "grafo.h"
//#include "grafo.cpp"
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

grafo* leituraArquivo()
{
    cout << "Inicio leitura do arquivo" << endl;
    ifstream entrada;
    grafo *g = NULL;

    string arq;
    cout << "Digite o nome do arquivo com sua path: " << endl;
    cin >> arq;
    entrada.open(arq.c_str());

    if(!entrada){
        abort();
    }
    int direcionado, ponderado, peso;
    queue<int> fila;
    string numero = "";
    for(string linha; getline(entrada,linha);){
        int maxLin = strlen(linha.c_str());
        char *c = new char[maxLin+1];
        strcpy(c, linha.c_str());
        for(int i = 0; i <= maxLin; i++){
            while(c[i]!= ' ' && i <= maxLin){
                numero += c[i];
                i++;
            }
            fila.push(atoi(numero.c_str()));
            numero = "";
        }
        if(g == NULL){
            cout << "Grafo direcionado? Sim = 1 / Nao = 0" << endl;
            cin >> direcionado;
            cout << endl;
            cout << "Arestas Ponderadas? Sim = 1 / Nao = 0" << endl;
            cin >> ponderado;
            cout << endl;
            cout << "Pesos nos vertices? Sim = 1 / Nao = 0" << endl;
            cin >> peso;
            cout << endl;
            g = new grafo(direcionado,ponderado,peso,fila.front());
            fila.pop();
        }
        else if(!fila.empty()){
            int no1 = fila.front(), no2;
            fila.pop();
            while(!fila.empty())
            {
                no2 = fila.front();
                g->adicionaAresta(no1,no2);
                fila.pop();
            }
        }
    }
    cout << "Fim leitura arquivo" << endl;
    entrada.close();
    return g;
}

int main(int argc, char ** argv)
{
    int arnaldo=2;


    grafo teste(0,1,1,10);

    teste.adicionaArestaPeso(0,5,7);
    teste.adicionaArestaPeso(5,9,3);
    teste.adicionaArestaPeso(2,3,7);
    teste.adicionaArestaPeso(3,4,7);

    teste.imprimeArestaPeso();

    //teste.imprimeArestaPeso();

    cout << endl;
    cout << endl;
    teste.letraD(0,9);





    grafo *teste2 = leituraArquivo();

    teste2->imprime();

    cout << "\t--/--"<<endl;

    cout << "Inicio escrita arquivo" << endl;
    ofstream saida;
    saida.open("Saida.txt");
    if(saida.is_open())
    {
        //teste2->imprimeEmDot(&saida);
        teste.imprimeEmDot(&saida);

        /*saida << "Tamanho: " << teste2->getTam() << endl;
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
        }*/
    }
    else cout << "Problema ao criar arquivo" << endl;
    saida.close();
    cout << "Fim escrita arquivo" << endl;

    if(teste.getTemArestaPonderada() == 0)
    {
        cout << "deu";
    }

    delete teste2;

    return 0;
}
