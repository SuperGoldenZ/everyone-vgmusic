#include "midi.h"
#include <dos.h>
#include <conio.h>
#include "keyboard.h"

#define drumlevel 127
#define drumchannel 10

#define fxchannel 5
#define fxlevel 127

const int speed = 150;
const int basschannel = 3;
const int basslevel = 127;
const int uhlevel = 25;

int basschannel2 = 4;

int chordchannel = 6;
int chordlevel = 127;

int reversecymbalchannel = 7;
int reversecymballevel = 127;

int notes[127];

int bassnotes[100][8];

void dostuff();

void playchord1()
{
   play_note(chordchannel,E5-12,chordlevel);   
   play_note(chordchannel,C5-12,chordlevel);   
   play_note(chordchannel,A4-12,chordlevel);   
}

void killchord1()
{
   kill_note(chordchannel,E5-12,chordlevel);   
   kill_note(chordchannel,C5-12,chordlevel);   
   kill_note(chordchannel,A4-12,chordlevel);   
}

void playchord2()
{
   play_note(chordchannel,E5-12,chordlevel);   
   play_note(chordchannel,C5-12,chordlevel);   
   play_note(chordchannel,G4-12,chordlevel);   
}

void killchord2()
{
   kill_note(chordchannel,E5-12,chordlevel);   
   kill_note(chordchannel,C5-12,chordlevel);   
   kill_note(chordchannel,G4-12,chordlevel);   
}

void playchord3()
{
   play_note(chordchannel,D5-12,chordlevel);
   play_note(chordchannel,B4-12,chordlevel);   
   play_note(chordchannel,G4-12,chordlevel);   
}

void killchord3()
{
   kill_note(chordchannel,D5-12,chordlevel);   
   kill_note(chordchannel,B4-12,chordlevel);   
   kill_note(chordchannel,G4-12,chordlevel);   
}

void playchord4()
{
   play_note(chordchannel,C5-12,chordlevel);   
   play_note(chordchannel,A4-12,chordlevel);   
   play_note(chordchannel,F4-12,chordlevel);   
}

void killchord4()
{
   kill_note(chordchannel,C5-12,chordlevel);   
   kill_note(chordchannel,A4-12,chordlevel);   
   kill_note(chordchannel,F4-12,chordlevel);   
}


void list_samples()
{
   clrscr();
   cout << "Mortal Kombat Samples";
   cout << "\nF1: Gong ";
   cout << "\nF2: Test your might";
   cout << "\nF3: Electricity";
   cout << "\nF4: MORTAL KOMBAT!";
   cout << "\nF5: Fight!";
   cout << "\nF6: uh";
   cout << "\nF7: Finish Him!";
   cout << "\nF8: Excellent";
   cout << "\nF9: Kano";
   cout << "\nF10: Liu Kang";
   cout << "\nF11: Rayden";
   cout << "\nF12: Johnny Cage";
   cout << "\nQ: Scorpion";
   cout << "\nW: Subzero";
   cout << "\nE: Sonya";
}

int delay1(int speed)
{
   for (int index=0;index<speed;index++)
   {
      delay(1);
      dostuff();
      if (key_table[INDEX_ESC]) return 1;
   }
   return 0;
}

int uhmeasure(int measure)
{
      if ((measure == 14) || (measure == 15) ||
          (measure == 16) || (measure == 18) ||
          (measure == 19) || (measure == 20) ||
          (measure == 21) || (measure == 22) ||
          (measure == 23) || (measure == 24) ||
          (measure == 38) || (measure == 39) ||
          (measure == 40) || (measure == 46) ||
          (measure == 47) || (measure == 48) ||
          (measure == 62) || (measure == 63) ||
          (measure == 64) || (measure == 65) || 
          (measure == 66) || (measure == 67) ||
          (measure == 68) || (measure == 69) ||
          (measure == 70) || (measure == 71) ||
          (measure == 72) || (measure == 90) ||
          (measure == 91) || (measure == 92) ||
          (measure == 93) || (measure == 94) ||
          (measure == 95) || (measure == 96) ||
          (measure == 97))
      return 1;
   return 0;
}

