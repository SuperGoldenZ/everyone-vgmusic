#include <dos.h>
#include <conio.h>
#include "keyboard.h"
#include "midi.h"
#include "lights.h"

#define drumlevel 127
#define drumchannel 10
#define basslevel 127
#define basschannel 2

#define chordchannel 3
#define chordlevel 100

#define chirpchannel 4
#define chirplevel 127

int speed = 80;
//old 90
//old 110
int measure = 0;

void playchordb1(char channel, char velocity)
{
        play_note(channel,71,velocity);
        play_note(channel,67,velocity);
        play_note(channel,62,velocity);
}

void killchordb1(char channel, char velocity)
{
        kill_note(channel,71,velocity);
        kill_note(channel,67,velocity);
        kill_note(channel,62,velocity);
}

void playchordb2(char channel, char velocity)
{
        play_note(channel,73,velocity);
        play_note(channel,69,velocity);
        play_note(channel,64,velocity);
}

void killchordb2(char channel, char velocity)
{
        kill_note(channel,73,velocity);
        kill_note(channel,69,velocity);
        kill_note(channel,64,velocity);
}

void playchordb3(char channel, char velocity)
{
        play_note(channel,74,velocity);
        play_note(channel,67,velocity);
        play_note(channel,62,velocity);
}

void killchordb3(char channel, char velocity)
{
        kill_note(channel,74,velocity);
        kill_note(channel,67,velocity);
        kill_note(channel,62,velocity);
}

void playchordb4(char channel, char velocity)
{
        play_note(channel,73,velocity);
        play_note(channel,70,velocity);
        play_note(channel,66,velocity);
}

void killchordb4(char channel, char velocity)
{
        kill_note(channel,73,velocity);
        kill_note(channel,70,velocity);
        kill_note(channel,66,velocity);
}

void playchord1(char channel, char velocity)
{
        play_note(channel,81,velocity);
        play_note(channel,76,velocity);
        play_note(channel,74,velocity);
}

void killchord1(char channel, char velocity)
{
        kill_note(channel,81,velocity);
        kill_note(channel,76,velocity);
        kill_note(channel,74,velocity);
}

void playchord2(char channel, char velocity)
{
        play_note(channel,81,velocity);
        play_note(channel,79,velocity);
        play_note(channel,76,velocity);
}

void killchord2(char channel, char velocity)
{
        kill_note(channel,81,velocity);
        kill_note(channel,79,velocity);
        kill_note(channel,76,velocity);
}

void playchord3(char channel, char velocity)
{
        play_note(channel,84,velocity);
        play_note(channel,81,velocity);
        play_note(channel,76,velocity);
}

void killchord3(char channel, char velocity)
{
        kill_note(channel,84,velocity);
        kill_note(channel,81,velocity);
        kill_note(channel,76,velocity);
}

void playchord4(char channel, char velocity)
{
        play_note(channel,86,velocity);
        play_note(channel,83,velocity);
        play_note(channel,79,velocity);
}

void killchord4(char channel, char velocity)
{
        kill_note(channel,86,velocity);
        kill_note(channel,83,velocity);
        kill_note(channel,79,velocity);
}

void playchord5(char channel, char velocity)
{
        play_note(channel,F5,velocity);
        play_note(channel,D5,velocity);
        play_note(channel,AS4,velocity);
}

void killchord5(char channel, char velocity)
{
        kill_note(channel,F5,velocity);
        kill_note(channel,D5,velocity);
        kill_note(channel,AS4,velocity);
}

void playchord6(char channel, char velocity)
{
        play_note(channel,A5,velocity);
        play_note(channel,E5,velocity);
        play_note(channel,C5,velocity);
}

void killchord6(char channel, char velocity)
{
        kill_note(channel,A5,velocity);
        kill_note(channel,E5,velocity);
        kill_note(channel,C5,velocity);
}

void playchord7(char channel, char velocity)
{
        play_note(channel,A5,velocity);
        play_note(channel,G5,velocity);
        play_note(channel,D5,velocity);
}

void killchord7(char channel, char velocity)
{
        kill_note(channel,A5,velocity);
        kill_note(channel,G5,velocity);
        kill_note(channel,D5,velocity);
}

