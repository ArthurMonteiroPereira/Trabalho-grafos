#include <iostream>
#include <stdio.h>
#include "ListaEnc.h"
#define T 10
using namespace std;


class grafo
{
private:
    ListaEnc *vertices;
    int tamanho;
    int direcionado; //0=não direcionado,1=direcionado
    int arestaPonderada; //0=não ponderada,1=ponderada
    int pesoNosVertices; //0=sem peso,1=com peso
public:
    grafo(int tam);
    grafo(int direcionado,int arestaPonderada,int pesoNosVertices,int tam);
    ~grafo();
    bool existeAresta(int no1,int no2);
    void imprime();
    void adicionaAresta(int no1,int no2);
    void removeAresta(int no1,int no2);

};
