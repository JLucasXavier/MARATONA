from random import randint
from model import regras_gerais


__all__ =["tabuleiro_cria","colocar_peca","movimento","getTabuleiro","passo","movimento"]

def rolar_dado():
  return randint(1,6)

def novo_jogo():
  global tabuleiro, spawn
  tabuleiro = tabuleiro_cria()
  tabuleiro = atualiza_tab(tabuleiro)


##Cria o tabuleiro como uma lista de matrizes 2D
def tabuleiro_cria():
  tabuleir = []

  #cada lugar do tabuleiro possui uma pos, isso e, um dicionario
  #{'x':0,'y':0,'jogadores':[],'cor':"white",'inicial':False,'barreira':False}

  #norte
  norte = [ [ {'x':0,'y':0,'jogadores':[],'cor':"white",'inicial':False,'barreira':False,'abrigo':False} for i in range(6) ] for j in range(3) ]
  
  #Desenha abrigo
  norte[0][1]['abrigo'] = True
  
  #Desenha casa inicial e cor do caminho final
  norte[2][1]['inicial'] = True
  norte[2][1]['cor'] = 'green'
  norte[1][1]['cor'] = 'green'
  norte[1][2]['cor'] = 'green'
  norte[1][3]['cor'] = 'green'
  norte[1][4]['cor'] = 'green'
  norte[1][5]['cor'] = 'green'
  tabuleir.append(norte) 
  
  #direita
  
  direita = [[{'x':0,'y':0,'jogadores':[],'cor':"white",'inicial':False,'barreira':False,'abrigo':False} for x in range(3)] for y in range(6)]
  #Desenha abrigo
  direita[4][0]['abrigo'] = True
  
  #Desenha casa inicial e cor do caminho final
  direita[4][2]['inicial'] = True
  direita[4][2]['cor'] = 'yellow'
  direita[4][1]['cor'] = 'yellow'
  direita[3][1]['cor'] = 'yellow'
  direita[2][1]['cor'] = 'yellow'
  direita[1][1]['cor'] = 'yellow'
  direita[0][1]['cor'] = 'yellow'
  tabuleir.append(direita)
  
  #sul
  #Desenha casa inicial e cor do caminho final
  sul = [[{'x':0,'y':0,'jogadores':[],'cor':"white",'inicial':False,'barreira':False,'abrigo':False} for x in range(6)] for y in range(3)]
  
  #Desenha abrigo
  sul[2][4]['abrigo'] = True
  
  #Desenha casa inicial e cor do caminho final
  sul[0][4]['inicial'] = True
  sul[0][4]['cor'] = 'blue'
  sul[1][4]['cor'] = 'blue'
  sul[1][3]['cor'] = 'blue'
  sul[1][2]['cor'] = 'blue'
  sul[1][1]['cor'] = 'blue'
  sul[1][0]['cor'] = 'blue'

  tabuleir.append(sul)
  
  #esquerda
  esquerda = [[{'x':0,'y':0,'jogadores':[],'cor':"white",'inicial':False,'barreira':False,'abrigo':False} for x in range(3)] for y in range(6)]
  #Desenha abrigo
  esquerda[1][2]['abrigo'] = True
  
  #Desenha casa inicial e cor do caminho final
  esquerda[1][0]['inicial'] = True
  esquerda[1][0]['cor'] = 'red'
  esquerda[1][1]['cor'] = 'red'
  esquerda[2][1]['cor'] = 'red'
  esquerda[3][1]['cor'] = 'red'
  esquerda[4][1]['cor'] = 'red'
  esquerda[5][1]['cor'] = 'red'
  tabuleir.append(esquerda)

  return tabuleir


tabuleiro = tabuleiro_cria()


##coloca uma peca no jogo
def colocar_peca(jogador):
  global tabuleiro
  
  #saida somente com o numero 6
  dado = regras_gerais.getDado()
  if dado != 6:
    return 0

  
  if jogador == 0:
    tabuleiro[0][0][1]['jogadores'].append([0,0]) #DELETAR
    peca = regras_gerais.sair_spawn(jogador)
    if(peca == -1): return -1
    tabuleiro[0][2][1]['jogadores'].append([0,0])
  
  if jogador == 1:
    peca = regras_gerais.sair_spawn(jogador)
    if(peca == -1): return -1
    tabuleiro[1][4][2]['jogadores'].append(peca)

  if jogador == 2:
    peca = regras_gerais.sair_spawn(jogador)
    if(peca == -1): return -1
    tabuleiro[2][0][4]['jogadores'].append(peca)
  
  if jogador == 3:
    peca = regras_gerais.sair_spawn(jogador)
    if(peca == -1): return -1
    tabuleiro[3][1][0]['jogadores'].append(peca)


