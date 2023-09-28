uint16_t T_INTERVAL = 20;

uint32_t loop_time;

//Returns a boolean value to show if the time is later than a prior time interval
bool measurement(uint32_t t, uint32_t t0, uint16_t dt) {
  return ((t >= t0) && (t - t0 >= dt)) ||         // This section handles the normal case
            ((t < t0) && (t + (~t0) + 1 >= dt));  // If there is an overflow of data, handle the case
}
void setup() {
  Serial.begin(115200); // Set the Baud Rate
  
  loop_time = millis(); // Time since the code was started
}

void loop() {
  uint32_t t;
  uint16_t read_1, read_2, read_3, meas, min_read; // Initialize Voltage Variables

  t = millis();
  if (measurement(t, loop_time, T_INTERVAL)) {
    meas = 0;

    for (int i = 0; i <= 100; i++) { // Take 100 low readings and add them together
      read_1 = analogRead(0); // Average the readings
      read_2 = analogRead(0);
      read_3 = analogRead(0);

      min_read = min(min(read_1, read_2), read_3); // Take the lowest reading
      meas = meas + min_read; // Append the lowest reading
  }
    meas = meas/100; // Average the readings
    Serial.print(meas);
    Serial.println(meas); // Use the Serial Monitor to send the sensor data out


    loop_time = t;
  }
}