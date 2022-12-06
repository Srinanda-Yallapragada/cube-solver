import kociemba

#Gets user input of the state of one side of the cube
def get_side(center_color):
           
    #gather the input for the U side of the cube. The U side has a white center piece.
    return_side = input("List the colors on the" + center_color + "side in caps with no spaces: ")
    # Converts the side to a format that the kociemba algorithm can take as an input
    return_side = return_side .replace("W","U").replace("Y","D").replace("R","R").replace("O","L").replace("G","F").replace("B","B")
    return return_side

def main():

#R2 U' B2 L2 U B2 U2 B2 D' R2 U2 R F L2 D2 F R D U2 B

    print("While giving the inputs below, make sure the white center is facing the top!, For the yellow center, make sure that yellow center is facing up and the blue center is facing you, for the white ")
    W_U_side = get_side("white center")
    G_F_side = get_side("green center")
    R_R_side = get_side("red center")
    Y_D_side = get_side("yellow center")
    O_L_side = get_side("orange center")
    B_B_side = get_side("blue center")


    #The order is relevant, koceimba takes up, right front down left back
    kociemba_input = W_U_side+R_R_side+G_F_side+Y_D_side+O_L_side+B_B_side
    print(kociemba_input)
    print(kociemba.solve(kociemba_input))

if __name__ == '__main__':
    main()