#ola107.py
#Due 3/31/21
#Written by Drew Lickman
#CSCI 1170-003
#Description: Write a program that lets the user play the game of Rock, Paper, Scissors against the computer.

import random

def intro(): #Introduce user to rock paper scissors
    print("This is Rock-Paper-Scissors")
    print("Rock beats scissors, paper beats rock, and scissors beats paper")
    
def get_comp_choice(): #Generate random number which will be converted to rock, paper, or scissors
    compChoice = random.randint(1,3)
    #print("COMP CHOICE IS", compChoice) #cheat mode
    return compChoice

def get_user_choice():
    gettingChoice = True
    while gettingChoice:
        choice = input("Rock, paper, or scissors? ")
        if choice == "rock" or choice == "paper" or choice == "scissors" or choice == "r" or choice == "p" or choice == "s":
            return choice_to_num(choice)
        else:
            print("Please type 'rock', 'paper', or 'scissors'")
    
def choice_to_num(choice): #Convert RPS to 123
    if choice == "rock" or choice == "r":
        return 1
    elif choice == "paper" or choice == "p":
        return 2
    elif choice == "scissors" or choice == "s":
        return 3
    
def num_to_choice(num): #Convert input number to text
    if num == 1:
        return "rock"
    elif num == 2:
        return "paper"
    elif num == 3:
        return "scissors"

def display_choices(comp_choice, user_choice): #Display what the computer and user chose, and then display the result
    num_to_choice(user_choice)
    print("I choose", num_to_choice(comp_choice))
    print("You chose", num_to_choice(user_choice))
    
    #Display result
    if user_choice == 1 and comp_choice == 3: #Rock beats paper
        print("You won!")
    elif comp_choice == 1 and user_choice == 3: #Rock beats paper
        print("I won, you lose")
    elif user_choice == comp_choice: #Same thing is tie
        print("It's a tie!")
    elif user_choice > comp_choice: #Paper beats rock (2 vs 1) and Scissors beats paper (3 vs 2)
        print("You won!")
    else:
        print("I won, you lose")
    
def keep_going(): #Loop the code if user wants to play again
    response = input("Do you want to play another game? y/n ")
    if response == "y" or response == "yes" or response == "Y" or response == "Yes":
        main()

def main():
    print("")
    display_choices(get_comp_choice(), get_user_choice())
    keep_going()

intro()
main()