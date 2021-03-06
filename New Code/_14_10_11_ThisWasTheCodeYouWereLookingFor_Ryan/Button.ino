class Button {
private:
  int pin;
  unsigned long downAt;
  boolean down;
  boolean last;
  
public:
  Button();
  boolean isDown();
  void readState();
  unsigned long lastChange();
  void attach(int);
};

//initializes the button object
Button::Button() {
  this->pin = 0;
  this->downAt = 0;
  this->down = 0;
}

//ataches the button to a pin
void Button::attach(int pin) {
  this->pin = pin;
}

//returns the time of the last change in state in milliseconds since start
unsigned long Button::lastChange () {
  return this->downAt;
}

//reads the state of a button
void Button::readState() {
  last = down;
  down = digitalRead(pin);
  if (down != last) {
    downAt = millis();
  }
}

//returns the state of a button
boolean Button::isDown() {
  return this->down;
}
