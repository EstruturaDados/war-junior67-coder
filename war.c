#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Territorio
//----------------------------------------------------------------------------------
typedef struct {
    char nome[50];
    char cor_exercito[20];
    int tropas;
} Territorio;
//----------------------------------------------------------------------------------

// Função para ler os dados de um único território
void ler_territorio(Territorio *t, int indice) {
    // Limpa o buffer antes de usar fgets, caso haja '\n' restante
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} 

    printf("\n--- Cadastro do Territorio %d ---\n", indice + 1);
    
    // Leitura do Nome (usando fgets para strings com espaco)
    printf("Nome do Territorio: ");
    if (fgets(t->nome, sizeof(t->nome), stdin) == NULL) {
        // Trata erro de leitura ou EOF
        return; 
    }
    // Remove o '\n' lido pelo fgets, se estiver presente
    t->nome[strcspn(t->nome, "\n")] = 0; 

    // Leitura da Cor do Exercito
    printf("Cor do Exercito Dominante: ");
    if (fgets(t->cor_exercito, sizeof(t->cor_exercito), stdin) == NULL) {
        return;
    }
    t->cor_exercito[strcspn(t->cor_exercito, "\n")] = 0;

    // Leitura do Numero de Tropas
    printf("Numero de Tropas: ");
    // Usamos scanf para ler o inteiro e limpamos o buffer imediatamente
    if (scanf("%d", &t->tropas) != 1) {
         printf("Erro na leitura do numero de tropas.\n");
         t->tropas = 0;
    }
}

// Funcao para exibir o mapa (lista de todos os territorios)
void exibir_mapa(Territorio territorios[], int tamanho) {
    printf("\n============================================\n");
    printf("           ESTADO ATUAL DO MAPA\n");
    printf("============================================\n");
    printf("| %-4s | %-20s | %-15s | %-6s |\n", "ID", "Territorio", "Exercito", "Tropas");
    printf("|------|----------------------|-----------------|--------|\n");
    
    for (int i = 0; i < tamanho; i++) {
        printf("| %-4d | %-20s | %-15s | %-6d |\n", 
               i + 1, 
               territorios[i].nome, 
               territorios[i].cor_exercito, 
               territorios[i].tropas);
    }
    printf("============================================\n");
}

int main() {
    const int NUM_TERRITORIOS = 5;
    // Vetor estatico de 5 elementos (Territorios)
    Territorio mapa[NUM_TERRITORIOS]; 

    printf("Bem-vindo ao Desafio WAR Estruturado - Nivel Novato!\n");
    printf("Por favor, cadastre os %d territorios.\n", NUM_TERRITORIOS);

    // Loop de cadastro
    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        ler_territorio(&mapa[i], i);
    }

    // Exibicao do mapa
    exibir_mapa(mapa, NUM_TERRITORIOS);

    return 0;
}// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    // - Define a cor do jogador e sorteia sua missão secreta.

    // 2. Laço Principal do Jogo (Game Loop):
    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    // - A cada iteração, exibe o mapa, a missão e o menu de ações.
    // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
    //   - Opção 1: Inicia a fase de ataque.
    //   - Opção 2: Verifica se a condição de vitória foi alcançada e informa o jogador.
    //   - Opção 0: Encerra o jogo.
    // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.

    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
