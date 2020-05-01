#include "midi.h"
#include "lights.h"
#include <dos.h>   
#include "keyboard.h"

#define basschannel 2
#define basslevel 127
#define samplechannel 11
#define samplelevel 127

int speed = 125;

//DOWN RIGHT X 8
//LEFT UP    X 8
//DOWN RIGHT X 8
//LEFT UP    X 6

//DOWN SPACE LEFT ENTER

//Q W     Q    W
//Q SPACE LEFT Q

//DOWN RIGHT DOWN RIGHT
//DOWN SPACE LEFT ENTER

//MEASURE 9 ?
//Q W     Q    W
//Q SPACE LEFT Q

//DOWN RIGHT DOWN RIGHT
//DOWN DOWN  R    T

//F1 F2 X 4
//T  Y  X 6
//LEFT UP X 2
//R T     X 2
//R SPACE LEFT ENTER //end measure 16, begin 17 ... back to measure 9

void title()
{
   clrscr();
   cout << "Bubble Bobble Bass Blaster!";
   cout << "\nPress ESC to quit...";
   cout << "\n//DOWN SPACE LEFT ENTER";
   cout << "\n";
   cout << "\n//Q W     Q    W";
   cout << "\n//Q SPACE LEFT Q";
   cout << "\n";
   cout << "\n//DOWN RIGHT DOWN RIGHT";
   cout << "\n//DOWN SPACE LEFT ENTER";
   cout << "\n";
   cout << "\n//MEASURE 9 ?";
   cout << "\n//Q W     Q    W";
   cout << "\n//Q SPACE LEFT Q";
   cout << "\n";
   cout << "\n//DOWN RIGHT DOWN RIGHT";
   cout << "\n//DOWN DOWN  R    T";
   cout << "\n";
   cout << "\n//F1 F2 X 4";
   cout << "\n//T  Y  X 6";
   cout << "\n//LEFT UP X 2";
   cout << "\n//R T     X 2";
   cout << "\n//R SPACE LEFT ENTER //end measure 16, begin 17 ... back to measure 9";
}

