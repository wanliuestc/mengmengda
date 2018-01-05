from urllib import request

f = request.urlopen('http://www.baidu.com')
for k, v in f.getheaders():
    print('%s: %s' % (k, v))
#data = f.read()
#print(data)
