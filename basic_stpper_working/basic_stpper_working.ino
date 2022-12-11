#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define H 9
#define I 10
#define J 11
#define K 12
#define NUMBER_OF_STEPS_PER_REV 512

void setup(){
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(E,OUTPUT);
pinMode(F,OUTPUT);
pinMode(G,OUTPUT);
pinMode(H,OUTPUT);
pinMode(I,OUTPUT);
pinMode(J,OUTPUT);
pinMode(K,OUTPUT);


digitalWrite(E,1);
digitalWrite(F,1);
digitalWrite(G,1);
digitalWrite(H,1);
digitalWrite(I,1);
digitalWrite(J,1);
digitalWrite(K,1);
}

void write(int a,int b,int c,int d){
digitalWrite(A,a);
digitalWrite(B,b);
digitalWrite(C,c);
digitalWrite(D,d);
}

void onestep(){
write(1,0,0,0);

write(1,1,0,0);

write(0,1,0,0);

write(0,1,1,0);

write(0,0,1,0);

write(0,0,1,1);

write(0,0,0,1);

write(1,0,0,1);

}

void loop(){
int i;
i=0;
while(i<NUMBER_OF_STEPS_PER_REV){
onestep();
i++;
}
}