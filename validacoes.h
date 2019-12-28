#ifndef VALIDACOES_H_INCLUDED
#define VALIDACOES_H_INCLUDED
#include <iostream>
#include <ctime>
#include <string>
#include <Math.h>

/* 
    BIBLIOTECA RESPONSÁVEL POR VALIDAR A ENTRADA DE DADOS DO USUÁRIO
*/

//DECLARAÇÃO DAS FUNÇÕES:
int validaCodBar(string);
int validaData(int, int, int);
int bissexto(int);
int chartoint(char);
int stringtoint(string);
int validaValor(string);
int validaPreco(string);

int validaCodBar(string codigo){
    //VALIDA CÓDIGO DE BARRAR DE ACORDO COM O PADRÃO BRASILEIRO DE TER 8 OU 13 CARACTERES.
    if(codigo.size() == 8 || codigo.size() == 13){
        return 1;
    } else{
        return 0;
    }
}

int bissexto(int a){
    //FUNÇÃO QUE VERIFICA SE UM ANO É BISSEXTO. NECESSÁRIO PARA A VALIDAÇÃO DA DATA.
    if((a % 4 == 0) && (a % 100 != 0)){
        return 1;
    } else if (a % 400 == 0){
        return 1;
    } else{
        return 0;
    }
}

int validaData(int d, int m, int a){
    int maiorDia;
    if(a < 0 || m < 1 || m > 12){
        return 0;
    }

    if (m == 2){
        if (bissexto(a)){
            maiorDia = 29;
        } else{
            maiorDia = 28;
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11){
        maiorDia = 30;
    } else{
        maiorDia = 31;
    }

    if(d < 1 || d > maiorDia){
        return 0;
    }

    return 1;
}

int stringtoint(string s){
    //TRANSFORMA STRING EM INTEIRO
    int tam = s.size();
    int j = 0;
    int soma = 0;
    int pos;
    for(int i = tam - 1; i >= 0; i--){
        pos = chartoint(s[j]);
        pos = pos * pow(10, i); //REALIZA O POLINÔMIO
        soma = soma + pos;
        j++;
    }
    return soma;
}

int chartoint(char c){
    return c - '0';
}

int validaValor(string s){
    //FUNÇÃO PARA VALIDAR A QUANTIDADE NO ESTOQUE.
    char c;
    int tam = s.size();
    for(int i = 0; i < tam; i++){
        c = s[i];
        if(c < '0' || c > '9'){
            return 0; //SÓ ACEITA NÚMEROS!
        }
    }
    return 1;
}

int validaPreco(string p){
    int tam = p.size();
    int qtdDePts = 0; //VAI CONTAR QUANTOS PONTOS TEM NA STRING. OBRIGATORIAMENTE, NO PREÇO DEVE HAVER APENAS 1
    for(int i = 0; i < tam; i++){
        if((p[i] < '0' || p[i] > '9') && (p[i] != '.')){
            return 0; //APENAS NÚMEROS OU O PONTO É ACEITO.
        }
        
        if(p[i] == '.'){
            qtdDePts++;
        }
    }
    if(qtdDePts == 1){
        return 1; //QUANTIDADE DE PONTOS DEVE SER IGUAL A 1
    } else{
        return 0; //CASO CONTRÁRIO, O RETORNO É 0.
    }
}

#endif
