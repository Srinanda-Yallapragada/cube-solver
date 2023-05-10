import os
import time
from sys import exit

def print_instructions():
    print("To start, place the cube (with middle caps on) inside the square in front of the camera")
    time.sleep(1)
    print("There are 6 photos to take: F, R, B, L, U, D\n")
    time.sleep(1)
    print("Press any of the 6 keys on the keyboard to take the letter's photo")
    time.sleep(1)
    print("Instructions for each photo below. Orientation is VERY important, so follow instructions to the best of your ability.")
    time.sleep(1)
    print("F:\nFace the GREEN middle cap towards the camera, with the WHITE middle cap facing upwards")
    time.sleep(1)
    print("R:\nFace the RED middle cap towards the camera, with the WHITE middle cap facing upwards")
    time.sleep(1)
    print("B:\nFace the BLUE middle cap towards the camera, with the WHITE middle cap facing upwards")
    time.sleep(1)
    print("L:\nFace the ORANGE middle cap towards the camera, with the WHITE middle cap facing upwards")
    time.sleep(1)
    print("U:\nFace the WHITE middle cap towards the camera, with the BLUE middle cap facing upwards")
    time.sleep(1)
    print("D:\nFace the YELLOW middle cap towards the camera, with the GREEN middle cap facing upwards")
    time.sleep(1)


if __name__ == "__main__":
    print("Beginning cube face recognition...\n")
    print_instructions()

    ret = os.system('python3 cube_reader.py')
    if ret == 0: #Error checking
        print("Finished cube face recognition...")
    else:
        raise Exception("Error with the webcam. Something is terribly wrong. Try restarting.")

    time.sleep(1)

    print("Beginning solving algorithm...")
    ret = os.system("python3 cube_solver.py cube-faces") 
    if ret == 0: #Error checking
        print("Successfully finished generating solution")
    else:
        raise Exception("Error executing algorithm. Try restarting to application to retake images.")

    time.sleep(1)

    print("Beginning compilation of arduino code...")
    os.system("arduino-cli compile --fqbn arduino:mbed_nano:nano33ble sketch_nov30a.ino")
    print("Finished compilation of arduino code")

    wait = input("Please load the cube into the solver (Enter when finished)")

    time.sleep(1)

    print("Uploading code to arduino...")
    #may have to change the port
    os.system("arduino-cli upload -p COM9 --fqbn arduino:mbed_nano:nano33ble sketch_nov30a.ino")
    print("Finished uploading code, solving should begin.")