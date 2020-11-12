from model import regras_tabuleiro,regras_gerais
from view import draw_canvas

#
#Cuida dos eventos
#
def click(event):
    #Caso, pelas regras gerais, esteja no momento de aguardo: qualquer clique e desconsiderado
    if regras_gerais.getWating():
        return

    #Obtem informacoes
    x = event.x
    y = event.y
    tab = 0
    vez = regras_gerais.getVez()


    #Caputura spawns e coloca determinada peca no tabuleiro, caso nao existam mais pecas o comando e ignorado
    if(x>350 and y <234 and vez == 0):
        colocando = regras_tabuleiro.colocar_peca(0)
        if(colocando != -1):
            regras_gerais.proxima_jogada(event.widget)
            return

    if(x>351 and y>351 and vez == 1):
        colocando = regras_tabuleiro.colocar_peca(1)
        if(colocando != -1):
            regras_gerais.proxima_jogada(event.widget)
            return

    if(x<233 and y >351 and vez == 2):
        colocando = regras_tabuleiro.colocar_peca(2)
        if(colocando != -1):
            regras_gerais.proxima_jogada(event.widget)
            return

    if(x<233 and y <234 and vez == 3):
        colocando = regras_tabuleiro.colocar_peca(3)
        if(colocando != -1):
            regras_gerais.proxima_jogada(event.widget)
            return


    #Captura qual setor dos tabuleiros o mouse esta clicando
    if(y<234):
        tab = 0
    elif(x>349):
        tab = 1
    elif(y>351):
        tab = 2
    elif(x<217):
        tab = 3
    
    ##encontra a posicao do clique dado o tabuleiro
    tabuleiro = regras_tabuleiro.getTabuleiro()
    xoff = 0
    for posx in tabuleiro[tab]:
        yoff = 0
        for posy in posx:
            if(x>=posy['x'] and x <= posy['x']+39) and (y>=posy['y'] and y <= posy['y']+39):
                #receve de quem e a vez
                vez = regras_gerais.getVez()

                #Verifica se existe algum jogador no local clicado
                if len(posy['jogadores'])>0:
                    i = 0   
                    #Para cada jogador na posicao seleciona o jogador da vex
                    for jogador in posy['jogadores']:
                        if jogador[0] == vez:
                            #chama funcao de movimento
                            regras_tabuleiro.movimento(jogador,[xoff,yoff,tab])
                            #Remove o jogador da posicao anterior
                            posy['jogadores'].pop(i)
                            #proxima jogada
                            regras_gerais.proxima_jogada(event.widget)
                            return #quebra o loop apos achar oq precisa
                        i +=1
                    
            yoff +=1
        xoff += 1