# Graph - Algoritmos de Busca

## 🔍 BFS - Breadth First Search
Busca em largura que percorre o grafo por camadas, visitando todos os vizinhos antes de aprofundar. Usa fila (queue) e garante o menor caminho em grafos não ponderados.

## 🌲 DFS - Depth First Search
Busca em profundidade que vai o mais fundo possível antes de voltar. Pode ser recursiva (usa call stack) ou iterativa (usa pilha explícita).

## ✅ DFS Recursivo
Implementação simples com função que chama a si mesma. Útil para grafos pequenos ou problemas estruturais.

´´´cpp
void dfsRecursive(int v, vector<bool>& visited) {
    visited[v] = true;
    for (int neighbor : adjList[v])
        if (!visited[neighbor])
            dfsRecursive(neighbor, visited);
}
´´´

## ✅ DFS Iterativo
Evita recursão usando `std::stack`. Mais seguro em grafos grandes.

´´´cpp
void dfsIterative(int start) {
    stack<int> stk;
    vector<bool> visited(V, false);
    stk.push(start);
    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();
        if (!visited[current]) {
            visited[current] = true;
            for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it)
                if (!visited[*it])
                    stk.push(*it);
        }
    }
}
´´´

## 📎 Comparativo Rápido

| Algoritmo | Estrutura | Garante menor caminho | Ideal para             |
|-----------|-----------|------------------------|------------------------|
| BFS       | Fila      | ✅ Sim                 | Menor caminho, níveis  |
| DFS       | Pilha     | ❌ Não                | Componentes, ciclos    |
