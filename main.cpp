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
#include "criarArquivo.h"
#include <ctime>
using namespace std;



int main(int argc, char *argv[])
{   
    float alpha;
    clock_t start, end;
    int retorno;
    float retorno2;
    int aux1,aux2,aux3;
    ofstream saida;
    grafo *teste = leituraArquivoNovo(argv[2]);   
    switch ( stoi(argv[1]) )
    {
    case 1 :{
        start =clock();
        retorno=teste->aGM();
        end=clock();
        cout << "Custo da solucao com algoritmo guloso:" << retorno <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
        break;
    }
    case 2 :{
        cout<<"----------rodando algotimo randomizado-----------------------"<<endl;
        alpha=0.05;
        start =clock();
        retorno2=teste->aGMRand(alpha);
        end=clock();
        cout << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" e:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
        
        alpha=0.1;
        start =clock();
        retorno2=teste->aGMRand(alpha);
        end=clock();
        cout << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" e:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
        
        alpha=0.15;
        start =clock();
        retorno2=teste->aGMRand(alpha);
        end=clock();
        cout << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" e:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
        
        alpha=0.30;
        start =clock();
        retorno2=teste->aGMRand(alpha);
        end=clock();
        cout << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" e:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
      
        alpha=0.5;
        start =clock();
        retorno2=teste->aGMRand(alpha);
        end=clock();
        cout << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" e:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl<<"--------------------------------"<<endl;
        break;
    }
    case 3 :{
        start =clock();
        retorno2=teste->aGMGGRASP();
        end=clock();
        cout << "Custo da solucao com algoritmo guloso randomizado reativo e:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl<<"--------------------------------"<<endl;
        break;
    }

    default :
        cout << "opcao escolhida invalida" << endl;
        break;
    }

    cout << "\t--/--"<<endl;

    delete teste;
    saida.close();
    return 0;
}
