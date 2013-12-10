#include <stdio.h>
#include <stdlib.h>
#include <cmath>

bool witness(long long a, long long n)
{
    long long t, d, x;
    d = 1;
    int i= ceil(log(n-1.0) / log(2.0)) - 1;
    for(; i >= 0; i--)
    {
        x = d;
        d = (d * d) % n;
        if (d == 1 && x != 1 && x != n-1) {
            return true;
        }
        if (((n - 1) & (1 << i)) > 0) {
            d = (d * a) % n;
        }
    }
    return d == 1 ? false : true;
}

bool miller_rabin(long long n)
{
    if (n == 2) {
        return true;
    }
    
    if (n == 1 || ((n & 1) == 0)) {
        return false;
    }
    
    for (int i = 0; i < 50; i++) {
        long long a = rand() * (n-2) / RAND_MAX + 1;
        if (witness(a, n)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    int n, cnt;
    long long a;

    while (scanf("%d", &n) != EOF) {
        cnt=0;
        while (n--) {
            scanf("%lld",&a);
            if (miller_rabin(a)) {
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
