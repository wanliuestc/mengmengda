from io import StringIO
from io import BytesIO

f = StringIO()
f.write('hello')
f.write(' ')
f.write('world!')
print(f.getvalue())

f = BytesIO()
f.write('中文'.encode('utf-8'))
print(f.getvalue())
print('中文好'.encode('utf-8'))
