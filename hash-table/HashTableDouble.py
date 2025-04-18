class HashTableDouble:
    def __init__(self, n):
        self.n = n
        self.level1_size = 10
        self.level2_size = n // self.level1_size
        self.table = [[[] for _ in range(self.level2_size)] for _ in range(self.level1_size)]

    # H1
    def hash1(self, key):
        return hash(key) % self.level1_size

    # H2
    def hash2(self, key):
        return (hash(key) // self.level1_size) % self.level2_size

    def insert(self, key, value):
        i = self.hash1(key)
        j = self.hash2(key)
        for k, (k_existente, _) in enumerate(self.table[i][j]):
            if k_existente == key:
                self.table[i][j][k] = (key, value)
                return
        self.table[i][j].append((key, value))

    def search(self, key):
        i = self.hash1(key)
        j = self.hash2(key)
        for k_existente, valor in self.table[i][j]:
            if k_existente == key:
                return valor
        return None