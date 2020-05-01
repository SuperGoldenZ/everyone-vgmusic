#include "midi.h"
#include "lights.h"
#include <dos.h>
#include "keyboard.h"
   
int speed = 125; //old 160

int drumchannel = 10;
int drumlevel = 127;
//int notes[127];

int chordchannel = 2;
int chordlevel = 127;
int chordminus = 30;
int chordminus2 = 30;
int doodlechannel = 3;
int doodlelevel = 120;
int apeshit = 0;

int powerleadchannel = 4;
int powerleadlevel = 127;

int doodlenotes[100][16];

void menu()
{
   clrscr();
   cout << "Shadowgate";
   cout << "\n[SPACE] Bass kick";
   cout << "\n[ENTER] Died drums";
   cout << "\n[ESC]   Quit";
}

void play_dead_chord_F1()
{
   play_note(chordchannel,G4,chordlevel-chordminus);
   play_note(chordchannel,DS4,chordlevel-chordminus);
   play_note(chordchannel,C4,chordlevel-chordminus);

   play_note(chordchannel,G5,chordlevel-chordminus);
   play_note(chordchannel,DS5,chordlevel-chordminus);
   play_note(chordchannel,C5,chordlevel-chordminus);
}

void play_dead_chord_F2()
{
   play_note(chordchannel,GS4,chordlevel-chordminus);
   play_note(chordchannel,DS4,chordlevel-chordminus);
   play_note(chordchannel,C4,chordlevel-chordminus);

   play_note(chordchannel,GS5,chordlevel-chordminus);
   play_note(chordchannel,DS5,chordlevel-chordminus);
   play_note(chordchannel,C5,chordlevel-chordminus);
}

void play_dead_chord_F3()
{
   play_note(chordchannel,F4,chordlevel-chordminus);
   play_note(chordchannel,D4,chordlevel-chordminus);
   play_note(chordchannel,AS3,chordlevel-chordminus);

   play_note(chordchannel,F5,chordlevel-chordminus);
   play_note(chordchannel,D5,chordlevel-chordminus);
   play_note(chordchannel,AS4,chordlevel-chordminus);
}

void play_dead_chord_F4()
{
   play_note(chordchannel,GS4,chordlevel-chordminus);
   play_note(chordchannel,F4,chordlevel-chordminus);
   play_note(chordchannel,C4,chordlevel-chordminus);

   play_note(chordchannel,GS5,chordlevel-chordminus);
   play_note(chordchannel,F5,chordlevel-chordminus);
   play_note(chordchannel,C5,chordlevel-chordminus);
}

void play_dead_chord_F5()
{
   play_note(chordchannel,G4,chordlevel-chordminus);
   play_note(chordchannel,F4,chordlevel-chordminus);
   play_note(chordchannel,C4,chordlevel-chordminus);

   play_note(chordchannel,G5,chordlevel-chordminus);
   play_note(chordchannel,F5,chordlevel-chordminus);
   play_note(chordchannel,C5,chordlevel-chordminus);
}

void kill_dead_chord_F1()
{
   kill_note(chordchannel,G4,chordlevel-chordminus);
   kill_note(chordchannel,DS4,chordlevel-chordminus);
   kill_note(chordchannel,C4,chordlevel-chordminus);

   kill_note(chordchannel,G5,chordlevel-chordminus);
   kill_note(chordchannel,DS5,chordlevel-chordminus);
   kill_note(chordchannel,C5,chordlevel-chordminus);
}

void kill_dead_chord_F2()
{
   kill_note(chordchannel,GS4,chordlevel-chordminus);
   kill_note(chordchannel,DS4,chordlevel-chordminus);
   kill_note(chordchannel,C4,chordlevel-chordminus);

   kill_note(chordchannel,GS5,chordlevel-chordminus);
   kill_note(chordchannel,DS5,chordlevel-chordminus);
   kill_note(chordchannel,C5,chordlevel-chordminus);
}

void kill_dead_chord_F3()
{
   kill_note(chordchannel,F4,chordlevel-chordminus);
   kill_note(chordchannel,D4,chordlevel-chordminus);
   kill_note(chordchannel,AS3,chordlevel-chordminus);

   kill_note(chordchannel,F5,chordlevel-chordminus);
   kill_note(chordchannel,D5,chordlevel-chordminus);
   kill_note(chordchannel,AS4,chordlevel-chordminus);
}

void kill_dead_chord_F4()
{
   kill_note(chordchannel,GS4,chordlevel-chordminus);
   kill_note(chordchannel,F4,chordlevel-chordminus);
   kill_note(chordchannel,C4,chordlevel-chordminus);

   kill_note(chordchannel,GS5,chordlevel-chordminus);
   kill_note(chordchannel,F5,chordlevel-chordminus);
   kill_note(chordchannel,C5,chordlevel-chordminus);
}

