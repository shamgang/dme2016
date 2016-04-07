const int NumOctaves = 7;
const int OctavePins[] = { 2, 3, 4, 5, 6, 7, 8 };

void setup()
{
  Serial.begin(689);
  for (int i = 0; i < NumOctaves; i++)
  {
    pinMode(OctavePins[i], INPUT);
  }
}

void loop()
{
  // send piano information to pi
  int pianoInfo = 0;

  int val;
  for (int i = 0; i < 7; i++)
  {
    val = digitalRead(OctavePins[i]);
    pianoInfo |= val << (NumOctaves - i - 1);
  }

  Serial.write(pianoInfo);  

  // read info from pi

  // send motor information
}
