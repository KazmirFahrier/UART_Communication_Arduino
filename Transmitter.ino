void setup() {
  // Set baud rate for serial communication
  unsigned long baud = 9600;
  unsigned long ubrr = (F_CPU / 16 / baud) - 1;

  // Set baud rate registers
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)ubrr;

  // Enable transmitter
  UCSR0B = (1 << TXEN0);

  // Set frame format: 8 data bits, 1 stop bit
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void loop() {
  // Transmit a character
  char data = 'A';
  transmit(data);

  // Wait for a second
  delay(1000);
}

void transmit(char data) {
  // Wait for the transmit buffer to be empty
  while (!(UCSR0A & (1 << UDRE0)))
    ;

  // Put data into buffer, sends the data
  UDR0 = data;
}
