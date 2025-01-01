# -*- coding: utf-8 -*-
from random import randint

from src.jogador import Jogador
from src.tabuleiro import Tabuleiro

class JogadorIA(Jogador):
    def __init__(self, tabuleiro : Tabuleiro, tipo : int):
        super().__init__(tabuleiro, tipo)

    def getJogada(self) -> (int, int):
        f_rule1 = self.possivel_vitoria()
        
        if isinstance(f_rule1, tuple):
            return f_rule1

        f_rule2 = self.cria_duas_sequencias()
        if isinstance(f_rule2, tuple):
            return f_rule2

        f_rule3 = self.usar_centro()
        if isinstance(f_rule3, tuple):
            return f_rule3

        cantos = [(0, 0), (0, 2), (2, 0), (2, 2)]

        f_rule4 = self.marcar_canto_oposto(cantos)
        if isinstance(f_rule4, tuple):
            return f_rule4

        f_rule5 = self.marcar_qualquer_canto(cantos)
        if isinstance(f_rule5, tuple):
            return f_rule5

        f_rule6 = self.jogada_aleatoria()
        return f_rule6

    ### Rule 1

    def seq_com_vitoria(self, line) -> int:
        for i in range(0, 3):
            if line[i] == Tabuleiro.DESCONHECIDO:
                return i
        return -1

    def possivel_vitoria(self) -> (int, int):
        # Linhas
        for l in range(0, 3):
            soma = 0
            for c in range(0, 3):
                soma += self.matriz[l][c]
            if soma == 2:
                in_c = self.seq_com_vitoria(self.matriz[l])
                if in_c != -1:
                    return l, in_c

        # Colunas
        for c in range(0, 3):
            soma = 0
            for l in range(0, 3):
                soma += self.matriz[l][c]
            if soma == 2:
                for l in range(0, 3):
                    if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                        return l, c

        # Diagonal Principal
        soma = 0
        for i in range(0, 3):
            soma += self.matriz[i][i]
        if soma == 2:
            for i in range(0, 3):
                if self.matriz[i][i] == Tabuleiro.DESCONHECIDO:
                    return i, i

        # Diagonal Secundária
        soma = 0
        for i in range(0, 3):
            soma += self.matriz[i][2 - i]
        if soma == 2:
            for i in range(0, 3):
                if self.matriz[i][2 - i] == Tabuleiro.DESCONHECIDO:
                    return i, 2 - i

        return None

    ### Rule 2

    def cria_duas_sequencias(self) -> (int, int):
        for l in range(3):
            for c in range(3):
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    self.matriz[l][c] = self.tipo # Para testar

                    duplas = 0

                    # Linhas
                    if self.matriz[l].count(self.tipo) == 2 and Tabuleiro.DESCONHECIDO in self.matriz[l]:
                        duplas += 1

                    # Colunas
                    coluna = [self.matriz[i][c] for i in range(3)]
                    if coluna.count(self.tipo) == 2 and Tabuleiro.DESCONHECIDO in coluna:
                        duplas += 1

                    # Diagonais
                    if l == c:
                        diagonal_principal = [self.matriz[i][i] for i in range(3)]
                        if diagonal_principal.count(self.tipo) == 2 and Tabuleiro.DESCONHECIDO in diagonal_principal:
                            duplas += 1

                    if l + c == 2:
                        diagonal_secundaria = [self.matriz[i][2 - i] for i in range(3)]
                        if diagonal_secundaria.count(self.tipo) == 2 and Tabuleiro.DESCONHECIDO in diagonal_secundaria:
                            duplas += 1

                    self.matriz[l][c] = Tabuleiro.DESCONHECIDO # Ajeitar pós teste

                    if duplas >= 2:
                        return l, c
        return None

    ### Rule 3

    def usar_centro(self) -> (int, int):
        if self.matriz[1][1] == Tabuleiro.DESCONHECIDO:
            return 1, 1
        return None

    ### Rule 4

    def marcar_canto_oposto(self, cantos) -> (int, int):
        for c in cantos:
            if self.matriz[c[0]][c[1]] == self.tipo:
                match c:
                    case (0, 0):
                        return (2, 2)
                    case (0, 2):
                        return (2, 0)
                    case (2, 0):
                        return (0, 2)
                    case (2, 2):
                        return (0, 0)
        return None

    ### Rule 5

    def marcar_qualquer_canto(self, cantos) -> (int, int):
        for c in cantos:
            if self.matriz[c[0]][c[1]] == Tabuleiro.DESCONHECIDO:
                return c
        return None
    
    ### Rule 6

    def jogada_aleatoria(self) -> (int, int):
        lista = []
        for l in range(0, 3):
            for c in range(0, 3):
                if self.matriz[l][c] == Tabuleiro.DESCONHECIDO:
                    lista.append((l, c))

        if len(lista) > 0:
            p = randint(0, len(lista) - 1)
            return lista[p]
        else:
            return None