void kill_dead_chord_F5()
{
   kill_note(chordchannel,G4,chordlevel-chordminus);
   kill_note(chordchannel,F4,chordlevel-chordminus);
   kill_note(chordchannel,C4,chordlevel-chordminus);

   kill_note(chordchannel,G5,chordlevel-chordminus);
   kill_note(chordchannel,F5,chordlevel-chordminus);
   kill_note(chordchannel,C5,chordlevel-chordminus);
}

void play_dead_chord_1()
{
   play_note(chordchannel,G3,chordlevel-chordminus2);
   play_note(chordchannel,AS3,chordlevel-chordminus2);
   play_note(chordchannel,D4,chordlevel-chordminus2);

   play_note(chordchannel,D5,chordlevel-chordminus2);
   play_note(chordchannel,AS4,chordlevel-chordminus2);
   play_note(chordchannel,G4,chordlevel-chordminus2);
}

void play_dead_chord_2()
{
   play_note(chordchannel,G3,chordlevel-chordminus2);
   play_note(chordchannel,AS3,chordlevel-chordminus2);
   play_note(chordchannel,DS4,chordlevel-chordminus2);

   play_note(chordchannel,DS5,chordlevel-chordminus2);
   play_note(chordchannel,AS4,chordlevel-chordminus2);
   play_note(chordchannel,G4,chordlevel-chordminus2);
}

void play_dead_chord_3()
{
   play_note(chordchannel,C4,chordlevel-chordminus2);
   play_note(chordchannel,A3,chordlevel-chordminus2);
   play_note(chordchannel,F3,chordlevel-chordminus2);

   play_note(chordchannel,C5,chordlevel-chordminus2);
   play_note(chordchannel,A4,chordlevel-chordminus2);
   play_note(chordchannel,F4,chordlevel-chordminus2);
}

void play_dead_chord_4()
{
   play_note(chordchannel,DS4,chordlevel-chordminus2);
   play_note(chordchannel,C4,chordlevel-chordminus2);
   play_note(chordchannel,G3,chordlevel-chordminus2);

   play_note(chordchannel,DS5,chordlevel-chordminus2);
   play_note(chordchannel,C5,chordlevel-chordminus2);
   play_note(chordchannel,G4,chordlevel-chordminus2);
}

void play_dead_chord_5()
{
   play_note(chordchannel,D4,chordlevel-chordminus2);
   play_note(chordchannel,C4,chordlevel-chordminus2);
   play_note(chordchannel,G3,chordlevel-chordminus2);

   play_note(chordchannel,D5,chordlevel-chordminus2);
   play_note(chordchannel,C5,chordlevel-chordminus2);
   play_note(chordchannel,G4,chordlevel-chordminus2);
}

void kill_dead_chord_1()
{
   kill_note(chordchannel,G3,chordlevel-chordminus2);
   kill_note(chordchannel,AS3,chordlevel-chordminus2);
   kill_note(chordchannel,D4,chordlevel-chordminus2);

   kill_note(chordchannel,D5,chordlevel-chordminus2);
   kill_note(chordchannel,AS4,chordlevel-chordminus2);
   kill_note(chordchannel,G4,chordlevel-chordminus2);
}

void kill_dead_chord_2()
{
   kill_note(chordchannel,G3,chordlevel-chordminus2);
   kill_note(chordchannel,AS3,chordlevel-chordminus2);
   kill_note(chordchannel,DS4,chordlevel-chordminus2);

   kill_note(chordchannel,DS5,chordlevel-chordminus2);
   kill_note(chordchannel,AS4,chordlevel-chordminus2);
   kill_note(chordchannel,G4,chordlevel-chordminus2);
}

void kill_dead_chord_3()
{
   kill_note(chordchannel,C4,chordlevel-chordminus2);
   kill_note(chordchannel,A3,chordlevel-chordminus2);
   kill_note(chordchannel,F3,chordlevel-chordminus2);

   kill_note(chordchannel,C5,chordlevel-chordminus2);
   kill_note(chordchannel,A4,chordlevel-chordminus2);
   kill_note(chordchannel,F4,chordlevel-chordminus2);
}

void kill_dead_chord_4()
{
   kill_note(chordchannel,DS4,chordlevel-chordminus2);
   kill_note(chordchannel,C4,chordlevel-chordminus2);
   kill_note(chordchannel,G3,chordlevel-chordminus2);

   kill_note(chordchannel,DS5,chordlevel-chordminus2);
   kill_note(chordchannel,C5,chordlevel-chordminus2);
   kill_note(chordchannel,G4,chordlevel-chordminus2);
}

void kill_dead_chord_5()
{
   kill_note(chordchannel,D4,chordlevel-chordminus2);
   kill_note(chordchannel,C4,chordlevel-chordminus2);
   kill_note(chordchannel,G3,chordlevel-chordminus2);

   kill_note(chordchannel,D5,chordlevel-chordminus2);
   kill_note(chordchannel,C5,chordlevel-chordminus2);
   kill_note(chordchannel,G4,chordlevel-chordminus2);
}

int odd(int num)
{
   if ((num%2) == 0)
      return 0;
   return 1;
}

