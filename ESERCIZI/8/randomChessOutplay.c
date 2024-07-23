#include <stdio.h>

int main(){
    int QueenRow, QueenCollumn;
    int KingRow, KingCollumn;

    int n = 8;
    int chess[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            chess[i][j] = 0;

    printf("dammi la riga del Re (1-8): ");
    scanf("%d", &KingRow);
    printf("dammi la colonna del Re (1-8): ");
    scanf("%d", &KingCollumn);

    printf("dammi la riga della regina (1-8): ");
    scanf("%d", &QueenRow);
    printf("dammi la colonna della regina (1-8): ");
    scanf("%d", &QueenCollumn);

    chess[KingRow-1][KingCollumn-1] = 1;
    chess[QueenRow-1][QueenCollumn-1] = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", chess[i][j]);
        printf("\n");
    }

    if (QueenCollumn == KingCollumn || QueenRow == KingRow)
        printf("{la regina ha mangiato il re.}");
    else if ( (QueenCollumn - QueenRow) == (KingCollumn - KingRow) )
        printf("{la regina ha mangiato il re.}");
    else if ( (QueenCollumn + QueenRow) == (KingCollumn + KingRow) )
        printf("{la regina ha mangiato il re.}");
}