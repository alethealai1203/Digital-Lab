// 定義列與行接腳
#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 A4
#define COL5 A3
#define COL6 A2
#define COL7 A1
#define COL8 A0

const int row[] = {ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {COL1, COL2, COL3, COL4, COL5, COL6, COL7, COL8};

byte incomingByte;

// 三個圖案：A、H、O
int A[8][8] = {
  {1,1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,1,1,1,1,1}
};

int H[8][8] = {
  {1,1,1,1,1,1,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,1,1,1,1,1}
};

int O[8][8] = {
  {1,1,0,0,0,0,1,1},
  {1,0,1,1,1,1,0,1},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {1,0,1,1,1,1,0,1},
  {1,1,0,0,0,0,1,1}
};

void setup() {
  Serial.begin(9600);

  // 設定所有列與行為輸出
  for (int i = 0; i < 8; i++) {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], HIGH); // 預設關閉
    pinMode(col[i], OUTPUT);
    digitalWrite(col[i], HIGH); // 預設關閉
  }
}

// 顯示圖案函數
void showPattern(int pattern[8][8]) {
  for (int r = 0; r < 8; r++) {
    digitalWrite(row[r], LOW);
    for (int c = 0; c < 8; c++) {
      digitalWrite(col[c], pattern[r][c] ? LOW : HIGH);
    }
    delay(1);
    for (int c = 0; c < 8; c++) {
      digitalWrite(col[c], HIGH);
    }
    digitalWrite(row[r], HIGH);
  }
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
  }

  // 持續顯示圖案直到下一次輸入
  if (incomingByte == 'a' || incomingByte == 'A') {
    for (int i = 0; i < 500; i++) showPattern(A);
  } else if (incomingByte == 'h' || incomingByte == 'H') {
    for (int i = 0; i < 500; i++) showPattern(H);
  } else if (incomingByte == 'o' || incomingByte == 'O') {
    for (int i = 0; i < 500; i++) showPattern(O);
  }
}



