class Node:
    def __init__(self, valor):
        self.valor = valor
        self.esquerda = None
        self.direita = None

class ArvoreBinaria:
    def __init__(self):
        self.raiz = None

    def inserir(self, valor):
        self.raiz = self._inserir_recursivo(self.raiz, valor)

    def _inserir_recursivo(self, no, valor):
        if no is None:
            return Node(valor)
        if valor < no.valor:
            no.esquerda = self._inserir_recursivo(no.esquerda, valor)
        else:
            no.direita = self._inserir_recursivo(no.direita, valor)
        return no

    def em_ordem(self):
        self._em_ordem_recursivo(self.raiz)
        print()

    def _em_ordem_recursivo(self, no):
        if no:
            self._em_ordem_recursivo(no.esquerda)
            print(no.valor, end=' ')
            self._em_ordem_recursivo(no.direita)

    def buscar(self, valor):
        return self._buscar_recursivo(self.raiz, valor)

    def _buscar_recursivo(self, no, valor):
        if no is None or no.valor == valor:
            return no
        if valor < no.valor:
            return self._buscar_recursivo(no.esquerda, valor)
        else:
            return self._buscar_recursivo(no.direita, valor)

if __name__ == "__main__":
    arvore = ArvoreBinaria()
    valores = [8, 3, 10, 1, 6, 14, 4, 7, 13]
    for v in valores:
        arvore.inserir(v)

    print("Em ordem (crescente):")
    arvore.em_ordem()

    valor_busca = 6
    resultado = arvore.buscar(valor_busca)
    if resultado:
        print(f"Valor {valor_busca} encontrado.")
    else:
        print(f"Valor {valor_busca} não está na árvore.")
