long long getMSB(long long n) {
    if (n == 0) return 0;

    int pos = 63 - __builtin_clzll(n);
    return 1LL << pos;
}