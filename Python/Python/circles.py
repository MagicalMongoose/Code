import turtle

#variables
numCircles = 20
Radius = 20
offset = 10
animSpeed = 0 #0 is fastest
x = 0
y = 0

#setup
turtle.setup(500, 500)
turtle.speed(animSpeed)
turtle.tracer(True)
turtle.penup()
turtle.hideturtle()

for i in range(numCircles):
    turtle.pendown()
    turtle.circle(Radius)
    turtle.penup()
    Radius += offset
    y -= offset
    turtle.goto(x, y)

turtle.done()