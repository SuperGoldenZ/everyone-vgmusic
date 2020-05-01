#include <dos.h>
#include <conio.h>
#include "keyboard.h"
#include "midi.h"
#include "lights.h"

#define drumlevel 127
#define drumchannel 10

#define guitarchannel 3
#define guitarlevel 127

int samplechannel =11;

int chordchannel = 2;

int speed = 125; //old 115

int odd(int num)
{
   if ((num%2) == 0)
      return 0;
   return 1;
}

void playchordf1()
{
   play_note(chordchannel,B3,127);
   play_note(chordchannel,FS3,127);
}

void killchordf1()
{
   kill_note(chordchannel,B3,127);
   kill_note(chordchannel,FS3,127);
}

void playchordf2()
{
   play_note(chordchannel,B3,127);
   play_note(chordchannel,G3,127);
}

void killchordf2()
{
   kill_note(chordchannel,B3,127);
   kill_note(chordchannel,G3,127);
}

void playchordf3()
{
   play_note(chordchannel,CS4,127);
   play_note(chordchannel,G3,127);
}

void killchordf3()
{
   kill_note(chordchannel,CS4,127);
   kill_note(chordchannel,G3,127);
}

void playchordf4()
{
   play_note(chordchannel,D4,127);
   play_note(chordchannel,FS3,127);
}

void killchordf4()
{
   kill_note(chordchannel,D4,127);
   kill_note(chordchannel,FS3,127);
}

void playchordf5()
{
   play_note(chordchannel,E3,127);
   play_note(chordchannel,B3,127);
}

void killchordf5()
{
   kill_note(chordchannel,E3,127);
   kill_note(chordchannel,B3,127);
}

void playchordf6()
{
   play_note(chordchannel,D3,127);
   play_note(chordchannel,A3,127);
}

void killchordf6()
{
   kill_note(chordchannel,D3,127);
   kill_note(chordchannel,A3,127);
}


void dostuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      playchordf1();
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      killchordf1();
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      playchordf2();
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      killchordf2();
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      playchordf3();
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
      killchordf3();
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
   {
      notes[INDEX_F4]=1;
      playchordf4();
   }

   if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
   {
      killchordf4();
      notes[INDEX_F4]=0;
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      playchordf5();
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      killchordf5();
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
   {
      notes[INDEX_F6]=1;
      playchordf6();
   }

   if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
   {
      killchordf6();
      notes[INDEX_F6]=0;
   }

}

int delay1(int speed)
{
        for (int index=0;index<speed;index++)
        {
                if (key_table[INDEX_ESC]) return 1;
                dostuff();
                delay (1);
        }
        return 0;
}

int go()
{
   int measure = 0;
   int count = 0;
   clrscr();
   cout << "Go!";

   play_note(samplechannel,DS5,127);
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;

   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;

   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;

   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;

   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;

   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;

   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;
   if (delay1(speed)) return 0;

   kill_note(samplechannel,DS5,127);

   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      cout << " one ";

      if (measure == 1) play_note(drumchannel,CS2,127); else
            play_note(drumchannel,D1,127);
      play_note(drumchannel,GS1,127);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_note(drumchannel,GS1,127);
      if (measure == 1) kill_note(drumchannel,CS2,127); else
      kill_note(drumchannel,D1,127);

      play_note(drumchannel,GS1,70);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_note(drumchannel,GS1,70);

      play_note(drumchannel,GS1,127);
      if (odd(measure)) play_note(drumchannel,CS2,127);

      if (measure != 1)
         play_note(drumchannel,C1,127);
      if (measure == 72)
      {
         play_note(drumchannel,CS2,127);
         break;
      }
      cout << " two ";
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      if (measure != 1)
         kill_note(drumchannel,C1,127);
      kill_note(drumchannel,GS1,127);
      if (odd(measure)) kill_note(drumchannel,CS2,127);

      play_note(drumchannel,GS1,70);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_note(drumchannel,GS1,70);

      cout << " three ";
      if ((measure == 5) || (measure == 13) || (measure == 29) || (measure == 45)) play_note(drumchannel,CS2,127);
      play_note(drumchannel,D1,127);
      play_note(drumchannel,GS1,127);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_note(drumchannel,GS1,127);
      kill_note(drumchannel,D1,127);
      if ((measure == 5) || (measure == 13) || (measure == 29) || (measure == 45))kill_note(drumchannel,CS2,127);

      if ((measure == 5) || (measure == 13) || (measure == 29) || (measure == 45)) play_note(drumchannel,A2,127);

      play_note(drumchannel,GS1,70);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_note(drumchannel,GS1,70);
      if ((measure == 5) || (measure == 13) || (measure == 29) || (measure == 45)) kill_note(drumchannel,A2,127);

      play_note(drumchannel,GS1,70);
      if ((measure == 5) || (measure == 13) || (measure == 29) || (measure == 45)) play_note(drumchannel,CS2,127);
      play_note(drumchannel,C1,127);
      cout << " four ";
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_note(drumchannel,GS1,70);
      kill_note(drumchannel,C1,127);
      if ((measure == 5) || (measure == 13) || (measure == 29) || (measure == 45)) kill_note(drumchannel,CS2,127);

      play_note(drumchannel,GS1,70);
      if (delay1(speed)) return 0;
      if (delay1(speed)) break;
      kill_note(drumchannel,GS1,70);

   }

   return 1;
}

void showinfo()
{
   clrscr();
   cout << "It's up to us to take out umbrella";
   wait_for_no(INDEX_ESC);
   cout << "\n[1    ]: Go!";
   cout << "\nESC: Quit";
}

void main()
{
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        showinfo();
        change_program(drumchannel,120,1);
        change_program(1,43,1);
        change_effects_level(drumchannel,0);
        change_effects_level(1,0);
        change_program(2,81,1);
        change_volume(2,70);
        change_program(samplechannel,124,0);
        while (1)
        {
                delay1(1);
                if (key_table[INDEX_1])
                {
                   go();
                   wait_for_no(INDEX_ESC);

                   play_note(drumchannel,C2,127);
                   if (delay1(speed)) break;
                   if (delay1(speed)) break;
                   play_note(drumchannel,B1,127);
                   if (delay1(speed)) break;
                   if (delay1(speed)) break;

                   play_note(drumchannel,A1,127);
                   if (delay1(speed)) break;
                   if (delay1(speed)) break;
                   play_note(drumchannel,G1,127);
                   if (delay1(speed)) break;
                   if (delay1(speed)) break;

                   play_note(drumchannel,C2,127);
                   if (delay1(speed)) break;
                   play_note(drumchannel,B1,127);
                   if (delay1(speed)) break;
                   play_note(drumchannel,A1,127);
                   if (delay1(speed)) break;
                   play_note(drumchannel,G1,127);
                   if (delay1(speed)) break;

                   play_note(drumchannel,C2,127);
                   if (delay1(speed)) break;
                   play_note(drumchannel,B1,127);
                   if (delay1(speed)) break;
                   play_note(drumchannel,A1,127);
                   if (delay1(speed)) break;
                   play_note(drumchannel,G1,127);
                   play_note(drumchannel,CS2,127);

                   if (delay1(speed)) break;

                   showinfo();
                }
                if (key_table[INDEX_ESC]) break;
        }
        change_volume(2,99);
        all_lights_off(0);
        change_light_level(3,127);

        kill_keyboard();
        Exit_MIDI();
    }
