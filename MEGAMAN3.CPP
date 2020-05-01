#include <dos.h>
#include <conio.h>
#include "keyboard.h"
#include "midi.h"
#include "lights.h"

#define drumlevel 127
#define drumchannel 10

#define synthdrumchannel 11
#define synthdrumlevel 127

#define basschannel 2
#define basslevel 127

#define introbasschannel 3
#define introbasslevel 127

#define tinelevel 127

#define lead2channel 4

#define lead3channel 5

#define stringchannel 6 //52 2

#define stringchannel2 8 //55 user

#define guitarchannel 9

#define padechochannel 7

#define pianochannel 12

#define blahchannel 13

#define tinechannel 15

#define chordlevel556 90

#define samplechannel 14

int bassnotes[50][12];

int speed = 100;

int measure = -1;

int firstnote = 0;
int lightfadein = 0;

void dostuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      firstnote = 1;
      play_note(introbasschannel,FS2,introbasslevel);
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      kill_note(introbasschannel,FS2,introbasslevel);
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      play_note(introbasschannel,E2,introbasslevel);
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      kill_note(introbasschannel,E2,introbasslevel);
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))
   {
      notes[INDEX_LEFT]=1;
      play_note(introbasschannel,B1,introbasslevel);
   }

   if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))
   {
      kill_note(introbasschannel,B1,introbasslevel);
      notes[INDEX_LEFT]=0;
   }

   if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
   {
      notes[INDEX_UP]=1;
      play_note(introbasschannel,CS2,introbasslevel);
   }

   if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))
   {
      kill_note(introbasschannel,CS2,introbasslevel);
      notes[INDEX_UP]=0;
   }

   if ((notes[INDEX_RIGHT] == 0) && (key_table[INDEX_RIGHT]==1))
   {
      notes[INDEX_RIGHT]=1;
      play_note(introbasschannel,D2,introbasslevel);
   }

   if ((notes[INDEX_RIGHT] == 1) && (key_table[INDEX_RIGHT]==0))
   {
      kill_note(introbasschannel,D2,introbasslevel);
      notes[INDEX_RIGHT]=0;
   }

   if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))
   {
      notes[INDEX_DOWN]=1;
      play_note(introbasschannel,F2,introbasslevel);
   }

   if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))
   {
      kill_note(introbasschannel,F2,introbasslevel);
      notes[INDEX_DOWN]=0;
   }

   if ((notes[INDEX_ENTER] == 0) && (key_table[INDEX_ENTER]==1))
   {
      notes[INDEX_ENTER]=1;
      play_note(introbasschannel,CS3,introbasslevel);
      fade_out_light(2,50,1,2);
   }

   if ((notes[INDEX_ENTER] == 1) && (key_table[INDEX_ENTER]==0))
   {
      kill_note(introbasschannel,CS3,introbasslevel);
      notes[INDEX_ENTER]=0;
   }

   if ((notes[INDEX_G] == 0) && (key_table[INDEX_G]==1))
   {
      notes[INDEX_G]=1;
      play_note(introbasschannel,C2,introbasslevel);
   }

   if ((notes[INDEX_G] == 1) && (key_table[INDEX_G]==0))
   {
      kill_note(introbasschannel,C2,introbasslevel);
      notes[INDEX_G]=0;
   }

   if ((notes[INDEX_T] == 0) && (key_table[INDEX_T]==1))
   {
      notes[INDEX_T]=1;
      play_note(introbasschannel,DS2,introbasslevel);
   }

   if ((notes[INDEX_T] == 1) && (key_table[INDEX_T]==0))
   {
      kill_note(introbasschannel,DS2,introbasslevel);
      notes[INDEX_T]=0;
   }