int reversemeasure(int measure)
{
   if ((measure == 9) || (measure == 13) || (measure == 17) ||
       (measure == 21) || (measure == 33) || (measure == 37) ||
       (measure == 41) || (measure == 45) || (measure == 61) ||
       (measure == 65) || (measure == 69) || (measure == 85) ||
       (measure == 89) || (measure == 93) || (measure == 97) ||
       (measure == 102))
          return 1;
   return 0;
}

//samples start on 62
void dostuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      play_note(fxchannel,62,fxlevel);
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      kill_note(fxchannel,62,fxlevel);
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      play_note(fxchannel,63,fxlevel);
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      kill_note(fxchannel,63,fxlevel);
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      play_note(fxchannel,64,fxlevel);
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
      kill_note(fxchannel,64,fxlevel);
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
   {
      notes[INDEX_F4]=1;
      play_note(fxchannel,65,fxlevel);
   }                       

   if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
   {
      kill_note(fxchannel,65,fxlevel);
      notes[INDEX_F4]=0;
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      play_note(fxchannel,66,fxlevel);
   }                       

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      kill_note(fxchannel,66,fxlevel);
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
   {
      notes[INDEX_F6]=1;
      play_note(fxchannel,67,fxlevel);
   }                       

   if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
   {
      kill_note(fxchannel,67,fxlevel);
      notes[INDEX_F6]=0;
   }

   if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
   {
      notes[INDEX_F7]=1;
      play_note(fxchannel,68,fxlevel);
   }                       

   if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
   {
      kill_note(fxchannel,68,fxlevel);
      notes[INDEX_F7]=0;
   }

   if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
   {
      notes[INDEX_F8]=1;
      play_note(fxchannel,69,fxlevel);
   }                       

   if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))
   {
      kill_note(fxchannel,69,fxlevel);
      notes[INDEX_F8]=0;
   }

   if ((notes[INDEX_F9] == 0) && (key_table[INDEX_F9]==1))
   {
      notes[INDEX_F9]=1;
      play_note(fxchannel,70,fxlevel);
   }                       

   if ((notes[INDEX_F9] == 1) && (key_table[INDEX_F9]==0))
   {
      kill_note(fxchannel,70,fxlevel);
      notes[INDEX_F9]=0;
   }

   if ((notes[INDEX_F10] == 0) && (key_table[INDEX_F10]==1))
   {
      notes[INDEX_F10]=1;
      play_note(fxchannel,71,fxlevel);
   }                       

   if ((notes[INDEX_F10] == 1) && (key_table[INDEX_F10]==0))
   {
      kill_note(fxchannel,71,fxlevel);
      notes[INDEX_F10]=0;
   }

   if ((notes[INDEX_F11] == 0) && (key_table[INDEX_F11]==1))
   {
      notes[INDEX_F11]=1;
      play_note(fxchannel,72,fxlevel);
   }                       

   if ((notes[INDEX_F11] == 1) && (key_table[INDEX_F11]==0))
   {
      kill_note(fxchannel,72,fxlevel);
      notes[INDEX_F11]=0;
   }

   if ((notes[INDEX_F12] == 0) && (key_table[INDEX_F12]==1))
   {
      notes[INDEX_F12]=1;
      play_note(fxchannel,73,fxlevel);
   }                       

   if ((notes[INDEX_F12] == 1) && (key_table[INDEX_F12]==0))
   {
      kill_note(fxchannel,73,fxlevel);
      notes[INDEX_F12]=0;
   }

   if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
   {
      notes[INDEX_Q]=1;
      play_note(fxchannel,74,fxlevel);
   }                       

   if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))
   {
      kill_note(fxchannel,74,fxlevel);
      notes[INDEX_Q]=0;
   }

   if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
   {
      notes[INDEX_W]=1;
      play_note(fxchannel,75,fxlevel);
   }                       

   if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))
   {
      kill_note(fxchannel,75,fxlevel);
      notes[INDEX_W]=0;
   }

   if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
   {
      notes[INDEX_E]=1;
      play_note(fxchannel,76,fxlevel);
   }                       

   if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))
   {
      kill_note(fxchannel,76,fxlevel);
      notes[INDEX_E]=0;
   }

}

