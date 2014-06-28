int FUNC_NAME(int const* A, int const n, int const iters)
{
    int i, j;
    int res;

    res = 0;
    for(i = 0; i < iters; ++i) {
        for(j = 0; j < n; ++j) {
            #ifdef EXPECT
                if(__builtin_expect(A[j], EXPECT)) {
                    res = j;
                }
            #else
                if(A[j]) {
                    res = j;
                }
            #endif
        }
    }

    return res;
}

