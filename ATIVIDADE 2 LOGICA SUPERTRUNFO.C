#include <stdio.h>
#include <string.h>

struct Cidade {
    char estado[3];
    char codigo[10];
    char nome[100];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

// Função para obter nome do atributo
const char* nomeAtributo(int id) {
    switch (id) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per capita";
        default: return "Desconhecido";
    }
}

// Função para retornar valor numérico do atributo da cidade
float obterValor(struct Cidade c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.num_pontos_turisticos;
        case 5: return c.densidade_populacional;
        case 6: return c.pib_per_capita;
        default: return -1;
    }
}

// Retorna se o maior vence (1) ou o menor vence (0)
int maiorVence(int atributo) {
    return atributo == 5 ? 0 : 1; // Densidade Populacional = menor vence
}

int main() {
    struct Cidade cidade1, cidade2;

    // Cadastro da Carta 1
    printf("Digite o código do estado da cidade 1: ");
    scanf("%s", cidade1.estado);
    printf("Digite o código da carta 1: ");
    scanf("%s", cidade1.codigo);
    printf("Digite o nome da cidade 1: ");
    scanf(" %[^\n]", cidade1.nome);
    printf("Digite a população da cidade 1: ");
    scanf("%d", &cidade1.populacao);
    printf("Digite a área da cidade 1 em km²: ");
    scanf("%f", &cidade1.area);
    printf("Digite o PIB da cidade 1 (em bilhões): ");
    scanf("%f", &cidade1.pib);
    printf("Digite o número de pontos turísticos da cidade 1: ");
    scanf("%d", &cidade1.num_pontos_turisticos);

    // Cadastro da Carta 2
    printf("\nDigite o código do estado da cidade 2: ");
    scanf("%s", cidade2.estado);
    printf("Digite o código da carta 2: ");
    scanf("%s", cidade2.codigo);
    printf("Digite o nome da cidade 2: ");
    scanf(" %[^\n]", cidade2.nome);
    printf("Digite a população da cidade 2: ");
    scanf("%d", &cidade2.populacao);
    printf("Digite a área da cidade 2 em km²: ");
    scanf("%f", &cidade2.area);
    printf("Digite o PIB da cidade 2 (em bilhões): ");
    scanf("%f", &cidade2.pib);
    printf("Digite o número de pontos turísticos da cidade 2: ");
    scanf("%d", &cidade2.num_pontos_turisticos);

    // Calculando atributos derivados
    cidade1.densidade_populacional = cidade1.populacao / cidade1.area;
    cidade1.pib_per_capita = (cidade1.pib * 1e9) / cidade1.populacao;
    cidade2.densidade_populacional = cidade2.populacao / cidade2.area;
    cidade2.pib_per_capita = (cidade2.pib * 1e9) / cidade2.populacao;

    // Menu dinâmico de escolha de dois atributos diferentes
    int atributo1 = 0, atributo2 = 0;

    do {
        printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional (MENOR vence)\n6 - PIB per capita\n");
        printf("Digite sua escolha: ");
        scanf("%d", &atributo1);
    } while (atributo1 < 1 || atributo1 > 6);

    do {
        printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 6; i++) {
            if (i != atributo1)
                printf("%d - %s\n", i, nomeAtributo(i));
        }
        printf("Digite sua escolha: ");
        scanf("%d", &atributo2);
    } while (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1);

    // Obter valores
    float valor1_attr1 = obterValor(cidade1, atributo1);
    float valor2_attr1 = obterValor(cidade2, atributo1);
    float valor1_attr2 = obterValor(cidade1, atributo2);
    float valor2_attr2 = obterValor(cidade2, atributo2);

    // Comparação individual
    int pontos1 = 0, pontos2 = 0;
    pontos1 += (maiorVence(atributo1) ? (valor1_attr1 > valor2_attr1) : (valor1_attr1 < valor2_attr1));
    pontos2 += (maiorVence(atributo1) ? (valor2_attr1 > valor1_attr1) : (valor2_attr1 < valor1_attr1));
    pontos1 += (maiorVence(atributo2) ? (valor1_attr2 > valor2_attr2) : (valor1_attr2 < valor2_attr2));
    pontos2 += (maiorVence(atributo2) ? (valor2_attr2 > valor1_attr2) : (valor2_attr2 < valor1_attr2));

    // Soma total dos atributos
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    // Exibição clara dos dados
    printf("\n--- RESULTADOS DA RODADA ---\n");
    printf("\nCarta 1: %s (%s)\n", cidade1.nome, cidade1.estado);
    printf("%s: %.2f\n", nomeAtributo(atributo1), valor1_attr1);
    printf("%s: %.2f\n", nomeAtributo(atributo2), valor1_attr2);
    printf("Soma dos atributos: %.2f\n", soma1);

    printf("\nCarta 2: %s (%s)\n", cidade2.nome, cidade2.estado);
    printf("%s: %.2f\n", nomeAtributo(atributo1), valor2_attr1);
    printf("%s: %.2f\n", nomeAtributo(atributo2), valor2_attr2);
    printf("Soma dos atributos: %.2f\n", soma2);

    // Decisão final
    printf("\n>>> Resultado final: ");
    (soma1 > soma2) ? printf("%s venceu!\n", cidade1.nome) :
    (soma2 > soma1) ? printf("%s venceu!\n", cidade2.nome) :
                      printf("Empate!\n");

    return 0;
}
