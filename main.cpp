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
using namespace std;



int main(int argc, char ** argv)
{
    int status;
    int aux1,aux2,aux3;
    ofstream saida;
    grafo *teste = leituraArquivo();
    saida.open("Arquivo_Saida.txt");
    while(status!=0)
    {
        cout<<endl<<"///////////////////////////// MENU DE INTERACAO ////////////////////////"<<endl;
        cout<<" 1 - interacao ""a"" (fecho transitivo direto)"<<endl;
        cout<<" 2 - interacao ""b"" (fecho transitivo indireto"<<endl;
        cout<<" 3 - interacao ""c"" (caminho minimo por djkstra)"<<endl;
        cout<<" 4 - interacao ""d"" (caminho minimo por floyd)"<<endl;
        cout<<" 5 - interacao ""e"" (arvore geradora minima vertice-induzido por x usando Prim)"<<endl;
        cout<<" 6 - interacao ""f"" (arvore geradora minima  vertice-induzido por x usando Kruskal)"<<endl;
        cout<<" 7 - interacao ""g"" (a arvore dada pela ordem de caminhamento em profundidade a partir de no dado parametro,destacando as arestas de retorno)"<<endl;
        cout<<" 8 - interacao ""h"" (uma ordenaçao topologica em D ou a informaçao de que D nao e um grafo aciclico direcionado)"<<endl;
        cout<<" 0 - sair"<<endl;
        cin>>status;
        switch ( status )
        {
        case 1 :{
            // letra a
            saida << "////////// LETRA a /////////////////"<<endl;
            teste->letraA(&saida,6);
            saida << endl<<"////////////////////////////////////"<<endl;
            break;
        }
        case 2 :{
            // letra b
            saida << "////////// LETRA b /////////////////"<<endl;
            teste->letraB(&saida,6);
            saida <<endl<< "////////////////////////////////////"<<endl;
            break;
        }
        case 3 :{
            //letra c
            break;
        }
        case 4 :{
            cout<<"digite os dois nos que deseja o caminho minimo"<<endl;
            cin>>aux1;
            cin>>aux2;
            aux3=teste->letraD(aux1,aux2);
            saida << "////////// LETRA d /////////////////"<<endl;
            cout<<"Caminho minimo entre os nos "<<aux1<<" e "<<aux2<<" tem tamanho:"<<aux3<<endl;
            saida<<"Caminho minimo entre os nos "<<aux1<<" e "<<aux2<<" tem tamanho:"<<aux3<<endl;
            teste->imprimeArestaModelo(&saida,aux1,aux2,aux3);
            teste->imprimeArestaModeloTela(aux1,aux2,aux3);
            saida <<endl<< "////////////////////////////////////"<<endl;
            break;
        }
        case 5 :{
            //letra e
            ListaEnc *vet = new ListaEnc();
            int v[] = {6,8,12,13,17,29,49,116};
            for(int k = 0; k < 8; k++)
                {
                    vet->insereInicio(v[k]);
                }
            teste->letraE(&saida,vet);
            break;
        }
        case 6 :{
            //letra f
            break;
        }
        case 7 :{
            //letra g
            break;
        }
        case 8 :{
            //letra h
            break;
        }
        case 0 :{
            status=0;
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
