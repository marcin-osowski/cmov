#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int   A_SIZE    = 1024;
const int   ITERS     = 200 * 1000;
const float PROBS[]   = {0.0f, 0.001f,
                         0.005f, 0.01f, 0.1f, 0.15f,
                         0.2f, 0.3f, 0.4f, 0.5f,
                         0.6f, 0.7f, 0.8f, 0.9f,
                         0.99f, 0.999f, 0.9999f, 1.0f};


int test_cmov(int const* A, int const n, int const iters);
int test_cmov_0(int const* A, int const n, int const iters);
int test_cmov_1(int const* A, int const n, int const iters);

int test_branch(int const* A, int const n, int const iters);
int test_branch_0(int const* A, int const n, int const iters);
int test_branch_1(int const* A, int const n, int const iters);

int main()
{
    int i, j;
    int A[A_SIZE];

    srand(time(NULL));

    printf("#probability;time_branch;time_branch_0;time_branch_1;"
           "time_cmov;time_cmov_0;time_cmov_1;\n");


    for(i = 0; i < sizeof(PROBS)/sizeof(float); ++i) {
        printf("%f", PROBS[i]);
        for(j = 0; j < A_SIZE; ++j) {
            float const rand_val = (float)rand() / (float)RAND_MAX;
            A[j] = rand_val < PROBS[i];
        }

        clock_t before;
        volatile int sum;
        sum = sum;

        before = clock();
        sum = test_branch(A, A_SIZE, ITERS);
        printf(";%f", (float)(clock() - before) / (float)CLOCKS_PER_SEC);

        before = clock();
        sum = test_branch_0(A, A_SIZE, ITERS);
        printf(";%f", (float)(clock() - before) / (float)CLOCKS_PER_SEC);

        before = clock();
        sum = test_branch_1(A, A_SIZE, ITERS);
        printf(";%f", (float)(clock() - before) / (float)CLOCKS_PER_SEC);


        before = clock();
        sum = test_cmov(A, A_SIZE, ITERS);
        printf(";%f", (float)(clock() - before) / (float)CLOCKS_PER_SEC);

        before = clock();
        sum = test_cmov_0(A, A_SIZE, ITERS);
        printf(";%f", (float)(clock() - before) / (float)CLOCKS_PER_SEC);

        before = clock();
        sum = test_cmov_1(A, A_SIZE, ITERS);
        printf(";%f", (float)(clock() - before) / (float)CLOCKS_PER_SEC);

        printf("\n");
    }

    return 0;
}

