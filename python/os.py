import os

print(os.name)
print(os.uname())
print(os.environ)
print(os.path.abspath('.'))
#os.mkdir('/root/work/mkdir')
#os.rmdir('/root/work/mkdir')

l = [x for x in os.listdir('.')]
print(next(iter(l)))
print(next(iter(l)))
