from PIL import Image
from urllib import request
import io
f = request.urlopen('http://www.baidu.com/img/bd_logo1.png')
data = f.read()
ff = open('aaa.png', 'wb')
ff.write(data)
#print(data)
