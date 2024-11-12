int botonA = A0;
int botonB = A1;
int botonC = A2;
int botonD = A3;
int boton1 = A4;
int boton2 = A5;

// 13
int ledA = 8;
int ledB = 2;
int ledC = 12;
int ledD = 4;
int ledE = 5;
int ledF = 6;
int ledG = 10;
int ledSuma = 13;
int ledResta = 11;
int ledMultiplicacion = 3;
int ledDivision = 7;

const int segmentos[16][7] = {
  {LOW, LOW, LOW, LOW, LOW, LOW, HIGH},  // 0
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},  // 1
  {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW},  // 2
  {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW},  // 3
  {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW},  // 4
  {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW},  // 5 //
  {LOW, HIGH, LOW, LOW, LOW, LOW, LOW},  // 6  //
  {LOW, LOW, LOW, HIGH, HIGH, HIGH, LOW},  // 7 //
  {LOW, LOW, LOW, LOW, LOW, LOW, LOW},  // 8 //
  {LOW, LOW, LOW, LOW, HIGH, LOW, LOW},  // 9  //
  {LOW, LOW, LOW, HIGH, LOW, LOW, LOW},  // 10 //
  {HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},  // 11 /
  {LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH},  // 12 /
  {HIGH, LOW, LOW, LOW, LOW, HIGH, LOW},  // 13 /
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},  // 14 /
  {LOW, HIGH, HIGH, HIGH, LOW, LOW, LOW}   // 15 /
};

void setup() {
  inicializacion();
}

void loop() {
  int estadoA = digitalRead(botonA);
  int estadoB = digitalRead(botonB);
  int estadoC = digitalRead(botonC);
  int estadoD = digitalRead(botonD);
  
  Visual(estadoA,estadoB,estadoC,estadoD);

  int index = (estadoA << 3) | (estadoB << 2) | (estadoC << 1) | estadoD;  // Convierte estados a un índice binario
  metodo(index);
}

void metodo(int index) {
  digitalWrite(ledA, segmentos[index][0]);
  digitalWrite(ledB, segmentos[index][1]);
  digitalWrite(ledC, segmentos[index][2]);
  digitalWrite(ledD, segmentos[index][3]);
  digitalWrite(ledE, segmentos[index][4]);
  digitalWrite(ledF, segmentos[index][5]);
  digitalWrite(ledG, segmentos[index][6]);
  delay(400);
}

void Visual(int a,int b,int c ,int d){
  Serial.print(a);
  Serial.print(b);
  Serial.print(c);
  Serial.println(d);
  delay(400);
}
void inicializacion() {
  pinMode(botonA, INPUT);
  pinMode(botonB, INPUT);
  pinMode(botonC, INPUT);
  pinMode(botonD, INPUT);
  //new
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);

  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  // new
  pinMode(ledSuma, OUTPUT);
  pinMode(ledResta, OUTPUT);
  pinMode(ledMultiplicacion, OUTPUT);
  pinMode(ledDivision, OUTPUT);

  Serial.begin(9600);
}
