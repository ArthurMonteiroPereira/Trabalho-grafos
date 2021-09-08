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



int main(int argc, char *argv[])
{
    int status;
    int aux1,aux2,aux3;
    ofstream saida;
    grafo *teste = leituraArquivoNovo(argv[2]);
    cout<<"certo";
    saida.open(argv[3]);
    
    switch ( stoi(argv[1]) )
    {
    case 1 :{
        // letra a
        break;
    }
    case 2 :{
        // letra b

        break;
    }
    case 3 :{
        //letra c

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
