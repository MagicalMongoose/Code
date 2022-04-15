import turtle

beeperPosX = 5
beeperPosY = 3

screen = turtle.Screen()



class Reeborg(self, x, y):
    def __init__(self, x, y):
        self.xPos = x
        self.yPos = y
        carryingBeeper = False

    #methods
    def move(self):
        turtle.self.forward()
    
    def turn_left(self):
        turtle.self.left(90)

    def pick_beeper(self):
        if carryingBeeper == False and (self.xPos == beeperPosX and self.yPos == beeperPosY):
            carryingBeeper = True

    def place_beeper(self):
        if carryingBeeper == True:
            carryingBeeper = False

Reeborg(0, 0)
screen.done()