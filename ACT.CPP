#include "keyboard.h"
#include "midi.h"
#include "lights.h"

#include <iostream.h>

#define stringchannel1 2
#define stringchannel2 3
#define stringlead1 4
#define stringlead2 5
#define stringlead1level 100
#define stringlead2level 100
#define stringchord 6
#define stringchordlevel 110
#define secondc 7

void dostuff()
{

   if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
   {   
      notes[INDEX_Q]=1;   
      play_note(stringlead1,A4,stringlead1level);
   }   
   if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))   
   {   
      kill_note(stringlead1,A4,stringlead1level);
      notes[INDEX_Q]=0;   
   }   

   if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
   {   
      notes[INDEX_W]=1;   
      play_note(stringlead1,AS4,stringlead1level);
   }   
   if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))   
   {   
      kill_note(stringlead1,AS4,stringlead1level);
      notes[INDEX_W]=0;   
   }

   if ((notes[INDEX_E]== 0) && (key_table[INDEX_E]==1))
   {   
      notes[INDEX_E]=1;   
      play_note(stringlead1,C5,stringlead1level);
   }   
   if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))   
   {   
      kill_note(stringlead1,C5,stringlead1level);
      notes[INDEX_E]=0;   
   }   

   if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
   {   
      notes[INDEX_R]=1;   
      play_note(stringlead1,D5,stringlead1level);
   }   
   if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))   
   {   
      kill_note(stringlead1,D5,stringlead1level);
      notes[INDEX_R]=0;   
   }   

   if ((notes[INDEX_A] == 0) && (key_table[INDEX_A]==1))
   {   
      notes[INDEX_A]=1;   
      play_note(stringlead1,E5,stringlead1level);
   }   
   if ((notes[INDEX_A] == 1) && (key_table[INDEX_A]==0))   
   {   
      kill_note(stringlead1,E5,stringlead1level);
      notes[INDEX_A]=0;   
   }   

   if ((notes[INDEX_S] == 0) && (key_table[INDEX_S]==1))
   {   
      notes[INDEX_S]=1;   
      play_note(stringlead1,F5,stringlead1level);
   }   
   if ((notes[INDEX_S] == 1) && (key_table[INDEX_S]==0))   
   {   
      kill_note(stringlead1,F5,stringlead1level);
      notes[INDEX_S]=0;   
   }   

   if ((notes[INDEX_D] == 0) && (key_table[INDEX_D]==1))
   {   
      notes[INDEX_D]=1;   
      play_note(stringlead1,G5,stringlead1level);
   }   
   if ((notes[INDEX_D] == 1) && (key_table[INDEX_D]==0))   
   {   
      kill_note(stringlead1,G5,stringlead1level);
      notes[INDEX_D]=0;   
   }   

   if ((notes[INDEX_F] == 0) && (key_table[INDEX_F]==1))
   {   
      notes[INDEX_F]=1;   
      play_note(stringlead1,A5,stringlead1level);
   }   
   if ((notes[INDEX_F] == 1) && (key_table[INDEX_F]==0))   
   {   
      kill_note(stringlead1,A5,stringlead1level);
      notes[INDEX_F]=0;   
   }   

   if ((notes[INDEX_Z] == 0) && (key_table[INDEX_Z]==1))
   {   
      notes[INDEX_Z]=1;   
      play_note(stringlead1,CS5,stringlead1level);
   }   
   if ((notes[INDEX_Z] == 1) && (key_table[INDEX_Z]==0))   
   {   
      kill_note(stringlead1,CS5,stringlead1level);
      notes[INDEX_Z]=0;   
   }   

   if ((notes[INDEX_X] == 0) && (key_table[INDEX_X]==1))
   {   
      notes[INDEX_X]=1;   
      play_note(stringlead1,AS5,stringlead1level);
   }   
   if ((notes[INDEX_X] == 1) && (key_table[INDEX_X]==0))   
   {   
      kill_note(stringlead1,AS5,stringlead1level);
      notes[INDEX_X]=0;   
   }   


   if ((notes[INDEX_C] == 0) && (key_table[INDEX_C]==1))
   {   
      notes[INDEX_C]=1;   
      play_note(stringlead1,C6,stringlead1level);
   }   
   if ((notes[INDEX_C] == 1) && (key_table[INDEX_C]==0))   
   {   
      kill_note(stringlead1,C6,stringlead1level);
      notes[INDEX_C]=0;   
   }   


   if ((notes[INDEX_V] == 0) && (key_table[INDEX_V]==1))
   {   
      notes[INDEX_V]=1;   
      play_note(stringlead1,D6,stringlead1level);
   }   
   if ((notes[INDEX_V] == 1) && (key_table[INDEX_V]==0))   
   {   
      kill_note(stringlead1,D6,stringlead1level);
      notes[INDEX_V]=0;   
   }   


   if ((notes[INDEX_41] == 0) && (key_table[INDEX_41]==1))
   {   
      notes[INDEX_41]=1;   
      play_note(stringlead1,G4,stringlead1level);
   }   
   if ((notes[INDEX_41] == 1) && (key_table[INDEX_41]==0))   
   {   
      kill_note(stringlead1,G4,stringlead1level);
      notes[INDEX_41]=0;   
   }   

   if ((notes[INDEX_31] == 0) && (key_table[INDEX_31]==1))
   {   
      notes[INDEX_31]=1;   
      play_note(stringlead1,F4,stringlead1level);
   }   
   if ((notes[INDEX_31] == 1) && (key_table[INDEX_31]==0))   
   {   
      kill_note(stringlead1,F4,stringlead1level);
      notes[INDEX_31]=0;   
   }   

   if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))
   {   
      notes[INDEX_LEFT]=1;   
      play_note(stringchord,A3,stringchordlevel);
      play_note(stringchord,D4,stringchordlevel);
   }
   if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))   
   {   
      kill_note(stringchord,A3,stringchordlevel);
      kill_note(stringchord,D4,stringchordlevel);
      notes[INDEX_LEFT]=0;   
   }   

   if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
   {   
      notes[INDEX_UP]=1;   
      play_note(stringchord,CS4,stringchordlevel);
      play_note(stringchord,A3,stringchordlevel);
   }
   if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))   
   {   
      kill_note(stringchord,CS4,stringchordlevel);
      kill_note(stringchord,A3,stringchordlevel);
      notes[INDEX_UP]=0;   
   }   

   if ((notes[INDEX_RIGHT] == 0) && (key_table[INDEX_RIGHT]==1))
   {   
      notes[INDEX_RIGHT]=1;   
      play_note(stringchord,C4,stringchordlevel);
      play_note(stringchord,G3,stringchordlevel);
   }
   if ((notes[INDEX_RIGHT] == 1) && (key_table[INDEX_RIGHT]==0))   
   {   
      kill_note(stringchord,C4,stringchordlevel);
      kill_note(stringchord,G3,stringchordlevel);
      notes[INDEX_RIGHT]=0;   
   }   

   if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))
   {   
      notes[INDEX_DOWN]=1;   
      play_note(stringchord,D4,stringchordlevel);
      play_note(stringchord,F3,stringchordlevel);
   }
   if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))   
   {   
      kill_note(stringchord,D4,stringchordlevel);
      kill_note(stringchord,F3,stringchordlevel);
      notes[INDEX_DOWN]=0;   
   }   

   if ((notes[INDEX_0] == 0) && (key_table[INDEX_0]==1))
   {   
      notes[INDEX_0]=1;   
      play_note(stringchord,D4,stringchordlevel);
      play_note(stringchord,G3,stringchordlevel);
   }
   if ((notes[INDEX_0] == 1) && (key_table[INDEX_0]==0))   
   {   
      kill_note(stringchord,D4,stringchordlevel);
      kill_note(stringchord,G3,stringchordlevel);
      notes[INDEX_0]=0;   
   }   

   if ((notes[INDEX_1] == 0) && (key_table[INDEX_1]==1))
   {   
      notes[INDEX_1]=1;   
      play_note(stringchord,CS4,stringchordlevel);
      play_note(stringchord,E3,stringchordlevel);
   }
   if ((notes[INDEX_1] == 1) && (key_table[INDEX_1]==0))   
   {   
      kill_note(stringchord,CS4,stringchordlevel);
      kill_note(stringchord,E3,stringchordlevel);
      notes[INDEX_1]=0;   
   }   



}

