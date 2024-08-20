void setup() {
  // Set baud rate for serial communication
  unsigned long baud = 9600;
  unsigned long ubrr = (F_CPU / 16 / baud) - 1;

  // Set baud rate registers
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)ubrr;

  // Enable receiver
  UCSR0B = (1 << RXEN0);

  // Set frame format: 8 data bits, 1 stop bit
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

  // Initialize serial monitor
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read
  if (UCSR0A & (1 << RXC0)) {
    char receivedData = receive();
    Serial.print("Received: ");
    Serial.println(receivedData);
  }
}

char receive() {
  // Wait for data to be received
  while (!(UCSR0A & (1 << RXC0)))
    ;

  // Get and return received data from buffer
  return UDR0;
}
