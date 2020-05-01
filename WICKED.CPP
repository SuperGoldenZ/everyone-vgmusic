#include "midi.h"
#include <dos.h>   
#include "keyboard.h"
   
int speed = 100; //old 160

int drumchannel = 10;
int drumlevel = 127;
int notes[127];
int synthnotes[10][16];

#define basschannel 2
#define basslevel 127

int chordchannel = 3;
int chordlevel = 127;

int bassnotes[50][8];

void menu()
{
   clrscr();
   cout << "Wicked Child";
   cout << "\n[ENTER]      Start";
   cout << "\n[ESC]        Quit";
}

void play_wicked_chord_F1()
{
   play_note(chordchannel,D5-12,chordlevel);
   play_note(chordchannel,A4-12,chordlevel);
   play_note(chordchannel,F4-12,chordlevel);
}

void kill_wicked_chord_F1()
{
   kill_note(chordchannel,D5-12,chordlevel);
   kill_note(chordchannel,A4-12,chordlevel);
   kill_note(chordchannel,F4-12,chordlevel);
}

void play_wicked_chord_F2()
{
   play_note(chordchannel,F5-12,chordlevel);
}

void kill_wicked_chord_F2()
{
   kill_note(chordchannel,F5-12,chordlevel);
}

void play_wicked_chord_F3()
{
   play_note(chordchannel,D4-12,chordlevel);
   play_note(chordchannel,AS4-12,chordlevel);
   play_note(chordchannel,F4-12,chordlevel);
}

void kill_wicked_chord_F3()
{
   kill_note(chordchannel,D4-12,chordlevel);
   kill_note(chordchannel,AS4-12,chordlevel);
   kill_note(chordchannel,F4-12,chordlevel);
}

void play_wicked_chord_F4()
{
   play_note(chordchannel,D5-12,chordlevel);
}

void kill_wicked_chord_F4()
{
   kill_note(chordchannel,D5-12,chordlevel);
}

void play_wicked_chord_F5()
{
   play_note(chordchannel,C5-12,chordlevel);
   play_note(chordchannel,A4-12,chordlevel);
   play_note(chordchannel,E4-12,chordlevel);
}

void kill_wicked_chord_F5()
{
   kill_note(chordchannel,C5-12,chordlevel);
   kill_note(chordchannel,A4-12,chordlevel);
   kill_note(chordchannel,E4-12,chordlevel);
}

void play_wicked_chord_F6()
{
   play_note(chordchannel,E4-12,chordlevel);
   play_note(chordchannel,C4-12,chordlevel);
   play_note(chordchannel,G4-12,chordlevel); //was a3
}

void kill_wicked_chord_F6()
{
   kill_note(chordchannel,E4-12,chordlevel);
   kill_note(chordchannel,C4-12,chordlevel);
   kill_note(chordchannel,G4-12,chordlevel); //was a3
}

void play_wicked_chord_F7()
{
   play_note(chordchannel,E5-12,chordlevel);
   play_note(chordchannel,A4-12,chordlevel);
   play_note(chordchannel,E4-12,chordlevel);
}

void kill_wicked_chord_F7()
{
   kill_note(chordchannel,E5-12,chordlevel);
   kill_note(chordchannel,A4-12,chordlevel);
   kill_note(chordchannel,E4-12,chordlevel);
}

void do_wicked_stuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      play_wicked_chord_F1();
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      kill_wicked_chord_F1();
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      play_wicked_chord_F2();
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      kill_wicked_chord_F2();
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      play_wicked_chord_F3();
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
      kill_wicked_chord_F3();
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
   {
      notes[INDEX_F4]=1;
      play_wicked_chord_F4();
   }

   if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
   {
      kill_wicked_chord_F4();
      notes[INDEX_F4]=0;
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      play_wicked_chord_F5();
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      kill_wicked_chord_F5();
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
   {
      notes[INDEX_F6]=1;
      play_wicked_chord_F6();
   }

   if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
   {
      kill_wicked_chord_F6();
      notes[INDEX_F6]=0;
   }

   if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
   {
      notes[INDEX_F7]=1;
      play_wicked_chord_F7();
   }

   if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
   {
      kill_wicked_chord_F7();
      notes[INDEX_F7]=0;
   }

}

