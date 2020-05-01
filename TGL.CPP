#include <dos.h>
#include <conio.h>
#include "keyboard.h"
#include "midi.h"
#include "lights.h"

#define drumlevel 127
#define drumchannel 10

#define samplechannel 11
#define samplelevel 127

#define chordchannel 2

#define fxchannel 2
#define fxlevel 127

#define brasschannel 3
int brasslevel = 127;

#define basschannel 5
int basslevel = 75;

#define scc 4
#define chordlevel 75

//old 100
int speed = 110;   //old 100
int bassnotes[16];
int walkbassnotes[32][8];
int firstflightbassnotes[50][8];
int area0bassnotes[10][16];
int computerroombassnotes[15][8];
int apeshit = 0;

void area0();

void playchord1(char channel, char velocity)
{
        play_note(channel,GS5,velocity);
}

void killchord1(char channel, char velocity)
{
        kill_note(channel,GS5,velocity);
}

void playchord2(char channel, char velocity)
{
        play_note(channel,GS4,velocity);
}

void killchord2(char channel, char velocity)
{
        kill_note(channel,GS4,velocity);
}

int go();

void playchord3(char channel, char velocity)
{
        play_note(channel,FS5,velocity);
}

void killchord3(char channel, char velocity)
{
        kill_note(channel,FS5,velocity);
}

void playchord4(char channel, char velocity)
{
        play_note(channel,DS5,velocity);
}

void killchord4(char channel, char velocity)
{
        kill_note(channel,DS5,velocity);
}

void playchord5(char channel, char velocity)
{
        play_note(channel,CS2,velocity);
}

void killchord5(char channel, char velocity)
{
        kill_note(channel,CS2,velocity);
}

void playchord6(char channel, char velocity)
{
        play_note(channel,B1,velocity);
}

void killchord6(char channel, char velocity)
{
        kill_note(channel,B1,velocity);
}

void playchord7(char channel, char velocity)
{
        play_note(channel,GS2,velocity);
}

void killchord7(char channel, char velocity)
{
        kill_note(channel,GS2,velocity);

}

void playchord8(char channel, char velocity)
{
        play_note(channel,FS2,velocity);
}

void killchord8(char channel, char velocity)
{
        kill_note(channel,FS2,velocity);
}

void dostuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      playchord1(fxchannel,fxlevel);
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      playchord2(fxchannel,fxlevel);
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      playchord3(fxchannel,fxlevel);
   }

   if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
   {
      notes[INDEX_F4]=1;
      playchord4(fxchannel,fxlevel);
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      playchord5(brasschannel,brasslevel);
   }

   if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
   {
      notes[INDEX_F6]=1;
      playchord6(brasschannel,brasslevel);
   }

   if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
   {
      notes[INDEX_F7]=1;
      playchord7(brasschannel,brasslevel);
   }

   if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
   {
      notes[INDEX_F8]=1;
      playchord8(brasschannel,brasslevel);
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      killchord1(fxchannel,fxlevel);
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      killchord2(fxchannel,fxlevel);
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
      killchord3(fxchannel,fxlevel);
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
   {
      killchord4(fxchannel,fxlevel);
      notes[INDEX_F4]=0;
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      killchord5(brasschannel,brasslevel);
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
   {
      killchord6(brasschannel,brasslevel);
      notes[INDEX_F6]=0;
   }

   if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
   {
      killchord7(brasschannel,brasslevel);
      notes[INDEX_F7]=0;
   }

   if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))
   {
      killchord8(brasschannel,brasslevel);
      notes[INDEX_F8]=0;
   }
}

void do_flight_stuff()
{
}

/*void dostuff()
{
   if ((notes[INDEX_11] == 0) && (key_table[INDEX_11]==1))
   {
      notes[INDEX_11]=1;
      playchord1(scc,chordlevel);
   }

   if ((notes[INDEX_11] == 1) && (key_table[INDEX_11]==0))
   {
      killchord1(scc,chordlevel);
      notes[INDEX_11]=0;
   }

   if ((notes[INDEX_21] == 0) && (key_table[INDEX_21]==1))
   {
      notes[INDEX_21]=1;
      playchord2(scc,chordlevel);
   }

   if ((notes[INDEX_21] == 1) && (key_table[INDEX_21]==0))
   {
      killchord2(scc,chordlevel);
      notes[INDEX_21]=0;
   }

   if ((notes[INDEX_31] == 0) && (key_table[INDEX_31]==1))
   {
      notes[INDEX_31]=1;
      playchord3(scc,chordlevel);
   }

   if ((notes[INDEX_31] == 1) && (key_table[INDEX_31]==0))
   {
      killchord3(scc,chordlevel);
      notes[INDEX_31]=0;
   }

} */

void dointrostuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      play_note(samplechannel,C5,127);
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      kill_note(samplechannel,C5,127);
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      play_note(basschannel,D2,127);
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      kill_note(basschannel,D2,127);
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      play_note(basschannel,C2,127);
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
      kill_note(basschannel,C2,127);
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
   {
      notes[INDEX_F4]=1;
      play_note(basschannel,G2,127);
   }

   if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
   {
      kill_note(basschannel,G2,127);
      notes[INDEX_F4]=0;
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      play_note(basschannel,F2,127);
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      kill_note(basschannel,F2,127);
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
   {
      notes[INDEX_F6]=1;
      play_note(basschannel,E2,127);
      apeshit = 1;
   }

   if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
   {
      kill_note(basschannel,E2,127);
      notes[INDEX_F6]=0;
   }

}

