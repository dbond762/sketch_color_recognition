const int RPin = 11;
const int GPin = 10;
const int BPin = 9;

const int tonePin = 8;
const int sensorPin = 12;

void setup() {
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  
  pinMode(tonePin, OUTPUT);
  pinMode(sensorPin, INPUT);

  setColor(0, 0, 0);  
  Serial.begin(38400);
}

void loop() {
  serialCommutator();
  sensor();
}

int sensorState = LOW;
int sensorVal = 0;

const char motionDetected = 'M';
const char motionStoped = 'm';

void sensor() {
  sensorVal = digitalRead(sensorPin);
  if (sensorVal == HIGH) {
    delay(100);
    if (sensorState == LOW) {
      Serial.println(motionDetected);
      sensorState = HIGH;
    }
  }
  else {
    delay(200);
    if (sensorState == HIGH){
      Serial.println(motionStoped);
      sensorState = LOW;
    }
  }
}

const byte rgbLedCmd = '#';
const byte musicCmd = '$';
const byte stopCmd = ':';
char cmdCh;

char *song1 = "3c.5,4e4,2e4-2e.4,4h4,4a#4|3h.4,4d#4,2d#4-1d#4|3h.4,4d4,2d4-2d.4,4a4,4g#4|3a.4,4c#4,2c#4-1c#4|3a.4,4c4,2c4-2c.4,4a4,4g#4|3a.4,4h3,2h3-2h3,4p,4h3,4d4,4e4|3f.4,4f4,3e4,3d4,3d4,2c4,3c4|3e4,4d4,4c4,3h3,3a3,2c4,2h3|3c.5,4e4,2e4-2e.4,4h4,4a#4|3h.4,4d#4,2d#4-1d#4|3h.4,4d4,2d4-2d.4,4a4,4g#4|3a.4,4c#4,2c#4-1c#4|3a.4,4c4,2c4-2c.4,4a4,4g#4|3a.4,4h3,2h3-2h3,4p,4h3,4d4,4e4|3f.4,4f4,3e4,3d4,3d4,2c4,3c4|3e4,4d4,4c4,3h3,3a3,2c4,2h3|1a3,2p,4e4,4f4,4g4,4a4|3hb4,4e4,4f4,4g4,4a4,3hb4,3p,3hb4,3a4,3g4|3hb4,4a4,4g4,2a4,4d4,4e4,4f4,4g4,3a4,4d4,4e4|4f4,4g4,3a4,3p,3a4,3g4,3f4,3a4,3g4|3p,3f4,3f4,4e4,4d4,2e4,4e4,4f4,4g4,4a4|3hb4,4e4,4f4,4g4,4a4,3hb4,3p,3hb4,3a4,3g4|3hb4,4a4,4g4,3a4,3a4,3c5,2h4,3d#4|3c4,2h4,3d#4,3c5,4h4,4f4,3c5,4h4,4f4|1c5,1h4";
//char *song2 = "2e3,2h3,2h3,2f#3|2f3,2f3,2f3,3f3,3f#3|2e3,2h3,2h3,2f#3|2f3,2f3,2f3,3f3,3f#3|2e3,2h3,2h3,2f#3|2f3,2f3,2f3,3f3,3f#3|2e3,2h3,2h3,2f#3|1db.4,3h3,2h3,2h3|4e2,4e2,4e2,4e2,2e2,3p,3e2,4e2,4e2,4e2,4e2|4db2,4db2,4db2,4db2,2db2,3p,3db2,4db2,4db2,4db2,4db2|4h1,4h1,4h1,4h1,2h1,3p,3h1,4h1,4h1,4h1,4h1|4db2,4db2,4db2,4db2,2db2,3p,3db2,4db2,4db2,4db2,4db2|4e2,4e2,4e2,4e2,2e2,3p,3e2,4e2,4e2,4e2,4e2|4db2,4db2,4db2,4db2,2db2,3p,3db2,4db2,4db2,4db2,4db2|4h1,4h1,4h1,4h1,2h1,3p,3h1,4h1,4h1,4h1,4h1";
//char *song3 = "0e4|3h4,4a4,4e4,4h4,4a4,4e4,4h4,4a4,4e4,4h4,4a4,4e4,4c3,4a4,4e4|3h4,4a4,4e4,4h4,4a4,4e4,4h4,4a4,4e4,4h4,4a4,4e4,4c3,4a4,4e4|3h4,4a4,4e4,4h4,4a4,4e4,4h4,4a4,4e4,4h4,4a4,4e4,4c3,4a4,4e4|3h4,4a4,4e4,4h4,4a4,4e4,4h4,4a4,4e4,4h4,4a4,3c4,3h3";
char *Unforgiven = "1c5,3c5,3c5,2d5,1d#5,1d#5,3d#5,3d#5,3d5,1a#4,3a#4,2a#4,3g4,3c5,3d5,1c5,3c5,3c5,3d5,1d#5,1g5,3g5,3g5,3f5,1d5,3a#4,2a#4,3g4,3c5,3d5,3c5";
char *StressedOut = "2a4,3e5,3e5,3e5,2e5,3c5,1c5,3e5,3e5,2e5,3h4,2h4,1a4,3e5,3e5,3e5,3c5,1c5,3c5,3c5,3a5,3g5,3c5,3h4,3a5,3g5,3d5,3e5";
char *Numb = "3e5,3g5,3e5,1a5,2c6,1h5,3e5,3g5,3e5,1c6,2h5,1g5,3e5,3g5,3e5,1a5,2c6,1h5,3e5,3g5,3e5,1c6,2h5,1g5";
char *InTheEnd = "2e5,2h5,2h5,2g5,2f#5,2f#5,2f#5,3f#5,3g5,2e5,2h5,2h5,2g5,2f#5,2f#5,2f#5,3f#5,3g5,2e5,2h5,2h5,2g5,2f#5,2f#5,2f#5,3f#5,3g5,2e5,2h5,2h5,2g5,2f#5,2f#5,2f#5,3f#5,3g5";
char *PersonalJesus = "3f4,1f4,2d#4,2f4,2f4,2g#4,3f4,2f4,3g#4,2f4,3f4,2g#4,2f4,2g#4,3f4,2f4,2g#4,3f4,2f4,3g#4,2f4,3f4,2g#4,2f4,2g#4,3f4,2f4,2g#4,3f4,2f4,3g#4,2f4,3f4,2g#4,2f4,2g#4,3a#4,2a#4,2c#5,3a#4,2a#4,3c#5,2g#4,3g#4,2c5,2g#4,2c5,2f4,2g#4,3f4,2f4,3g#4,2f4,3f4,2g#4,2f4,2g#4";
int songNum = 0;

