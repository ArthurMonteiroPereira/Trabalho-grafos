#include <iostream>
#include <stdio.h>
#include "ListaEnc.h"
#include "grafo.h"
#define T 10
#define INFINITO 999999999
#include <fstream>
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

void grafo::imprimeEmDot(ofstream* saida/*recebe também o vetor solução*/){          //chamar para o grafo auxiliar
    int isDir = getEhDirecionado();
    int isPond = getTemArestaPonderada();
    int hasPesoVert = getTemPesoNosVertices();

    if(isDir)
    {
        *saida << "strict digraph {" << endl;
    }

    if(!isDir)
    {
        *saida << "strict graph {" << endl;
    }

    if(hasPesoVert)
    {
        for(int i=0; i < tamanho; i++)
            if(!vertices[i].vazia())
            {
                for(int z=0;z<vertices[i].tamanho();z++)
                    {
                        *saida << i << "_p" << pesoV[i];
                        if(isDir)
                            *saida << "->";
                        else
                            *saida << "--";
                        *saida << vertices[i].get(z);
                        if(isPond)
                            *saida << "[label =" << retornaPesoAresta(i,vertices[i].get(z)) << "]" <<endl;

                    }
            }
            else
                *saida << i << endl;
    }

    if(!hasPesoVert)
    {
                for(int i=0; i < tamanho; i++)
            if(!vertices[i].vazia())
            {
                for(int z=0;z<vertices[i].tamanho();z++)
                    {
                        *saida << i;
                        if(isDir)
                            *saida << "->";
                        else
                            *saida << "--";
                        *saida << vertices[i].get(z);
                        if(isPond)
                            *saida << "[label =" << retornaPesoAresta(i,vertices[i].get(z)) << "]" <<endl;
                    }

            }
            else
                *saida << i << endl;
    }
    *saida << "}";
    return;
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

void grafo::converteListaMatriz(int **matriz){
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            matriz[i][j]=INFINITO;
        }
    }
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<vertices[i].tamanho();j++){
            matriz[i][vertices[i].get(j)]=vertices[i].getPeso(j);
        }
    }
}

void grafo::imprimeMatriz(){
    int **matriz = new int*[tamanho];
    for(int i=0;i<tamanho;i++){
        matriz[i]= new int[tamanho];
    }
    converteListaMatriz(matriz);
    for (int i=0;i<tamanho;i++) {
        cout<<endl;
        for (int j=0;j<tamanho;j++)
            cout<<" "<<matriz[i][j];
    }
    cout<<endl;
    for(int i=0;i<tamanho;i++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

void grafo::letraD(int no1,int no2){
    ///////////alocando matrix de adjacencia///////////
    int **matriz = new int*[tamanho];
    for(int i=0;i<tamanho;i++){
        matriz[i]= new int[tamanho];
    }
    converteListaMatriz(matriz);
    ///////////////////criando matriz aux//////////////
    int **aux = new int*[tamanho];
    for(int i=0;i<tamanho;i++){
        aux[i]= new int[tamanho];
    }
    //////////////////Algoritimo de Floyd-Warshall///////////////////////
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            if(matriz[i][j]<INFINITO){
                aux[i][j]=i;
            }
        }
    }
    for(int k=0;k<tamanho;k++){
        for(int i=0;i<tamanho;i++){
            for(int j=0;j<tamanho;j++){
                if(matriz[i][j]>matriz[i][k]+matriz[k][j]){
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                    aux[i][j]=aux[k][j];
                }
            }
        }
    }
    ///////////////////////retorno////////////////////////////////////
    if(matriz[no1][no2]>=INFINITO){
        cout<<"letra D caminho nao existe"<<endl;
    }
    else{
        cout<<endl;
        cout<<"Letra D,para os nos "<<no1<<" e "<<no2<<":"<<matriz[no1][no2];
        cout<<endl;
    }
    //////////////////desalocando matrix aux//////////////////////
    for(int i=0;i<tamanho;i++){
        delete[] aux[i];
    }
    delete[] aux;
    ////////////////desalocando matriz principal/////////////////////////
    for(int i=0;i<tamanho;i++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

void grafo::letraC(int no1,int no2){


}

bool grafo::existeAresta(int no1,int no2){}


int grafo::getTemArestaPonderada(){
    return arestaPonderada;
}

int grafo::getEhDirecionado(){
    return direcionado;
}

int grafo::getTemPesoNosVertices(){
    return pesoNosVertices;
}