void doarea0stuff()
{
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

int delay_flight(int speed)
{
        for (int index=0;index<speed;index++)
        {
                if (key_table[INDEX_ESC]) return 1;
                do_flight_stuff();
                delay (1);
        }
        return 0;
}

int delay_intro(int speed)
{
        for (int index=0;index<speed;index++)
        {
                if (key_table[INDEX_ESC]) return 1;
                dointrostuff();
                delay (1);
        }
        return 0;
}

int delay0(int speed)
{
        for (int index=0;index<speed;index++)
        {
                if (key_table[INDEX_ESC]) return 1;
                doarea0stuff();
                delay (1);
        }
        return 0;
}

int delaycomputerroom(int speed)
{
        for (int index=0;index<speed;index++)
        {
                if (key_table[INDEX_ESC]) return 1;
                doarea0stuff();
                delay (1);
        }
        return 0;
}

void computerroom()
{
   clrscr();
   int measure = 0;
   int count = 0;

   cout << "Computer Room";
   change_program(basschannel,45,1);
   change_program(1,88,4);
   all_lights_off(0);
   if (delaycomputerroom(speed)) return;
   if (delaycomputerroom(speed)) return;
   if (delaycomputerroom(speed)) return;
   if (delaycomputerroom(speed)) return;

   while (1)
   {
      play_note(drumchannel,FS1,127);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      play_note(drumchannel,FS1,127);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      play_note(drumchannel,FS1,127);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      play_note(drumchannel,FS1,127);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      break;
   }

   change_light_level(2,127);
   change_light_level(4,35);
   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      play_note(drumchannel,FS1,127);
      play_note(basschannel,computerroombassnotes[measure][0],basslevel);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      kill_note(basschannel,computerroombassnotes[measure][0],basslevel);
      play_note(drumchannel,FS1,127);
      play_note(basschannel,computerroombassnotes[measure][1],basslevel);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      kill_note(basschannel,computerroombassnotes[measure][1],basslevel);

      play_note(drumchannel,FS1,127);
      play_note(basschannel,computerroombassnotes[measure][2],basslevel);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      kill_note(basschannel,computerroombassnotes[measure][2],basslevel);
      play_note(drumchannel,FS1,127);
      play_note(basschannel,computerroombassnotes[measure][3],basslevel);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      kill_note(basschannel,computerroombassnotes[measure][3],basslevel);

      play_note(drumchannel,FS1,127);
      play_note(basschannel,computerroombassnotes[measure][4],basslevel);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      kill_note(basschannel,computerroombassnotes[measure][4],basslevel);
      play_note(drumchannel,FS1,127);
      play_note(basschannel,computerroombassnotes[measure][5],basslevel);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      kill_note(basschannel,computerroombassnotes[measure][5],basslevel);

      play_note(drumchannel,FS1,127);
      play_note(basschannel,computerroombassnotes[measure][6],basslevel);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      kill_note(basschannel,computerroombassnotes[measure][6],basslevel);
      play_note(drumchannel,FS1,127);
      play_note(basschannel,computerroombassnotes[measure][7],basslevel);
      if (delaycomputerroom(speed)) break;
      if (delaycomputerroom(speed)) break;
      kill_note(drumchannel,FS1,127);
      kill_note(basschannel,computerroombassnotes[measure][7],basslevel);
      if (measure == 14)
      {
         count++;
         measure = 0;
         if (count == 2)
            break;
      }
   }
   all_lights_off(0);
//   area0();
   go();
}

void area0()
{
   clrscr();
   cout << "Area 0";
   int count = 0;
   int measure = 0;
   change_program(basschannel,44,2);
   change_program(1,90,1); //old 107 1
   change_light_level(1,50);
   change_light_level(2,75);
   change_light_level(3,25);
   change_light_level(4,50);
   if (delay0(speed)) return;
   if (delay0(speed)) return;
   if (delay0(speed)) return;
   if (delay0(speed)) return;

   while (1)
   {
      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(drumchannel,C1,127);
      if (delay0(speed)) break;

      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(drumchannel,C1,127);
      play_note(drumchannel,D1,127);
      if (delay0(speed)) break;
      kill_note(drumchannel,D1,127);
      if (delay0(speed)) break;

      break;
   }

   while (1)
   {
      cout << "\nMeasure: " << ++measure;
      play_note(basschannel,area0bassnotes[measure][0],basslevel);
      if (measure == 1) play_note(drumchannel,CS2,127);
      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][0],basslevel);
      play_note(basschannel,area0bassnotes[measure][1],basslevel);
      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][1],basslevel);
      kill_note(drumchannel,C1,127);
      if (measure == 1) kill_note(drumchannel,CS2,127);

      play_note(drumchannel,D1,127);
      play_note(basschannel,area0bassnotes[measure][2],basslevel);
      if (delay0(speed)) break;
      kill_note(drumchannel,D1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][2],basslevel);
      play_note(basschannel,area0bassnotes[measure][3],basslevel);
      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][3],basslevel);
      kill_note(drumchannel,C1,127);

      play_note(basschannel,area0bassnotes[measure][4],basslevel);
      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][4],basslevel);
      play_note(basschannel,area0bassnotes[measure][5],basslevel);
      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][5],basslevel);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      play_note(basschannel,area0bassnotes[measure][6],basslevel);
      if (delay0(speed)) break;
      kill_note(drumchannel,D1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][6],basslevel);
      play_note(basschannel,area0bassnotes[measure][7],basslevel);
      play_note(drumchannel,D1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][7],basslevel);
      kill_note(drumchannel,D1,127);

      play_note(basschannel,area0bassnotes[measure][8],basslevel);
      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][8],basslevel);
      play_note(basschannel,area0bassnotes[measure][9],basslevel);
      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][9],basslevel);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      play_note(basschannel,area0bassnotes[measure][10],basslevel);
      if (delay0(speed)) break;
      kill_note(drumchannel,D1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][10],basslevel);
      play_note(basschannel,area0bassnotes[measure][11],basslevel);
      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][11],basslevel);
      kill_note(drumchannel,C1,127);

      play_note(basschannel,area0bassnotes[measure][12],basslevel);
      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][12],basslevel);
      play_note(basschannel,area0bassnotes[measure][13],basslevel);
      play_note(drumchannel,C1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][13],basslevel);
      kill_note(drumchannel,C1,127);

      play_note(drumchannel,D1,127);
      play_note(basschannel,area0bassnotes[measure][14],basslevel);
      if (delay0(speed)) break;
      kill_note(drumchannel,D1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][14],basslevel);
      play_note(basschannel,area0bassnotes[measure][15],basslevel);
      play_note(drumchannel,D1,127);
      if (delay0(speed)) break;
      kill_note(basschannel,area0bassnotes[measure][15],basslevel);
      kill_note(drumchannel,D1,127);

      if (measure == 9)
      {
         measure = 0;
         count++;
         if (count == 2)
            break;
      }
   }
   go();
}

