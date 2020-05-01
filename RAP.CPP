#include "midi.h"
#include "lights.h"
#include <dos.h>   
#include "keyboard.h"

#define basschannel 2
#define basslevel 127

#define drumchannel 10

int speed = 150;

int delay1(int num);

void pause1()
{
   cout << "\nPress ESC to return!";
   wait_for(INDEX_ESC);
   wait_for_no(INDEX_ESC);
   while (1 == 1)
   {
      play_note(drumchannel,D1,127);
      delay(speed);
      delay(speed);
      kill_note(drumchannel,D1,127);

      play_note(drumchannel,D1,127);
      delay(speed);
      delay(speed);
      kill_note(drumchannel,D1,127);

      play_note(drumchannel,D1,127);
      delay(speed);
      delay(speed);
      kill_note(drumchannel,D1,127);

      play_note(drumchannel,AS1,127);
      delay(speed);
      delay(speed);
      kill_note(drumchannel,AS1,127);
      break;
   }
   play_note(drumchannel,CS2,127);
}

int delay1(int num)
{   
   int index;
   int toreturn = 0;
   for (index=0;index<num;index++)   
   {   
      //dostuff();   
      if (key_table[INDEX_ESC]) return 1;   
      if (key_table[INDEX_SPACE]) toreturn=2;
      delay(1);
   }   
   return toreturn;   
}   

void main()
{
   GetBlastInfo(&blastInfo);
   MIDIType = SBMIDI;   
   DSPReset();   
   Init_MIDI();   
   install_keyboard();

   mix_mode();
   mix_name("Rap      ");
   mix_mode();

   for (int index=0;index<127;index++)
      notes[index] = 0;   
   change_program(basschannel,40,1);
   change_program(1,40,1);
   change_program(drumchannel,123,1);
   change_effects_channel(drumchannel);
   mix_mode();
   cout << "\nPress [SPACE] to start!";
   wait_for(INDEX_SPACE);
   wait_for_no(INDEX_SPACE);

   for (index=0;index<4;index++)
   {
      play_note(drumchannel,38,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,127);
   }

   while (1)
   {
      //ONE
      cout << "\nOne ";
      play_note(drumchannel,36,127);
      play_note(drumchannel,GS1,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,36,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,GS1,127);
      play_note(drumchannel,GS1,127);
      if (delay1(speed)==1) break;
      if (delay1(speed)==1) break;
      kill_note(drumchannel,GS1,127);

      //kill_note(drumchannel,CS2,127);


      cout << "two ";
      play_note(drumchannel,38,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,38,127);
      if (delay1(speed)==1) break;
      if (delay1(speed)==1) break;
      play_note(drumchannel,36,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,36,127);

      cout << "three ";
      play_note(drumchannel,GS1,127);
      if (delay1(speed)==1) break;
      if (delay1(speed)==1) break;
      kill_note(drumchannel,GS1,127);
      play_note(drumchannel,36,127);
      play_note(drumchannel,GS1,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,36,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,GS1,127);

      cout << "four ";
      play_note(drumchannel,GS1,127);
      play_note(drumchannel,38,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,38,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,GS1,127);
      if (delay1(speed)==1) break;
      if (delay1(speed)==1) break;

      //TWO
      cout << "\nOne ";
      play_note(drumchannel,36,127);
      play_note(drumchannel,GS1,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,36,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,GS1,127);
      play_note(drumchannel,GS1,127);
      if (delay1(speed)==1) break;
      if (delay1(speed)==1) break;
      kill_note(drumchannel,GS1,127);

      cout << "two ";
      play_note(drumchannel,38,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,38,127);
      if (delay1(speed)==1) break;
      if (delay1(speed)==1) break;
      play_note(drumchannel,36,127);
      if (delay1(speed)==1) break;
      kill_note(drumchannel,36,127);

      cout << "three ";
      while (1 == 1)
      {
         int temp;

         play_note(drumchannel,GS1,127);
         temp = delay1(speed);
         if (temp == 2) pause1();
         if ((temp == 1) || (temp == 2)) break;
         temp = delay1(speed);
         if (temp == 2) pause1();
         if ((temp == 1) || (temp == 2)) break;

         kill_note(drumchannel,GS1,127);
         play_note(drumchannel,36,127);
         play_note(drumchannel,GS1,127);
         temp = delay1(speed);
         if (temp == 2) pause1();
         if ((temp == 1) || (temp == 2)) break;

         kill_note(drumchannel,36,127);
         temp = delay1(speed);
         if (temp == 2) pause1();
         if ((temp == 1) || (temp == 2)) break;

         kill_note(drumchannel,GS1,127);

      cout << "four ";

      play_note(drumchannel,GS1,127);
      play_note(drumchannel,38,127);
      temp = delay1(speed);
      if (temp == 1) break;
      if (temp == 2)
      {
         pause1();
         break;
      }

      kill_note(drumchannel,38,127);
      temp = delay1(speed);
      if (temp == 1) break;
      if (temp == 2)
      {
         pause1();
         break;
      }

      kill_note(drumchannel,GS1,127);
      play_note(drumchannel,AS1,127);


      temp = delay1(speed);
      if (temp == 1) break;
      temp = delay1(speed);
      if (temp == 1) break;

      kill_note(drumchannel,AS1,127);
      if (temp == 2)
      {
         pause1();
         break;
      }
      break;
      } // end four

   }

   Exit_MIDI();
   kill_keyboard();
}
