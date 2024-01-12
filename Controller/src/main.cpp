/*
Aquaponics Media Cleaning System Controller V1.0

Created by Jeremy Sharp and Tom Gentrup
01-09-2024
*/

//Includes
#include <Arduino.h>

//Pin Definitions
#define trommel_motor 8
#define solenoid_valve 9
#define boost_pump 10

//global variables and flags, defualt all states to zero on power up
bool start_flag = 0b0;
int time_remaining = 0;
bool tumbler_flag = 0b0;
bool spraybar_flag = 0b0;
bool solenoid_flag = 0b0;

//function declarations
void disableStart(); //Sets the start button flag down
void enableStart(); //Sets the start button flag up
void raiseTimer(); //Raises the cycle timer for Timer Interrupt
void clearTimer(); //Sets the timer to zero to reset cycle
void beginTumbler(); //Gradually increases tumbler speed
void stopTumbler(); //Gradually reduces tumbler speed
void openSolenoid(); //Opens solenoid valve
void closeSolenoid(); //Closes solenoid valve
void beginSpraybar(); //Powers spray bar pump
void stopSpraybar(); //Powers down spray bar pump
void emerStopTumbler(); //Emergency stops tumbler
void errorMsg(uint8_t error_in);


void setup() {

}

void loop() {
  // put your main code here, to run repeatedly:
}

//function definitions
void disableStart(){ //Sets the start button flag down
  start_flag = 0b0;
  closeSolenoid();
  stopSpraybar();
  stopTumbler();
}


void enableStart(){ //Sets the start button flag up
  start_flag = 0b1;
}


void raiseTimer(); //Raises the cycle timer for Timer Interrupt


void clearTimer(); //Sets the timer to zero to reset cycle


void beginTumbler(){ //Gradually increases tumbler speed
//add speed control later
  if(start_flag){
    tumbler_flag =0b1;
    digitalWrite(trommel_motor,HIGH); //turn on trommel motor if start flag is set
  }
  else{
    tumbler_flag =0b0;
    digitalWrite(trommel_motor,LOW); //turn off trommel motor if start flag is not set
    errorMsg(2); //print errior message showing that system was not properly initalized
  }
}


void openSolenoid(){ //Opens solenoid valve
  if(start_flag){
      solenoid_flag =0b1;
      digitalWrite(solenoid_valve,HIGH); //open valve if start flag is set
    }
    else{
      solenoid_flag =0b0;
      digitalWrite(solenoid_valve,LOW); //close valve if start flag is not set
      errorMsg(3); //print errior message showing that system was not properly initalized
    }
}

void closeSolenoid(){ //Closes solenoid valve
  solenoid_flag =0b0;
  digitalWrite(solenoid_valve,LOW); //close valve
}

void beginSpraybar(){ //Powers spray bar pump
//may not be necessary, redundant with solenoid
}

void stopSpraybar(); //Powers down spray bar pump
//may not be necessary, redundant with solenoid

void emerStopTumbler(){ //Emergency stops tumbler
  tumbler_flag =0b0;
  digitalWrite(trommel_motor,LOW); //turn off trommel motor
  errorMsg(1); //print errior message showing that trommel was emergency stopped
}

void errorMsg(uint8_t error_in){
  Serial.print("System Halted, error:");
  Serial.println((int)errorMsg);
}