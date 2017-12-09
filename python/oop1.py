class Student(object):
    def __init__(self, name, score):
        self.__name = name
        self.__score = score

    def print_score(self):
        print('%s:%s' % (self.__name, self.__score))

Tom = Student('Tom', 56)
Jack = Student('Jack', 99)


Tom.print_score()
Jack.print_score()

print(dir(Tom))
print(Tom._Student__name)
