from model import regras_tabuleiro
from model import regras_gerais
from view import draw_canvas
from dados import *


#Realiza uma jogada
def jogada(janela,cnv):
    regras_gerais.watingSwitch()
    dado = regras_gerais.rolar_dado()
    draw_canvas.desenha_dado(janela)