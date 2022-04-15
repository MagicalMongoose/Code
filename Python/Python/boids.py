#Boids rules
#Separation: steer to avoid crowding local flockmates
#Alignment: steer toward the average heading of local flockmates
#Cohesion: steer to move toward the average position (center of mass) of local flockmates

import random
import math
from turtle import *

hideturtle()
roomSize = 400
animSpeed = 0
window = Screen()
window.bgcolor("white")
window.setup(roomSize, roomSize)
speed(animSpeed)
tracer(True)

class Boid:
    def __init__(self, boids):
        self.turtle = Turtle()
        self.x = randPos()
        self.y = randPos()
        self.direction = (random.random()*360)
        self.color = Boid.newColor(self)
        self.turtle.goto(self.x, self.y)
        self.number = len(boids)+1
        #self.turtle.hideturtle()
        #self.updatePosition()

    def newColor(self):
        c = random.randint(1,3)
        if c == 1:
            self.turtle.color("red")
            c += 1
        elif c == 2:
            self.turtle.color("green")
            c += 1
        elif c == 3: 
           self.turtle.color("blue")
           c = 1

    def updatePosition(self, boids):
        def distance(j):
            dist = math.sqrt( ((boids[j].getBoidX() - self.x)**2) + ((boids[j].getBoidY() - self.y)**2) )
            print("Distance from boid", self.number, "and boid", boids[j].number, "is", format(dist, ".2f"))
            return dist
        #This is where the algorithm would go
        #Separation:
        boidSize = 50
        done = False
        while not done:
            for i in range(len(boids)): #Turn this into a double For Loop so that it checks ALL other boids for each boid
                for j in range(i):
                    print("I:", i, " J:", j)
                    dist = distance(j)
                    #print(distance(i))
                    #if dist == 0.0:
                    #    pass
                    if (dist <= boidSize):
                        #print(i, dist)
                        #print(len(boids))
                        self.x = randPos()
                        self.y = randPos()
                        self.turtle.goto(self.x, self.y)
                        #i -= 1
                        j += 1
                        pass
                    else:
                        #print("Staying...", i, distance(i))
                        #self.turtle.forward(50)
                        self.x, self.y = self.turtle.position()
                        done = True
                        #i += 1
                        break
                    pass
            #i += 1
        done = False
        
        #Alignment:
        self.direction = (random.random()*360)
        self.turtle.setheading(self.direction)
        self.turtle.goto(self.x, self.y)
       #self.turtle.penup()
       #self.turtle.pendown()

    def printPosition(self, boidNum):
        print("Update position for boid", boidNum, self)
        print("X:", format(self.x, ".2f"), "Y:", format(self.y, ".2f"), "Direction:", format(self.direction, ".2f"))
        
    def getBoidX(self):
        return self.x
    
    def getBoidY(self):
        return self.y
    
    def getBoidDir(self):
        return self.direction

    def printPosition(self, boidNum):
        print("Update position for boid", boidNum, self)
        print("X:", format(self.x, ".2f"), "Y:", format(self.y, ".2f"), "Direction:", format(self.direction, ".2f"))

    def updatePosition(self, boids):
        def distance(thisX, thisY, thatX, thatY, radius):
            dist = math.sqrt( abs((thatX-thisX)+(thatY-thisY)) )
            print("Distance from boid", self.number, "and boid", other.number, "is", format(dist, ".2f"), end=" ")
            return dist

        #This is where the algorithm would go
        #Separation:
        boidSize = 10
        for other in boids:
            dist = distance(self.getBoidX(), self.getBoidY(), other.getBoidX(), other.getBoidY(), boidSize) 
            if other != self and dist < boidSize:
                print("moving to 0 0")
                self.x = randPos() 
                self.y = randPos()
                self.turtle.goto(self.x, self.y)
            else:
                print("spin")
                self.turtle.setheading(random.random()*360)

        #Alignment:
        def alignment():
            self.direction = (random.random()*360)
            self.turtle.setheading(self.direction)
            self.turtle.goto(self.x, self.y)
    

def randPos():
    randPos = (random.random()*(roomSize)-(roomSize/2))
    #print(randPos)
    return randPos

def main():
    print("\n\n\n\n\n\n\n\n")
    #Create numBoids boids
    numBoids = 3
    boids = []
    for i in range(numBoids):
        boids.append(Boid(boids))
        
    def printXYDir():   
        for i in range(numBoids):
            print(
            "Boid ", i+1, ":", sep="", end="")
            print(
            "X:", format((boids[i].getBoidX()), ".2f"),
            "Y:", format((boids[i].getBoidY()), ".2f"),
            "Direction:", format((boids[i].getBoidDir()), ".2f")
            )

    def moveSecond():
        for i in range(numBoids):
            boids[i].updatePosition(boids)
        #printXYDir()
        print("")
        window.ontimer(moveSecond)
    window.ontimer(moveSecond)
    
main()
#window.mainloop()
window.exitonclick()