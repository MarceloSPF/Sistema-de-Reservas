#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char reserva[10][6] = {
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '}
    };

    char continuar;
    int fileira = -1, assento = -1;
    char poltrona = ' ';
    char tipo_passagem;

    do {
        // Limpa o console
        #ifdef _WIN32
            system("cls");  // Para Windows
        #else
            system("clear");  // Para Linux e macOS
        #endif

        do {
            printf("\nEscolha o tipo de passagem (E - Econômica, X - Executiva): ");
            scanf(" %c", &tipo_passagem);
            if (tipo_passagem != 'E' && tipo_passagem != 'X')
                printf("\nTipo de passagem inválido. Tente novamente.\n");
        } while (tipo_passagem != 'E' && tipo_passagem != 'X'); //Verifica se usuario digitou um tipo valido de passagem

        while (true) {
            printf("\nDigite a fileira (1-10): ");
            scanf("%d", &fileira);
            printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
            scanf(" %c", &poltrona);

            if (fileira < 1 || fileira > 10 || (poltrona < 'A' || poltrona > 'F')) {
                printf("\nFileira ou poltrona inválida. Tente novamente.\n");
                continue;
            }

            switch (poltrona) { //Caso o usuario digite minusculo ou maiusculo o case sera aplicado da mesma forma
                case 'A':
                case 'a':
                    assento = 0;
                    break;
                case 'B':
                case 'b':
                    assento = 1;
                    break;
                case 'C':
                case 'c':
                    assento = 2;
                    break;
                case 'D':
                case 'd':
                    assento = 3;
                    break;
                case 'E':
                case 'e':
                    assento = 4;
                    break;
                case 'F':
                case 'f':
                    assento = 5;
                    break;
                default:
                    printf("\nPoltrona inválida\n");
                    continue;
            }

            if (reserva[fileira - 1][assento] == 'x') {
                printf("\nEsse assento já está reservado. Por favor, escolha outro.\n");
                continue;
            }

            if (tipo_passagem == 'E' && (assento == 0 || assento == 5)) {
                printf("\nPara passagem Econômica, as poltronas A e F não estão disponíveis.\n");
                continue;
            }

            // Reserva o assento
            reserva[fileira - 1][assento] = 'x';
            break;
        }

        // Exibe o mapa de assentos
        printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
        for (int x = 0; x < 10; x++) {
            printf("\n\t%02d\t", x + 1);
            for (int y = 0; y < 6; y++) {
                if (reserva[x][y] == 'x') {
                    printf("[🔴] "); // Assento ocupado
                } else {
                    printf("[🟢] "); // Assento livre
                }
                if (y == 2) {
                    printf("\t");
                }
            }
        }
        printf("\n");

        // Pergunta se deseja continuar
        printf("\nDeseja realizar outra reserva? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("\nEncerrando o sistema de reservas...\n");
    return 0;
}
