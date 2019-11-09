class ShiftRegister {

 int pin_serial;
 int pin_sr_clock;
 int pin_reg_clock;
 int hold_time;

public:

 ShiftRegister(int pin_serial, int pin_sr_clock, int pin_reg_clock, int hold_time /*in ms*/ = 1) {
  this->pin_serial = pin_serial;
  this->pin_sr_clock = pin_sr_clock;
  this->pin_reg_clock = pin_reg_clock;
  this->hold_time = hold_time;
  
  pinMode(pin_serial, OUTPUT);
  digitalWrite(pin_serial, LOW);
  pinMode(pin_sr_clock, OUTPUT);
  digitalWrite(pin_sr_clock, LOW);
  pinMode(pin_reg_clock, OUTPUT);
  digitalWrite(pin_sr_clock, LOW);
 }

 ~ShiftRegister() {}

private:

 template<typename T>
 void output(T data) {
  int bits = sizeof(T) * 8;

  for (int pos = 0; pos < bits; ++pos) {
    digitalWrite(pin_serial, data & 0x01 ? HIGH : LOW);
    data >>= 1;
    digitalWrite(pin_sr_clock, HIGH);
    delay(hold_time);
    digitalWrite(pin_sr_clock, LOW);
    digitalWrite(pin_serial, LOW);
  }

  digitalWrite(pin_reg_clock, HIGH);
  delay(hold_time);
  digitalWrite(pin_reg_clock, LOW);
 }

public:

 void write_byte(byte data) {
  output(data);
 }
};
