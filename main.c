/*        Ricardo Lucas Kucek

  Para obter os pontos relativos a este trabalho, você deverá criar um programa,
utilizando a linguagem Python, C, ou C++. Este programa, quando executado, irá
apresentar os resultados de operações que serão realizadas entre dois conjuntos
de dados. O programa que você desenvolverá irá receber como entrada um arquivo
de texto (.txt) contendo vários conjuntos de dados e várias operações. Estas
operações e dados estarão representadas em um arquivo de textos contendo apenas
os dados referentes as operações que devem ser realizadas segundo a seguinte
regra fixa: a primeira linha do arquivo de texto de entrada conterá o número de
operações que estão descritas no arquivo, este número de operações será um
inteiro; as linhas seguintes seguirão sempre o mesmo padrão de três linhas: a
primeira linha apresenta o código da operação (U para união, I para interseção,
D para diferença e C produto cartesiano), a segunda e terceira linhas conterão
os elementos dos conjuntos separados por virgulas. A seguir está um exemplo das
linhas que podem existir em um arquivo de testes para o programa que você irá
desenvolver:

4
U
3, 5, 67, 7
1, 2, 3, 4
I
1, 2, 3, 4, 5
4, 5
D
1, A, C, 34
A, C, D, 23
C
3, 4, 5, 5, A, B, R
1, B, C, D, 1

  Neste exemplo temos 4 operações uma união (U), uma interseção (I), um
diferença (D) e um produto cartesiano (C). A união, definida por U, deverá ser
executada sobre os conjuntos {𝟑, 𝟓, 𝟔𝟕,  {𝟏, 𝟐, 𝟑, 𝟒}, cujos elementos e
tão explicitados nas linhas posteriores a definição da operção  A resposta do
seu programa deverá conter a operação realizada, descrita por extenso, os dados
dos conjuntos identificados, e o resultado da operação. No caso da união a linha
de saída deverá conter a informação e a formatação mostrada a seguir: União:
  conjunto 1 {3, 5, 67, 7}, conjunto 2 {1, 2, 3, 4}. Resultado: {3, 5, 67, 7, 1,
2, 4}

Seu programa deverá mostrar a saída no terminal, ou em um arquivo detextos. Em
qualquer um dos casos, a saída será composta por uma linha de saída para cada
operação constante no arquivo de textos de entrada formatada segundo o exemplo
de saída acima. Observe as letras maiúsculas e minúsculas, e os pontos
utilizados na formatação da linha de saída apresenta acima. No caso do texto de
exemplo, teremos 4 linhas, e apenas 4 linhas de saída, formatadas e pontuadas
conforme o exemplo de saída acima. O uso de linhas extras na saída, ou erros de
formatação, implicam em perda de pontos como pode ser visto na rubrica de
avaliação constante neste documento.

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Union(char combination[], char arr1[], char arr2[])
{
    char buffer[1024] = "";

    strcpy(buffer, arr1);

    char *charTkn = strtok(arr2, ", ");
    while (charTkn != NULL)
    {
        if (strstr(buffer, charTkn) == NULL)
        {
            strcat(buffer, ", ");
            strcat(buffer, charTkn);
        }

        charTkn = strtok(NULL, ", ");
    }

    strcpy(combination, buffer);
}

void Intersection(char combination[], char arr1[], char arr2[])
{
    char buffer[1024] = "";

    char *charTkn = strtok(arr1, ", ");
    while (charTkn != NULL)
    {
        if (strstr(arr2, charTkn) != NULL)
        {
            if (strlen(buffer) > 0)
                strcat(buffer, ", ");
            strcat(buffer, charTkn);
        }

        charTkn = strtok(NULL, ", ");
    }

    strcpy(combination, buffer);
}

void Diference(char combination[], char arr1[], char arr2[])
{
    char buffer[1024] = "";

    char *charTkn = strtok(arr1, ", ");
    while (charTkn != NULL)
    {
        if (strstr(arr2, charTkn) == NULL)
        {
            if (strlen(buffer) > 0)
                strcat(buffer, ", ");
            strcat(buffer, charTkn);
        }

        charTkn = strtok(NULL, ", ");
    }

    strcpy(combination, buffer);
}

void CartesianProduct(char combination[], char arr1[], char arr2[])
{
    char buffer[1024] = "";

    char arr1Tmp[1024] = "", arr2Tmp[1024] = "";

    strcpy(arr1Tmp, arr1);
    strcpy(arr2Tmp, arr2);

    char *arr1Tokens[255], *arr2Tokens[255];

    int arr1cnt = 0, arr2cnt = 0;

    char *token = strtok(arr1Tmp, ", ");
    while (token != NULL)
    {
        arr1Tokens[arr1cnt] = token;
        arr1cnt++;
        token = strtok(NULL, ", ");
    }

    token = strtok(arr2Tmp, ", ");
    while (token != NULL)
    {
        arr2Tokens[arr2cnt] = token;
        arr2cnt++;
        token = strtok(NULL, ", ");
    }

    for (int i = 0; i < arr1cnt; i++)
    {
        for (int j = 0; j < arr2cnt; j++)
        {
            if (strlen(buffer) > 0)
                strcat(buffer, ", ");

            strcat(buffer, "(");
            strcat(buffer, arr1Tokens[i]);
            strcat(buffer, ", ");
            strcat(buffer, arr2Tokens[j]);
            strcat(buffer, ")");
        }
    }

    strcpy(combination, buffer);
}

void ExecuteFile(const char fileName[])
{
    FILE *file = fopen(fileName, "r");

    if (file == NULL)
    {
        perror("Não foi possivel abrir esse arquivo");
        fclose(file);
        return;
    }

    int operationCnt = 0;
    fscanf(file, "%d", &operationCnt);

    char operationCode = '_';

    char operationOne[1024], operationTwo[1024];

    char operationOneTemp[1024], operationTwoTemp[1024];

    char combination[1024];

    for (int i = 0; i < operationCnt; i++)
    {
        fscanf(file, " %c", &operationCode);

        fgets(operationOne, sizeof(operationOne), file);
        fgets(operationOne, sizeof(operationOne), file);
        operationOne[strlen(operationOne) - 1] = '\0';

        fgets(operationTwo, sizeof(operationTwo), file);
        operationTwo[strlen(operationTwo) - 1] = '\0';

        strcpy(operationOneTemp, operationOne);
        strcpy(operationTwoTemp, operationTwo);

        switch (operationCode)
        {
        case 'U':
            Union(combination, operationOneTemp, operationTwo);
            printf("União: conjunto 1 {%s}, conjunto 2 {%s}. Resultado: {%s}\n",
                   operationOne, operationTwo, combination);
            break;

        case 'I':
            Intersection(combination, operationOneTemp, operationTwoTemp);
            printf("Intersecção: conjunto 1 {%s}, conjunto 2 {%s}. Resultado: {%s}\n",
                   operationOne, operationTwo, combination);
            break;

        case 'D':
            Diference(combination, operationOneTemp, operationTwoTemp);
            printf("Diferença: conjunto 1 {%s}, conjunto 2 {%s}. Resultado: {%s}\n",
                   operationOne, operationTwo, combination);
            break;

        case 'C':
            CartesianProduct(combination, operationOneTemp, operationTwoTemp);
            printf("Produto cartesiano: conjunto 1 {%s}, conjunto 2 {%s}. Resultado: "
                   "{%s}\n",
                   operationOne, operationTwo, combination);
            break;

        default:
            printf("Operação incorreta: %c\n", operationCode);
            break;
        }

        printf("\n");
    }

    fclose(file);
}

int main(void)
{
    ExecuteFile("test1.txt");
    return 0;
}
