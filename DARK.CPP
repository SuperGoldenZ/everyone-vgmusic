#include <dos.h>   
#include "keyboard.h"
#include "midi.h"
#include "lights.h"

int speed = 150; //old 160

int drumchannel = 10;
int drumlevel = 127;
int synthnotes[10][16];

int chordchannel = 2;
int chordlevel = 127;

#define guitarchannel 4
#define guitarlevel 127
#define faderate 3

#define trumpetchannel 5
#define trumpetlevel 127

#define basschannel 6
#define basslevel 127

#define basschannel2 7
#define basslevel2 127

#define synthchannel 8
#define synthlevel 127 //old 127

void menu()
{
   clrscr();
   cout << "The Dark World";
   cout << "\n[ENTER] (+Q) Start";
   cout << "\n[ESC]        Quit";
}

void play_guitar_chord_Q()
{
   play_note(guitarchannel,B2,guitarlevel);
   play_note(guitarchannel,B1,guitarlevel);
}

void kill_guitar_chord_Q()
{
   kill_note(guitarchannel,B2,guitarlevel);
   kill_note(guitarchannel,B1,guitarlevel);
}

void play_guitar_chord_W()
{
   play_note(guitarchannel,A2,guitarlevel);
   play_note(guitarchannel,A1,guitarlevel);
}

void kill_guitar_chord_W()
{
   kill_note(guitarchannel,A2,guitarlevel);
   kill_note(guitarchannel,A1,guitarlevel);
}

void play_guitar_chord_E()
{
   play_note(guitarchannel,G3,guitarlevel);
   play_note(guitarchannel,G2,guitarlevel);
}

void kill_guitar_chord_E()
{
   kill_note(guitarchannel,G3,guitarlevel);
   kill_note(guitarchannel,G2,guitarlevel);
}

void play_guitar_chord_T()
{
   play_note(guitarchannel,FS3,guitarlevel);
   play_note(guitarchannel,FS2,guitarlevel);
}

void kill_guitar_chord_T()
{
   kill_note(guitarchannel,FS3,guitarlevel);
   kill_note(guitarchannel,FS2,guitarlevel);
}

void play_guitar_chord_Y()
{
   play_note(guitarchannel,E3,guitarlevel);
   play_note(guitarchannel,E2,guitarlevel);
}

void kill_guitar_chord_Y()
{
   kill_note(guitarchannel,E3,guitarlevel);
   kill_note(guitarchannel,E2,guitarlevel);
}

void play_guitar_chord_U()
{
   play_note(guitarchannel,D3,guitarlevel);
   play_note(guitarchannel,D2,guitarlevel);
}

void kill_guitar_chord_U()
{
   kill_note(guitarchannel,D3,guitarlevel);
   kill_note(guitarchannel,D2,guitarlevel);
}

void play_guitar_chord_I()
{
   play_note(guitarchannel,CS3,guitarlevel);
   play_note(guitarchannel,CS2,guitarlevel);
}

void kill_guitar_chord_I()
{
   kill_note(guitarchannel,CS3,guitarlevel);
   kill_note(guitarchannel,CS2,guitarlevel);
}

void play_guitar_chord_O()
{
   play_note(guitarchannel,A2,guitarlevel);
   play_note(guitarchannel,A1,guitarlevel);
}

void kill_guitar_chord_O()
{
   kill_note(guitarchannel,A2,guitarlevel);
   kill_note(guitarchannel,A1,guitarlevel);
}

void play_guitar_chord_F2()
{
   play_note(guitarchannel,G3,guitarlevel);
   play_note(guitarchannel,G2,guitarlevel);
}

void kill_guitar_chord_F2()
{
   kill_note(guitarchannel,G3,guitarlevel);
   kill_note(guitarchannel,G2,guitarlevel);
}

void play_guitar_chord_F1()
{
   play_note(guitarchannel,D3,guitarlevel);
   play_note(guitarchannel,D2,guitarlevel);
}

void kill_guitar_chord_F1()
{
   kill_note(guitarchannel,D3,guitarlevel);
   kill_note(guitarchannel,D2,guitarlevel);
}

void play_guitar_chord_F4()
{
   play_note(guitarchannel,A3,guitarlevel);
   play_note(guitarchannel,A2,guitarlevel);
}

void kill_guitar_chord_F4()
{
   kill_note(guitarchannel,A3,guitarlevel);
   kill_note(guitarchannel,A2,guitarlevel);
}

