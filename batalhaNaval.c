#include <stdio.h>

/*Declarando prototipos*/
int limpaTabuleiro();
int imprimeTabuleiro();
int colocaNavioH();
int colocaNavioV();
int colocaNavioD();
int colocaHabilidade();

int main()
{
    /*Inicializando o tabuleiro*/
    int tabuleiro[10][10];
    limpaTabuleiro(tabuleiro);
    

    int navio[3] = {3, 3, 3};

    /*Exibindo tabuleiro vazio*/
    printf("Este é nosso tabuleiro de Batalha Naval!");
    imprimeTabuleiro(tabuleiro);
    putchar('\n');

    /*Posicionando 4 navios no tabuleiro*/
    printf("Vamos colocar quatro navios no tabuleiro. Sendo, um na vertical, um na horizontal, e dois na diagonal\n\n");
    colocaNavioH(navio, 2, 2, tabuleiro);
    colocaNavioV(navio, 3, 3, tabuleiro);
    colocaNavioD(navio, 2, 7, tabuleiro);
    colocaNavioD(navio, 6, 1, tabuleiro);

    /*Impressao final*/
    imprimeTabuleiro(tabuleiro);
    putchar('\n');


    
    /*Inicialiando habilidades*/
    int cone[3][5] = 
    {
        {0,0,5,0,0},
        {0,5,5,5,0},
        {5,5,5,5,5}
    };

    int octaedro[3][5] = 
    {
        {0,0,6,0,0},
        {0,6,6,6,0},
        {0,0,6,0,0}
    };

    int cruz[3][5] = 
    {
        {0,0,7,0,0},
        {7,7,7,7,7},
        {0,0,7,0,0}
    };
    
    /*Imprimindo habilidades*/
    printf("Vamos fazer inserir as habilidades no tabuleiro:\n");
 
    printf("Legenda: 5 - Cone;\n         6 - Octaedro;\n         7 - Cruz;\n");
    limpaTabuleiro(tabuleiro);
    colocaHabilidade(cone, 2, 3, tabuleiro);
    colocaHabilidade(octaedro, 5, 3, tabuleiro);
    colocaHabilidade(cruz, 5, 7, tabuleiro);
    imprimeTabuleiro(tabuleiro);
    
    return 0;
}

/*Declaracao das funcoes*/
int limpaTabuleiro(int tabuleiro[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
}
int imprimeTabuleiro(int tabuleiro[10][10])
{
    for (int c = 0; c < 10; c++)
    {
        for (int l = 0; l < 10; l++)
        {
            printf("[%d]", tabuleiro[c][l]);
        }
        printf("\n");
    }
    return 0;
}

int colocaNavioH(int navio[3], int coluna, int linha, int tabuleiro[10][10])
{
    /*Valida Coordenadas*/
    if (coluna > 10 || coluna < 0 || linha > 10 || linha < 0)
    {
        printf("Coordenadas Invalidas!");
    }

    if (tabuleiro[coluna][linha] != 0 || tabuleiro[coluna + 1][linha] != 0 || tabuleiro[coluna + 2][linha] != 0)
    {
        printf("Ja existe um navio no caminho!\n");
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[coluna][linha + i] = navio[i];
        }
    }
}
int colocaNavioV(int navio[3], int coluna, int linha, int tabuleiro[10][10])
{
    /*Valida Coordenadas*/
    if (coluna > 10 || coluna < 0 || linha > 10 || linha < 0)
    {
        printf("Coordenadas Invalidas!");
    }

    if (tabuleiro[coluna][linha] != 0 || tabuleiro[coluna][linha + 1] != 0 || tabuleiro[coluna][linha + 2] != 0)
    {
        printf("Ja existe um navio no caminho!\n");
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[coluna + i][linha] = navio[i];
        }
    }
}
int colocaNavioD(int navio[3], int coluna, int linha, int tabuleiro[10][10])
{
    /*Valida Coordenadas*/
    if (coluna > 10 || coluna < 0 || linha > 10 || linha < 0)
    {
        printf("Coordenadas Invalidas!");
    }

    if (tabuleiro[coluna][linha] != 0 || tabuleiro[coluna][linha + 1] != 0 || tabuleiro[coluna][linha + 2] != 0)
    {
        printf("Ja existe um navio no caminho!\n");
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[coluna + i][linha+i] = navio[i];
        }
        
    }
}

int colocaHabilidade(int habilidade[3][5], int x, int y, int tabuleiro[10][10])
{
    if (x < 1 || x > 8 || y < 2 || y > 7)
    {
        printf("Não foi possivel inserir habilidade. Verifique coordenadas");
        return 0;
    }
    
    x -= 1;
    y -= 2;
    int a,b=y;    

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)        
        {
            tabuleiro[x][b] = habilidade[i][j];
            b++;
        }
        x++;
        b = y;
    }
}