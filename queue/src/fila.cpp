#include <iostream>
#include "fila.h"

using namespace std;

fila::fila(int cap) {
    capacidade = cap;
    dados = new int[capacidade];
    inicio = 0;
    fim = 0;
    tamanho = 0;
}

fila::~fila() {
    delete[] dados;
}

bool fila::inserir(int valor) {
    if (estaCheia())
        return false;

    dados[fim] = valor;
    fim = (fim + 1) % capacidade;
    tamanho++;
    return true;
}

bool fila::remover() {
    if (estaVazia())
        return false;

    inicio = (inicio + 1) % capacidade;
    tamanho--;
    return true;
}

int fila::consultarInicio() const {
    if (estaVazia())
        return -1; 
    return dados[inicio];
}

bool fila::estaVazia() const {
    return tamanho == 0;
}

bool fila::estaCheia() const {
    return tamanho == capacidade;
}

void fila::imprimir() const {
    cout << "[ ";
    for (int i = 0; i < tamanho; i++) {
        int indice = (inicio + i) % capacidade;
        cout << dados[indice] << " ";
    }
    cout << "]" << endl;
}