void playchord8(char channel, char velocity)
{
        play_note(channel,C6,velocity);
        play_note(channel,G5,velocity);
        play_note(channel,E5,velocity);
}

void killchord8(char channel, char velocity)
{
        kill_note(channel,C6,velocity);
        kill_note(channel,G5,velocity);
        kill_note(channel,E5,velocity);
}

void playchirp1(char channel, char velocity)
{
        play_note(channel,93,velocity);
        play_note(channel,86,velocity);
        play_note(channel,77,velocity);
}

void killchirp1(char channel, char velocity)
{
        kill_note(channel,93,velocity);
        kill_note(channel,86,velocity);
        kill_note(channel,77,velocity);
}

void playchirp2(char channel, char velocity)
{
        play_note(channel,95,velocity);
        play_note(channel,88,velocity);
        play_note(channel,79,velocity);
}

void killchirp2(char channel, char velocity)
{
        kill_note(channel,95,velocity);
        kill_note(channel,88,velocity);
        kill_note(channel,79,velocity);
}

void playchirp3(char channel, char velocity)
{
        play_note(channel,96,velocity);
        play_note(channel,89,velocity);
        play_note(channel,81,velocity);
}

void killchirp3(char channel, char velocity)
{
        kill_note(channel,96,velocity);
        kill_note(channel,89,velocity);
        kill_note(channel,81,velocity);
}
void playchirp4(char channel, char velocity)
{
        play_note(channel,96,velocity);
        play_note(channel,91,velocity);
        play_note(channel,86,velocity);
}

void killchirp4(char channel, char velocity)
{
        kill_note(channel,96,velocity);
        kill_note(channel,91,velocity);
        kill_note(channel,86,velocity);
}

char delay1(int speed)
{
        int index;
        for (index=0;index<speed;index++)
        {
                delay(1);
                if (key_table[INDEX_ESC]) return 1;

                      if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
                        {
                                notes[INDEX_F1]=1;
                                playchord1(chordchannel,chordlevel);
                        }

                        if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
                        {
                                notes[INDEX_F2]=1;
                                playchord2(chordchannel,chordlevel);
                        }

                        if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
                        {
                                notes[INDEX_F3]=1;
                                playchord3(chordchannel,chordlevel);
                        }

                        if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
                        {
                          notes[INDEX_F4]=1;
                          playchord4(chordchannel,chordlevel);
                        }

        if ((notes[INDEX_11] == 0) && (key_table[INDEX_11]==1))
        {
          notes[INDEX_11]=1;
          playchirp1(chirpchannel,chirplevel);
        }

        if ((notes[INDEX_21] == 0) && (key_table[INDEX_21]==1))
        {
          notes[INDEX_21]=1;
          playchirp2(chirpchannel,chirplevel);
        }

        if ((notes[INDEX_31] == 0) && (key_table[INDEX_31]==1))
        {
          notes[INDEX_31]=1;
          playchirp3(chirpchannel,chirplevel);
        }

        if ((notes[INDEX_41] == 0) && (key_table[INDEX_41]==1))
        {
          notes[INDEX_41]=1;
          playchirp4(chirpchannel,chirplevel);
        }

        if ((notes[INDEX_11] == 1) && (key_table[INDEX_11]==0))
        {
          notes[INDEX_11]=0;
          killchirp1(chirpchannel,chirplevel);
        }

        if ((notes[INDEX_21] == 1) && (key_table[INDEX_21]==0))
        {
          notes[INDEX_21]=0;
          killchirp2(chirpchannel,chirplevel);
        }

        if ((notes[INDEX_31] == 1) && (key_table[INDEX_31]==0))
        {
          notes[INDEX_31]=0;
          killchirp3(chirpchannel,chirplevel);
        }

        if ((notes[INDEX_41] == 1) && (key_table[INDEX_41]==0))
        {
          notes[INDEX_41]=0;
          killchirp4(chirpchannel,chirplevel);
        }

        if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))
        {
          notes[INDEX_Q]=0;
          killchordb1(chirpchannel,chirplevel-45);
        }

        if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
        {
          notes[INDEX_Q]=1;
          playchordb1(chirpchannel,chirplevel-45);
        }

        if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))
        {
          notes[INDEX_W]=0;
          killchordb2(chirpchannel,chirplevel-45);
        }

        if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
        {
          notes[INDEX_W]=1;
          playchordb2(chirpchannel,chirplevel-45);
        }

        if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))
        {
          notes[INDEX_E]=0;
          killchordb3(chirpchannel,chirplevel-45);
        }

        if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
        {
          notes[INDEX_E]=1;
          playchordb3(chirpchannel,chirplevel-45);
        }

        if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))
        {
          notes[INDEX_R]=0;
          killchordb4(chirpchannel,chirplevel-45);
        }

        if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
        {
          notes[INDEX_R]=1;
          playchordb4(chirpchannel,chirplevel-45);
        }

        if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
        {
          notes[INDEX_F5]=1;
          playchord5(chordchannel,chordlevel);
        }

        if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
        {
          notes[INDEX_F6]=1;
          playchord6(chordchannel,chordlevel);
        }

        if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
        {
          notes[INDEX_F7]=1;
          playchord7(chordchannel,chordlevel);
        }

        if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
        {
          notes[INDEX_F8]=1;
          playchord8(chordchannel,chordlevel);
        }

                        if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
                        {
                                killchord1(chordchannel,chordlevel);
                                notes[INDEX_F1]=0;
                        }

                        if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
                        {
                                killchord2(chordchannel,chordlevel);
                                notes[INDEX_F2]=0;
                        }

                        if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
                        {
                                killchord3(chordchannel,chordlevel);
                                notes[INDEX_F3]=0;
                        }

        if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
        {
          killchord4(chordchannel,chordlevel);
          notes[INDEX_F4]=0;
        }

        if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
        {
          killchord5(chordchannel,chordlevel);
          notes[INDEX_F5]=0;
        }

        if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))
        {
          killchord8(chordchannel,127);
          notes[INDEX_F8]=0;
        }

        if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
        {
          killchord6(chordchannel,chordlevel);
          notes[INDEX_F6]=0;
        }

        if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
        {
          killchord7(chordchannel,chordlevel);
          notes[INDEX_F7]=0;
        }

        }
        return 0;
}

