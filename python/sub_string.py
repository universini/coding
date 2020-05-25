#!/usr/bin/python

def sub_string(string, word):
	words = string.split(" ")
	for i in words:
		print(i)
		if i == word:
			return i, "yes"
	return "no"

if __name__ == '__main__':
	s = "sidde gowda also known as sidde siddu sidda"
	print(sub_string(s, "siddu"))
