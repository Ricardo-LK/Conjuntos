**CRIAR ARQUIVOS**

1.  Um aquivo de texto(.txt) deve ser criado;

2.  Esse arquivo deve seguir as sequintes regras:

        *A primeira linha do arquivo deve conter o número de operações que são descritas no arquivo, este número deve ser um inteiro;
    
        *As linhas seguintes seguirão sempre o mesmo padrão de três linhas;

        *A primeira linha apresenta o código da operação
        (U para união, I para interseção, D para diferença e C produto cartesiano)

        *A segunda e terceira conterão os elementos dos conjuntos separados por virgulas.

**RODAR PROGRAMA**

3.  O programa deve rodar com o arquivo ja proporcionado para testes;

4.  Após a criação do seu aquivo, a função ExecuteFile deve receber como parâmentro o nome exato (com extensão .txt) do arquivo criado.

5.  Caso no Replit: Aperte o botão Run para rodar o programa;

5.  Caso no GitHub:

    - Abra seu editor e no terminal clone o repositorio com o comando:
      git clone https://github.com/Ricardo-LK/Conjuntos.git

    - Instale um compilador de C em sua máquina caso não o tenha;

    - Você deve compilar o código C com o comando:
      gcc main.c -o main

    - Finalmente para rodar o arquivo digite o comando:
      ./main
