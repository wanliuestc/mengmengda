x = 'ABC'
print(len(x))
x = b'ABC'
print(len(x))
print(len('ABC'.encode('ascii')))
print('你好'.encode('utf-8'))
print(len('你好'.encode('utf-8')))
print(b'ABC'.decode('ascii'))
print(b'\xe4\xb8\xad\xe6\x96\x87'.decode('utf-8'))
print('hello %s' % 'changwanli')
print('%s %d %f %x' % ('abc', 123, 123.333, 66))
