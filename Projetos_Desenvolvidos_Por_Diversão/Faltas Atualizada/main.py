import os

def obtendo_alunos():
    nome_arquivo = 'turmaalpha.txt'

    p = open(nome_arquivo, 'r')
    linhas = p.readlines()
    p.close()
    
    c = 0
    for linha in linhas:
        if '\n' in linha:
            linhas[c] = linha.replace("\n", '')
        
        c += 1
            
    
    linhas.sort()
    
    return linhas

# Vamos obter a lista completa dos alunos
alunos_totais = obtendo_alunos()

# vamos guardar quem ja chegou aqui
safos = []

# vamos guardar atletas 
atletas = ['Artur', 'Hilgert', 'Marques', 'Ritto', 'Samara', 'Luisi', 'Cantergiani', 'Neves', 'Gustavo', 'Manetti', 'Thiago Angelo', 
           'Raposo', 'Schowantz', 'Willian', 'Santiago', 'Luana Garcia', 'Vaz', 'Gloria', 'Eric Santos', 'Modesto']

# Agora vamos apresentar ao sanha
def apresentacao():
    
    def cabecalho():
        print(f'\033[7m\033[1m', end='')
        print('*'*10)
        print('Faltas')
        print('*'*10+'\n')
    
    def apresentando_nao_chamados():
        q = 1
        for aluno in alunos_totais:
            # Ha essa verificacao para nao mostrarmos os que estão faltando
            if aluno not in safos:
                print(f'{q}:', end='')
                if aluno in atletas:
                    print(f'\033[33m{aluno}\033[0m\033[7m\033[1m')
                else:
                    print(aluno)
                    
            q += 1
                    
        print(f'\nHá um total de {len(safos)} em forma')
    
    
    def obtendo_safos():
        nome = input('Insira um nome safo: ')
        
        if len(nome) == 0:
            return None
        
        def verificando_se_existe():
            def comparando(nome1, nome2):
                
                i = 0
                while True:
                    try:
                        if nome1[i].upper() != nome2[i].upper():
                            return False
                    except IndexError:
                        # conseguimos, fomos ate o final sem achar erros
                        return True
                    
                    i += 1
                
            for aluno in alunos_totais:
                if aluno not in safos:
                    if comparando(nome, aluno):
                        print(f'Achei {aluno}')
                        return True, aluno
            
            
            return False, None
            
        situacao = verificando_se_existe()
        
        if situacao[0]:
            safos.append(situacao[1])
            
    
    while True:
        cabecalho()
        
        apresentando_nao_chamados()
        
        obtendo_safos()
        
        os.system('clear')
    
    print('\033[0m')
        
    
apresentacao()