void do_dead_stuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      play_dead_chord_F1();
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      kill_dead_chord_F1();
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      play_dead_chord_F2();
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      kill_dead_chord_F2();
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      play_dead_chord_F3();
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
      kill_dead_chord_F3();
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
   {
      notes[INDEX_F4]=1;
      play_dead_chord_F4();
   }

   if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
   {
      kill_dead_chord_F4();
      notes[INDEX_F4]=0;
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      play_dead_chord_F5();
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      kill_dead_chord_F5();
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_11] == 0) && (key_table[INDEX_11]==1))
   {
      notes[INDEX_11]=1;
      play_dead_chord_1();
   }

   if ((notes[INDEX_11] == 1) && (key_table[INDEX_11]==0))
   {
      kill_dead_chord_1();
      notes[INDEX_11]=0;
   }

   if ((notes[INDEX_21] == 0) && (key_table[INDEX_21]==1))
   {
      notes[INDEX_21]=1;
      play_dead_chord_2();
   }

   if ((notes[INDEX_21] == 1) && (key_table[INDEX_21]==0))
   {
      kill_dead_chord_2();
      notes[INDEX_21]=0;
   }

   if ((notes[INDEX_31] == 0) && (key_table[INDEX_31]==1))
   {
      notes[INDEX_31]=1;
      play_dead_chord_3();
   }

   if ((notes[INDEX_31] == 1) && (key_table[INDEX_31]==0))
   {
      kill_dead_chord_3();
      notes[INDEX_31]=0;
   }

   if ((notes[INDEX_41] == 0) && (key_table[INDEX_41]==1))
   {
      notes[INDEX_41]=1;
      play_dead_chord_4();
   }

   if ((notes[INDEX_41] == 1) && (key_table[INDEX_41]==0))
   {
      kill_dead_chord_4();
      notes[INDEX_41]=0;
   }

   if ((notes[INDEX_51] == 0) && (key_table[INDEX_51]==1))
   {
      notes[INDEX_51]=1;
      play_dead_chord_5();
   }

   if ((notes[INDEX_51] == 1) && (key_table[INDEX_51]==0))
   {
      kill_dead_chord_5();
      notes[INDEX_51]=0;
   }

   if ((notes[INDEX_F12] == 0) && (key_table[INDEX_F12]==1))
   {
      notes[INDEX_F12]=1;
      play_note(doodlechannel,G5,doodlelevel);
   }

   if ((notes[INDEX_F12] == 1) && (key_table[INDEX_F12]==0))
   {
      kill_note(doodlechannel,G5,doodlelevel);
      notes[INDEX_F12]=0;
   }

   if ((notes[INDEX_F11] == 0) && (key_table[INDEX_F11]==1))
   {
      notes[INDEX_F11]=1;
      play_note(doodlechannel,DS5,doodlelevel);
   }

   if ((notes[INDEX_F11] == 1) && (key_table[INDEX_F11]==0))
   {
      kill_note(doodlechannel,DS5,doodlelevel);
      notes[INDEX_F11]=0;
   }

   if ((notes[INDEX_F10] == 0) && (key_table[INDEX_F10]==1))
   {
      notes[INDEX_F10]=1;
      play_note(doodlechannel,D5,doodlelevel);
   }

   if ((notes[INDEX_F10] == 1) && (key_table[INDEX_F10]==0))
   {
      kill_note(doodlechannel,D5,doodlelevel);
      notes[INDEX_F10]=0;
   }

   if ((notes[INDEX_F9] == 0) && (key_table[INDEX_F9]==1))
   {
      notes[INDEX_F9]=1;
      play_note(doodlechannel,C5,doodlelevel);
   }

   if ((notes[INDEX_F9] == 1) && (key_table[INDEX_F9]==0))
   {
      kill_note(doodlechannel,C5,doodlelevel);
      notes[INDEX_F9]=0;
   }

   if ((notes[INDEX_BACKSPACE] == 0) && (key_table[INDEX_BACKSPACE]==1))
   {
      notes[INDEX_BACKSPACE]=1;
      play_note(doodlechannel,GS5,doodlelevel);
   }

   if ((notes[INDEX_BACKSPACE] == 1) && (key_table[INDEX_BACKSPACE]==0))
   {
      kill_note(doodlechannel,GS5,doodlelevel);
      notes[INDEX_BACKSPACE]=0;
   }

   if ((notes[INDEX_BACKSLASH] == 0) && (key_table[INDEX_BACKSLASH]==1))
   {
      notes[INDEX_BACKSLASH]=1;
      play_note(doodlechannel,DS5,doodlelevel);
   }

   if ((notes[INDEX_BACKSLASH] == 1) && (key_table[INDEX_BACKSLASH]==0))
   {
      kill_note(doodlechannel,DS5,doodlelevel);
      notes[INDEX_BACKSLASH]=0;
   }

   if ((notes[INDEX_EQUAL] == 0) && (key_table[INDEX_EQUAL]==1))
   {
      notes[INDEX_EQUAL]=1;
      play_note(doodlechannel,D5,doodlelevel);
   }

   if ((notes[INDEX_EQUAL] == 1) && (key_table[INDEX_EQUAL]==0))
   {
      kill_note(doodlechannel,D5,doodlelevel);
      notes[INDEX_EQUAL]=0;
   }

   if ((notes[INDEX_MINUS] == 0) && (key_table[INDEX_MINUS]==1))
   {
      notes[INDEX_MINUS]=1;
      play_note(doodlechannel,C5,doodlelevel);
   }

   if ((notes[INDEX_MINUS] == 1) && (key_table[INDEX_MINUS]==0))
   {
      kill_note(doodlechannel,C5,doodlelevel);
      notes[INDEX_MINUS]=0;
   }

   if ((notes[INDEX_RIGHTSQUAREBRACE] == 0) && (key_table[INDEX_RIGHTSQUAREBRACE]==1))
   {
      notes[INDEX_RIGHTSQUAREBRACE]=1;
      play_note(doodlechannel,F5,doodlelevel);
   }

   if ((notes[INDEX_RIGHTSQUAREBRACE] == 1) && (key_table[INDEX_RIGHTSQUAREBRACE]==0))
   {
      kill_note(doodlechannel,F5,doodlelevel);
      notes[INDEX_RIGHTSQUAREBRACE]=0;
   }

   if ((notes[INDEX_LEFTSQUAREBRACE] == 0) && (key_table[INDEX_LEFTSQUAREBRACE]==1))
   {
      notes[INDEX_LEFTSQUAREBRACE]=1;
      play_note(doodlechannel,G5,doodlelevel);
   }

   if ((notes[INDEX_LEFTSQUAREBRACE] == 1) && (key_table[INDEX_LEFTSQUAREBRACE]==0))
   {
      kill_note(doodlechannel,G5,doodlelevel);
      notes[INDEX_LEFTSQUAREBRACE]=0;
   }

   if ((notes[INDEX_P] == 0) && (key_table[INDEX_P]==1))
   {
      notes[INDEX_P]=1;
      play_note(doodlechannel,GS5,doodlelevel);
   }

   if ((notes[INDEX_P] == 1) && (key_table[INDEX_P]==0))
   {
      kill_note(doodlechannel,GS5,doodlelevel);
      notes[INDEX_P]=0;
   }

   if ((notes[INDEX_O] == 0) && (key_table[INDEX_O]==1))
   {
      notes[INDEX_O]=1;
      play_note(doodlechannel,G5,doodlelevel);
   }

   if ((notes[INDEX_O] == 1) && (key_table[INDEX_O]==0))
   {
      kill_note(doodlechannel,G5,doodlelevel);
      notes[INDEX_O]=0;
   }

   if ((notes[INDEX_QUOTE] == 0) && (key_table[INDEX_QUOTE]==1))
   {
      notes[INDEX_QUOTE]=1;
      play_note(doodlechannel,D5,doodlelevel);
   }

   if ((notes[INDEX_QUOTE] == 1) && (key_table[INDEX_QUOTE]==0))
   {
      kill_note(doodlechannel,D5,doodlelevel);
      notes[INDEX_QUOTE]=0;
   }

   if ((notes[INDEX_COLIN] == 0) && (key_table[INDEX_COLIN]==1))
   {
      notes[INDEX_COLIN]=1;
      play_note(doodlechannel,AS4,doodlelevel);
   }

   if ((notes[INDEX_COLIN] == 1) && (key_table[INDEX_COLIN]==0))
   {
      kill_note(doodlechannel,AS4,doodlelevel);
      notes[INDEX_COLIN]=0;
   }

   if ((notes[INDEX_L] == 0) && (key_table[INDEX_L]==1))
   {
      notes[INDEX_L]=1;
      play_note(doodlechannel,A4,doodlelevel);
   }

   if ((notes[INDEX_L] == 1) && (key_table[INDEX_L]==0))
   {
      kill_note(doodlechannel,A4,doodlelevel);
      notes[INDEX_L]=0;
   }

   if ((notes[INDEX_K] == 0) && (key_table[INDEX_K]==1))
   {
      notes[INDEX_K]=1;
      play_note(doodlechannel,G4,doodlelevel);
   }

   if ((notes[INDEX_K] == 1) && (key_table[INDEX_K]==0))
   {
      kill_note(doodlechannel,G4,doodlelevel);
      notes[INDEX_K]=0;
   }

   if ((notes[INDEX_SLASH] == 0) && (key_table[INDEX_SLASH]==1))
   {
      notes[INDEX_SLASH]=1;
      play_note(doodlechannel,DS5,doodlelevel);
   }

   if ((notes[INDEX_SLASH] == 1) && (key_table[INDEX_SLASH]==0))
   {                            
      kill_note(doodlechannel,DS5,doodlelevel);
      notes[INDEX_SLASH]=0;
   }

   if ((notes[INDEX_GREATERTHAN] == 0) && (key_table[INDEX_GREATERTHAN]==1))
   {
      notes[INDEX_GREATERTHAN]=1;
      play_note(doodlechannel,AS4,doodlelevel);
   }

   if ((notes[INDEX_GREATERTHAN] == 1) && (key_table[INDEX_GREATERTHAN]==0))
   {                            
      kill_note(doodlechannel,AS4,doodlelevel);
      notes[INDEX_GREATERTHAN]=0;
   }

   if ((notes[INDEX_LESSTHAN] == 0) && (key_table[INDEX_LESSTHAN]==1))
   {
      notes[INDEX_LESSTHAN]=1;
      play_note(doodlechannel,A4,doodlelevel);
   }

   if ((notes[INDEX_LESSTHAN] == 1) && (key_table[INDEX_LESSTHAN]==0))
   {                            
      kill_note(doodlechannel,A4,doodlelevel);
      notes[INDEX_LESSTHAN]=0;
   }

   if ((notes[INDEX_M] == 0) && (key_table[INDEX_M]==1))
   {
      notes[INDEX_M]=1;
      play_note(doodlechannel,G4,doodlelevel);
   }

   if ((notes[INDEX_M] == 1) && (key_table[INDEX_M]==0))
   {                            
      kill_note(doodlechannel,G4,doodlelevel);
      notes[INDEX_M]=0;
   }

   if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))
   {
      notes[INDEX_LEFT]=1;
      play_note(doodlechannel,C5,doodlelevel);
   }

   if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))
   {
      kill_note(doodlechannel,C5,doodlelevel);
      notes[INDEX_LEFT]=0;
   }

   if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))
   {
      notes[INDEX_DOWN]=1;
      play_note(doodlechannel,D5,doodlelevel);
   }

   if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))
   {
      kill_note(doodlechannel,D5,doodlelevel);
      notes[INDEX_DOWN]=0;
   }

   if ((notes[INDEX_RIGHT] == 0) && (key_table[INDEX_RIGHT]==1))
   {
      notes[INDEX_RIGHT]=1;
      play_note(doodlechannel,DS5,doodlelevel);
   }

   if ((notes[INDEX_RIGHT] == 1) && (key_table[INDEX_RIGHT]==0))
   {
      kill_note(doodlechannel,DS5,doodlelevel);
      notes[INDEX_RIGHT]=0;
   }

   if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
   {
      notes[INDEX_UP]=1;
      play_note(doodlechannel,D5,doodlelevel);
   }

   if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))
   {
      kill_note(doodlechannel,D5,doodlelevel);
      notes[INDEX_UP]=0;
   }

}

