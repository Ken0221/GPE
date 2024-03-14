#include <math.h>
#include <stdio.h>

#include <iostream>
#include <vector>
using namespace std;

bool Nprime[1000000]; // global parameter initialize it as false

int main() {
    // 質數表
    Nprime[0] = true;
    Nprime[1] = true;
    int sqrt_1000000 = sqrt(1000000); // 只要sqrt(NUM)以內質數的倍數都刪掉就可
    for (int i = 2; i <= sqrt_1000000; i++) {
        if (!Nprime[i]) {
            for (int j = i * i; j < 1000000; j += i) { 
                if (!Nprime[j])
                    Nprime[j] = true; 
            }
        }
    }

    int DgPrimeNum[1000000];
    DgPrimeNum[0] = 0;
    for (int i = 1; i < 1000000; i++) {
        DgPrimeNum[i] = DgPrimeNum[i - 1]; //count the num of digital prime before i(inclusive)
        if (!Nprime[i]) { //Is Digital Prime?
            int ii = i;
            int num = 0;
            while (ii > 0) {
                num += ii % 10;
                ii /= 10;
            }
            if(!Nprime[num])
                DgPrimeNum[i]++;
        }
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", DgPrimeNum[b] - DgPrimeNum[a - 1]);
    }
    return 0;
}