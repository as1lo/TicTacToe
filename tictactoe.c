#include <stdio.h>
#include <stdlib.h>

//verificação da matriz das posições do tabuleiro.
//função para iniciar o processo de verificação de vitória.
//utilizará os números referentes a 'X' e 'O' na tabela ASCII para inserir na matriz 
//caso a posição do tabuleiro seja igual a selecionada pelo jogador.
void tabuleiroverify(int comp, int jog, int tabuleiro[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tabuleiro[i][j] == comp){
                if(jog % 2 != 0){
                    tabuleiro[i][j] = 88;
                }else{
                    tabuleiro[i][j] = 79;
                }
            }
            
        }
    }
}

//verificação de vitória
int verificarVencedor(int tabuleiro[3][3]){

    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            if (tabuleiro[i][0] == 88){
                
                return 1;
            }else if (tabuleiro[i][0] == 79){

                return 2;
            }
        }
    }

    // Verificar colunas
    for(int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
            if (tabuleiro[0][i] == 88){
                return 1;
            }
            else if (tabuleiro[0][i] == 79){

                return 2;
            }
        }
    }

    // Verificar diagonais
    if((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) ||
        (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])) {
        if (tabuleiro[1][1] == 88){

            return 1;
        }
        else if (tabuleiro[1][1] == 79){
            
            return 2;
        }
    }
    
    //se o jogo não acabou.
    return 0;
}

//função para inserir a posição.
void jogo(int *pos){
    int x = 0;

    printf("+---+---+---+\n");
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            
            pos[x] = x;
        
            printf("| %d ", pos[x]);
            x++;
        }

        printf("|\n+---+---+---+\n");
    }
}

//função de inicialização do jogo
void base(int *pos, int comp, int tabuleiro[3][3]){
    int x, cont = 1, giro = 1, verify[8], ver = 0;

    for(int i = 0; i < 9; i++){
        verify[i] = 10;
    }

    //pedindo para selecionar a posição
    while(giro <= 9){
        x = 0;
        
        do{
            ver = 0;
            
            //verificação de número inválido fora do conjunto de números de posição.
            do{
                //troca da vez de jogada.
                if(cont % 2 != 0){
                    printf("Vez de 'X': ");
                    scanf("%d", &comp);
                    printf("\n");

                    tabuleiroverify(comp, cont, tabuleiro);

                }else{
                    printf("Vez de 'O': ");
                    scanf("%d", &comp);
                    printf("\n");

                    tabuleiroverify(comp, cont, tabuleiro);
                }

                if(comp < 0 || comp > 9){
                    printf("Digite um número válido!\n");
                }
            }while(comp < 0 || comp > 9);

            //verificador de erro de escolha de posição.
            for(int i = 0; i < 9; i++){
                if(verify[i] == comp){    
                    printf("Escolha outro!\n");
                    break;
                }else{
                    verify[i] = comp;
                    ver = 1;
                }
            }
            
        }while(!ver);

        system("cls");
        
        printf("+---+---+---+\n");

        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){

                //verificação da posição
                if(pos[x] == comp){

                    //verificação da vez da jogada
                    if(cont % 2 != 0){
                        pos[x] = 88;

                        printf("| %c ", pos[x]);
                        cont++;
                        x++; 
                        
                    }else{
                        pos[x] = 79;

                        printf("| %c ", pos[x]);
                        cont++;
                        x++; 
                    }
                        
                }else{
                    if(pos[x] < 10){
                        pos[x] = x;
                    
                        printf("| %d ", x);
                        
                        x++; 
                    }else{
                        printf("| %c ", pos[x]);

                        x++;
                    }
                    
                }
                    
            }

            printf("|\n+---+---+---+\n");
        }
        giro++;
        
        //verificação de vitória.
        if(verificarVencedor(tabuleiro) == 1){
            printf("Vitória de 'X'!\n");
            break;
        }else if(verificarVencedor(tabuleiro) == 2){
            printf("Vitória de 'O'!\n");
            break;
        }
        
        //verificação de empate
        if(giro > 9){
            printf("Empate!\n");
        }
    }
}

int main(){
    int tabuleiro[3][3], comp = 0, pos[9], c;
    char resp;

    do{
        //preparação para verificação de vitória!!!
        //criando uma matriz para inserir as posições do tabuleiro
        //e em seguida substituir a posição pelo número relacional à 'X' e 'O' na tabela ASCII
        //dentro de uma função.
        c = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                tabuleiro[i][j] = c;
                c++;
            }
        }


        printf("===========| Jogo da Velha |===========\n");
        printf("Digite o número relativo a posição em que deseja jogar!\n");
        
        jogo(pos);

        base(pos, comp, tabuleiro);

        printf("Jogar Novamente? [s/n]:\n");
        scanf(" %c", &resp);

        system("cls");
    }while(resp == 's');
   
    return 0;
}