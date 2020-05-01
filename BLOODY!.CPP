#include <dos.h>
#include <conio.h>
#include "keyboard.h"
#include "midi.h"
#include "lights.h"

#define drumlevel 127
#define drumchannel 10

#define guitarchannel 3
#define guitarlevel 127

int speed = 125;

void dostuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
//      playchord1(fxchannel,fxlevel);
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
//      killchord1(fxchannel,fxlevel);
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

void play_rhythm_chord(char highnote)
{
   play_note(guitarchannel,highnote,127);
   play_note(guitarchannel,highnote-12,127);
}

void kill_rhythm_chord(char highnote)
{
   kill_note(guitarchannel,highnote,127);
   kill_note(guitarchannel,highnote-12,127);
}

void play_rhythm_chord1(int measure)
{
   if ((measure == 7) || (measure == 11))
   {
      play_note(guitarchannel,G1,127);
      play_note(guitarchannel,G2,127);
   }
   if ((measure == 8) || (measure == 12))
   {
      play_note(guitarchannel,F1,127);
      play_note(guitarchannel,F2,127);
   }
   if ((measure == 9) || (measure == 13))
   {
      play_note(guitarchannel,DS1,127);
      play_note(guitarchannel,DS2,127);
   }
}

void kill_rhythm_chord1(int measure)
{
   if ((measure == 7) || (measure == 11))
   {
      kill_note(guitarchannel,G1,127);
      kill_note(guitarchannel,G2,127);
   }
   if ((measure == 8) || (measure == 12))
   {
      kill_note(guitarchannel,F1,127);
      kill_note(guitarchannel,F2,127);
   }
   if ((measure == 9) || (measure == 13))
   {
      kill_note(guitarchannel,DS1,127);
      kill_note(guitarchannel,DS2,127);
   }
}

void play_rhythm_chord2(int measure)
{
   if ((measure == 7) || (measure == 11))
   {
      play_note(guitarchannel,G2,127);
      play_note(guitarchannel,G3,127);
   }
   if ((measure == 8) || (measure == 12))
   {
      play_note(guitarchannel,F2,127);
      play_note(guitarchannel,F3,127);
   }
   if ((measure == 9) || (measure == 13))
   {
      play_note(guitarchannel,DS2,127);
      play_note(guitarchannel,DS3,127);
   }
}

void kill_rhythm_chord2(int measure)
{
   if ((measure == 7) || (measure == 11))
   {                           
      kill_note(guitarchannel,G2,127);
      kill_note(guitarchannel,G3,127);
   }
   if ((measure == 8) || (measure == 12))
   {                           
      kill_note(guitarchannel,F2,127);
      kill_note(guitarchannel,F3,127);
   }
   if ((measure == 9) || (measure == 13))
   {                           
      kill_note(guitarchannel,DS2,127);
      kill_note(guitarchannel,DS3,127);
   }
}

