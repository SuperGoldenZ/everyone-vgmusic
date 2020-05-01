#include "keyboard.h"
#include "midi.h"
#include <dos.h>
#include <conio.h>

#define hitchannel 3
#define drumlevel 127
#define drumchannel 10
#define basschannel 2

#define guitarchannel 4

int guitarlevel = 127;

int notes [127];

int speed = 75;
int bassnotes[50][4];
int basslevel = 0;

void play_chord1()
{
   play_note(guitarchannel,A2,guitarlevel);
   play_note(guitarchannel,A1,guitarlevel);
}

void kill_chord1()
{
   kill_note(guitarchannel,A2,guitarlevel);
   kill_note(guitarchannel,A1,guitarlevel);
}

void play_chord2()
{
   play_note(guitarchannel,G3,guitarlevel);
   play_note(guitarchannel,D3,guitarlevel);
}

void kill_chord2()
{
   kill_note(guitarchannel,G3,guitarlevel);
   kill_note(guitarchannel,D3,guitarlevel);
}

void play_chord3()
{
   play_note(guitarchannel,A3,guitarlevel);
   play_note(guitarchannel,E3,guitarlevel);
}

void kill_chord3()
{
   kill_note(guitarchannel,A3,guitarlevel);
   kill_note(guitarchannel,E3,guitarlevel);
}

void dostuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      play_chord1();
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      kill_chord1();
      notes[INDEX_F1]=0;
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


void showinfo()
{
   clrscr();
   cout << "Trail Blazer";
   wait_for_no(INDEX_ESC);
   cout << "\n[1    ]: Start";
   cout << "\nESC: Quit";
}

void go()
{
   int measure = 2;

   while (1)
   {
      cout << "\nMeasure: "<< ++ measure;
      if ((measure == 3) || (measure == 10) || (measure == 18)) play_note(drumchannel,CS2,127);
      if ((measure == 10) || (measure == 18)) play_note(hitchannel,AS4,127);
      play_note(drumchannel,DS2,127);
      if (delay1(speed)) break;
      if ((measure == 3) || (measure == 10) || (measure == 18)) kill_note(drumchannel,CS2,127);
      if ((measure == 10) || (measure == 18)) kill_note(hitchannel,AS4,127);
      if ((measure == 6) || (measure == 10) || (measure == 14) || (measure == 18)) play_chord3();
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      if ((measure == 10) || (measure == 18)) play_note(drumchannel,A2,127);
      if ((measure == 10) || (measure == 18)) play_note(hitchannel,A4,127);
      if (delay1(speed)) break;
      if ((measure == 6) || (measure == 10) || (measure == 14) || (measure == 18)) kill_chord3();

      if ((measure == 10) || (measure == 18)) kill_note(drumchannel,A2,127);
      if ((measure == 10) || (measure == 18)) kill_note(hitchannel,A4,127);

      if ((measure == 6) || (measure == 10) || (measure == 14) || (measure == 18)) play_chord3();
      play_note(drumchannel,DS2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,DS2,127);
      if (delay1(speed)) break;

      if ((measure == 10)|| (measure == 18)) play_note(drumchannel,CS2,127);
      if ((measure == 10) || (measure == 18)) play_note(hitchannel,G4,127);
      if (delay1(speed)) break;
      if ((measure == 6) || (measure == 10) || (measure == 14) || (measure == 18)) kill_chord3();

      kill_note(drumchannel,DS2,127);
      if ((measure == 10)|| (measure == 18)) kill_note(drumchannel,A2,127);
      if ((measure == 10) || (measure == 18)) kill_note(hitchannel,G4,127);

      play_note(drumchannel,DS2,127);
      play_note(drumchannel,D1,127);
      play_chord2();
      if (delay1(speed)) break;
      if ((measure == 10)|| (measure == 18)) play_note(drumchannel,A2,127);
      if ((measure == 10) || (measure == 18)) play_note(hitchannel,A4,127);
      if (delay1(speed)) break;
      kill_chord2();
      play_chord3();
      if ((measure == 10)|| (measure == 18)) kill_note(drumchannel,A2,127);
      if ((measure == 10) || (measure == 18)) kill_note(hitchannel,A4,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_chord3();
      kill_note(drumchannel,D1,127);
      kill_note(drumchannel,DS2,127);

      if (measure == 18) break;
   }

   while (1)
   {
      cout << "\nMeasure: "<< ++ measure;
      play_note(drumchannel,AS1,127);
      play_note(drumchannel,C1,127);
      play_chord1();
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_chord1();
      play_chord1();
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_chord1();

      play_chord1();
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_chord1();
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,AS1,127);
      play_note(drumchannel,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      play_chord1();
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_chord1();

      play_chord1();
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_chord1();
      play_chord1();
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      kill_note(drumchannel,D1,127);
      kill_chord1();
      if (measure == 34)
         break;

      cout << "\nMeasure: "<< ++ measure;
      play_note(drumchannel,AS1,127);
      play_note(drumchannel,C1,127);
      play_chord1();
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_chord1();
      play_chord1();
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_chord1();
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,C1,127);
      play_chord1();
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_chord1();
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,AS1,127);
      play_note(drumchannel,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      kill_note(drumchannel,D1,127);
      if (measure == 34)
         break;
   }
}

void main()
{
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        mix_mode();
        showinfo();
        change_program(drumchannel,120,0);
        change_program(basschannel,40,1);
        change_program(guitarchannel,37,2);
        change_effects_level(drumchannel,0);
        change_program(hitchannel,127,1);
        change_effects_channel(hitchannel);
        change_effects_level(1,0);
        change_effects_level(drumchannel,0);
        change_volume(guitarchannel,50);
        int measure;

        for (measure=3;measure<50;measure+=4)
        {
           bassnotes[measure][0] = A1;
           bassnotes[measure][1] = A1;
        }

        for (measure=4;measure<50;measure+=4)
        {
           bassnotes[measure][0] = A1;
           bassnotes[measure][1] = A1;
           bassnotes[measure][2] = A1;
        }

        for (measure=5;measure<50;measure+=4)
        {
           bassnotes[measure][0] = A1;
           bassnotes[measure][1] = A1;
        }

        for (measure=6;measure<50;measure+=4)
        {
           bassnotes[measure][0] = AS1;
           bassnotes[measure][1] = A1;
           bassnotes[measure][2] = G1;
           bassnotes[measure][3] = A1;
        }

        while (1)
        {
                delay1(1);
                if (key_table[INDEX_1])
                {
                   go();
                   showinfo();
                }
                if (key_table[INDEX_ESC]) break;
        }
        change_volume(guitarchannel,99);
                kill_keyboard();
                Exit_MIDI();
    }
