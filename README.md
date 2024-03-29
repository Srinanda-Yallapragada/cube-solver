# Cube-Solver

## Quick About
Course final project for CS335 at UMass Amherst during the Fall 2022 semester.
Created by Krisna Lach and Srinanda Yallapragada.

## Credits
cube_solver.py was NOT written by either of us. It was from Simon Massey. Github repository found here: 
https://github.com/simbo1905/CubieMoves
It requires additional files to be able to run, but they aren't included here for brevity sake.
A few tweaks have been made such that it would be usable in our project.

## Project Images

### Picture of demo scanning cube faces
![Picture of demo of scanning cube faces.](https://github.com/Srinanda-Yallapragada/cube-solver/blob/main/images/Image%20of%20capturing%20cube%20faces.jpg)

### Picture of the robot finished solving a cube
![Picture of the robot finished solving a cube.](https://github.com/Srinanda-Yallapragada/cube-solver/blob/main/images/Image%20of%20robot%20holding%20a%20solved%20cube.jpg)

## The Report
### 1. Description of what the project does. 
The project first uses a webcam and the cv2 library to take 6 images of each of the rubik’s cube sides. After saving the 6 images, it sends them to two separate algorithms (neither of which we wrote, cited later), one that translates the images into a string, and the second one that takes the string and outputs a solution string, which is the set of moves to perform to solve the cube. It writes this to the .ino file, which tells the motors to perform the set of moves. The motors connect to the cube with 3D printed arms that act as cube caps. Our hardware connected to the Arduino consists of 6 stepper motors connected to 6 motor drives. These are powered by an external power supply and we regulate the power with MOSFETs. Outputs are sent from the Arduino to the motors, and to make sure we had enough pins, we used enable pins to decide which motor to send data to. The biggest limitations of the project are that the image processing algorithm requires good photos, which is hard to always get consistently, and that the motor arms sometimes pop out of the cube when turning, which invalidates the whole solving process. Thus, the project is inconsistent and dependent on somewhat precise user input (proper photos, consistent insertion of cube arm into cube).

### 2. The development process
It should be prefaced that the All-Campus Makerspace was essential in the development of this project. The staff and volunteers were there to answer questions and guide us through things we didn’t know, and the tools (3D printing, woodworking) were invaluable. Special thanks to Shira, Andrew and Keegan in the makerspace! 

Srinanda: The first problem that we faced was that I did not have enough GPIO pins on the arduino to control all 6 stepper motors as each stepper motor needed 4 pins. The work around was to use 6 signal pins with MOSFETs which solved two problems (essentially making 6 enable pins similar to the logic labs in class). One, I could share one signal across all six stepper motors, and the second problem where the stepper motors would get a 5V power supply from an external power source instead of the board. This meant that the board would also be safe from getting burnt. After our first iteration of wiring everything in and building a structure of wood to hold the cube, we realized that the stepper motors were not strong enough to consistently turn each side of the cube. The steppers worked individually to turn each side, but once all six motors were in the encasing, they failed to turn the sides. While buying stronger stepper motors would have been a better solution, we did not have the time to wait for them to ship, and thus we solved the problem by using a 9V power supply instead (This has the drawback of reducing the stepper motors lifespan, but we needed it to last only till the demo so accepted the drawback). This allowed the motors to turn with more current and torque. We also realized that we didn't build our structure as sturdy as possible and some of the stepper motor's power was being absorbed by the loose stand, so we rectified that problem using hot glue. To build the second iteration of our wood structure, I used a table saw to cut the wood pieces precisely, and Krisna gave the brilliant idea to use velcro instead of screwing the structure in to give us the right balance of looseness so that we could pull the cube in and out, and stability when the cube was placed inside. Throughout the project, I also spent a lot of time trying to debug any wiring problems and placing resistors in certain locations to prevent floating signals from causing problems near the MOSFETs. 

Krisna:
The 3D printed cube arms went through 4 iterations, each improving upon the last. I learned how to design in CAD with openSCAD and to be precise with 3D printing. The build holding the motors went through two iterations. I designed the first in wood, but it turned out to be too inaccurate in measurements, which caused turning problems with the motors. Srinanda took over for the second iteration, which is what we went with. In terms of physical project development, this was the extent of what I did. For the software, I worked with the python cv2 library and code imported from Simon Massey’s CubieMoves (link here: simbo1905/CubieMoves: This project solves a Rubik's Cube using OpenCV libraries. (github.com)). The cv2 library was for taking the images, and required a fair amount of experimental calibration to get somewhat right. I used Srinanda’s webcam to take the photos. Massey’s code was fed the images and includes the two algorithms I explained above. I tweaked their code slightly; I removed all logging information and made it so the solution is written to the .ino instead of being printed out. Then, I had to write up the arduino code to process the moves. Lastly, I wrote a program that compiled all the steps to make things more seamless. This required the usage of the arduino-cli python library, which lets you compile and upload arduino code from python. 

### 3. What we learned from it. 
Srinanda:
I learnt how to use a lot of tools during this project ranging from woodworking to 3d printing. A key learning was how MOSFETs function, and then applying that to the wiring board to control the stepper motors as that saved us a lot of trouble. This project also taught me how to work within the limitations of what you have, as we could not easily buy enough stepper motors in time for our project, and we didn't have enough GPIO pins at the start. It took a bit of thinking, but we were able to work within our resources to make this project come to life. I also learnt about the Kociemba algorithm which is an algorithm that is used to calculate the least number of moves to solve a Rubik’s cube.

Krisna: 
Before going into the project, I had little to no knowledge of electronics and the microcontroller. Naturally, I learned a lot about the wiring necessary for stepper motors and how to use the microcontroller to control them. Through library usage and implementing code from others (Massey), I learned about the libraries themselves and how to integrate them and code I didn’t write. 

Both:
Perhaps what we learned most from though was the designing process. We had a lot of problems with simply coming up with ideas to meet requirements, like how to attach the motors to the cube, how to attach the motors to the wooden stands, how to attach the stands in such a way that they’re detachable, how to make things precise such that they don’t hinder motor rotation. We solved such issues through a lot of brainstorming and bouncing of ideas off each other. The biggest problem overall was the motors not having enough strength to turn. This was why we scrapped the first iteration of the cube build, and we also over-volted the motors. 