void bassline(int speed)
{
   int index1;
   int index2;
   play_note(drumchannel,CS2,127);
   while (1 == 1 )
   {
      play_note(basschannel,A1,basslevel);
      cout << "\nMeasure 6:  1 " ;
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);
      kill_note(drumchannel,CS2,127);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      cout << " 2 " ;
      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);

      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);

      cout << " 3 " ;
      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      cout << " 4 ";
      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);

      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);

      play_note(basschannel,A1,basslevel);
      cout << "\nMeasure 7:  1 " ;
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      cout << " 2 " ;
      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);

      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);

      cout << " 3 " ;
      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      cout << " 4 ";
      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);

      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);

      play_note(basschannel,A1,basslevel);
      cout << "\nMeasure 8:  1 " ;
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      cout << " 2 " ;
      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);
                             
      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);

      cout << " 3 " ;
      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      cout << " 4 ";
      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,A1,basslevel);

      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);

      play_note(basschannel,G1,basslevel);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,basslevel);

      break;
   }
}

int drumloop(int speed)
{
   int measure = 13;

   while (1)
   {
      cout << "\nMeasure " << ++measure << ": ";
      if (measure == 82)
         break;
      if (measure == 17)
      {
         cout << " 1 " ;
         play_note(drumchannel,GS1,drumlevel);
         delay(speed);
         delay(speed);
         delay(speed);
         delay(speed);
         kill_note(drumchannel,GS1,drumlevel);
         cout << " 2 " ;
         play_note(drumchannel,GS1,drumlevel);
         delay(speed);
         delay(speed);
         delay(speed);
         delay(speed);
         kill_note(drumchannel,GS1,drumlevel);
         cout << " 3 " ;
         play_note(drumchannel,GS1,drumlevel);
         delay(speed);
         delay(speed);
         delay(speed);
         delay(speed);
         kill_note(drumchannel,GS1,drumlevel);
         cout << " 4 " ;
         play_note(drumchannel,GS1,drumlevel);
         delay(speed);
         delay(speed);
         delay(speed);
         delay(speed);
         kill_note(drumchannel,GS1,drumlevel);
         cout << "\nMeasure: " << ++measure;
      }

      if ((measure == 25) || (measure == 73))
      {
         for (int index=0;index<4;index++)
         {
            play_note(drumchannel,B1-12,drumlevel);
            play_note(drumchannel,C2-12,drumlevel);
            if (delay1(speed*4)) break;
            play_note(drumchannel,B1-12,drumlevel);
            play_note(drumchannel,C2-12,drumlevel);
         }
         cout << "\nMeasure: " << ++measure;
      }

      if ((measure == 34) || (measure == 58))
      {
         playchord1();
         play_note(drumchannel,C2-12,drumlevel);
         play_note(drumchannel,B1-12,drumlevel);
         if ((measure == 14) || (measure == 18) || (measure == 22))
            play_note(drumchannel,CS3-12,drumlevel);
         play_note(drumchannel,FS2-12,drumlevel);
         if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);

         if ((measure == 14) || (measure == 18) || (measure == 22))
            kill_note(drumchannel,CS3-12,drumlevel);

         kill_note(drumchannel,C2-12,drumlevel);
         kill_note(drumchannel,B1-12,drumlevel);

         for (int index=0;index<3;index++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
               kill_note(drumchannel,FS2-12,drumlevel);
         }

         play_note(drumchannel,FS2-12,drumlevel);
         play_note(drumchannel,C2-12,drumlevel);
         play_note(drumchannel,B1-12,drumlevel);
         if (delay1(speed)) break;
         kill_note(drumchannel,FS2-12,drumlevel);
         kill_note(drumchannel,C2-12,drumlevel);
         kill_note(drumchannel,B1-12,drumlevel);

         for ( index=0;index<3;index++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
         }

         play_note(drumchannel,FS2-12,drumlevel);
         play_note(drumchannel,C2-12,drumlevel);
         play_note(drumchannel,B1-12,drumlevel);
         if (delay1(speed)) break;
         kill_note(drumchannel,FS2-12,drumlevel);
         kill_note(drumchannel,C2-12,drumlevel);
         kill_note(drumchannel,B1-12,drumlevel);

         for ( index=0;index<3;index++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
         }

         play_note(drumchannel,FS2-12,drumlevel);
         play_note(drumchannel,C2-12,drumlevel);
         play_note(drumchannel,B1-12,drumlevel);
         if (delay1(speed)) break;
         kill_note(drumchannel,FS2-12,drumlevel);
         kill_note(drumchannel,C2-12,drumlevel);
         kill_note(drumchannel,B1-12,drumlevel);

         for ( index=0;index<3;index++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
         }

         killchord1();
         cout << "\nMeasure: " << ++measure;
      }

      if ((measure == 35) || (measure == 59))
      {
         playchord2();
         for (int index2=0;index2<4;index2++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            play_note(drumchannel,C2-12,drumlevel);
            play_note(drumchannel,B1-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
            kill_note(drumchannel,C2-12,drumlevel);
            kill_note(drumchannel,B1-12,drumlevel);

            for (int index=0;index<3;index++)
            {
               play_note(drumchannel,FS2-12,drumlevel);
               if (delay1(speed)) break;
               kill_note(drumchannel,FS2-12,drumlevel);
            }
         }
         killchord2();
         cout << "\nMeasure: " << ++measure;
      }

      if ((measure == 36) || (measure == 60))
      {
         playchord3();
         for (int index2=0;index2<4;index2++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            play_note(drumchannel,C2-12,drumlevel);
            play_note(drumchannel,B1-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
            kill_note(drumchannel,C2-12,drumlevel);
            kill_note(drumchannel,B1-12,drumlevel);

            for (int index=0;index<3;index++)
            {
               play_note(drumchannel,FS2-12,drumlevel);
               if (delay1(speed)) break;
               kill_note(drumchannel,FS2-12,drumlevel);
            }
         }
         cout << "\nMeasure: " << ++measure;
         killchord3();
      }

      if ((measure == 37) || (measure == 61))
      {
         playchord4();
         for (int index2=0;index2<4;index2++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            play_note(drumchannel,C2-12,drumlevel);
            play_note(drumchannel,B1-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
            kill_note(drumchannel,C2-12,drumlevel);
            kill_note(drumchannel,B1-12,drumlevel);

            for (int index=0;index<3;index++)
            {
               play_note(drumchannel,FS2-12,drumlevel);
               if (delay1(speed)) break;
               kill_note(drumchannel,FS2-12,drumlevel);
            }
         }
         killchord4();
         cout << "\nMeasure: " << ++measure;
      }

      if (measure == 49)
      {
         for (int index=0;index<4;index++)
         {
            play_note(drumchannel,E2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,E2-12,drumlevel);
            play_note(drumchannel,E2-12,drumlevel);
            if (delay1(speed*2)) break;
            kill_note(drumchannel,E2-12,drumlevel);
         }

         for (index=0;index<4;index++)
         {
            play_note(drumchannel,E2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,E2-12,drumlevel);
         }
         cout << "\nMeasure: " << ++measure;
      }

      /*if (measure == 58)
      {
         play_note(drumchannel,FS2-12,drumlevel);
         if (measure == 58)
         play_note(drumchannel,CS3-12,drumlevel);
         if (delay1(speed)) break;
         if (measure == 58)
            kill_note(drumchannel,CS3-12,drumlevel);
         kill_note(drumchannel,FS2-12,drumlevel);
         play_note(drumchannel,FS2-12,drumlevel);
         if (delay1(speed)) break;
         kill_note(drumchannel,FS2-12,drumlevel);
         play_note(drumchannel,AS2-12,drumlevel);
         if (delay1(speed*2)) break;
         kill_note(drumchannel,AS2-12,drumlevel);

         for (int index=0;index<3;index++)
         {
           play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
           kill_note(drumchannel,FS2-12,drumlevel);
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
            play_note(drumchannel,AS2-12,drumlevel);
            if (delay1(speed*2)) break;
            kill_note(drumchannel,AS2-12,drumlevel);
         }
         cout << "\nMeasure: " << ++measure;
      }

      if (measure == 59)
      {
         for (int index=0;index<4;index++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
            play_note(drumchannel,AS2-12,drumlevel);
            if (delay1(speed*2)) break;
            kill_note(drumchannel,AS2-12,drumlevel);
         }
         cout << "\nMeasure: " << ++measure;
      }

      if (measure == 60)
      {
         for (int index=0;index<4;index++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
            play_note(drumchannel,AS2-12,drumlevel);
            if (delay1(speed*2)) break;
            kill_note(drumchannel,AS2-12,drumlevel);
         }
         cout << "\nMeasure: " << ++measure;
      }

      if (measure == 61)
      {
         for (int index=0;index<4;index++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
            play_note(drumchannel,AS2-12,drumlevel);
            if (delay1(speed*2)) break;
            kill_note(drumchannel,AS2-12,drumlevel);
         }
         cout << "\nMeasure: " << ++measure;
      }*/

      if (measure == 82)
      {
         play_note(drumchannel,FS2-12,drumlevel);
         play_note(drumchannel,CS3-12,drumlevel);
         if (delay1(speed)) break;
         kill_note(drumchannel,FS2-12,drumlevel);
         kill_note(drumchannel,CS3-12,drumlevel);

         for (int index=0;index<15;index++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
         }
         cout << "\nMeasure: " << ++measure;
      }

      if (measure == 98) break;
      if (measure == 83)
      {
         for (int index=0;index<16;index++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
         }
         cout << "\nMeasure: " << ++measure;
      }

      if (measure == 84)
      {
         for (int index=0;index<16;index++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
         }
         cout << "\nMeasure: " << ++measure;
      }

      if (measure == 85)
      {
         for (int index=0;index<16;index++)
         {
            play_note(drumchannel,FS2-12,drumlevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,FS2-12,drumlevel);
         }
         cout << "\nMeasure: " << ++measure;
      }

      //One
      cout << " 1 " ;
      if ((measure == 38) || (measure == 58) || (measure == 62) || (measure == 82) || (measure == 86))
         playchord1();
      if ((measure == 39) || (measure == 59) || (measure == 63) || (measure == 83) || (measure == 87))
         playchord2();
      if ((measure == 40) || (measure == 60) || (measure == 64) || (measure == 84) || (measure == 88))
         playchord3();
      if ((measure == 41) || (measure == 61) || (measure == 65) || (measure == 85) || (measure == 89))
         playchord4();

      play_note(drumchannel,FS2-12,drumlevel);
      play_note(drumchannel,C2-12,drumlevel);
      play_note(drumchannel,B1-12,drumlevel);
      play_note(basschannel2,bassnotes[measure][0],127);
      if ((measure == 14) || (measure == 18) || (measure == 22))
         play_note(drumchannel,CS3-12,drumlevel);
      if (delay1(speed)) break;
      if ((measure == 14) || (measure == 18) || (measure == 22))
         kill_note(drumchannel,CS3-12,drumlevel);

      kill_note(drumchannel,FS2-12,drumlevel);
      kill_note(drumchannel,C2-12,drumlevel);
      kill_note(drumchannel,B1-12,drumlevel);
      play_note(drumchannel,FS2-12,drumlevel);

      if (delay1(speed)) break;

      if (uhmeasure(measure))
         play_note(fxchannel,67,fxlevel-uhlevel);

      kill_note(drumchannel,FS2-12,drumlevel);
      play_note(drumchannel,AS2-12,drumlevel);

      if (delay1(speed)) break;
      kill_note(basschannel2,bassnotes[measure][0],127);
      play_note(basschannel2,bassnotes[measure][1],127);
      if (delay1(speed)) break;

      if (uhmeasure(measure))
         kill_note(fxchannel,67,fxlevel);

      kill_note(drumchannel,AS2-12,drumlevel);

      if (uhmeasure(measure))
         play_note(fxchannel,67,fxlevel-uhlevel);

      cout << " 2 " ;
      //Two
      play_note(drumchannel,FS2-12,drumlevel);
      play_note(drumchannel,C2-12,drumlevel);
      play_note(drumchannel,B1-12,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,FS2-12,drumlevel);
      kill_note(drumchannel,C2-12,drumlevel);
      kill_note(drumchannel,B1-12,drumlevel);
      play_note(drumchannel,FS2-12,drumlevel);
      if (delay1(speed)) break;
      kill_note(basschannel2,bassnotes[measure][1],127);
      play_note(basschannel2,bassnotes[measure][2],127);

      kill_note(drumchannel,FS2-12,drumlevel);
      play_note(drumchannel,AS2-12,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,bassnotes[measure][2],127);

      if (uhmeasure(measure))
         kill_note(fxchannel,67,fxlevel);

      if (uhmeasure(measure))
         play_note(fxchannel,67,fxlevel-uhlevel);

      kill_note(drumchannel,AS2-12,drumlevel);

      //Three
      if (reversemeasure(measure)==1)
      {
         play_note(reversecymbalchannel,C3,127);
      }
      cout << " 3 " ;
      play_note(drumchannel,FS2-12,drumlevel);
      play_note(drumchannel,C2-12,drumlevel);
      play_note(drumchannel,B1-12,drumlevel);
      play_note(basschannel2,bassnotes[measure][3],127);
      if (delay1(speed)) break;
      kill_note(basschannel2,bassnotes[measure][3],127);
      play_note(basschannel2,bassnotes[measure][4],127);

      kill_note(drumchannel,FS2-12,drumlevel);
      kill_note(drumchannel,C2-12,drumlevel);
      kill_note(drumchannel,B1-12,drumlevel);
      play_note(drumchannel,FS2-12,drumlevel);

      if (delay1(speed)) break;
      kill_note(basschannel2,bassnotes[measure][4],127);
      play_note(basschannel2,bassnotes[measure][5],127);

      kill_note(drumchannel,FS2-12,drumlevel);
      play_note(drumchannel,AS2-12,drumlevel);

      if (delay1(speed)) break;
      kill_note(basschannel2,bassnotes[measure][5],127);

      if (uhmeasure(measure))
         kill_note(fxchannel,67,fxlevel);

      if (uhmeasure(measure))
         play_note(fxchannel,67,fxlevel-uhlevel);

      if (delay1(speed)) break;
      kill_note(drumchannel,AS2-12,drumlevel);

      cout << " 4 " ;
      //Four
      play_note(drumchannel,FS2-12,drumlevel);
      play_note(drumchannel,C2-12,drumlevel);
      play_note(drumchannel,B1-12,drumlevel);
      play_note(basschannel2,bassnotes[measure][6],127);

      if (delay1(speed)) break;
      kill_note(drumchannel,FS2-12,drumlevel);
      kill_note(drumchannel,C2-12,drumlevel);
      kill_note(drumchannel,B1-12,drumlevel);
      play_note(drumchannel,FS2-12,drumlevel);

      if (delay1(speed)) break;
      kill_note(basschannel2,bassnotes[measure][6],127);
      play_note(basschannel2,bassnotes[measure][7],127);

      if (uhmeasure(measure))
         kill_note(fxchannel,67,fxlevel);

      if (uhmeasure(measure))
         play_note(fxchannel,67,fxlevel-uhlevel);

      kill_note(drumchannel,FS2-12,drumlevel);
      play_note(drumchannel,AS2-12,drumlevel);

      if (delay1(speed)) break;

      if (uhmeasure(measure))
         kill_note(fxchannel,67,fxlevel);

      if (uhmeasure(measure))
         play_note(fxchannel,67,fxlevel-uhlevel);

      if (delay1(speed)) break;

      if (uhmeasure(measure))
         kill_note(fxchannel,67,fxlevel);

      kill_note(drumchannel,AS2-12,drumlevel);
      if ((measure == 38) || (measure == 58) || (measure == 62) || (measure == 82) || (measure == 86))
         killchord1();
      if ((measure == 39) || (measure == 59) || (measure == 63) || (measure == 83) || (measure == 87))
         killchord2();
      if ((measure == 40) || (measure == 60) || (measure == 64) || (measure == 84) || (measure == 88))
         killchord3();
      if ((measure == 41) || (measure == 61) || (measure == 65) || (measure == 85) || (measure == 89))
         killchord4();
      kill_note(basschannel2,bassnotes[measure][7],127);
      if (reversemeasure(measure)==1)
         kill_note(reversecymbalchannel,C3,127);
   }
   wait_for_no(INDEX_ESC);
   clrscr();
   cout << "Mortal Kombat!";
   cout << "\n1: Bass line";
   cout << "\n2: Drum loop";
   cout << "\nESC: Quit";
   return 0;
}

//***
void go(int speed)
{
   clrscr();
   while (1 == 1)
   {
      cout << "LET KOMBAT BEGIN!";
      cout << "\nMeasure 1: ";
      cout << " 1 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 2 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 3 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 4 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 5 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 6 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 7 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 8 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << "\nMeasure 2: ";
      cout << " 1 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 2 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 3 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 4 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << "\nMeasure 3: ";
      cout << " 1 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 2 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 3 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 4 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << "\nMeasure 4: ";
      cout << " 1 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 2 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 3 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 4 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << "\nMeasure 5: ";
      cout << " 1 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 2 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 3 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 4 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      bassline(speed);

      cout << "\nMeasure 9: ";
      cout << " 1 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 2 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 3 ";
      play_note(reversecymbalchannel,C3,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;

      cout << " 4 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(reversecymbalchannel,C3,127);

//      change_volume(1,0);
//      change_volume(16,99);

      cout << "\nMeasure 10: ";
      cout << " 1 ";

      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      cout << " 2 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,G1,127);
      cout << " 3 ";
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      cout << " 4 ";
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,G1,127);

      cout << "\nMeasure 11: ";
      cout << " 1 ";
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      cout << " 2 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,G1,127);
      cout << " 3 ";
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      cout << " 4 ";
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,G1,127);

      cout << "\nMeasure 12: ";
      cout << " 1 ";
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      cout << " 2 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,G1,127);
      cout << " 3 ";
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      if (delay1(speed)) break;

      cout << " 4 ";
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,G1,127);

      cout << "\nMeasure 13: ";
      cout << " 1 ";
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,A1,127);
      if (delay1(speed)) break;
      cout << " 2 ";
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,A1,127);
      play_note(basschannel2,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,G1,127);
      cout << " 3 ";
      play_note(reversecymbalchannel,C3,127);
      play_note(basschannel2,C2,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,C2,127);
      play_note(basschannel2,C2,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,C2,127);
      play_note(basschannel2,C2,127);
      if (delay1(speed)) break;
      kill_note(basschannel2,C2,127);
      if (delay1(speed)) break;
      cout << " 4 ";
      play_note(basschannel2,D2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,D2,127);
      play_note(basschannel2,D2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel2,D2,127);
      kill_note(reversecymbalchannel,C3,127);
      break;
   }

   drumloop(speed);
   wait_for_no(INDEX_ESC);
   clrscr();
   cout << "1: FIGHT!";
   cout << "\nESC: Quit";
}

