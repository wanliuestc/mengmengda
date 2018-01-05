import json
d = dict(name='bob', age=20,score=90)
print(json.dumps(d))

class student(object):
    def __init__(self, name, age, score):
        self.name = name
        self.age = age
        self.score = score

def student2dict(stu):
    return {'name':stu.name, 'age':stu.age, 'score':stu.score}

def dict2student(d):
    return student(d['name'], d['age'], d['score'])

s = student('tom', 20, 99)
print(s.name)
print(s.__dict__)
print(json.dumps(s, default = student2dict))
print(json.dumps(s, default = lambda obj : obj.__dict__))
js = json.dumps(s, default = student2dict)
print(json.loads(js, object_hook=dict2student))
