print()
optionprice = float(input("What is the price per option share? $"))
optionprice *= 100
strikeprice = float(input("What is the strike price? $"))
strikeprice *= optionprice
currentprice = float(input("How much is the stock worth now? $"))
currentprice *= optionprice
netprofit =  float(currentprice) - float(strikeprice) - float(optionprice)
print()
print("This call option would be worth $" + str(netprofit))