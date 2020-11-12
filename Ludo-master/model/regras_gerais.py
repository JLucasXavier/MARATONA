import random
from view import draw_canvas

__all__ = ['rolar_dado','check_ganhador','getSpawn','novo_jogo','sair_spawn','getVez',"vezAdd","rolar_dado","getDado"]


#
#Inicializa o jogo com as variaveis globais de regras_gerais
#
def novo_jogo():
  global spawn
  global vez
  global dado
  global wating
  global winnners
  winners = [[],[],[],[]]
  wating = True
  dado = random.randint(1,6)
  vez = 0
  jogador = [[],[],[],[]]

  ##pecas jogador 1 [jogadorID,Npeca]
  jogador[0].append([0,0])
  jogador[0].append([0,1])
  jogador[0].append([0,2])
  jogador[0].append([0,3])

  ##pecas jogador 2
  jogador[1].append([1,0])
  jogador[1].append([1,1])
  jogador[1].append([1,2])
  jogador[1].append([1,3])

  ##pecas jogador 3
  jogador[2].append([2,0])
  jogador[2].append([2,1])
  jogador[2].append([2,2])
  jogador[2].append([2,3])

  ##pecas jogador 4
  jogador[3].append([3,0])
  jogador[3].append([3,1])
  jogador[3].append([3,2])
  jogador[3].append([3,3])
  
  spawn = jogador


#
#Funcoes do spawn - local onde as pecas ficam ate serem nascidas
#
def getSpawn():
  global spawn
  return spawn

def sair_spawn(jogador):
  global spawn
  if (len(spawn[jogador]) < 1):
    return -1
  peca = spawn[jogador].pop()
  return peca
 

#
#Funcoes de vez - define de quem e a vez de jogar assim como faz a passagem de vez
#
def getVez():
  global vez
  return vez

def vezAdd():
    global vez
    if(vez ==3):
      vez = 0
    else:
      vez +=1


#
#Funcoes de dado- rola obtem o valor da variavel global dado
#
def rolar_dado():
  global dado
  dado = random.randint(1,6)
  return dado


def getDado():
  global dado
  return dado


#
#Confere a existencia de ganhadores
#
def check_ganhador(jogadores):
  for jogador in jogadores:
    win =0
    for peca in jogador:
      if peca[1] == -1:
        win += 1
    if(win == 4):
      return jogador
  return -1
  

#
#Funcoes de espera, isso e, o tempo em que o jogador fica aguardando ser a sua jogada
#
def getWating():
  global wating
  return wating

def watingSwitch():
  global wating
  if wating: wating = False
  if not wating: waiting = True


#
#Finaliza uma jogada
#
def proxima_jogada(canvas):
  global vez,wating
  wating = True
  vezAdd()

  draw_canvas.desenha_dado(canvas.master)
  draw_canvas.desenha_tabuleiro(canvas)
  