int space_flight()
{
   clrscr();
   cout << "Flying through space!";
   int index;
   int measure = 0;
   speed = 90;
   change_program(basschannel,48,0);  //48 0
//   basslevel = 0;
   play_note(11,60,127);
   delay1(speed*50);
   for (index=0;index<4;index++)
   {
      play_note(drumchannel,37,drumlevel);
      if (delay1(speed*2)) return 0;
      kill_note(drumchannel,37,drumlevel);
   }
   int c = 0;
   all_lights_off(0);
//   change_volume(basschannel,90);
   while (1)
   {
       c++;
       measure = 0;
       for (index=0;index<3;index++)
       {
          cout << "\nMeasure: " << ++measure;
          play_note(drumchannel,44,127);
          play_note(drumchannel,36,127);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,38,127);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          play_note(drumchannel,42,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,42,127);
       }

          cout << "\nMeasure: " << ++measure;
          play_note(drumchannel,44,127);
          play_note(drumchannel,36,127);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,38,127);
          kill_note(drumchannel,44,127);
          play_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,38,127);
          play_note(drumchannel,38,127);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,38,127);
          play_note(drumchannel,38,127);
          play_note(drumchannel,43,127);
          if (delay1(speed)) break;
          kill_note(drumchannel,38,127);
          kill_note(drumchannel,43,127);

       for (index=0;index<3;index++)
       {
          cout << "\nMeasure: " << ++measure;
          play_note(drumchannel,44,127);
          play_note(drumchannel,36,127);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,38,127);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          play_note(drumchannel,42,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,42,127);
       }

          cout << "\nMeasure: " << ++measure;
          play_note(drumchannel,44,127);
          play_note(drumchannel,36,127);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,36,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(basschannel,bassnotes[measure-1],basslevel);
          play_note(drumchannel,44,127);
          play_note(drumchannel,38,127);
          play_note(drumchannel,57,127); //49
          if (delay1(speed)) return 0;
          kill_note(drumchannel,57,127);
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,38,127);
          kill_note(drumchannel,44,127);
          play_note(drumchannel,38,127);
          if (delay1(speed)) return 0;
          play_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,38,127);
          play_note(drumchannel,38,127);
          play_note(drumchannel,44,127);
          if (delay1(speed)) return 0;
          kill_note(basschannel,bassnotes[measure-1],basslevel);
          kill_note(drumchannel,44,127);
          kill_note(drumchannel,38,127);
          play_note(drumchannel,38,127);
          play_note(drumchannel,43,127);
          if (delay1(speed)) break;
          kill_note(drumchannel,38,127);
          kill_note(drumchannel,43,127);
          if (c == 2)
          {
             change_light_level(1,50);
             change_light_level(2,75);
             change_light_level(3,25);
             change_light_level(4,50);
          }

          if (c == 4) break;
   }
   kill_note(11,62,127);
   all_lights_off(0);
   change_light_level(3,127);

   clrscr();
   cout << "The Guardian Legend - Walk About";
   cout << "\n1: Start!";
   cout << "\n[SPACE]: Fly Through Space!";
   cout << "\nESC: Quit";
   cout << "\nC: " << c;
   wait_for_no(INDEX_ESC);
   return 0;
}


int go()
{
        change_program(1,88,4);
        change_program(fxchannel,100,4);
        change_program(brasschannel,87,4);
        change_program(basschannel,48,0);  //48 0

        clrscr();
        cout << "Walking About!";
        int index;
        int times = 0;
        speed = 95;
        play_note(drumchannel,D1,127);
        cout << "\nReady";
        delay1(speed*4);
        cout << " set";
        play_note(drumchannel,D1,127);
        delay1(speed*4);
        cout << " go!";
        for (index=0;index<1;index++)
        {
           play_note(drumchannel,38,drumlevel);
           if (delay1(speed*4)) return 0;
           kill_note(drumchannel,38,drumlevel);
        }

        for (times=0;times<2;times++)
        {
        for (index=0;index<7;index++)
        {
                brasslevel = 127;
                cout << "\nMeasure " << index + 1 ;
                play_note(drumchannel,C1,drumlevel);

                if (delay1(speed)) return 0;
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) return 0;
                if (delay1(speed)) return 0;
                if (delay1(speed)) return 0;
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) return 0;
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) return 0;
                play_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) return 0;
                kill_note(drumchannel,C1,drumlevel);
                if (delay1(speed)) return 0;
                if (delay1(speed)) return 0;
                if (delay1(speed)) return 0;
                if (delay1(speed)) return 0;
                if (delay1(speed)) return 0;
                play_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) return 0;
                kill_note(drumchannel,D1,drumlevel);
                if (delay1(speed)) return 0;
                if (delay1(speed)) return 0;
                if (delay1(speed)) return 0;
        }
        brasslevel = 100;
