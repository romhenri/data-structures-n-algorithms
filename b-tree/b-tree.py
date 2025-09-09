class BTreeNode:
    def __init__(self, t, leaf=False):
        self.t = t
        self.leaf = leaf
        self.keys = [None] * (2 * t - 1)
        self.children = [None] * (2 * t)
        self.n = 0

    def traverse(self):
        i = 0
        for i in range(self.n):
            if not self.leaf:
                self.children[i].traverse()
            print(self.keys[i], end=" ")

        if not self.leaf:
            self.children[i + 1].traverse()

    def search(self, k):
        i = 0
        while i < self.n and k > self.keys[i]:
            i += 1

        if i < self.n and self.keys[i] == k:
            return self

        if self.leaf:
            return None

        return self.children[i].search(k)

class BTree:
    def __init__(self, t):
        self.root = None
        self.t = t

    def traverse(self):
        if self.root:
            self.root.traverse()
        print()

    def search(self, k):
        if self.root is None:
            return None
        else:
            return self.root.search(k)

    def insert(self, k):
        if self.root is None:
            self.root = BTreeNode(self.t, leaf=True)
            self.root.keys[0] = k
            self.root.n = 1
        else:
            if self.root.n == 2 * self.t - 1:
                s = BTreeNode(self.t, leaf=False)
                s.children[0] = self.root
                self._split_child(s, 0, self.root)
                
                i = 0
                if s.keys[0] < k:
                    i += 1
                self._insert_non_full(s.children[i], k)
                self.root = s
            else:
                self._insert_non_full(self.root, k)

    def _insert_non_full(self, x, k):
        i = x.n - 1

        if x.leaf:
            while i >= 0 and x.keys[i] > k:
                x.keys[i + 1] = x.keys[i]
                i -= 1
            x.keys[i + 1] = k
            x.n += 1
        else:
            while i >= 0 and x.keys[i] > k:
                i -= 1
            i += 1
            if x.children[i].n == 2 * self.t - 1:
                self._split_child(x, i, x.children[i])
                if x.keys[i] < k:
                    i += 1
            self._insert_non_full(x.children[i], k)

    def _split_child(self, x, i, y):
        t = self.t
        z = BTreeNode(t, y.leaf)
        z.n = t - 1

        for j in range(t - 1):
            z.keys[j] = y.keys[j + t]

        if not y.leaf:
            for j in range(t):
                z.children[j] = y.children[j + t]

        y.n = t - 1

        for j in range(x.n, i, -1):
            x.children[j + 1] = x.children[j]

        x.children[i + 1] = z

        for j in range(x.n - 1, i - 1, -1):
            x.keys[j + 1] = x.keys[j]

        x.keys[i] = y.keys[t - 1]
        x.n += 1


if __name__ == '__main__':
    # Cria uma B-Tree com grau mínimo 3
    # Cada nó terá no mínimo 2 chaves e no máximo 5 chaves
    arvore_b = BTree(3)

    valores = [10, 20, 5, 6, 12, 30, 7, 17, 40, 50, 1]
    for v in valores:
        arvore_b.insert(v)

    print("Percurso em ordem na árvore B:")
    arvore_b.traverse()

    valor_busca = 6
    resultado = arvore_b.search(valor_busca)
    if resultado:
        print(f"Valor {valor_busca} encontrado na árvore.")
    else:
        print(f"Valor {valor_busca} não encontrado.")

    valor_busca = 15
    resultado = arvore_b.search(valor_busca)
    if resultado:
        print(f"Valor {valor_busca} encontrado na árvore.")
    else:
        print(f"Valor {valor_busca} não encontrado.")