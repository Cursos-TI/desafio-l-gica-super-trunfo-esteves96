#include <stdio.h>

// Estrutura para armazenar as informações de uma cidade
typedef struct {
    char estado[3];
    int codigo;
    char nome[50];
    int populacao;
    double pib;
    double area;
    int pontos_turisticos;
    double densidade_populacional;
    double pib_per_capita;
} Cidade;

// Função para calcular a densidade populacional
double calcular_densidade(int populacao, double area) {
    return (area > 0) ? (populacao / area) : 0;
}

// Função para calcular o PIB per capita
double calcular_pib_per_capita(double pib, int populacao) {
    return (populacao > 0) ? (pib / populacao) : 0;
}

// Função para registrar uma cidade
void registrar_cidade(Cidade *cidade) {
    printf("\nInforme o estado (sigla de 2 letras): ");
    scanf("%2s", cidade->estado);
    
    printf("Informe o código da cidade: ");
    scanf("%d", &cidade->codigo);
    
    printf("Informe o nome da cidade: ");
    scanf(" %[^"]s", cidade->nome);
    
    printf("Informe a população da cidade: ");
    scanf("%d", &cidade->populacao);
    
    printf("Informe o PIB da cidade (em milhões): ");
    scanf("%lf", &cidade->pib);
    
    printf("Informe a área da cidade (em km²): ");
    scanf("%lf", &cidade->area);
    
    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);
    
    cidade->densidade_populacional = calcular_densidade(cidade->populacao, cidade->area);
    cidade->pib_per_capita = calcular_pib_per_capita(cidade->pib, cidade->populacao);
}

// Função para exibir os detalhes de uma cidade
void exibir_cidade(const Cidade *cidade) {
    printf("\n--- Informações da Cidade ---\n");
    printf("Estado: %s\n", cidade->estado);
    printf("Código: %d\n", cidade->codigo);
    printf("Nome: %s\n", cidade->nome);
    printf("População: %d\n", cidade->populacao);
    printf("PIB: %.2lf milhões\n", cidade->pib);
    printf("Área: %.2lf km²\n", cidade->area);
    printf("Número de pontos turísticos: %d\n", cidade->pontos_turisticos);
    printf("Densidade Populacional: %.2lf hab/km²\n", cidade->densidade_populacional);
    printf("PIB per Capita: %.2lf milhões\n", cidade->pib_per_capita);
}

int main() {
    Cidade cidade;
    
    printf("Registro de Cidades\n");
    registrar_cidade(&cidade);
    exibir_cidade(&cidade);
    
    return 0;
}