cout << "\nMeasure " << ++index;
                play_note(drumchannel,C1,drumlevel);
                play_note(brasschannel,walkbassnotes[8][0],brasslevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[8][0],brasslevel);
                play_note(brasschannel,walkbassnotes[8][1],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[8][1],brasslevel);
                play_note(brasschannel,walkbassnotes[8][2],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[8][2],brasslevel);
                play_note(brasschannel,walkbassnotes[8][3],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[8][3],brasslevel);
                play_note(brasschannel,walkbassnotes[8][4],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[8][4],brasslevel);
                play_note(brasschannel,walkbassnotes[8][5],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[8][5],brasslevel);
                play_note(brasschannel,walkbassnotes[8][6],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[8][6],brasslevel);
                play_note(brasschannel,walkbassnotes[8][7],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[8][7],brasslevel);

                cout << "\nMeasure " << index + 9 ;
                play_note(drumchannel,C1,drumlevel);
                if (index == 0) play_note(drumchannel,A2,drumlevel);
                play_note(brasschannel,walkbassnotes[9][0],brasslevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                if (index == 0) kill_note(drumchannel,A2,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[9][0],brasslevel);
                play_note(brasschannel,walkbassnotes[9][1],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[9][1],brasslevel);
                play_note(brasschannel,walkbassnotes[9][2],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[9][2],brasslevel);
                play_note(brasschannel,walkbassnotes[9][3],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[9][3],brasslevel);
                play_note(brasschannel,walkbassnotes[9][4],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[9][4],brasslevel);
                play_note(brasschannel,walkbassnotes[9][5],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[9][5],brasslevel);
                play_note(brasschannel,walkbassnotes[9][6],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[9][6],brasslevel);
                play_note(brasschannel,walkbassnotes[9][7],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[9][7],brasslevel);

                cout << "\nMeasure " << index + 9 ;
                play_note(drumchannel,C1,drumlevel);
                if (index == 0) play_note(drumchannel,A2,drumlevel);
                play_note(brasschannel,walkbassnotes[10][0],brasslevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                if (index == 0) kill_note(drumchannel,A2,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[10][0],brasslevel);
                play_note(brasschannel,walkbassnotes[10][1],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[10][1],brasslevel);
                play_note(brasschannel,walkbassnotes[10][2],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[10][2],brasslevel);
                play_note(brasschannel,walkbassnotes[10][3],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[10][3],brasslevel);
                play_note(brasschannel,walkbassnotes[10][4],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[10][4],brasslevel);
                play_note(brasschannel,walkbassnotes[10][5],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[10][5],brasslevel);
                play_note(brasschannel,walkbassnotes[10][6],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[10][6],brasslevel);
                play_note(brasschannel,walkbassnotes[10][7],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[10][7],brasslevel);

                cout << "\nMeasure " << index + 9 ;
                play_note(drumchannel,C1,drumlevel);
                if (index == 0) play_note(drumchannel,A2,drumlevel);
                play_note(brasschannel,walkbassnotes[11][0],brasslevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                if (index == 0) kill_note(drumchannel,A2,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[11][0],brasslevel);
                play_note(brasschannel,walkbassnotes[11][1],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[11][1],brasslevel);
                play_note(brasschannel,walkbassnotes[11][2],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[11][2],brasslevel);
                play_note(brasschannel,walkbassnotes[11][3],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[11][3],brasslevel);
                play_note(brasschannel,walkbassnotes[11][4],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[11][4],brasslevel);
                play_note(brasschannel,walkbassnotes[11][5],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[11][5],brasslevel);
                play_note(brasschannel,walkbassnotes[11][6],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[11][6],brasslevel);
                play_note(brasschannel,walkbassnotes[11][7],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[11][7],brasslevel);

                cout << "\nMeasure 12";
                play_note(drumchannel,C1,drumlevel);
                if (index == 0) play_note(drumchannel,A2,drumlevel);
                play_note(brasschannel,walkbassnotes[12][0],brasslevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                if (index == 0) kill_note(drumchannel,A2,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[12][0],brasslevel);
                play_note(brasschannel,walkbassnotes[12][1],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[12][1],brasslevel);
                play_note(brasschannel,walkbassnotes[12][2],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[12][2],brasslevel);
                play_note(brasschannel,walkbassnotes[12][3],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[12][3],brasslevel);
                play_note(brasschannel,walkbassnotes[12][4],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[12][4],brasslevel);
                play_note(brasschannel,walkbassnotes[12][5],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[12][5],brasslevel);
                play_note(brasschannel,walkbassnotes[12][6],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[12][6],brasslevel);
                play_note(brasschannel,walkbassnotes[12][7],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[12][7],brasslevel);

                cout << "\nMeasure 13";
                play_note(drumchannel,C1,drumlevel);
                play_note(brasschannel,walkbassnotes[13][0],brasslevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[13][0],brasslevel);
                play_note(brasschannel,walkbassnotes[13][1],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[13][1],brasslevel);
                play_note(brasschannel,walkbassnotes[13][2],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[13][2],brasslevel);
                play_note(brasschannel,walkbassnotes[13][3],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[13][3],brasslevel);
                play_note(brasschannel,walkbassnotes[13][4],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[13][4],brasslevel);
                play_note(brasschannel,walkbassnotes[13][5],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[13][5],brasslevel);
                play_note(brasschannel,walkbassnotes[13][6],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[13][6],brasslevel);
                play_note(brasschannel,walkbassnotes[13][7],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[13][7],brasslevel);

                cout << "\nMeasure 14";
                play_note(drumchannel,C1,drumlevel);
                play_note(brasschannel,walkbassnotes[14][0],brasslevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[14][0],brasslevel);
                play_note(brasschannel,walkbassnotes[14][1],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[14][1],brasslevel);
                play_note(brasschannel,walkbassnotes[14][2],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[14][2],brasslevel);
                play_note(brasschannel,walkbassnotes[14][3],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[14][3],brasslevel);
                play_note(brasschannel,walkbassnotes[14][4],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[14][4],brasslevel);
                play_note(brasschannel,walkbassnotes[14][5],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[14][5],brasslevel);
                play_note(brasschannel,walkbassnotes[14][6],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[14][6],brasslevel);
                play_note(brasschannel,walkbassnotes[14][7],brasslevel);
                delay1(speed);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[14][7],brasslevel);

        cout << "\nCrazy 1";
                play_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(brasschannel,walkbassnotes[15][0],brasslevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[15][0],brasslevel);
                play_note(brasschannel,walkbassnotes[15][1],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[15][1],brasslevel);
                play_note(brasschannel,walkbassnotes[15][2],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[15][2],brasslevel);
                play_note(brasschannel,walkbassnotes[15][3],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[15][3],brasslevel);
                play_note(brasschannel,walkbassnotes[15][4],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[15][4],brasslevel);
                play_note(brasschannel,walkbassnotes[15][5],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[15][5],brasslevel);
                play_note(brasschannel,walkbassnotes[15][6],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[15][6],brasslevel);
                play_note(brasschannel,walkbassnotes[15][7],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[15][7],brasslevel);

                cout << "\nCrazy 2";
                play_note(drumchannel,C1,drumlevel);
                play_note(brasschannel,walkbassnotes[16][0],brasslevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[16][0],brasslevel);
                play_note(brasschannel,walkbassnotes[16][1],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[16][1],brasslevel);
                play_note(brasschannel,walkbassnotes[16][2],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[16][2],brasslevel);
                play_note(brasschannel,walkbassnotes[16][3],brasslevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[16][3],brasslevel);
                play_note(brasschannel,walkbassnotes[16][4],brasslevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[16][4],brasslevel);
                play_note(brasschannel,walkbassnotes[16][5],brasslevel);
                kill_note(drumchannel,C1,drumlevel);

                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);

                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[16][5],brasslevel);
                play_note(brasschannel,walkbassnotes[16][6],brasslevel);
                kill_note(drumchannel,D1,drumlevel);

                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);

                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(brasschannel,walkbassnotes[16][6],brasslevel);
                play_note(brasschannel,walkbassnotes[16][7],brasslevel);

                kill_note(drumchannel,D1,drumlevel);

                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);

                play_note(drumchannel,D1,drumlevel);
                delay1(speed);
                kill_note(drumchannel,D1,drumlevel);
                kill_note(brasschannel,walkbassnotes[16][7],brasslevel);
                }
