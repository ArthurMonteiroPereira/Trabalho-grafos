#ifndef LISTAENC_H_INCLUDED
#define LISTAENC_H_INCLUDED


#include <iostream>

using namespace std;

// classe No
class No
{
private:
    int v;
    No* prox;
public:
    No(int v) // construtor
    {
        this->v = v;
        this->prox = NULL;
    }

    int obterValor() // obtém o valor
    {
        return v;
    }

    No* obterProx() // obtém o próximo No
    {
        return prox;
    }

    void setProx(No* p) // seta o próximo No
    {
        prox = p;
    }
};

// classe ListaEnc
class ListaEnc
{
private:
    No* cabeca; // primeiro elemento
    No* cauda; // último elemento

public:
    ListaEnc()
    {
        // se não passar elemento, então cabeca e cauda são NULL
        cabeca = NULL;
        cauda = NULL;
    }

    ListaEnc(int v)
    {
        // se passar elemento, então cria novo No
        cabeca = new No(v);
        cauda = cabeca;
    }

    virtual ~ListaEnc() // destrutor
    {
        delete cabeca;
    }

    void mostrar() // mostra todos os elementos da ListaEnc
    {
        cout << "\nImprimindo todos os elementos...\n";
        No* c = cabeca;
        if(vazia())
            cout << "A ListaEnc NAO possui elementos!!\n";
        else
        {
            while(c) // percorre a ListaEnc
            {
                cout << c->obterValor() << endl;
                c = c->obterProx();
            }
            cout << endl;
        }
    }

    bool vazia() // verifica se a ListaEnc está vazia
    {
        if(cabeca == NULL)
            return true;
        else
        {
            return false;
        }
    }

    //retorna elemento da posição x
    int get(int x)
    {
        No* c = cabeca;
        for(int i=0; i<x; i++)
        {
            c=c->obterProx();
        }
        return c->obterValor();
    }
    // insere no início (semelhante a push_front da list)
    void insereInicio(int v)
    {
        No* novo_no = new No(v);

        if(vazia())
        {
            cabeca = novo_no;
            cauda = novo_no;
        }
        else
        {
            novo_no->setProx(cabeca);
            cabeca = novo_no;
        }
    }

    // insere no final (semelhante a push_back da list)
    void insereFinal(int v)
    {
        No* novo_no = new No(v);

        if(vazia())
        {
            cabeca = novo_no;
            cauda = novo_no;
        }
        else
        {
            cauda->setProx(novo_no);
            cauda = novo_no;
        }
    }

    // retorna o tamanho da ListaEnc
    int tamanho()
    {
        if(vazia()) // se for vazia, entã retorna 0
            return 0;

        No* c = cabeca;
        int tam = 0;
        // percorre a ListaEnc
        do
        {
            c = c->obterProx();
            tam++;
        }
        while(c);
        return tam;
    }

    // verifica se um elemento existe na ListaEnc
    bool existe(int v)
    {
        No* c = cabeca;
        while(c)
        {
            if(c->obterValor() == v)
                return true;
            c = c->obterProx();
        }
        return false;
    }
    //Remove elemento da lista
    int RemoveDado(int dado)
    {
        No *ptr, *antes;
        if (cabeca==NULL)
        {
            return 0;  // Lista vazia !!!
        }
        else
        {
            ptr = cabeca;
            antes = cabeca;
            while (ptr !=NULL)
            {
                if (ptr->obterValor() == dado)
                {
                    if (ptr == cabeca)
                    {
                        cabeca = cabeca->obterProx();
                        free(ptr);
                        return 1;
                    }
                    else
                    {
                        antes->setProx(ptr->obterProx());
                        free(ptr);
                        return 1;
                    }
                }
                else
                {
                    antes = ptr;
                    ptr = ptr->obterProx();
                }
            }
            return 0;
        }
    }

    // remove da ListaEnc, remoção do final (semelhante a pop_back da list)
    void remover()
    {
        if(!vazia())
        {
            // se houver só 1 elemento
            if(cabeca->obterProx() == NULL)
                cabeca = NULL;
            else if(cabeca->obterProx()->obterProx() == NULL) // 2 elementos
                cabeca->setProx(NULL);
            else // > 2 elementos
            {
                No* ant_ant = cabeca;
                No* ant = cabeca->obterProx();
                No* corrente = cabeca->obterProx()->obterProx();

                while(corrente)
                {
                    No* aux = ant;
                    ant = corrente;
                    ant_ant = aux;
                    corrente = corrente->obterProx();
                }
                delete ant_ant->obterProx(); // libera memória
                ant_ant->setProx(NULL); // seta o prox como NULL
                cauda = ant_ant; // atualiza a cauda
            }
        }
    }
};
#endif