int go()
{
   int measure = 3;
   int count = 0;
   clrscr();
   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,D1,127);
      play_note(guitarchannel,G2,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,D1,127);
      kill_note(guitarchannel,G2,127);

      play_note(drumchannel,D1,127);
      play_note(drumchannel,A2,127);
      play_note(guitarchannel,G2,127);
      play_note(guitarchannel,G1,127);
      if (delay1(speed)) return 0;
      kill_note(guitarchannel,G2,127);
      kill_note(guitarchannel,G1,127);
      kill_note(drumchannel,D1,127);
      kill_note(drumchannel,A2,127);

      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,D1,127);
      play_note(drumchannel,CS2,127);
      play_note(guitarchannel,G2,127);
      play_note(guitarchannel,G1,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,D1,127);
      kill_note(drumchannel,CS2,127);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;

      play_note(drumchannel,FS1,127);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_note(drumchannel,FS1,127);

      play_note(drumchannel,FS1,127);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_note(drumchannel,FS1,127);

      play_note(drumchannel,FS1,127);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_note(drumchannel,FS1,127);

      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,FS1,127);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      play_note(drumchannel,C2,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,C2,127);
      play_note(drumchannel,C2,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,FS1,127);
      kill_note(drumchannel,C2,127);

      play_note(drumchannel,FS1,127);
      play_note(drumchannel,B1,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,B1,127);
      play_note(drumchannel,B1,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,B1,127);
      play_note(drumchannel,A1,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,A1,127);
      play_note(drumchannel,A1,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,A1,127);
      kill_note(drumchannel,FS1,127);

      play_note(drumchannel,G1,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,G1,127);
      play_note(drumchannel,G1,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,G1,127);
      play_note(drumchannel,G1,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,G1,127);
      play_note(drumchannel,G1,127);
      play_note(drumchannel,C2,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,G1,127);
      kill_note(drumchannel,C2,127);

      play_note(drumchannel,C2,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,C2,127);
      play_note(drumchannel,B1,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,B1,127);
      play_note(drumchannel,A1,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,A1,127);
      play_note(drumchannel,F1,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,F1,127);
      kill_note(guitarchannel,G2,127);
      kill_note(guitarchannel,G1,127);
      break;
   }


   //Main groove
   while (1)
   {
      cout << "\nBegining of main groove drum loop for loop";
      for (int index=0;index<3;index++)
      {
      cout << "\nMeasure: " << ++measure;
      if (measure == 7) play_note(drumchannel,CS2,127);
      play_note(drumchannel,C1,127);
      play_rhythm_chord1(measure);
      if (delay1(speed)) return 0;
      kill_rhythm_chord1(measure);
      play_rhythm_chord1(measure);
      if (delay1(speed)) return 0;
      kill_rhythm_chord1(measure);
      play_rhythm_chord1(measure);
      if (delay1(speed)) return 0;
      kill_rhythm_chord1(measure);
      play_rhythm_chord1(measure);
      if (delay1(speed)) return 0;
      kill_rhythm_chord1(measure);
      play_rhythm_chord1(measure);
      if (measure == 7) kill_note(drumchannel,CS2,127);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      if (delay1(speed)) return 0;
      kill_rhythm_chord1(measure);
      play_rhythm_chord1(measure);
      if (delay1(speed)) return 0;
      kill_rhythm_chord1(measure);
      play_rhythm_chord1(measure);
      if (delay1(speed)) return 0;
      kill_rhythm_chord1(measure);
      play_rhythm_chord1(measure);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,D1,127);
      kill_rhythm_chord1(measure);

      play_rhythm_chord1(measure);
      play_note(drumchannel,C1,127);
      if (delay1(speed)) return 0;
      kill_rhythm_chord1(measure);
      play_rhythm_chord2(measure);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_rhythm_chord2(measure);
      play_rhythm_chord1(measure);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,C1,127);
      kill_rhythm_chord1(measure);

      play_rhythm_chord2(measure);
      play_note(drumchannel,D1,127);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_rhythm_chord2(measure);
      play_rhythm_chord1(measure);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_note(drumchannel,D1,127);
      kill_rhythm_chord1(measure);
      }

      //***
      cout << "\nMeasure: " << ++measure;
      if (measure == 10)
      {
      play_note(drumchannel,C1,127);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      play_rhythm_chord(DS3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS3);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(AS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(AS2);
      play_rhythm_chord(D3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(D3);
      play_rhythm_chord(G3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G3);
      kill_note(drumchannel,D1,127);

      play_note(drumchannel,C1,127);
      play_rhythm_chord(A2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(A2);
      play_rhythm_chord(C3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(C3);
      play_rhythm_chord(F3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F3);
      play_rhythm_chord(C3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(C3);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(AS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(AS2);
      play_rhythm_chord(DS3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS3);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      kill_note(drumchannel,D1,127);
      }

      if (measure == 14)
      {
      play_note(drumchannel,C1,127);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      play_rhythm_chord(DS3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS3);
      play_rhythm_chord(AS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(AS2);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      kill_note(drumchannel,D1,127);

      play_note(drumchannel,C1,127);
      play_rhythm_chord(G3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G3);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(F3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F3);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      play_rhythm_chord(DS3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS3);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      play_rhythm_chord(D3);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(D3);
      play_rhythm_chord(D2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(D2);
      kill_note(drumchannel,D1,127);

      //neer neer neer part
      for (int index=0;index<4;index++)
      {
      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,C1,127);
      play_rhythm_chord(G2);
      play_note(drumchannel,F2,127);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,F2,127);
      play_note(drumchannel,F2,127);
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      kill_note(drumchannel,C1,127);
      kill_note(drumchannel,F2,127);

      play_note(drumchannel,F2,127);
      play_note(drumchannel,D1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_note(drumchannel,A2,127);
      play_rhythm_chord(G3);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,A2,127);
      kill_note(drumchannel,F2,127);
      play_note(drumchannel,F2,127);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G3);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      kill_note(drumchannel,D1,127);
      kill_note(drumchannel,F2,127);

      play_note(drumchannel,F2,127);
      play_note(drumchannel,C1,127);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      kill_note(drumchannel,F2,127);
      play_note(drumchannel,F2,127);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      kill_note(drumchannel,C1,127);
      kill_note(drumchannel,F2,127);

      play_note(drumchannel,F2,127);
      play_note(drumchannel,D1,127);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      play_note(drumchannel,CS2,127);
      play_rhythm_chord(F3);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,CS2,127);
      kill_note(drumchannel,F2,127);
      play_note(drumchannel,F2,127);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F3);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      kill_note(drumchannel,D1,127);
      kill_note(drumchannel,F2,127);

      play_note(drumchannel,F2,127);
      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,C1,127);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      kill_note(drumchannel,F2,127);
      play_note(drumchannel,F2,127);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      kill_note(drumchannel,C1,127);
      kill_note(drumchannel,F2,127);

      play_note(drumchannel,F2,127);
      play_note(drumchannel,D1,127);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      play_rhythm_chord(DS3);
      play_note(drumchannel,A2,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,F2,127);
      kill_note(drumchannel,A2,127);
      play_note(drumchannel,F2,127);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS3);
      play_rhythm_chord(DS2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(DS2);
      kill_note(drumchannel,D1,127);
      kill_note(drumchannel,F2,127);

      play_note(drumchannel,F2,127);
      play_note(drumchannel,C1,127);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      play_rhythm_chord(F3);
      play_note(drumchannel,CS2,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,CS2,127);
      kill_note(drumchannel,F2,127);
      play_note(drumchannel,F2,127);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F3);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      kill_note(drumchannel,C1,127);
      kill_note(drumchannel,F2,127);

      play_note(drumchannel,F2,127);
      play_note(drumchannel,D1,127);
      play_note(drumchannel,A2,127);
      play_rhythm_chord(F3);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,A2,127);
      kill_rhythm_chord(F3);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      kill_note(drumchannel,F2,127);
      play_note(drumchannel,F2,127);
      play_rhythm_chord(F3);
      play_note(drumchannel,CS2,127);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,CS2,127);
      kill_rhythm_chord(F3);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      kill_note(drumchannel,D1,127);
      kill_note(drumchannel,F2,127);
      } //end for loop

      cout << "\nMeasure: " << ++measure << " (after for loop)";
      play_note(drumchannel,C1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      kill_note(drumchannel,D1,127);

      play_note(drumchannel,C1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      kill_note(drumchannel,D1,127);

      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,C1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      kill_note(drumchannel,D1,127);

      play_note(drumchannel,C1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(F2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(F2);
      kill_note(drumchannel,D1,127);

      //piano part
      cout << "\nPiano comes in here!";
      change_volume(guitarchannel,60);
      for (index=0;index<8;index++)
      {
      cout << "\nMeasure: " << ++measure;
      if (measure == 7) play_note(drumchannel,CS2,127);
      play_note(drumchannel,C1,127);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (measure == 7) kill_note(drumchannel,CS2,127);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,D1,127);
      kill_rhythm_chord(G2);

      play_rhythm_chord(G2);
      play_note(drumchannel,C1,127);
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G2);
      play_rhythm_chord(G3);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G3);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      kill_note(drumchannel,C1,127);
      kill_rhythm_chord(G2);

      play_rhythm_chord(G3);
      play_note(drumchannel,D1,127);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_rhythm_chord(G3);
      play_rhythm_chord(G2);
      if (delay1(speed)) return 0;
      if (delay1(speed)) return 0;
      kill_note(drumchannel,D1,127);
      kill_rhythm_chord(G2);
      }
      measure=6;
      count++;
      if (count == 2)
         return 1;
      }
      change_volume(guitarchannel,80);
   }

   return 1;
}

void showinfo()
{
   clrscr();
   cout << "Bloody F'N Tears";
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
        change_program(drumchannel,120,0);
        change_program(guitarchannel,37,2);
        change_program(1,0,2);
        change_volume(guitarchannel,80);
        change_effects_level(drumchannel,0);
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
        all_lights_off(0);
        change_light_level(3,127);

        kill_keyboard();
        Exit_MIDI();
    }
