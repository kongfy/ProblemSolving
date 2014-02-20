#include <cstdio>
#include <cstring>

#define MAXLEN 5000

char a[MAXLEN], b[MAXLEN];
unsigned int f[MAXLEN][MAXLEN];

inline unsigned int min(unsigned int a, unsigned int b)
{
    if (a < b) {
        return a;
    }
    return b;
}

int main(int argc, char *argv[])
{
    scanf("%s", a);
    scanf("%s", b);

    int la = strlen(a);
    int lb = strlen(b);

    // init
    memset(f, 0xff, sizeof(f));
    for (int i = 0; i <= la; ++i) {
        f[i][0] = i;
    }
    for (int j = 0; j <= lb; ++j) {
        f[0][j] = j;
    }

    // dp
    for (int i = 1; i <= la; ++i) {
        for (int j = 1; j <= lb; ++j) {
            if (a[i - 1] == b[j - 1]) {
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            } else {
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
            }

            f[i][j] = min(f[i][j], f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j] + 1);
        }
    }

    printf("%u\n", f[la][lb]);

    // validate
    // for (int i = 0; i <= la; ++i) {
    //     for (int j = 0; j <= lb; ++j) {
    //         printf("%u\t", f[i][j]);
    //     }
    //     printf("\n");
    // }
    
    return 0;
}