void serialCommutator() {
  if (Serial.available() > 0) {
    cmdCh = Serial.read();
    
    Serial.print("cmdCh = ");
    Serial.println(cmdCh);
    
    switch (cmdCh) {
      case rgbLedCmd:
        rgbLed();
        break;
      case musicCmd:
        songNum = Serial.read() - '0';
        switch (songNum) {
          case 0:
            ToneMusic(80, song1);
            break;
          case 1:
            ToneMusic(80, Unforgiven);
            break;
          case 2:
            ToneMusic(120, StressedOut);
            break;
          case 3:
            ToneMusic(80, Numb);
            break;
          case 4:
            ToneMusic(80, InTheEnd);
            break;
          case 5:
            ToneMusic(130, PersonalJesus);
            break;
        }
        break;
    }
  }
}

const int colorMaxLen = 12;
String red, green, blue;
char curColor, ch;
int idx = 0;

void rgbLed() {
  delay(10);
  while (Serial.available() > 0) {
    delay(10);
    ch = Serial.read();
    
    if (ch == stopCmd || idx >= colorMaxLen) {
      break;
    }
    
    if (ch == 'R') {
      curColor = 'R';
      red = "";
    }
    else if (ch == 'G') {
      curColor = 'G';
      green = "";
    }
    else if (ch == 'B') {
      curColor = 'B';
      blue = "";
    }
    else if (curColor == 'R' && ch != 'R') {
      red += ch;
    }
    else if (curColor == 'G' && ch != 'G') {
      green += ch;
    }
    else if (curColor == 'B' && ch != 'B') {
      blue += ch;
    }
    
    idx++;
  }
  
  setColor(red.toInt(), green.toInt(), blue.toInt());
  idx = 0;
}

void setColor(int R, int G, int B) {
  analogWrite(RPin, R);
  analogWrite(GPin, G/4);
  analogWrite(BPin, B/2);
}

const double a4 = 432.0;
int freqs[] = { 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494 };

long wholenote, duration, duration2;
int num, note = 0, octave, freq, shift;

void ToneMusic(int bpm, char *notes) {
  wholenote = (60 * 1000L / bpm) << 2;
  
  while (*notes) {
    num = *notes++ - '0';
    duration = wholenote >> num;
    
    Serial.print(num, DEC);
    
    switch (*notes) {
      case 'c':
        note = 1;
        break;
      case 'd':
        note = 3;
        break;
      case 'e':
        note = 5;
        break;
      case 'f':
        note = 6;
        break;
      case 'g':
        note = 8;
        break;
      case 'a':
        note = 10;
        break;
      case 'b':
        note = 11;
        break;
      case 'h':
        note = 12;
        break;
      case 'p':
      default:
        note = 0;
    }
    
    Serial.print(*notes);
    
    notes++;
    
    if (note == 0) {
      notes++;
      delay(duration);
      continue;
    }
    
    if (*notes == '#') {
      Serial.print("#");
      
      notes++;
      note++;
    }
    if (*notes == 'b') {
      Serial.print("b");
      
      notes++;
      note--;
    }
    
    if (*notes == '.') {
      Serial.print(".");
      
      notes++;
      duration += duration >> 1;
    }
    
    octave = *notes++ - '0';
    
    Serial.print(octave, DEC);
    Serial.print("\t");
    
    freq = freqs[note-1];
    shift = octave - 4;
    if (shift > 0) {
      freq <<= shift;
    } else {
      freq >>= -shift;
    }
    
    Serial.print(freq);
    
    if (*notes == '-') {
      Serial.print("\t-");
      
      notes++;
      num = *notes++ - '0';
      
      Serial.print(num, DEC);
      
      duration2 = wholenote >> num;
      
      notes++;
      if (*notes == '#' || *notes == 'b') {
        Serial.print(*notes);
        
        notes++;
      }
      
      if (*notes == '.') {
        Serial.print('.');
        
        notes++;
        duration2 += duration2 >> 1;
      }
      
      notes++;
      duration += duration2;
    }
    
    Serial.print("\t");
    Serial.println(duration, DEC);
    
    if (*notes == ',' || *notes == '|') {
      notes++;
    }
    
    tone(tonePin, freq);
    delay(duration);
    noTone(tonePin);
  }
}
