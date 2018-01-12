from email.mime.text import MIMEText
import smtplib

msg = MIMEText('hello, send by python..', 'plain', 'utf-8')
msg['from'] = 'changwanli777@163.com'
msg['to'] = '973240931@qq.com'

from_addr = 'changwanli777@163.com'
password = 'qwe123456'
to_addr = '973240931@qq.com'
smtp_server = 'smtp.163.com'

server = smtplib.SMTP(smtp_server, 25)
server.set_debuglevel(1)
server.login(from_addr, password)
server.sendmail(from_addr, [to_addr], msg.as_string())
server.quit()
