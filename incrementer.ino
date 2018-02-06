const int first=10;
const int last=36;

int iter=0;
int active=0;
int reaction=0;
int num_array[40][8] = {  { 1,1,1,1,1,1,0,0 },    // 0
                          { 0,1,1,0,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1,0 },    // 2
                          { 1,1,1,1,0,0,1,0 },    // 3
                          { 0,1,1,0,0,1,1,0 },    // 4
                          { 1,0,1,1,0,1,1,0 },    // 5
                          { 1,0,1,1,1,1,1,0 },    // 6
                          { 1,1,1,0,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1,0 },    // 8
                          { 1,1,1,0,0,1,1,0 },    // 9
                          { 1,1,1,0,1,1,1,0 },    // A
                          { 0,0,1,1,1,1,1,0 },    // b
                          { 1,0,0,1,1,1,0,0 },    // C
                          { 0,1,1,1,1,0,1,0 },    // d
                          { 1,0,0,1,1,1,1,0 },    // E
                          { 1,0,0,0,1,1,1,0 },    // F
                          { 1,0,1,1,1,1,0,0 },    // G
                          { 0,1,1,0,1,1,1,0 },    // H
                          { 0,1,1,0,0,0,0,0 },    // I
                          { 0,1,1,1,1,0,0,0 },    // J
                          { 0,1,1,0,1,1,1,0 },    // K
                          { 0,0,0,1,1,1,0,0 },    // L
                          { 1,1,1,0,1,1,0,1 },    // M
                          { 0,0,1,0,1,0,1,0 },    // n
                          { 0,0,1,1,1,0,1,0 },    // o
                          { 1,1,0,0,1,1,1,0 },    // P
                          { 1,1,1,1,1,1,0,1 },    // Q
                          { 0,0,0,0,1,0,1,0 },    // r
                          { 1,0,1,1,0,1,1,0 },    // S
                          { 1,0,0,0,1,1,0,0 },    // T
                          { 0,0,1,1,1,0,0,0 },    // u
                          { 0,1,1,1,1,1,0,0 },    // V
                          { 0,1,1,1,1,1,1,1 },    // W
                          { 0,1,1,0,1,1,1,1 },    // X
                          { 0,1,1,1,0,1,1,0 },    // y
                          { 1,1,0,1,1,0,1,1 },    // Z
                          { 0,0,0,0,0,0,1,0 },    // -
                          { 0,1,1,0,1,1,0,0 },    // 11
                          { 1,0,0,1,0,0,1,0 },    // three bars
                          { 0,0,0,0,0,0,0,0 }};   // blank
void Num_Write(int number) {
  for (int j=0; j < 8; j++) {
   digitalWrite(j+5, num_array[number][j]);
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  //pinMode(13, OUTPUT);
  Num_Write(iter+first);
}

void loop() {
  int on=digitalRead(2);
  //digitalWrite(13,on);
  if(reaction==4000) {
    reaction=0;
    if(on and !active) {
      reaction=0;
      iter++;
      iter%=(last-first);
      Serial.println(iter+first);
      Num_Write(iter+first);
      //delay(200);
    }
    if(on) {
      active=1;
    }
    else {
      active=0;
    }
  }
  else {
    if((on and !active) or (!on and active)) {
      reaction++;
    }
  }
}
