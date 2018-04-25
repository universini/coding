#!/usr/bin/python

cache = {}

def fib_dyn(n):
	if n is 0 or n is 1:
		return n

	if n in cache:
		return cache[n]
	else:
		cache[n] = fib_dyn(n-1) + fib_dyn(n-2)
		return cache[n]

if __name__ == '__main__':
	n = int(input("enter number: "))
	print(fib_dyn(n))
