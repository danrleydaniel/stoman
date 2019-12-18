#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include "funcionalidades.h"

using namespace std;

void logotipoPrincipal(void);
char menuPrincipal(void);

void cadastraProduto(void);
void logoCadastraProduto(void);
void listaProdutos(void);
void editaProduto(void);
void deletaProduto(void);
void registraCompra(void);
void listaRelatorio(void);
void sobre(void);



int main(void){
    system("cls||clear");
    char op;
    logotipoPrincipal();
    op = menuPrincipal();

    while(op != '0'){
        switch(op){
            case '1': cadastraProduto(); break;
            case '2': listaProdutos(); break;
            case '3': editaProduto(); break;
            case '4': deletaProduto(); break;
            case '5': registraCompra(); break;
            case '6': listaRelatorio(); break;
            case '7': sobre(); break;
            default: cout << "\nOpção inválida!\n";
        }
        cout << "\nO que deseja fazer agora? ";
        op = menuPrincipal();
    }

    return 0;
}

void logotipoPrincipal(void){
    cout << " _____ _____ ________  ___  ___   _   _ \n"
    "/  ___|_   _|  _  |  \\/  | / _ \\ | \\ | |\n"
    "\\ `--.  | | | | | | .  . |/ /_\\ \\|  \\| |\n"
    " `--. \\ | | | | | | |\\/| ||  _  || . ` |\n"
    "/\\__/ / | | \\ \\_/ / |  | || | | || |\\  |\n"
    "\\____/  \\_/  \\___/\\_|  |_/\\_| |_/\\_| \\_/\n"
    "                                        \n"
    "                                        ";
}

char menuPrincipal(void){
    char opc;
    cout << "\n1 - Cadastrar Produto\n";
    cout << "2 - Listar Produtos\n";
    cout << "3 - Editar Produto\n";
    cout << "4 - Deletar Produto\n";
    cout << "5 - Registrar Compra\n";
    cout << "6 - Listar Relatórios de Vendas\n";
    cout << "7 - Sobre\n";
    cout << "0 - Sair\n\n";
    cout << "ESCOLHA UMA OPÇÃO: ";
    cin >> opc;
    return opc;
}

void cadastraProduto(void){
    logoCadastraProduto();
    Produto *novoProduto = new Produto();
    string name;
    string cod;
    float price;
    int day, month, year;
    int quantidade;

    setbuf(stdin, NULL);
    cout << "\nINFORME DOS DADOS A SEGUIR:\n";
    cout << "\nNome: ";
    getline(cin, name);
    cout << "\n\nCódigo de Barras: ";
    cin >> cod;
    cout << "\n\nPreço: ";
    cin >> price;
    cout << "\n\nData de Vencimento: (DIA MÊS ANO): ";
    cin >> day >> month >> year;
    cout << "\n\nQuantidade no Estoque: ";
    cin >> quantidade;

    novoProduto->insereProduto(name, cod, price, day, month, year, quantidade, 'c');
    novoProduto->exibeProduto();
    
}

void listaProdutos(void){
    cout << "\nEm breve\n";
}

void editaProduto(void){
    cout << "\nEm breve\n";
}

void deletaProduto(void){
    cout << "\nEm breve\n";
}

void registraCompra(void){
    cout << "\nEm breve\n";
}

void listaRelatorio(void){
    cout << "\nEm breve\n";
}

void sobre(void){
    cout << "\nEm breve\n";
}

void logoCadastraProduto(void){
    system("cls||clear");
    cout << "  _       _        __ ___ _        _     _   _   _   _     ___ _  \n"
    " /   /\\  | \\  /\\  (_   | |_)  /\\  |_)   |_) |_) / \\ | \\ | | | / \\ \n"
    " \\_ /--\\ |_/ /--\\ __)  | | \\ /--\\ | \\   |   | \\ \\_/ |_/ |_| | \\_/ \n"
    "                                                                  ";
}

