void consoleLog(int x);
void strLog(char * msg);
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
  strLog('Im a robot in the world');
}
