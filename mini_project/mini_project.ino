#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN 13
DHT dht(DHTPIN, DHTTYPE);

const int segA = 2;
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;

const int digits[10][7] = 
{
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};

void displayDigitZero() 
{
  digitalWrite(segA, HIGH);    // Segment A on
  digitalWrite(segB, HIGH);    // Segment B on
  digitalWrite(segC, HIGH);    // Segment C on
  digitalWrite(segD, HIGH);    // Segment D on
  digitalWrite(segE, HIGH);    // Segment E on
  digitalWrite(segF, HIGH);    // Segment F on
  digitalWrite(segG, LOW);     // Segment G off
}

void displayDigitOne() 
{
  digitalWrite(segA, LOW);    // Segment A off
  digitalWrite(segB, HIGH);   // Segment B on
  digitalWrite(segC, HIGH);   // Segment C on
  digitalWrite(segD, LOW);    // Segment D off
  digitalWrite(segE, LOW);    // Segment E off
  digitalWrite(segF, LOW);    // Segment F off
  digitalWrite(segG, LOW);    // Segment G off
}

void displayDigitTwo() 
{
  digitalWrite(segA, HIGH);     // Segment A on
  digitalWrite(segB, HIGH);     // Segment B on
  digitalWrite(segC, LOW);      // Segment C off
  digitalWrite(segD, HIGH);     // Segment D on
  digitalWrite(segE, HIGH);     // Segment E on
  digitalWrite(segF, LOW);      // Segment F off
  digitalWrite(segG, HIGH);     // Segment G on
}

void displayDigitThree() 
{
  digitalWrite(segA, HIGH);     // Segment A on
  digitalWrite(segB, HIGH);     // Segment B on
  digitalWrite(segC, HIGH);     // Segment C on
  digitalWrite(segD, HIGH);     // Segment D on
  digitalWrite(segE, LOW);      // Segment E off
  digitalWrite(segF, LOW);      // Segment F off
  digitalWrite(segG, HIGH);     // Segment G on
}

void displayDigitFour() 
{
  digitalWrite(segA, LOW);      // Segment A off
  digitalWrite(segB, HIGH);     // Segment B on
  digitalWrite(segC, HIGH);     // Segment C on
  digitalWrite(segD, LOW);      // Segment D off
  digitalWrite(segE, LOW);      // Segment E off
  digitalWrite(segF, HIGH);     // Segment F on
  digitalWrite(segG, HIGH);     // Segment G on
}

void displayDigitFive() 
{
  digitalWrite(segA, HIGH);      // Segment A on
  digitalWrite(segB, LOW);       // Segment B off
  digitalWrite(segC, HIGH);      // Segment C on
  digitalWrite(segD, HIGH);      // Segment D on
  digitalWrite(segE, LOW);       // Segment E off
  digitalWrite(segF, HIGH);      // Segment F on
  digitalWrite(segG, HIGH);      // Segment G on
}

void displayDigitSix() 
{
  digitalWrite(segA, HIGH);       // Segment A on
  digitalWrite(segB, LOW);        // Segment B off
  digitalWrite(segC, HIGH);       // Segment C on
  digitalWrite(segD, HIGH);       // Segment D on
  digitalWrite(segE, HIGH);       // Segment E on
  digitalWrite(segF, HIGH);       // Segment F on
  digitalWrite(segG, HIGH);       // Segment G on (all segments lit)
}

void displayDigitSeven() 
{
  digitalWrite(segA, HIGH);        // Segment A on 
  digitalWrite(segB, HIGH);        // Segment B on 
  digitalWrite(segC, HIGH);        // Segment C on 
  digitalWrite(segD, LOW);       // Segment D off 
  digitalWrite(segE, LOW);       // Segment E off 
  digitalWrite(segF, LOW);       // Segment F off 
  digitalWrite(segG, LOW);       // Segment G off 
}

void displayDigitEight() 
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void displayDigitNine() 
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void setup()
{
  Serial.begin(9600);
  dht.begin();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  // Set pins as OUTPUT for each seg
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
}


void loop()
{
  short humidity = dht.readHumidity();
  short temp = dht.readTemperature();
  Serial.print("HUMIDITY = ");
  Serial.print(humidity );
  Serial.print("\t\t");
  
  Serial.print("TEMPERATURE = ");
  Serial.print(temp);
  Serial.print("% *c");
  Serial.print("\n");

  // int analogValue = analogRead(A0);
  // float voltage = analogValue * (5.0 / 1023.0); // Convert analog value to voltage
  
  // Serial.print("Analog Value: ");
  // Serial.print(analogValue);
  // Serial.print(" Voltage: ");
  // Serial.print(voltage);
  
  // float temp = voltage * 100; // Convert voltage to temperature in Celsius
  // Serial.print(" Temperature: ");
  // Serial.print(temp);
  // Serial.println(" °C");

  int digit = static_cast<int>(temp);
  if (digit < 0 || digit > 100) 
  {
    digit = 0;
  }
  int tensDigit = digit / 10;  // Tens place (integer division)
  Serial.print("Tens Digit = ");
  Serial.print(tensDigit);
  Serial.print("\t\t");

  switch(tensDigit)
  {
  case 0:
    displayDigitZero();
    break;
  case 1:
    displayDigitOne();
    break;
  case 2:
    displayDigitTwo();
    break;
  case 3:
    displayDigitThree();
    break;
  case 4:
    displayDigitFour();
    break;
  case 5:
    displayDigitFive();
    break;
  case 6:
    displayDigitSix();
    break;
  case 7:
    displayDigitSeven();
    break;
  case 8:
    displayDigitEight();
    break;
  case 9:
    displayDigitNine();
    break;
  default:
    break;
  }

  int unitsDigit = digit % 10;  // Tens place (integer division)
  Serial.print("Units Digit = ");
  Serial.print(unitsDigit);
  Serial.print("\n");

  switch(unitsDigit)
  {
  case 0:
    displayDigitZero();
    break;
  case 1:
    displayDigitOne();
    break;
  case 2:
    displayDigitTwo();
    break;
  case 3:
    displayDigitThree();
    break;
  case 4:
    displayDigitFour();
    break;
  case 5:
    displayDigitFive();
    break;
  case 6:
    displayDigitSix();
    break;
  case 7:
    displayDigitSeven();
    break;
  case 8:
    displayDigitEight();
    break;
  case 9:
    displayDigitNine();
    break;
  default:
    break;
  }
  delay(3000);
}


