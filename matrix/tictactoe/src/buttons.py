# -*- coding: utf-8 -*-
import pygame
from src.tabuleiro import Tabuleiro
 
buttons_v = pygame.sprite.Group()

class Button(pygame.sprite.Sprite):
    def __init__(self, screen, position, dim):
        super().__init__()
        self.colors = "black on white"
        self.fg, self.bg = self.colors.split(" on ")
        
        self.x, self.y = position
        self.w , self.h = dim
        self.rect = pygame.Rect(self.x, self.y, self.w, self.h)
        self.screen = screen
        self.jogador = Tabuleiro.DESCONHECIDO
        self.change_text(Tabuleiro.DESCONHECIDO)
        self.update()
        buttons_v.add(self)
 
 
    def change_text(self, jogador):
        if self.jogador != Tabuleiro.DESCONHECIDO:
            return False
        self.jogador = jogador
        self.font = pygame.font.SysFont("Consolas", 150)
        RED = (185, 0, 0)
        BLUE = (0, 0, 185)
        DEFAULT = (0, 0, 0)
        
        if(jogador == Tabuleiro.JOGADOR_X):
            self.text_render = self.font.render("X", 1, BLUE)
        elif(jogador == Tabuleiro.JOGADOR_0):
            self.text_render = self.font.render("O", 1, RED)
        else:
            self.text_render = self.font.render("", 1, DEFAULT)
        
        self.screen.blit(self.text_render, (self.x, self.y))
        return True
        
 
    def update(self):
        self.fg, self.bg = self.colors.split(" on ")
        pygame.draw.rect(self.screen, self.bg, (self.x, self.y, self.w , self.h))
        self.image = self.text_render