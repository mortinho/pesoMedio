#include <stdlib.h>
#include <stdio.h>
#define MAX 15

struct Pessoa{
    float peso;
    int fxEtaria,idade;
};
struct Media{
    float soma;
    int qtd;
};
enum {crianca, adoles, jovem, adulto};

int main(int argc, char ** argv){
    struct Pessoa pessoal[MAX];
    struct Media medias[4];
    int i;
    char temp[100];
    for (i = 0; i<4; i++){
        medias[i].soma = 0; medias[i].qtd = 0;
    }
    for (i = 0; i<MAX; i++){
        printf("Pessoa #%d: \nidade: ",i+1); scanf("%s",&temp); 
        pessoal[i].idade = atoi(temp);
        printf("peso: "); scanf("%s",&temp);
        pessoal[i].peso = atof(temp);
        pessoal[i].fxEtaria = pessoal[i].idade/10;
        if (pessoal[i].fxEtaria <= 0) pessoal[i].fxEtaria = 0;
        else if(pessoal[i].fxEtaria > 3) pessoal[i].fxEtaria = 3;
        
        medias[pessoal[i].fxEtaria].soma += pessoal[i].peso;
        medias[pessoal[i].fxEtaria].qtd++;
    }
    for (i = 0; i<4;i++){
        switch (i){
            case crianca: printf("peso medio das criancas"); break;
            case adoles: printf("peso medio dos adolescentes"); break;
            case jovem: printf("peso medio dos jovens") ; break;
            case adulto: printf("peso medio dos adultos"); break;
            default: printf("error"); break;
        }
        if (medias[i].qtd == 0){ printf(":0\n"); continue;}
        printf(": %.2f\n",medias[i].soma/medias[i].qtd);
    }
    return(EXIT_SUCCESS);
}