void go()
{
   clrscr();
   cout << "Double Dragon: ";
   int count = 0;
   measure = 0;
   speed =80;

   play_note(drumchannel,D1,drumlevel);
   delay(speed);
   kill_note(drumchannel,D1,drumlevel);
   play_note(drumchannel,D1,drumlevel);
   delay(speed);
   kill_note(drumchannel,D1,drumlevel);
   play_note(drumchannel,D1,drumlevel);
   delay(speed);
   kill_note(drumchannel,D1,drumlevel);
   delay(speed);

   play_note(drumchannel,D1,drumlevel);
   delay(speed);
   kill_note(drumchannel,D1,drumlevel);
   play_note(drumchannel,D1,drumlevel);
   delay(speed);
   kill_note(drumchannel,D1,drumlevel);
   play_note(drumchannel,D1,drumlevel);
   delay(speed);
   kill_note(drumchannel,D1,drumlevel);
   delay(speed);

   play_note(drumchannel,D1,drumlevel);
   delay(speed);
   kill_note(drumchannel,D1,drumlevel);
   play_note(drumchannel,D1,drumlevel);
   delay(speed);
   kill_note(drumchannel,D1,drumlevel);
   play_note(drumchannel,D1,drumlevel);
   delay(speed);
   kill_note(drumchannel,D1,drumlevel);

   change_light_level(1,50);
   change_light_level(2,75);
   change_light_level(3,25);
   change_light_level(4,50);

while (1)
{

   while (1)
   {

   speed = 80;
   measure = 0;
   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,C1,127);
      play_note(basschannel,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,C1,127);
      kill_note(basschannel,G1,127);

      play_note(basschannel,G1,127);
      play_note(drumchannel,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      kill_note(basschannel,G1,127);

      play_note(basschannel,G1,127);
      play_note(drumchannel,C1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (measure % 2)
      {
         kill_note(drumchannel,C1,127);
         play_note(drumchannel,C1,127);
      }
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,C1,127);
      kill_note(basschannel,G1,127);

      play_note(basschannel,G1,127);
      play_note(drumchannel,D1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(basschannel,G1,127);

      play_note(basschannel,G1,127);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,127);
      kill_note(basschannel,G1,127);
      if (measure == 6)
         break;
   }

cout << "\nFinishing up...";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,AS1,basslevel);  //old got rid of bass
                play_note(basschannel,AS1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,AS1,basslevel);
                play_note(basschannel,AS1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,AS1,basslevel);
                play_note(basschannel,AS1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,AS1,basslevel);
                play_note(basschannel,AS1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,AS1,basslevel);
                play_note(basschannel,AS1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,AS1,basslevel);
                play_note(basschannel,AS1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,AS1,basslevel);
                play_note(basschannel,AS1,basslevel);

                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,AS1,basslevel);
                play_note(basschannel,AS1,basslevel);

                cout << "\nBANG!";
                play_note(drumchannel,CS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(basschannel,A1,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,CS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                if (delay1(speed)) break;

                cout << " BANG!";
                play_note(drumchannel,CS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(basschannel,A1,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,CS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                if (delay1(speed)) break;

                cout << " BANG!";
                play_note(drumchannel,CS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(basschannel,A1,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,CS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                if (delay1(speed)) break;

                cout << " BANG!";
                play_note(drumchannel,CS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(basschannel,A1,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,CS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                cout << "1";
                if (delay1(speed)) break;
                cout << "2";
                if (delay1(speed)) break;
                cout << "3";
                if (delay1(speed)) break;
                cout << "4";
                if (delay1(speed)) break;
                cout << "5";
                if (delay1(speed)) break;
                cout << " GO!";
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                cout << " GO!";
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                cout << " GO!";
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                break;
}

speed = 85;
//i'm not afraid

cout << "\n\n1";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,50,basslevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,50,basslevel);

cout << "\n2";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,48,basslevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,48,basslevel);


cout << "\n3";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,F1,basslevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,C2,basslevel);

cout << "\n4";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,G1,basslevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                play_note(drumchannel,A1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,A1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1+1,basslevel);

cout << "\n5";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1,basslevel);

cout << "\n6";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,G2,basslevel);

cout << "\n7";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,G2,basslevel);

cout << "\n8";
                play_note(basschannel,G1,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,B1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,B1,drumlevel);
                play_note(drumchannel,B1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,B1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,G1,basslevel);
                play_note(drumchannel,A1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,A1,drumlevel);
                if (delay1(speed)) break;
                play_note(drumchannel,CS2,drumlevel);
                play_note(drumchannel,G1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,CS2,drumlevel);
                kill_note(drumchannel,G1,drumlevel);
                cout << "1 ";
                if (delay1(speed)) break;
                cout << "2 ";
                if (delay1(speed)) break;
                cout << "3 ";
                if (delay1(speed)) break;
                cout << "4 ";
                if (delay1(speed)) break;
                cout << "5 ";
                if (delay1(speed)) break;
                cout << "\nGO!";
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);

