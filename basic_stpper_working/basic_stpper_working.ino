#define A 2
#define B 3
#define C 4
#define D 5
 

 //Mark it with the correst side up
#define NUMBER_OF_STEPS_PER_REV 512

void setup(){
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);


}

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

void loop(){

digitalWrite(6,HIGH);

int i;
i=0;
while(i<(NUMBER_OF_STEPS_PER_REV/4)){
onestep();
i++;
  }
delay(1000);

}