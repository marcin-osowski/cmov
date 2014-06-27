
int test_branch(int const* A, int const n, int const iters)
{
    int i, j;
    int sum;

    sum = 0;
    for(i = 0; i < iters; ++i) {
        for(j = 0; j < n; ++j) {
            if(A[j]) {
                sum += j;
            }
        }
    }

    return sum;
}

int test_branch_0(int const* A, int const n, int const iters)
{
    int i, j;
    int sum;

    sum = 0;
    for(i = 0; i < iters; ++i) {
        for(j = 0; j < n; ++j) {
            if(__builtin_expect(A[j], 0)) {
                sum += j;
            }
        }
    }

    return sum;
}

int test_branch_1(int const* A, int const n, int const iters)
{
    int i, j;
    int sum;

    sum = 0;
    for(i = 0; i < iters; ++i) {
        for(j = 0; j < n; ++j) {
            if(__builtin_expect(A[j], 0)) {
                sum += j;
            }
        }
    }

    return sum;
}