cout << "\n\n1 (second time)";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,50,basslevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,50,basslevel);

cout << "\n2";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,48,basslevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,48,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,48,basslevel);


cout << "\n3";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,F1,basslevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,F1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,F1,basslevel);
                play_note(basschannel,C2,basslevel);

cout << "\n4";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,G1,basslevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,G1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                play_note(drumchannel,A1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,A1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1+1,basslevel);

cout << "\n5";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1+1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,A1+1,basslevel);
                play_note(basschannel,A1,basslevel);

cout << "\n6";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,A1,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,A1,basslevel);
                play_note(basschannel,G2,basslevel);

cout << "\n7";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,G2,basslevel);

cout << "\n8";

                play_note(drumchannel,DS2,drumlevel);
                play_note(basschannel,C2,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,C2,basslevel);

                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,CS2,drumlevel);        
                play_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,CS2,drumlevel);        
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,C2,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,CS2,drumlevel);        
                play_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,CS2,drumlevel);        
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,DS2,drumlevel);
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,C2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,C2,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,CS2,drumlevel);        
                play_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,CS2,drumlevel);        
                kill_note(drumchannel,D1,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,C2,basslevel);
                play_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                play_note(drumchannel,A1,drumlevel);
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,C2,basslevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,A1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,DS2,drumlevel);

                if (delay1(speed)) break;
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,C2,basslevel);
                kill_note(drumchannel,D1,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,G1,drumlevel);

                if (delay1(speed)) break;
                kill_note(drumchannel,G1,drumlevel);

                play_note(drumchannel,DS2,drumlevel);    
                play_note(drumchannel,F1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,C2,basslevel);

                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,F1,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,CS2,drumlevel);    
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,CS2,drumlevel);    
                kill_note(drumchannel,D1,drumlevel);
                kill_note(basschannel,C2,basslevel);

