#ifndef __SWAP_H__
#define __SWAP_H__

#define DECLTYPE(x) __typeof(x)

#define SWAP(a, b)                                                             \
    do {                                                                       \
        DECLTYPE(a) _t = a;                                                    \
        a = b;                                                                 \
        b = _t;                                                                \
    } while (0)

#endif
