#include <dos.h>
#include <conio.h>
#include "keyboard.h"
#include <midi.h>

#include "lights.h"

#define drumlevel 127
#define drumchannel 10

int speed = 110;

void dostuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      all_lights_on(127);
   }

   if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
   {
      notes[INDEX_Q]=1;
      all_lights_off(0);
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      fade_in_light(1,0,127,3);
      fade_in_light(2,0,127,3);
      fade_in_light(3,0,127,3);
      fade_in_light(4,0,127,3);
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      fade_in_light(4,5,127,3);
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      notes[INDEX_F5]=0;
      change_light_level(4,0);
//      fade_in_light(4,5,127);
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      fade_out_light(1,0,1,3);
      fade_out_light(2,0,1,3);
      fade_out_light(3,0,1,3);
      fade_out_light(4,0,1,3);
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
//      kill_note(16,1,127);
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
//      kill_note(16,1,127);
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
//      kill_note(16,1,127);
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))
   {
//      kill_note(16,1,127);
      notes[INDEX_Q]=0;
   }

   if ((notes[INDEX_11] == 0) && (key_table[INDEX_11]==1))
   {
      notes[INDEX_11]=1;
      change_light_level(1,127);
   }

   if ((notes[INDEX_11] == 1) && (key_table[INDEX_11]==0))
   {
      notes[INDEX_11]=0;
   }

   if ((notes[INDEX_21] == 0) && (key_table[INDEX_21]==1))
   {
      notes[INDEX_21]=1;
      change_light_level(1,0);
   }

   if ((notes[INDEX_21] == 1) && (key_table[INDEX_21]==0))
   {
      notes[INDEX_21]=0;
   }

   if ((notes[INDEX_31] == 0) && (key_table[INDEX_31]==1))
   {
      notes[INDEX_31]=1;
      change_light_level(2,127);
   }

   if ((notes[INDEX_31] == 1) && (key_table[INDEX_31]==0))
   {
      notes[INDEX_31]=0;
   }

   if ((notes[INDEX_41] == 0) && (key_table[INDEX_41]==1))
   {
      notes[INDEX_41]=1;
      change_light_level(2,0);
   }

   if ((notes[INDEX_41] == 1) && (key_table[INDEX_41]==0))
   {
      notes[INDEX_41]=0;
   }

   if ((notes[INDEX_51] == 0) && (key_table[INDEX_51]==1))
   {
      notes[INDEX_51]=1;
      change_light_level(3,127);
   }

   if ((notes[INDEX_51] == 1) && (key_table[INDEX_51]==0))
   {
      notes[INDEX_51]=0;
   }

   if ((notes[INDEX_61] == 0) && (key_table[INDEX_61]==1))
   {
      notes[INDEX_61]=1;
      change_light_level(3,0);
   }

   if ((notes[INDEX_61] == 1) && (key_table[INDEX_61]==0))
   {
      notes[INDEX_61]=0;
   }

   if ((notes[INDEX_71] == 0) && (key_table[INDEX_71]==1))
   {
      notes[INDEX_71]=1;
      change_light_level(4,127);
   }

   if ((notes[INDEX_71] == 1) && (key_table[INDEX_71]==0))
   {
      notes[INDEX_71]=0;
   }

   if ((notes[INDEX_81] == 0) && (key_table[INDEX_81]==1))
   {
      notes[INDEX_81]=1;
      change_light_level(4,0);
   }

   if ((notes[INDEX_81] == 1) && (key_table[INDEX_81]==0))
   {
      notes[INDEX_81]=0;
   }

}

int delay1(int speed)
{
        for (int index=0;index<speed;index++)
        {
           do_fade_stuff();
           if (key_table[INDEX_ESC]) return 1;
           dostuff();
           delay (1);
        }
        return 0;
}

void showinfo()
{
   clrscr();
   cout << "Lights!";
   cout << "\nF1: Turn on all lights";
   wait_for_no(INDEX_ESC);
}

void main()
{
   int red;
   int green;
   int blue;
   int white;

   cout << "\nEnter red: ";
   cin >> red;
   cout << "\nEnter green: ";
   cin >> green;
   cout << "\nEnter blue: ";
   cin >> blue;
   cout << "\nEnter white: ";
   cin >> white;

        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        showinfo();
   change_light_level(1,red);
   change_light_level(2,blue);
   change_light_level(3,white);
   change_light_level(4,green);

        while (1)
        {
/*           cout << "\nNew Measure";
           play_note(10,AS1,127);
           play_note(10,C1,127);
           delay1(speed);
           kill_note(10,AS1,127);
           play_note(10,AS1,127);
           delay1(speed);
           kill_note(10,AS1,127);
           play_note(10,AS1,127);
           delay1(speed);
           kill_note(10,AS1,127);
           play_note(10,AS1,127);
           delay1(speed);
           kill_note(10,AS1,127);
           kill_note(10,C1,127);

           play_note(10,AS1,127);
           play_note(10,D1,127);
           delay1(speed);
           kill_note(10,AS1,127);
           play_note(10,AS1,127);
           delay1(speed);
           kill_note(10,AS1,127);
           play_note(10,AS1,127);
           delay1(speed);
           kill_note(10,AS1,127);
           play_note(10,AS1,127);
           delay1(speed);
           kill_note(10,AS1,127);
           kill_note(10,D1,127);*/
           delay1(1);
           if (key_table[INDEX_1])
           {
              showinfo();
           }
           if (key_table[INDEX_ESC]) break;
        }
        kill_keyboard();
        Exit_MIDI();
    }
