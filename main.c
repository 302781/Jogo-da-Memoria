#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define coberto 0
#define descoberto 1

// Estado da carta
typedef enum {
    Escondida,
    Revelado,
    Removida
} EstadoCarta;

// Carta
typedef struct {
    char simbolo;
    EstadoCarta estado;
    int linha, coluna;
} Carta;

// Lista Encadeada (não usada no jogo, mas incluída por requisito)
typedef struct No {
    Carta carta;
    struct No* prox;
} No;

// Jogador
typedef struct {
    char nome[50];
    int pares_encontrados;
} Jogador;

// Tabuleiro de símbolos (pares)
int jogo1[4][5] = {
    {1,2,3,4,5},
    {6,7,8,9,0},
    {1,2,3,4,5},
    {6,7,8,9,0}
};

// Estado das cartas (coberto ou descoberto)
int estado[4][5] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

// Protótipos
void monta();
int analiza();

int main(void) {
    int l1, c1, l2, c2;
    int op;
    int gameover = 0;

    while (op != 2) {
        printf("\t\tBem-vindo(a) ao Jogo da Memória!!\n\n");
        printf("Escolha uma opção:\n");
        printf("(1) Jogar\n");
        printf("(2) Sair\n");
        printf("Op: ");
        scanf("%d", &op);

        if (op == 1) {
            while (!gameover) {
jgd1:
                system("cls");
                monta();
                printf("Digite a linha e a coluna da primeira carta: ");
                scanf("%d %d", &l1, &c1);
                l1--; c1--;

                if (estado[l1][c1] == descoberto) {
                    printf("Ops... Essa posição já foi descoberta.\n");
                    Sleep(1000);
                    goto jgd1;
                }

                if (l1 < 0 || l1 > 3 || c1 < 0 || c1 > 4) {
                    printf("Valores válidos: linhas de 1 a 4, colunas de 1 a 5.\n");
                    Sleep(1000);
                    goto jgd1;
                }

                estado[l1][c1] = descoberto;

jgd2:
                system("cls");
                monta();
                printf("Digite a linha e a coluna da segunda carta: ");
                scanf("%d %d", &l2, &c2);
                l2--; c2--;

                if (estado[l2][c2] == descoberto) {
                    printf("Ops... Essa posição já foi descoberta.\n");
                    Sleep(1000);
                    goto jgd2;
                }

                if (l2 < 0 || l2 > 3 || c2 < 0 || c2 > 4 || (l1 == l2 && c1 == c2)) {
                    printf("Valores válidos: linhas de 1 a 4, colunas de 1 a 5. E não pode repetir a primeira posição!\n");
                    Sleep(1000);
                    goto jgd2;
                }

                estado[l2][c2] = descoberto;

                system("cls");
                monta();

                if (jogo1[l1][c1] != jogo1[l2][c2]) {
                    printf("Errou!\n");
                    Sleep(1000);
                    estado[l1][c1] = coberto;
                    estado[l2][c2] = coberto;
                } else {
                    printf("Acertou um par!\n");
                    Sleep(1000);
                }

                gameover = analiza();
            }

            printf("Parabéns! Você encontrou todos os pares!\n");
            system("pause");
        }
    }

    return 0;
}

// Mostra o tabuleiro
void monta() {
    int l, c;
    printf("    1  2  3  4  5\n");
    for (l = 0; l < 4; l++) {
        printf("%d |", l + 1);
        for (c = 0; c < 5; c++) {
            if (estado[l][c] == descoberto)
                printf(" %d ", jogo1[l][c]);
            else
                printf(" * ");
        }
        printf("\n");
    }
    printf("\n");
}

// Verifica se todas as cartas foram descobertas
int analiza() {
    int l, c, qt = 0;
    for (l = 0; l < 4; l++) {
        for (c = 0; c < 5; c++) {
            if (estado[l][c] == descoberto)
                qt++;
        }
    }
    return qt == 20;
}
