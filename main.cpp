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
            int entrada;
            cout<<"Digite o ID do vertice desejado:"<<endl;
            cin>>entrada;
            cout<<endl;

            teste->letraA(&saida, entrada);
            saida << endl<<"////////////////////////////////////"<<endl;
            break;
        }
        case 2 :{
            // letra b
            saida << "////////// LETRA b /////////////////"<<endl;
            int entrada;
            cout<<"Digite o ID do vertice desejado:"<<endl;
            cin>>entrada;
            cout<<endl;
            teste->letraB(&saida,entrada);
            saida <<endl<< "////////////////////////////////////"<<endl;
            break;
        }
        case 3 :{
            //letra c
            cout<<"digite os dois nos que deseja o caminho minimo"<<endl;
            cin>>aux1;
            cout<<endl;
            cin>>aux2;
            cout<<endl;
            aux3=teste->letraC(aux1,aux2);
            saida << "////////// LETRA c /////////////////"<<endl;
            cout<<"Caminho minimo entre os nos "<<aux1<<" e "<<aux2<<" tem tamanho:"<<aux3<<endl;
            saida<<"Caminho minimo entre os nos "<<aux1<<" e "<<aux2<<" tem tamanho:"<<aux3<<endl;
            teste->imprimeArestaModelo(&saida,aux1,aux2,aux3);
            teste->imprimeArestaModeloTela(aux1,aux2,aux3);
            saida <<endl<< "////////////////////////////////////"<<endl;
            break;
        }
        case 4 :{
            cout<<"digite os dois nos que deseja o caminho minimo"<<endl;
            cin>>aux1;
            cout<<endl;
            cin>>aux2;
            cout<<endl;
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
            int entrada;
            cout<<"Digite o ID do vertice para adicionar ao subconjunto, ou -1 para dar continuidade:"<<endl;
            cin>>entrada;
            cout<<endl;
            while(entrada!=-1)
            {
                vet->insereFinal(entrada);
                cout<<"Digite o ID do vertice adicionar ao subconjunto, ou -1 para dar continuidade"<<endl;
                cin>>entrada;
                cout<<endl;
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
            int entrada;
            cout<<"Digite o ID do vertice desejado:"<<endl;
            cin>>entrada;
            cout<<endl;
            teste->letraG(&saida, entrada);
            break;
        }
        case 8 :{
            //letra h
            teste->letraH(&saida);
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
