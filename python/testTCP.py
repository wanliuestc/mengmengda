import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('www.sina.com.cn', 80))

s.send(b'GET / HTTP/1.1\r\nHost: www.sina.com.cn\r\nConnection: close\r\n\r\n')

buf = []
while True:
    d = s.recv(10240)
    if d:
        buf.append(d)
    else:
        break
data = b''.join(buf)
s.close()

header, html = data.split(b'\r\n\r\n', 1)

print(header.decode('utf-8'))
f = open('sina.html', 'wb')
f.write(html)
f.close()