##
##COME
#come jogador pos[x,y,tab]
def come(pos,idComido):
  tab = tabuleiro[pos[2]]
  x = pos[0]
  y = pos[1]
  
  k=0
  for i in tab[x][y]['jogadores']:
    if i[0] == idComido:
      tab[x][y]['jogadores'].remove(k)
      k += 1
    else:
      return
  return

##passo normal pos[x,y,tab], 
def passo(pos):
  tab = pos[2]
  
  ## PASSOS 1 setor
  ##
  if tab == 0:
    ##[1]caso esteja na primeira coluna
    if pos[0] == 0:
      ##final da primeira coluna
      if pos[1] == 0:
        pos[0] += 1
      ## outro lugar da primeira coluna
      else:
        pos[1] -= 1
      return pos
    
    ##[2]caso esteja na segunda coluna
    if pos[0] == 1:
      pos[0]+=1
      return pos
    
    ##[3]caso esteja na terceira coluna
    if pos[0] == 2:
      #final da terceira coluna
      if pos[1]==5:
        pos[0] = 0
        pos[1] = 0
        pos[2] = 1
        return pos
        ##outro lugar
      else:
        pos[1] += 1
        return pos

  ##
  ## PASSOS 2 setor
  ##
  if tab == 1:
    ##[1]caso esteja na primeira linha
    if pos[1] == 0:
      ##final da primeira lnha
      if pos[0] == 5:
        pos[1] += 1
      ## outro lugar da primeira linha
      else:
        pos[0] += 1
      return pos
    
    ##[2]caso esteja na segunda linha
    if pos[1] == 1:
      pos[1]+=1
      return pos
    
    ##[3]caso esteja na terceira linha
    if pos[1] == 2:
      #final da terceira linha
      if pos[0]==0:
        pos[0] = 2
        pos[1] = 0
        pos[2] = 2
        return pos
        ##outro lugar
      else:
        pos[0] -= 1
        return pos
  ##
  ## PASSOS 3 setor
  ##
  if tab == 2:
    ##[1]caso esteja na terceira coluna
    if pos[0] == 2:
      ##final da terceira coluna
      if pos[1] == 5:
        pos[0] -= 1
      ## outro lugar da primeira coluna
      else:
        pos[1] += 1
      return pos
    
    ##[2]caso esteja na segunda coluna
    if pos[0] == 1:
      pos[0]-=1
      return pos
    
    ##[3]caso esteja na primeira coluna
    if pos[0] == 0:
      #final da terceira coluna
      if pos[1]==0:
        pos[0] = 5
        pos[1] = 2
        pos[2] = 3
        return pos
        ##outro lugar
      else:
        pos[1] -= 1
        return pos
  ##
  ## PASSOS 4 setor
  ##
  if tab == 3:
    ##[1]caso esteja na terceira linha
    if pos[1] == 2:
      ##final da primeira lnha
      if pos[0] == 0:
        pos[1] -= 1
      ## outro lugar da primeira linha
      else:
        pos[0] -= 1
      return pos
    
    ##[2]caso esteja na segunda linha
    if pos[1] == 1:
      pos[1]-=1
      return pos
    
    ##[3]caso esteja na primeira linha
    if pos[1] == 0:
      #final da primeira linha
      if pos[0]==5:
        pos[0] = 0
        pos[1] = 5
        pos[2] = 0
        return pos
        ##outro lugar
      else:
        pos[0] += 1
        return pos


#Passo especial pos[x,y,tab]
def passo_especial(pos):
  tab = pos[2]
  
  ##
  #setor norte
  ##
  if tab == 0:
    ##possicao ganhadora
    if pos[1] == 5:
      pos[0] = -1
      pos[1] = -1
      pos[2] = -1
    else:
      pos[1] += 1
    return pos

  ##
  #setor esquerda
  ##
  if tab == 1:
    ##possicao ganhadora
    if pos[1] == 2:
      pos[0] = -1
      pos[1] = -1
      pos[2] = -1
    else:
      pos[0] -= 1
    return pos

  ##
  #setor sul
  ##
  if tab == 2:
    ##possicao ganhadora
    if pos[0] == 2:
      pos[0] = -1
      pos[1] = -1
      pos[2] = -1
    else:
      pos[1] -= 1
    return pos

  ##
  #setor direita
  ##
  if tab == 3:
    ##possicao ganhadora
    if pos[0] == 5:
      pos[0] = -1
      pos[1] = -1
      pos[2] = -1
    else:
      pos[0] += 1
    return pos




