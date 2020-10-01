#!/usr/bin/python

def add_num(a, b):
	return(a+b)

class test(object):
	def __init__(self, a, b):
		self.a = a
		self.b = b

	addn = add_num

if __name__ == '__main__':
	t = test(2,3)
	print(add_num(t.a, t.b))

