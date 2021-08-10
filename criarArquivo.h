grafo* leituraArquivo()
{
    cout << "Inicio leitura do arquivo" << endl;
    ifstream entrada;
    grafo *g = NULL;
    cout << "Digite nome do arquivo .txt:" << endl;
    string arquivo;
    cin >> arquivo;
    arquivo += ".txt";
    entrada.open(arquivo.c_str());
    if(!entrada){
        abort();
    }
    queue<int> fila;
    string numero = "";
    for(string linha; getline(entrada,linha);){
        int maxLin = strlen(linha.c_str());
        char *c = new char[maxLin+1];
        strcpy(c, linha.c_str());
        for(int i = 0; i <= maxLin; i++){
            while(c[i]!= ' ' && i <= maxLin){
                numero += c[i];
                i++;
            }
            fila.push(atoi(numero.c_str()));
            numero = "";
        }
        if(g == NULL){
            g = new grafo(0,0,0, fila.front());
            fila.pop();
        }

        else
        {
            while(!fila.empty())
            {
                int no1, no2;
                no1 = fila.front();
                fila.pop();
                no2 = fila.front();
                fila.pop();
                if(g->getTemArestaPonderada() == 1){
                    int peso;
                    peso = fila.front();
                    fila.pop();
                    g->adicionaArestaPeso(no1,no2,peso);
                }
                else
                {
                    g->adicionaAresta((no1-1),(no2-1));

                }
            }
        }
    }
    cout << "Fim leitura arquivo" << endl;
    entrada.close();
    return g;
}
