#include <stdio.h>
#include <stdbool.h>

// Declara o array com a matriz base

int matrizSudoku[9][9] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

// Função central que valida se a tentativa está de acordo com as regras do Sudoku

bool tentativaValida(int matrizSudoku[9][9], int linha, int coluna, int numeroAtual){

// Definir a condição  que valida os números das colunas e linhas
// Se o valor do índice de uma coluna, em uma determinada linha for igual ao numeroAtual, então o número não será válido para aquela posição
for (int i=0; i<=8; i++){

    if(matrizSudoku[linha][i]==numeroAtual || matrizSudoku[i][coluna]==numeroAtual){
        return false;
    }
}
// Função que mapeia onde cada quadrante começa

int padraoQuadrante[9] = {0,0,0,3,3,3,6,6,6};

int inicioLinhaQuadrante =  padraoQuadrante[linha];
int inicioColunaQuadrante = padraoQuadrante[coluna];

for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrizSudoku[inicioLinhaQuadrante + i][inicioColunaQuadrante + j] == numeroAtual) {
                return false;
            }
        }
    }
    return true;
}
// Função solucionadora do problema

bool preencheSudoku(){

for (int linha = 0; linha < 9; linha++) {
        for (int coluna = 0; coluna < 9; coluna++) {
            // Confere se a posição na matriz está vazia a cada loop
            if (matrizSudoku[linha][coluna] == 0) { 
                // Confere se o numeroAtual está entre 1 e 9, inclusive
                for (int numeroAtual = 1; numeroAtual <= 9; numeroAtual++) {

                    // Aplica as regras da tentativaValida
                    if (tentativaValida(matrizSudoku,linha, coluna, numeroAtual)) {
                        // Declara o valor do indice atual, se as regras são satisfeitas
                        matrizSudoku[linha][coluna] = numeroAtual;
                        // Vai para a próxima posição
                        if (preencheSudoku()) return true;
                        //Se preencheSudoku retornar false, significa que a escolha anterior levou a um erro adiante. Desfazemos a escolha resetando para 0.
                        matrizSudoku[linha][coluna] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true; 
}

// Função que imprime toda a matriz
void printMatrix(){

for(int i=0; i < 9; i++){
    for(int j=0; j< 9; j++){

        printf("%d", matrizSudoku[i][j]);
    }
    printf("\n");
}
}

// Chamada de funções

int main(){

if (preencheSudoku()) { 
        printf("Sudoku Resolvido:\n");
        printMatrix();
    } else {
        printf("Nao foi possivel encontrar uma solucao.\n");
    }
    return 0;
}
