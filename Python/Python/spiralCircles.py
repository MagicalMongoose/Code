import turtle

#variables
numCircles = 36
radius = 100
offset = 10
angle = 0
animSpeed = 0 #0 is fastest
x = 0
y = 0

#setup
turtle.setup(500, 500)
turtle.hideturtle()
turtle.speed(animSpeed)
turtle.tracer(0,0)
turtle.penup()

for i in range(numCircles):
    turtle.setheading(angle)
    turtle.pendown()
    turtle.circle(radius)
    turtle.penup()
    angle += offset

turtle.done()