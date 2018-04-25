#!/usr/bin/python3

def is_prime(n):
    flag = False
    for i in range(2, n//2):
        if n%i == 0:
            flag = True
            break

    if flag == True:
        return 0
    else:
        return 1

if __name__ == '__main__':
    n = int(raw_input("Enter num: "))
    r = is_prime(n)
    print("%s" % "prime" if r else "not prime")

