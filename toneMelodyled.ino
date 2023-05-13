#include "pitches.h"




int melody0[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4
};


int noteDurations[] = {
  2, 2, 2, 2, 2, 2, 2, 1
};
int melody1[]={
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};


int melodynum=0;
#define BUTTON 12
byte presentState=1, previousState=1;


void setup() {
  // iterate over the notes of the melody:
  pinMode(12,INPUT_PULLUP);
  for(int i=2;i<=8;i++)
  {
    pinMode(i,OUTPUT);
  }
}


void loop() {
  // no need to repeat the melody.
  if(melodynum==0)
  {
    for (int thisNote = 0; thisNote < 7; thisNote++)
    {
      // to calculate the note duration, take one second divided by the note type.
     //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(11, melody0[thisNote], noteDuration);
      if (melody0[thisNote]==NOTE_C4)//led
      {
        digitalWrite(2,HIGH);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        digitalWrite(2,LOW);
      }
     
      else if(melody0[thisNote]==NOTE_G4)
      {
        digitalWrite(6,HIGH);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        digitalWrite(6,LOW);
      }
     
      else if(melody0[thisNote]==NOTE_A4)
      {
        digitalWrite(7,HIGH);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        digitalWrite(7,LOW);
      }
     
      noTone(11);
      presentState=digitalRead(12);
      if(presentState==0&&previousState==1)
      {
        melodynum=melodynum+1;
        break;
      }
      previousState==presentState;
    }
   
  }
  if(melodynum==1)
  {
    for (int thisNote = 0; thisNote < 7; thisNote++)
    {
      // to calculate the note duration, take one second divided by the note type.
     //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(11, melody1[thisNote], noteDuration);
      if (melody1[thisNote]==NOTE_F4)//led
      {
        digitalWrite(5,HIGH);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        digitalWrite(5,LOW);
      }
      else if(melody1[thisNote]==NOTE_E4)
      {
        digitalWrite(4,HIGH);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        digitalWrite(4,LOW);
      }
      else if(melody1[thisNote]==NOTE_D4)
      {
        digitalWrite(3,HIGH);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        digitalWrite(3,LOW);
      }
      else if(melody1[thisNote]==NOTE_C4)
      {
        digitalWrite(2,HIGH);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        digitalWrite(2,LOW);
      }
     
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
     
      // stop the tone playing:
      noTone(11);
      presentState=digitalRead(12);
      if(presentState==0&&previousState==1)
      {
        melodynum=melodynum-1;
        break;
      }
      previousState==presentState;
    }
    
  }
}





