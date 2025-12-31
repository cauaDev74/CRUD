#include <stdio.h>
#include <stdlib.h>

int m[2][3] = {
    {1, 2, 3}, {4, 5, 6}
};

int main(){
    int matriz[5][5];

    for(int i = 0; i < 5; i++){
        printf("Insira coluna %d: ", i+1);
        scanf("%d", &matriz[i][i]);
        for(int j = 0; j < 5; j++){
            printf("Insira linha %d: ", j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("%d %d %d %d\n", matriz[0][0], matriz[1][0], matriz[2][0]);

}