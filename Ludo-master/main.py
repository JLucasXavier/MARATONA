import tkinter
from model import regras_gerais,regras_tabuleiro
from control.callbacks import *
from control import event_handler
from view.draw_canvas import *
#
#MAIN
#
janela = Tk()

janela.title('Janela inicial')
janela.minsize(width=844, height=585)
janela.maxsize(width=844, height=585) #Tamanho da tela imutável

#jogo
regras_tabuleiro.novo_jogo()
regras_gerais.novo_jogo()

#Board canvas
cnv = Canvas(janela,width=844,height=586,bg="white")
desenho_principal(cnv,janela)
cnv.bind('<ButtonRelease-1>', event_handler.click)
cnv.pack()
janela.mainloop()