/*   if ((notes[INDEX_11] == 0) && (key_table[INDEX_11]==1))
   {
      notes[INDEX_11]=1;
      play_note(stringchannel,CS4,introbasslevel);
      play_note(lead2channel,CS4,introbasslevel);
   }

   if ((notes[INDEX_11] == 1) && (key_table[INDEX_11]==0))
   {
      kill_note(stringchannel,CS4,introbasslevel);
      kill_note(lead2channel,CS4,introbasslevel);
      notes[INDEX_11]=0;
   }

   if ((notes[INDEX_21] == 0) && (key_table[INDEX_21]==1))
   {
      notes[INDEX_21]=1;
      play_note(stringchannel,F4,introbasslevel);
      play_note(lead2channel,F4,introbasslevel);
   }

   if ((notes[INDEX_21] == 1) && (key_table[INDEX_21]==0))
   {
      kill_note(stringchannel,F4,introbasslevel);
      kill_note(lead2channel,F4,introbasslevel);
      notes[INDEX_21]=0;
   }

   if ((notes[INDEX_31] == 0) && (key_table[INDEX_31]==1))
   {
      notes[INDEX_31]=1;
      play_note(stringchannel,GS4,introbasslevel);
      play_note(lead2channel,GS4,introbasslevel);
   }

   if ((notes[INDEX_31] == 1) && (key_table[INDEX_31]==0))
   {
      kill_note(stringchannel,GS4,introbasslevel);
      kill_note(lead2channel,GS4,introbasslevel);
      notes[INDEX_31]=0;
   }

   if ((notes[INDEX_41] == 0) && (key_table[INDEX_41]==1))
   {
      notes[INDEX_41]=1;
      play_note(stringchannel,CS5,introbasslevel);
      play_note(lead2channel,CS5,introbasslevel);
   }

   if ((notes[INDEX_41] == 1) && (key_table[INDEX_41]==0))
   {
      kill_note(stringchannel,CS5,introbasslevel);
      kill_note(lead2channel,CS5,introbasslevel);
      notes[INDEX_41]=0;
   }*/

   if ((notes[INDEX_P] == 0) && (key_table[INDEX_P]==1))
   {
      notes[INDEX_P]=1;
      play_note(tinechannel,A4,tinelevel);
   }

   if ((notes[INDEX_P] == 1) && (key_table[INDEX_P]==0))
   {
      kill_note(tinechannel,A4,tinelevel);
      notes[INDEX_P]=0;
   }

   if ((notes[INDEX_O] == 0) && (key_table[INDEX_O]==1))
   {
      notes[INDEX_O]=1;
      play_note(tinechannel,FS4,tinelevel);
   }

   if ((notes[INDEX_O] == 1) && (key_table[INDEX_O]==0))
   {
      kill_note(tinechannel,FS4,tinelevel);
      notes[INDEX_O]=0;
   }

   if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
   {
      notes[INDEX_F4]=1;
      play_note(tinechannel,CS5,tinelevel);
   }

   if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
   {
      kill_note(tinechannel,CS5,tinelevel);
      notes[INDEX_F4]=0;
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      play_note(tinechannel,E4,tinelevel);
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      kill_note(tinechannel,E4,tinelevel);
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
   {
      notes[INDEX_F6]=1;
      play_note(tinechannel,F4,tinelevel);
   }

   if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
   {
      notes[INDEX_F6]=0;
      kill_note(tinechannel,F4,tinelevel);
   }
}

