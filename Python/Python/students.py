#I didn't write this lol
class Student:
    def __init__(self, name, age, grade):
        self.name = name
        self.age = age
        self.grade = grade # 0 - 100

    def getGrade(self):
        return self.grade

class Course:
    def __init__(self, subject, max_students):
        self.subject = subject
        self.max_students = max_students
        self.students = []

    def addStudent(self, student):
        if len(self.students) < self.max_students:
            self.students.append(student)
            return True
        return False

    def getAvgGrade(self):
        avgGrade = 0
        for student in self.students:
            avgGrade += student.getGrade()
        avgGrade /= len(self.students)
        return avgGrade

s1 = Student("Tim", 19, 95)
s2 = Student("Bill", 19, 75)
s3 = Student("Jill", 19, 65)

math = Course("Math", 2)
math.addStudent(s1)
math.addStudent(s2)
print("Average grade in Math:", math.getAvgGrade())