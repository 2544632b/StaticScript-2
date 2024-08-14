function fibonacci(n: number): number {
    if(n <= 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

type_assert(fibonacci(10) == 89);
type_assert(fibonacci(11) == 144);
type_assert(fibonacci(12) == 233);
type_assert(fibonacci(13) == 377);
type_assert(fibonacci(14) == 610);
type_assert(fibonacci(15) == 987);
type_assert(fibonacci(16) == 1597);
type_assert(fibonacci(17) == 2584);
type_assert(fibonacci(18) == 4181);
type_assert(fibonacci(19) == 6765);
type_assert(fibonacci(20) == 10946);