'''
keep an array of solution S
every time F function is called with argument n
    first check if S[n] has a value
    if yes, return the value
    if no
        compute F(n)
        store result in S[n]
        return the result
'''
def fibonacci(n):  
    return fibonacci_helper(n, {0: 0, 1: 1})

def fibonacci_helper(n, cache):
    if n not in cache:
        fib1 = fibonacci_helper(n-1, cache)
        fib2 = fibonacci_helper(n-2, cache)
        cache[n] = fib1 + fib2
    return cache[n]

if __name__ == "__main__":
    res = fibonacci(6)
    print(res)