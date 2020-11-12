from tkinter import *
from control import callbacks
from model import regras_gerais,regras_tabuleiro ##getTabuleiro,getVez,getDado
from dados import *



#
#Desenho principal- O tabuleiro, as casas inicias/finais, assim como o aba direita
#
def desenho_principal(cnv,top):
    inicial_direita(top,cnv)
    desenha_tabuleiro(cnv)
    casas_iniciais(cnv)
    casas_finais(cnv)


#
#Desenha "aba"direita
#
def inicial_direita(janela,cnv): #Janela a direita
    c = Canvas(janela,width=255,height=585,bg="grey")
    Button(c, width=23,heigh=2,text="Novo Jogo").place(x=45,y=30)
    Button(c, width=23,heigh=2,text="Carregar Jogo").place(x=45,y=90)
    Button(c, width=23,heigh=2,text="Salvar").place(x=45,y=150)
    Button(c, width=23, heigh=2, text="Jogar Dado",command =  lambda: callbacks.jogada(janela,cnv)).place(x=45, y=450)
    Label(c,font='Arial 20',text='À jogar',background='grey').place(x=55,y=220,width=140,heigh=30)
    c.pack(side='right')


#
#Desenha as casas inicias
#
def casas_iniciais(c):
    #medina markeer
    
    #offset
    xoff = 234 +3*39
    yoff = 234 +3*39
    dist1 = 30
    dist2 = 80
    #vermelho
    c.create_rectangle(0,0,234,234,fill="red")
    c.create_oval(dist1,dist1,dist2,dist2,fill="white")
    c.create_oval(dist1+120,dist1,dist2+120,dist2,fill="white")
    c.create_oval(dist1,dist1+120,dist2,dist2+120,fill="white")
    c.create_oval(dist1+120,dist1+120,dist2+120,dist2+120,fill="white")

    #verde
    c.create_rectangle(0+xoff,0,234+xoff,234,fill="green")
    c.create_oval(dist1+xoff,dist1,dist2+xoff,dist2,fill="white")
    c.create_oval(dist1+xoff+120,dist1,dist2+xoff+120,dist2,fill="white")
    c.create_oval(dist1+xoff,dist1+120,dist2+xoff,dist2+120,fill="white")
    c.create_oval(dist1+120+xoff,dist1+120,dist2+120+xoff,dist2+120,fill="white")

    #azul
    c.create_rectangle(0,0+yoff,234,234+yoff,fill="blue")
    c.create_oval(dist1,dist1+yoff,dist2,dist2+yoff,fill="white")
    c.create_oval(dist1+120,dist1+yoff,dist2+120,dist2+yoff,fill="white")
    c.create_oval(dist1,dist1+120+yoff,dist2,dist2+120+yoff,fill="white")
    c.create_oval(dist1+120,dist1+120+yoff,dist2+120,dist2+120+yoff,fill="white")

    #amarelo
    c.create_rectangle(0+xoff,0+yoff,234+xoff,234+yoff,fill="yellow")
    c.create_oval(dist1+xoff,dist1+yoff,dist2+xoff,dist2+yoff,fill="white")
    c.create_oval(dist1+xoff+120,dist1+yoff,dist2+xoff+120,dist2+yoff,fill="white")
    c.create_oval(dist1+xoff,dist1+yoff+120,dist2+xoff,dist2+yoff+120,fill="white")
    c.create_oval(dist1+120+xoff,dist1+120+yoff,dist2+120+xoff,dist2+120+yoff,fill="white")
    
    #pack
    c.pack()


#
#Desenha o meio
#
def casas_finais(c):
    xoff = 234 +3*39
    yoff = 234 +3*39

    meiox = (234 + xoff)/2
    meioy = (234 + yoff)/2
    verde = [234,234, xoff+0,234,meiox,meioy]
    c.create_polygon(verde,fill='green', width=2)

    vermelho = [234,234,234,yoff+0,meiox,meioy]
    c.create_polygon(vermelho,fill='red', width=2)

    azul = [234,yoff+0,yoff+0,xoff+0,meiox,meioy]
    c.create_polygon(azul,fill='blue', width=2)

    amarelo = [xoff+0,yoff+0,xoff+0,234,meiox,meioy]
    c.create_polygon(amarelo,fill='yellow', width=2)

    c.pack

