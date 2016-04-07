const int NumOctaves = 7;
const int OctavePins[] = { 2, 3, 4, 5, 6, 7, 8 };

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < NumOctaves; i++)
  {
    pinMode(OctavePins[i], INPUT);
  }
  pinMode(13, OUTPUT);
}

void loop()
{
  // send piano information to pi
  int pianoInfo = 0;

  int val;
  for (int i = 0; i < 7; i++)
  {
    val = digitalRead(OctavePins[i]);
    if (val == LOW)
    {
      pianoInfo |= 1 << (NumOctaves - i - 1);
    }
  }

  if (pianoInfo == 0)
  {
    digitalWrite(13, LOW);
  }
  else
  {
    digitalWrite(13, HIGH);
  }

  Serial.println(pianoInfo, BIN);

  delay(100);

  // read info from pi

  // send motor information
}
