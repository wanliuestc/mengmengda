import functools

def now():
    print('2015-3-25')

f = now
f()
print(f.__name__)

def log(func):
    def wrapper(*args, **kv):
        print('call %s():' % func.__name__)
        return func(*args, **kv)
    return wrapper

@log
def test():
    print('hello world')

test()

def log2(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kv):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kv)
        return wrapper
    return decorator

@log2('execute')
def test2():
    print('hello world2')

test2()

print(test2.__name__)
