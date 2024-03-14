#include <iostream>
#include<math.h>
using namespace std;

int main() {
    int d;
    int dary[4] = {10, 100, 1000, 10000};
    while (scanf("%d", &d) != EOF) {
        int max = dary[(d / 2) - 1];
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < max; j++) {
                if ((i + j) * (i + j) == i * max + j) {
                    int check = i * 10;
                    int count = 1;
                    while(check < max && count < d / 2){
                        check *= 10;
                        count++;
                        cout << 0;
                    }
                    cout << i;
                    check = j * 10;
                    count = 1;
                    while(check < max && count < d / 2){
                        check *= 10;
                        count++;
                        cout << 0;
                    }
                    cout << j << endl;
                }
            }
        }
    }

    return 0;
}