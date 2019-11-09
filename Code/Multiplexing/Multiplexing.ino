/*
  Oct 2019
  Displaying Numbers onto a 4x 8 Segment Display

*/

/*
      a
    -----
    |    |
  f | g  | b
    ------
    |    |
  e |    | c
    ------
      d     . dp

  PINOUT OF SEGMENT DISPLAY

  D1 a f D2 D3 b

  e d dp c g D4

  D1-4 is annode (which segment you are writing to)
  a - g & dp is kathode
*/

// Digital Pins
#define PIN_A 1
#define PIN_B 1
#define PIN_C 1
#define PIN_D 1
#define PIN_E 1
#define PIN_F 1
#define PIN_G 1

// Digital Pins
#define PIN_D1 1
#define PIN_D2 1
#define PIN_D3 1
#define PIN_D4 1

// Textual Character Representation you write to the display.
char writer[4];

void set_display_content(char (&data)[4]) {

  for (unsigned int i = 0; i < 4; ++i) {

    if (data[i] >= (char)48 && data[i] <= (char)57) {
      writer[i] = '0';
    } else {
      writer[i] = data[i];
    }
  }
}

void print_display() {

  int pins[4]{PIN_D1, PIN_D2, PIN_D3, PIN_D4};

  // Reset all Pins to ground (annode pulled low)
  // So all segments are disabled
  for (int i = 0; i < 4; ++i) {
    digitalWrite(pin[i], LOW);
  }

  // Each segment is configured individually per display block.
  for (int i = 0; i < 4; ++i) {

    // Enable anode
    digitalWrite(pin[i], HIGH);

    // Set kathodes for each display method.
    switch(writer[i]) {
      case '0': // a b c d e f
        break;
      case '1': // b c
        break;
      case '2': // a b d e g
        break;
      case '3': // a b c d g
        break;
      case '4': // b c g f
        break;
      case '5': // a c d f g
        break;
      case '6': // a c d e f g
        break;
      case '7': // a b c
        break;
      case '8': // a b c d e f g
        break;
      case '9': // a b c d f g
        break;
      // TODO: A B C D E & F for hex display
    }

    digitalWrite(pin[i], LOW);
  }
  
}

void setup() {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
