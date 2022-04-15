def main():
    board = []
    for y in range(4):
        for x in range(8):
            if x % 2 == 0:
                board.append(["Black"])
            else:
                board.append(["White"])
        for x in range(8,17):
            if x % 2 == 0:
                board.append(["White"])
            else:
                board.append(["Black"])
        
    for i in range(8):
        for j in range(8):
            print(i+1, j+1, board[j], end="")
        print("")
main()