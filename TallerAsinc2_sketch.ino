int potentiometerPin = A0;   // Analog pin for the potentiometer
int outputPins[] = {2, 3, 4}; // Output pins for Gray code bits

const int grayCode[] = {0, 1, 3, 2, 6, 7, 5, 4}; // Gray code mapping

void setup() {
    pinMode(outputPins[0], OUTPUT);
    pinMode(outputPins[1], OUTPUT);
    pinMode(outputPins[2], OUTPUT);
    Serial.begin(9600);
}

void updateOutput(int grayValue) {
    for (int i = 0; i < 3; i++) {
        int bitValue = (grayValue >> (2 - i)) & 1;
        digitalWrite(outputPins[i], bitValue);
    }
}

void loop() {
    int potentiometerValue = analogRead(potentiometerPin);
    int grayValue = grayCode[potentiometerValue / 128]; // Divide by 128 for 8 steps (1024 / 8 = 128)

    Serial.print("Analog: ");
    Serial.print(potentiometerValue);
    Serial.print(" | Gray: ");
    Serial.println(grayValue, BIN);

    updateOutput(grayValue);

    delay(100);


}
