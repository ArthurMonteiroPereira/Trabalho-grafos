#include <iostream>
#include <stdio.h>
#include "ListaEnc.h"
#include "grafo.h"
#define T 10
using namespace std;

grafo::grafo(int eDirecionado,int eArestaPonderada,int ePesoNosVertices,int tam){
    direcionado=eDirecionado;
    arestaPonderada=eArestaPonderada;
    pesoNosVertices=ePesoNosVertices;
    tamanho = tam;
    vertices = new ListaEnc[tam];
    if(ePesoNosVertices==1){
        pesoV = new int[tam];
        for(int i=0;i<tam;i++)
            pesoV[i]=0;
    }
}
grafo::grafo(int tam){
    direcionado=0;
    arestaPonderada=0;
    pesoNosVertices=0;
    tamanho = tam;
    vertices = new ListaEnc[tam];
}
grafo::~grafo(){
    for(int i=0;i<tamanho;i++){
        vertices[i].remover();
    }
    delete []vertices;
    if(pesoNosVertices==1){
        delete []pesoV;
    }
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
    if(no1>=tamanho || no2>=tamanho){
        cout<<"error:VERTICES NAO PRESENTES"<<endl;
    }
    if(direcionado==1){
        vertices[no1].insereInicio(no2);
    }
    else{
        vertices[no2].insereInicio(no1);
        vertices[no1].insereInicio(no2);
    }
}
void grafo::adicionaArestaPeso(int no1,int no2,int peso){
    if(no1>=tamanho || no2>=tamanho){
        cout<<"error:VERTICES NAO PRESENTES"<<endl;
    }
    if(direcionado==1){
        vertices[no1].insereInicio(no2);
        vertices[no1].setPeso(0,peso);
    }
    else{
        vertices[no2].insereInicio(no1);
        vertices[no2].setPeso(0,peso);
        vertices[no1].insereInicio(no2);
        vertices[no1].setPeso(0,peso);
    }
}

void grafo::removeAresta(int no1,int no2){
    if(vertices[no1].existe(no2)){
        vertices[no1].RemoveDado(no2);
        vertices[no2].RemoveDado(no1);
    }
    else{
        cout<<"erro aresta nao existe";
    }
}
void grafo::inserePesoVertice(int vert,int peso){
    pesoV[vert]=peso;
}
void grafo::imprimeVerticePeso(){
    cout<<endl;
    for(int i=0;i<tamanho;i++){
        cout<<"vertice "<<i<<" pesa:"<<pesoV[i]<<endl;
    }
    cout<<endl;
}
void grafo::imprimeArestaPeso(){
    cout<<endl;
    cout<<tamanho<<endl;
    for(int i=0;i<tamanho;i++){
        cout<<i<<" -- ";
        if(!vertices[i].vazia()){
            for(int z=0;z<vertices[i].tamanho();z++)
                cout<<vertices[i].get(z)<<"("<<vertices[i].getPeso(z)<<")"<<" ,";
        }
    cout<<endl;
    }

}
void grafo::alteraPesoAresta(int no1,int no2,int peso){
    if(direcionado==1){
        if(vertices[no1].existe(no2)){
            vertices[no1].setPeso(vertices[no1].existeRetorna(no2),peso);
        }
        else{
            cout<<"erro na alteração de peso da aresta,aresta não existe";
        }
    }
    else{
        vertices[no1].setPeso(vertices[no1].existeRetorna(no2),peso);
        vertices[no2].setPeso(vertices[no2].existeRetorna(no1),peso);
    }
}
int grafo::retornaPesoAresta(int no1,int no2){
    return vertices[no1].getPeso(vertices[no1].existeRetorna(no2));
}

bool existeAresta(int no1,int no2){}
