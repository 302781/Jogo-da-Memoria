# Jogo-da-Memoria

Como jogar: 
1.O tabuleiro tem cartas viradas para baixo (escondidas).
2.Em cada rodada, o jogador escolhe duas posições (linha e coluna) para virar as cartas.
3.As cartas são reveladas temporariamente:
  .Se forem iguais, formam um par, e permanecem viradas (descobertas).
  .Se forem diferentes, são cobertas novamente após alguns segundos.
4.O processo se repete até que todos os pares sejam encontrados.

Condições para acertar um par:
1.As duas cartas viradas devem ter o mesmo número ou símbolo.
2.O jogador não pode escolher a mesma posição duas vezes na rodada.

Erros comuns (bloqueados pelo código):
1.Escolher posições fora do tabuleiro (valores inválidos).
2.Escolher uma carta que já foi descoberta.
3.Escolher duas vezes a mesma carta.

Fim do jogo:
O jogo termina quando todas as cartas do tabuleiro forem descobertas (ou seja, todos os 10 pares forem encontrados em um tabuleiro 4x5).

Instruções de Compilação e Execução
Para Windows (com GCC instalado)
Pré-requisitos:
Ter o GCC instalado. Se não tiver, instale o MinGW.
Salve seu código com o nome memoria.c.

Compilando o programa:
1.Abra o Prompt de Comando (cmd).
2.Navegue até a pasta onde está o arquivo memoria.c.
C:\Users\SeuNome\Documentos\JogoMemoria
3.Compile com:
gcc memoria.c -o memoria.exe
Se você estiver usando windows.h e Sleep(), não precisa adicionar nenhuma biblioteca extra.
4.Executando o jogo:
main

Organização do Código

O projeto está estruturado em um único arquivo fonte (memoria.c) para facilitar a compreensão e atender aos requisitos da disciplina, com uso de struct, enum, listas encadeadas (conceito incluído) e gravação em arquivo.

Arquivo principal: main.c
Esse arquivo contém toda a lógica do jogo da memória, incluindo:

 Principais Tipos e Estruturas
'enum EstadoCarta':
Define os três estados possíveis de uma carta:
1.Escondida
2.Revelado
3.Removida

struct Carta:
Representa uma carta no jogo, com:
1.'simbolo' (valor da carta, por exemplo, 1 a 9)
2.'estado' (usando o enum acima)
3.'linha' e 'coluna' (posição no tabuleiro)

struct Jogador:
Representa o jogador, com:
1.'nome'
2.'pares_encontrados'

struct No:
Estrutura de lista encadeada representando um conceito avançado de manipulação dinâmica (não usada diretamente no fluxo, mas incluída conforme requisito da atividade).

Principais Variáveis Globais
1.int jogo1[4][5]:
Matriz com os símbolos/valores das cartas (com pares repetidos).
2.int estado[4][5]:
Matriz para controlar o estado de cada posição (coberta ou descoberta).

Funções
1.'int main()'
Função principal que exibe o menu inicial, controla o fluxo do jogo e chama as demais funções.
2.'void monta()'
.Exibe o tabuleiro atual no terminal.
.Mostra o número da carta se estiver descoberta ou * se estiver escondida.
3.'int analiza()'
.Verifica se todas as cartas do jogo já foram descobertas.
.Retorna 1 (verdadeiro) se o jogo terminou, ou 0 caso contrário.

Fluxo do jogo:
1.O usuário seleciona a opção "Jogar".
2.Escolhe duas posições (linha/coluna) para revelar cartas.
3.Se os símbolos forem iguais, o par permanece visível.
4.Se forem diferentes, são ocultados novamente após um pequeno atraso (Sleep()).
5.O jogo continua até todos os pares serem encontrados.
6.Uma mensagem de parabéns é exibida.

Arquivo adicional: placar.txt
O arquivo implementar gravação de pontuação, o jogo pode registrar o nome do jogador e número de pares encontrados em placar.txt.