void dostuff1()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      play_note(stringchannel,E4,introbasslevel);
      play_note(lead2channel,E4,introbasslevel);
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      kill_note(stringchannel,E4,introbasslevel);
      kill_note(lead2channel,E4,introbasslevel);
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      play_note(stringchannel,A3,introbasslevel);
      play_note(lead2channel,A3,introbasslevel);
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      kill_note(stringchannel,A3,introbasslevel);
      kill_note(lead2channel,A3,introbasslevel);
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      play_note(stringchannel,CS4,introbasslevel);
      play_note(lead2channel,CS4,introbasslevel);
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
      kill_note(stringchannel,CS4,introbasslevel);
      kill_note(lead2channel,CS4,introbasslevel);
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      play_note(stringchannel,FS4,introbasslevel);
      play_note(lead2channel,FS4,introbasslevel);
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      kill_note(stringchannel,FS4,introbasslevel);
      kill_note(lead2channel,FS4,introbasslevel);
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
   {
      notes[INDEX_F6]=1;
      play_note(stringchannel,CS4,introbasslevel);
      play_note(lead2channel,CS4,introbasslevel);
   }

   if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
   {
      kill_note(stringchannel,CS4,introbasslevel);
      kill_note(lead2channel,CS4,introbasslevel);
      notes[INDEX_F6]=0;
   }

   if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
   {
      notes[INDEX_F7]=1;
      play_note(stringchannel,E4,introbasslevel);
      play_note(lead2channel,E4,introbasslevel);
   }

   if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
   {
      kill_note(stringchannel,E4,introbasslevel);
      kill_note(lead2channel,E4,introbasslevel);
      notes[INDEX_F7]=0;
   }

   if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
   {
      notes[INDEX_F8]=1;
      play_note(stringchannel,GS4,introbasslevel);
      play_note(lead2channel,GS4,introbasslevel);
   }

   if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))
   {
      kill_note(stringchannel,GS4,introbasslevel);
      kill_note(lead2channel,GS4,introbasslevel);
      notes[INDEX_F8]=0;
   }

   if ((notes[INDEX_11] == 0) && (key_table[INDEX_11]==1))
   {
      notes[INDEX_11]=1;
      play_note(stringchannel,CS5,chordlevel556);
      play_note(stringchannel2,CS4,chordlevel556);
      play_note(lead2channel,CS5,chordlevel556);
   }

   if ((notes[INDEX_11] == 1) && (key_table[INDEX_11]==0))
   {
      kill_note(stringchannel,CS5,chordlevel556);
      kill_note(stringchannel2,CS4,chordlevel556);
      kill_note(lead2channel,CS5,chordlevel556);
      notes[INDEX_11]=0;
   }

   if ((notes[INDEX_21] == 0) && (key_table[INDEX_21]==1))
   {
      notes[INDEX_21]=1;
      play_note(stringchannel,B4,chordlevel556);
      play_note(stringchannel2,B3,chordlevel556);
      play_note(lead2channel,B4,chordlevel556);
   }

   if ((notes[INDEX_21] == 1) && (key_table[INDEX_21]==0))
   {
      kill_note(stringchannel,B4,introbasslevel);
      kill_note(stringchannel2,B3,introbasslevel);
      kill_note(lead2channel,B4,introbasslevel);
      notes[INDEX_21]=0;
   }

   if ((notes[INDEX_31] == 0) && (key_table[INDEX_31]==1))
   {
      notes[INDEX_31]=1;
      play_note(stringchannel,E5,chordlevel556);
      play_note(stringchannel2,E4,chordlevel556);
      play_note(lead2channel,E5,chordlevel556);
   }

   if ((notes[INDEX_31] == 1) && (key_table[INDEX_31]==0))
   {
      kill_note(stringchannel,E5,introbasslevel);
      kill_note(stringchannel2,E4,introbasslevel);
      kill_note(lead2channel,E5,introbasslevel);
      notes[INDEX_31]=0;
   }

   if ((notes[INDEX_41] == 0) && (key_table[INDEX_41]==1))
   {
      notes[INDEX_41]=1;
      play_note(stringchannel,DS5,chordlevel556);
      play_note(stringchannel2,DS4,chordlevel556);
      play_note(lead2channel,DS5,chordlevel556);
   }

   if ((notes[INDEX_41] == 1) && (key_table[INDEX_41]==0))
   {
      kill_note(stringchannel,DS5,introbasslevel);
      kill_note(stringchannel2,DS4,introbasslevel);
      kill_note(lead2channel,DS5,introbasslevel);
      notes[INDEX_41]=0;
   }

   if ((notes[INDEX_51] == 0) && (key_table[INDEX_51]==1))
   {
      notes[INDEX_51]=1;
      play_note(stringchannel,GS4,chordlevel556);
      play_note(stringchannel2,GS3,chordlevel556);
      play_note(lead2channel,GS4,chordlevel556);
   }

   if ((notes[INDEX_51] == 1) && (key_table[INDEX_51]==0))
   {
      kill_note(stringchannel,GS4,introbasslevel);
      kill_note(stringchannel2,GS3,introbasslevel);
      kill_note(lead2channel,GS4,introbasslevel);
      notes[INDEX_51]=0;
   }

   if ((notes[INDEX_61] == 0) && (key_table[INDEX_61]==1))
   {
      notes[INDEX_61]=1;
      play_note(stringchannel,FS4,chordlevel556);
      play_note(stringchannel2,FS3,chordlevel556);
      play_note(lead2channel,FS4,chordlevel556);
   }

   if ((notes[INDEX_61] == 1) && (key_table[INDEX_61]==0))
   {
      kill_note(stringchannel,FS4,introbasslevel);
      kill_note(stringchannel2,FS3,introbasslevel);
      kill_note(lead2channel,FS4,introbasslevel);
      notes[INDEX_61]=0;
   }

   if ((notes[INDEX_71] == 0) && (key_table[INDEX_71]==1))
   {
      notes[INDEX_71]=1;
      play_note(stringchannel,CS4,chordlevel556);
      play_note(stringchannel2,CS3,chordlevel556);
      play_note(lead2channel,CS4,chordlevel556);
   }

   if ((notes[INDEX_71] == 1) && (key_table[INDEX_71]==0))
   {
      kill_note(stringchannel,CS4,introbasslevel);
      kill_note(stringchannel2,CS3,introbasslevel);
      kill_note(lead2channel,CS4,introbasslevel);
      notes[INDEX_71]=0;
   }

   if ((notes[INDEX_81] == 0) && (key_table[INDEX_81]==1))
   {
      notes[INDEX_81]=1;
      play_note(stringchannel,CS4,introbasslevel);
      play_note(lead2channel,CS4,introbasslevel);
   }

   if ((notes[INDEX_81] == 1) && (key_table[INDEX_81]==0))
   {
      kill_note(stringchannel,CS4,introbasslevel);
      kill_note(lead2channel,CS4,introbasslevel);
      notes[INDEX_81]=0;
   }

   if (measure >= 18)
   {

   if ((notes[INDEX_SPACE] == 0) && (key_table[INDEX_SPACE]==1))
   {
      notes[INDEX_SPACE]=1;
      play_note(stringchannel,FS3,introbasslevel);
      play_note(lead2channel,FS3,introbasslevel);
   }

   if ((notes[INDEX_SPACE] == 1) && (key_table[INDEX_SPACE]==0))
   {
      kill_note(stringchannel,FS3,100);
      kill_note(lead2channel,FS3,100);
      notes[INDEX_SPACE]=0;
   }
   }

   if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))
   {
      notes[INDEX_LEFT]=1;
      play_note(stringchannel,B3,100);
      play_note(lead2channel,B3,100);
   }

   if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))
   {
      kill_note(stringchannel,B3,100);
      kill_note(lead2channel,B3,100);
      notes[INDEX_LEFT]=0;
   }

   if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))
   {
      notes[INDEX_DOWN]=1;
      play_note(stringchannel,CS4,100);
      play_note(lead2channel,CS4,100);
   }

   if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))
   {
      kill_note(stringchannel,CS4,100);
      kill_note(lead2channel,CS4,100);
      notes[INDEX_DOWN]=0;
   }

   if ((notes[INDEX_RIGHT] == 0) && (key_table[INDEX_RIGHT]==1))
   {
      notes[INDEX_RIGHT]=1;
      play_note(stringchannel,E4,100);
      play_note(lead2channel,E4,100);
   }

   if ((notes[INDEX_RIGHT] == 1) && (key_table[INDEX_RIGHT]==0))
   {
      kill_note(stringchannel,E4,100);
      kill_note(lead2channel,E4,100);
      notes[INDEX_RIGHT]=0;
   }

   if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
   {
      notes[INDEX_UP]=1;
      play_note(stringchannel,DS4,100);
      play_note(lead2channel,DS4,100);
   }

   if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))
   {
      kill_note(stringchannel,DS4,100);
      kill_note(lead2channel,DS4,100);
      notes[INDEX_UP]=0;
   }

   if ((notes[INDEX_A] == 0) && (key_table[INDEX_A]==1))
   {
      notes[INDEX_A]=1;
      play_note(guitarchannel,D2,127);
   }

   if ((notes[INDEX_A] == 1) && (key_table[INDEX_A]==0))
   {
      kill_note(guitarchannel,D2,127);
      notes[INDEX_A]=0;
   }


   if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
   {
      notes[INDEX_Q]=1;
      play_note(blahchannel,CS4,127);
      play_note(blahchannel,A3,127);
      play_note(blahchannel,FS3,127);
//    play_note(blahchannel2,A3,127);
//    play_note(lead2channel,CS4,127);
   }

   if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))
   {
      kill_note(blahchannel,CS4,127);
      kill_note(blahchannel,A3,127);
      kill_note(blahchannel,FS3,127);
//    kill_note(blahchannel2,A3,127);
//    kill_note(lead2channel,CS4,127);
      notes[INDEX_Q]=0;
   }

   if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
   {
      notes[INDEX_W]=1;
      play_note(blahchannel,A3,127);
      play_note(blahchannel,CS4,127);
      play_note(blahchannel,E4,127);
   }

   if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))
   {
      kill_note(blahchannel,A3,127);
      kill_note(blahchannel,CS4,127);
      kill_note(blahchannel,E4,127);
      notes[INDEX_W]=0;
   }

   if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
   {
      notes[INDEX_E]=1;
      play_note(blahchannel,CS4,127);
      play_note(blahchannel,E4,127);
      play_note(blahchannel,GS4,127);
   }

   if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))
   {
      kill_note(blahchannel,CS4,127);
      kill_note(blahchannel,E4,127);
      kill_note(blahchannel,GS4,127);
      notes[INDEX_E]=0;
   }

   if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
   {
      notes[INDEX_R]=1;
      play_note(blahchannel,GS4,127);
      play_note(blahchannel,B3,127);
      play_note(blahchannel,DS4,127);
   }

   if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))
   {
      kill_note(blahchannel,GS4,127);
      kill_note(blahchannel,B3,127);
      kill_note(blahchannel,DS4,127);
      notes[INDEX_R]=0;
   }
}

