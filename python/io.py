f = open('/root/work/mengmengda/c++/test.cpp', 'r')
while True:
    line = f.read(10)
    if not line:
        break
    print(line)
f.close()