int delay_wicked(int speed)
{
   for (int index=0;index<speed;index++)
   {
      if (key_table[INDEX_ESC]) return 1;
      delay(1);
      do_wicked_stuff();
   }
   return 0;
}

void wicked_child()
{
   cout << "\nSomething wicked this way comes...";
   int measure = 0;
   int index;

   for (index=0;index<1;index++)
   {
      play_note(10,CS1,127);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(10,CS1,127);
      play_note(10,CS1,127);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(10,CS1,127);
      play_note(10,CS1,127);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(10,CS1,127);
      cout << "\nMeasure: " << ++measure;
      play_note(10,D1,127);
      play_note(basschannel,B1,basslevel);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      kill_note(basschannel,B1,basslevel);
      play_note(basschannel,D2,basslevel);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(basschannel,D2,basslevel);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      play_note(basschannel,E2,basslevel);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
   }

   for (index=0;index<8;index++)
   {
      cout << "\nMeasure: " <<++ measure;
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);

      play_note(10,D1,127);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);

      play_note(10,C1,127);
      if ((measure == 3) || (measure == 7))
      {
         kill_note(basschannel,E2,basslevel);
         play_note(basschannel,E1,127);
      }
      if (measure == 5)
      {
         kill_note(basschannel,C2,127);
         play_note(basschannel,C2,127);
      }
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if ((measure == 3) || (measure == 7))
      {
         kill_note(basschannel,E1,127);
         play_note(basschannel,E2,127);
      }
      if (measure == 5)
      {
         kill_note(basschannel,C2,127);
         play_note(basschannel,B1,127);
      }
      if (measure == 9)
      {
         play_note(basschannel,B1+1,127);
      }

      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if ((measure == 3) || (measure == 7))
      {
         kill_note(basschannel,E2,127);
         play_note(basschannel,D2,127);
      }
      if (measure == 5)
      {
         kill_note(basschannel,B1,127);
         play_note(basschannel,D2,127);
      }

      kill_note(10,C1,127);

      play_note(10,D1,127);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if ((measure == 3) || (measure == 7))
      {
         kill_note(basschannel,D2,127);
         play_note(basschannel,C2,127);
      }
      if (measure == 5)
      {
         kill_note(basschannel,D2,127);
         play_note(basschannel,E2,127);
      }
      if (measure == 9)
      {
         kill_note(basschannel,B1+1,127);
         play_note(basschannel,B1+1,127);
      }
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      if (measure == 8)
         kill_note(basschannel,B1,127);
      if (measure == 9)
         kill_note(basschannel,B1+1,127);
   }
   cout << "!"; //starts measure 10
   for (index=0;index<4;index++)
   {
      cout << "\nMeasure: " <<++ measure;
      play_note(10,C1,127);
      if ((measure == 10) || (measure == 12) || (measure == 11) || (measure == 13)
          || (measure == 14))
         play_note(basschannel,B1,127);

      if (delay_wicked(speed)) break;
      if (measure == 14)
      {
         kill_note(basschannel,B1,127);
         play_note(basschannel,B1,127);
      }
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (measure == 14)
      {
         kill_note(basschannel,B1,127);
         play_note(basschannel,B1,127);
      }
      if ((measure == 10) || (measure == 12) || (measure == 11) || (measure == 13) | (measure == 15))
         kill_note(basschannel,B1,127);

      if (delay_wicked(speed)) break;
      if (measure == 14)
         play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      if (measure == 14)
         kill_note(basschannel,B1,127);

      play_note(10,D1,127);
      if (delay_wicked(speed)) break;

      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C1,127);
      if ((measure == 10) || (measure == 12) || (measure == 11) || (measure == 13))
         play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      if ((measure == 10) || (measure == 12) || (measure == 11) || (measure == 13))
      {
         kill_note(basschannel,B1,127);
      }
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);

      if ((measure == 10) || (measure == 12) || (measure == 11) || (measure == 13))
      {
         play_note(basschannel,B1,127);
      }

      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      if ((measure == 10) || (measure == 12) || (measure == 11) || (measure == 13))
      {
         kill_note(basschannel,B1,127);
      }

      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if ((measure == 11) || (measure == 13))
         play_note(basschannel,B1,127);

      if (delay_wicked(speed)) break;
      if ((measure == 11) || (measure == 13))
         kill_note(basschannel,B1,127);

      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      if ((measure == 11)|| (measure == 13))
         play_note(basschannel,B1+3,127);

      play_note(10,D1,127);
      if (delay_wicked(speed)) break;
      if ((measure == 11)|| (measure == 13))
         kill_note(basschannel,B1+3,127);

      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C1,127);
      if ((measure == 11)|| (measure == 13))
         play_note(basschannel,B1+5,127);
      if (delay_wicked(speed)) break;
      if ((measure == 11)|| (measure == 13))
         kill_note(basschannel,B1+5,127);

      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);

   }
   
   cout << "!"; //first measure is 4
   for (index=0;index<1;index++)
   {
      cout << "\nMeasure: " <<++ measure;
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);

      cout << "\nMeasure: " <<++ measure;
      
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(basschannel,B1+3,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1+3,127);
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C1,127);
      play_note(basschannel,B1+5,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1+5,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);

      cout << "\nMeasure: " <<++ measure;
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
//      speed--;      
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(basschannel,B1,127);
//      speed--;      
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
//      speed--;      
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(basschannel,B1,127);
//      speed--;      
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);

