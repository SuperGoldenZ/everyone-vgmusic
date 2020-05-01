//1  2  3  4  5  6  7  8
//F1 F2 F3 F2 F1 F2 F4
//F5 F6  F5 F5 F6  F5 F5

//NEXT
//F1 F7 F4 F2 F1 F2 F4 F8 F4
//F4 + F7
//F4 + F5
//F9 + F6
//F8 + F2
//F9 + F6
//F9 + F2
//F9 + F6

//------------------------------
//0-----------0-----1-----1-----     -1
//1-----3-----1-----2-----1-----     -1
//1-----4-----2-----2-----2-----      1
//2-----4-----2-----4-----4-----      2
//------6-----------------------

//MEASURE 24
//DUM DUM DUM

#define bass_drum 36
#define snare_drum 38
#define high_hat 46
#define panflutechannel 3
#define panup 36

#define guitarchannel 2

#include <keyboard.h>
#include "midi.h"
#include "lights.h"
#include <dos.h>
#include <conio.h>

int drumlevel = 90;

#define drumchannel 10

#define guitarlevel 100

int timpanilevel = 90;
#define timpanichannel 11

int panflutelevel  = 50;

int speed =110;

//B D# G# B
void playchord1(char channel, char velocity)
{
        play_note(channel,47,velocity);
        play_note(channel,51,velocity);
        play_note(channel,56,velocity);
        play_note(channel,59,velocity);
}

void killchord1(char channel, char velocity)
{
        kill_note(channel,47,velocity);
        kill_note(channel,51,velocity);
        kill_note(channel,56,velocity);
        kill_note(channel,59,velocity);
}

//A#4 C#5 F#5 A#5
void playchord2(char channel, char velocity)
{
        play_note(channel,46,velocity);
        play_note(channel,49,velocity);
        play_note(channel,54,velocity);
        play_note(channel,58,velocity);
}

void killchord2(char channel, char velocity)
{
        kill_note(channel,46,velocity);
        kill_note(channel,49,velocity);
        kill_note(channel,54,velocity);
        kill_note(channel,58,velocity);
}

//B4 E5 G#5 B5
void playchord3(char channel, char velocity)
{
        play_note(channel,47,velocity);
        play_note(channel,52,velocity);
        play_note(channel,56,velocity);
        play_note(channel,59,velocity);
}

void killchord3(char channel, char velocity)
{
        kill_note(channel,47,velocity);
        kill_note(channel,52,velocity);
        kill_note(channel,56,velocity);
        kill_note(channel,59,velocity);
}

//G#4 B4 E5 G#5
void playchord4(char channel, char velocity)
{
        play_note(channel,44,velocity);
        play_note(channel,47,velocity);
        play_note(channel,52,velocity);
        play_note(channel,56,velocity);
}

void killchord4(char channel, char velocity)
{
        kill_note(channel,44,velocity);
        kill_note(channel,47,velocity);
        kill_note(channel,52,velocity);
        kill_note(channel,56,velocity);
}

//G#4 B4 D#5 G#5
void playchord5(char channel, char velocity)
{
        play_note(channel,44,velocity);
        play_note(channel,47,velocity);
        play_note(channel,51,velocity);
        play_note(channel,56,velocity);
}

void killchord5(char channel, char velocity)
{
        kill_note(channel,44,velocity);
        kill_note(channel,47,velocity);
        kill_note(channel,51,velocity);
        kill_note(channel,56,velocity);
}

//F#4 A#4 C#5 F#5
void playchord6(char channel, char velocity)
{
        play_note(channel,54-12,velocity);
        play_note(channel,58-12,velocity);
        play_note(channel,61-12,velocity);
        play_note(channel,66-12,velocity);
}

void killchord6(char channel, char velocity)
{
        kill_note(channel,54-12,velocity);
        kill_note(channel,58-12,velocity);
        kill_note(channel,61-12,velocity);
        kill_note(channel,66-12,velocity);
}


//B4 D#5 F#5 B5
void playchord7(char channel, char velocity)
{
        play_note(channel,47,velocity);
        play_note(channel,51,velocity);
        play_note(channel,54,velocity);
        play_note(channel,59,velocity);
}