//kill_note(11,61,127);
space_flight();
return 1;
}

void first_flight()
{
   clrscr();
   cout << "First flight";
   int index;
   int measure = 18;
//   basslevel = 0;
//   change_program(basschannel,46,0);

   index = 0;
   while (1)
   {
      index++;
      play_note(drumchannel,FS1,127);
      play_note(basschannel,F2,basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,F2,basslevel);

      play_note(basschannel,A2,basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,A2,basslevel);
      kill_note(drumchannel,FS1,127);
      if (index == 4)
         break;
   }

   while (1)
   {

      play_note(basschannel,F2,basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,F2,basslevel);

      play_note(basschannel,A2,basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,A2,basslevel);
      break;
   }

   while (1)
   {
      cout << "\nMeasure: "<< ++measure;
      play_note(basschannel,firstflightbassnotes[measure][0],basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,firstflightbassnotes[measure][0],basslevel);
      play_note(basschannel,firstflightbassnotes[measure][1],basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,firstflightbassnotes[measure][1],basslevel);

      play_note(drumchannel,D1,127);
      play_note(basschannel,firstflightbassnotes[measure][2],basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,firstflightbassnotes[measure][2],basslevel);
      play_note(basschannel,firstflightbassnotes[measure][3],basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,firstflightbassnotes[measure][3],basslevel);
      kill_note(drumchannel,D1,127);

      play_note(basschannel,firstflightbassnotes[measure][4],basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,firstflightbassnotes[measure][4],basslevel);
      play_note(basschannel,firstflightbassnotes[measure][5],basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,firstflightbassnotes[measure][5],basslevel);

      play_note(drumchannel,D1,127);
      play_note(basschannel,firstflightbassnotes[measure][6],basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,firstflightbassnotes[measure][6],basslevel);
      play_note(basschannel,firstflightbassnotes[measure][7],basslevel);
      if (delay_flight(speed)) break;
      if (delay_flight(speed)) break;
      kill_note(basschannel,firstflightbassnotes[measure][7],basslevel);
      kill_note(drumchannel,D1,127);
      if (measure == 46)
         break;
   }
   computerroom();
}


void intro()
{
   clrscr();
   wait_for_no(INDEX_F1);
   change_program(1,105,1);
   change_program(basschannel,45,1);
   cout << "Intro!";
   cout << "\nF2  F3 F4  F5";
   cout << "\nF2 (F3+F1) F2 F5";
   cout << "\nF2 F6";
   cout << "\n\nF1: Blast Off!";
   cout << "\nESC: Quit";
   while (1)
   {
      if (key_table[INDEX_F12])
      {
         break;
      }
      if (apeshit)
         break;
      if (delay_intro(1)) break;
   }
   basslevel = 0;
   cout << "\nAuto Bass... Hold SPACE to continue";
   while (1)
   {
      play_note(basschannel,F2,basslevel);
      if (delay_intro(speed)) break;
      if (delay_intro(speed)) break;
      kill_note(basschannel,F2,basslevel);
      if (basslevel <= 127)
         basslevel+= 4;
      if (basslevel > 127)
         basslevel = 127;
      play_note(basschannel,A2,basslevel);
      if (delay_intro(speed)) break;
      if (delay_intro(speed)) break;
      kill_note(basschannel,A2,basslevel);
      if (basslevel <= 127)
         basslevel+= 4;
      if (basslevel > 127)
      {
         basslevel = 127;
      }
      if (key_table[INDEX_SPACE])
         break;
   }

   first_flight();
}


void showinfo()
{
   clrscr();
   cout << "The Guardian Legend";
   wait_for_no(INDEX_ESC);
   cout << "\n[F1]:    Intro";
   cout << "\n[F2]:    First Flight";
   cout << "\n[F3]:    Area 0";
   cout << "\n[F4]:    Computer Room";
   cout << "\n[1    ]: Walk Around";
   cout << "\n[SPACE]: Fly Through Space!";
   cout << "\nESC: Quit";
}

