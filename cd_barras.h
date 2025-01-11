#include <string.h>
#include <stdio.h>

//grupo de constantes para o codificador do codigo de barras
//aqui as funcoes irao transformar o identificador para binario

//marcadores padrao de inicio, meio, e fim
const int inicio_cod[] = {1, 0, 1};
const int centro_cod[] = {0, 1, 0, 1, 0};
const int fim_cod[] = {1, 0 , 1};

//padrao EAN-8 para conversao de inteiro para binario
const int l_code[10][7] = {
    {0, 0, 0, 1, 1, 0, 1}, //0
    {0, 0, 1, 1, 0, 0, 1}, //1
    {0, 0, 1, 0, 0, 1, 1}, //2
    {0, 1, 1, 1, 1, 0, 1}, //3
    {0, 1, 0, 0, 0, 1, 1}, //4
    {0, 1, 1, 0, 0, 0, 1}, //5
    {0, 1, 0, 1, 1, 1, 1}, //6
    {0, 1, 1, 1, 0, 1, 1}, //7
    {0, 1, 1, 0, 1, 1, 1}, //8
    {0, 0, 0, 1, 0, 1, 1} //9
};

const int r_code[10][7] = {
    {1, 1, 1, 0, 0, 1, 0}, //0
    {1, 1, 0, 0, 1, 1, 0}, //1
    {1, 1, 0, 1, 1, 0, 0}, //2
    {1, 0, 0, 0, 0, 1, 0}, //3
    {1, 0, 1, 1, 1, 0, 0}, //4
    {1, 0, 0, 1, 1, 1, 0}, //5
    {1, 0, 1, 0, 0, 0, 0}, //6
    {1, 0, 0, 0, 1, 0, 0}, //7
    {1, 0, 0, 1, 0, 0, 0}, //8
    {1, 1, 1, 0, 1, 0, 0} //9
};

//funcao na qual converte o identificador (8 digitos) em codigo binario
void codIdentificador(int identificador[], char resultado[]) {
    int pos = 0;

    //marcadores do inicio
    for(int i = 0; i < 3; i++){
        resultado[pos++] = '0' + inicio_cod[i];
    }

    //adicioando os 4 digitos iniciais
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++){
            resultado[pos++] = '0' + l_code[identificador[i]][j];
        }
    }

    //marcadores do centro
    for(int i = 0; i < 5; i++){
        resultado[pos++] = '0' + centro_cod[i];
    }

    //adicioando os 4 digitos finais
    for(int i = 4; i < 8; i++) {
        for(int j = 0; j < 7; j++){
            resultado[pos++] = '0' + l_code[identificador[i]][j];
        }
    }

    //marcadores do fim
    for(int i = 0; i < 3; i++){
        resultado[pos++] = '0' + fim_cod[i];
    }
}