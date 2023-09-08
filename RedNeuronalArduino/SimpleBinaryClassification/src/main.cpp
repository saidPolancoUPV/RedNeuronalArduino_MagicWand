#include <Arduino.h>

const int num_in = 2;

double input_x[num_in] = {0.15, 0.34};
double vec_W[num_in] = {0.19, -0.33};




// put function declarations here:
int myFunction(int, int);

void setup() {

  Serial.begin(9600);
  // put your setup code here, to run once:
  int result = myFunction(2, 3);

  Serial.println(result);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}