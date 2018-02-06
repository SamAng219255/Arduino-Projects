int iter=0;
int active=0;
int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9
void Num_Write(int number) {
  for (int j=0; j < 7; j++) {
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
  pinMode(13, OUTPUT);
  Num_Write(iter);
}

void loop() {
  int on=digitalRead(2);
  digitalWrite(13,on);
  if(on and !active) {
    iter++;
    iter%=10;
    Serial.println(iter);
    Num_Write(iter);
    delay(100);
  }
  if(on) {
    active=1;
  }
  else {
    active=0;
  }
}

