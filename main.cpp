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
    grafo *teste = leituraArquivo();
    while(status!=0)
    {
        cout<<"///////////////////////////// MENU DE INTERACAO ////////////////////////"<<endl;
        cout<<" 1 - interacao ""a"" (fecho transitivo direto)"<<endl;
        cout<<" 2 - interacao ""b"" (fecho transitivo indireto"<<endl;
        cout<<" 3 - interacao ""c"" (caminho minimo por djkstra)"<<endl;
        cout<<" 4 - interacao ""d"" (caminho minimo por floyd)"<<endl;
        cout<<" 5 - interacao ""e"" (arvore geradora minima vertice-induzido por x usando Prim)"<<endl;
        cout<<" 6 - interacao ""f"" (arvore geradora minima  vertice-induzido por x usando Kruskal)"<<endl;
        cout<<" 7 - interacao ""g"" (a arvore dada pela ordem de caminhamento em profundidade a partir de no dado parametro,destacando as arestas de retorno)"<<endl;
        cout<<" 8 - interacao ""h"" (uma ordenašao topologica em D ou a informašao de que D nao e um grafo aciclico direcionado)"<<endl;
        cout<<" 0 - sair"<<endl;
        cin>>status;
        switch ( status )
        {
        case 1 :{
            // letra a
            teste->letraA(6);
            break;
        }
        case 2 :{
            // letra b
            teste->letraB(6);
            break;
        }
        case 3 :{
            //letra c
            break;
        }
        case 4 :{
            //letra d
            break;
        }
        case 5 :{
            //letra e
            int v[] = {6,8,12,13,17,29,116};
            teste->letraE(v);
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
        }
            break;
        default :
            break;
        }
    }

    cout << "\t--/--"<<endl;

    delete teste;
    return 0;
}
