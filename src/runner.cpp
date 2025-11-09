#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int T = 1000, ts, te;

int main() {
    int time = 0;

    while(T--) {
        system("./maker");
        int ts = clock();
        system("./simulate_anneal");
        int te = clock();
        time += te - ts;
    }

    printf("Time: %d", time);

    return 0;
}