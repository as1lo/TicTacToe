#include <stdio.h>
#include <stdlib.h>

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
void base(int *pos, int comp){

    int x, cont = 1, giro = 1, verify[8], ver = 0, hori1x = 0, hori2x= 0, hori3x= 0, ver1x= 0, ver2x= 0, ver3x= 0, diag1x= 0, diag2x = 0;

    int hori1 = 0, hori2 = 0, hori3 = 0, ver1 = 0, ver2 = 0, ver3 = 0, diag1 = 0, diag2 = 0;

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
        
                }else{
                    printf("Vez de 'O': ");
                    scanf("%d", &comp);
                    printf("\n");

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
            
        }while(ver != 1);
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

        if(cont % 2 == 0){
            //verificação horizontal1x
            if(comp == 0 || comp == 1 || comp == 2){
                hori1x++;
            }
            
            if(hori1x >= 3){
                printf("Vitória de 'X'!\n");
                break;
            }

            //verificação horizontal2x
            if(comp == 3 || comp == 4 || comp == 5){
                hori2x++;
            }
            
            if(hori2x >= 3){
                printf("Vitória de 'X'!\n");
                break;
            }

            //verificação horizontal3x
            if(comp == 6 || comp == 7 || comp == 8){
                hori3x++;
            }
            
            if(hori3x >= 3){
                printf("Vitória de 'X'!\n");
                break;
            }

            //
            //verificação vertical1x
            if(comp == 0 || comp == 3 || comp == 6){
                ver1x++;
            }
            
            if(ver1x >= 3){
                printf("Vitória de 'X'!\n");
                break;
            }

            //verificação vertical2x
            if(comp == 1 || comp == 4 || comp == 7){
                ver2x++;
            }
            
            if(ver2x >= 3){
                printf("Vitória de 'X'!\n");
                break;
            }

            //verificação vertical3x
            if(comp == 2 || comp == 5 || comp == 8){
                ver3x++;
            }
            
            if(ver3x >= 3){
                printf("Vitória de 'X'!\n");
                break;
            }

            //
            //verificação diagonal1x
            if(comp == 0 || comp == 4 || comp == 8){
                diag1x++;
            }
            
            if(diag1x >= 3){
                printf("Vitória de 'X'!\n");
                break;
            }

            //verificação diagonal2x
            if(comp == 2 || comp == 4 || comp == 6){
                diag2x++;
            }
            
            if(diag2x >= 3){
                printf("Vitória de 'X'!\n");
                break;
            }
        }else{
            //verificação horizontal1
            if(comp == 0 || comp == 1 || comp == 2){
                hori1++;
            }
            
            if(hori1 >= 3){
                printf("Vitória de 'O'!\n");
                break;
            }

            //verificação horizontal2
            if(comp == 3 || comp == 4 || comp == 5){
                hori2++;
            }
            
            if(hori2 >= 3){
                printf("Vitória de 'O'!\n");
                break;
            }

            //verificação horizontal3
            if(comp == 6 || comp == 7 || comp == 8){
                hori3++;
            }
            
            if(hori3 >= 3){
                printf("Vitória de 'O'!\n");
                break;
            }

            //
            //verificação vertical1
            if(comp == 0 || comp == 3 || comp == 6){
                ver1++;
            }
            
            if(ver1 >= 3){
                printf("Vitória de 'O'!\n");
                break;
            }

            //verificação vertical2
            if(comp == 1 || comp == 4 || comp == 7){
                ver2++;
            }
            
            if(ver2 >= 3){
                printf("Vitória de 'O'!\n");
                break;
            }

            //verificação vertical3
            if(comp == 2 || comp == 5 || comp == 8){
                ver3++;
            }
            
            if(ver3 >= 3){
                printf("Vitória de 'O'!\n");
                break;
            }

            //verificação diagonal1
            if(comp == 0 || comp == 4 || comp == 8){
                diag1++;
            }
            
            if(diag1 >= 3){
                printf("Vitória de 'O'!\n");
                break;
            }

            //verificação diagonal2
            if(comp == 2 || comp == 4 || comp == 6){
                diag2++;
            }
            
            if(diag2 >= 3){
                printf("Vitória de 'O'!\n");
                break;
            }
        }
        
        //verificação de empate
        if(giro > 9){
            printf("Empate!\n");
        }
    }
}

int main(){
    
    int comp = 0, pos[9];
    char resp;

    do{
        printf("===========| Jogo da Velha |===========\n");
        printf("Digite o número relativo a posição em que deseja jogar!\n");
        
        jogo(pos);

        base(pos, comp);

        printf("Jogar Novamente? [s/n]:\n");
        scanf(" %c", &resp);

        system("cls");
    }while(resp == 's');
   
    return 0;
}