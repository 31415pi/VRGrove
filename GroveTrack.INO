/*Arduino side
 * code for grove mini trackball to port movement data as CSV over Serial
 * for use in Tabitha Nikolai's project Utopia Without You
 * Comission Date: June 2018
 * 
 * Using this for Unity VR controller interfacing - Unity code attached in repo
 */
#include "Wire.h"
#include "MiniTrackball.h"
#include "string.h"

MTB minitb;
int minval = 0; // minimum value to read in order to change send variable

void setup() {
  Serial.begin(9600);
  Wire.begin();

}

  void loop() {
  uint8_t pos[5];
  
  int up = 0;
  int down = 0; 
  int left = 0;
  int right = 0;

  minitb.GetTrackData(pos);
 
  //0 - up, 1 - down, 2 - left , 3 - right, 4 - click

  //min val check;
  if ( pos[0] > minval )  up = pos[0];   
  if ( pos[1] > minval )  down = pos[1]; 
  if ( pos[2] > minval )  left = pos[2]; 
  if ( pos[3] > minval ) right = pos[3];
  
  String yolo = String();

//  yolo = "U";
//  yolo.concat(up).concat("D").concat(down).concat("L").concat(left).concat("R").concat(right);
  yolo.concat(up).concat(",").concat(down).concat(",").concat(left).concat(",").concat(right);
  
  Serial.println(yolo);
  delay(100);
  }
