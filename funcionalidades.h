#ifndef FUNCIONALIDADES_H_INCLUDED
#define FUNCIONALIDADES_H_INCLUDED
#include <iostream>
#include <fstream>
#include <ctime>


using namespace std;


int calculaVencimento(int, int, int, int, int, int);
void insereString(char*, string);

struct noProduto{
    char nome[50];
    char codBar[13];
    float preco;
    int diaV;
    int mesV;
    int anoV;
    int qtd;
    char status;
};

class Produto{
    public:
        string nome;
        string codBar;
        float preco;
        int diaV;
        int mesV;
        int anoV;
        int qtd;
        char status;

        void insereProduto(string n, string c, float p, int d, int m, int a, int q, char s);
        void exibeProduto(void);
    private:
        void gravaProduto(string n, string c, float p, int d, int m, int a, int q, char s);
};

void Produto::insereProduto(string n, string c, float p, int d, int m, int a, int q, char s){
    this->nome = n;
    this->codBar = c;
    this->preco = p;
    this->diaV = d;
    this->mesV = m;
    this->anoV = a;
    this->qtd = q;
    this->status = s;

    this->gravaProduto(n, c, p, d, m, a, q, s);
}

void Produto::exibeProduto(void){
    struct tm *date;
    time_t segundos;
    time(&segundos);
    date = localtime(&segundos);

    int contVenci;
    int diaA, mesA, anoA;
    diaA = date->tm_mday;
    mesA = date->tm_mon + 1;
    anoA = date->tm_year + 1900;
    contVenci = calculaVencimento(this->diaV, this->mesV, this->anoV, diaA, mesA, anoA);

    cout << "\nNOME..................: " << this->nome << "\n";
    cout << "CÓDIGO DE BARRA.........: " << this->codBar << "\n";
    cout << "PREÇO...................: " << this->preco << "\n";
    if(contVenci == 0){
        cout << "ATENÇÃO! PRODUTO FORA DO PRAZO DE VALIDADE";
    } else{
        cout << "DATA DE VENCIMENTO......: " << this->diaV << "/" << this->mesV << "/" << this->anoV;
    }
    if(qtd == 0){
        cout << "\nPRODUTO ESGOTADO!\n";
    } else{
        cout << "\nRESTA(M) " << this->qtd << " UNIDADE(S) NO ESTOQUE\n";
    }
    cout << "\n";
}

void Produto::gravaProduto(string n, string c, float p, int d, int m, int a, int q, char s){
    ofstream arq;
    arq.open("produtos.dat",ios::app);

    if(!arq.is_open()){
        cout << "\nHouve um erro na abertura do arquivo 'produtos.dat', o programa será encerrado.\n";
        exit(1);
    }

    arq << "Nome: " << n << "\n";
    arq << "Código de Barras: " << c << "\n";
    arq << "Preço: " << p << "\n";
    arq << "Data de Vencimento: " << d << "/" << m << "/" << a << "\n";
    arq << "Quantidade: " << q << "\n";
    arq << "ENDINFO\n";

    arq.close();
}

void insereString(char* p, string s){
    int tam = s.size();
    for(int i = 0; i < tam; i++){
        p[i] = s[i];
    }
}

int calculaVencimento(int d1, int m1, int a1, int d2, int m2, int a2){
    if(a1 < a2){
        return 0;
    } else if((a1 == a2) && (m1 < m2)){
        return 0;
    } else if((a1 == a2) && (m1 == m2) && (d1 < d2)){
        return 0;
    } else{
        return 1;
    }
}


#endif
