#include <DHT.h>
#include <Servo.h>

#define DHTTYPE DHT11
#define DHTPIN 13

DHT dht(DHTPIN, DHTTYPE);
Servo S1;

const int tensDigitSegments[7] = {2, 3, 4, 5, 6, 7, 8};
const int unitsDigitSegments[7] = {9, 10, 11, 12, A0, A1, A2};

const int digits[10][7] = {
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

void displayDigit(int digit, const int segmentPins[]) {
    for (int i = 0; i < 7; i++) {
        digitalWrite(segmentPins[i], digits[digit][i] ? HIGH : LOW);
    }
}

void oscillateServo(int delayTime) {
    for (int pos = 0; pos <= 180; pos++) {
        S1.write(pos);
        delay(delayTime);
    }
    for (int pos = 180; pos >= 0; pos--) {
        S1.write(pos);
        delay(delayTime);
    }
}

void setup() {
    Serial.begin(9600);
    dht.begin();
    S1.attach(A3);
    Serial.println("Humidity and Temperature Monitoring");

    for (int i = 0; i < 7; i++) {
        pinMode(tensDigitSegments[i], OUTPUT);
        pinMode(unitsDigitSegments[i], OUTPUT);
    }
}

void loop() {
    // Read sensor values
    int humidity = dht.readHumidity();
    int temperature = dht.readTemperature();

    // Validate sensor readings
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // Display temperature on 7-segment
    int tensDigit = temperature / 10;
    int unitsDigit = temperature % 10;

    displayDigit(tensDigit, tensDigitSegments);
    displayDigit(unitsDigit, unitsDigitSegments);

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%, Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");

    // Map humidity to servo speed
    int delayTime = map(humidity, 35, 90, 50, 5); // Faster oscillation for higher humidity
    oscillateServo(delayTime);
    delay(1000);
}
