#include <dos.h>
#include <conio.h>
#include "keyboard.h"
#include "midi.h"
#include "lights.h"

#define drumlevel1 127
#define drumchannel1 10

#define drumchannel 10
#define drumlevel2 127
#define drumchannel2 11

#define synthdrumchannel 12
#define synthdrumlevel 127

#define basschannel 2
#define basslevel 127

#define lead2channel 3
#define lead2level 100

#define chordchannel 4
#define chordlevel 80

#define stringchannel 5
#define stringlevel 80

#define guitarchannel 6
#define guitarlevel 75

int bassnotes[100][8];

int speed = 100;  //old 110

void dostuff()
{
   //C2 C2  C2 D2 D#2
   //C2 F2 G2

   //F3


   if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
   {
      notes[INDEX_Q]=1;
      play_note(chordchannel,C4,chordlevel);
      play_note(chordchannel,F4,chordlevel);
   }

   if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))
   {
      kill_note(chordchannel,C4,chordlevel);
      kill_note(chordchannel,F4,chordlevel);
      notes[INDEX_Q]=0;
   }

   if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
   {
      notes[INDEX_W]=1;
      play_note(chordchannel,AS4,chordlevel);
      play_note(chordchannel,DS4,chordlevel);
   }

   if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))
   {
      kill_note(chordchannel,AS4,chordlevel);
      kill_note(chordchannel,DS4,chordlevel);
      notes[INDEX_W]=0;
   }


   if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
   {
      notes[INDEX_E]=1;
      play_note(chordchannel,DS4,chordlevel);
      play_note(chordchannel,GS4,chordlevel);
   }

   if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))
   {
      kill_note(chordchannel,DS4,chordlevel);
      kill_note(chordchannel,GS4,chordlevel);
      notes[INDEX_E]=0;
   }

   if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
   {
      all_lights_off(0);
      notes[INDEX_R]=1;
      play_note(chordchannel,G4,chordlevel);
      play_note(chordchannel,C5,chordlevel);
      change_light_level(1,50);
   }

   if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))
   {
      kill_note(chordchannel,G4,chordlevel);
      kill_note(chordchannel,C5,chordlevel);
      notes[INDEX_R]=0;
   }

   if ((notes[INDEX_T] == 0) && (key_table[INDEX_T]==1))
   {
      change_light_level(1,127);
      change_light_level(2,75);
      notes[INDEX_T]=1;
      play_note(chordchannel,A4,chordlevel);
      play_note(chordchannel,D5,chordlevel);
   }

   if ((notes[INDEX_T] == 1) && (key_table[INDEX_T]==0))
   {
      kill_note(chordchannel,A4,chordlevel);
      kill_note(chordchannel,D5,chordlevel);
      notes[INDEX_T]=0;
      change_light_level(1,50);
      change_light_level(2,75);
      change_light_level(3,25);
      change_light_level(4,50);
   }

   if ((notes[INDEX_A] == 0) && (key_table[INDEX_A]==1))
   {
      notes[INDEX_A]=1;
      play_note(chordchannel,G3,chordlevel);
      play_note(chordchannel,C4,chordlevel);
   }

   if ((notes[INDEX_A] == 1) && (key_table[INDEX_A]==0))
   {
      kill_note(chordchannel,G3,chordlevel);
      kill_note(chordchannel,C4,chordlevel);
      notes[INDEX_A]=0;
   }

   if ((notes[INDEX_S] == 0) && (key_table[INDEX_S]==1))
   {
      notes[INDEX_S]=1;
      play_note(chordchannel,C4,chordlevel);
      play_note(chordchannel,C3,chordlevel);
   }

   if ((notes[INDEX_S] == 1) && (key_table[INDEX_S]==0))
   {
      kill_note(chordchannel,C4,chordlevel);
      kill_note(chordchannel,C3,chordlevel);
      notes[INDEX_S]=0;
   }

   if ((notes[INDEX_D] == 0) && (key_table[INDEX_D]==1))
   {
      notes[INDEX_D]=1;
      play_note(chordchannel,F3,chordlevel);
      play_note(chordchannel,A3,chordlevel);
   }

   if ((notes[INDEX_D] == 1) && (key_table[INDEX_D]==0))
   {
      kill_note(chordchannel,F3,chordlevel);
      kill_note(chordchannel,A3,chordlevel);
      notes[INDEX_D]=0;
   }


   if ((notes[INDEX_F] == 0) && (key_table[INDEX_F]==1))
   {
      notes[INDEX_F]=1;
      play_note(chordchannel,DS4,chordlevel);
      play_note(chordchannel,G4,chordlevel);
   }

   if ((notes[INDEX_F] == 1) && (key_table[INDEX_F]==0))
   {
      kill_note(chordchannel,DS4,chordlevel);
      kill_note(chordchannel,G4,chordlevel);
      notes[INDEX_F]=0;
   }

   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      play_note(lead2channel,C3,lead2level);
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      kill_note(lead2channel,C3,lead2level);
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      play_note(lead2channel,D2,lead2level);
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      kill_note(lead2channel,D2,lead2level);
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      play_note(lead2channel,DS2,lead2level);
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
      kill_note(lead2channel,DS2,lead2level);
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
   {
      notes[INDEX_F4]=1;
      play_note(lead2channel,F2,lead2level);
   }

   if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
   {
      kill_note(lead2channel,F2,lead2level);
      notes[INDEX_F4]=0;
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      play_note(lead2channel,G2,lead2level);
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      kill_note(lead2channel,G2,lead2level);
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
   {
      notes[INDEX_F6]=1;
      play_note(lead2channel,G3,lead2level);
   }

   if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
   {
      kill_note(lead2channel,G3,lead2level);
      notes[INDEX_F6]=0;
   }


   if ((notes[INDEX_U] == 0) && (key_table[INDEX_U]==1))
   {
      notes[INDEX_U]=1;
      play_note(stringchannel,GS2,stringlevel);
      play_note(stringchannel,F2,stringlevel);
   }

   if ((notes[INDEX_U] == 1) && (key_table[INDEX_U]==0))
   {
      kill_note(stringchannel,GS2,stringlevel);
      kill_note(stringchannel,F2,stringlevel);
      notes[INDEX_U]=0;
   }

   if ((notes[INDEX_I] == 0) && (key_table[INDEX_I]==1))
   {
      notes[INDEX_I]=1;
      play_note(stringchannel,GS2,stringlevel);
      play_note(stringchannel,C3,stringlevel);
   }

   if ((notes[INDEX_I] == 1) && (key_table[INDEX_I]==0))
   {
      kill_note(stringchannel,GS2,stringlevel);
      kill_note(stringchannel,C3,stringlevel);
      notes[INDEX_I]=0;
   }

   if ((notes[INDEX_91] == 0) && (key_table[INDEX_91]==1))
   {
      notes[INDEX_91]=1;
      play_note(stringchannel,DS3,stringlevel);
      play_note(stringchannel,C3,stringlevel);
   }

   if ((notes[INDEX_91] == 1) && (key_table[INDEX_91]==0))
   {
      kill_note(stringchannel,DS3,stringlevel);
      kill_note(stringchannel,C3,stringlevel);
      notes[INDEX_91]=0;
   }

   if ((notes[INDEX_P] == 0) && (key_table[INDEX_P]==1))
   {
      notes[INDEX_P]=1;
      play_note(stringchannel,C3,stringlevel); //b old ds3
      play_note(stringchannel,F3,stringlevel);
   }

   if ((notes[INDEX_P] == 1) && (key_table[INDEX_P]==0))
   {
      kill_note(stringchannel,C3,stringlevel); //b ds3
      kill_note(stringchannel,F3,stringlevel);
      notes[INDEX_P]=0;
   }

   if ((notes[INDEX_11] == 0) && (key_table[INDEX_11]==1))
   {
      notes[INDEX_11]=1;
      play_note(guitarchannel,AS2,guitarlevel);
      play_note(guitarchannel,G2,guitarlevel);
   }

   if ((notes[INDEX_11] == 1) && (key_table[INDEX_11]==0))
   {
      kill_note(guitarchannel,AS2,guitarlevel);
      kill_note(guitarchannel,G2,guitarlevel);
      notes[INDEX_11]=0;
   }

   if ((notes[INDEX_21] == 0) && (key_table[INDEX_21]==1))
   {
      notes[INDEX_21]=1;
      play_note(guitarchannel,F2,guitarlevel);
      play_note(guitarchannel,A2,guitarlevel);
   }

   if ((notes[INDEX_21] == 1) && (key_table[INDEX_21]==0))
   {
      kill_note(guitarchannel,F2,guitarlevel);
      kill_note(guitarchannel,A2,guitarlevel);
      notes[INDEX_21]=0;
   }              

   if ((notes[INDEX_31] == 0) && (key_table[INDEX_31]==1))
   {
      notes[INDEX_31]=1;
      play_note(guitarchannel,DS2,guitarlevel);
      play_note(guitarchannel,G2,guitarlevel);
   }

   if ((notes[INDEX_31] == 1) && (key_table[INDEX_31]==0))
   {
      kill_note(guitarchannel,DS2,guitarlevel);
      kill_note(guitarchannel,G2,guitarlevel);
      notes[INDEX_31]=0;
   }              

   if ((notes[INDEX_41] == 0) && (key_table[INDEX_41]==1))
   {
      notes[INDEX_41]=1;
      play_note(guitarchannel,AS2,guitarlevel);
      play_note(guitarchannel,D3,guitarlevel);
   }

   if ((notes[INDEX_41] == 1) && (key_table[INDEX_41]==0))
   {
      kill_note(guitarchannel,AS2,guitarlevel);
      kill_note(guitarchannel,D3,guitarlevel);
      notes[INDEX_41]=0;
   }              

   if ((notes[INDEX_51] == 0) && (key_table[INDEX_51]==1))
   {
      notes[INDEX_51]=1;
      play_note(guitarchannel,A2,guitarlevel);
      play_note(guitarchannel,C3,guitarlevel);
   }

   if ((notes[INDEX_51] == 1) && (key_table[INDEX_51]==0))
   {
      kill_note(guitarchannel,A2,guitarlevel);
      kill_note(guitarchannel,C3,guitarlevel);
      notes[INDEX_51]=0;
   }              

   if ((notes[INDEX_61] == 0) && (key_table[INDEX_61]==1))
   {
      notes[INDEX_61]=1;
      play_note(guitarchannel,AS2,guitarlevel);
      play_note(guitarchannel,G2,guitarlevel);
   }

   if ((notes[INDEX_61] == 1) && (key_table[INDEX_61]==0))
   {
      kill_note(guitarchannel,AS2,guitarlevel);
      kill_note(guitarchannel,G2,guitarlevel);
      notes[INDEX_61]=0;
   }              

   if ((notes[INDEX_71] == 0) && (key_table[INDEX_71]==1))
   {
      notes[INDEX_71]=1;
      play_note(guitarchannel,C3,guitarlevel);
      play_note(guitarchannel,DS3,guitarlevel);
   }

   if ((notes[INDEX_71] == 1) && (key_table[INDEX_71]==0))
   {
      kill_note(guitarchannel,C3,guitarlevel);
      kill_note(guitarchannel,DS3,guitarlevel);
      notes[INDEX_71]=0;         
   }              

   if ((notes[INDEX_81] == 0) && (key_table[INDEX_81]==1))
   {
      notes[INDEX_81]=1;
      play_note(guitarchannel,F3,guitarlevel);
      play_note(guitarchannel,D3,guitarlevel);
   }

   if ((notes[INDEX_81] == 1) && (key_table[INDEX_81]==0))
   {
      kill_note(guitarchannel,F3,guitarlevel);
      kill_note(guitarchannel,D3,guitarlevel);
      notes[INDEX_81]=0;
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

int level1()
{
   clrscr();
   cout << "\nGo!" << endl;
   cout << "Q W Q E Q W Q E R T R T  ((slide))" << endl;
   cout << "A S D F (skip) (F6) D F (toms)" << endl;
   cout << "  |" << endl;
   cout << "  ---> F1 F1 F1 F2 F3 F1 F4 F5" << endl;

   int measure = 0;
   play_note(drumchannel1,FS1,127);
   delay1(speed);
   delay1(speed);
   delay1(speed);
   delay1(speed);
   kill_note(drumchannel1,FS1,127);
   change_light_level(2,75);
   play_note(drumchannel1,FS1,127);
   delay1(speed);
   delay1(speed);
   delay1(speed);
   delay1(speed);
   kill_note(drumchannel1,FS1,127);
   change_light_level(1,50);
   play_note(drumchannel1,FS1,127);
   delay1(speed);
   delay1(speed);
   delay1(speed);
   delay1(speed);
   kill_note(drumchannel1,FS1,127);
   change_light_level(4,50);
   play_note(drumchannel1,FS1,127);
   delay1(speed);
   delay1(speed);
   delay1(speed);
   delay1(speed);
   kill_note(drumchannel1,FS1,127);
   change_light_level(3,25);

   //First slide
   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel1,FS1,127);
      play_note(basschannel,F2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,F2,127);
      play_note(basschannel,DS2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,DS2,127);
      play_note(basschannel,C2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,C2,127);
      kill_note(drumchannel1,FS1,127);

      play_note(drumchannel1,FS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,GS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,GS1,127);
      play_note(basschannel,G1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,GS1,127);
      kill_note(drumchannel1,FS1,127);

      play_note(drumchannel1,FS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,GS1,127);
      play_note(basschannel,G1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,F1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,F1,127);
      play_note(basschannel,DS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,DS1,127);
      play_note(basschannel,F1,127);
      kill_note(drumchannel1,FS1,127);

      play_note(drumchannel1,FS1,127);
      play_note(drumchannel1,D1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,F1,127);
      play_note(basschannel,C1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,D1,127);
      play_note(drumchannel1,D1,127);
      kill_note(basschannel,C1,127);
      play_note(basschannel,DS1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      kill_note(basschannel,DS1,127);
      play_note(basschannel,E1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,D1,127);
      kill_note(basschannel,E1,127);
      kill_note(drumchannel1,FS1,127);
      break;
   }

   for (int blah=0;blah<2;blah++)
   {
   //Main groove
   measure = 1;
   while (1)
   {
      //First measure after slide
      cout << "\nMeasure: " << ++measure;
      if (measure == 2) play_note(drumchannel1,CS2,127);
      play_note(drumchannel2,C1,127);
      play_note(drumchannel2,DS2,127);
      play_note(basschannel,C2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,C2,127);
      kill_note(drumchannel2,DS2,127);
      if (measure == 2) kill_note(drumchannel1,CS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,F1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);

      play_note(drumchannel1,D1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,F1,127);
      play_note(basschannel,F1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,F1,127);
      play_note(basschannel,GS1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,GS1,127);
      play_note(basschannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(drumchannel1,D1,127);
      kill_note(basschannel,AS1,127);
      play_note(basschannel,C2,127);

      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,C2,127);
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,DS2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);

      play_note(drumchannel1,D1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,DS2,127);
      play_note(basschannel,DS2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(basschannel,DS2,127);
      play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,DS2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,D1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(basschannel,DS2,127);

      //Second measure after slide
      cout << "\nMeasure: " << ++measure;
      play_note(basschannel,C2,127);
      play_note(drumchannel2,C1,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,C2,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,F1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);

      play_note(drumchannel1,D1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,F1,127);
      play_note(basschannel,GS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,GS1,127);
      play_note(basschannel,AS1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,C2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);

      play_note(drumchannel2,DS2,127);
      kill_note(drumchannel1,D1,127);
      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,DS2,127);

      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(basschannel,DS2,127);
      play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      play_note(drumchannel2,C1,127);
      kill_note(basschannel,D2,127);
      play_note(basschannel,DS2,127);

      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(basschannel,DS2,127);
      play_note(basschannel,D2,127);

      play_note(drumchannel1,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(drumchannel1,D1,127);
      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      kill_note(basschannel,AS1,127);
      if (measure == 9)
         break;
   }

   //measures 10-13
   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel1,D1,127);
      play_note(basschannel,C2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel1,D1,127);
      play_note(drumchannel1,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);

      play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,C1,127);
      play_note(drumchannel1,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel,D2,127);
      kill_note(drumchannel1,C1,127);
      play_note(drumchannel1,D1,127);
      play_note(basschannel,DS2,127);
      if (delay1(speed)) break;

      if (delay1(speed)) break;
      kill_note(basschannel,DS2,127);
      kill_note(drumchannel1,D1,127);
      play_note(drumchannel1,C1,127);
      play_note(basschannel,C2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,G2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,C1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,G2,127);

      play_note(basschannel,AS2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,AS2,127);
      play_note(basschannel,B2,127);
      if (delay1(speed)) break;
      play_note(drumchannel1,C1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,B2,127);
      play_note(basschannel,C3,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,C1,127);
      kill_note(basschannel,C3,127);

      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel1,D1,127);
      play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel1,D1,127);
      play_note(drumchannel1,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel,D2,127);

      play_note(basschannel,DS2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,C1,127);
      play_note(drumchannel1,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel,DS2,127);
      kill_note(drumchannel1,C1,127);
      play_note(drumchannel1,D1,127);
      play_note(basschannel,F2,127);
      if (delay1(speed)) break;

      if (delay1(speed)) break;
      kill_note(drumchannel1,D1,127);
      play_note(drumchannel1,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel1,C1,127);
      if (measure == 11) kill_note(basschannel,F2,127);
      if (measure == 11) play_note(basschannel,DS2,127);
      if (delay1(speed)) break;
      if (measure == 11) kill_note(basschannel,DS2,127);
      if (measure == 13) kill_note(basschannel,F2,127);

      if (measure == 11) play_note(basschannel,F2,127);
      if (measure == 13) play_note(basschannel,AS2,127);
      play_note(drumchannel1,B2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,B2,127);
      play_note(drumchannel1,A2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,A2,127);
      play_note(drumchannel1,G2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,G2,127);
      play_note(drumchannel1,F2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,F2,127);
      if (measure == 11) kill_note(basschannel,F2,127);
      if (measure == 13) kill_note(basschannel,AS2,127);
      if (measure == 13)
         break;
   }

   //measure 14
   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel1,C1,127);
      play_note(basschannel,F2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,F2,127);
      play_note(basschannel,DS2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,DS2,127);
      play_note(basschannel,C2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,C2,127);
      kill_note(drumchannel1,C1,127);

      play_note(drumchannel1,C1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,GS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,GS1,127);
      play_note(basschannel,G1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,GS1,127);
      kill_note(drumchannel1,C1,127);

      play_note(drumchannel1,C1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,GS1,127);
      play_note(basschannel,G1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,F1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,F1,127);
      play_note(basschannel,DS1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,DS1,127);
      play_note(basschannel,F1,127);
      kill_note(drumchannel1,C1,127);

      play_note(drumchannel1,C1,127);
      play_note(drumchannel1,D1,127);
      if (delay1(speed)) break;
      kill_note(basschannel,F1,127);
      play_note(basschannel,C1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,D1,127);
      play_note(drumchannel1,D1,127);
      kill_note(basschannel,C1,127);
      play_note(basschannel,DS1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,D1,127);
      play_note(drumchannel1,D1,127);
      kill_note(basschannel,DS1,127);
      play_note(basschannel,E1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,D1,127);
      kill_note(basschannel,E1,127);
      kill_note(drumchannel1,C1,127);
      break;
   }

   //15-on?
   while (1)
   {
      if ((measure != 18) && (measure != 19))
      {
      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel2,C1,127);
      play_note(drumchannel2,DS2,127);
      if (measure == 15) play_note(basschannel,C2,127);
      if (measure == 17) {play_note(basschannel,F2,127);cout << "\n17 play bass note!!!";}
      if (measure == 21) play_note(basschannel,F2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      if (measure == 15) kill_note(basschannel,C2,127);

      play_note(drumchannel2,DS2,127);
      play_note(drumchannel1,D1,127);
      if (measure == 15) play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      if (measure == 15) kill_note(basschannel,D2,127);
      if (measure == 15) play_note(basschannel,DS2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      if (measure == 15) kill_note(basschannel,DS2,127);
      if (measure == 17) kill_note(basschannel,F2,127);
      kill_note(drumchannel1,D1,127);
      if (measure == 21) kill_note(basschannel,F2,127);

      if (measure == 17) play_note(basschannel,AS1,127);
      if (measure == 15) play_note(basschannel,C2,127);
      if (measure == 21) play_note(basschannel,AS1,127);
      play_note(drumchannel2,DS2,127);
      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      if (measure == 15) kill_note(basschannel,C2,127);
      if (measure == 15) play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      if (measure == 15) kill_note(basschannel,D2,127);
      if (measure == 15) play_note(basschannel,DS2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      if (measure == 15) kill_note(basschannel,DS2,127);

      play_note(drumchannel2,DS2,127);
      play_note(drumchannel1,D1,127);
      if (measure == 15) play_note(basschannel,G1,127);
      if (delay1(speed)) break;
      if (measure == 15) kill_note(basschannel,G1,127);
      if (measure == 15) play_note(basschannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      if (measure == 15) kill_note(basschannel,AS1,127);
      if (measure == 15) play_note(basschannel,B1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel1,D1,127);
      kill_note(drumchannel2,DS2,127);
      if (measure == 15) kill_note(basschannel,B1,127);
      if (measure == 17) kill_note(basschannel,AS1,127);
      if (measure == 21) kill_note(basschannel,AS1,127);

      play_note(drumchannel2,DS2,127);
      if (measure == 16) play_note(basschannel,C2,127);
      cout << "\nMeasure: " << ++measure;
      if (measure == 18) {play_note(basschannel,DS2,127);cout << "\nMEASURE 18 PLAY BASS";}
      if (measure == 22) play_note(basschannel,DS2,127);
      play_note(drumchannel2,C1,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      if (measure == 16) kill_note(basschannel,C2,127);
      if (measure == 16) play_note(basschannel,C2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (measure == 16) kill_note(basschannel,C2,127);
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      if (measure == 22) kill_note(basschannel,DS2,127);

      play_note(drumchannel2,DS2,127);
      play_note(drumchannel1,D1,127);
      if (measure == 22) play_note(basschannel,DS2,127);
      if (measure == 16) play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      if (measure == 22) kill_note(basschannel,DS2,127);
      if (measure == 22) play_note(basschannel,F2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      if (measure == 22) kill_note(basschannel,F2,127);
      if (measure == 22) play_note(basschannel,DS2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      if (measure == 16) kill_note(basschannel,D2,127);
      if (measure == 18) kill_note(basschannel,DS2,127);
      if (measure == 22) kill_note(basschannel,DS2,127);

      if (measure == 18) play_note(basschannel,G1,127);
      if (measure == 16) play_note(basschannel,DS2,127);
      if (measure == 22) play_note(basschannel,G2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(drumchannel1,D1,127);
      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      if (measure == 16) kill_note(basschannel,DS2,127);
      if (measure == 16) play_note(basschannel,F2,127);
      kill_note(drumchannel2,C1,127);
      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (measure == 18) kill_note(basschannel,G1,127);
      if (measure == 22) kill_note(basschannel,G2,127);

      if (measure == 22) play_note(basschannel,F2,127);
      play_note(drumchannel1,D1,127);
      if (measure == 18) play_note(basschannel,F1,127);
      if (delay1(speed)) break;
      if (measure == 18) kill_note(basschannel,F1,127);
      if (measure == 18) play_note(basschannel,A1,127);
      if (delay1(speed)) break;
      if (measure == 18) kill_note(basschannel,A1,127);
      if (measure == 16) kill_note(basschannel,F2,127);
      if (measure == 16) play_note(basschannel,G2,127);
      if (measure == 18) play_note(basschannel,AS1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(drumchannel,D1,127);
      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      if (measure == 18) kill_note(basschannel,AS1,127);
      if (measure == 18) play_note(basschannel,B1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      if (measure == 16) kill_note(basschannel,G2,127);
      if (measure == 18) kill_note(basschannel,B1,127);
      if (measure == 22) kill_note(basschannel,F2,127);
      if (measure == 9)
         break;
      }
      //else if measure == 19
      else if (measure == 18)
      {
          cout << "\nMeasure: " << ++measure;
          play_note(drumchannel2,C1,127);
          play_note(basschannel,C2,127);
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          kill_note(drumchannel2,C1,127);

          play_note(drumchannel2,C1,127);
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          kill_note(drumchannel2,C1,127);

          play_note(drumchannel2,C1,127);
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          kill_note(drumchannel2,C1,127);

          play_note(drumchannel2,C1,127);
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          kill_note(drumchannel2,C1,127);
          kill_note(basschannel,C2,127);
      } //else if measure == 20
      else if (measure == 19)
      {
          cout << "\nMeasure: " << ++measure;
          play_note(drumchannel1,D1,127);
          play_note(basschannel,DS2,127);
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          kill_note(drumchannel1,D1,127);

          play_note(drumchannel2,C1,127);
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          if (delay1(speed)) break;
          kill_note(drumchannel2,C1,127);

          play_note(drumchannel1,D1,127);
          if (delay1(speed)) break;
          kill_note(drumchannel1,D1,127);
          play_note(drumchannel2,C1,127);
          if (delay1(speed)) break;
          kill_note(drumchannel2,C1,127);
          if (delay1(speed)) break;
          play_note(drumchannel2,C1,127);
          if (delay1(speed)) break;
          kill_note(drumchannel2,C1,127);

          play_note(drumchannel2,D1,127);
          if (delay1(speed)) break;
          kill_note(drumchannel2,D1,127);
          play_note(drumchannel2,C1,127);
          if (delay1(speed)) break;
          kill_note(drumchannel2,C1,127);
          if (delay1(speed)) break;
          play_note(drumchannel2,C1,127);
          if (delay1(speed)) break;
          kill_note(drumchannel2,C1,127);
          kill_note(basschannel,DS2,127);
      }
      if (measure == 22)
         break;
   }

   for (measure=23;measure<26;measure++)
   {
        //double bass?
        cout << "\nMeasure: " << measure;
        play_note(drumchannel1,C1,127);
        play_note(basschannel,bassnotes[measure][0],basslevel);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);

        if (delay1(speed)) break;
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        kill_note(basschannel,bassnotes[measure][0],basslevel);
        play_note(basschannel,bassnotes[measure][1],basslevel);
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);

        play_note(drumchannel1,D1,127);
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        kill_note(basschannel,bassnotes[measure][1],basslevel);
        play_note(basschannel,bassnotes[measure][2],basslevel);
        play_note(drumchannel1,D1,127);
        play_note(drumchannel1,A2,127);
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        kill_note(drumchannel1,A2,127);
        kill_note(basschannel,bassnotes[measure][2],basslevel);

        play_note(basschannel,bassnotes[measure][3],basslevel);
        play_note(drumchannel1,D1,127);
        play_note(drumchannel1,CS2,127);
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        kill_note(drumchannel1,CS2,127);
        kill_note(basschannel,bassnotes[measure][3],basslevel);
   }
   while (1)
   {
        //double bass?
        cout << "\nMeasure: " << measure;
        play_note(drumchannel1,D1,127);
        play_note(basschannel,bassnotes[measure][0],basslevel);
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        play_note(drumchannel1,D1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        play_note(drumchannel1,D1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        play_note(drumchannel1,D1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);

        if (delay1(speed)) break;
        play_note(drumchannel1,D1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        kill_note(basschannel,bassnotes[measure][0],basslevel);
        play_note(basschannel,bassnotes[measure][1],basslevel);
        play_note(drumchannel1,D1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        play_note(drumchannel1,D1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);

        play_note(drumchannel1,D1,127);
        play_note(drumchannel1,FS1,127);
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        kill_note(basschannel,bassnotes[measure][1],basslevel);
        play_note(basschannel,bassnotes[measure][2],basslevel);
        play_note(drumchannel1,D1,127);
        play_note(drumchannel1,CS2,127);
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        kill_note(drumchannel1,FS1,127);
        kill_note(drumchannel1,D1,127);
        kill_note(drumchannel1,CS2,127);
        kill_note(basschannel,bassnotes[measure][2],basslevel);

        play_note(basschannel,bassnotes[measure][3],basslevel);
        play_note(drumchannel1,D1,127);
        play_note(drumchannel1,A2,127);
        play_note(drumchannel1,AS1,127);
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        kill_note(drumchannel1,A2,127);
        kill_note(drumchannel1,AS1,127);
        kill_note(basschannel,bassnotes[measure][3],basslevel);
        break;
   }

   for (measure=27;measure<31;measure++)
   {
        //double bass?
        cout << "\nMeasure: " << measure;
        play_note(drumchannel1,C1,127);
        play_note(drumchannel1,AS1,127);
        play_note(basschannel,bassnotes[measure][0],basslevel);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        kill_note(drumchannel1,AS1,127);

        play_note(drumchannel1,AS1,127);
        if (delay1(speed)) break;
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        kill_note(basschannel,bassnotes[measure][0],basslevel);
        play_note(basschannel,bassnotes[measure][1],basslevel);
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        play_note(drumchannel1,C1,127);
        if (delay1(speed)) break;
        kill_note(drumchannel1,C1,127);
        kill_note(drumchannel1,AS1,127);

        play_note(drumchannel1,AS1,127);
        play_note(drumchannel1,D1,127);
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        kill_note(basschannel,bassnotes[measure][1],basslevel);
        play_note(basschannel,bassnotes[measure][2],basslevel);
        play_note(drumchannel1,D1,127);
        play_note(drumchannel1,CS2,127);
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        kill_note(drumchannel1,CS2,127);
        kill_note(basschannel,bassnotes[measure][2],basslevel);
        kill_note(drumchannel1,AS1,127);

        play_note(basschannel,bassnotes[measure][3],basslevel);
        play_note(drumchannel1,D1,127);
        play_note(drumchannel1,A2,127);
        play_note(drumchannel1,AS1,127);
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        if (delay1(speed)) break;
        kill_note(drumchannel1,D1,127);
        kill_note(drumchannel1,A2,127);
        kill_note(basschannel,bassnotes[measure][3],basslevel);
        kill_note(drumchannel1,AS1,127);
   }

/*   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      if (measure == 27) play_note(drumchannel1,CS2,127);
      play_note(drumchannel2,C1,127);
      play_note(drumchannel2,DS2,127);
      play_note(basschannel,bassnotes[measure][0],127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      if (measure == 27) kill_note(drumchannel1,CS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,F1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);

      play_note(drumchannel1,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      kill_note(basschannel,bassnotes[measure][0],127);
      play_note(basschannel,bassnotes[measure][1],127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(drumchannel1,D1,127);

      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      kill_note(basschannel,bassnotes[measure][1],127);
      play_note(basschannel,bassnotes[measure][2],127);
      play_note(drumchannel2,DS2,127);
      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      kill_note(basschannel,bassnotes[measure][2],127);

      play_note(basschannel,bassnotes[measure][3],127);
      play_note(drumchannel2,DS2,127);
      play_note(drumchannel1,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel1,D1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(basschannel,bassnotes[measure][3],127);

      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel2,C1,127);
      play_note(drumchannel2,DS2,127);
      play_note(basschannel,bassnotes[measure][0],127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);

      play_note(drumchannel1,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      kill_note(basschannel,bassnotes[measure][0],127);
      play_note(basschannel,bassnotes[measure][1],127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,C2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      kill_note(drumchannel1,D1,127);

      play_note(drumchannel2,DS2,127);
      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel,bassnotes[measure][1],127);
      play_note(basschannel,bassnotes[measure][2],127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      play_note(drumchannel2,C1,127);

      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(basschannel,bassnotes[measure][2],127);

      play_note(basschannel,bassnotes[measure][3],127);

      play_note(drumchannel1,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,DS2,127);
      play_note(drumchannel2,DS2,127);
      kill_note(drumchannel1,D1,127);
      play_note(drumchannel2,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel2,C1,127);
      kill_note(drumchannel2,DS2,127);
      kill_note(basschannel,bassnotes[measure][3],127);
      if (measure == 31)
         break;
   }*/
   if (blah == 1)
      break;
   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,C1,127);

      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);

      play_note(drumchannel,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,B1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,B1,127);
      play_note(drumchannel,A1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,A1,127);
      play_note(drumchannel,G1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,G1,127);
      play_note(drumchannel,F1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,F1,127);

      play_note(drumchannel,B1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,B1,127);
      play_note(drumchannel,A1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,A1,127);
      play_note(drumchannel,G1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,G1,127);
      play_note(drumchannel,F1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,F1,127);
      break;
   }
   } // end blah
   return 1;
}

void showinfo()
{
   clrscr();
   cout << "Contra";
   wait_for_no(INDEX_ESC);
   cout << "\n[1    ]: Level 1";
   cout << "\nESC: Quit" << endl << endl;
   cout << "Q W Q E Q W Q E R T R T  ((slide))" << endl;
   cout << "A S D F (skip) (skip) D F (toms)" << endl;
}

void main()
{

        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        showinfo();
        change_program(guitarchannel,37,2);
        change_program(basschannel,45,1);
        change_program(drumchannel1,120,1);
        change_program(drumchannel2,121,2);
        change_program(synthdrumchannel,118,4);
        change_program(1,105,1);
        change_effects_level(guitarchannel,0);
        //change_effects_channel(guitarchannel);
        change_program(lead2channel,105,1);
        change_program(chordchannel,53,2);
        change_program(stringchannel,53,0); //old 54 2    53 2

        bassnotes[23][0] = G2;
        bassnotes[23][1] = G2;
        bassnotes[23][2] = G2;
        bassnotes[23][3] = F2;

        bassnotes[24][0] = DS2;
        bassnotes[24][1] = DS2;
        bassnotes[24][2] = DS2;
        bassnotes[24][3] = F2;

        bassnotes[25][0] = G2;
        bassnotes[25][1] = G2;
        bassnotes[25][2] = G2;
        bassnotes[25][3] = F2;

        //26 = Weird
        bassnotes[26][0] = DS2;
        bassnotes[26][1] = DS2;
        bassnotes[26][2] = DS2;
        bassnotes[26][3] = F2;

        bassnotes[27][0] = G2;
        bassnotes[27][1] = G2;
        bassnotes[27][2] = G2;
        bassnotes[27][3] = F2;

        bassnotes[28][0] = DS2;
        bassnotes[28][1] = DS2;
        bassnotes[28][2] = DS2;
        bassnotes[28][3] = F2;

        bassnotes[29][0] = G2;
        bassnotes[29][1] = G2;
        bassnotes[29][2] = G2;
        bassnotes[29][3] = A2;

        bassnotes[30][0] = F2;
        bassnotes[30][1] = F2;
        bassnotes[30][2] = F2;
        bassnotes[30][3] = F2;
        change_effects_level(10,0);
        change_light_level(3,127);
        while (1)
        {
/*              play_note(drumchannel1,AS1,127);
                delay1(speed);
                kill_note(drumchannel1,AS1,127);
                play_note(drumchannel1,AS1,127);
                delay1(speed);
                delay1(speed);
                kill_note(drumchannel1,AS1,127);
                delay1(speed);
                delay1(speed);
                play_note(drumchannel1,GS1,127);
                delay1(speed);
                delay1(speed);
                kill_note(drumchannel1,GS1,127);
                delay1(speed);*/
                delay1(1);
                if (key_table[INDEX_1])
                {
                   level1();
                   showinfo();
                   change_light_level(1,0);
                   change_light_level(2,0);
                   change_light_level(3,127);
                   change_light_level(4,0);
                }
                if (key_table[INDEX_ESC]) break;
        }
                kill_keyboard();
                Exit_MIDI();
    }