void killchord7(char channel, char velocity)
{
        kill_note(channel,47,velocity);
        kill_note(channel,51,velocity);
        kill_note(channel,54,velocity);
        kill_note(channel,59,velocity);
}

//G#4 C#5 F5 G#5
void playchord8(char channel, char velocity)
{
        play_note(channel,44,velocity);
        play_note(channel,49,velocity);
        play_note(channel,53,velocity);
        play_note(channel,56,velocity);
}

void killchord8(char channel, char velocity)
{
        kill_note(channel,44,velocity);
        kill_note(channel,49,velocity);
        kill_note(channel,53,velocity);
        kill_note(channel,56,velocity);
}

//E4 G#4 B4 E5
void playchord9(char channel, char velocity)
{
        play_note(channel,52,velocity);
        play_note(channel,56,velocity);
        play_note(channel,59,velocity);
        play_note(channel,64,velocity);

}

void killchord9(char channel, char velocity)
{
        kill_note(channel,52,velocity);
        kill_note(channel,56,velocity);
        kill_note(channel,59,velocity);
        kill_note(channel,64,velocity);
}

void dostuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      playchord1(guitarchannel,guitarlevel);
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      killchord1(guitarchannel,guitarlevel);
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      playchord2(guitarchannel,guitarlevel);
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      killchord2(guitarchannel,guitarlevel);
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      playchord3(guitarchannel,guitarlevel);
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
      killchord3(guitarchannel,guitarlevel);
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
   {
      notes[INDEX_F4]=1;
      playchord4(guitarchannel,guitarlevel);
   }

   if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
   {
      killchord4(guitarchannel,guitarlevel);
      notes[INDEX_F4]=0;
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      playchord5(guitarchannel,guitarlevel);
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      killchord5(guitarchannel,guitarlevel);
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
   {
      notes[INDEX_F6]=1;
      playchord6(guitarchannel,guitarlevel);
   }

   if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
   {
      killchord6(guitarchannel,guitarlevel);
      notes[INDEX_F6]=0;
   }

   if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
   {
      notes[INDEX_F7]=1;
      playchord7(guitarchannel,guitarlevel);
   }

   if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
   {
      killchord7(guitarchannel,guitarlevel);
      notes[INDEX_F7]=0;
   }

   if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
   {
      notes[INDEX_F8]=1;
      playchord8(guitarchannel,guitarlevel);
   }

   if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))
   {
      killchord8(guitarchannel,guitarlevel);
      notes[INDEX_F8]=0;
   }

   if ((notes[INDEX_F9] == 0) && (key_table[INDEX_F9]==1))
   {
      notes[INDEX_F9]=1;
      playchord9(guitarchannel,guitarlevel);
   }

   if ((notes[INDEX_F9] == 1) && (key_table[INDEX_F9]==0))
   {
      killchord9(guitarchannel,guitarlevel);
      notes[INDEX_F9]=0;
   }

}

int delay1(int speed1)
{
        for (int index=0;index<speed1;index++)
        {
                if (key_table[INDEX_ESC]) return 1;
                delay (1);
                dostuff();
        }
        return 0;
}

