#include <uspeech.h>
//#define LED pins
//#define blue for power
//#define red for fail
//#define green for success
signal voice(A0);
int time; // this calibrates our time for library use
bool first = true, process = false;
syllable syll; // name of our accumulator class
Servo lock_mechanism // this is the name of our servo object

void setup(){ // This runs once on startup
  //########################################
  //#DEBUG STUFF, delete for final delivery#
  //#These were values we tried along the way. They didn't work at that time.
  //#voice.minVolume = 50; // was 600
  //#voice.econstant = 2; // this value never exceeds 1 good
  //#voice.aconstant = 4; // this value never exceeds 3, thinks it's o
  //#voice.fconstant = 300; // THIS VALUE BREAKS OUR STUFF
  //#voice.vconstant = 5; // doesn't exceed 4
  //#voice.shconstant = 8; // doesn't go under 8, goes 8-12
  //#voice.f_enabled = true; // THIS VALUE MAKES /f/ WORK AND EVERYTHING ELSE BREAKS
  //#voice.amplificationFactor = 2; // let's try to boost our signal
  //#######################################
  voice.minVolume = 200; // was 600
  voice.econstant = 2; // this value never exceeds 1 good
  voice.aconstant = 4; // this value never exceeds 3, thinks it's o
  voice.vconstant = 6; // doesn't exceed 4
  voice.shconstant = 8; // doesn't go under 8, goes 8-12
  voice.fconstant = 400;
  Serial.begin(9600);
  time = millis(); // DEBUG THIS, it was placed in a different place in example
  voice.calibrate(); // call to calibrate function
//ALSO 
//turn on blue LED to show power is on (maybe put this in firmware? 
// this one should be on as long as the board is powered.)
 }

//This is the unlock function; it just writes to the servo.
void unlock(){
  lock_mechanism.write(0); //make sure this works, it should go 90 degrees to the right 
  Serial.println("This is a debug statement to prove that unlock worked.");
}

//This is the lock function, to be triggered when the user pushes a button on the lid
void lock(){
  lock_mechanism.write(90); // returns to the center
  Serial.println("This is a debug statement to prove that lock worked.");
}


void loop(){
  while(true){
  // ###############################################################
  // # This loop tests for silence. If it's silent it checks the last thing it heard when
  // # it wasn't silent. If it isn't silent it starts accumulating phonemes for testing.
  // # After testing a word, it should clear the accumulators and set word_waiting to false.
  // # This keeps it from holding on to garbage phonemes.
  // # This also means that the word is only tested after you stop talking.
  // # Test for the presence of the password ("sesame" or "seesaw")
  // ################################################################
  
  //  Test for the presence of the button {
  //    if button then call lock()
  //  }
  
  // get phoneme:  char a_phoneme = voice.getPhoneme(); //listen for and collect a word
  // Serial.println(voice.getPhoneme()); // print the phoneme you got for debugging
  //  if silence {
  //    if word_waiting = true
  //      int sum = some phonemes, see servocontrol for example
  //      if sum = number we expect
  //        if /ss/ showed up the right minimum number of times
  //            and if /e/ showed up the right minimum number of times
  //            then unlock()
  //            turn green LED on
  //            blink three times to congratulate them
  //            after a second or so turn it off
  //        else 
  //          red LED on cause you failed
  //          blink it three times quickly using wait() and on/off statements
  //          turn it off afterwards, you told them what they needed to know
  //      
  //      set word_waiting to false regardless of if it was right or wrong
  //      set the accumulators to 0 for all of the phonemes (syll.f, .e, .o, .v, .s, .h)
  //  }
  
  // else if not silence {
  //  classify the phonemes, which counts them up as they go along
  //  set word_waiting = true
  // }
  // 
  } // end of while(true)
} // end of void loop()
