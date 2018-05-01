#include <stdlib.h>
#include <stdio.h>
#define MAX 15

struct Pessoa{
    float peso;
    int fxEtaria,idade;
};
/*auto explicatorio?*/

struct Media{
    float soma;
    int qtd;
};
enum {crianca, adoles, jovem, adulto};
/*struct para armazenar os dados parcias para o calculo da media
 enum para "traduzir" o que cada indice representa*/

int main(int argc, char ** argv){
    struct Pessoa pessoal[MAX];
    struct Media medias[4];
    int i;
    char temp[100];
    
    for (i = 0; i<4; i++){
        medias[i].soma = 0; medias[i].qtd = 0;
    } /* inicializando as somas parcias com 0,
       *nao lembro de um metodo mais decente*/
    
    for (i = 0; i<MAX; i++){
        printf("Pessoa #%d: \nidade: ",i+1); scanf("%s",&temp); 
        pessoal[i].idade = atoi(temp);
        printf("peso: "); scanf("%s",&temp);
        pessoal[i].peso = atof(temp);
        /*leitura por string, evita problemas misticos com o scanf*/
        
        pessoal[i].fxEtaria = pessoal[i].idade/10;
        /*como as faixas sao intervalos de 10 anos,
         *fazendo a divisao inteira passamos a idade para decada*/
        
        if (pessoal[i].fxEtaria <= 0) pessoal[i].fxEtaria = 0;
        else if(pessoal[i].fxEtaria > 3) pessoal[i].fxEtaria = 3;
        /* esse if garante q o indice do vetor esteja entre 0 e 3*/
        
        medias[pessoal[i].fxEtaria].soma += pessoal[i].peso;
        medias[pessoal[i].fxEtaria].qtd++;
        /* soma parcial e contador atualizados de acordo com a faixa encontrada*/
    }
    for (i = 0; i<4;i++){
        switch (i){
            case crianca: printf("peso medio das criancas"); break;
            case adoles: printf("peso medio dos adolescentes"); break;
            case jovem: printf("peso medio dos jovens") ; break;
            case adulto: printf("peso medio dos adultos"); break;
            default: printf("error"); break;
        }/* case para diferenciar as medias uma das outras para o usuario*/
        
        if (medias[i].qtd == 0){ printf(":0\n"); continue;}
        /*evitando abrir um portal pra outra dimensao*/
        
        printf(": %.2f\n",medias[i].soma/medias[i].qtd);
        /*e finalmente a media*/
    }
    return(EXIT_SUCCESS);
}