int go()
{
   clrscr();
   cout << "Here comes Frog!";
   cout << "\nF1 F7 F4 F2 F1 F2 F4 F8 F4";
   cout << "\nF4 + F7";
   cout << "\n//F4 + F5";
   cout << "\n//F9 + F6";
   cout << "\n//F8 + F2";
   cout << "\n//F9 + F6";
   cout << "\n//F9 + F2";
   cout << "\n//F9 + F6";

     int measure = 0;
   change_light_level(1,50);
   change_light_level(2,75);
   change_light_level(3,25);
   change_light_level(4,50);
   
   for (int index=0;index<4;index++)
   {
      play_note(timpanichannel,56,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
   }

   while (1)
   {
      speed = 110;
      //begin!
//      cout << "\nMeasure " << ++measure << " (start)";
      play_note(timpanichannel,56,timpanilevel);
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,49+36,panflutelevel);
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,56,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,49+36,panflutelevel);
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,44+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//      cout << "\nMeasure " << ++measure;
      play_note(timpanichannel,54,timpanilevel);
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,42+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,42+36,panflutelevel);
      play_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,49+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,49+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,44+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      play_note(panflutechannel,44+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      play_note(panflutechannel,42+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,42+36,panflutelevel);
      kill_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//      cout << "\nMeasure " << ++measure;
      play_note(timpanichannel,52,timpanilevel);
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,49+36,panflutelevel);
      kill_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,52,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,49+36,panflutelevel);
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,44+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      kill_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//      cout << "\nMeasure " << ++measure;
      play_note(timpanichannel,54,timpanilevel);
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,42+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,42+36,panflutelevel);
      play_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,49+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,49+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,44+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      play_note(panflutechannel,44+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      play_note(panflutechannel,42+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,42+36,panflutelevel);
      kill_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//      cout << "\nMeasure " << ++measure;
      play_note(timpanichannel,56,timpanilevel);
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,49+36,panflutelevel);
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,56,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,49+36,panflutelevel);
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,44+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//      cout << "\nMeasure " << ++measure;
      play_note(timpanichannel,54,timpanilevel);
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,42+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,42+36,panflutelevel);
      play_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,49+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,49+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,44+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      play_note(panflutechannel,44+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      play_note(panflutechannel,42+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,42+36,panflutelevel);
      kill_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//      cout << "\nMeasure " << ++measure;
      play_note(timpanichannel,52,timpanilevel);
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,49+36,panflutelevel);
      kill_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,52,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,49+36,panflutelevel);
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,47+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      play_note(panflutechannel,44+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      play_note(panflutechannel,46+36,panflutelevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,46+36,panflutelevel);
      if (delay1(speed)) break;
      play_note(panflutechannel,47+36,panflutelevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,47+36,panflutelevel);
      kill_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//      cout << "\nMeasure " << ++measure;
      play_note(timpanichannel,56,timpanilevel);
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(panflutechannel,44+36,panflutelevel);
      play_note(panflutechannel,42+36,panflutelevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(panflutechannel,42+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,42,timpanilevel);
      play_note(timpanichannel,44,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,56,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44+36,panflutelevel);
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,54,timpanilevel);
      play_note(panflutechannel,42+36,panflutelevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(panflutechannel,42+36,panflutelevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,56,timpanilevel);
      play_note(panflutechannel,44+36,panflutelevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(panflutechannel,44+36,panflutelevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,56,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      play_note(drumchannel,49,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      play_note(drumchannel,49,drumlevel); //end!!

//START FAST G#2 44
 //   speed = 100;
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,56,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//B2
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,59,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,59,timpanilevel);
      play_note(timpanichannel,59,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,59,timpanilevel);
      play_note(timpanichannel,59,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,59,timpanilevel);
      play_note(timpanichannel,59,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,59,timpanilevel);
      play_note(timpanichannel,59,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,59,timpanilevel);
      play_note(timpanichannel,59,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,59,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//E2
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,52,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//F#2 
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//G#2 44

//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,56,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//F#2
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//E2
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,52,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//F2   16
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,53,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,53,timpanilevel);
      play_note(timpanichannel,53,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,53,timpanilevel);
      play_note(timpanichannel,53,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,53,timpanilevel);
      play_note(timpanichannel,53,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,53,timpanilevel);
      play_note(timpanichannel,53,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
//      play_note(panflutechannel,77-24,panflutelevel);
      if (delay1(speed)) break;
//      kill_note(panflutechannel,77-24,panflutelevel);
//      play_note(panflutechannel,80-24,panflutelevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
//      kill_note(panflutechannel,80-24,panflutelevel);
//      play_note(panflutechannel,83-24,panflutelevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,53,timpanilevel);
      play_note(timpanichannel,53,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
//      kill_note(panflutechannel,83-24,panflutelevel);
//      play_note(panflutechannel,92-24,panflutelevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
//      kill_note(panflutechannel,92-24,panflutelevel);
      kill_note(timpanichannel,53,timpanilevel);
      kill_note(drumchannel,38,drumlevel);

//E2 NEXT
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,52,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,59,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,59,timpanilevel);
      play_note(timpanichannel,59,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,59,timpanilevel);

//E2 NEXT
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,52,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,56,timpanilevel);
 
//E2 NEXT
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,52,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);

//F2 F#2 FOUR WHOLE
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,53,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,53,timpanilevel);
      play_note(timpanichannel,53,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,53,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);

//E2 F#2
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,52,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);

//E2 G#2
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,52,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,56,timpanilevel);

