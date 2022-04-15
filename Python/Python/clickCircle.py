import turtle

radius = 100
multiplier = 8


screen = turtle.Screen()
screen.setup(radius*multiplier, radius*multiplier)
turtle.tracer(0, 0)
turtle.penup()
turtle.goto(turtle.xcor(), turtle.ycor()-(radius))
turtle.begin_fill()
#turtle.circle(radius)
turtle.end_fill()

def clicked(x, y):
    goto = turtle.goto(x, y-50)
    turtle.pendown()
    turtle.circle(100)
    return goto

screen.onscreenclick(clicked)
#screen.listen()





turtle.done()