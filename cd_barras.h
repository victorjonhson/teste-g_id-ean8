//grupo de constantes para o codificador do codigo de barras
//aqui as funcoes irao transformar o identificador para binario

//marcadores padrao de inicio, meio, e fim
const int inicio_cod[] = {1, 0, 1};
const int centro_cod[] = {0, 1, 0, 1, 0};
const int fim_cod[] = {1, 0 , 1};

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


int codIdentificador(int identificador[]) {

}