def desenha_pequenos_triangulos(c):
    vermelho = [45,239, 45,270,70,(239+270)/2]
    c.create_polygon(vermelho,fill='white', width=2)

    verde = [317,45,347,45,(317+347)/2,70]
    c.create_polygon(verde,fill='white', width=2)

    azul = [240,540,270,540,(240+270)/2,515]
    c.create_polygon(azul,fill='white', width=2)

    amarelo = [512,(317+347)/2,540,317,540,347]
    c.create_polygon(amarelo,fill='white', width=2)


#
#Desenha tabuleiro
#
def desenha_tabuleiro(c):
    tabuleiro = regras_tabuleiro.getTabuleiro()
    
    
    #setor norte
    for row in tabuleiro[0]:
        desenha_pequenos_triangulos(c)
        for pos in row:
            #Desenha como abrigo ou casa normal
            if pos['abrigo']:
                c.create_rectangle(pos['x'],pos['y'],pos['x']+39,pos['y']+39,fill="black")
            else:
                c.create_rectangle(pos['x'],pos['y'],pos['x']+39,pos['y']+39,fill=pos['cor'])
            
            jg = 0
            if len(pos['jogadores']) > 0:
                jg_ultimo = pos['jogadores'][0][0]
            for jogadores in pos['jogadores']:
                jg += 1
                if(jg >= 2 and jogadores[0] == jg_ultimo ):
                    desenha_multiplos_jogadores(jogadores,pos['x'],pos['y'],c)
                elif jogadores[0] != jg_ultimo:
                    desenha_jogadorDiferentes(jogadores,jg_ultimo,pos['x'],pos['y'],c)
                else:
                    desenha_jogador(jogadores,pos['x'],pos['y'],c)
                jg_ultimo = jogadores[0]
    ###
    #setor direito
    for row in tabuleiro[1]:
        for pos in row:
            if pos['abrigo']:
                c.create_rectangle(pos['x'],pos['y'],pos['x']+39,pos['y']+39,fill="black")
            else:
                c.create_rectangle(pos['x'],pos['y'],pos['x']+39,pos['y']+39,fill=pos['cor'])
            
            jg = 0
            if len(pos['jogadores']) > 0:
                jg_ultimo = pos['jogadores'][0][0]
            for jogadores in pos['jogadores']:
                jg += 1
                if(jg >= 2 and jogadores[0] == jg_ultimo ):
                    desenha_multiplos_jogadores(jogadores,pos['x'],pos['y'],c)
                elif jogadores[0] != jg_ultimo:
                    desenha_jogadorDiferentes(jogadores,jg_ultimo,pos['x'],pos['y'],c)
                else:
                    desenha_jogador(jogadores,pos['x'],pos['y'],c)
                jg_ultimo = jogadores[0]
    ###
    #setor sul
    for row in tabuleiro[2]:
        for pos in row:
            #Desenha o abrigo/casa
            if pos['abrigo']:
                c.create_rectangle(pos['x'],pos['y'],pos['x']+39,pos['y']+39,fill="black")
            else:
                c.create_rectangle(pos['x'],pos['y'],pos['x']+39,pos['y']+39,fill=pos['cor'])
            
            jg = 0
            if len(pos['jogadores']) > 0:
                jg_ultimo = pos['jogadores'][0][0]
            for jogadores in pos['jogadores']:
                jg += 1
                if(jg >= 2 and jogadores[0] == jg_ultimo ):
                    desenha_multiplos_jogadores(jogadores,pos['x'],pos['y'],c)
                elif jogadores[0] != jg_ultimo:
                    desenha_jogadorDiferentes(jogadores,jg_ultimo,pos['x'],pos['y'],c)
                else:
                    desenha_jogador(jogadores,pos['x'],pos['y'],c)
                jg_ultimo = jogadores[0]
    ###
    #setor esquerda
    for row in tabuleiro[3]:
        for pos in row:
            #Desenha o abrigo ou a casa principal
            if pos['abrigo']:
                c.create_rectangle(pos['x'],pos['y'],pos['x']+39,pos['y']+39,fill="black")
            else:
                c.create_rectangle(pos['x'],pos['y'],pos['x']+39,pos['y']+39,fill=pos['cor'])

            jg = 0
            if len(pos['jogadores']) > 0:
                jg_ultimo = pos['jogadores'][0][0]
            for jogadores in pos['jogadores']:
                jg += 1
                if(jg >= 2 and jogadores[0] == jg_ultimo ):
                    desenha_multiplos_jogadores(jogadores,pos['x'],pos['y'],c)
                elif jogadores[0] != jg_ultimo:
                    desenha_jogadorDiferentes(jogadores,jg_ultimo,pos['x'],pos['y'],c)
                else:
                    desenha_jogador(jogadores,pos['x'],pos['y'],c)
                jg_ultimo = jogadores[0]

    desenha_pequenos_triangulos(c)

    ###

