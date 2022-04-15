import turtle

#variables
numCircles = 36
radius = 200
angle = 0
animSpeed = 0 #0 is fastest
x = -100
y = 0

#setup
turtle.setup(500, 500)
turtle.hideturtle()
turtle.speed(animSpeed)
turtle.tracer(True)
turtle.penup()
turtle.goto(x, y)

for i in range(numCircles):
    turtle.setheading(angle)
    turtle.pendown()
    turtle.forward(radius)
    angle += 190


turtle.done()