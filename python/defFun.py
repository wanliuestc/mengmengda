def my_abs(x):
    if not isinstance(x, (int, float)):
        return 0
    if x > 0:
        return x
    else:
        return -x

def test1(*argvs):
    for argv in argvs:
        print(argv)

my_abs(-10)
test1(1, 2, 3, 4, 5, 6)
li = [1, 2, 3, 4]
test1(*li)

def test2(name, age, **kv):
    print('name:', name, 'age:', age, 'other:', kv)

def test3(a, b, c = 0, *, city, job):
    print(a, b, c, city, job)

def test4(a, b, c = 0, *args, city, job):
    print(a, b, c, args, city, job)

def test5(a, b, c = 0, *args, city, job, **kv):
    print(a, b, c, args, city, job, kv)

test2('changwanli', 123, hello=3, world='t')
d = {'hello':3, 'world':'123'}
test2('55', '4', **d)
test2('123', 0, dd = d['hello'])
test3(1, 2, 3, city='hefei', job='pp')
test4(1, 2, 3, 'a', 'b', city='heifei', job='pp')
test5(1, 2, 3, 'aa', 'bb', 'cc', city='luan', job='kk', name='changwanli')