#
#Desenha jogador
#
def desenha_jogador(jogador,x,y,c):
    if(jogador[0] == 0):
        create_circle(x+39/2,y+39/2,39/3,c,'green')
    if(jogador[0] == 1):
        create_circle(x+39/2,y+39/2,39/3,c,'yellow')
    if(jogador[0] == 2):
        create_circle(x+39/2,y+39/2,39/3,c,'blue')
    if(jogador[0] == 3):
        create_circle(x+39/2,y+39/2,39/3,c,'red')

## desenhas multiplos jogadores iguais
def desenha_multiplos_jogadores(jogador,x,y,c):
    if(jogador[0] == 0):
        create_circleLine(x+39/2,y+39/2,39/4+5,c,'white',"green")
        create_circle(x+39/2,y+39/2,39/4,c,'green')
    if(jogador[0] == 1):    
        create_circleLine(x+39/2,y+39/2,39/4+5,c,'white',"yellow")
        create_circle(x+39/2,y+39/2,39/4,c,'yellow')
    if(jogador[0] == 2):
        create_circleLine(x+39/2,y+39/2,39/4+5,c,'white',"blue")
        create_circle(x+39/2,y+39/2,39/4,c,'blue')
    if(jogador[0] == 3):
        create_circleLine(x+39/2,y+39/2,39/4+5,c,'white',"red")
        create_circle(x+39/2,y+39/2,39/4,c,'red')

## desenha multiplos jogadores diferentes
def desenha_jogadorDiferentes(jogador1,jogador2ID,x,y,c):
    if(jogador1[0] == 0):color1 = "green"
    if(jogador1[0] == 1):color1 = "yellow"    
    if(jogador1[0] == 2):color1 = "blue"
    if(jogador1[0] == 3):color1 = "red"

    if(jogador2ID == 0):color2 = "green"
    if(jogador2ID== 1):color2 = "yellow"    
    if(jogador2ID == 2):color2 = "blue"
    if(jogador2ID == 3):color2 = "red"

    create_circleLine(x+39/2,y+39/2,39/4+5,c,'white',color2)
    create_circle(x+39/2,y+39/2,39/4,c,color1)


#
#Desenha o dado
#
def desenha_dado(c):
    dado = regras_gerais.getDado()
    dadoo = dado
    
    #----------borda do dado----------------
    vez = regras_gerais.getVez()
    if(vez == 0): color = "green"
    if(vez == 1): color = "yellow"
    if(vez == 2): color = "blue"
    if(vez == 3): color = "red"


    #-----------dado---------------------
    if dadoo == 1:
        img = PhotoImage(file="dados/dado_1.png")
    if dadoo == 2:
        img = PhotoImage(file="dados/dado_2.png")
    if dadoo == 3:
        img = PhotoImage(file="dados/dado_3.png")
    if dadoo == 4:
        img = PhotoImage(file="dados/dado_4.png")
    if dadoo == 5:
        img = PhotoImage(file="dados/dado_5.png")
    if dadoo == 6:
        img = PhotoImage(file="dados/dado_6.png")
    
    w = Label(c, image=img,background = color, borderwidth = 2, relief = SUNKEN)
    w.place(x=690,y=300)
    w.imagem = img

#   
#Desenha formas geometricas - funcoes auxiliares
#
#desenha circulo
def create_circle(x, y, r, c,color): 
    x0 = x - r
    y0 = y - r
    x1 = x + r
    y1 = y + r
    return c.create_oval(x0, y0, x1, y1,fill=color)


#desenha circulo com linha
def create_circleLine(x, y, r, c,color,lineColor): #center coordinates, radius
    x0 = x - r
    y0 = y - r
    x1 = x + r
    y1 = y + r
    return c.create_oval(x0, y0, x1, y1,fill=color,outline=lineColor,width = 5)

