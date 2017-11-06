score = {'changwanli':88, 'zhangsan':77, 'lisi':66}
print(score, score['changwanli'])
score['jack'] = 90
print(score)

if('changwanli' in score):
    print('exist')

print('changwanli' in score)
print(score.get('changwanli'), score.get('hello'), score.get('hello', '00'))
score.pop('changwanli')
print(score)

s = set([1,1,2,3,4])
print(s)
s.add(100)
s.remove(3)
print(s)
s2 = set([1, 4, 6, 9])
print(s & s2, s | s2)
t = 10;
s.add(10)
t = (1,2)
s.add(t)
print(s)
