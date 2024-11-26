#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN 13
DHT dht(DHTPIN, DHTTYPE);

// Pins for tens and units digits
const int tensDigitSegments[7] = {2, 3, 4, 5, 6, 7, 8};  // Pins for tens place
const int unitsDigitSegments[7] = {9, 10, 11, 12, A0, A1, A2}; // Pins for units place

// Digit segment patterns (1 for ON, 0 for OFF)
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

// Function to display a digit on a specified set of segments
void displayDigit(int digit, const int segmentPins[]) 
{
  for (int i = 0; i < 7; i++) 
  {
    digitalWrite(segmentPins[i], digits[digit][i] ? HIGH : LOW);
  }
}

// Setup function
void setup() 
{
  Serial.begin(9600);
  dht.begin();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  
  // Set all segment pins as OUTPUT
  for (int i = 0; i < 7; i++) 
  {
    pinMode(tensDigitSegments[i], OUTPUT);
    pinMode(unitsDigitSegments[i], OUTPUT);
  }
}

// Main loop
void loop() 
{
  short humidity = dht.readHumidity();
  short temp = dht.readTemperature();
  
  Serial.print("HUMIDITY = ");
  Serial.print(humidity);
  Serial.print("\t\tTEMPERATURE = ");
  Serial.print(temp);
  Serial.println("°C");

  // Extract tens and units digits
  int tensDigit = temp / 10;  // Tens place
  int unitsDigit = temp % 10;  // Units place

  // Display the digits
  displayDigit(tensDigit, tensDigitSegments);  // Display tens digit
  delay(2000); // Hold the display for tens digit

  displayDigit(unitsDigit, unitsDigitSegments);  // Display units digit
  delay(2000); // Hold the display for units digit
}
