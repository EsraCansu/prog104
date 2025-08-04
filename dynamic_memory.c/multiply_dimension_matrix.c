#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*int main(){
    int p[10][6];
    int i, j;

    srand(time(NULL));

    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            p[i][j]=rand()%49+1;
        }
    }

    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/

int main(){
    int p[10][6];
    int i, j;

    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            scanf("%d", &p[i][j]); // hoca neden & kullandı
        }
        printf("\n");
    }
    return 0;
}