def fibonacci_mod_m(n, m):
   
    cache = {0: 0, 1: 1}

    def fib_m(n):
        if n in cache:
            return cache[n]

        if n % 2 == 0:
            fib_half_n = fib_m(n // 2)
            result = (2 * fib_m(n // 2 - 1) + fib_half_n) * fib_half_n
        else:
            result = fib_m((n + 1) // 2) ** 2 + fib_m((n - 1) // 2) ** 2

        cache[n] = result = result % m
        return result

    return fib_m(n)


if __name__ == "__main__":
    n, m = map(int, input().split())
    print(fibonacci_mod_m(n, m))