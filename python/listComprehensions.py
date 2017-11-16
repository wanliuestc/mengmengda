print(range(1, 11))
print(list(range(1, 11)))
print(x*x for x in range(1, 11))
x = range(1, 11)
#for t in x:
 #   print(t)
#expr for iter_val in iterable if cond_exp
#() genetrator []list
L= [x for x in range(1, 15) if x%2==0]
print(L)
L = (x for x in range(1, 15) if x%2==0)
print(L)

def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        print(b)
        a, b = b, a+b
        n=n+1

fib(6)

def odd():
    print('step 1')
    yield 1
    print('step 2')
    yield 2
    print('step 3')
    yield 3

o = odd()
print(o)
next(o)
next(o)
next(o)
