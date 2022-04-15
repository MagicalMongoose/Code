import turtle
import math
import random

edge = 350
screen = turtle.Screen()
screen.title("Spinning Cube")
screen.setup(edge*2, edge*2)
screen.clear()
screen.colormode(255)
turtle.hideturtle()
turtle.speed(0)
maxMovement = 5

def randRGB(): #color randomizer :D
    RGB = int((random.random()*255))
    return RGB

def randPos():
    return random.randint(-edge, edge)
    
def testEdges(self, turtle): #edge cases     #testEdges(self, self)
    if self.turtle.xcor() <= -edge or self.turtle.xcor() >= edge:  #these seem to only account for the bottom right position
        turtle.dX = -(turtle.dX)
    elif self.turtle.ycor() <= -edge or self.turtle.ycor() >= edge:      
        turtle.dY = -(turtle.dY)

class Turtle():
    count = 0

    def __init__(self, turtle, tX, tY):
        self.turtle = turtle
        self.tX = tX
        self.tY = tY
        self.dX = 0
        self.dY = 0
        self.count += 1 

    def transform(self, dX, dY):
        for i in range(1):
            if self == turt[0] or self == turt[7]:
                self.dX = dX + 10
            elif self == turt[2] or self == turt[5]:
                self.dX = dX - 10
            else: 
                self.dX = dX
                self.dY = dY
        for i in range(1):
            if self == turt[0] or self == turt[7]:
                self.dY = dY - 10
            elif self == turt[2] or self == turt[5]:
                self.dY = dY + 10
            else: 
                self.dX = dX
                self.dY = dY
        main(self, color)

    def transform2(self, dX, dY):
        for i in range(1):
            if self == turt[0] or self == turt[7]:
                self.dX = dX + 10
            elif self == turt[2] or self == turt[5]:
                self.dX = dX - 10
            else: 
                self.dX = dX
                self.dY = dY
        for i in range(1):
            if self == turt[0] or self == turt[7]:
                self.dY = dY + 10
            elif self == turt[2] or self == turt[5]:
                self.dY = dY - 10
            else: 
                self.dX = dX
                self.dY = dY
        main(self, color)

#main
def main(self, color):
    self.tX += self.dX
    self.tY += self.dY
    self.turtle.color(color)
    #self.turtle.penup()              #comment this to show lines
    
    self.turtle.goto(self.tX, self.tY)
    self.turtle.pendown() 
    turtle.dot()
    #turtle.update()
    
    
color = [0, 0, 0]
def newColor():
    color[0] = (randRGB(), randRGB(), randRGB())
    Turtle.count += 1

color0 = (randRGB(), randRGB(), randRGB()) #i couldn't figure out how to return 3 numbers as input to main()
color1 = (randRGB(), randRGB(), randRGB())  
color2 = (randRGB(), randRGB(), randRGB())  
color3 = (randRGB(), randRGB(), randRGB())  
color4 = (randRGB(), randRGB(), randRGB())  
color5 = (randRGB(), randRGB(), randRGB())  
color6 = (randRGB(), randRGB(), randRGB())  
color7 = (randRGB(), randRGB(), randRGB())  

turt = []
def newTurt():
    turt.append(Turtle(turtle, randPos(), randPos()))
    #main(turt[0], color2)

def start():
    turtle.tracer(1, 0) #draws without animation
    for i in range(1):
        try: #8 turtles for 8 vertices
            turt.append(Turtle(turtle, -250, 150))
            main(turt[0], color0)

            turt.append(Turtle(turtle, 0, 300))
            main(turt[1], color1)

            turt.append(Turtle(turtle, 250, 150))
            main(turt[2], color2)

            turt.append(Turtle(turtle, 0, 0))
            main(turt[3], color3)

            turt.append(Turtle(turtle, 0, -300))
            main(turt[4], color4)

            turt.append(Turtle(turtle, 250, -150))
            main(turt[5], color5)

            turt.append(Turtle(turtle, 0, 0))
            main(turt[6], color6)

            turt.append(Turtle(turtle, -250, -150))
            main(turt[7], color7)
        except IndexError:
            print("NOT ENOUGH TURTLES!")

while True:
    #first half of spin
    for i in range(3):
        for turtles in turt:
            turtle.clear()
            for i in range(len(turt)):
                Turtle.transform(turt[i], 0, 0)
    #second half of spin
    for i in range(3):
        for turtles in turt:
            turtle.clear()
            for i in range(len(turt)):
                Turtle.transform2(turt[i], 0, 0)

    #reset to beginning to make illusion of rotation
    turt = []
    start()

turtle.done()
