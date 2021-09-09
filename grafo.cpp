#include <iostream>
#include <stdio.h>
#include "ListaEnc.h"
#include "grafo.h"
#define T 10
#define INFINITO 999999999
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

grafo::grafo(int eDirecionado,int eArestaPonderada,int ePesoNosVertices,int tam)
{
    direcionado=eDirecionado;
    arestaPonderada=eArestaPonderada;
    pesoNosVertices=ePesoNosVertices;
    tamanho = tam;
    vertices = new ListaEnc[tam];
    if(ePesoNosVertices==1)
    {
        pesoV = new int[tam];
        for(int i=0; i<tam; i++)
            pesoV[i]=0;
    }
}
grafo::grafo(int eDirecionado,int eArestaPonderada,int ePesoNosVertices,int tam,int qntGrupos)
{
    direcionado=eDirecionado;
    arestaPonderada=eArestaPonderada;
    pesoNosVertices=ePesoNosVertices;
    tamanho = tam;
    vertices = new ListaEnc[tam];
    if(ePesoNosVertices==1)
    {
        pesoV = new int[tam];
        for(int i=0; i<tam; i++)
            pesoV[i]=0;
    }
    grupos = new ListaEnc[qntGrupos+1];
    numeroDeGrupos=qntGrupos+1;
}
grafo::grafo(int tam)
{
    direcionado=0;
    arestaPonderada=0;
    pesoNosVertices=0;
    tamanho = tam;
    vertices = new ListaEnc[tam];
}
grafo::~grafo()
{
    for(int i=0; i<tamanho; i++)
    {
        vertices[i].remover();
    }
    delete []vertices;
    if(pesoNosVertices==1)
    {
        delete []pesoV;
    }
}
void grafo::imprimeArestaModelo(ofstream *saida,int no1,int no2,int caminho)
{
    if(saida->is_open())
    {
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
            *saida << no1 << "_p" << pesoV[no1];
            if(isDir)
                *saida << "->";
            else
                *saida << "--";
            *saida << no2;
            if(isPond)
                *saida << "[label =" << caminho << "]" <<endl;
        }
        if(!hasPesoVert)
        {
            *saida << no1;
            if(isDir)
                *saida << "->";
            else
                *saida << "--";
            *saida << no2;
            if(isPond)
                *saida << "[label =" << caminho << "]" <<endl;
        }
        *saida << "}";
    }
    else
        cout << "Problema ao criar arquivo" << endl;
}
void grafo::imprimeArestaModeloTela(int no1,int no2,int caminho){

        int isDir = getEhDirecionado();
        int isPond = getTemArestaPonderada();
        int hasPesoVert = getTemPesoNosVertices();
        if(isDir)
        {
            cout<< "strict digraph {" << endl;
        }

        if(!isDir)
        {
            cout << "strict graph {" << endl;
        }
        if(hasPesoVert)
        {
            cout << no1 << "_p" << pesoV[no1];
            if(isDir)
                cout << "->";
            else
                cout << "--";
            cout << no2;
            if(isPond)
                cout << "[label =" << caminho << "]" <<endl;
        }
        if(!hasPesoVert)
        {
            cout << no1;
            if(isDir)
                cout << "->";
            else
                cout << "--";
            cout << no2;
            if(isPond)
                cout << "[label =" << caminho << "]" <<endl;
        }
        cout << "}";
}
void grafo::imprimeEmDot(ofstream *saida,ListaEnc* solucao)  // Mudar pra abrir o arquivo de saida aqui dentro mesmo
{
    if(saida->is_open())
    {
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
                if(solucao->existe(i))
                {
                    for(int z=0; z<vertices[i].tamanho()&&solucao->existe(z); z++)
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
                if(solucao->existe(i))
                {
                    for(int z=0; z<vertices[i].tamanho()&&solucao->existe(z); z++)
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
    }
    else
        cout << "Problema ao criar arquivo" << endl;
}
void grafo::imprimeEmDotTela(ListaEnc* solucao)  // Mudar pra abrir o arquivo de saida aqui dentro mesmo
{

        int isDir = getEhDirecionado();
        int isPond = getTemArestaPonderada();
        int hasPesoVert = getTemPesoNosVertices();

        if(isDir)
        {
            cout << "strict digraph {" << endl;
        }

        if(!isDir)
        {
            cout << "strict graph {" << endl;
        }

        if(hasPesoVert)
        {
            for(int i=0; i < tamanho; i++)
                if(solucao->existe(i))
                {
                    for(int z=0; z<vertices[i].tamanho()&&solucao->existe(z); z++)
                    {
                        cout << i << "_p" << pesoV[i];
                        if(isDir)
                            cout << "->";
                        else
                            cout << "--";
                        cout << vertices[i].get(z);
                        if(isPond)
                            cout << "[label =" << retornaPesoAresta(i,vertices[i].get(z)) << "]" <<endl;

                    }
                }
                else
                    cout << i << endl;
        }

        if(!hasPesoVert)
        {
            for(int i=0; i < tamanho; i++)
                if(solucao->existe(i))
                {
                    for(int z=0; z<vertices[i].tamanho()&&solucao->existe(z); z++)
                    {
                        cout << i;
                        if(isDir)
                            cout << "->";
                        else
                            cout << "--";
                        cout << vertices[i].get(z);
                        if(isPond)
                            cout << "[label =" << retornaPesoAresta(i,vertices[i].get(z)) << "]" <<endl;
                    }

                }
                else
                    cout << i << endl;
        }
        cout << "}";
}
void grafo::imprime()
{
    cout<<endl;
    cout<<tamanho<<endl;
    for(int i=0; i<tamanho; i++)
    {
        cout<<i<<" -- ";
        if(!vertices[i].vazia())
        {
            for(int z=0; z<vertices[i].tamanho(); z++)
                cout<<vertices[i].get(z)<<",";
        }
        cout<<endl;
    }
}
void grafo::adicionaAresta(int no1,int no2)
{
    if(no1>=tamanho || no2>=tamanho)
    {
        cout<<"error:VERTICES NAO PRESENTES"<<endl;
    }
    if(direcionado==1)
    {
        vertices[no1].insereInicio(no2);
    }
    else
    {
        vertices[no2].insereInicio(no1);
        vertices[no1].insereInicio(no2);
    }
}
void grafo::adicionaArestaPeso(int no1,int no2,int peso)
{
    if(no1>=tamanho || no2>=tamanho)
    {
        cout<<"error:VERTICES NAO PRESENTES"<<endl;
    }
    if(direcionado==1)
    {
        vertices[no1].insereInicio(no2);
        vertices[no1].setPeso(0,peso);
    }
    else
    {
        vertices[no2].insereInicio(no1);
        vertices[no2].setPeso(0,peso);
        vertices[no1].insereInicio(no2);
        vertices[no1].setPeso(0,peso);
    }
}

void grafo::adicionaVerticeGrupo(int vertice,int qualGrupo){
    grupos[qualGrupo].insereInicio(vertice);
}

void grafo::removeAresta(int no1,int no2)
{
    if(vertices[no1].existe(no2))
    {
        vertices[no1].RemoveDado(no2);
        vertices[no2].RemoveDado(no1);
    }
    else
    {
        cout<<"erro aresta nao existe";
    }
}

void grafo::inserePesoVertice(int vert,int peso)
{
    pesoV[vert]=peso;
}
void grafo::imprimeVerticePeso()
{
    cout<<endl;
    for(int i=0; i<tamanho; i++)
    {
        cout<<"vertice "<<i<<" pesa:"<<pesoV[i]<<endl;
    }
    cout<<endl;
}
void grafo::imprimeArestaPeso()
{
    cout<<endl;
    cout<<tamanho<<endl;
    for(int i=0; i<tamanho; i++)
    {
        cout<<i<<" -- ";
        if(!vertices[i].vazia())
        {
            for(int z=0; z<vertices[i].tamanho(); z++)
                cout<<vertices[i].get(z)<<"("<<vertices[i].getPeso(z)<<")"<<" ,";
        }
        cout<<endl;
    }

}
void grafo::alteraPesoAresta(int no1,int no2,int peso)
{
    if(direcionado==1)
    {
        if(vertices[no1].existe(no2))
        {
            vertices[no1].setPeso(vertices[no1].existeRetorna(no2),peso);
        }
        else
        {
            cout<<"erro na alteração de peso da aresta,aresta não existe";
        }
    }
    else
    {
        vertices[no1].setPeso(vertices[no1].existeRetorna(no2),peso);
        vertices[no2].setPeso(vertices[no2].existeRetorna(no1),peso);
    }
}
int grafo::retornaPesoAresta(int no1,int no2)
{
    return vertices[no1].getPeso(vertices[no1].existeRetorna(no2));
}

void grafo::converteListaMatrizD(int **matriz)
{
    for(int i=0; i<tamanho; i++)
    {
        for(int j=0; j<tamanho; j++)
        {
            matriz[i][j]=INFINITO;
        }
    }
    for(int i=0; i<tamanho; i++)
    {
        for(int j=0; j<vertices[i].tamanho(); j++)
        {
            matriz[i][vertices[i].get(j)]=vertices[i].getPeso(j);
        }
    }
}

void grafo::imprimeMatriz()
{
    int **matriz = new int*[tamanho];
    for(int i=0; i<tamanho; i++)
    {
        matriz[i]= new int[tamanho];
    }
    converteListaMatrizD(matriz);
    for (int i=0; i<tamanho; i++)
    {
        cout<<endl;
        for (int j=0; j<tamanho; j++)
            cout<<" "<<matriz[i][j];
    }
    cout<<endl;
    for(int i=0; i<tamanho; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void grafo::converteListaMatrizAB(bool **matriz)
{
    for(int i=0; i<tamanho; i++)
    {
        for(int j=0; j<tamanho; j++)
        {
            matriz[i][j]=false;
        }
    }
    for(int i=0; i<tamanho; i++)
    {
        for(int j=0; j<tamanho; j++)
        {
            if(i == j )
                matriz[i][j]= false;
            else
                matriz[i][j]=vertices[i].existe(j);

        }
    }
}

void grafo::letraA(ofstream *saida,int id)
{
    cout << "Inicio letra A" << endl;
    if(id < tamanho)
    {
        ListaEnc *solucao;
        stack<int> pilha;
        bool **matriz = new bool*[tamanho];
        for(int i=0; i<tamanho; i++)
        {
            matriz[i]= new bool[tamanho];
        }

        converteListaMatrizAB(matriz);
        solucao = new ListaEnc();

        if(!vertices[id].vazia())
        {
            for(int j = 0; j < tamanho; j++)
            {
                if(matriz[id][j])
                {
                    if(!solucao->existe(j))
                    {
                        solucao->insereFinal(j);
                        pilha.push(j);
                    }
                }
            }
        }
        while(!pilha.empty())
        {
            id = pilha.top();
            pilha.pop();

            if(!vertices[id].vazia())
            {
                for(int j = 0; j < tamanho; j++)
                {
                    if(matriz[id][j])
                    {
                        if(!solucao->existe(j))
                        {
                            solucao->insereFinal(j);
                            pilha.push(j);
                        }
                    }
                }
            }

        }
        imprimeEmDotTela(solucao);
        imprimeEmDot(saida,solucao);
        cout << "Fim letra A" << endl;
    }
}

void grafo::letraB(ofstream *saida,int id)
{
    cout << "Inicio letra B" << endl;
    if(id < tamanho)
    {
        ListaEnc *solucao;
        stack<int> pilha;
        bool **matriz = new bool*[tamanho];
        for(int i=0; i<tamanho; i++)
        {
            matriz[i]= new bool[tamanho];
        }

        converteListaMatrizAB(matriz);
        solucao = new ListaEnc();

        if(!vertices[id].vazia())
        {
            for(int i = 0; i < tamanho; i++)
            {
                if(matriz[i][id])
                {
                    if(!solucao->existe(i))
                    {
                        solucao->insereFinal(i);
                        pilha.push(i);
                    }
                }
            }
        }
        while(!pilha.empty())
        {
            id = pilha.top();
            pilha.pop();

            if(!vertices[id].vazia())
            {
                for(int i = 0; i < tamanho; i++)
                {
                    if(matriz[i][id])
                    {
                        if(!solucao->existe(i))
                        {
                            solucao->insereFinal(i);
                            pilha.push(i);
                        }
                    }
                }
            }

        }
        imprimeEmDotTela(solucao);
        imprimeEmDot(saida,solucao);
        cout << "Fim letra B" << endl;
    }
}

int grafo::letraD(int no1,int no2)
{
    ///////////alocando matrix de adjacencia///////////
    int **matriz = new int*[tamanho];
    for(int i=0; i<tamanho; i++)
    {
        matriz[i]= new int[tamanho];
    }
    converteListaMatrizD(matriz);
    ///////////////////criando matriz aux//////////////
    int **aux = new int*[tamanho];
    for(int i=0; i<tamanho; i++)
    {
        aux[i]= new int[tamanho];
    }
    //////////////////Algoritimo de Floyd-Warshall///////////////////////
    for(int i=0; i<tamanho; i++)
    {
        for(int j=0; j<tamanho; j++)
        {
            if(matriz[i][j]<INFINITO)
            {
                aux[i][j]=i;
            }
        }
    }
    for(int k=0; k<tamanho; k++)
    {
        for(int i=0; i<tamanho; i++)
        {
            for(int j=0; j<tamanho; j++)
            {
                if(matriz[i][j]>matriz[i][k]+matriz[k][j])
                {
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                    aux[i][j]=aux[k][j];
                }
            }
        }
    }
    ///////////////////////retorno////////////////////////////////////
    if(matriz[no1][no2]>=INFINITO)
    {
        cout<<"letra D caminho nao existe"<<endl;
    }
    else
    {
        return matriz[no1][no2];
    }
    //////////////////desalocando matrix aux//////////////////////
    for(int i=0; i<tamanho; i++)
    {
        delete[] aux[i];
    }
    delete[] aux;
    ////////////////desalocando matriz principal/////////////////////////
    for(int i=0; i<tamanho; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
}

int grafo::letraC(int no1,int no2)
{
    int aux;
    ///////////alocando matrix de adjacencia///////////
    int **matriz = new int*[tamanho];
    for(int i=0; i<tamanho; i++)
    {
        matriz[i]= new int[tamanho];
    }
    converteListaMatrizD(matriz);
    //////////// ALGORITIMO //////////////////
    int *dist = new int [tamanho];
    bool *esta = new bool[tamanho];
    for(int i=0;i<tamanho;i++){
        dist[i]=INFINITO;
        esta[i]=false;
    }
    dist[no1]=0;
    for(int i=0;i<tamanho-1;i++){
        int u = minVetor(dist,esta);
        esta[i]=true;
        for(int j=0;j<tamanho;j++){
            if(!esta[j]&& matriz[u][j]&&dist[u]!=INFINITO&&dist[u]+matriz[u][j]<dist[j]){
                dist[j]=dist[u]+matriz[u][j];
            }
        }
    }
    //////////////////////////////
    aux=dist[no2];
    //////////////////////////////
    for(int i=0; i<tamanho; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
    ///////////////////////////
    return aux;
}

int grafo::minVetor(int *dist,bool *esta){
    int base=INFINITO;
    int mIndice;
    for(int i=0;i<tamanho;i++){
        if(esta[i]==false && dist[i]<=base){
            base=dist[i];
            mIndice=i;
        }
    }
    return mIndice;
}

void grafo::letraE(ofstream *saida,ListaEnc *vet)
{
    grafo *sub = new grafo(direcionado, arestaPonderada, pesoNosVertices,tamanho);
    ListaEnc *solucao =new ListaEnc(), *conectados = new ListaEnc();
    int arestaMin[] = {INFINITO,INFINITO,INFINITO};

    for(int k = 0; k < vet->tamanho(); k++)
    {
        solucao->insereInicio(vet->get(k));
    }

    conectados->insereInicio(vet->get(0));
    while(conectados->tamanho() < solucao->tamanho())
    {
        for(int i = 0; i < tamanho; i++)
        {
            for(int j = 0; j < tamanho; j++)
            {
                if(vertices[i].existe(j) && solucao->existe(j) && !conectados->existe(j) && solucao->existe(i) && conectados->existe(i))
                {
                    if(vertices[i].getPeso(vertices[i].existeRetorna(j)) < arestaMin[2])
                    {
                        arestaMin[0] = i;
                        arestaMin[1] = j;
                        arestaMin[2] = vertices[i].getPeso(vertices[i].existeRetorna(j));
                    }
                }
            }
        }
        sub->adicionaArestaPeso(arestaMin[0],arestaMin[1],arestaMin[2]);
        conectados->insereInicio(arestaMin[1]);
        arestaMin[2] = INFINITO;
    }

    sub->imprimeEmDot(saida,solucao);
    sub->imprimeEmDotTela(solucao);
}

int grafo::contaArestas(){
     int aux=0;
     for(int i=0;i<tamanho;i++){
           aux+=vertices[i].tamanho();
     }
     return aux;
}
void grafo::letraF(ofstream *saida, ListaEnc *vet){

    grafo *arvore = new grafo(direcionado, arestaPonderada, pesoNosVertices, tamanho);

    for(int k = 0; k < vet->tamanho(); k++)
    {
    }

}

void grafo::letraG(ofstream *saida, int id){
    ListaEnc *arvore = new ListaEnc();
    bool *visitados = new  bool[tamanho];
    for(int i = 0; i < tamanho; i++){
        visitados[i] = false;
    }
    arvore = recursivoG(id,arvore,visitados);
    imprimeEmDot(saida, arvore);
    imprimeEmDotTela(arvore);
}

ListaEnc* grafo::recursivoG(int id, ListaEnc *sol, bool *vis){
    vis[id] = true;
    sol->insereFinal(id);

    for(int i = 0; i < vertices[id].tamanho(); i++){
        if(!vis[vertices[id].get(i)]){
            recursivoG(vertices[id].get(i),sol,vis);
        }
    }
    return  sol;
}

bool grafo::existeAresta(int no1,int no2) {}


int grafo::getTemArestaPonderada()
{
    return arestaPonderada;
}

int grafo::getEhDirecionado()
{
    return direcionado;
}

int grafo::getTemPesoNosVertices()
{
    return pesoNosVertices;
}

void grafo::letraH(ofstream *saida)
{
    int entrada =0;
    int* grau_e = new int[tamanho];
    for(int i =0; i<tamanho;i++)
    {
        grau_e[i]=0;
    }
    for(int i=0; i<tamanho;i++)
    {
        for(int j=0; j<vertices[i].tamanho();j++)
        {
            if(vertices[i].existe(j))
            {
                grau_e[vertices[i].get(j)]+=1;
            }
        }
    }
    for(int i =0; i<tamanho;i++)
    {
        if(grau_e[i]==0)
        {
            entrada = i;
            auxH(saida,entrada);
            return;
        }
        cout<<"grafo nao e aciclico"<<endl;
    }

    return;
}

void grafo::auxH(ofstream *saida, int id){
    ListaEnc *arvore = new ListaEnc();
    bool *visitados = new  bool[tamanho];
    for(int i = 0; i < tamanho; i++){
        visitados[i] = false;
    }
    arvore = recursivoH(id,arvore,visitados);
    if(arvore!=NULL)
    {
        cout<<"Ordenacao topologica:"<<endl;
        arvore->mostrar();
        imprimeEmDot(saida, arvore);
        imprimeEmDotTela(arvore);
    }
    else
        cout<<"grafo nao e aciclico"<<endl;

}

ListaEnc* grafo::recursivoH(int id, ListaEnc *sol, bool *vis){
    if(sol!=NULL)
    {
         vis[id] = true;
        sol->insereFinal(id);

        for(int i = 0; i < vertices[id].tamanho(); i++){
            if(!vis[vertices[id].get(i)]){
                recursivoH(vertices[id].get(i),sol,vis);
            }
            else
            {
                sol = NULL;
                return sol;
            }
            }
    }
    else
        cout<<"sol NULL"<<endl;

    return  sol;
}
int grafo::grupoVerticeX(int x){
    for(int i = 0; i < numeroDeGrupos; i++){
        if(grupos[i].existe(x))
            return i;
    }
}


int  grafo::aGM()
{
    int status;
    int custoSol = 0;
    ListaEnc *solucao = new ListaEnc(), *conectados = new ListaEnc();
    int arestaMin[] = {INFINITO,INFINITO,INFINITO};
    bool *visitados = new  bool[numeroDeGrupos];
    for(int i = 0; i < numeroDeGrupos; i++){
        visitados[i]=false;
    }

    for(int k = 0; k < tamanho; k++)
    {
        solucao->insereInicio(k);
    }

    conectados->insereInicio(0);
    visitados[grupoVerticeX(0)]=true;
    while(status!=numeroDeGrupos)
    {
        status=0;
        for(int i = 0; i < tamanho; i++)
        {
            for(int j = 0; j < tamanho; j++)
            {   
                if(vertices[i].existe(j) && solucao->existe(j) && !conectados->existe(j) && solucao->existe(i) && conectados->existe(i))
                {
                    if(visitados[grupoVerticeX(j)]==false){
                        if(vertices[i].getPeso(vertices[i].existeRetorna(j)) < arestaMin[2])
                        {
                            arestaMin[0] = i;
                            arestaMin[1] = j;
                            arestaMin[2] = vertices[i].getPeso(vertices[i].existeRetorna(j));

                        }
                    }
                }
            }
        }

        custoSol += arestaMin[2];
        conectados->insereInicio(arestaMin[1]);
        arestaMin[2] = INFINITO;
        visitados[grupoVerticeX(arestaMin[1])]=true;
        //cout<<custoSol<<endl;
        for(int i=1;i<numeroDeGrupos;i++){
            if(visitados[i]==true){
                status=status+1;
            }
        }
        status++;
    }
    //cout << "Custo da solucao com algoritmo guloso:" << custoSol << endl;
    return custoSol;
}