def movimento_especial(jogador,pos,dado):
  print(pos)
  #caso 1, jogador 0
  if jogador[0] == 0:
    teste = (pos[1] + dado)
    if teste == 6:
      print("WINNNEER")
    return


  #caso 2, jogador 1
  if jogador[0] == 1:
    teste = (pos[0] - dado)
    if teste == -1:
      print("WINNNEER")
    return

  #caso 3, jogador 2
  if jogador[0] == 2:
    teste = (pos[1] - dado)
    if teste == -1:
      print("WINNNEER")
    return

  #caso 4, jogador 3
  if jogador[0] == 3:
    teste = (pos[0] + dado)
    if teste == 6:
      print("WINNNEER")
    return

      

#confere se o passo vai fazer entrar na coluna final
#jogador = [jogador,id_peca]
#pos = [x,y,tabuleiro]
def confere_especial(jogador,pos):
  ## jogador 1
  if jogador[0] ==0:
    if pos[0] == 1 and pos[1] == 0 and pos[2]==0:
      return True
    if pos[0] == 1 and pos[1] > 0 and pos[2]==0:
      return 22

    return False

  
  ## jogador 2
  if jogador[0] ==1:
    if pos[0] == 5 and pos[1] == 1 and pos[2]==1:
      return True
    if pos[0] > 5 and pos[1] == 1 and pos[2]==1:
      return 22
    
    return False 

  ## jogador 3
  if jogador[0] ==2:
    if pos[0] == 1 and pos[1] == 5 and pos[2]==2:
      return True
    if pos[0] == 1 and pos[1] < 5 and pos[2]==2:
      return 22

    return False 

  ## jogador 4
  if jogador[0] ==3:
    if pos[0] == 0 and pos[1] == 1 and pos[2]==3:
      return True
    if pos[0] > 0 and pos[1] == 1 and pos[2]==3:
      return 22

    return False  



##jogador = [jogador,id peca]
## pos = [x,y,setor]
def movimento(jogador,pos):
  pos2 = pos
  dado = regras_gerais.getDado()

  # verifica se esta no caminho final, se estiver nao se move
  if confere_especial(jogador,pos) == 22:
    movimento_especial(jogador,pos,dado)
    tabuleiro = getTabuleiro()
    tabuleiro[pos2[2]][pos2[0]][pos2[1]]['jogadores'].append(jogador)
    return
  
  #caminha
  for i in range(dado):
    if confere_especial(jogador,pos2):
      pos2 = passo_especial(pos2)
    else:
      pos2 = passo(pos2)
      
    
  #chega ao final do caminho
  tabuleiro = getTabuleiro()
  tabuleiro[pos2[2]][pos2[0]][pos2[1]]['jogadores'].append(jogador)

  #atualiza o jogador apos o movimento
  

  
## ca
  
#
#Atualiza o tabuleiro
#
def atualiza_tab(tabuleiro):

  #atualiza setor norte
  yoff = 0
  for y in range(6):
    xoff = 234
    for x in range(3):
      tabuleiro[0][x][y]['x'] = xoff
      tabuleiro[0][x][y]['y'] = yoff
      xoff += 39
    yoff += 39

  

  #atualiza setor direita
  xoff = 351
  for x in range(6):
    yoff = 234 
    for y in range(3):
      tabuleiro[1][x][y]['x'] = xoff
      tabuleiro[1][x][y]['y'] = yoff
      yoff += 39
    xoff += 39

  
  
  #atualiza setor sul
  yoff = 351
  for y in range(6):
    xoff = 234
    for x in range(3):
      tabuleiro[2][x][y]['x'] = xoff
      tabuleiro[2][x][y]['y'] = yoff
      xoff += 39
    yoff += 39


  

  #atualiza setor direita
  xoff = 0
  for x in range(6):
    yoff = 234 
    for y in range(3):
      tabuleiro[3][x][y]['x'] = xoff
      tabuleiro[3][x][y]['y'] = yoff
      yoff += 39
    xoff += 39
  
  return tabuleiro


def getTabuleiro():
  global tabuleiro
  return tabuleiro

