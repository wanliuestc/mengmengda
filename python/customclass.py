class Student(object):
    def __init__(self, name):
        self.name = name
    
    def __str__(self):
        return 'student name is %s ' % self.name

    def __call__(self):
        print('hello %s' %  self.name)


class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1

    def __iter__(self):
        return self

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b
        if self.a > 1000:
            raise StopIteration()
        return self.a

    def __getitem__(self, n):
        a, b = 0, 1
        for x in range(n):
            a, b = b, a + b
        return a
    

class Chain(object):
    def __init__(self, path=''):
        self._path = path

    def __getattr__(self, path):
        return Chain('%s/%s' % (self._path, path))

    def __str__(self):
        return self._path
        
    __repr__ = __str__

print(Student('Michael'))
#for n in Fib():
#    print(n)
#print(Fib()[10])
print(Chain().status.user.timeline.list)
s = Student('changwanli')
s()
