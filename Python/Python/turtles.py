import turtle
import math
import random

edge = 350
screen = turtle.Screen()
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
    
def testEdges(self, turtle): #edge cases
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
        self.dX = random.randint(-(maxMovement), maxMovement)
        self.dY = random.randint(-(maxMovement), maxMovement)
        self.count += 1 

    def dist2Mid(self):
        return math.sqrt(((self.tX)**2)+((self.tY)**2))

    def gravity(self):
        if self.tX > 0:
            self.dX -= 1/(Turtle.dist2Mid(self)*0.01)
        elif self.tX < 0:
            self.dX += 1/(Turtle.dist2Mid(self)*0.01)
        if self.dY > 0:
            self.dY += 1/(Turtle.dist2Mid(self)*0.01)
        elif self.dY < 0:
            self.dY -= 1/(Turtle.dist2Mid(self)*0.01)

#main
def main(self, color):
    self.tX += self.dX
    self.tY += self.dY
    Turtle.gravity(self)
    self.turtle.color(color)
    #self.turtle.penup()              #comment this to show lines 
    self.turtle.goto(self.tX, self.tY)
    
    self.turtle.pendown() 
    turtle.dot()
    testEdges(self, self) 
    turtle.update()
    

color = [0, 0, 0]
def newColor():
    color[0] = (randRGB(), randRGB(), randRGB())
    Turtle.count += 1

color0 = (randRGB(), randRGB(), randRGB())
color1 = (randRGB(), randRGB(), randRGB())  
color2 = (randRGB(), randRGB(), randRGB())  
color3 = (randRGB(), randRGB(), randRGB())  

turt = []
def newTurt():
    turt.append(Turtle(turtle, randPos(), randPos()))
    #main(turt[0], color2)

turtle.tracer(0, 0)
for i in range(1000):
    try:
        newTurt()
        newColor()
        main(turt[0], color0)
        newTurt()
        main(turt[1], color1) #turtle is accessing tX-dY for t1 which ends up drawing an <
        #newTurt()
        #main(turt[2], color2)
        #newTurt()
        #main(turt[3], color3)
        #main(turt[5])
        #main(turt[6])
        #main(turt[7])
        #main(turt[8])
        #main(turt[9])
    except IndexError:
        print("NOT ENOUGH TURTLES!")

turtle.done()