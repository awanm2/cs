# How to sort pairs

class Student:
    def __init__(self, name, grade, age) -> None:
        self.name = name
        self.grade = grade
        self.age = age
    def __repr__(self) -> str:
        '''
        returs object representation in string format
        '''    
        return repr((self.name, self.grade, self.age))


def test_student_sorting():
    student_objects = [Student('john', 'A', 15) , Student('jane', 'B', 12), Student('dave', 'B', 10)]
    print("Orignal student list")
    print(student_objects)
    # Now lets tell sorted what key to be used for sorting
    print("Students sorted by name")
    print(sorted(student_objects,  key = lambda student:student.name))
    print("Students sorted by grades")
    print(sorted(student_objects, key = lambda student :student.grade))
    print("Studens sorted by age")
    print(sorted(student_objects, key = lambda student: student.age))
    print("Studens sorted by age but in reverse order")
    print(sorted(student_objects, key = lambda student: student.age, reverse = True))



# https://docs.python.org/3/howto/sorting.html

if __name__ == '__main__':
    test_student_sorting()
    
    
