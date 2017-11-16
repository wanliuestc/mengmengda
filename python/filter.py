from collections import Iterable, Iterator
def is_odd(n):
    return n % 2 == 1

print(filter(is_odd, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
print(isinstance(filter(is_odd, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), Iterator))
print(list(filter(is_odd, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])))
