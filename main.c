#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int   A_SIZE    = 2048;
const int   ITERS     = 500 * 1000;
const float PROBS[]   = {0.0f, 0.05f, 0.1f, 0.15f,
                         0.2f, 0.25f, 0.3f, 0.35f,
                         0.4f, 0.45f, 0.5f, 0.55f,
                         0.6f, 0.65f, 0.7f, 0.75f,
                         0.8f, 0.85f, 0.9f, 0.95f,
                         1.0f};


int test_cmov(int const* A, int const n, int const iters);

int test_branch(int const* A, int const n, int const iters);
int test_branch_0(int const* A, int const n, int const iters);
int test_branch_1(int const* A, int const n, int const iters);

int main()
{
    int i, j;
    int A[A_SIZE];

    srand(time(NULL));

    printf("#probability;time_branch;time_branch_0;"
           "time_branch_1;time_cmov\n");
    fflush(stdout);


    for(i = 0; i < sizeof(PROBS)/sizeof(float); ++i) {
        printf("%f", PROBS[i]);
        for(j = 0; j < A_SIZE; ++j) {
            float const rand1 = (float)rand() * (float)RAND_MAX;
            float const rand2 = (float)rand();
            float const rand_val = rand1 + rand2;
            float const rand_01 = rand_val / (float)RAND_MAX / (float)RAND_MAX;
            A[j] = rand_01 < PROBS[i];
        }

        clock_t before;
        volatile int sum;
        sum = sum;

        before = clock();
        sum = test_branch(A, A_SIZE, ITERS);
        printf(";%f", (float)(clock() - before) / (float)CLOCKS_PER_SEC);
        fflush(stdout);

        before = clock();
        sum = test_branch_0(A, A_SIZE, ITERS);
        printf(";%f", (float)(clock() - before) / (float)CLOCKS_PER_SEC);
        fflush(stdout);

        before = clock();
        sum = test_branch_1(A, A_SIZE, ITERS);
        printf(";%f", (float)(clock() - before) / (float)CLOCKS_PER_SEC);
        fflush(stdout);


        before = clock();
        sum = test_cmov(A, A_SIZE, ITERS);
        printf(";%f", (float)(clock() - before) / (float)CLOCKS_PER_SEC);
        fflush(stdout);

        printf("\n");
        fflush(stdout);
    }

    return 0;
}

