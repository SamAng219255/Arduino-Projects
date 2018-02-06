unsigned long previousmillis=0;
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
                          { 0,0,0,0,0,0,0,1 },    // .
                          { 1,0,0,1,0,0,1,0 },    // three bars
                          { 0,0,0,0,0,0,0,0 }};   // blank
void Num_Write(int number) {
  for (int j=0; j < 8; j++) {
   digitalWrite(j+5, num_array[number][j]);
  }
}
int iter=0;
int toindex(char income) {
  int outcome=39;
  if(income=='0') {
    outcome=0;
  }
  else if(income=='1') {
    outcome=1;
  }
  else if(income=='2') {
    outcome=2;
  }
  else if(income=='3') {
    outcome=3;
  }
  else if(income=='4') {
    outcome=4;
  }
  else if(income=='5') {
    outcome=5;
  }
  else if(income=='6') {
    outcome=6;
  }
  else if(income=='7') {
    outcome=7;
  }
  else if(income=='8') {
    outcome=8;
  }
  else if(income=='9') {
    outcome=9;
  }
  else if(income=='a' or income=='A') {
    outcome=10;
  }
  else if(income=='b' or income=='B') {
    outcome=11;
  }
  else if(income=='c' or income=='C') {
    outcome=12;
  }
  else if(income=='d' or income=='D') {
    outcome=13;
  }
  else if(income=='e' or income=='E') {
    outcome=14;
  }
  else if(income=='f' or income=='F') {
    outcome=15;
  }
  else if(income=='g' or income=='G') {
    outcome=16;
  }
  else if(income=='h' or income=='H') {
    outcome=17;
  }
  else if(income=='i' or income=='I') {
    outcome=18;
  }
  else if(income=='j' or income=='J') {
    outcome=19;
  }
  else if(income=='k' or income=='K') {
    outcome=20;
  }
  else if(income=='l' or income=='L') {
    outcome=21;
  }
  else if(income=='m' or income=='M') {
    outcome=22;
  }
  else if(income=='n' or income=='N') {
    outcome=23;
  }
  else if(income=='o' or income=='O') {
    outcome=24;
  }
  else if(income=='p' or income=='P') {
    outcome=25;
  }
  else if(income=='q' or income=='Q') {
    outcome=26;
  }
  else if(income=='r' or income=='R') {
    outcome=27;
  }
  else if(income=='s' or income=='S') {
    outcome=28;
  }
  else if(income=='t' or income=='T') {
    outcome=29;
  }
  else if(income=='u' or income=='U') {
    outcome=30;
  }
  else if(income=='v' or income=='V') {
    outcome=31;
  }
  else if(income=='w' or income=='W') {
    outcome=32;
  }
  else if(income=='x' or income=='X') {
    outcome=33;
  }
  else if(income=='y' or income=='Y') {
    outcome=34;
  }
  else if(income=='z' or income=='Z') {
    outcome=35;
  }
  else if(income=='-') {
    outcome=36;
  }
  else if(income=='.') {
    outcome=37;
  }
  else if(income=='=') {
    outcome=38;
  }
  else if(income==' ') {
    outcome=39;
  }
  return outcome;
}
void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}
long timesincelast=0;
int len=0;
int finallen=0;
char text[64];
char incomingByte = 0;
char finaltxt[64];
void loop() {
  int incoming=0;
        // send data only when you receive data:
        if (Serial.available() > 0) {
          incoming=1;
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                text[len]=incomingByte;
                len++;
        }
        timesincelast++;
        if(incoming) {
          timesincelast=0;
        }
        if(timesincelast==4000) {
          for(int i=0; i<len; i++) {
            Serial.print(text[i]);
            finaltxt[i]=text[i];
          }
          finallen=len+1;
          finaltxt[len]='=';
          len=0;
          iter=-1;
          Serial.println();
        }
  unsigned long currentmillis = millis();
  long delta=currentmillis-previousmillis;
  if(delta<400) {
    Num_Write(toindex(finaltxt[iter]));
  }
  if(delta>400) {
    Num_Write(39);
  }
  if(delta>1000) {
    previousmillis=currentmillis;
    iter++;
    iter%=finallen;
  }
}

