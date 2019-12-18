#ifndef FUNCIONALIDADES_H_INCLUDED
#define FUNCIONALIDADES_H_INCLUDED
#include <iostream>
#include <ctime>


using namespace std;


int calculaVencimento(int, int, int, int, int, int);

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
