#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TENTATIVAS 6

void jogarForca() {
    char palavra[] = "progamacao";
    int tamanho = strlen(palavra);
    char palavra_descoberta[tamanho];
    int tentativas = 0;
    int acertos = 0;
    char letra;

    // Inicializando a palavra descoberta com underscores
    for (int i = 0; i < tamanho; i++) {
        palavra_descoberta[i] = '_';
    }

    printf("Bem-vindo ao jogo da Forca!\n");

    while (tentativas < MAX_TENTATIVAS && acertos < tamanho) {
        printf("\nPalavra: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%c ", palavra_descoberta[i]);
        }
        printf("\nTentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);

        printf("Digite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra); // Convertendo a letra para minúscula

        int acertou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == letra && palavra_descoberta[i] == '_') {
                palavra_descoberta[i] = letra;
                acertos++;
                acertou = 1;
            }
        }

        if (!acertou) {
            tentativas++;
            printf("A letra nao esta na palavra.\n");
        } else {
            printf("Boa! Voce acertou uma letra.\n");
        }
    }

    if (acertos == tamanho) {
        printf("\nParabens! Voce ganhou! A palavra era: %s\n", palavra);
    } else {
        printf("\nVoce perdeu! A palavra era: %s\n", palavra);
    }
}

int main() {
    jogarForca();
    return 0;
}
