class Student(object):
    def __init__(self, name, score):
        self.name = name
        self.score = score

    def print_score(self):
        print('%s:%s' % (self.name, self.score))

Tom = Student('Tom', 56)
Jack = Student('Jack', 99)

Tom.print_score()
Jack.print_score()
