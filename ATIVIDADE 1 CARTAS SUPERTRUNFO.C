#include <stdio.h>

int main() {
    printf("Desafio Super Trunfo: Comparação das cartas!\n");

    char estado1[20], estado2[20];
    char codestado1[5], codestado2[5];
    char cidestado1[20], cidestado2[20];
    unsigned long int habestado1, habestado2; 
    float areacidade1, areacidade2;
    float PIBestado1, PIBestado2;
    float densidadePopulacional1, densidadePopulacional2;
    float pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;
    float pontosTuristicos1, pontosTuristicos2; 

    // Entrada para o primeiro estado
    printf("Digite o estado 1: \n");
    scanf("%s", estado1);

    printf("Digite o código do estado 1: \n");
    scanf("%s", codestado1);

    printf("Digite a cidade do estado 1: \n");
    scanf("%s", cidestado1);

    printf("Digite a quantidade de habitantes da cidade 1: \n");
    scanf("%lu", &habestado1);  

    printf("Digite a área em km² da cidade 1: \n");
    scanf("%f", &areacidade1);

    printf("Digite o PIB da cidade 1: \n");
    scanf("%f", &PIBestado1);

    printf("Digite o número de pontos turísticos da cidade 1: \n");  
    scanf("%f", &pontosTuristicos1);

    // Entrada para o segundo estado
    printf("Digite o estado 2: \n");
    scanf("%s", estado2);

    printf("Digite o código do estado 2: \n");
    scanf("%s", codestado2);

    printf("Digite a cidade do estado 2: \n");
    scanf("%s", cidestado2);

    printf("Digite a quantidade de habitantes da cidade 2: \n");
    scanf("%lu", &habestado2);  

    printf("Digite a área em km² da cidade 2: \n");
    scanf("%f", &areacidade2);

    printf("Digite o PIB da cidade 2: \n");
    scanf("%f", &PIBestado2);

    printf("Digite o número de pontos turísticos da cidade 2: \n");  
    scanf("%f", &pontosTuristicos2);

    // Verificando se a população não é zero para evitar divisão por zero
    if (habestado1 == 0) {
        pibPerCapita1 = 0;
        printf("Erro: A população da cidade 1 é zero, não é possível calcular o PIB per capita.\n");
    } else {
        pibPerCapita1 = PIBestado1 / habestado1;
    }

    if (habestado2 == 0) {
        pibPerCapita2 = 0;
        printf("Erro: A população da cidade 2 é zero, não é possível calcular o PIB per capita.\n");
    } else {
        pibPerCapita2 = PIBestado2 / habestado2;
    }

    // Calculando a densidade populacional para ambos os estados
    densidadePopulacional1 = habestado1 / areacidade1;
    densidadePopulacional2 = habestado2 / areacidade2;

    // Calculando o Super Poder para cada carta
    superPoder1 = (float)habestado1 + areacidade1 + PIBestado1 + pontosTuristicos1 + pibPerCapita1 + (1 / densidadePopulacional1);
    superPoder2 = (float)habestado2 + areacidade2 + PIBestado2 + pontosTuristicos2 + pibPerCapita2 + (1 / densidadePopulacional2);

    // Comparação das Cartas
    printf("\nComparação das Cartas:\n");

    // Comparar baseando-se no PIB
    printf("PIB: ");
    if (PIBestado1 > PIBestado2) {
        printf("Carta 1 venceu (1)\n");
    } else if (PIBestado1 < PIBestado2) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate (0)\n");
    }

    // Comparar baseando-se na população
    printf("População: ");
    if (habestado1 > habestado2) {
        printf("Carta 1 venceu (1)\n");
    } else if (habestado1 < habestado2) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate (0)\n");
    }

    // Comparar baseando-se na área
    printf("Área: ");
    if (areacidade1 > areacidade2) {
        printf("Carta 1 venceu (1)\n");
    } else if (areacidade1 < areacidade2) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate (0)\n");
    }

    // Comparar baseando-se na densidade populacional (menor densidade vence)
    printf("Densidade populacional: ");
    if (densidadePopulacional1 < densidadePopulacional2) {
        printf("Carta 1 venceu (1)\n");
    } else if (densidadePopulacional1 > densidadePopulacional2) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate (0)\n");
    }

    // Comparar baseando-se no PIB per capita
    printf("PIB per capita: ");
    if (pibPerCapita1 > pibPerCapita2) {
        printf("Carta 1 venceu (1)\n");
    } else if (pibPerCapita1 < pibPerCapita2) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate (0)\n");
    }

    // Comparar baseando-se no Super Poder
    printf("Super Poder: ");
    if (superPoder1 > superPoder2) {
        printf("Carta 1 venceu (1)\n");
    } else if (superPoder1 < superPoder2) {
        printf("Carta 2 venceu (0)\n");
    } else {
        printf("Empate (0)\n");
    }

    return 0;
}
