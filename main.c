#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    char *arr1Tokens[1024], *arr2Tokens[1024];

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
        operationOne[strcspn(operationOne, "\n")] = '\0';

        fgets(operationTwo, sizeof(operationTwo), file);
        operationTwo[strcspn(operationTwo, "\n")] = '\0';

        switch (operationCode)
        {
        case 'U':
            printf("União: conjunto 1 {%s}, conjunto 2 {%s}. Resultado: {%s, %s}\n",
                   operationOne, operationTwo, operationOne, operationTwo);
            break;
        case 'I':
            strcpy(operationOneTemp, operationOne);
            Intersection(combination, operationOneTemp, operationTwo);
            printf("Intersecção: conjunto 1 {%s}, conjunto 2 {%s}. Resultado: {%s}\n",
                   operationOne, operationTwo, combination);
            break;

        case 'D':
            strcpy(operationOneTemp, operationOne);
            Diference(combination, operationOneTemp, operationTwo);
            printf("Diferença: conjunto 1 {%s}, conjunto 2 {%s}. Resultado: {%s}\n",
                   operationOne, operationTwo, combination);
            break;

        case 'C':
            strcpy(operationOneTemp, operationOne);
            strcpy(operationTwoTemp, operationTwo);

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
