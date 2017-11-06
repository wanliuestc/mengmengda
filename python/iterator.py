from collections import Iterable
d = {'a':1, 'b':2, 'c':3}
for key in d:
    print(key, d[key])

print(isinstance('abc', Iterable))
