#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) return 1;

    time_t curtime;
    time(&curtime);
    char *t_str = ctime(&curtime);
    t_str[24] = '\0'; // 移除 ctime 結尾的換行符號

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", t_str);

    srand(time(NULL));
    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "[%d]: ", i);
        if (i <= n) {
            int num[7];
            for (int j = 0; j < 7; j++) {
                int r, dup;
                do {
                    dup = 0;
                    r = rand() % 69 + 1;
                    for (int k = 0; k < j; k++) {
                        if (num[k] == r) {
                            dup = 1;
                            break;
                        }
                    }
                } while (dup);
                num[j] = r;
                fprintf(fp, "%02d ", num[j]);
            }
        } else {
            fprintf(fp, "-- -- -- -- -- -- -- ");
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