cout << "\n\ninterlude";
cout << "\n1";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,50,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,F3,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,53,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53,basslevel);
cout << "\n2";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,53,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53,basslevel);
                play_note(basschannel,53,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53,basslevel);
                play_note(basschannel,53,basslevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,65,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,65,basslevel);
                play_note(basschannel,64,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,64,basslevel);
                play_note(basschannel,62,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,62,basslevel);
                play_note(basschannel,60,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,60,basslevel);
                kill_note(drumchannel,D1,drumlevel);

cout << "\n3";

                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,50,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,53,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53,basslevel);

cout << "\n4";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,53,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53,basslevel);
                play_note(basschannel,53,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53,basslevel);
                play_note(basschannel,47,basslevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,47,basslevel);
                play_note(basschannel,59,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,59,basslevel);
                play_note(basschannel,48,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,60,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,60,basslevel);
                play_note(basschannel,49,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,49,basslevel);
                play_note(basschannel,61,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,61,basslevel);
                kill_note(drumchannel,D1,drumlevel);

cout << "\n5";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,50,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,50,basslevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,50,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,53,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53,basslevel);

cout << "\n6";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,53,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53,basslevel);
                play_note(basschannel,53,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53,basslevel);
                play_note(basschannel,53,basslevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53,basslevel);
                play_note(basschannel,53+12,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,53+12,basslevel);
                play_note(basschannel,52,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,52,basslevel);
                play_note(basschannel,62,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,62,basslevel);
                play_note(basschannel,48,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,48,basslevel);
                play_note(basschannel,60,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,60,basslevel);
                kill_note(drumchannel,D1,drumlevel);

cout << "\n7";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(basschannel,55,basslevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,F3,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);

cout << "\n8";
                play_note(drumchannel,DS2,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,DS2,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,F2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,F2,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                play_note(basschannel,55,basslevel);
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,F2,drumlevel);
                if (delay1(speed)) break;
                kill_note(drumchannel,D1,drumlevel);
                kill_note(drumchannel,F2,drumlevel);
                if (delay1(speed)) break;
                kill_note(basschannel,55,basslevel);
                if (count++ == 1) break;
        }
        play_note(drumchannel,49,drumlevel);
        delay1(speed);
        kill_note(drumchannel,49,drumlevel);
        clrscr();
        cout << "Double Dragon Theme";
        cout << "\n1: Start!";
        cout << "\nESC: Quit";
        wait_for_no(INDEX_ESC);
}

void main()
{
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        change_program(drumchannel,120,1);
        change_program(basschannel,41,2);
        change_program(chordchannel,92,3);
        change_program(chirpchannel,22,3);
        change_program(1,90,1);
        change_volume(1,99);
        change_volume(basschannel,99);
        change_volume(chordchannel,99);
        change_volume(chirpchannel,90);
        change_volume(drumchannel,99);
        change_effects_level(drumchannel,0);
        mix_mode();
        clrscr();
        cout << "Double Dragon Theme";
        cout << "\n1: Start!";
        cout << "\nESC: Quit";

        while (1)
        {
                delay1(1);
                if (key_table[INDEX_1])
                {
                   go();
                   all_lights_off(0);
                   change_light_level(3,127);
                }
                if (key_table[INDEX_ESC]) break;
        }
                kill_keyboard();
                Exit_MIDI();
    }