void main()
{
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        change_program(drumchannel,120,1);
        change_program(fxchannel,100,4);
        change_program(brasschannel,87,4);
        change_program(basschannel,48,0);  //48 0
        change_program(11,124,0);
        change_program(1,88,4);
        change_program(4,53,0);
//      change_effects_channel(8);
        mix_name("Guardian");
        mix_mode();
        showinfo();
        bassnotes[0] = 57;
        bassnotes[1] = 60;
        bassnotes[2] = 65;
        bassnotes[3] = 64;
        bassnotes[4] = 57;
        bassnotes[5] = 60;
        bassnotes[6] = 65;
        bassnotes[7] = 64;
        bassnotes[8] = 57;
        bassnotes[9] = 60;
        bassnotes[10] = 65;
        bassnotes[11] = 64;
        bassnotes[12] = 57;
        bassnotes[13] = 60;
        bassnotes[14] = 65;
        bassnotes[15] = 64;
        for (int index=0;index<16;index++)
         bassnotes[index] -= 12;
        for (int measure=0;measure<8;measure++)
           for (int note=0;note<8;note++)
              walkbassnotes[measure][note] = 0;
              
        walkbassnotes[8][0] = GS3 - 12;
        walkbassnotes[8][1] = GS3 - 12;
        walkbassnotes[8][2] = AS3- 12;
        walkbassnotes[8][3] = AS3- 12;
        walkbassnotes[8][4] = B3- 12;
        walkbassnotes[8][5] = B3- 12;
        walkbassnotes[8][6] = CS4- 12;
        walkbassnotes[8][7] = CS4- 12;

        walkbassnotes[9][0] = A3- 12;
        walkbassnotes[9][1] = A2- 12;
        walkbassnotes[9][2] = E4- 12;
        walkbassnotes[9][3] = E3- 12;
        walkbassnotes[9][4] = DS4- 12;
        walkbassnotes[9][5] = E4- 12;
        walkbassnotes[9][6] = A3- 12;
        walkbassnotes[9][7] = A3- 12;

        walkbassnotes[10][0] = B3- 12;
        walkbassnotes[10][1] = B3- 12;
        walkbassnotes[10][2] = FS3- 12;
        walkbassnotes[10][3] = FS3- 12;
        walkbassnotes[10][4] = E3- 12;
        walkbassnotes[10][5] = E3- 12;
        walkbassnotes[10][6] = DS3- 12;
        walkbassnotes[10][7] = DS3- 12;

        walkbassnotes[11][0] = GS3- 12;
        walkbassnotes[11][1] = GS3- 12;
        walkbassnotes[11][2] = DS4- 12;
        walkbassnotes[11][3] = DS4- 12;
        walkbassnotes[11][4] = CS4- 12;
        walkbassnotes[11][5] = CS4- 12;
        walkbassnotes[11][6] = B3- 12;
        walkbassnotes[11][7] = B3- 12;

        walkbassnotes[12][0] = CS4- 12;
        walkbassnotes[12][1] = CS3- 12;
        walkbassnotes[12][2] = B3- 12;
        walkbassnotes[12][3] = B2- 12;
        walkbassnotes[12][4] = A3- 12;
        walkbassnotes[12][5] = A2- 12;
        walkbassnotes[12][6] = GS3- 12;
        walkbassnotes[12][7] = GS3- 12;

        walkbassnotes[13][0] = A3- 12;
        walkbassnotes[13][1] = A2- 12;
        walkbassnotes[13][2] = E4- 12;
        walkbassnotes[13][3] = E3- 12;
        walkbassnotes[13][4] = DS4- 12;
        walkbassnotes[13][5] = E4- 12;
        walkbassnotes[13][6] = A3- 12;
        walkbassnotes[13][7] = A3- 12;

        walkbassnotes[14][0] = B3- 12;
        walkbassnotes[14][1] = B3- 12;
        walkbassnotes[14][2] = FS3- 12;
        walkbassnotes[14][3] = FS3- 12;
        walkbassnotes[14][4] = E3- 12;
        walkbassnotes[14][5] = E3- 12;
        walkbassnotes[14][6] = DS3- 12;
        walkbassnotes[14][7] = DS3- 12;

        walkbassnotes[15][0] = GS3- 12;
        walkbassnotes[15][1] = GS3- 12;
        walkbassnotes[15][2] = GS3- 12;
        walkbassnotes[15][3] = B3- 12;
        walkbassnotes[15][4] = B3- 12;
        walkbassnotes[15][5] = B3- 12;
        walkbassnotes[15][6] = DS3- 12;
        walkbassnotes[15][7] = DS3- 12;

        walkbassnotes[16][0] = DS3- 12;
        walkbassnotes[16][1] = FS3- 12;
        walkbassnotes[16][2] = FS3- 12;
        walkbassnotes[16][3] = FS3- 12;
        walkbassnotes[16][4] = E3- 12;
        walkbassnotes[16][5] = E3- 12;
        walkbassnotes[16][6] = DS3- 12;
        walkbassnotes[16][7] = DS3- 12;

        firstflightbassnotes[19][0] = F2;
        firstflightbassnotes[19][1] = AS2;
        firstflightbassnotes[19][2] = F2;
        firstflightbassnotes[19][3] = AS2;
        firstflightbassnotes[19][4] = F2;
        firstflightbassnotes[19][5] = AS2;
        firstflightbassnotes[19][6] = F2;
        firstflightbassnotes[19][7] = DS3;

        firstflightbassnotes[20][0] = AS2;
        firstflightbassnotes[20][1] = DS3;
        firstflightbassnotes[20][2] = AS2;
        firstflightbassnotes[20][3] = DS3;
        firstflightbassnotes[20][4] = AS2;
        firstflightbassnotes[20][5] = DS3;
        firstflightbassnotes[20][6] = AS2;
        firstflightbassnotes[20][7] = DS3;

        for (measure=21;measure<=23;measure++)
        {
           firstflightbassnotes[measure][0] = F2;
           firstflightbassnotes[measure][1] = AS2;
           firstflightbassnotes[measure][2] = F2;
           firstflightbassnotes[measure][3] = AS2;
           firstflightbassnotes[measure][4] = F2;
           firstflightbassnotes[measure][5] = AS2;
           firstflightbassnotes[measure][6] = F2;
           firstflightbassnotes[measure][7] = AS2;
        }

        firstflightbassnotes[24][0] = DS3;
        firstflightbassnotes[24][1] = AS2;
        firstflightbassnotes[24][2] = DS3;
        firstflightbassnotes[24][3] = AS2;
        firstflightbassnotes[24][4] = DS3;
        firstflightbassnotes[24][5] = AS2;
        firstflightbassnotes[24][6] = DS3;
        firstflightbassnotes[24][7] = AS2;

        for (measure=25;measure<=26;measure++)
        {
           firstflightbassnotes[measure][0] = F2;
           firstflightbassnotes[measure][1] = AS2;
           firstflightbassnotes[measure][2] = F2;
           firstflightbassnotes[measure][3] = AS2;
           firstflightbassnotes[measure][4] = F2;
           firstflightbassnotes[measure][5] = AS2;
           firstflightbassnotes[measure][6] = F2;
           firstflightbassnotes[measure][7] = AS2;
        }

        firstflightbassnotes[27][0] = F3;
        firstflightbassnotes[27][1] = C3;
        firstflightbassnotes[27][2] = F3;
        firstflightbassnotes[27][3] = C3;
        firstflightbassnotes[27][4] = F3;
        firstflightbassnotes[27][5] = C3;
        firstflightbassnotes[27][6] = F3;
        firstflightbassnotes[27][7] = C3;

        firstflightbassnotes[28][0] = F3;
        firstflightbassnotes[28][1] = C3;
        firstflightbassnotes[28][2] = DS3;
        firstflightbassnotes[28][3] = AS2;
        firstflightbassnotes[28][4] = DS3;
        firstflightbassnotes[28][5] = AS2;
        firstflightbassnotes[28][6] = DS3;
        firstflightbassnotes[28][7] = AS2;

        firstflightbassnotes[29][0] = DS3;
        firstflightbassnotes[29][1] = AS2;
        firstflightbassnotes[29][2] = DS3;
        firstflightbassnotes[29][3] = AS2;
        firstflightbassnotes[29][4] = F2;
        firstflightbassnotes[29][5] = AS2;
        firstflightbassnotes[29][6] = F2;
        firstflightbassnotes[29][7] = AS2;

        firstflightbassnotes[30][0] = F2;
        firstflightbassnotes[30][1] = AS2;
        firstflightbassnotes[30][2] = F2;
        firstflightbassnotes[30][3] = AS2;
        firstflightbassnotes[30][4] = F2;
        firstflightbassnotes[30][5] = AS2;
        firstflightbassnotes[30][6] = F2;
        firstflightbassnotes[30][7] = AS2;

        firstflightbassnotes[31][0] = F2;
        firstflightbassnotes[31][1] = AS2;
        firstflightbassnotes[31][2] = F2;
        firstflightbassnotes[31][3] = AS2;
        firstflightbassnotes[31][4] = G3;
        firstflightbassnotes[31][5] = D3;
        firstflightbassnotes[31][6] = G3;
        firstflightbassnotes[31][7] = D3;

        firstflightbassnotes[32][0] = G3;
        firstflightbassnotes[32][1] = D3;
        firstflightbassnotes[32][2] = G3;
        firstflightbassnotes[32][3] = D3;
        firstflightbassnotes[32][4] = F3;
        firstflightbassnotes[32][5] = C3;
        firstflightbassnotes[32][6] = F3;
        firstflightbassnotes[32][7] = C3;

        firstflightbassnotes[33][0] = F3;
        firstflightbassnotes[33][1] = C3;
        firstflightbassnotes[33][2] = F3;
        firstflightbassnotes[33][3] = C3;
        firstflightbassnotes[33][4] = AS3;
        firstflightbassnotes[33][5] = DS2;
        firstflightbassnotes[33][6] = AS3;
        firstflightbassnotes[33][7] = DS3;

        firstflightbassnotes[34][0] = AS2;
        firstflightbassnotes[34][1] = DS3;
        firstflightbassnotes[34][2] = AS2;
        firstflightbassnotes[34][3] = DS3;
        firstflightbassnotes[34][4] = AS2;
        firstflightbassnotes[34][5] = DS3;
        firstflightbassnotes[34][6] = AS2;
        firstflightbassnotes[34][7] = DS3;

        firstflightbassnotes[35][0] = AS2;
        firstflightbassnotes[35][1] = DS3;
        firstflightbassnotes[35][2] = AS2;
        firstflightbassnotes[35][3] = DS3;
        firstflightbassnotes[35][4] = AS2;
        firstflightbassnotes[35][5] = DS3;
        firstflightbassnotes[35][6] = G3;
        firstflightbassnotes[35][7] = D3;

        firstflightbassnotes[36][0] = G3;
        firstflightbassnotes[36][1] = D3;
        firstflightbassnotes[36][2] = G3;
        firstflightbassnotes[36][3] = D3;
        firstflightbassnotes[36][4] = G3;
        firstflightbassnotes[36][5] = D3;
        firstflightbassnotes[36][6] = F3;
        firstflightbassnotes[36][7] = C3;

        firstflightbassnotes[37][0] = F3;
        firstflightbassnotes[37][1] = C3;
        firstflightbassnotes[37][2] = F3;
        firstflightbassnotes[37][3] = C3;
        firstflightbassnotes[37][4] = F3;
        firstflightbassnotes[37][5] = C3;
        firstflightbassnotes[37][6] = F3;
        firstflightbassnotes[37][7] = AS2;

        firstflightbassnotes[38][0] = F2;
        firstflightbassnotes[38][1] = AS2;
        firstflightbassnotes[38][2] = F2;
        firstflightbassnotes[38][3] = AS2;
        firstflightbassnotes[38][4] = F2;
        firstflightbassnotes[38][5] = AS2;
        firstflightbassnotes[38][6] = F2;
        firstflightbassnotes[38][7] = AS2;

        firstflightbassnotes[39][0] = F3;
        firstflightbassnotes[39][1] = AS2;
        firstflightbassnotes[39][2] = F3;
        firstflightbassnotes[39][3] = AS2;
        firstflightbassnotes[39][4] = F3;
        firstflightbassnotes[39][5] = AS2;
        firstflightbassnotes[39][6] = F3;
        firstflightbassnotes[39][7] = AS2;

        firstflightbassnotes[40][0] = DS3;
        firstflightbassnotes[40][1] = AS2;
        firstflightbassnotes[40][2] = DS3;
        firstflightbassnotes[40][3] = AS2;
        firstflightbassnotes[40][4] = DS3;
        firstflightbassnotes[40][5] = AS2;
        firstflightbassnotes[40][6] = DS3;
        firstflightbassnotes[40][7] = AS2;

        firstflightbassnotes[41][0] = F3;
        firstflightbassnotes[41][1] = C3;
        firstflightbassnotes[41][2] = F3;
        firstflightbassnotes[41][3] = C3;
        firstflightbassnotes[41][4] = F3;
        firstflightbassnotes[41][5] = C3;
        firstflightbassnotes[41][6] = F3;
        firstflightbassnotes[41][7] = C3;

        firstflightbassnotes[42][0] = C3;
        firstflightbassnotes[42][1] = AS2;
        firstflightbassnotes[42][2] = F3;
        firstflightbassnotes[42][3] = C2;
        firstflightbassnotes[42][4] = F2;
        firstflightbassnotes[42][5] = C2;
        firstflightbassnotes[42][6] = F2;
        firstflightbassnotes[42][7] = C2;

        firstflightbassnotes[43][0] = F2;
        firstflightbassnotes[43][1] = AS2;
        firstflightbassnotes[43][2] = F2;
        firstflightbassnotes[43][3] = AS2;
        firstflightbassnotes[43][4] = F2;
        firstflightbassnotes[43][5] = AS2;
        firstflightbassnotes[43][6] = F2;
        firstflightbassnotes[43][7] = AS2;

        firstflightbassnotes[44][0] = F2;
        firstflightbassnotes[44][1] = AS2;
        firstflightbassnotes[44][2] = DS3;
        firstflightbassnotes[44][3] = AS2;
        firstflightbassnotes[44][4] = DS3;
        firstflightbassnotes[44][5] = AS2;
        firstflightbassnotes[44][6] = DS3;
        firstflightbassnotes[44][7] = AS2;

        firstflightbassnotes[45][0] = DS3;
        firstflightbassnotes[45][1] = AS2;
        firstflightbassnotes[45][2] = DS3;
        firstflightbassnotes[45][3] = AS2;
        firstflightbassnotes[45][4] = DS3;
        firstflightbassnotes[45][5] = AS2;
        firstflightbassnotes[45][6] = DS3;
        firstflightbassnotes[45][7] = AS2;

        firstflightbassnotes[46][0] = F2;
        firstflightbassnotes[46][1] = AS2;
        firstflightbassnotes[46][2] = F2;
        firstflightbassnotes[46][3] = AS2;
        firstflightbassnotes[46][4] = F2;
        firstflightbassnotes[46][5] = AS2;
        firstflightbassnotes[46][6] = F2;
        firstflightbassnotes[46][7] = AS2;

        for (measure=1;measure<=4;measure++)
           for (note=0;note<16;note++)
              area0bassnotes[measure][note] = GS1;

        for (measure=9;measure<=9;measure++)
           for (note=0;note<16;note++)
              area0bassnotes[measure][note] = GS1;

        for (measure=8;measure<=8;measure++)
           for (note=0;note<16;note++)
              area0bassnotes[measure][note] = C1;

        area0bassnotes[2][10] = F1;
        area0bassnotes[2][11] = F1;
        area0bassnotes[2][12] = FS1;
        area0bassnotes[2][13] = FS1;
        area0bassnotes[2][14] = G1;
        area0bassnotes[2][15] = G1;

        area0bassnotes[9][10] = F1;
        area0bassnotes[9][11] = F1;
        area0bassnotes[9][12] = FS1;
        area0bassnotes[9][13] = FS1;
        area0bassnotes[9][14] = G1;
        area0bassnotes[9][15] = G1;
                       
        area0bassnotes[4][10] = AS1;
        area0bassnotes[4][11] = AS1;
        area0bassnotes[4][12] = B1;
        area0bassnotes[4][13] = B1;
        area0bassnotes[4][14] = C2;
        area0bassnotes[4][15] = C2;

        for (measure=5;measure<=5;measure++)
           for (note=0;note<16;note++)
              if (note < 8)
                 area0bassnotes[measure][note] = CS2;
              else
                 area0bassnotes[measure][note] = C2;

        for (measure=6;measure<=6;measure++)
           for (note=0;note<16;note++)
              if (note < 8)
                 area0bassnotes[measure][note] = B1;
              else
                 area0bassnotes[measure][note] = AS1;

        for (measure=7;measure<=7;measure++)
           for (note=0;note<16;note++)
              if (note < 8)
                 area0bassnotes[measure][note] = CS2;
              else
                 area0bassnotes[measure][note] = C2;

        for (measure=1;measure<=9;measure++)
           for (note=0;note<16;note++)
              area0bassnotes[measure][note] += 12;

        for (measure=1;measure<=2;measure++)
           for (note=0;note<16;note++)
              computerroombassnotes[measure][note] = FS2;

        for (measure=3;measure<=4;measure++)
           for (note=0;note<16;note++)
              computerroombassnotes[measure][note] = CS2;

        for (measure=5;measure<=6;measure++)
           for (note=0;note<16;note++)
              computerroombassnotes[measure][note] = A1;

        for (measure=7;measure<=8;measure++)
           for (note=0;note<16;note++)
              computerroombassnotes[measure][note] = B1;

        for (measure=9;measure<=10;measure++)
           for (note=0;note<16;note++)
              computerroombassnotes[measure][note] = D2;

        for (measure=11;measure<=12;measure++)
           for (note=0;note<16;note++)
              computerroombassnotes[measure][note] = E2;

        computerroombassnotes[2][6] = FS3;
        computerroombassnotes[2][7] = CS3;

        computerroombassnotes[4][6] = CS3;
        computerroombassnotes[4][7] = A2;

        computerroombassnotes[6][6] = A2;
        computerroombassnotes[6][7] = E2;

        computerroombassnotes[8][6] = B2;
        computerroombassnotes[8][7] = FS2;

        computerroombassnotes[9][6] = D3;
        computerroombassnotes[9][7] = D3;

        computerroombassnotes[10][6] = D3;
        computerroombassnotes[10][7] = A2;

        computerroombassnotes[11][6] = E3;
        computerroombassnotes[11][7] = B2;

        computerroombassnotes[12][6] = E3;
        computerroombassnotes[12][7] = B2;

        computerroombassnotes[13][0] = FS3;
        computerroombassnotes[13][1] = CS3;
        computerroombassnotes[13][2] = A2;
        computerroombassnotes[13][3] = FS2;
        computerroombassnotes[13][4] = FS3;
        computerroombassnotes[13][5] = CS3;
        computerroombassnotes[13][6] = A2;
        computerroombassnotes[13][7] = FS2;

        computerroombassnotes[14][0] = FS3;
        computerroombassnotes[14][1] = CS3;
        computerroombassnotes[14][2] = A2;
        computerroombassnotes[14][3] = FS2;
        computerroombassnotes[14][4] = FS3;
        computerroombassnotes[14][5] = CS3;
        computerroombassnotes[14][6] = A2;
        computerroombassnotes[14][7] = FS2;
        change_effects_level(10,0);
        mix_mode();

        //13 & 14
        while (1)
        {
                delay1(1);
                if (key_table[INDEX_F1])
                {
                   intro();
                   showinfo();
                   basslevel = 75;
                   change_program(1,88,4);
                   change_program(basschannel,48,0);  //48 0
                }

                if (key_table[INDEX_F2])
                {
                   first_flight();
                   showinfo();
                   basslevel = 75;
                   change_program(1,88,4);
                   change_program(basschannel,48,0);  //48 0
                }

                if (key_table[INDEX_F3])
                {
                   area0();
                   showinfo();
                   basslevel = 75;
                   change_program(1,88,4);
                   change_program(basschannel,48,0);  //48 0
                }

                if (key_table[INDEX_F4])
                {
                   computerroom();
                   showinfo();
                   basslevel = 75;
                   change_program(1,88,4);
                   change_program(basschannel,48,0);  //48 0
                }

                if (key_table[INDEX_1])
                {
                   go();
                   showinfo();
                }
                if (key_table[INDEX_ESC]) break;
                if (key_table[INDEX_SPACE])
                {
                   space_flight();
                   showinfo(); 
                }
        }
//      change_volume(basschannel,99);
        kill_keyboard();
        Exit_MIDI();
    }
