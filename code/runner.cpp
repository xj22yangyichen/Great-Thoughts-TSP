#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int T = 10000, ts, te;

int main() {
    ts = clock();

    while(T--) {
        system("./maker");
        system("./bf");
    }

    te = clock();
    printf("Time: %d", te - ts);

    return 0;
}