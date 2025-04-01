#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_CARTAS 40
#define CARTAS_MAO 3

typedef struct
{
    int numero;
    char naipe[10];
} Carta;

typedef struct
{
    Carta cartas[CARTAS_MAO];
    int pontos;
    int vitorias;
    char nome[50];
} Jogador;

typedef struct
{
    int indiceMonte;
    int numeroRodada;
    int valorRodada;
    int nivelTruco;
} Rodada;

Carta monte[TOTAL_CARTAS];
Rodada rodadaAtual = {0, 1, 1, 0};
Jogador *ultimoQuePediuTruco = NULL;

const int sequenciaTruco[] = {1, 3, 6, 9};
const int valoresValidos[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12};
const char naipesValidos[4][10] = {"Espadas", "Copas", "Ouros", "Paus"};

void montarBaralho();
void embaralhar();
void distribuir(Jogador *a, Jogador *b);
Carta escolherCarta(Jogador *j);
int obterHierarquia(Carta c);
int decidirRodada(Carta c1, Carta c2);
int turno(Jogador *j1, Jogador *j2, int numeroMao, Carta *ultimaCartaJ2);
int rodada(Jogador *j1, Jogador *j2);
void pedirTruco(Jogador *quemPede, Jogador *quemResponde);

int main()
{
    printf("\n------------ JOGAR TRUCO ------------ \n\n");
    srand(time(NULL));

    Jogador j1 = {.pontos = 0}, j2 = {.pontos = 0};
    strcpy(j1.nome, "Jogador 1");
    strcpy(j2.nome, "Jogador 2");

    montarBaralho();
    embaralhar();
    distribuir(&j1, &j2);

    while (j1.pontos < 12 && j2.pontos < 12)
    {
        printf("\nPontos: %s [%d] x [%d] %s | Valor da rodada: %d pontos\n",
               j1.nome, j1.pontos, j2.pontos, j2.nome, rodadaAtual.valorRodada);

        int vencedor = rodada(&j1, &j2);
        if (vencedor == 1)
        {
            j1.pontos += rodadaAtual.valorRodada;
            printf("%s venceu a rodada!\n", j1.nome);
        }
        else if (vencedor == 2)
        {
            j2.pontos += rodadaAtual.valorRodada;
            printf("%s venceu a rodada!\n", j2.nome);
        }
        else
        {
            printf("Rodada encerrada por desistencia.\n");
        }

        rodadaAtual.valorRodada = 1;
        rodadaAtual.nivelTruco = 0;
        rodadaAtual.numeroRodada++;
        ultimoQuePediuTruco = NULL;
        embaralhar();
        distribuir(&j1, &j2);
    }

    printf("\n------------ JOGO ACABOU ------------\n");
    if (j1.pontos >= 12)
    {
        printf("%s venceu com %d pontos!\n", j1.nome, j1.pontos);
    }
    else
    {
        printf("%s venceu com %d pontos!\n", j2.nome, j2.pontos);
    }
    return 0;
}

void montarBaralho()
{
    int idx = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            monte[idx].numero = valoresValidos[j];
            strcpy(monte[idx].naipe, naipesValidos[i]);
            idx++;
        }
    }
}

void embaralhar()
{
    for (int i = 0; i < TOTAL_CARTAS; i++)
    {
        int r = rand() % TOTAL_CARTAS;
        Carta temp = monte[i];
        monte[i] = monte[r];
        monte[r] = temp;
    }
    rodadaAtual.indiceMonte = 0;
}

void distribuir(Jogador *a, Jogador *b)
{
    for (int i = 0; i < CARTAS_MAO; i++)
    {
        a->cartas[i] = monte[rodadaAtual.indiceMonte++];
        b->cartas[i] = monte[rodadaAtual.indiceMonte++];
    }
}

Carta escolherCarta(Jogador *j)
{
    int escolha;
    while (1)
    {
        printf("\nCartas de %s:\n", j->nome);
        for (int i = 0; i < CARTAS_MAO; i++)
        {
            if (j->cartas[i].numero > 0)
            {
                printf("%d - %d de %s\n", i + 1, j->cartas[i].numero, j->cartas[i].naipe);
            }
        }
        printf("Escolha a carta (1-%d): ", CARTAS_MAO);
        scanf("%d", &escolha);
        if (escolha >= 1 && escolha <= CARTAS_MAO && j->cartas[escolha - 1].numero > 0)
        {
            Carta selecionada = j->cartas[escolha - 1];
            j->cartas[escolha - 1].numero = 0;
            return selecionada;
        }
        printf("Carta inválida. Tente novamente.\n");
    }
}

