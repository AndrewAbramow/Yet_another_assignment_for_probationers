#include <iostream>

int main() {
  volatile uint8_t arr[8];

  for(int i=0; i<8; ++i) {
    arr[i] = i;
  }

}