void dostuff()
{
        if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))   
        {   
          notes[INDEX_Q]=1;   
          play_note(basschannel,A1,127);                   
        }   
        if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))   
        {   
          kill_note(basschannel,A1,127);         
          notes[INDEX_Q]=0;   
        }   

        if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
        {   
          notes[INDEX_W]=1;   
          play_note(basschannel,A2,127);                   
        }   
        if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))   
        {   
          kill_note(basschannel,A2,127);         
          notes[INDEX_W]=0;   
        }   

        if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
        {   
          notes[INDEX_R]=1;   
          play_note(basschannel,C2,127);                   
        }   
        if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))   
        {   
          kill_note(basschannel,C2,127);         
          notes[INDEX_R]=0;   
        }   

        if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
        {   
          notes[INDEX_F1]=1;   
          play_note(basschannel,DS2,127);                   
        }   
        if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))   
        {   
          kill_note(basschannel,DS2,127);         
          notes[INDEX_F1]=0;   
        }   

        if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
        {   
          notes[INDEX_F2]=1;   
          play_note(basschannel,DS3,127);                   
        }   
        if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))   
        {   
          kill_note(basschannel,DS3,127);         
          notes[INDEX_F2]=0;   
        }   

        if ((notes[INDEX_T] == 0) && (key_table[INDEX_T]==1))
        {   
          notes[INDEX_T]=1;   
          play_note(basschannel,D2,127);                   
        }   
        if ((notes[INDEX_T] == 1) && (key_table[INDEX_T]==0))   
        {   
          kill_note(basschannel,D2,127);         
          notes[INDEX_T]=0;   
        }   

        if ((notes[INDEX_Y] == 0) && (key_table[INDEX_Y]==1))
        {   
          notes[INDEX_Y]=1;   
          play_note(basschannel,D3,127);                   
        }   
        if ((notes[INDEX_Y] == 1) && (key_table[INDEX_Y]==0))   
        {   
          kill_note(basschannel,D3,127);         
          notes[INDEX_Y]=0;   
        }   

        if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
        {   
          notes[INDEX_F3]=1;   
          play_note(basschannel,D2,127);                   
        }   
        if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))   
        {   
          kill_note(basschannel,D2,127);         
          notes[INDEX_F3]=0;   
        }   

        if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
        {   
          notes[INDEX_F4]=1;   
          play_note(basschannel,D3,127);                   
        }   
        if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))   
        {   
          kill_note(basschannel,D3,127);         
          notes[INDEX_F4]=0;   
        }   

        if ((notes[INDEX_F12] == 0) && (key_table[INDEX_F12]==1))
        {   
          notes[INDEX_F12]=1;   
          play_note(samplechannel,CS5,127);
          change_light_level(1,0);
          change_light_level(2,0);
          change_light_level(3,0);
          change_light_level(4,0);
          change_light_level(14,127);
        }
        if ((notes[INDEX_F12] == 1) && (key_table[INDEX_F12]==0))   
        {   
          kill_note(samplechannel,CS5,127);         
          change_light_level(14,0);
          change_light_level(1,50);
          change_light_level(2,75);
          change_light_level(3,25);
          change_light_level(4,50);
          notes[INDEX_F12]=0;
        }   

        if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))
        {   
          notes[INDEX_DOWN]=1;   
          play_note(basschannel,AS1,127);                   
        }   
        if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))   
        {   
          kill_note(basschannel,AS1,127);         
          notes[INDEX_DOWN]=0;   
        }   

        if ((notes[INDEX_RIGHT] == 0) && (key_table[INDEX_RIGHT]==1))
        {   
          notes[INDEX_RIGHT]=1;   
          play_note(basschannel,AS2,127);                   
        }   
        if ((notes[INDEX_RIGHT] == 1) && (key_table[INDEX_RIGHT]==0))   
        {   
          kill_note(basschannel,AS2,127);         
          notes[INDEX_RIGHT]=0;   
        }   

        if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))
        {   
          notes[INDEX_LEFT]=1;   
          play_note(basschannel,G1,127);                   
        }   
        if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))   
        {   
          kill_note(basschannel,G1,127);         
          notes[INDEX_LEFT]=0;   
        }   

        if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
        {   
          notes[INDEX_UP]=1;   
          play_note(basschannel,G2,127);                   
        }   
        if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))   
        {   
          kill_note(basschannel,G2,127);         
          notes[INDEX_UP]=0;   
        }   

        if ((notes[INDEX_SPACE] == 0) && (key_table[INDEX_SPACE]==1))
        {   
          notes[INDEX_SPACE]=1;   
          play_note(basschannel,F1,127);                   
        }   
        if ((notes[INDEX_SPACE] == 1) && (key_table[INDEX_SPACE]==0))   
        {   
          kill_note(basschannel,F1,127);         
          notes[INDEX_SPACE]=0;   
        }   

        if ((notes[INDEX_ENTER] == 0) && (key_table[INDEX_ENTER]==1))
        {   
          notes[INDEX_ENTER]=1;   
          play_note(basschannel,GS1,127);                   
        }   
        if ((notes[INDEX_ENTER] == 1) && (key_table[INDEX_ENTER]==0))   
        {   
          kill_note(basschannel,GS1,127);         
          notes[INDEX_ENTER]=0;   
        }   

}


int delay1(int speed)
{
   for (int index=0;index<speed;index++)
   {
      if (key_table[INDEX_ESC]) return 1;
      dostuff();
      delay(1);
   }
   return 0;
}

int count = 0;

void main()
{
   GetBlastInfo(&blastInfo);
   MIDIType = SBMIDI;   
   DSPReset();   
   Init_MIDI();   
   install_keyboard();
   mix_name("Bubble  ");
   mix_mode();
   title();

   for (int index=0;index<127;index++)
      notes[index] = 0;   
   change_program(basschannel,40,1);
   change_program(1,13,1);
   change_program(samplechannel,124,0);
   change_high_note(1,E4);
   change_low_note(3,F4);
   change_program(3,51,1);
   change_keyboard_input(3,1);
   change_light_level(1,50);
   change_light_level(2,75);
   change_light_level(3,25);
   change_light_level(4,50);

   mix_name("Bubble   ");
   mix_mode();
//   all_lights_off(0);
   while (1)
   {

//      if (count == 0)
//      {
//         fade_in_light(1,5,127,2);
//      }

//      if (count == 500)
//      {
//         fade_out_light(1,5,1,3);
//         fade_in_light(4,5,127,3);
//      }

//      if (count == 1000)
//      {
//         fade_in_light(1,5,127,2);
//         fade_out_light(4,5,1,3);
//         count = 1;
//      }

      if (delay1(2)) break;
//      do_fade_stuff();
      count++;
   }
   change_light_level(1,0);
   change_light_level(2,0);
   change_light_level(3,127);
   change_light_level(4,0);

   change_high_note(1,127);
   change_low_note(3,0);
   change_keyboard_input(3,0);
   Exit_MIDI();
   kill_keyboard();
}
