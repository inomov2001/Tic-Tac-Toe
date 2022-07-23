#include<stdio.h>
#include<stdlib.h>

void yutiq(int v) {
    if (v == 1) {
        printf("Bratan yuttiz endi osh qberas (X)\n");
        printf("\n");
    }else{
        printf("Adashib yutib quydingiz 😏 (0)\n");
        printf("\n");
    }
}

int Elbek(int v, int s[3][3]) {
    int a = (
        s[0][0] == v && s[0][1] == v && s[0][2] == v ||
        s[1][0] == v && s[1][1] == v && s[1][2] == v ||
        s[2][0] == v && s[2][1] == v && s[2][2] == v ||
        s[0][0] == v && s[1][0] == v && s[2][0] == v ||
        s[0][1] == v && s[1][1] == v && s[2][1] == v ||
        s[0][2] == v && s[1][2] == v && s[2][2] == v ||
        s[0][0] == v && s[1][1] == v && s[2][2] == v ||
        s[0][2] == v && s[1][1] == v && s[2][0] == v);

    if (a == 1) {
        yutiq(v);
        return 1;
    }

    return 0;
}


void olma(int banan[3][3]){
    system("clear");
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++){
            switch (banan[i][j]){
                case 1: printf(" X "); break;
                case 0: printf(" O "); break;
                case -1: printf("   "); break;
            }
            if (j != 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2) {
            printf("-----------\n");
        }
    }
}

int main(){
        char belgi;
        do{
    int arr[3][3] = {
        {-1, -1, -1},
        {-1, -1, -1},
        {-1, -1, -1}
    };
       
            for (int i = 0; i < 9; i++){
                int sum, x = 1, y = 0;
                olma(arr);
                if(i % 2 == 0){
                    printf("1 dan 9 gacha bo'lgan sonlarni kiriting!\n");
                    printf("Kiriting X -> ");
                    scanf("%d", &sum);
                    
                    if (arr[0][sum - 1] == -1) arr[0][sum - 1] = 1;
                    else i --;
                    if (Elbek(1, arr) == 1){
                        olma(arr);
                        yutiq(1);
                        break;
                    }
                }else {
                    printf("1 dan 9 gacha bo'lgan sonlarni kiriting!\n");
                    printf("Kiriting O -> ");
                    scanf("%d", &sum);

                    if (arr[0][sum - 1] == -1) arr[0][sum - 1] = 0;
                    else i --;
                    if (Elbek(0, arr) == 1){
                        olma(arr);
                        yutiq(0);
                        break;
                    }
                }
            }
            printf("Yana uynashdi xohlaysizmi yoki dars qilasizmi? h/y\n");
            scanf("%s", &belgi);

        } while (belgi == 104);
    printf("Bor endi darsini qil!!!");


    return 0;
}
