#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cd_barras.h"

//gerador de codigo EAN-8
//gerar uma imagem com um codigo de barras a partir de um dado identificador

//padrao EAN-8 possui 7 digitos e 1 digito verificador
int main(int argc, char *argv[]){

    int digitos[8] = {};
    int soma = 0;

    char cod_barras[68*3];
    const char *nomeArquivo = "cd_barras.pbm";

    int altura = 100;
    int espaco_l = 8;

    if(argc < 2){
        printf("Por favor, digite um identificador de 8 numeros como argumento.\n");
        return -1;
    }

    //recebe o segundo parametro, ja que o primeiro eh o nome do arquivo passado na linha do cmd
    char *entrada = argv[1];

    //verifica se a entrada tem 8 numeros
    if(strlen(entrada) != 8){
        printf("O identificador deve ter exatamente 8 digitos.\n");
        return -1;
    }

    //conversao de string para numero
    for (int i = 0; i < 8; i++){
        digitos[i] = entrada[i] - '0';
    }

    //verificando se os dados estao corretos (somente valido de 0 a 9)
    for (int i = 0; i < 8; i++){
        if (digitos[i] < 0 || digitos[i] > 9){
            printf("O Identificador precisa ter apenas numeros! Digite novamente:\n");
            return -1;
        }
    }

    //Leitura do Codigo de barras (calcular soma dos 7 digitos)
    for (int i = 0; i < 7; i++) {
        if (i % 2 == 0) {
            soma += (digitos[i] * 3);
        } else {
            soma += (digitos[i] * 1);
        }
    }

    //Digito verificador
    if (((soma + digitos[7]) % 10) == 0){
        printf("Leitura realizada com sucesso!.\n");
        printf("Soma: %d\n", soma);
    } else {
        printf("Houve algum erro.\n");
        printf("Soma: %d\n", soma);
    }

    //verificando se o usuário passou o espacamento lateral no argumento
    if (argc > 2){
        espaco_l = atoi(argv[2]);
    }
    //verificando se o usuário passou a altura no argumento
    if(argc > 3){
        altura = atoi(argv[3]);
    }

    printf("\n");

    //transforma o identificador de 8 digitos para binario (1, 0)
    codIdentificador(digitos, cod_barras, 3);
    printf("Codigo de barras gerado eh (binario): %s\n", cod_barras);

    //gerar imagem .pbm com o codigo binario
    gerarImagemPBM(cod_barras, "cod_barras.pbm", altura, espaco_l);

}