int delay_dead(int speed)
{
   for (int index=0;index<speed;index++)
   {
      if (key_table[INDEX_ESC]) return 1;
      delay(1);
      do_dead_stuff();
   }
   return 0;
}

void dead_drums(int speed)
{
   clrscr();
   cout << "shadow.cpp running dead drums";
/*   while (1)
   {
         cout << "\n1";
         play_note(drumchannel,CS2,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         play_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         kill_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;

         cout << "\n2";
         play_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         kill_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         play_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         kill_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         play_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         kill_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
   }*/

   int volume = 99;
   //start loop
   for (int measure = 10;measure<65;measure++)  //old 70
   {
      cout << "\nMeasure: " << measure;
      if ((measure == 10) || (measure == 12))
      {
         play_note(drumchannel,CS2,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         play_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         kill_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
      }

      if ((measure == 11) || (measure == 13))
      {
         play_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         kill_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         play_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         kill_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         play_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,36,127);
         kill_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
      }

      if ((measure == 14) || (measure == 15))
      {
         play_note(drumchannel,CS2,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,AS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,AS1,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,AS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,AS1,127);
         play_note(drumchannel,FS1,127);
         if (measure == 15)
            play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         if (measure == 15)
            kill_note(drumchannel,36,127);
         play_note(drumchannel,AS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,AS1,127);
      }

      if (measure == 16)
      {
         play_note(drumchannel,CS2,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,AS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,AS1,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,CS2,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,AS1,127);
         if (delay_dead(speed)) break;
         if (delay_dead(speed)) break;
         kill_note(drumchannel,AS1,127);
         play_note(drumchannel,FS1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,D2,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,D2,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D2,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D2,127);
         play_note(drumchannel,D2,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,D2,127);
      }

      if (measure == 17)
      {
         play_note(drumchannel,CS2,127);
         play_note(drumchannel,C2,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,D1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,C2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,36,127);

         play_note(drumchannel,C2,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,C2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,D1,127);

         play_note(drumchannel,C2,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,C2,127);
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D1,127);

         play_note(drumchannel,B1,127);
         play_note(drumchannel,D1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,B1,127);
         kill_note(drumchannel,D1,127);

         play_note(drumchannel,CS2,127);
         play_note(drumchannel,B1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,D1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,B1,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,36,127);

         play_note(drumchannel,B1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,B1,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,D1,127);

         play_note(drumchannel,AS1,127);
         play_note(drumchannel,A1,127);
         play_note(drumchannel,D1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,A1,127);
         kill_note(drumchannel,D1,127);

         play_note(drumchannel,A1,127);
         play_note(drumchannel,D1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,A1,127);
         kill_note(drumchannel,D1,127);

         play_note(drumchannel,CS2,127);
         play_note(drumchannel,A1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,D1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,A1,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,36,127);

         play_note(drumchannel,G1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,D1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,G1,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,36,127);

         play_note(drumchannel,CS2,127);
         play_note(drumchannel,D1,127);
         play_note(drumchannel,G1,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,G1,127);
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,D1,127);
         play_note(drumchannel,G1,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,G1,127);

         play_note(drumchannel,CS2,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,F1,127);
         play_note(drumchannel,D1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         change_volume(1,85);
         change_volume(powerleadchannel,99);
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,F1,127);
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,36,127);

         play_note(drumchannel,CS2,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,F1,127);
         play_note(drumchannel,D1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,F1,127);
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,36,127);

         play_note(drumchannel,CS2,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,F1,127);
         play_note(drumchannel,D1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,F1,127);
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,36,127);

         play_note(drumchannel,CS2,127);
         play_note(drumchannel,F1,127);
         play_note(drumchannel,D1,127);
         play_note(drumchannel,36,127);
         if (delay_dead(speed)) break;
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,F1,127);
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,36,127);
         //old change powerlead
         //change_program(1,90,1);
         //old change program
      }

      if ((measure > 17) && (odd(measure)==0))
      {
         if ((measure == 34) && (apeshit == 0))
         {
            change_light_level(1,0);
            change_light_level(2,0);
            change_light_level(4,0);
            change_light_level(9,127);
            apeshit = 1;
         }

         play_note(drumchannel,CS2,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,C1,drumlevel);
         if (measure == 50)
            cout << "\nfading out one";
         else
            cout << " one ";
         if (measure >= 50)
         {
            change_volume(chordchannel,volume--);
            chordlevel--;
            doodlelevel--;
            drumlevel--;
         }
         if (measure >= 34)
            play_note(doodlechannel,doodlenotes[measure][0],doodlelevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][0],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][1],doodlelevel);
         }
         kill_note(drumchannel,CS2,drumlevel);
         kill_note(drumchannel,FS1,drumlevel);
         kill_note(drumchannel,C1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][1],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][2],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][2],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][3],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][3],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][4],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,AS1,drumlevel);
         play_note(drumchannel,D1,drumlevel);
         cout << " two ";
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][4],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][5],doodlelevel);
         }
         if (measure >= 50)
         {
            doodlelevel--;
            drumlevel--;
         }
         kill_note(drumchannel,AS1,drumlevel);
         kill_note(drumchannel,D1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][5],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][6],doodlelevel);
         }
         if (measure >= 50)
         {
            change_volume(powerleadchannel,volume--);
            chordlevel--;
            doodlelevel--;
            drumlevel--;
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][6],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][7],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][7],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][8],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,C1,drumlevel);
         cout << " three ";
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][8],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][9],doodlelevel);
         }
         if (measure >= 50)
         {
            doodlelevel--;
            drumlevel--;
         }
         kill_note(drumchannel,FS1,drumlevel);
         kill_note(drumchannel,C1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][9],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][10],doodlelevel);
         }
         if (measure >= 50)
         {
            change_volume(powerleadchannel,volume--);
            doodlelevel--;
            chordlevel--;
            drumlevel--;
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][10],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][11],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][11],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][12],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,AS1,drumlevel);
         play_note(drumchannel,D1,drumlevel);
         cout << " four ";
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][12],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][13],doodlelevel);
         }
         if (measure >= 50)
         {
            doodlelevel--;
            drumlevel--;
         }
         kill_note(drumchannel,AS1,drumlevel);
         kill_note(drumchannel,D1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][13],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][14],doodlelevel);
         }
         if (measure >= 50)
         {
            change_volume(powerleadchannel,volume--);
            doodlelevel--;
            chordlevel--;
            drumlevel--;
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,C1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][14],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][15],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         kill_note(drumchannel,C1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][15],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
      }

      if ((measure > 17) && (odd(measure)==1))
      {
         if ((apeshit == 1) && (measure == 41))
         {
            change_light_level(1,50);
            change_light_level(2,75);
            change_light_level(3,25);
            change_light_level(4,50);
            change_light_level(9,0);
         }

         play_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,C1,drumlevel);
         cout << " one ";
         if (measure >= 34)
         {
            play_note(doodlechannel,doodlenotes[measure][0],doodlelevel);
         }
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][0],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][1],doodlelevel);
         }
         if (measure >= 50)
         {
            doodlelevel--;
            drumlevel--;
         }
         kill_note(drumchannel,FS1,drumlevel);
         kill_note(drumchannel,C1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][1],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][2],doodlelevel);
         }
         if (measure >= 50)
         {
            change_volume(powerleadchannel,volume--);
            doodlelevel--;
            chordlevel--;
            drumlevel--;
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][2],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][3],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][3],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][4],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,AS1,drumlevel);
         play_note(drumchannel,D1,drumlevel);
         cout << " two ";
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][4],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][5],doodlelevel);
         }
         if (measure >= 50)
         {
            doodlelevel--;
            drumlevel--;
         }
         kill_note(drumchannel,AS1,drumlevel);
         kill_note(drumchannel,D1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][5],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][6],doodlelevel);
         }
         if (measure >= 50)
         {
            change_volume(powerleadchannel,volume--);
            doodlelevel--;
            chordlevel--;
            drumlevel--;
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][6],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][7],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][7],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][8],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,C1,drumlevel);
         cout << " three ";
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][8],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][9],doodlelevel);
         }
         if (measure >= 50)
         {
            doodlelevel--;
            drumlevel--;
         }
         kill_note(drumchannel,FS1,drumlevel);
         kill_note(drumchannel,C1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][9],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][10],doodlelevel);
         }
         if (measure >= 50)
         {
            change_volume(powerleadchannel,volume--);
            doodlelevel--;
            chordlevel--;
            drumlevel--;
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][10],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][11],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][11],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][12],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,AS1,drumlevel);
         play_note(drumchannel,D1,drumlevel);
         cout << " four ";
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][12],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][13],doodlelevel);
         }
         if (measure >= 50)
         {
            doodlelevel--;
            drumlevel--;
         }
         kill_note(drumchannel,AS1,drumlevel);
         kill_note(drumchannel,D1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,C1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][13],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][14],doodlelevel);
         }
         if (measure >= 50)
         {
            change_volume(powerleadchannel,volume--);
            doodlelevel--;
            chordlevel--;
            drumlevel--;
         }
         kill_note(drumchannel,C1,drumlevel);
         kill_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         play_note(drumchannel,C1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][14],doodlelevel);
            play_note(doodlechannel,doodlenotes[measure][15],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
         kill_note(drumchannel,C1,drumlevel);
         play_note(drumchannel,FS1,drumlevel);
         if (delay_dead(speed)) break;
         if (measure >= 34)
         {
            kill_note(doodlechannel,doodlenotes[measure][15],doodlelevel);
         }
         kill_note(drumchannel,FS1,drumlevel);
      }
   }

   cout << "\nOld volume: " << volume;
   cout << "\nDrum level: " << drumlevel;
   cout << "\nChord level: " << chordlevel;
   cout << "\nFading out chords and powerlead: ";
   cout << "\nFading out regular lead: ";
   volume = 90;
   for (int index=0; index < 90;index++)
   {
      cout << ".";
      if (delay_dead(speed*2)) break;
      change_volume(1,volume--);
   }

   menu();
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
   change_program(1,98,1);
   change_program(chordchannel,54,4);
   change_program(10,120,1);
   change_program(powerleadchannel,90,1);
   change_program(doodlechannel,90,1);
   change_keyboard_input(powerleadchannel,1);
   change_volume(1,90);
   change_volume(powerleadchannel,0);
   doodlenotes[34][0] = G5;
   doodlenotes[34][1] = DS5;
   doodlenotes[34][2] = D5;
   doodlenotes[34][3] = C5;
   int note;
   int measure;
   for (note=4;note<=15;note++)
      doodlenotes[34][note] = doodlenotes[34][note-4];
   for (measure=35;measure<=39;measure++)
      for (note=0;note<16;note++)
         doodlenotes[measure][note] = doodlenotes[34][note];
   doodlenotes[35][0] = GS5;
   doodlenotes[35][4] = GS5;
   doodlenotes[35][8] = F5;
   doodlenotes[35][12] = F5;

   doodlenotes[37][0] = GS5;
   doodlenotes[37][4] = GS5;
   doodlenotes[37][8] = F5;
   doodlenotes[37][9] = D5;
   doodlenotes[37][10] = C5;
   doodlenotes[37][11] = AS4;

   doodlenotes[37][12] = F5;
   doodlenotes[37][13] = D5;
   doodlenotes[37][14] = C5;
   doodlenotes[37][15] = D5;

   doodlenotes[40][0] = F5;
   doodlenotes[40][1] = G5;
   doodlenotes[40][2] = GS5;
   doodlenotes[40][3] = G5;
   doodlenotes[40][4] = F5;
   doodlenotes[40][5] = G5;
   doodlenotes[40][6] = GS5;
   doodlenotes[40][7] = G5;
   doodlenotes[40][8] = F5;
   doodlenotes[40][9] = G5;
   doodlenotes[40][10] = GS5;
   doodlenotes[40][11] = G5;
   doodlenotes[40][12] = F5;
   doodlenotes[40][13] = G5;
   doodlenotes[40][14] = GS5;
   doodlenotes[40][15] = G5;

   doodlenotes[41][12] = GS5;
   doodlenotes[41][13] = G5;
   doodlenotes[41][14] = F5;
   doodlenotes[41][15] = G5;

   for (note=4;note<16;note++)
      doodlenotes[40][note] = doodlenotes[40][note-4];
   for (note=0;note<16;note++)
      doodlenotes[41][note] = doodlenotes[40][note];
   for (measure=42;measure<=47;measure++)
   {
      if ((odd(measure)) && (measure != 47))
      {
         doodlenotes[measure][0] = DS5;
         doodlenotes[measure][4] = DS5;
         doodlenotes[measure][8] = DS5;
         doodlenotes[measure][12] = DS5;
      }
      else
      {
         doodlenotes[measure][0] = D5;
         doodlenotes[measure][4] = D5;
         doodlenotes[measure][8] = D5;
         doodlenotes[measure][12] = D5;
      }
         doodlenotes[measure][1] = AS4;
         doodlenotes[measure][5] = AS4;
         doodlenotes[measure][9] = AS4;
         doodlenotes[measure][13] = AS4;
         doodlenotes[measure][2] = A4;
         doodlenotes[measure][6] = A4;
         doodlenotes[measure][10] = A4;
         doodlenotes[measure][14] = A4;
         doodlenotes[measure][3] = G4;
         doodlenotes[measure][7] = G4;
         doodlenotes[measure][11] = G4;
         doodlenotes[measure][15] = G4;
   }
   doodlenotes[43][8] = C5;
   doodlenotes[43][12] = C5;
   doodlenotes[43][13] = A4;
   doodlenotes[43][14] = G4;
   doodlenotes[43][15] = A4;

   doodlenotes[45][8] = C5;
   doodlenotes[45][12] = C5;
   doodlenotes[45][13] = A4;
   doodlenotes[45][14] = G4;
   doodlenotes[45][15] = A4;

   doodlenotes[48][0] = C5;
   doodlenotes[48][1] = D5;
   doodlenotes[48][2] = DS5;
   doodlenotes[48][3] = D5;
   doodlenotes[48][4] = C5;
   doodlenotes[48][5] = D5;
   doodlenotes[48][6] = DS5;
   doodlenotes[48][7] = D5;
   doodlenotes[48][8] = C5;
   doodlenotes[48][9] = D5;
   doodlenotes[48][10] = DS5;
   doodlenotes[48][11] = D5;
   doodlenotes[48][12] = C5;
   doodlenotes[48][13] = D5;
   doodlenotes[48][14] = DS5;
   doodlenotes[48][15] = D5;

   doodlenotes[49][0] = C5;
   doodlenotes[49][1] = D5;
   doodlenotes[49][2] = DS5;
   doodlenotes[49][3] = D5;
   doodlenotes[49][4] = C5;
   doodlenotes[49][5] = D5;
   doodlenotes[49][6] = DS5;
   doodlenotes[49][7] = D5;
   doodlenotes[49][8] = C5;
   doodlenotes[49][9] = D5;
   doodlenotes[49][10] = DS5;
   doodlenotes[49][11] = D5;
   doodlenotes[49][12] = DS5;
   doodlenotes[49][13] = D5;
   doodlenotes[49][14] = C5;
   doodlenotes[49][15] = D5;

   for (measure=50;measure<100;measure++)
      for (note=0;note<16;note++)
         doodlenotes[measure][note] = doodlenotes[measure-16][note];

   mix_name("Shadow   ");
   change_effects_level(10,0);
   mix_mode();
   menu();
   change_light_level(1,50);
   change_light_level(2,75);
   change_light_level(3,25);
   change_light_level(4,50);

   while (1)
   {
      do_fade_stuff();
      if ((notes[INDEX_SPACE] == 0) && (key_table[INDEX_SPACE]==1))
      {   
         notes[INDEX_SPACE]=1;   
         play_note(10,36,127);
         change_light_level(1,127);
         change_light_level(2,127);
         change_light_level(3,127);
      }
      if ((notes[INDEX_SPACE] == 1) && (key_table[INDEX_SPACE]==0))   
      {   
         kill_note(10,36,127);
         change_light_level(1,50);
         change_light_level(2,75);
         change_light_level(3,25);
         notes[INDEX_SPACE]=0;
      }   

      if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))
      {   
         notes[INDEX_LEFT]=1;   
         play_note(10,D1,127);
      }   
      if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))   
      {   
         kill_note(10,D1,127);
         notes[INDEX_LEFT]=0;   
      }   

      if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))
      {   
         notes[INDEX_DOWN]=1;   
         play_note(10,FS1,127);
      }   
      if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))   
      {   
         kill_note(10,FS1,127);
         notes[INDEX_DOWN]=0;   
      }   

      if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
      {   
         notes[INDEX_UP]=1;   
         play_note(10,CS2,127);
      }   
      if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))   
      {   
         kill_note(10,CS2,127);
         notes[INDEX_UP]=0;   
      }   

      if (key_table[INDEX_ENTER])
      {
         dead_drums(speed);
         wait_for_no(INDEX_ESC);
         all_lights_off(0);
      }
//      do_dead_stuff();
      if (key_table[INDEX_ESC]) break;
   }   
   change_keyboard_input(powerleadchannel,0);
   change_volume(chordchannel,99);
   change_volume(1,99);
   change_volume(10,99);
   all_lights_off(0);
   change_light_level(3,127);
   mix_name("Multi    ");
   mix_mode();
   Exit_MIDI();
   kill_keyboard();   
   clrscr();
   cout << "shadow.cpp terminated";   

}
