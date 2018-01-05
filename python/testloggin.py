import logging
logging.basicConfig(level=logging.INFO, filename = '/root/work/pylog')
s = '1'
n = int(s)
logging.info('n = %d' % n)
print(10/n)