//E2 F#2
//      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,52,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);

      //REAL LAST ONE
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,52,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,52,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,52,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,54,timpanilevel);

//      cout << "\nMeasure " << ++measure << " (last one)";
/*
      play_note(timpanichannel,56,timpanilevel);
      play_note(drumchannel,49,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,44,panflutelevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,49,drumlevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(panflutechannel,44,panflutelevel);
      play_note(panflutechannel,42,panflutelevel);
      play_note(drumchannel,38,drumlevel);
      kill_note(timpanichannel,56,timpanilevel);
      play_note(timpanichannel,54,timpanilevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,38,drumlevel);
      kill_note(panflutechannel,42,panflutelevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,42,timpanilevel);
      play_note(timpanichannel,44,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,44,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44,panflutelevel);
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,56,timpanilevel);
      play_note(drumchannel,38,drumlevel);
      play_note(panflutechannel,44,panflutelevel);
      if (delay1(speed)) break;
      kill_note(panflutechannel,44,panflutelevel);
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,54,timpanilevel);
      play_note(panflutechannel,42,panflutelevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,54,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(panflutechannel,42,panflutelevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,56,timpanilevel);
      play_note(panflutechannel,44,panflutelevel);
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      kill_note(panflutechannel,44,panflutelevel);
      play_note(drumchannel,38,drumlevel);
      play_note(timpanichannel,56,timpanilevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(timpanichannel,56,timpanilevel);
      kill_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      play_note(drumchannel,49,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      play_note(drumchannel,49,drumlevel);*/
   }
   wait_for_no(INDEX_ESC);
   clrscr();
   cout << "1: Frog de Rhapsody";
   cout << "\nESC: Quit";
   return 1;
}

void testloop()
{
   int measure = 0;
   speed = 90;
   while (1)
   {
      cout << "\nMeasure " << ++measure;
      play_note(drumchannel,bass_drum,drumlevel);
      play_note(drumchannel,high_hat,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,high_hat,drumlevel);
      play_note(drumchannel,high_hat,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,high_hat,drumlevel);
      play_note(drumchannel,high_hat,drumlevel);
      kill_note(drumchannel,bass_drum,drumlevel);
      play_note(drumchannel,snare_drum,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,high_hat,drumlevel);
      play_note(drumchannel,high_hat,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,high_hat,drumlevel);
      play_note(drumchannel,high_hat,drumlevel);
      kill_note(drumchannel,snare_drum,drumlevel);
      play_note(drumchannel,36,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,high_hat,drumlevel);
      play_note(drumchannel,high_hat,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,high_hat,drumlevel);
      play_note(drumchannel,high_hat,drumlevel);
      play_note(drumchannel,38,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,high_hat,drumlevel);
      play_note(drumchannel,high_hat,drumlevel);
      if (delay1(speed)) break;
      if (delay1(speed)) break;
      kill_note(drumchannel,high_hat,drumlevel);
      kill_note(drumchannel,38,drumlevel);
   }
wait_for_no(INDEX_ESC);
}

void main()
{
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        change_program(1,36,3);
        change_program(drumchannel,120,1);
//      change_program(guitarchannel,30,4);
        change_program(guitarchannel,53,1);
        change_effects_level(drumchannel,0);
        change_effects_level(timpanichannel,0);
//TIMPANI!
        change_program(timpanichannel,126,2);
//        change_program(panflutechannel,36,3);
        change_program(panflutechannel,70,1);
        change_program(1,105,1);
        int index;
        for (index=0;index<127;index++)
          notes[index]=0;
        clrscr();
        cout << "1: Frog de Rhapsody";
        cout << "\nT: Test Loop";
        cout << "\nESC: Quit";
        all_lights_off(0);
        change_light_level(3,127);

        while (1)
        {
                delay1(1);
                if (key_table[INDEX_1]) go();
                if (key_table[INDEX_T]) testloop();
                if (key_table[INDEX_ESC]) break;
        }
        all_lights_off(0);
        change_light_level(3,127);
        kill_keyboard();
        Exit_MIDI();
    }
