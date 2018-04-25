#!/usr/bin/python3

def fib(n):
    a, b = 0, 1

    if n < 0:
        return -1
    elif n == 0 or n == 1:
        return n
    else:
        for i in range(1,n):
            c = a + b
            a = b
            b = c
        return b

if __name__ == '__main__':
    n = int(raw_input("Enter number: "))
    print(fib(n))
