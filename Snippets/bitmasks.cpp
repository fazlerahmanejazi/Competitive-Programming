#define countBit(n) __builtin_popcountll(n)
#define checkBit(n, i) (((n)>>(i))&1)
#define toggleBit(n, i) (n^=(1<<i))
#define clearBit(n, i) (n&=~(1<<i))
#define setBit(n, i) (n|=(1<<i))