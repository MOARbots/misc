boolean TurnClockwise(float myangle, float mydesiredangle) {
    float RotationDifference1 = mydesiredangle-myangle;
    float RotationDifference2 = (360-abs(RotationDifference1))*((RotationDifference1) / abs(RotationDifference1) * -1); 
    float Diff;
    if (abs(RotationDifference2) > abs(RotationDifference1))
    {
        Diff = RotationDifference1;
    }
    if (abs(RotationDifference1) > abs(RotationDifference2))
    {
        Diff = RotationDifference2;
    }
    if (Diff < 0){//clockwise
        return true;
    }
    if (Diff > 0){//counterclockwise
        return false;
    }   
}

void setup() {
  Serial.begin(9600);
}

void loop ()
{
  float myangle = 72;
  float mydesiredangle = 36;
  Serial.println(TurnClockwise(myangle, mydesiredangle));
  delay(200);
}
