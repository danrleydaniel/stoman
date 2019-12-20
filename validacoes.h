#ifndef VALIDACOES_H_INCLUDED
#define VALIDACOES_H_INCLUDED
#include <iostream>
#include <ctime>
#include <Math.h>

int validaCodBar(string);
int validaData(int, int, int);
int bissexto(int);
int chartoint(char);
int stringtoint(string);
int validaValor(string);

int validaCodBar(string codigo){
    if(codigo.size() == 8 || codigo.size() == 13){
        return 1;
    } else{
        return 0;
    }
}

int bissexto(int a){
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
    int tam = s.size();
    int j = 0;
    int soma = 0;
    int pos;
    for(int i = tam - 1; i >= 0; i--){
        pos = chartoint(s[j]);
        pos = pos * pow(10, i);
        soma = soma + pos;
        j++;
    }
    return soma;
}

int chartoint(char c){
    return c - '0';
}

int validaValor(string s){
    char c;
    int tam = s.size();
    for(int i = 0; i < tam; i++){
        c = s[i];
        if(c < '0' || c > '9'){
            return 0;
        }
    }
    return 1;
}


#endif