void play_guitar_chord_F3()
{
   play_note(guitarchannel,E3,guitarlevel);
   play_note(guitarchannel,E2,guitarlevel);
}

void kill_guitar_chord_F3()
{
   kill_note(guitarchannel,E3,guitarlevel);
   kill_note(guitarchannel,E2,guitarlevel);
}

void play_guitar_chord_F6()
{
   play_note(guitarchannel,FS3,guitarlevel);
   play_note(guitarchannel,FS2,guitarlevel);
}

void kill_guitar_chord_F6()
{
   kill_note(guitarchannel,FS3,guitarlevel);
   kill_note(guitarchannel,FS2,guitarlevel);
}

void play_guitar_chord_F5()
{
   play_note(guitarchannel,CS3,guitarlevel);
   play_note(guitarchannel,CS2,guitarlevel);
}

void kill_guitar_chord_F5()
{
   kill_note(guitarchannel,CS3,guitarlevel);
   kill_note(guitarchannel,CS2,guitarlevel);
}

void play_guitar_chord_F7()
{
   play_note(guitarchannel,B3,guitarlevel);
   play_note(guitarchannel,B2,guitarlevel);
}

void kill_guitar_chord_F7()
{
   kill_note(guitarchannel,B3,guitarlevel);
   kill_note(guitarchannel,B2,guitarlevel);
}

void play_guitar_chord_F8()
{
   play_note(guitarchannel,FS3,guitarlevel);
   play_note(guitarchannel,FS2,guitarlevel);
}

void kill_guitar_chord_F8()
{
   kill_note(guitarchannel,FS3,guitarlevel);
   kill_note(guitarchannel,FS2,guitarlevel);
}

void play_guitar_chord_F9()
{
   play_note(guitarchannel,A3,guitarlevel);
   play_note(guitarchannel,A2,guitarlevel);
}

void kill_guitar_chord_F9()
{
   kill_note(guitarchannel,A3,guitarlevel);
   kill_note(guitarchannel,A2,guitarlevel);
}

void play_guitar_chord_F10()
{
   play_note(guitarchannel,E3,guitarlevel);
   play_note(guitarchannel,E2,guitarlevel);
}

void kill_guitar_chord_F10()
{
   kill_note(guitarchannel,E3,guitarlevel);
   kill_note(guitarchannel,E2,guitarlevel);
}

void play_guitar_chord_F11()
{
   play_note(guitarchannel,G3,guitarlevel);
   play_note(guitarchannel,G2,guitarlevel);
}

void kill_guitar_chord_F11()
{
   kill_note(guitarchannel,G3,guitarlevel);
   kill_note(guitarchannel,G2,guitarlevel);
}

void play_guitar_chord_F12()
{
   play_note(guitarchannel,D3,guitarlevel);
   play_note(guitarchannel,D2,guitarlevel);
}

void kill_guitar_chord_F12()
{
   kill_note(guitarchannel,D3,guitarlevel);
   kill_note(guitarchannel,D2,guitarlevel);
}

void play_guitar_chord_space()
{
   play_note(guitarchannel,C3,guitarlevel);
   play_note(guitarchannel,C2,guitarlevel);
}

void kill_guitar_chord_space()
{
   kill_note(guitarchannel,C3,guitarlevel);
   kill_note(guitarchannel,C2,guitarlevel);
}

void play_trumpet_chord_1()
{
   play_note(trumpetchannel,B4,trumpetlevel);
   play_note(trumpetchannel,FS4,trumpetlevel);
}

void kill_trumpet_chord_1()
{
   kill_note(trumpetchannel,B4,trumpetlevel);
   kill_note(trumpetchannel,FS4,trumpetlevel);
}

void play_trumpet_chord_2()
{
   play_note(trumpetchannel,A4,trumpetlevel);
   play_note(trumpetchannel,E4,trumpetlevel);
}

void kill_trumpet_chord_2()
{
   kill_note(trumpetchannel,A4,trumpetlevel);
   kill_note(trumpetchannel,E4,trumpetlevel);
}

void play_trumpet_chord_3()
{
   play_note(trumpetchannel,G4,trumpetlevel);
   play_note(trumpetchannel,D4,trumpetlevel);
}

void kill_trumpet_chord_3()
{
   kill_note(trumpetchannel,G4,trumpetlevel);
   kill_note(trumpetchannel,D4,trumpetlevel);
}

void play_trumpet_chord_4()
{
   play_note(trumpetchannel,FS4,trumpetlevel);
   play_note(trumpetchannel,CS4,trumpetlevel);
}

