#ifndef FILA_H
#define FILA_H

class fila {
private:
    int* dados;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;

public:
    fila(int capacidade);
    ~fila();

    bool inserir(int valor);
    bool remover();
    int consultarInicio() const;
    bool estaVazia() const;
    bool estaCheia() const;
    void imprimir() const;
};

#endif
