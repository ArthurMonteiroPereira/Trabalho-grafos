#include <iostream>
#include <stdio.h>
#include "ListaEnc.h"
#include "grafo.h"
#define T 10
using namespace std;

grafo::grafo(int edirecionado,int earestaPonderada,int epesoNosVertices,int tam){
    direcionado=edirecionado;
    arestaPonderada=earestaPonderada;
    pesoNosVertices=epesoNosVertices;
    tamanho = tam;
}
grafo::grafo(int tam){
    direcionado=0;
    arestaPonderada=0;
    pesoNosVertices=0;
    tamanho = tam;
    vertices = new ListaEnc[tam];
}
grafo::~grafo(){
    delete []vertices;
}
void grafo::imprime(){
    cout<<endl;
    cout<<tamanho<<endl;
    for(int i=0;i<tamanho;i++){
        cout<<i<<" -- ";
        if(!vertices[i].vazia()){
            for(int z=0;z<vertices[i].tamanho();z++)
                cout<<vertices[i].get(z)<<",";
        }
    cout<<endl;
    }
}
void grafo::adicionaAresta(int no1,int no2){
    if(no1>tamanho || no2>tamanho){
        cout<<"error:VERTICES NAO PRESENTES"<<endl;
    }
    if(direcionado==1){
        vertices[no1].insereFinal(no2);
    }
    else{
        vertices[no2].insereFinal(no1);
        vertices[no1].insereFinal(no2);
    }
}
void grafo::removeAresta(int no1,int no2){}
bool existeAresta(int no1,int no2){}