void kill_trumpet_chord_4()
{
   kill_note(trumpetchannel,FS4,trumpetlevel);
   kill_note(trumpetchannel,CS4,trumpetlevel);
}

void do_dark_stuff()
{
   if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
   {
      notes[INDEX_Q]=1;
      play_guitar_chord_Q();
      play_trumpet_chord_1();
   }

   if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))
   {
      kill_guitar_chord_Q();
      kill_trumpet_chord_1();
      notes[INDEX_Q]=0;
   }

   if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
   {
      notes[INDEX_W]=1;
      play_guitar_chord_W();
      play_trumpet_chord_2();
   }

   if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))
   {
      kill_guitar_chord_W();
      kill_trumpet_chord_2();
      notes[INDEX_W]=0;
   }

   if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
   {
      notes[INDEX_E]=1;
      play_guitar_chord_E();
      play_trumpet_chord_3();
   }

   if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))
   {
      kill_guitar_chord_E();
      kill_trumpet_chord_3();
      notes[INDEX_E]=0;
   }

   if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
   {
      notes[INDEX_R]=1;
      play_trumpet_chord_4();
   }

   if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))
   {
      kill_trumpet_chord_4();
      notes[INDEX_R]=0;
   }

   if ((notes[INDEX_T] == 0) && (key_table[INDEX_T]==1))
   {
      notes[INDEX_T]=1;
      play_guitar_chord_T();
   }

   if ((notes[INDEX_T] == 1) && (key_table[INDEX_T]==0))
   {
      kill_guitar_chord_T();
      notes[INDEX_T]=0;
   }

   if ((notes[INDEX_Y] == 0) && (key_table[INDEX_Y]==1))
   {
      notes[INDEX_Y]=1;
      play_guitar_chord_Y();
   }

   if ((notes[INDEX_Y] == 1) && (key_table[INDEX_Y]==0))
   {
      kill_guitar_chord_Y();
      notes[INDEX_Y]=0;
   }

   if ((notes[INDEX_U] == 0) && (key_table[INDEX_U]==1))
   {
      notes[INDEX_U]=1;
      play_guitar_chord_U();
   }

   if ((notes[INDEX_U] == 1) && (key_table[INDEX_U]==0))
   {
      kill_guitar_chord_U();
      notes[INDEX_U]=0;
   }

   if ((notes[INDEX_I] == 0) && (key_table[INDEX_I]==1))
   {
      notes[INDEX_I]=1;
      play_guitar_chord_I();
   }

   if ((notes[INDEX_I] == 1) && (key_table[INDEX_I]==0))
   {
      kill_guitar_chord_I();
      notes[INDEX_I]=0;
   }

   if ((notes[INDEX_O] == 0) && (key_table[INDEX_O]==1))
   {
      notes[INDEX_O]=1;
      play_guitar_chord_O();
   }

   if ((notes[INDEX_O] == 1) && (key_table[INDEX_O]==0))
   {
      kill_guitar_chord_O();
      notes[INDEX_O]=0;
   }

   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      play_guitar_chord_F1();
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      kill_guitar_chord_F1();
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      play_guitar_chord_F2();
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      kill_guitar_chord_F2();
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      play_guitar_chord_F3();
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
      kill_guitar_chord_F3();
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
   {
      notes[INDEX_F4]=1;
      play_guitar_chord_F4();
   }

   if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
   {
      kill_guitar_chord_F4();
      notes[INDEX_F4]=0;
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      play_guitar_chord_F5();
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      kill_guitar_chord_F5();
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
   {
      notes[INDEX_F6]=1;
      play_guitar_chord_F6();
   }

   if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
   {
      kill_guitar_chord_F6();
      notes[INDEX_F6]=0;
   }

   if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
   {
      notes[INDEX_F7]=1;
      play_guitar_chord_F7();
   }

   if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
   {
      kill_guitar_chord_F7();
      notes[INDEX_F7]=0;
   }

   if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
   {
      notes[INDEX_F8]=1;
      play_guitar_chord_F8();
   }

   if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))
   {
      kill_guitar_chord_F8();
      notes[INDEX_F8]=0;
   }

   if ((notes[INDEX_F9] == 0) && (key_table[INDEX_F9]==1))
   {
      notes[INDEX_F9]=1;
      play_guitar_chord_F9();
   }

   if ((notes[INDEX_F9] == 1) && (key_table[INDEX_F9]==0))
   {
      kill_guitar_chord_F9();
      notes[INDEX_F9]=0;
   }

   if ((notes[INDEX_F10] == 0) && (key_table[INDEX_F10]==1))
   {
      notes[INDEX_F10]=1;
      play_guitar_chord_F10();
   }

   if ((notes[INDEX_F10] == 1) && (key_table[INDEX_F10]==0))
   {
      kill_guitar_chord_F10();
      notes[INDEX_F10]=0;
   }

   if ((notes[INDEX_F11] == 0) && (key_table[INDEX_F11]==1))
   {
      notes[INDEX_F11]=1;
      play_guitar_chord_F11();
   }

   if ((notes[INDEX_F11] == 1) && (key_table[INDEX_F11]==0))
   {
      kill_guitar_chord_F11();
      notes[INDEX_F11]=0;
   }

   if ((notes[INDEX_F12] == 0) && (key_table[INDEX_F12]==1))
   {
      notes[INDEX_F12]=1;
      play_guitar_chord_F12();
   }

   if ((notes[INDEX_F12] == 1) && (key_table[INDEX_F12]==0))
   {
      kill_guitar_chord_F12();
      notes[INDEX_F12]=0;
   }

   if ((notes[INDEX_SPACE] == 0) && (key_table[INDEX_SPACE]==1))
   {
      notes[INDEX_SPACE]=1;
      play_guitar_chord_space();
   }

   if ((notes[INDEX_SPACE] == 1) && (key_table[INDEX_SPACE]==0))
   {
      kill_guitar_chord_space();
      notes[INDEX_SPACE]=0;
   }
}

