#include <string.h>

void consoleLog(int x);
void strLog(char * offset, int length);
void numLog(int x);

int main() {
    return 42;
}

void getNumber() {
    numLog(22);
}

void getDoubleNumber(int x) {
  numLog(x * 2);
}

void greet() {
  char * msg = "Hello from C";
  strLog(msg, strlen(msg));
}
