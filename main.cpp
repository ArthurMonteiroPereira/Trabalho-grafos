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
    int retorno,escolha,opcao;
    float retorno2;
    int aux1,aux2,aux3;
    ofstream saida;
    saida.open(argv[2]);
    if(!saida){
        cout<<"Error";
        abort();
    }
    grafo *teste = leituraArquivoNovo(argv[1]);
    for(int i=0;escolha!=0;i++){
        cout<<endl<<"///////////////////////////// MENU DE INTERACAO ////////////////////////"<<endl;
        cout<<" 1 - Rodar algoritimo guloso"<<endl;
        cout<<" 2 - Rodar algoritimo guloso randomizado"<<endl;
        cout<<" 3 - Rodar algoritimo guloso randomizado reativo"<<endl;
        cout<<" 0 - sair"<<endl;
        cin>>escolha;   
        switch ( escolha )
        {
        case 1 :{
            start =clock();
            retorno=teste->aGM();
            end=clock();
            cout << "Custo da solucao com algoritmo guloso:" << retorno <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
            saida << "Custo da solucao com algoritmo guloso:" << retorno <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
            break;
        }
        case 2 :{
            cout<<"Deseja rodar para os cinco alphas padrao (0.05,0.1,0.15,0.30,0.5) ou escolher um alpha?"<<endl<<"1-Escolher um alpha || 2-rodar padroes"<<endl;
            cin >> opcao;
            if(opcao==1){
                cout<<"escolha o alpha (0 < alpha< 1):";
                cin >>alpha;
                start =clock();
                retorno2=teste->aGMRand(alpha);
                end=clock();
                cout << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
                saida << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
            }
            else{
                cout<<"----------rodando algotimo randomizado-----------------------"<<endl;
                alpha=0.05;
                start =clock();
                retorno2=teste->aGMRand(alpha);
                end=clock();
                cout << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
                saida << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
                alpha=0.1;
                start =clock();
                retorno2=teste->aGMRand(alpha);
                end=clock();
                cout << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
                saida << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
                alpha=0.15;
                start =clock();
                retorno2=teste->aGMRand(alpha);
                end=clock();
                cout << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
                saida << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
                alpha=0.30;
                start =clock();
                retorno2=teste->aGMRand(alpha);
                end=clock();
                cout << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
                saida << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
                alpha=0.5;
                start =clock();
                retorno2=teste->aGMRand(alpha);
                end=clock();
                cout << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl<<"--------------------------------"<<endl;
                saida << "Custo medio da solucao com algoritmo guloso randomizado e alpha="<<alpha<<" deu:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl;
                break;
            }
        }
        case 3 :{
            start =clock();
            retorno2=teste->aGMGGRASP();
            end=clock();
            cout << "Custo da solucao com algoritmo guloso randomizado reativo e:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl<<"--------------------------------"<<endl;
            saida << "Custo da solucao com algoritmo guloso randomizado reativo e:" << retorno2 <<" e levou:"<<float(end-start)/CLOCKS_PER_SEC<<"segundos"<< endl<<"--------------------------------"<<endl;
            break;
        }

        default :
            
            break;
        }
    }
    cout << "\t--/--"<<endl;

    delete teste;
    saida.close();
    return 0;
}