int delay_dark(int speed)
{
   for (int index=0;index<speed;index++)
   {
      if (key_table[INDEX_ESC]) return 1;
      delay(1);
      do_dark_stuff();
   }
   return 0;
}

int odd(int num)
{
   if ((num%2) == 0)
      return 0;
   return 1;
}

void dark_world(int speed)
{
   clrscr();
   cout << "Welcome to the dark world!";

   for (int index=0;index<2;index++)
   {
   for (int measure = 1;measure<=16;measure++)
   {
      cout << "\nMeasure: " << measure;
      if (measure == 1)
      {
         all_lights_off(0);
         change_light_level(7,127);
      }

      if (measure == 4)
      {
         change_light_level(7,0);
         change_light_level(1,50);
         change_light_level(2,75);
         change_light_level(3,25);
         change_light_level(4,50);
      }

      if ((measure >= 1) && (measure <= 7))
      {
         if (measure == 1)
            change_volume(8,95);
         if (odd(measure))
            change_pan(8,0);
         else
            change_pan(8,6);
         if (measure == 1)
            change_volume(4,90);
         if (measure == 1)
            change_volume(1,95);
         cout << " one";
         if ((measure == 1) || (measure == 5))
            play_note(basschannel,B1,basslevel);
         if ((measure == 2) || (measure == 6))
            play_note(basschannel,A1,basslevel);
         if ((measure == 3) || (measure == 7))
            play_note(basschannel,G2,basslevel);
         if (measure == 4)
            play_note(basschannel,FS2,basslevel);

         play_note(drumchannel,CS2,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         play_note(synthchannel,synthnotes[measure][0],synthlevel);
         if (delay_dark(speed)) break;
         kill_note(synthchannel,synthnotes[measure][0],synthlevel);
         play_note(synthchannel,synthnotes[measure][1],synthlevel);
         if (delay_dark(speed)) break;
         if (odd(measure))
            change_pan(8,0);
         else
            change_pan(8,6);
         kill_note(synthchannel,synthnotes[measure][1],synthlevel);
         play_note(synthchannel,synthnotes[measure][2],synthlevel);
         if (delay_dark(speed)) break;
         kill_note(synthchannel,synthnotes[measure][2],synthlevel);
         play_note(synthchannel,synthnotes[measure][3],synthlevel);
         if (delay_dark(speed)) break;
         if (odd(measure))
            change_pan(8,1);
         else
            change_pan(8,5);
         kill_note(synthchannel,synthnotes[measure][3],synthlevel);
         play_note(synthchannel,synthnotes[measure][4],synthlevel);

         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);

         cout << " two";
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         kill_note(synthchannel,synthnotes[measure][4],synthlevel);
         play_note(synthchannel,synthnotes[measure][5],synthlevel);
         if (delay_dark(speed)) break;
         kill_note(synthchannel,synthnotes[measure][5],synthlevel);
         play_note(synthchannel,synthnotes[measure][6],synthlevel);
         if (measure == 4)
         {
            kill_note(basschannel,FS2,basslevel);
            play_note(basschannel,E2,basslevel);
         }

         if (delay_dark(speed)) break;
         if (odd(measure))
            change_pan(8,2);
         else
            change_pan(8,4);
         kill_note(synthchannel,synthnotes[measure][6],synthlevel);
         play_note(synthchannel,synthnotes[measure][7],synthlevel);
         if (delay_dark(speed)) break;
         kill_note(synthchannel,synthnotes[measure][7],synthlevel);
         play_note(synthchannel,synthnotes[measure][8],synthlevel);
         kill_note(drumchannel,FS1,127);

         cout << " three";
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         if (odd(measure))
            change_pan(8,3);
         else
            change_pan(8,3);
         kill_note(synthchannel,synthnotes[measure][8],synthlevel);
         play_note(synthchannel,synthnotes[measure][9],synthlevel);
         if (delay_dark(speed)) break;
         kill_note(synthchannel,synthnotes[measure][9],synthlevel);
         play_note(synthchannel,synthnotes[measure][10],synthlevel);
         if (measure == 4)
         {
            kill_note(basschannel,E2,basslevel);
            play_note(basschannel,D2,basslevel);
         }

         if (delay_dark(speed)) break;
         kill_note(synthchannel,synthnotes[measure][10],synthlevel);
         play_note(synthchannel,synthnotes[measure][11],synthlevel);
         if (delay_dark(speed)) break;
         if (odd(measure))
            change_pan(8,4);
         else
            change_pan(8,2);
         kill_note(synthchannel,synthnotes[measure][11],synthlevel);
         play_note(synthchannel,synthnotes[measure][12],synthlevel);
         kill_note(drumchannel,FS1,127);

         cout << " four";
         play_note(drumchannel,FS1,127);
         if (measure == 4)
         {
            kill_note(basschannel,D2,basslevel);
            play_note(basschannel,CS2,basslevel);
         }

         if (delay_dark(speed)) break;
         kill_note(synthchannel,synthnotes[measure][12],synthlevel);
         play_note(synthchannel,synthnotes[measure][13],synthlevel);
         if (delay_dark(speed)) break;
         if (odd(measure))
            change_pan(8,5);
         else
            change_pan(8,1);
         kill_note(synthchannel,synthnotes[measure][13],synthlevel);
         play_note(synthchannel,synthnotes[measure][14],synthlevel);

         if (measure == 4)
         {
            kill_note(basschannel,CS2,basslevel);
            play_note(basschannel,A1,basslevel);
         }

         if (delay_dark(speed)) break;
         kill_note(synthchannel,synthnotes[measure][14],synthlevel);
         play_note(synthchannel,synthnotes[measure][15],synthlevel);

         if (delay_dark(speed)) break;
         kill_note(drumchannel,FS1,basslevel);
         if ((measure == 1) || (measure == 5))
            kill_note(basschannel,B1,basslevel);
         if ((measure == 2) || (measure == 6))
            kill_note(basschannel,A1,basslevel);
         if ((measure == 3) || (measure == 7))
            kill_note(basschannel,G2,basslevel);
         if (measure == 4)
            kill_note(basschannel,A1,basslevel);
         kill_note(synthchannel,synthnotes[measure][15],synthlevel);
         if (odd(measure))
            change_pan(8,6);
         else
            change_pan(8,0);
      }

      if (measure==8)
      {
         change_volume(8,95-(faderate*1));
         change_volume(4,95);
         cout << " one";
         play_note(drumchannel,CS2,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         play_note(basschannel,FS2,basslevel);
         play_note(synthchannel,synthnotes[8][0],synthlevel);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*2));
         kill_note(synthchannel,synthnotes[8][0],synthlevel);
         play_note(synthchannel,synthnotes[8][1],synthlevel);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*3));
         change_pan(8,6);
         kill_note(synthchannel,synthnotes[8][1],synthlevel);
         play_note(synthchannel,synthnotes[8][2],synthlevel);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*4));
         kill_note(synthchannel,synthnotes[8][2],synthlevel);
         play_note(synthchannel,synthnotes[8][3],synthlevel);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*5));
         change_pan(8,5);
         kill_note(synthchannel,synthnotes[8][3],synthlevel);
         play_note(synthchannel,synthnotes[8][4],synthlevel);
         kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);

         change_volume(4,91);
         cout << " two";
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*6));
         kill_note(synthchannel,synthnotes[8][4],synthlevel);
         play_note(synthchannel,synthnotes[8][5],synthlevel);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*7));
         kill_note(synthchannel,synthnotes[8][5],synthlevel);
         play_note(synthchannel,synthnotes[8][6],synthlevel);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*8));
         change_pan(8,4);
         kill_note(synthchannel,synthnotes[8][6],synthlevel);
         play_note(synthchannel,synthnotes[8][7],synthlevel);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*9));
         kill_note(synthchannel,synthnotes[8][7],synthlevel);
         play_note(synthchannel,synthnotes[8][8],synthlevel);
         kill_note(drumchannel,FS1,127);
         kill_note(basschannel,FS2,basslevel);

         change_volume(4,91-4);
         cout << " three";
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         play_note(basschannel,E2,basslevel);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*10));
         change_pan(8,3);
         kill_note(synthchannel,synthnotes[8][8],synthlevel);
         play_note(synthchannel,synthnotes[8][9],synthlevel);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*11));
         kill_note(synthchannel,synthnotes[8][9],synthlevel);
         play_note(synthchannel,synthnotes[8][10],synthlevel);
         kill_note(basschannel,E2,basslevel);
         play_note(basschannel,D2,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*12));
         kill_note(synthchannel,synthnotes[8][10],synthlevel);
         play_note(synthchannel,synthnotes[8][11],synthlevel);
         kill_note(drumchannel,D1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*13));
         kill_note(synthchannel,synthnotes[8][11],synthlevel);
         play_note(synthchannel,synthnotes[8][12],synthlevel);
         kill_note(drumchannel,36,127);
         kill_note(basschannel,D2,basslevel);

         change_volume(4,91-8);
         cout << " four";
         play_note(drumchannel,FS1,127);
         play_note(basschannel,CS2,basslevel);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*14));
         kill_note(synthchannel,synthnotes[8][12],synthlevel);
         play_note(synthchannel,synthnotes[8][13],synthlevel);
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*15));
         kill_note(synthchannel,synthnotes[8][13],synthlevel);
         play_note(synthchannel,synthnotes[8][14],synthlevel);
         kill_note(drumchannel,36,127);
         kill_note(basschannel,CS2,basslevel);
         play_note(basschannel,A1,basslevel);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*16));
         kill_note(synthchannel,synthnotes[8][14],synthlevel);
         play_note(synthchannel,synthnotes[8][15],synthlevel);
         kill_note(drumchannel,D1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         change_volume(8,95-(faderate*17));
         kill_note(synthchannel,synthnotes[8][15],synthlevel);
         kill_note(drumchannel,D1,127);
         kill_note(basschannel,A1,basslevel);
      }

      if ((measure >= 9) && (measure <= 12))
      {
         if (measure == 9)
         {
            all_lights_off(0);
            change_light_level(13,127);
         }
         change_volume(4,80);
         change_volume(1,99);
         if (measure == 9)
            play_note(drumchannel,CS2,127);
         unsigned char bassnote1, bassnote2;
         if ((measure == 9) || (measure == 12))
         {
            bassnote1 = G2;
            bassnote2 = D2;
         }
         if (measure == 10)
         {
            bassnote1 = A2;
            bassnote2 = E2;
         }
         if (measure == 11)
         {
            bassnote1 = FS2;
            bassnote2 = CS2;
         }
            
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         cout << " two";
         play_note(basschannel2,bassnote1,basslevel);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote1,basslevel);
         if ((measure == 9) || (measure == 13) || (measure == 15))
            kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         cout << " three";
         play_note(basschannel2,bassnote1,basslevel);
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote1,basslevel);
         cout << " one";
         play_note(basschannel2,bassnote2,basslevel);
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote2,basslevel);
         cout << " two";
         play_note(basschannel2,bassnote1,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote1,basslevel);
         cout << " three";
         play_note(basschannel2,bassnote1,basslevel);
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote1,basslevel);
         cout << " one";
         play_note(basschannel2,bassnote2,basslevel);
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote2,basslevel);
         cout << " two";
         play_note(basschannel2,bassnote1,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote1,basslevel);
         cout << " three";
         play_note(basschannel2,bassnote1,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote1,basslevel);
         cout << " one";
         play_note(basschannel2,bassnote2,basslevel);
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,AS1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote2,basslevel);
         cout << " two";
         if (measure != 12)
            play_note(basschannel2,bassnote1,basslevel);
         else
            play_note(basschannel2,G2,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);

         if (delay_dark(speed)) break;
         cout << " three";
         if (measure != 12)
         {
            kill_note(basschannel2,bassnote1,basslevel);
            play_note(basschannel2,bassnote1,basslevel);
         } else
         {
            kill_note(basschannel2,G2,basslevel);
            play_note(basschannel2,D2,basslevel);
         }
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         if (measure == 12)
         {
            kill_note(basschannel2,D2,basslevel);
            play_note(basschannel2,A2,basslevel);
         }
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         cout << " one";
         if (measure != 12)
         {
            kill_note(basschannel2,bassnote1,basslevel);
            play_note(basschannel2,bassnote2,basslevel);
         } else
         {
            kill_note(basschannel2,A2,basslevel);
            play_note(basschannel2,E2,basslevel);
         }
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         if (measure != 12)
            kill_note(basschannel2,bassnote2,basslevel);
         else
            kill_note(basschannel2,E2,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
      }

      if ((measure == 13) || (measure == 14) || (measure == 15))
      {
         //if (measure == 13)
         //   change_volume(4,75);
         if (measure == 13)
         {
            change_light_level(13,0);
            change_light_level(1,50);
            change_light_level(2,75);
            change_light_level(3,25);
            change_light_level(4,50);
         }

         if ((measure == 13) || (measure == 15))
            play_note(drumchannel,CS2,127);
         unsigned char bassnote11, bassnote21,bassnote12,bassnote22,
                       bassnote31, bassnote32;
         if ((measure == 13) || (measure == 15))
         {
            bassnote11 = B2;
            bassnote21 = FS2;
            bassnote12 = A2;
            bassnote22 = E2;
            bassnote31 = A2;
            bassnote32 = E2;
         }
         if (measure == 14)
         {
            bassnote11 = G2;
            bassnote21 = D2;
            bassnote12 = G2;
            bassnote22 = D2;
            bassnote31 = A2;
            bassnote32 = E2;
         }

         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         play_note(basschannel2,bassnote11,basslevel);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote11,basslevel);
         play_note(basschannel2,bassnote21,basslevel);
         if ((measure == 13) || (measure == 15))
            kill_note(drumchannel,CS2,127);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote21,basslevel);
         play_note(basschannel2,bassnote11,basslevel);
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote11,basslevel);
         play_note(basschannel2,bassnote21,basslevel);
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote21,basslevel);
         play_note(basschannel2,bassnote11,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote11,basslevel);
         play_note(basschannel2,bassnote21,basslevel);
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote21,basslevel);
         play_note(basschannel2,bassnote11,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote11,basslevel);
         play_note(basschannel2,bassnote12,basslevel);
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote12,basslevel);
         play_note(basschannel2,bassnote22,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote22,basslevel);
         play_note(basschannel2,bassnote12,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote12,basslevel);
         play_note(basschannel2,bassnote22,basslevel);
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote22,basslevel);
         play_note(basschannel2,bassnote12,basslevel);
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,AS1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote12,basslevel);
         play_note(basschannel2,bassnote22,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote22,basslevel);
         play_note(basschannel2,bassnote12,basslevel);
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote12,basslevel);
         play_note(basschannel2,bassnote31,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote31,basslevel);
         play_note(basschannel2,bassnote32,basslevel);
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D1,127);
         if (measure != 14)
         {
            play_note(drumchannel,FS1,127);
            play_note(drumchannel,36,127);
         } else
         {
            play_note(drumchannel,D1,127);
            play_note(drumchannel,FS1,127);
         }
         if (delay_dark(speed)) break;
         kill_note(basschannel2,bassnote32,basslevel);
         if (measure != 14)
         {
            kill_note(drumchannel,FS1,127);
            kill_note(drumchannel,36,127);
         } else
         {
            kill_note(drumchannel,D1,127);
            kill_note(drumchannel,FS1,127);
         }
      }

      if (measure == 16)
      {
         change_volume(4,80);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         play_note(basschannel2,C2,basslevel);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,C2,basslevel);
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         play_note(basschannel2,C2,basslevel);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,C2,basslevel);
         play_note(basschannel2,C2,basslevel);
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,C2,basslevel);
         play_note(basschannel2,C2,basslevel);
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,C2,basslevel);

         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         play_note(basschannel2,FS2,basslevel);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,FS1,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,FS2,basslevel);
         play_note(basschannel2,E2,basslevel);
         kill_note(drumchannel,FS1,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,D1,127);
         kill_note(drumchannel,AS1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,E2,basslevel);
         play_note(basschannel2,D2,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,36,127);
         if (delay_dark(speed)) break;
         kill_note(basschannel2,D2,basslevel);
         play_note(basschannel2,CS2,basslevel);
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,36,127);
         play_note(drumchannel,AS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,AS1,127);
         kill_note(drumchannel,D1,127);
         play_note(drumchannel,FS1,127);
         play_note(drumchannel,D1,127);
         if (delay_dark(speed)) break;
         kill_note(drumchannel,FS1,127);
         kill_note(drumchannel,D1,127);
         kill_note(basschannel2,CS2,basslevel);
      }
   }
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
   synthnotes[1][0] = B3;
   synthnotes[1][1] = D4;
   synthnotes[1][2] = FS4;
   synthnotes[1][3] = D4;
   synthnotes[1][4] = B3;
   synthnotes[1][5] = D4;
   synthnotes[1][6] = FS4;
   synthnotes[1][7] = D4;
   synthnotes[1][8] = B3;
   synthnotes[1][9] = D4;
   synthnotes[1][10] = FS4;
   synthnotes[1][11] = B4;
   synthnotes[1][12] = D5;
   synthnotes[1][13] = B4;
   synthnotes[1][14] = FS4;
   synthnotes[1][15] = D4;

   synthnotes[2][0] = A3;
   synthnotes[2][1] = CS4;
   synthnotes[2][2] = E4;
   synthnotes[2][3] = CS4;
   synthnotes[2][4] = A3;
   synthnotes[2][5] = CS4;
   synthnotes[2][6] = E4;
   synthnotes[2][7] = CS4;
   synthnotes[2][8] = A3;
   synthnotes[2][9] = CS4;
   synthnotes[2][10] = E4;
   synthnotes[2][11] = CS4;
   synthnotes[2][12] = A4;
   synthnotes[2][13] = E4;
   synthnotes[2][14] = CS4;
   synthnotes[2][15] = A3;

   synthnotes[3][0] = G3;
   synthnotes[3][1] = B3;
   synthnotes[3][2] = D4;
   synthnotes[3][3] = B3;
   synthnotes[3][4] = G3;
   synthnotes[3][5] = B3;
   synthnotes[3][6] = D4;
   synthnotes[3][7] = B3;
   synthnotes[3][8] = G3;
   synthnotes[3][9] = B3;
   synthnotes[3][10] = D4;
   synthnotes[3][11] = G4;
   synthnotes[3][12] = B4;
   synthnotes[3][13] = G4;
   synthnotes[3][14] = D4;
   synthnotes[3][15] = B3;

   synthnotes[4][0] = AS3;
   synthnotes[4][1] = CS4;
   synthnotes[4][2] = FS4;
   synthnotes[4][3] = CS4;
   synthnotes[4][4] = AS3;
   synthnotes[4][5] = CS4;
   synthnotes[4][6] = FS4;
   synthnotes[4][7] = CS4;
   synthnotes[4][8] = AS3;
   synthnotes[4][9] = CS4;
   synthnotes[4][10] = FS4;
   synthnotes[4][11] = CS4;
   synthnotes[4][12] = AS3;
   synthnotes[4][13] = CS4;
   synthnotes[4][14] = FS4;
   synthnotes[4][15] = CS4;

   for (int measure=5;measure<=9;measure++)
      for (int note=0;note<=15;note++)
         synthnotes[measure][note] = synthnotes[measure-4][note];

   change_program(1,54,3); //old 54 3
   change_program(4,37,2);
   change_program(5,69,2);
   change_program(6,44,3);
   change_program(7,41,2);
   change_program(8,90,0); //old 103 0 
   change_program(10,120,1);
   change_volume(1,95);
   change_volume(2,90);
   change_volume(3,90);
   change_volume(4,90);
   change_volume(5,90);
   change_volume(6,90);
   change_volume(8,95);
   change_pan(8,0);
   change_volume(10,90);
   mix_mode();
   mix_name("DarkWorld");
   menu();
   while (1)   
   {   
      if (key_table[INDEX_ENTER])
      {
         dark_world(speed);
         all_lights_off(0);
         change_light_level(3,127);

         play_note(basschannel,B1,basslevel);
         play_note(10,CS2,127);
         play_note(10,A2,127);
         wait_for_no(INDEX_ESC);
         delay_dark(250);
         kill_note(10,CS2,127);
         kill_note(10,A2,127);
         kill_note(basschannel,B1,basslevel);
         menu();
      }
      do_dark_stuff();
      if (key_table[INDEX_ESC]) break;
   }   
   Exit_MIDI();   
   kill_keyboard();   
   cout << "\n\ndark.cpp terminated";   
}
