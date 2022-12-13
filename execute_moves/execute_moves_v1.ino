#define A 2
#define B 3
#define C 4
#define D 5
 
//Mark it with the correst side up
#define NUMBER_OF_STEPS_PER_REV 512

void setup() {  
  Serial.begin(9600);
  while(!Serial);

  //Setting up motors
  pinMode(A,OUTPUT); 
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT); 
  pinMode(6,OUTPUT);  // Front motor
  pinMode(7,OUTPUT);  // Right motor
  pinMode(8,OUTPUT);  // Back motor
  pinMode(9,OUTPUT);  // Left motor
  pinMode(10,OUTPUT); // Up motor
  pinMode(11,OUTPUT); // Down motor
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
  digitalWrite(11,0);


  //listen to laptop to fill this variable's information out.
  char buf[] ="D2 R' D' F2 B D R2 D2 R' F2 D' F2 U' B2 L2 U2 D R2 U";
  execute_moves(buf);
}

// rotation function
// pin = motor to rotate, arg2 and arg3 may or may not exist
void rotate(int pin, char arg2, char arg3) {
  int times = 1;
  bool reverse = false;
  if (arg2 == '2') { // checking if move variable has '2' in it, indicating two rotations
    times = 2;
    if (arg3 == '\'') { //checking if move variable has ''' in it after a 2, indication reverse
      reverse = true;
    }
  }
  if (arg2 == '\'') { // checking if move variable has ' in it, indicating reverse
    reverse = true;
  }
  digitalWrite(pin, HIGH);
  int j=0;
  //perform the steps
  while(j<(NUMBER_OF_STEPS_PER_REV/(4/times))){
    if (!reverse) {
      onestep();
    }
    else {
      reverseOneStep();
    }
    j++;
  }
  digitalWrite(pin, 0);
}

void loop(){
}

int execute_moves(char moves_to_exec[]) {
  Serial.println(moves_to_exec[0]);
  //read each move (tokenized by space only) into an array
  //for each input in the array, (there are a total of 3 * 6 18 possible values in the array to check)
  //check case, and execute move
  //return at the end of array as cube is solved. 
  int i = 0;
  //highest value a solution can be
  int move_limit = 40;
  char *p = strtok(moves_to_exec, " ");

  char *moves[move_limit] = {"A"};
  while (p != NULL)
  {
      moves[i++] = p;
      p = strtok(NULL, " ");
  }

  for (i = 0; i < move_limit; ++i) {
    char *move = moves[i];
    switch(move[0]) 
    {
      case 'F': 
        rotate(6, move[1], move[2]);
        break;
      case 'R': 
        rotate(7, move[1], move[2]);
        break;
      case 'B':
        rotate(8, move[1], move[2]);
        break;
      case 'L':
        rotate(9, move[1], move[2]);
        break;
      case 'U':
        rotate(10, move[1], move[2]); 
        break;
      case 'D':
        rotate(11, move[1], move[2]);
        break;
      default: Serial.println("H");
    } 
  }

  return 0;
}

// Taken and modified from https://create.arduino.cc/projecthub/debanshudas23/getting-started-with-stepper-motor-28byj-48-3de8c9

void write(int a,int b,int c,int d){
  digitalWrite(A,a);
  digitalWrite(B,b);
  digitalWrite(C,c);
  digitalWrite(D,d);
}

void onestep(){
  write(1,0,0,0);
  delay(1);
  write(1,1,0,0);
  delay(1);
  write(0,1,0,0);
  delay(1);
  write(0,1,1,0);
  delay(1);
  write(0,0,1,0);
  delay(1);
  write(0,0,1,1);
  delay(1);
  write(0,0,0,1);
  delay(1);
  write(1,0,0,1);
  delay(1);
}

void reverseOneStep(){
  write(1,0,0,1);
  delay(1);
  write(0,0,0,1);
  delay(1);
  write(0,0,1,1);
  delay(1);
  write(0,0,1,0);
  delay(1);
  write(0,1,1,0);
  delay(1);
  write(0,1,0,0);
  delay(1);
  write(1,1,0,0);
  delay(1);
  write(1,0,0,0);
  delay(1);
}


