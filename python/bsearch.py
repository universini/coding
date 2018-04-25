#!/usr/bin/python

class bs (object):
    def __init__(self):
        self.a = [5,7,12,14,16,23,56,190,210]
        self.last = len(self.a) - 1
        self.first = 0

    def bsearch(self, n):
        try:
            while self.first <= self.last:
                mid = (self.first + self.last)//2
                if n < self.a[mid]:
                    self.last = mid - 1
                elif n > self.a[mid]:
                    self.first = mid + 1
                else:
                    return mid
        except:
            return -1

if __name__ == '__main__':
    a = bs()
    n = int(input("Enter number to be found: "))
    print(a.bsearch(n))
