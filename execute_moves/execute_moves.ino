using namespace std;

int execute_moves(String moves_to_exec[]) {
  // put your main code here, to run repeatedly:
    Serial.println(moves_to_exec[0]);
  //read each move (tokenized by space only) into an array
  //for each input in the array, (there are a total of 3 * 6 18 possible values in the array to check)
  //check case, and execute move
  //return at the end of array as cube is solved. 

  delay(500);
  return 0;
}



void setup() {  
  delay(500);
  Serial.begin(9600);
  //highest value a solution can be
  int move_limit = 40;

  //listen to laptop to fill this variable's information out.
  char buf[] ="D2 R' D' F2 B D R2 D2 R' F2 D' F2 U' B2 L2 U2 D R2 U";
  int i = 0;
  char *p = strtok (buf, " ");

  char *array[move_limit] = {"A"};
  while (p != NULL)
  {
      array[i++] = p;
      p = strtok (NULL, " ");
  }
  for (i = 0; i < move_limit ; ++i) 
      Serial.println(array[i]);
}

void loop(){

}
