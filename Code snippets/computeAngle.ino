class Position { //a class Position, with coords (x,y) and rotation r
public:
  Position();
  float x;
  float y;
  float r;
};

Position::Position() //initialization function sets all class variables to 0
{  this-> x = 0;
   this-> y = 0;
   this-> r = 0;  }

//computes the angle betwween the robot and goal positions.
float computeAngle(Position::Position robot, Position::Position goal ){
  float deltaX = goal.x - robot.x;
  float deltaY = goal.y - robot.y;
  float myAnswer;
  if ((deltaX >= 0 && deltaY >= 0)||(deltaX >= 0 && deltaY < 0)){
    if (deltaX == 0) {deltaX= 0.00001;} //to avoid divide by zero conditions
    if (deltaY == 0) {deltaY = 0.00001;} //to avoid divide by zero conditions
    myAnswer = atan(deltaY / deltaX);
  }
  if ((deltaX < 0 && deltaY < 0)||(deltaX < 0 && deltaY >= 0)){
    if (deltaX == 0) {deltaX= 0.00001;} //to avoid divide by zero conditions
    if (deltaY == 0) {deltaY = 0.00001;} //to avoid divide by zero conditions
    myAnswer = atan(deltaY / deltaX) + M_PI;
  }
  //myAnswer = myAnswer + M_PI/2;
  myAnswer = myAnswer * 180 / M_PI;
  return myAnswer;

}
void setup(){
Serial.begin(9600);


}
void loop(){
  Position::Position myrobot;
  Position::Position mytarget;
  float Answer;
  myrobot.x = 0;
  myrobot.y = 0;
  mytarget.x = -1;
  mytarget.y = -1;
  Answer = computeAngle(myrobot, mytarget);
  Serial.println(Answer);
  delay(200);
}

