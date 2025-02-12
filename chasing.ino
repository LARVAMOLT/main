// Define RGB LED pins for 10 LEDs (each LED has 3 pins: R, G, B)
const int ledPins[10][3] = {
    {2, 3, 4},   // LED 1: Red, Green, Blue
    {5, 6, 7},   // LED 2: Red, Green, Blue
    {8, 9, 10},  // LED 3: Red, Green, Blue
    {11, 12, 13},// LED 4: Red, Green, Blue
    {A0, A1, A2},// LED 5: Red, Green, Blue
    {A3, A4, A5},// LED 6: Red, Green, Blue
    {A6, A7, 14},// LED 7: Red, Green, Blue
    {15, 16, 17},// LED 8: Red, Green, Blue
    {18, 19, 20},// LED 9: Red, Green, Blue
    {21, 22, 23} // LED 10: Red, Green, Blue
};

// Delay time between LED activations
const int chaseDelay = 150;  // Speed of the chase effect

void setup() {
    // Set all RGB LED pins as OUTPUT
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            pinMode(ledPins[i][j], OUTPUT);
        }
    }
}

void loop() {
    // Chasing pattern for Red, White, and Blue
    chaseColor(255, 0, 0);   // Red
    chaseColor(255, 255, 255); // White
    chaseColor(0, 0, 255);   // Blue
}

// Function to create a chasing effect with a specific color
void chaseColor(int red, int green, int blue) {
    for (int i = 0; i < 10; i++) {
        // Light up the current LED with the given color
        analogWrite(ledPins[i][0], red);
        analogWrite(ledPins[i][1], green);
        analogWrite(ledPins[i][2], blue);

        delay(chaseDelay);  // Wait for the chase effect

        // Turn off the LED before moving to the next one
        analogWrite(ledPins[i][0], 0);
        analogWrite(ledPins[i][1], 0);
        analogWrite(ledPins[i][2], 0);
    }
}