void main()
{
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        for (int index=0;index<127;index++)
                notes[index] = 0;
      mix_mode();
      change_program(reversecymbalchannel,119,4);
      change_program(1,91,1);
      change_program(basschannel2,46,1);
      change_program(basschannel,46,2);
      change_program(drumchannel,120,1); //old 121 2
      change_program(fxchannel,124,0);
      change_program(chordchannel,56,1);
      change_program(16,127,1);
      change_keyboard_input(16,1);
      change_volume(16,0);

      change_volume(1,85);
      change_volume(basschannel2,85);
      change_volume(basschannel,85);
      change_volume(drumchannel,85);
      change_volume(chordchannel,70);

      mix_name("Kombat   ");
      change_effects_channel(16);
      mix_mode();
      clrscr();
      list_samples();
      cout << "\n1: FIGHT!";
      cout << "\nESC: Quit";

      for (int measure=0;measure<100;measure++)
         for (int note=0;note<8;note++)
            bassnotes[measure][note] = 0;

      bassnotes[14][0] = A1;
      bassnotes[14][1] = A1;
      bassnotes[14][2] = G1;
      bassnotes[14][3] = A1;
      bassnotes[14][4] = A1;
      bassnotes[14][5] = A1;
      bassnotes[14][6] = A1;
      bassnotes[14][7] = G1;

      for (measure=15;measure<=16;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=18;measure<=21;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=22;measure<=24;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=26;measure<=33;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=42;measure<=44;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=42;measure<=44;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=46;measure<=48;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=50;measure<=57;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=66;measure<=68;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=70;measure<=72;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=74;measure<=81;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=90;measure<=92;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=90;measure<=92;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      for (measure=94;measure<=96;measure++)
         for (note=0;note<8;note++)
            bassnotes[measure][note] = bassnotes[14][note];

      bassnotes[17][0] = A1;
      bassnotes[17][1] = A1;
      bassnotes[17][2] = G1;
      bassnotes[17][3] = C2;
      bassnotes[17][4] = C2;
      bassnotes[17][5] = C2;
      bassnotes[17][6] = D2;
      bassnotes[17][7] = D2;

      bassnotes[45][0] = A1;
      bassnotes[45][1] = A1;
      bassnotes[45][2] = G1;
      bassnotes[45][3] = C2;
      bassnotes[45][4] = C2;
      bassnotes[45][5] = C2;
      bassnotes[45][6] = D2;
      bassnotes[45][7] = D2;

      bassnotes[49][0] = A1;
      bassnotes[49][1] = A1;
      bassnotes[49][2] = G1;
      bassnotes[49][3] = C2;
      bassnotes[49][4] = C2;
      bassnotes[49][5] = C2;
      bassnotes[49][6] = D2;
      bassnotes[49][7] = D2;

      bassnotes[93][0] = A1;
      bassnotes[93][1] = A1;
      bassnotes[93][2] = G1;
      bassnotes[93][3] = C2;
      bassnotes[93][4] = C2;
      bassnotes[93][5] = C2;
      bassnotes[93][6] = D2;
      bassnotes[93][7] = D2;

      bassnotes[97][0] = A1;
      bassnotes[97][1] = A1;
      bassnotes[97][2] = G1;
      bassnotes[97][3] = C2;
      bassnotes[97][4] = C2;
      bassnotes[97][5] = C2;
      bassnotes[97][6] = D2;
      bassnotes[97][7] = D2;

      bassnotes[69][0] = A1;
      bassnotes[69][1] = A1;
      bassnotes[69][2] = G1;
      bassnotes[69][3] = C2;
      bassnotes[69][4] = C2;
      bassnotes[69][5] = C2;
      bassnotes[69][6] = D2;
      bassnotes[69][7] = D2;

      bassnotes[21][0] = A1;
      bassnotes[21][1] = A1;
      bassnotes[21][2] = G1;
      bassnotes[21][3] = C2;
      bassnotes[21][4] = C2;
      bassnotes[21][5] = C2;
      bassnotes[21][6] = D2;
      bassnotes[21][7] = D2;

      while (1)
        {
           dostuff();
           if (key_table[INDEX_1]) go(110);
           if (key_table[INDEX_ESC]) break;
           if (key_table[INDEX_SPACE])
              bassline(150);
//         if (key_table[INDEX_1]) bassline(105);
//         if (key_table[INDEX_DOWN]) drumloop(109);
        }

        kill_keyboard();
        change_keyboard_input(16,0);
        change_keyboard_input(1,1);
        change_volume(1,99);
        change_volume(drumchannel,99);
        change_volume(chordchannel,99);
        change_effects_channel(1);
        Exit_MIDI();

    }
