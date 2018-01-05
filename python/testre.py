import re

print(re.match(r'^\d{3}\-\d{3,8}$', '010-1'))
print(re.split(r'\s+', 'a b   c'))
print(re.split(r'[\s\,\;]+', 'a,b;; c  d'))

m = re.match(r'(^\d{3})-(\d{3,8})$', '010-12345')
print(m)
print(m.group(0), m.group(1), m.group(2))

m = re.match(r'^(\d+)(0*)$', '102300')
print(m.groups())
m = re.match(r'^(\d+?)(0*?)$', '102300')
print(m.groups())