//      speed--;      
      cout << "\nMeasure: " <<++ measure;
      play_note(10,C1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      play_note(10,D1,127);
      play_note(basschannel,B1,127);

//      speed--;
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      play_note(basschannel,B1,127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      play_note(basschannel,B1,127);

//      speed--;
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      play_note(basschannel,B1,127);
      play_note(10,C1,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      kill_note(10,D1,127);
      play_note(10,D1,127);
      
      play_note(basschannel,B1+2,127);
//      speed--;
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1+2,127);
      if (delay_wicked(speed)) break;
      play_note(basschannel,B1+5,127);
      kill_note(10,D1,127);
      play_note(10,D1,127);
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,B1+5,127);
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
      kill_note(10,C1,127);
   }

   for (index=0;index<8;index++)
   {
      cout << "\nDouble bass speed: " << speed;
      cout << "\nMeasure " << ++measure ;
      cout << " one";
      play_note(10,FS1,127);
      play_note(10,C1,127);
//      if (measure != 18)
//         play_note(10,AS1,127);
      play_note(basschannel,bassnotes[measure][0],127);
      if (delay_wicked(speed)) break;
//      if (measure != 18)
//         kill_note(10,AS1,127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      kill_note(basschannel,bassnotes[measure][0],127);
      play_note(basschannel,bassnotes[measure][1],127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      kill_note(basschannel,bassnotes[measure][1],127);
      play_note(basschannel,bassnotes[measure][2],127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      cout << " two";
//      play_note(10,FS1,127);
      play_note(10,D1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,D1,127);
//      kill_note(10,FS1,127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      kill_note(basschannel,bassnotes[measure][2],127);
      play_note(basschannel,bassnotes[measure][3],127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      kill_note(basschannel,bassnotes[measure][3],127);
      play_note(basschannel,bassnotes[measure][4],127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      cout << " three";
      play_note(10,AS1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,bassnotes[measure][4],127);
      play_note(basschannel,bassnotes[measure][5],127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,bassnotes[measure][5],127);
      play_note(basschannel,bassnotes[measure][6],127);
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      cout << " four";
      play_note(10,D1,127);
//      play_note(10,FS1,127);
      if (delay_wicked(speed)) break;
//      kill_note(10,FS1,127);
      kill_note(10,D1,127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(basschannel,bassnotes[measure][6],127);
      play_note(basschannel,bassnotes[measure][7],127);
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,C1,127);
      play_note(10,C1,127);
      if (delay_wicked(speed)) break;
      kill_note(10,FS1,127);
      kill_note(basschannel,bassnotes[measure][7],127);
      kill_note(10,C1,127);
   }

   for (index=0;index<8;index++)
   {
      cout << "\nSlow measure " << ++measure;
      play_note(10,AS1,127);
      play_note(basschannel,bassnotes[measure][0],127);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(10,AS1,127);
      play_note(10,AS1,127);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(10,AS1,127);
      play_note(10,AS1,127);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(basschannel,bassnotes[measure][1],127);
      play_note(basschannel,bassnotes[measure][2],127);
      kill_note(10,AS1,127);
      play_note(10,AS1,127);
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      if (delay_wicked(speed)) break;
      kill_note(basschannel,bassnotes[measure][3],127);
      kill_note(10,AS1,127);
   }
}

void main()
{   
   GetBlastInfo(&blastInfo);   
   MIDIType = SBMIDI;   
   DSPReset();   
   Init_MIDI();   
   char control;   
   int value;   
   int channel;   
   install_keyboard();   
   for (int index=0;index<127;index++)   
      notes[index] = 0;   

   bassnotes[18][0] = (B1+5);
   bassnotes[18][1] = (B1+5+12);
   bassnotes[18][2] = (B1+5);
   bassnotes[18][3] = (B1+5+12);
   bassnotes[18][4] = (B1+5);
   bassnotes[18][5] = (B1+5+12);
   bassnotes[18][6] = (B1+5);
   bassnotes[18][7] = (B1+5+12);

   bassnotes[19][0] = (B1+5);
   bassnotes[19][1] = (B1+5+12);
   bassnotes[19][2] = (B1+5);
   bassnotes[19][3] = (B1+5+12);
   bassnotes[19][4] = (B1+5);
   bassnotes[19][5] = (B1+5+12);
   bassnotes[19][6] = (B1+5);
   bassnotes[19][7] = (B1+5+12);

   bassnotes[20][0] = (B1+1);
   bassnotes[20][1] = (B1+1+12);
   bassnotes[20][2] = (B1+1);
   bassnotes[20][3] = (B1+1+12);
   bassnotes[20][4] = (B1+1);
   bassnotes[20][5] = (B1+1+12);
   bassnotes[20][6] = (B1+1);
   bassnotes[20][7] = (B1+1+12);

   bassnotes[21][0] = (B1+1);
   bassnotes[21][1] = (B1+1+12);
   bassnotes[21][2] = (B1+1);
   bassnotes[21][3] = (B1+1+12);
   bassnotes[21][4] = (B1+1);
   bassnotes[21][5] = (B1+1+12);
   bassnotes[21][6] = (B1+2);
   bassnotes[21][7] = (B1+3);

   bassnotes[26][0] = C3-12;
   bassnotes[26][1] = C3-12;
   bassnotes[26][2] = D3-12;
   bassnotes[26][3] = E3-12;

   bassnotes[27][0] = C3-12;
   bassnotes[27][1] = C3-12;
   bassnotes[27][2] = D3-12;
   bassnotes[27][3] = E3-12;

   bassnotes[28][0] = D3-12;
   bassnotes[28][1] = D3-12;
   bassnotes[28][2] = E3-12;
   bassnotes[28][3] = F3-12;

   bassnotes[29][0] = D3-12;
   bassnotes[29][1] = D3-12;
   bassnotes[29][2] = E3-12;
   bassnotes[29][3] = F3-12;

   bassnotes[30][0] = C3-12;
   bassnotes[30][1] = C3-12;
   bassnotes[30][2] = D3-12;
   bassnotes[30][3] = E3-12;

   bassnotes[31][0] = C3-12;
   bassnotes[31][1] = C3-12;
   bassnotes[31][2] = D3-12;
   bassnotes[31][3] = E3-12;

   bassnotes[32][0] = D3-12;
   bassnotes[32][1] = D3-12;
   bassnotes[32][2] = E3-12;
   bassnotes[32][3] = F3-12;

   bassnotes[33][0] = D3-12;
   bassnotes[33][1] = D3-12;
   bassnotes[33][2] = E3-12;
   bassnotes[33][3] = F3-12;

   for (int measure=22;measure<22+4;measure++)
      for (int note=0; note<8; note++)
         bassnotes[measure][note] = bassnotes[measure-4][note];

   change_program(1,90,1); //old 54 3
   change_program(2,41,1);
   change_program(3,0,0);
   change_program(10,120,1);
   change_volume(1,99);
   change_volume(2,99);
   change_volume(3,99);
   change_volume(10,99);
   mix_name("Wicked   ");
   menu();
   while (1)   
   {   
      if (key_table[INDEX_ENTER])
      {
         wicked_child();
         wait_for_no(INDEX_ENTER);
         wait_for_no(INDEX_ESC);
         menu();
      }
      do_wicked_stuff();
      if (key_table[INDEX_ESC]) break;
   }   
   Exit_MIDI();   
   kill_keyboard();   
   cout << "\n\nwicked.cpp terminated";   
}
