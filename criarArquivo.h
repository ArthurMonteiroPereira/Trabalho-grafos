using namespace std;
int leAteEsp(int inicio,string *text,string *alvo){
    for(int i=inicio;text[i]!=" ";i++){
        *alvo+=text[i];
        if(text[i]==" ")
            cout<<"DEU ERRADO TEM ESPACO NA STRING"<<endl;
    }

}
int determinaTamanho(string entrada){
    string aux="";
    for(int i=0;entrada[i]!='.';i++){
        if(isdigit(entrada[i]))
            aux+=entrada[i];
        else{
            aux="";
        }
    }
    return stoi(aux);
}
int determinaQuantosGrupos(string entrada){
    string aux="";
    int i=0;
    while(isdigit(entrada[i])){
        aux+=entrada[i];
        i++;
    }
    return stoi(aux);
}
void determinaAresta(string text,int *dado1,int *dado2,int *dado3){
    string aux="";
    int i;
    for(i=0;text[i]!=' ';i++){
        aux+=text[i];
    }
    *dado1=stoi(aux);
    aux="";
    for(i++;text[i]!=' ';i++){
        aux+=text[i];
    }
    *dado2=stoi(aux);
    aux="";
    for(i++;i<text.size();i++){
        aux+=text[i];
    }
    *dado3=stoi(aux);

}
/*grafo* leituraArquivo(string caminhoArquivo)
{
    cout << "Inicio leitura do arquivo" << endl;
    ifstream entrada;
    grafo *g = NULL;
    int eDirecionado;
    int eArestaPonderada;
    int eVerticePonderado;
    eDirecionado=0;
    eArestaPonderada=1;
    eVerticePonderado=0;
    entrada.open(caminhoArquivo);
    if(!entrada){
        abort();
    }
    queue<int> fila;
    string numero = "";
    for(string linha; getline(entrada,linha);){
        int maxLin = strlen(linha.c_str());
        char *c = new char[maxLin+1];
        strcpy(c, linha.c_str());

       /* for(int i = 0; i <= maxLin; i++){
            while(c[i]!= ' ' && i <= maxLin){
                numero += c[i];
                i++;
            }
            fila.push(atoi(numero.c_str()));
            numero = "";
        }
        */
/*
        if(g == NULL){
            g = new grafo(eDirecionado,eArestaPonderada,eVerticePonderado,TAMANHO);//fila.front()

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
*/
grafo* leituraArquivoNovo(string caminhoArquivo)
{
    cout << "Inicio leitura do arquivo" << endl;
    string aux;
    int j;
    for (j = caminhoArquivo.size()-1; caminhoArquivo[j] != '\\' && caminhoArquivo[j] !='/' && j!=-1; j--){
    }
    for (j++; j<caminhoArquivo.size(); j++){
        aux+=caminhoArquivo[j];
    }
    ifstream entrada;
    grafo *g = NULL;
    int eDirecionado=0;
    int eArestaPonderada=1;
    int eVerticePonderado=0;
    int quantosVertices=0,quantosGrupos=0,i=0;
    string linha;
    int dado1,dado2,dado3;
    eDirecionado=0;
    eArestaPonderada=1;
    eVerticePonderado=0;
    entrada.open(caminhoArquivo);
    
    if(!entrada){
        cout<<"Error";
        abort();
    }
    
    quantosGrupos=determinaQuantosGrupos(aux);
    quantosVertices=determinaTamanho(aux);
    g = new grafo(eDirecionado,eArestaPonderada,eVerticePonderado,quantosVertices,quantosGrupos);
    getline(entrada,linha);
    //cout<<dado1;
    
    while(linha!=""){
        g->adicionaVerticeGrupo(i,stoi(linha));
        getline(entrada,linha);
        i++;
    }
    
    
    while (!entrada.eof()){ //enquanto end of file for false continua
        getline(entrada,linha);
        if(linha!=""){
            determinaAresta(linha,&dado1,&dado2,&dado3);
            g->adicionaArestaPeso(dado1,dado2,dado3);
        }
      }
    cout<<"fim da leitura do arquivo"<<endl;
    entrada.close();
    return g;
}