void delay1(int speed)
{
   for (int index=0;index<speed;index++)
   {
      delay(1);
      dostuff();
   }
}

void main()
{

   GetBlastInfo(&blastInfo);
   MIDIType = SBMIDI;
   DSPReset();
   Init_MIDI();
   install_keyboard();
   for (int index=0;index<127;index++)
      notes[index]=0;
   clrscr();
   mix_mode();
   mix_name("Actraiza");
   change_program(1,88,1);
   change_program(2,9,3);
   change_program(3,52,1);
//   change_program(4,51,1);
//   change_program(5,51,1);
   change_program(4,20,6);
   change_program(5,20,6);
   change_program(6,56,0);
   change_program(7,52,3);
   change_volume(3,52);
   change_keyboard_input(2,1);
   change_keyboard_input(3,1);
   change_low_note(1,C4);
   change_high_note(2,B3);
   change_high_note(3,B3);
   mix_mode();
   cout << "Actraiser" << endl << endl;
   cout << "F1: Fade out second part" << endl;
   cout << "F2: Set level back to normal" << endl << endl;
   cout << "R A S D F S E S Q E W" << endl;
   cout << "W E R A S E Q E 3 Q 4" << endl;
   cout << "W E R A S R Q R Q" << endl << endl;
   cout << "S A R A Z Q" << endl;
   cout << "D S A S R Q" << endl;
   cout << "F D S D X F S D" << endl;
   cout << "F X C V X D S A R A" << endl;
   change_light_level(1,50);
   change_light_level(2,75);
   change_light_level(3,25);
   change_light_level(4,50);
   while (1 == 1)
   {
      dostuff();
      if (key_table[INDEX_F1])
      {
         cout << "\nFading out part...";
         for (int level = 99; level >=0; level-=1)
         {
            cout << ".";
            change_volume(4,level);
            change_volume(6,level);
            delay1(60);
         }
         cout << " (done)";
      }
      if (key_table[INDEX_F2])
      {
         cout << "\nVolume set to LOUD!";
         change_volume(4,99);
         delay1(100);
         change_volume(6,99);
      }
      if (key_table[INDEX_ESC]) break;
   }
   all_lights_off(0);
   change_light_level(3,127);
   Exit_MIDI();
   kill_keyboard();   
}