int delay1(int speed)
{
        for (int index=0;index<speed;index++)
        {
                if (key_table[INDEX_ESC]) return 1;
                if (measure < 21)
                   dostuff();
                else
                   dostuff1();
                do_fade_stuff();
                delay (1);
        }
        return 0;
}

int delay_space(int speed)
{
        for (int index=0;index<speed;index++)
        {
                if (key_table[INDEX_SPACE]) return 1;
                dostuff();
                do_fade_stuff();
                delay(1);
        }
        return 0;
}

int intro()
{
   clrscr();
   wait_for_no(INDEX_ESC);
   all_lights_off(1);
   cout <<   "F1";                   //1
   cout << "\nF2 F2 F1";             //2
   cout << "\nLEFT UP    RIGHT";   //3
   cout << "\n           DOWN";                //4
   cout << "\nF1";                   //5
   cout << "\nF2";                   //6
   cout << "\nRIGHT";                //7
   cout << "\n     RIGHT F2   (\"da da \")";             //8
   cout << "\nF1                     O";                   //9
   cout << "\nF2 F2 F1               P";//10
   cout << "\nLEFT G                 F4";               //11
   cout << "\nUP                     F5 F6";  //12
   cout << "\nF1 F1 DOWN             O";           //13
   cout << "\nF2 F2 T                P";              //14
   cout << "\nRIGHT                  F4";                //15
   cout << "\nENTER";                //16
   cout << "\nHIT F12 TO START";
   wait_for(INDEX_F12);
   cout << "5 ";
   mix_name("5          ");
   mix_mode();
   delay1(200);
   cout << "4 ";
   mix_name("4          ");
   mix_mode();
   delay1(200);
   cout << "3 ";
   mix_name("3          ");
   mix_mode();
   delay1(200);
   cout << "2 ";
   mix_name("2          ");
   mix_mode();
   delay1(200);
   cout << "1 ";
   mix_name("1          ");
   mix_mode();
   delay1(200);
   mix_name("Mega Man   ");
   mix_mode();

   cout << "\n\nPress SPACE to start drum loop";
   measure = 0;
   while (1)
   {
      if ((firstnote == 1) && (lightfadein == 0))
      {
         fade_in_light(2,150,75,2);
         lightfadein = 1;
      }
      if (delay_space(speed)) break;
   }
   measure = 16;
   cout << "5 ";
   mix_name("5          ");
   mix_mode();
   delay1(200);
   cout << "4 ";
   mix_name("4          ");
   mix_mode();
   delay1(200);
   cout << "3 ";
   mix_name("3          ");
   mix_mode();
   delay1(200);
   cout << "2 ";
   mix_name("2          ");
   mix_mode();
   delay1(200);
   cout << "1 ";
   mix_name("1          ");
   mix_mode();
   delay1(200);
   mix_name("Mega Man   ");

   change_keyboard_input(lead2channel,1);
   change_program(lead3channel,9,1);

   change_volume(lead3channel,90);
   change_keyboard_input(lead3channel,1);

   change_program(1,90,1);
   change_program(lead2channel,91,1);
   kill_note(stringchannel,CS5,introbasslevel);
   kill_note(lead2channel,CS5,introbasslevel);
   mix_mode();

   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,D1,127);
      play_note(basschannel,D2,127);

      change_light_level(1,127);
      change_light_level(3,127);
      cout << "\ndrum! ";
      if (delay1(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      cout << "drum! ";
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      cout << "drum! ";
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      
      
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      cout << "drum! ";
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      
      
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      cout << "drum! ";
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      
      
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      cout << "drum! ";
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      cout << "drum! ";
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      cout << "drum! ";
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      cout << "drum! ";
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      all_lights_off(0);
      cout << "drum! ";
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      kill_note(basschannel,D2,127);
      

      change_light_level(2,127);
      change_light_level(4,127);

      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,D1,127);
      play_note(basschannel,E2,127);
      
      cout << "\ndrum! ";
      if (delay1(speed)) break;
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      cout << "drum! ";
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      
      
      cout << "drum! ";
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      cout << "drum! ";
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      cout << "drum! ";
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      cout << "drum! ";
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      cout << "drum! ";
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      cout << "drum! ";
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      
      cout << "drum! ";
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      
      all_lights_off(0);
      cout << "drum! ";
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      kill_note(basschannel,E2,127);
      

      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,D1,127);
      play_note(basschannel,FS2,127);
      change_light_level(1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      kill_note(basschannel,FS2,127);
      play_note(basschannel,GS2,127);
      play_note(drumchannel,D1,127);
      change_light_level(2,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      kill_note(basschannel,GS2,127);
      play_note(basschannel,A2,127);
      change_light_level(3,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,D1,127);
      kill_note(basschannel,A2,127);
      play_note(basschannel,B2,127);
      change_light_level(4,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      kill_note(basschannel,B2,127);

      cout << "\nMeasure: " << ++measure;
      play_note(basschannel,CS3,127);
      play_note(synthdrumchannel,C3,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(synthdrumchannel,C3,127);
      play_note(drumchannel,D1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(synthdrumchannel,C3,127);
      if (delay1(speed)) break;

      if (delay1(speed)) break;
      kill_note(synthdrumchannel,C3,127);
      play_note(drumchannel,D1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(synthdrumchannel,C3,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(synthdrumchannel,C3,127);

      play_note(drumchannel,D1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(synthdrumchannel,C3,127);
      if (delay1(speed)) break;
      kill_note(synthdrumchannel,C3,127);
      play_note(drumchannel,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);

      all_lights_off(0);
      play_note(synthdrumchannel,C3,127);
      if (delay1(speed)) break;
      kill_note(synthdrumchannel,C3,127);
      play_note(synthdrumchannel,C3,127);
      if (delay1(speed)) break;
      kill_note(synthdrumchannel,C3,127);
      play_note(synthdrumchannel,B1,127);
      if (delay1(speed)) break;
      kill_note(synthdrumchannel,B1,127);
      play_note(synthdrumchannel,B1,127);
      if (delay1(speed)) break;
      kill_note(synthdrumchannel,B1,127);
      kill_note(basschannel,CS3,127);
      break;
   }

   change_volume(padechochannel,99);
   int times = 0;
   kill_note(16,1,127);
   kill_note(stringchannel,CS5,introbasslevel);
   kill_note(lead2channel,CS5,introbasslevel);

   mix_mode();

   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      if (measure == 21)
      {
         change_light_level(10,127);
      }

      if (measure == 29)
      {
         change_light_level(12,0);
         change_light_level(1,127);
         change_light_level(3,127);
      }

      if (measure == 31)
      {
         change_light_level(1,0);
         change_light_level(3,0);
         change_light_level(2,127);
         change_light_level(4,127);
      }

      if (measure == 33)
      {
         change_light_level(2,0);
         change_light_level(4,0);
         change_light_level(1,127);
         change_light_level(4,127);
      }

      if (measure == 35)
      {
         change_light_level(1,0);
         change_light_level(4,0);
         change_light_level(2,127);
         change_light_level(3,127);
      }

      if (measure == 36)
      {
         change_light_level(2,0);
         change_light_level(3,0);
         change_light_level(1,127);
         change_light_level(2,127);
         change_light_level(3,127);
         change_light_level(4,127);
      }

      //begining of measure

      if (measure == 21)
         play_note(drumchannel,CS2,127);
      play_note(drumchannel,C1,127);
      play_note(basschannel,bassnotes[measure][0],basslevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel,bassnotes[measure][0],basslevel);
      play_note(basschannel,bassnotes[measure][1],basslevel);
      kill_note(drumchannel,C1,127);
      play_note(drumchannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      play_note(drumchannel,AS1,127);
      kill_note(basschannel,bassnotes[measure][1],basslevel);
      play_note(basschannel,bassnotes[measure][2],basslevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      kill_note(basschannel,bassnotes[measure][2],basslevel);
      play_note(basschannel,bassnotes[measure][3],basslevel);
      if (measure == 21)
         kill_note(drumchannel,CS2,127);

      play_note(drumchannel,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      play_note(drumchannel,AS1,127);
      kill_note(basschannel,bassnotes[measure][3],basslevel);
      play_note(basschannel,bassnotes[measure][4],basslevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      play_note(drumchannel,AS1,127);
      kill_note(basschannel,bassnotes[measure][4],basslevel);
      play_note(basschannel,bassnotes[measure][5],basslevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      kill_note(basschannel,bassnotes[measure][5],basslevel);
      play_note(basschannel,bassnotes[measure][6],basslevel);

      if ((measure != 28) && (measure != 36))
      {
      cout << " (" << measure << ")";
      play_note(drumchannel,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,C1,127);
      play_note(drumchannel,AS1,127);
      kill_note(basschannel,bassnotes[measure][6],basslevel);
      play_note(basschannel,bassnotes[measure][7],basslevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      play_note(drumchannel,AS1,127);
      kill_note(basschannel,bassnotes[measure][7],basslevel);
      play_note(basschannel,bassnotes[measure][8],basslevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      kill_note(basschannel,bassnotes[measure][8],basslevel);
      play_note(basschannel,bassnotes[measure][9],basslevel);

      play_note(drumchannel,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      kill_note(basschannel,bassnotes[measure][9],basslevel);
      play_note(basschannel,bassnotes[measure][10],basslevel);
      play_note(drumchannel,AS1,127);

      if (measure == 24)
      {
         change_light_level(12,127);
         change_light_level(10,0);
      }

      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      kill_note(basschannel,bassnotes[measure][10],basslevel);
      play_note(basschannel,bassnotes[measure][11],basslevel);
      play_note(drumchannel,AS1,127);
      if (delay1(speed)) break;
      kill_note(drumchannel,AS1,127);
      kill_note(basschannel,bassnotes[measure][11],basslevel);
      }

      else
      {
         if (times == 1)
         {
            cout << " (" << measure << ")";
            play_note(drumchannel,C1,127);
            play_note(synthdrumchannel,C3,127);
            if (delay1(speed)) break;
            if (delay1(speed)) break;
            kill_note(synthdrumchannel,C3,127);
            play_note(synthdrumchannel,C3,127);
            kill_note(basschannel,bassnotes[measure][6],basslevel);
            play_note(basschannel,bassnotes[measure][7],basslevel);
            kill_note(drumchannel,C1,127);
            play_note(drumchannel,AS1,127);
            if (delay1(speed)) break;
            kill_note(drumchannel,AS1,127);
            play_note(drumchannel,AS1,127);
            kill_note(basschannel,bassnotes[measure][7],basslevel);
            play_note(basschannel,bassnotes[measure][8],basslevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,AS1,127);
            kill_note(synthdrumchannel,C3,127);
            kill_note(basschannel,bassnotes[measure][8],basslevel);
            play_note(basschannel,bassnotes[measure][9],basslevel);
 
            play_note(synthdrumchannel,C3,127);
            play_note(drumchannel,D1,127);
            if (delay1(speed)) break;
            kill_note(synthdrumchannel,C3,127);
            play_note(synthdrumchannel,C3,127);

            if (measure == 36)
            {
               change_light_level(1,0);
               change_light_level(2,0);
               change_light_level(3,0);
               change_light_level(4,0);
            }

            if (delay1(speed)) break;
            kill_note(synthdrumchannel,C3,127);
            play_note(synthdrumchannel,B2,127);
            kill_note(drumchannel,D1,127);
            play_note(drumchannel,AS1,127);
            kill_note(basschannel,bassnotes[measure][9],basslevel);
            play_note(basschannel,bassnotes[measure][10],basslevel);

            if (delay1(speed)) break;
            kill_note(synthdrumchannel,B2,127);
            play_note(synthdrumchannel,B2,127);
            kill_note(drumchannel,AS1,127);
            play_note(drumchannel,AS1,127);
            kill_note(basschannel,bassnotes[measure][10],basslevel);
            play_note(basschannel,bassnotes[measure][11],basslevel);
            if (delay1(speed)) break;
            kill_note(synthdrumchannel,B2,127);
            kill_note(drumchannel,AS1,127);
            kill_note(basschannel,bassnotes[measure][11],basslevel);
            play_note(drumchannel,CS2,127);
         } else
         {
            cout << " (" << measure << ")";
            play_note(drumchannel,C1,127);
            play_note(synthdrumchannel,C3,127);
            if (delay1(speed)) break;
            if (delay1(speed)) break;
            kill_note(synthdrumchannel,C3,127);
            play_note(synthdrumchannel,C3,127);
            kill_note(basschannel,bassnotes[measure][6],basslevel);
            play_note(basschannel,bassnotes[measure][7],basslevel);
            kill_note(drumchannel,C1,127);
            play_note(drumchannel,AS1,127);
            if (delay1(speed)) break;
            kill_note(drumchannel,AS1,127);
            play_note(drumchannel,AS1,127);
            kill_note(basschannel,bassnotes[measure][7],basslevel);
            play_note(basschannel,bassnotes[measure][8],basslevel);
            if (delay1(speed)) break;
            kill_note(drumchannel,AS1,127);
            kill_note(synthdrumchannel,C3,127);
            kill_note(basschannel,bassnotes[measure][8],basslevel);
            play_note(basschannel,bassnotes[measure][9],basslevel);
 
            play_note(synthdrumchannel,C3,127);
            play_note(drumchannel,D1,127);
            if (delay1(speed)) break;
            kill_note(synthdrumchannel,C3,127);
            play_note(synthdrumchannel,C3,127);

            if (measure == 36)
            {
               change_light_level(1,0);
               change_light_level(2,0);
               change_light_level(3,0);
               change_light_level(4,0);
            }

            if (delay1(speed)) break;
            kill_note(synthdrumchannel,C3,127);
            play_note(synthdrumchannel,B2,127);
            kill_note(drumchannel,D1,127);
            play_note(drumchannel,AS1,127);
            kill_note(basschannel,bassnotes[measure][9],basslevel);
            play_note(basschannel,bassnotes[measure][10],basslevel);

            if (delay1(speed)) break;
            kill_note(synthdrumchannel,B2,127);
            play_note(synthdrumchannel,B2,127);
            kill_note(drumchannel,AS1,127);
            play_note(drumchannel,AS1,127);
            kill_note(basschannel,bassnotes[measure][10],basslevel);
            play_note(basschannel,bassnotes[measure][11],basslevel);
            if (delay1(speed)) break;
            kill_note(synthdrumchannel,B2,127);
            kill_note(drumchannel,AS1,127);
            kill_note(basschannel,bassnotes[measure][11],basslevel);
         }
      }

      //end special measure

      if (measure == 36)
      {
         times++;
         if (times == 2)
            break;
         measure = 20;
      }
   }
   return 1;
}

void showinfo()
{
   clrscr();
   cout << "Mega Man 3";
   wait_for_no(INDEX_ESC);
   cout << "\n[1    ]: Intro";
   cout << "\nSPACE LEFT  DOWN SPACE";
   cout << "\nRIGHT SPACE UP SPACE ";
   cout << "\nLEFT RIGHT SPACE UP";
   cout << "\nSPACE DOWN SPACE LEFT";
   cout << "\nESC: Quit";
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
        mix_mode();
        change_effects_channel(1);  //old 3
        mix_name("MegaMan");

        change_program(drumchannel,120,1);
        change_program(synthdrumchannel,118,4);
        change_program(basschannel,45,1);
        change_program(introbasschannel,40,1);
        change_program(stringchannel2,56,1); //

        for (int measure=21;measure<=36;measure++)
           for (int note=0;note<12;note++)
           {
              if ( (measure == 21) || (measure == 22) || (measure == 23)
                                   || (measure == 24))
                 bassnotes[measure][note] = FS2;
              if (measure == 25)
                 bassnotes[measure][note] = A2;
              if (measure == 26)
                 bassnotes[measure][note] = B2;
              if (measure == 27)
                 bassnotes[measure][note] = CS2;
              if (measure == 28)
                 bassnotes[measure][note] = CS2;
              if (measure == 29)
                 bassnotes[measure][note] = A2;
              if (measure == 30)
                 bassnotes[measure][note] = B2;
              if (measure == 31)
                 bassnotes[measure][note] = CS3;
              if (measure == 32)
                 bassnotes[measure][note] = CS3;
              if (measure == 33)
                 bassnotes[measure][note] = A2;
              if (measure == 34)
                 bassnotes[measure][note] = B2;
              if (measure == 35)
                 bassnotes[measure][note] = CS2;
              if (measure == 36)
                 bassnotes[measure][note] = CS2;
           }
/*        bassnotes[33][6] = B2;
        bassnotes[33][7] = B2;
        bassnotes[33][8] = B2;
        bassnotes[33][9] = B2;
        bassnotes[33][10] = B2;
        bassnotes[33][11] = B2;*/
        change_program(1,90,1);
        change_program(lead2channel,91,1);
        change_keyboard_input(lead2channel,1);
        change_program(lead3channel,9,1);
        change_volume(lead3channel,90);
        change_keyboard_input(lead3channel,1);
        change_program(stringchannel,52,2);
        change_program(padechochannel,91,0);
        change_program(guitarchannel,37,2);
        change_program(blahchannel,53,0);


        mix_mode();

        change_program(1,92,0);
        change_program(tinechannel,9,0);
        change_program(lead2channel,91,1);
        change_program(lead3channel,9,1);
        change_program(pianochannel,9,1);
        change_program(samplechannel,124,0);
        change_keyboard_input(lead2channel,1);
        change_keyboard_input(lead3channel,1);
//      change_keyboard_input(padechochannel,1);
        change_volume(lead3channel,90);
        change_keyboard_input(pianochannel,1);
        change_high_note(pianochannel,DS3);
        change_effects_level(3,0);
        change_pitch(pianochannel,1);

        //all_lights_on(50);
        change_light_level(3,127);
        measure = -1;
        while (1)
        {
                delay1(1);
                if (key_table[INDEX_1])
                {
                   change_program(1,9,1);
                   change_program(lead2channel,91,1);
                   change_keyboard_input(lead2channel,0);
                   change_keyboard_input(lead3channel,0);
                   //change_keyboard_input(padechochannel,1);
                   change_volume(padechochannel,0);
                   change_low_note(1,E3);
                   mix_mode();
                   intro();
                   wait_for_no(INDEX_ESC);
                   all_lights_off(0);
                   kill_note(drumchannel,CS2,127);
                   play_note(samplechannel,D5,127);
                   change_light_level(3,127);
                   delay(2500);
                   kill_note(samplechannel,D5,127);
                   showinfo();
                }
                if (key_table[INDEX_ESC]) break;
        }
        wait_for_no(INDEX_ESC);
        change_keyboard_input(lead2channel,0);
        change_keyboard_input(lead3channel,0);
        change_keyboard_input(padechochannel,0);
        change_keyboard_input(pianochannel,0);
        change_volume(lead3channel,99);
        change_pitch(pianochannel,0);
        change_low_note (1,0);
        change_high_note(pianochannel,127);
        kill_note(16,5,127);
        kill_keyboard();
        Exit_MIDI();
    }
