#include <LiquidCrystal.h>

// LCD
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// HC-SR04
const int trigPin = 6;
const int echoPin = 7;

// Botao
const int buttonPin = 8;

// LED de escavacao
const int ledEscavacao = 13;

enum Estado {
  SENSOR,
  ESCAVADO
};

Estado estadoAtual = SENSOR;

// Variaveis do sensor
long duration;
float distance;

// Controle da escavacao
bool escavando = false;
bool escavada = false;

int profundidadeAtual = 0;

void setup()
{
  lcd_1.begin(16, 2);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(ledEscavacao, OUTPUT);
  digitalWrite(ledEscavacao, LOW);

  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Coventina");

  lcd_1.setCursor(0, 1);
  lcd_1.print("Ligado");

  delay(2000);
}

void loop()
{
  
  if (estadoAtual == ESCAVADO)
{
  lcd_1.setCursor(0,0);
  lcd_1.print("Escavacao Feita   ");

  lcd_1.setCursor(0,1);
  lcd_1.print("Prof:100 cm    ");

  if (digitalRead(buttonPin) == LOW)
  {
    delay(200);

    retrairEscavadeira();

    estadoAtual = SENSOR;
  }

  return;
}
  // Verifica botao
 static bool ultimoEstadoBotao = HIGH;

bool estadoAtual = digitalRead(buttonPin);

if (ultimoEstadoBotao == HIGH && estadoAtual == LOW && !escavando)
{
  if (!escavada)
  {
    iniciarEscavacao();
  }
  else
  {
    retrairEscavadeira();
  }
}

ultimoEstadoBotao = estadoAtual;

  // Sensor ultrassonico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.0343 / 2;

  lcd_1.clear();

  lcd_1.setCursor(0, 0);
  lcd_1.print("Dist:");
  lcd_1.print(distance, 1);
  lcd_1.print("cm");

  lcd_1.setCursor(0, 1);

  if (distance <= 20)
  {
    lcd_1.print("!!! PERIGO !!!");
  }
  else if (distance <= 35)
  {
    lcd_1.print("!! CUIDADO !!");
  }
  else if (distance <= 50)
  {
    lcd_1.print("! ATENCAO !");
  }
  else
  {
    lcd_1.print("CAMINHO LIVRE");
  }

  delay(250);
}

void iniciarEscavacao()
{
  escavando = true;

  digitalWrite(ledEscavacao, HIGH);

  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Iniciando");

  lcd_1.setCursor(0, 1);
  lcd_1.print("Escavacao");

  delay(3000);

  for (int p = profundidadeAtual; p <= 100; p++)
  {
    profundidadeAtual = p;

    lcd_1.clear();

    lcd_1.setCursor(0, 0);
    lcd_1.print("Cavando...");

    lcd_1.setCursor(0, 1);
    lcd_1.print("Prof:");
    lcd_1.print(profundidadeAtual);
    lcd_1.print("cm");

    delay(40);
  }

  estadoAtual = ESCAVADO;
  escavada = true;
  escavando = false;
}

void retrairEscavadeira()
{
  escavando = true;

  digitalWrite(ledEscavacao, HIGH);

  for (int p = profundidadeAtual; p >= 0; p--)
  {
    profundidadeAtual = p;

    lcd_1.clear();

    lcd_1.setCursor(0, 0);
    lcd_1.print("Retraindo");

    lcd_1.setCursor(0, 1);
    lcd_1.print("Prof:");
    lcd_1.print(profundidadeAtual);
    lcd_1.print("cm");

    delay(40);
  }

  lcd_1.clear();

  lcd_1.setCursor(0, 0);
  lcd_1.print("Escavadeira");

  lcd_1.setCursor(0, 1);
  lcd_1.print("Recolhida");

  delay(3000);

  digitalWrite(ledEscavacao, LOW);

  profundidadeAtual = 0;
  escavada = false;
  escavando = false;
}
