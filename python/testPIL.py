from PIL import Image, ImageFilter
from urllib import request
import io
#f = request.urlopen('http://www.baidu.com/img/bd_logo1.png')
#data = f.read()
#ff = open('aaa.png', 'wb')
#ff.write(data)
im = Image.open('aaa.png')
im = im.convert('RGB')
im2 = im.filter(ImageFilter.BLUR)
im2.save('blur.png', 'png')
#print(data)