int obterHierarquia(Carta c)
{
    if (c.numero == 4 && c.naipe[0] == 'P')
    {
        return 13;
    }
    if (c.numero == 7 && c.naipe[0] == 'C')
    {
        return 12;
    }
    if (c.numero == 1 && c.naipe[0] == 'E')
    {
        return 11;
    }
    if (c.numero == 1 && c.naipe[0] == 'P')
    {
        return 10;
    }
    if (c.numero == 7)
    {
        return 9;
    }
    if (c.numero == 6)
    {
        return 8;
    }
    if (c.numero == 5)
    {
        return 7;
    }
    if (c.numero == 4)
    {
        return 6;
    }
    if (c.numero == 3)
    {
        return 5;
    }
    if (c.numero == 2)
    {
        return 4;
    }
    if (c.numero == 12)
    {
        return 3;
    }
    if (c.numero == 11)
    {
        return 2;
    }
    if (c.numero == 10)
    {
        return 1;
    }
    return 0;
}

int decidirRodada(Carta c1, Carta c2)
{
    int h1 = obterHierarquia(c1);
    int h2 = obterHierarquia(c2);

    if (h1 > h2)
    {
        return 1;
    }

    if (h2 > h1)
    {
        return 2;
    }

    return 0;
}

void pedirTruco(Jogador *quemPede, Jogador *quemResponde)
{
    if (rodadaAtual.nivelTruco >= 3)
    {
        printf("Não é possível aumentar mais o valor da rodada!\n");
        return;
    }

    if (ultimoQuePediuTruco == quemPede)
    {
        printf("Você já foi o último a pedir aumento nesta rodada.\n");
        return;
    }

    int proximoValor = sequenciaTruco[rodadaAtual.nivelTruco + 1];
    printf("%s pediu TRUCO para aumentar a rodada para %d pontos!\n", quemPede->nome, proximoValor);

    int resposta = 0;
    do
    {
        printf("\n%s, deseja aceitar o truco?\n", quemResponde->nome);
        printf("1 - Aceitar\n2 - Recusar\nEscolha: ");
        scanf("%d", &resposta);

        if (resposta == 1)
        {
            rodadaAtual.nivelTruco++;
            rodadaAtual.valorRodada = sequenciaTruco[rodadaAtual.nivelTruco];
            ultimoQuePediuTruco = quemPede;
            printf("Truco aceito! Rodada agora vale %d pontos!\n", rodadaAtual.valorRodada);
        }
        else if (resposta == 2)
        {
            printf("%s recusou o truco! %s ganha %d pontos.\n", quemResponde->nome, quemPede->nome, rodadaAtual.valorRodada);
            quemPede->pontos += rodadaAtual.valorRodada;

            rodadaAtual.valorRodada = 1;
            rodadaAtual.nivelTruco = 0;
            ultimoQuePediuTruco = NULL;

            rodadaAtual.indiceMonte = TOTAL_CARTAS;
        }
        else
        {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (resposta != 1 && resposta != 2);
}

int turno(Jogador *j1, Jogador *j2, int numeroMao, Carta *ultimaCartaJ2)
{
    printf("\n------------ RODADA %d | MÃO %d ------------\n", rodadaAtual.numeroRodada, numeroMao);

    int jogouCarta1 = 0, jogouCarta2 = 0;
    int aceitouTruco1 = (rodadaAtual.nivelTruco >= 0);
    int aceitouTruco2 = (rodadaAtual.nivelTruco >= 0);
    int fezAcao1 = 0, fezAcao2 = 0;
    int finalizou1 = 0, finalizou2 = 0;
    Carta cartaJ1 = {0};
    Carta cartaJ2 = {0};

    while (!finalizou1)
    {
        printf("\nCartas de %s:\n", j1->nome);
        for (int i = 0; i < CARTAS_MAO; i++)
        {
            if (j1->cartas[i].numero > 0)
                printf("%d - %d de %s\n", i + 1, j1->cartas[i].numero, j1->cartas[i].naipe);
        }

        printf("\nAções disponíveis:\n");

        int podeAumentar = (rodadaAtual.nivelTruco < 3 && ultimoQuePediuTruco != j1);
        int podeAceitar = (rodadaAtual.valorRodada > 1 && !aceitouTruco1 && ultimoQuePediuTruco == j2);
        int podeDesistir = (rodadaAtual.valorRodada > 1 && ultimoQuePediuTruco == j2 && !fezAcao1);
        int podeJogarCarta = (aceitouTruco1 && !jogouCarta1);
        int podeTerminar = (fezAcao1);

        if (podeAumentar)
            printf("1 - Aumentar (Truco)\n");
        if (podeAceitar)
            printf("2 - Aceitar Truco\n");
        if (podeDesistir)
            printf("3 - Desistir\n");
        if (podeJogarCarta)
            printf("4 - Jogar Carta\n");
        if (podeTerminar)
            printf("5 - Terminar Turno\n");

        printf("Escolha uma ação: ");
        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (podeAumentar)
            {
                pedirTruco(j1, j2);
                fezAcao1 = 1;
            }
            else
            {
                printf("Você não pode aumentar agora.\n");
            }
            break;
        case 2:
            if (podeAceitar)
            {
                aceitouTruco1 = 1;
                printf("%s aceitou o aumento!\n", j1->nome);
                fezAcao1 = 1;
            }
            else
            {
                printf("Não há aumento para aceitar.\n");
            }
            break;
        case 3:
            if (podeDesistir)
            {
                printf("%s desistiu. %s ganha %d pontos!\n", j1->nome, j2->nome, rodadaAtual.valorRodada);
                j2->pontos += rodadaAtual.valorRodada;
                return -1;
            }
            else
            {
                printf("Você não pode desistir agora.\n");
            }
            break;
        case 4:
            if (podeJogarCarta)
            {
                cartaJ1 = escolherCarta(j1);
                jogouCarta1 = 1;
                fezAcao1 = 1;
            }
            else
            {
                printf("Você não pode jogar carta agora.\n");
            }
            break;
        case 5:
            if (podeTerminar)
            {
                finalizou1 = 1;
            }
            else
            {
                printf("Você precisa executar uma ação antes de terminar o turno.\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
        }
    }

    while (!finalizou2)
    {
        printf("\nCartas de %s:\n", j2->nome);
        for (int i = 0; i < CARTAS_MAO; i++)
        {
            if (j2->cartas[i].numero > 0)
                printf("%d - %d de %s\n", i + 1, j2->cartas[i].numero, j2->cartas[i].naipe);
        }

        printf("\nAções disponíveis:\n");

        int podeAumentar = (rodadaAtual.nivelTruco < 3 && ultimoQuePediuTruco != j2);
        int podeAceitar = (rodadaAtual.valorRodada > 1 && !aceitouTruco2 && ultimoQuePediuTruco == j1);
        int podeDesistir = (rodadaAtual.valorRodada > 1 && ultimoQuePediuTruco == j1 && !fezAcao2);
        int podeJogarCarta = (aceitouTruco2 && !jogouCarta2);
        int podeTerminar = (fezAcao2);

        if (podeAumentar)
            printf("1 - Aumentar (Truco)\n");
        if (podeAceitar)
            printf("2 - Aceitar Truco\n");
        if (podeDesistir)
            printf("3 - Desistir\n");
        if (podeJogarCarta)
            printf("4 - Jogar Carta\n");
        if (podeTerminar)
            printf("5 - Terminar Turno\n");

        printf("Escolha uma ação: ");
        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (podeAumentar)
            {
                pedirTruco(j2, j1);
                fezAcao2 = 1;
            }
            else
            {
                printf("Você não pode aumentar agora.\n");
            }
            break;
        case 2:
            if (podeAceitar)
            {
                aceitouTruco2 = 1;
                printf("%s aceitou o aumento!\n", j2->nome);
                fezAcao2 = 1;
            }
            else
            {
                printf("Não há aumento para aceitar.\n");
            }
            break;
        case 3:
            if (podeDesistir)
            {
                printf("%s desistiu. %s ganha %d pontos!\n", j2->nome, j1->nome, rodadaAtual.valorRodada);
                j1->pontos += rodadaAtual.valorRodada;
                return -1;
            }
            else
            {
                printf("Você não pode desistir agora.\n");
            }
            break;
        case 4:
            if (podeJogarCarta)
            {
                cartaJ2 = escolherCarta(j2);
                jogouCarta2 = 1;
                fezAcao2 = 1;
            }
            else
            {
                printf("Você não pode jogar carta agora.\n");
            }
            break;
        case 5:
            if (podeTerminar)
            {
                finalizou2 = 1;
            }
            else
            {
                printf("Você precisa executar uma ação antes de terminar o turno.\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
        }
    }

    printf("%s jogou %d de %s\n", j1->nome, cartaJ1.numero, cartaJ1.naipe);
    printf("%s jogou %d de %s\n", j2->nome, cartaJ2.numero, cartaJ2.naipe);
    *ultimaCartaJ2 = cartaJ2;

    return decidirRodada(cartaJ1, cartaJ2);
}

int rodada(Jogador *j1, Jogador *j2)
{
    int vencedorMao[3] = {0};
    Carta ultimaCarta = {0};

    for (int i = 0; i < 3; i++)
    {
        int resultado;
        if (i % 2 == 0)
        {
            resultado = turno(j1, j2, i + 1, &ultimaCarta);
        }
        else
        {
            resultado = turno(j2, j1, i + 1, &ultimaCarta);
        }

        if (resultado == -1)
        {
            return -1;
        }

        vencedorMao[i] = resultado;

        if (i == 1)
        {
            if (vencedorMao[0] == vencedorMao[1] && vencedorMao[0] != 0)
            {
                return vencedorMao[0];
            }
            if (vencedorMao[0] == 0 && vencedorMao[1] == 0)
            {
                return 0;
            }
            if (vencedorMao[0] == 0 && vencedorMao[1] != 0)
            {
                return vencedorMao[1];
            }
        }
        if (i == 2)
        {
            if (vencedorMao[2] != 0)
            {
                return vencedorMao[2];
            }
            return vencedorMao[0];
        }
    }
    return 0;
}
