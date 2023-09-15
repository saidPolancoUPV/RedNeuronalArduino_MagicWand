int my_led = 13;
String incommingData = "";
String tmp = "";
char var;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  pinMode(my_led, OUTPUT);
}

void loop() {
  while(Serial.available()) {
    var = Serial.read();
    tmp = String(var);
    incommingData += tmp;
  }

  if (incommingData.equals("HHH")) {
    Serial.println(incommingData);
    digitalWrite(my_led, HIGH);
  }

  if (incommingData.equals("LLL")) {
    Serial.println(incommingData);
    digitalWrite(my_led, LOW);
  }

  delay(5000);
  incommingData = "";
}
