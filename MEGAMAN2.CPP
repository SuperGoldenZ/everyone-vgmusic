#include "keyboard.h"
#include "midi.h"
#include "lights.h"

#include <dos.h>
   
int nspeed = 135;

#define chordlevel 127
#define basschannel 3   
   
#define counterchannel 6   
#define counterlevel 127   
   
int bassnotes[56][12];   
int drumbassnotes[56][8];
int basslevel = 127; //old 127
int drumchannel = 10;

void flashman();   
   
//Octave||                     Note Numbers   
//   #  ||   
//      || C   | C#  | D   | D#  | E   | F   | F#  | G   | G#  | A   | A#  | B   
//-----------------------------------------------------------------------------   
//  -2  ||   0 |   1 |   2 |   3 |   4 |   5 |   6 |   7 |   8 |   9 |  10 | 11   
//  -1  ||  12 |  13 |  14 |  15 |  16 |  17 |  18 |  19 |  20 |  21 |  22 | 23   
//   0  ||  24 |  25 |  26 |  27 |  28 |  29 |  30 |  31 |  32 |  33 |  34 | 35   
//   1  ||  36 |  37 |  38 |  39 |  40 |  41 |  42 |  43 |  44 |  45 |  46 | 47   
//   2  ||  48 |  49 |  50 |  51 |  52 |  53 |  54 |  55 |  56 |  57 |  58 | 59   
//   3  ||  60 |  61 |  62 |  63 |  64 |  65 |  66 |  67 |  68 |  69 |  70 | 71   
//   4  ||  72 |  73 |  74 |  75 |  76 |  77 |  78 |  79 |  80 |  81 |  82 | 83   
//   5  ||  84 |  85 |  86 |  87 |  88 |  89 |  90 |  91 |  92 |  93 |  94 | 95   
//   6  ||  96 |  97 |  98 |  99 | 100 | 101 | 102 | 103 | 104 | 105 | 106 | 107   
//   7  || 108 | 109 | 110 | 111 | 112 | 113 | 114 | 115 | 116 | 117 | 118 | 119   
//   8  || 120 | 121 | 122 | 123 | 124 | 125 | 126 | 127 |   
   
//Skull Castle Rich's Part:   
//DOWN LEFT RIGHT UP DOWN UP DOWN LEFT RIGHT UP DOWN UP   
//SPACE SPACE LEFT DOWN ENTER   
   
//R R RIGHT R A Y Q A V R R RIGHT R   
//A A Q A V V T RIGHT Y Q A V V A V R   
   
int laser = 0;   
int index;   
   
#define flutechannel 5   
int flutelevel = 127;   
   
void menu();   
   
void playchord1()   
{   
 play_note(4,72,chordlevel);   
 play_note(4,67,chordlevel);   
 play_note(4,63,chordlevel);   
 play_note(4,60,chordlevel);   
}   
   
void playchord2()   
{   
 play_note(4,70,chordlevel);   
 play_note(4,65,chordlevel);   
 play_note(4,62,chordlevel);   
 play_note(4,58,chordlevel);   
}   
   
void playchord3()   
{   
 play_note(4,68,chordlevel);   
 play_note(4,63,chordlevel);   
 play_note(4,60,chordlevel);   
 play_note(4,56,chordlevel);   
}   
   
void playchord4()   
{   
 play_note(4,67,chordlevel);   
 play_note(4,62,chordlevel);   
 play_note(4,59,chordlevel);   
 play_note(4,55,chordlevel);   
}   
   
void playchord5()   
{   
 play_note(4,72,chordlevel);   
 play_note(4,67,chordlevel);   
 play_note(4,64,chordlevel);   
 play_note(4,60,chordlevel);   
}   
   
void killchord1()   
{   
 kill_note(4,72,chordlevel);   
 kill_note(4,67,chordlevel);   
 kill_note(4,63,chordlevel);   
 kill_note(4,60,chordlevel);   
}   
   
void killchord2()   
{   
 kill_note(4,70,chordlevel);   
 kill_note(4,65,chordlevel);   
 kill_note(4,62,chordlevel);   
 kill_note(4,58,chordlevel);   
}   
   
void killchord3()   
{   
 kill_note(4,68,chordlevel);   
 kill_note(4,63,chordlevel);   
 kill_note(4,60,chordlevel);   
 kill_note(4,56,chordlevel);   
}   
   
void killchord4()   
{   
 kill_note(4,67,chordlevel);   
 kill_note(4,62,chordlevel);   
 kill_note(4,59,chordlevel);   
 kill_note(4,55,chordlevel);   
}   
   
void killchord5()   
{   
 kill_note(4,72,chordlevel);   
 kill_note(4,67,chordlevel);   
 kill_note(4,64,chordlevel);   
 kill_note(4,60,chordlevel);   
}   
   
void playflashchord1()   
{   
 play_note(7,FS4,chordlevel);   
 play_note(7,D4,chordlevel);   
}   
   
void killflashchord1()   
{   
 kill_note(7,FS4,chordlevel);   
 kill_note(7,D4,chordlevel);   
}   
   
//F1 F1 ... F1 F2 F4 
void playflashchord2()
{   
 play_note(7,G4,chordlevel);   
 play_note(7,E4,chordlevel);   
}   
   
void killflashchord2()   
{   
 kill_note(7,G4,chordlevel);   
 kill_note(7,E4,chordlevel);   
}   
   
void playflashchord3()   
{   
 play_note(7,B4,chordlevel);   
 play_note(7,G4,chordlevel);   
}   
   
void killflashchord3()   
{   
 kill_note(7,B4,chordlevel);   
 kill_note(7,G4,chordlevel);   
}   
   
void playflashchord4()   
{   
 play_note(7,A4,chordlevel);   
 play_note(7,FS4,chordlevel);   
}   
   
void killflashchord4()   
{   
 kill_note(7,A4,chordlevel);   
 kill_note(7,FS4,chordlevel);   
}   
   
void dostuff()   
{   
        if ((notes[INDEX_1] == 0) && (key_table[INDEX_1]==1))   
        {   
          notes[INDEX_1]=1;   
          playchord1();   
        }   
        if ((notes[INDEX_1] == 1) && (key_table[INDEX_1]==0))   
        {   
          killchord1();   
          notes[INDEX_1]=0;   
        }   
   
        if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))   
        {   
          notes[INDEX_DOWN]=1;   
          playchord2();   
        }   
        if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))   
        {   
          killchord2();   
          notes[INDEX_DOWN]=0;   
        }   
   
        if ((notes[INDEX_3] == 0) && (key_table[INDEX_3]==1))   
        {   
          notes[INDEX_3]=1;   
          playchord3();   
        }   
        if ((notes[INDEX_3] == 1) && (key_table[INDEX_3]==0))   
        {   
          killchord3();   
          notes[INDEX_3]=0;   
        }   
   
        if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))   
        {   
          notes[INDEX_LEFT]=1;   
          playchord4();   
        }   
        if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))   
        {   
          killchord4();   
          notes[INDEX_LEFT]=0;   
        }   
   
        if ((notes[INDEX_5] == 0) && (key_table[INDEX_5]==1))   
        {   
          notes[INDEX_5]=1;   
          playchord5();   
        }   
        if ((notes[INDEX_5] == 1) && (key_table[INDEX_5]==0))   
        {   
          killchord5();   
          notes[INDEX_5]=0;   
        }   
}   
   
void doskull()   
{   
        if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))   
        {   
          notes[INDEX_R]=1;   
          play_note(counterchannel,CS5,127);                   
        }   
        if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))   
        {   
          kill_note(counterchannel,CS5,127);         
          notes[INDEX_R]=0;   
        }   
   
        if ((notes[INDEX_A] == 0) && (key_table[INDEX_A]==1))   
        {   
          notes[INDEX_A]=1;   
          play_note(counterchannel,E5,127);                   
        }   
        if ((notes[INDEX_A] == 1) && (key_table[INDEX_A]==0))   
        {   
          kill_note(counterchannel,E5,127);         
          notes[INDEX_A]=0;   
        }   
   
        if ((notes[INDEX_Y] == 0) && (key_table[INDEX_Y]==1))   
        {   
          notes[INDEX_Y]=1;   
          play_note(counterchannel,GS5,127);                   
        }   
        if ((notes[INDEX_Y] == 1) && (key_table[INDEX_Y]==0))   
        {   
          kill_note(counterchannel,GS5,127);         
          notes[INDEX_Y]=0;   
        }   
   
        if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))   
        {   
          notes[INDEX_Q]=1;   
          play_note(counterchannel,FS5,127);                   
        }   
        if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))   
        {   
          kill_note(counterchannel,FS5,127);         
          notes[INDEX_Q]=0;   
        }   
   
        if ((notes[INDEX_V] == 0) && (key_table[INDEX_V]==1))   
        {   
          notes[INDEX_V]=1;   
          play_note(counterchannel,DS5,127);                   
        }   
        if ((notes[INDEX_V] == 1) && (key_table[INDEX_V]==0))   
        {   
          kill_note(counterchannel,DS5,127);         
          notes[INDEX_V]=0;   
        }   
   
        if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))   
        {   
          notes[INDEX_DOWN]=1;   
          play_note(counterchannel,GS4,127);         
        }   
        if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))   
        {   
          kill_note(counterchannel,GS4,127);   
          notes[INDEX_DOWN]=0;   
        }   
   
        if ((notes[INDEX_ENTER] == 0) && (key_table[INDEX_ENTER]==1))   
        {   
          notes[INDEX_ENTER]=1;   
          play_note(counterchannel,DS4,127);         
        }   
        if ((notes[INDEX_ENTER] == 1) && (key_table[INDEX_ENTER]==0))   
        {   
          kill_note(counterchannel,DS4,127);         
          notes[INDEX_ENTER]=0;   
        }   
   
        if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))   
        {   
          notes[INDEX_LEFT]=1;   
          play_note(counterchannel,FS4,127);         
        }   
        if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))   
        {   
          kill_note(counterchannel,FS4,127);         
          notes[INDEX_LEFT]=0;   
        }   
   
        if ((notes[INDEX_RIGHT] == 0) && (key_table[INDEX_RIGHT]==1))   
        {   
          notes[INDEX_RIGHT]=1;   
          play_note(counterchannel,B4,127);         
        }   
        if ((notes[INDEX_RIGHT] == 1) && (key_table[INDEX_RIGHT]==0))   
        {   
          kill_note(counterchannel,B4,127);         
          notes[INDEX_RIGHT]=0;   
        }   
   
        if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))   
        {   
          notes[INDEX_UP]=1;   
          play_note(counterchannel,A4,127);         
        }   
        if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))   
        {   
          kill_note(counterchannel,A4,127);         
          notes[INDEX_UP]=0;   
        }   
   
        if ((notes[INDEX_SPACE] == 0) && (key_table[INDEX_SPACE]==1))   
        {   
          notes[INDEX_SPACE]=1;   
          play_note(counterchannel,E4,127);   
        }   
        if ((notes[INDEX_SPACE] == 1) && (key_table[INDEX_SPACE]==0))   
        {   
          kill_note(counterchannel,E4,127);   
          notes[INDEX_SPACE]=0;   
        }   
}   
   
void doflash()   
{   
        if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))   
        {   
          notes[INDEX_F1]=1;   
          playflashchord1();   
        }   
        if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))   
        {   
          killflashchord1();   
          notes[INDEX_F1]=0;   
        }   
   
        if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))   
        {   
          notes[INDEX_F2]=1;   
          playflashchord2();   
        }   
        if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))   
        {   
          killflashchord2();   
          notes[INDEX_F2]=0;   
        }   
   
        if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))   
        {   
          notes[INDEX_F3]=1;   
          playflashchord3();   
        }   
        if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))   
        {   
          killflashchord3();   
          notes[INDEX_F3]=0;   
        }   
   
        if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))   
        {   
          notes[INDEX_F4]=1;   
          playflashchord4();   
        }   
        if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))   
        {   
          killflashchord4();   
          notes[INDEX_F4]=0;   
        }   
}
   
int delay1(int num)   
{   
int index;   
for (index=0;index<num;index++)   
{   
 dostuff();   
 if (key_table[INDEX_SPACE]) return 1;   
 delay(1);   
}   
return 0;   
}   
   
void dobass();   
   
int delay2(int num)   
{   
 for (int index=0;index<num;index++)   
 {   
  dobass();   
  if (key_table[INDEX_ESC])   
  {   
   flutelevel = 0;   
   return 1;   
  }   
  delay(1);   
 }   
return 0;   
}   
   
int delay_skull(int num)   
{   
 for (int index=0;index<num;index++)   
 {   
  doskull();   
  if (key_table[INDEX_ESC])   
  {   
   return 1;   
  }   
  delay(1);   
 }   
return 0;   
}   
   
int delay_flash(int num)   
{   
 for (int index=0;index<num;index++)   
 {   
  doflash();   
  if (key_table[INDEX_ESC])   
  {   
   return 1;   
  }   
  delay(1);   
 }   
return 0;   
}   
   
//DRUMS!   
void drums(const int & speed)   
{   
clrscr();

  //***change_program(2,90,1); //quadratix
//change_effects_channel(2);

//***change_volume(2,99);
cout << "Drum mode activated!";   
cout << "\nSPACE returns to Bass Blaster Mode!";   
  //***delay(speed*2);
int measure = 21;    //old = 21
for (index=0;index<127;index++)   
   notes[index] = 0;   
//***play_note(1,61,127);
//screech delay
//***fade_out_light(2,35,1,3);
//***fade_out_light(4,35,1,2);
//***for (int index=0;index<(1000)+(speed*6);index++)
//***{
//***   delay1(1);
//***   do_fade_stuff();
//***}


/*   play_note(10,37,127);
   delay(speed);   
   delay(speed);   
   delay(speed);   
   delay(speed);   
   kill_note(10,37,127);

   play_note(10,37,127);
   delay(speed);   
   delay(speed);   
   delay(speed);   
   delay(speed);   
   kill_note(10,37,127);

   play_note(10,37,127);
   delay(speed);   
   delay(speed);   
   delay(speed);   
   delay(speed);   
   kill_note(10,37,127);

   play_note(10,37,127);
   delay(speed);   
   delay(speed);   
   delay(speed);   
   delay(speed);   
   kill_note(10,37,127);*/

   int count = 0;

//***   kill_note(1,61,127);
//***   change_light_level(9,127);
//   change_light_level(1,50);
//   change_light_level(2,75);
//   change_light_level(3,25);
//   change_light_level(4,50);

        while (1)
        {   
           if ((count == 1) && (measure == 35))
              break;
           //Begin measure
           if (measure == 46)
           {
              measure = 21;
              count++;
           }
           if (measure == 35)
           {
              change_light_level(1,50);
              change_light_level(2,75);
              change_light_level(3,25);
              change_light_level(3,50);
              change_light_level(9,0);

              cout << "\nMeasure: " << ++measure << " (pre solo 1)";
              play_note(basschannel,GS1,127);
              play_note(drumchannel,D2,127);
              play_note(drumchannel,E1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,D2,127);
              kill_note(drumchannel,E1,127);
              kill_note(basschannel,GS1,127);
              play_note(basschannel,GS1,127);
              play_note(drumchannel,C2,127);
              play_note(drumchannel,E1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,C2,127);
              kill_note(drumchannel,E1,127);
              kill_note(basschannel,GS1,127);
              play_note(basschannel,GS1,127);
              play_note(drumchannel,B1,127);
              play_note(drumchannel,E1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,B1,127);
              kill_note(drumchannel,E1,127);
              kill_note(basschannel,GS1,127);
              play_note(basschannel,GS1,127);
              play_note(drumchannel,E1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,E1,127);
              kill_note(basschannel,GS1,127);
              play_note(basschannel,AS1,127);
              play_note(drumchannel,A2,127);
              play_note(drumchannel,E1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(basschannel,AS1,127);
              kill_note(drumchannel,A2,127);
              kill_note(drumchannel,E1,127);
              play_note(basschannel,AS1,127);

              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(basschannel,AS1,127);
              play_note(basschannel,AS1,127);
              if (delay1(speed)) break;   
              if (delay1(speed)) break;   
              kill_note(basschannel,AS1,127);
              play_note(basschannel,AS1,127);
              play_note(drumchannel,E1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;
              kill_note(basschannel,AS1,127);
              kill_note(drumchannel,E1,127);
           }
           else
           if (measure == 36)
           {
              cout << "\nMeasure: " << ++measure << " (pre solo 2)";
              play_note(basschannel,C2,127);
              play_note(drumchannel,DS1,127);
              play_note(drumchannel,C1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(basschannel,C2,127);
              play_note(basschannel,C2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,DS1,127);
              kill_note(drumchannel,C1,127);
              play_note(drumchannel,DS1,127);
              play_note(drumchannel,C1,127);
              kill_note(basschannel,C2,127);
              play_note(basschannel,C2,127);
              if (delay1(speed)) break;   
              if (delay1(speed)) break;   
              kill_note(basschannel,C2,127);
              play_note(basschannel,C2,127);
              if (delay1(speed)) break;   
              if (delay1(speed)) break;   
              kill_note(drumchannel,DS1,127);
              kill_note(drumchannel,C1,127);
              play_note(drumchannel,DS1,127);
              play_note(drumchannel,C1,127);
              kill_note(basschannel,C2,127);
              play_note(basschannel,C2,127);
              if (delay1(speed)) break;   
              if (delay1(speed)) break;   
              kill_note(basschannel,C2,127);
              play_note(basschannel,C2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,DS1,127);
              kill_note(drumchannel,C1,127);
              play_note(drumchannel,DS1,127);
              play_note(drumchannel,C1,127);
              kill_note(basschannel,C2,127);
              play_note(basschannel,C2,127);
              if (delay1(speed)) break;   
              if (delay1(speed)) break;   
              kill_note(basschannel,C2,127);
              play_note(basschannel,C2,127);
              if (delay1(speed)) break;   
              if (delay1(speed)) break;   
              kill_note(drumchannel,DS1,127);
              kill_note(drumchannel,C1,127);
              kill_note(basschannel,C2,127);
           }
           else
           if ((measure == 37) || (measure == 38))
           {
              //Measures 38 and 39
              cout << "\nMeasure: " << ++measure;
              play_note(drumchannel,F1,127);
              play_note(basschannel,C2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              if (delay1(speed)) break;
              kill_note(basschannel,C2,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,F1,127);
              play_note(drumchannel,C1,127);
              play_note(drumchannel,G1,127);
              play_note(drumchannel,DS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,C1,127);
              kill_note(drumchannel,G1,127);
              kill_note(drumchannel,DS2,127);
              play_note(drumchannel,F1,127);
              play_note(basschannel,C2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(basschannel,C2,127);
              play_note(basschannel,C2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,F1,127);
              play_note(drumchannel,DS2,127);
              play_note(drumchannel,G1,127);
              if (delay1(speed)) break;
              kill_note(basschannel,C2,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,DS2,127);
              kill_note(drumchannel,G1,127);
              play_note(drumchannel,C1,127);
              play_note(drumchannel,F1,127);
              play_note(drumchannel,DS2,127);
              play_note(basschannel,C2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,C1,127);
              kill_note(drumchannel,F1,127);
              kill_note(drumchannel,DS2,127);
              if (delay1(speed)) break;
              kill_note(basschannel,C2,127);
              if (delay1(speed)) break;
           }
           else
           if ((measure == 39) || (measure == 40))
           {
              cout << "\nMeasure: " << ++measure;
              play_note(drumchannel,F1,127);
              play_note(basschannel,AS1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              if (delay1(speed)) break;
              kill_note(basschannel,AS1,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,F1,127);
              play_note(drumchannel,C1,127);
              play_note(drumchannel,G1,127);
              play_note(drumchannel,DS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,C1,127);
              kill_note(drumchannel,G1,127);
              kill_note(drumchannel,DS2,127);
              play_note(drumchannel,F1,127);
              play_note(basschannel,AS1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(basschannel,AS1,127);
              play_note(basschannel,AS1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,F1,127);
              play_note(drumchannel,DS2,127);
              play_note(drumchannel,G1,127);
              if (delay1(speed)) break;
              kill_note(basschannel,AS1,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,DS2,127);
              kill_note(drumchannel,G1,127);
              play_note(drumchannel,C1,127);
              play_note(drumchannel,F1,127);
              play_note(drumchannel,DS2,127);
              play_note(basschannel,AS1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,C1,127);
              kill_note(drumchannel,F1,127);
              kill_note(drumchannel,DS2,127);
              if (delay1(speed)) break;
              kill_note(basschannel,AS1,127);
              if (delay1(speed)) break;
           }
           else
           if ((measure == 41) || (measure == 42))
           {
              cout << "\nMeasure: " << ++measure;
              play_note(drumchannel,F1,127);
              play_note(basschannel,A1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              if (delay1(speed)) break;
              kill_note(basschannel,A1,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,F1,127);
              play_note(drumchannel,C1,127);
              play_note(drumchannel,G1,127);
              play_note(drumchannel,DS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,C1,127);
              kill_note(drumchannel,G1,127);
              kill_note(drumchannel,DS2,127);
              play_note(drumchannel,F1,127);
              play_note(basschannel,A1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(basschannel,A1,127);
              play_note(basschannel,A1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,F1,127);
              play_note(drumchannel,DS2,127);
              play_note(drumchannel,G1,127);
              if (delay1(speed)) break;
              kill_note(basschannel,A1,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,DS2,127);
              kill_note(drumchannel,G1,127);
              play_note(drumchannel,C1,127);
              play_note(drumchannel,F1,127);
              play_note(drumchannel,DS2,127);
              play_note(basschannel,A1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,C1,127);
              kill_note(drumchannel,F1,127);
              kill_note(drumchannel,DS2,127);
              if (delay1(speed)) break;
              kill_note(basschannel,A1,127);
              if (delay1(speed)) break;
           }
           else
           if ((measure == 43))
           {
              cout << "\nMeasure: " << ++measure;
              play_note(drumchannel,F1,127);
              play_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              if (delay1(speed)) break;
              kill_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,F1,127);
              play_note(drumchannel,C1,127);
              play_note(drumchannel,G1,127);
              play_note(drumchannel,DS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,C1,127);
              kill_note(drumchannel,G1,127);
              kill_note(drumchannel,DS2,127);
              play_note(drumchannel,F1,127);
              play_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(basschannel,GS2,127);
              play_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,F1,127);
              play_note(drumchannel,DS2,127);
              play_note(drumchannel,G1,127);
              if (delay1(speed)) break;
              kill_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,DS2,127);
              kill_note(drumchannel,G1,127);
              play_note(drumchannel,C1,127);
              play_note(drumchannel,F1,127);
              play_note(drumchannel,DS2,127);
              play_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,C1,127);
              kill_note(drumchannel,F1,127);
              kill_note(drumchannel,DS2,127);
              if (delay1(speed)) break;
              kill_note(basschannel,GS2,127);
              if (delay1(speed)) break;
           }
           else
           if ((measure == 44))   // end?
           {
              cout << "\nMeasure: " << ++measure;

              /*play_note(drumchannel,F1,127);
              play_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              if (delay1(speed)) break;
              kill_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,F1,127);
              play_note(drumchannel,C1,127);
              play_note(drumchannel,G1,127);
              play_note(drumchannel,DS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,C1,127);
              kill_note(drumchannel,G1,127);
              kill_note(drumchannel,DS2,127);
              play_note(drumchannel,F1,127);
              play_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(basschannel,GS2,127);
              play_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,F1,127);
              play_note(drumchannel,DS2,127);
              play_note(drumchannel,G1,127);
              if (delay1(speed)) break;
              kill_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,DS2,127);
              kill_note(drumchannel,G1,127);
              play_note(drumchannel,C1,127);
              play_note(drumchannel,F1,127);
              play_note(drumchannel,DS2,127);
              play_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,C1,127);
              kill_note(drumchannel,F1,127);
              kill_note(drumchannel,DS2,127);
              if (delay1(speed)) break;
              kill_note(basschannel,GS2,127);
              if (delay1(speed)) break;*/
           }
           else
           if ((measure == 45))
           {
              cout << "\nMeasure: " << ++measure;
              play_note(basschannel,GS2,127);
              play_note(drumchannel,D2,127);
              play_note(drumchannel,F1,127);
              play_note(drumchannel,D1,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,D2,127);
              kill_note(drumchannel,F1,127);
              kill_note(drumchannel,D1,127);
              play_note(drumchannel,D1,127);
              play_note(drumchannel,C2,127);

              if (delay1(speed)) break;
              kill_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,D1,127);
              kill_note(drumchannel,C2,127);
              play_note(drumchannel,D1,127);
              play_note(drumchannel,C2,127);
              play_note(drumchannel,G1,127);
              play_note(drumchannel,B1,127);
              play_note(drumchannel,DS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(drumchannel,D1,127);
              kill_note(drumchannel,C2,127);
              kill_note(drumchannel,G1,127);
              kill_note(drumchannel,B1,127);
              kill_note(drumchannel,DS2,127);
              play_note(drumchannel,F1,127);
              play_note(drumchannel,A1,127);
              play_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              if (delay1(speed)) break;   
              kill_note(basschannel,GS2,127);
              play_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,F1,127);
              kill_note(drumchannel,A1,127);
              if (delay1(speed)) break;
              play_note(drumchannel,A2,127);
              play_note(drumchannel,E1,127);
              play_note(drumchannel,D1,127);
              if (delay1(speed)) break;
              kill_note(basschannel,GS2,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,A2,127);
              kill_note(drumchannel,E1,127);
              kill_note(drumchannel,D1,127);
              play_note(drumchannel,B0,127);
              play_note(drumchannel,D1,127);
              play_note(drumchannel,FS1,127);
              play_note(basschannel,AS2,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,B0,127);
              kill_note(drumchannel,D1,127);
              kill_note(drumchannel,FS1,127);
              play_note(drumchannel,FS1,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,FS1,127);
              play_note(drumchannel,FS1,127);
              play_note(drumchannel,D1,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,FS1,127);
              kill_note(drumchannel,D1,127);
              play_note(drumchannel,FS1,127);
              kill_note(basschannel,AS2,127);
              if (delay1(speed)) break;
              kill_note(drumchannel,FS1,127);
              cout << "  end of measure 45";
              change_light_level(9,127);
              change_light_level(1,0);
              change_light_level(2,0);
              change_light_level(3,0);
              change_light_level(4,0);
           }

           else   //!!else  (main thing)
           {
           cout << "\nMeasure: " << ++measure << " !!else";
           if ( ((count == 0) && (measure == 22)) || (measure == 30))
              play_note(drumchannel,CS2,127);

           play_note(10,36,127);
           play_note(10,42,127);
           play_note(basschannel,drumbassnotes[measure][0],basslevel);
           if (delay1(speed)) break;   
           kill_note(10,36,127);
           kill_note(10,42,127);   
           play_note(10,42,127);   
           if (delay1(speed)) break;   
           kill_note(basschannel,drumbassnotes[measure][0],basslevel);
           play_note(basschannel,drumbassnotes[measure][1],basslevel);
           kill_note(10,42,127);
           play_note(10,42,127);   
           if (delay1(speed)) break;   
           kill_note(10,42,127);   
           play_note(10,42,127);   
           if (delay1(speed)) break;
           kill_note(10,42,127);   
           kill_note(basschannel,drumbassnotes[measure][1],basslevel);

           play_note(10,36,127);
           play_note(10,42,127);
           play_note(basschannel,drumbassnotes[measure][2],basslevel);
           if (delay1(speed)) break;
           kill_note(10,36,127);   
           kill_note(10,42,127);   
           play_note(10,42,127);   
           if (delay1(speed)) break;   
           kill_note(basschannel,drumbassnotes[measure][2],basslevel);
           play_note(basschannel,drumbassnotes[measure][3],basslevel);
           kill_note(10,42,127);
           play_note(10,42,127);   
           if (delay1(speed)) break;
           kill_note(10,42,127);   
           play_note(10,42,127);   
           if (delay1(speed)) break;
           kill_note(10,42,127);
           kill_note(basschannel,drumbassnotes[measure][3],basslevel);

           play_note(10,36,127);
           play_note(10,42,127);
           play_note(basschannel,drumbassnotes[measure][4],basslevel);
           if (measure == 29)
              play_note(drumchannel,D2,127);
           if (delay1(speed)) break;
           if (measure == 29)
              kill_note(drumchannel,D2,127);
           kill_note(10,36,127);
           kill_note(10,42,127);   
           play_note(10,42,127);   
           if (measure == 29)
              play_note(drumchannel,C2,127);
           if (delay1(speed)) break;
           if (measure == 29)
              kill_note(drumchannel,C2,127);
           kill_note(basschannel,drumbassnotes[measure][4],basslevel);
           play_note(basschannel,drumbassnotes[measure][5],basslevel);
           kill_note(10,42,127);
           play_note(10,42,127);   
           if (measure == 29)
              play_note(drumchannel,B1,127);
           if (delay1(speed)) break;
           if (measure == 29)
              kill_note(drumchannel,B1,127);
           kill_note(10,42,127);
           play_note(10,42,127);   
           if (measure == 29)
              play_note(drumchannel,A1,127);
           if (delay1(speed)) break;
           if (measure == 29)
              kill_note(drumchannel,A1,127);
           kill_note(10,42,127);
           kill_note(basschannel,drumbassnotes[measure][5],basslevel);

           play_note(10,36,127);
           play_note(10,42,127);
           play_note(basschannel,drumbassnotes[measure][6],basslevel);
           if (measure == 29)
              play_note(drumchannel,C2,127);
           if (delay1(speed)) break;
           if (measure == 29)
              kill_note(drumchannel,C2,127);
           kill_note(10,36,127);   
           kill_note(10,42,127);   
           play_note(10,42,127);   
           if (measure == 29)
              play_note(drumchannel,B1,127);
           if (delay1(speed)) break;
           if (measure == 29)
              kill_note(drumchannel,B1,127);
           kill_note(basschannel,drumbassnotes[measure][6],basslevel);
           play_note(basschannel,drumbassnotes[measure][7],basslevel);
           kill_note(10,42,127);
           play_note(10,42,127);   
           if (measure == 29)
              play_note(drumchannel,A1,127);
           if (delay1(speed)) break;
           if (measure == 29)
              kill_note(drumchannel,A1,127);

           kill_note(10,42,127);

           play_note(10,42,127);
           if (measure == 29)
              play_note(drumchannel,G1,127);
           if (delay1(speed)) break;
           if (measure == 29)
              kill_note(drumchannel,G1,127);
           kill_note(10,42,127);   
           kill_note(basschannel,drumbassnotes[measure][7],basslevel);


           if ((measure == 22) || (measure == 30))
              kill_note(drumchannel,CS2,127);
           }
        }   

   for (index=0;index<1;index++)
   {
   kill_note(10,54,127);
   change_light_level(9,0);
   change_light_level(1,50);
   change_light_level(2,75);
   change_light_level(3,25);
   change_light_level(4,50);
   //measure one of end
   play_note(10,D2,127);
   play_note(10,D1,127);
   play_note(basschannel,G1,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,D2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,G1,127);
   play_note(10,C2,127);
   play_note(10,D1,127);
   play_note(basschannel,G1,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,C2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,G1,127);
   play_note(10,B2,127);
   play_note(10,D1,127);
   play_note(basschannel,A1,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,B2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,A1,127);
   play_note(10,A2,127);
   play_note(10,D1,127);
   play_note(basschannel,C2,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,A2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,C2,127);
   if (delay1(speed)) break;

   play_note(10,C2,127);
   play_note(10,D1,127);
   play_note(basschannel,G1,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,C2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,G1,127);
   play_note(10,B2,127);
   play_note(10,D1,127);
   play_note(basschannel,A1,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,B2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,A1,127);
   play_note(10,A2,127);
   play_note(10,D1,127);
   play_note(basschannel,C2,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,A2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,C2,127);
   if (delay1(speed)) break;

   play_note(10,C2,127);
   play_note(10,D1,127);
   play_note(basschannel,G1,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,C2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,G1,127);
   play_note(10,B2,127);
   play_note(10,D1,127);
   play_note(basschannel,A1,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,B2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,A1,127);
   play_note(10,A2,127);
   play_note(10,D1,127);
   play_note(basschannel,C2,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,A2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,C2,127);
   if (delay1(speed)) break;

   play_note(10,C2,127);
   play_note(10,D1,127);
   play_note(basschannel,G2,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,C2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,G2,127);
   play_note(10,B2,127);
   play_note(10,D1,127);
   play_note(basschannel,A2,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,B2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,A2,127);
   play_note(10,A2,127);
   play_note(10,D1,127);
   play_note(basschannel,C3,127);
   play_note(10,CS1,127);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(10,CS1,127);
   kill_note(10,A2,127);
   kill_note(10,D1,127);
   kill_note(basschannel,C3,127);
   if (delay1(speed)) break;

   }
   wait_for_no(INDEX_SPACE);
   change_program(2,9,0);   
   menu();   
}   
//END DRUMS

//***
void  go()
{   
     nspeed = 135;   
     clrscr();   
     change_program(2,9,0); //tinestring
     change_effects_channel(8);
     all_lights_off(0);
     change_light_level(2,127);
     change_light_level(4,50);
     int measure = 1;
     cout << "Playing Mega Man 2 intro...";   
     flutelevel = 127;   

     cout << "\nMeasure " << measure++;
     play_note(flutechannel,82,flutelevel);   
     cout << " 1 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);
     cout << " 2 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 3 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 4 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   

     kill_note(flutechannel,82,flutelevel);
   
     //Measure 2   
     cout << "\nMeasure " << measure++;   
     play_note(flutechannel,83,flutelevel);   
     cout << " 1 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 2 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 3 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 4 " ;
     kill_note(flutechannel,83,flutelevel);
   
     play_note(flutechannel,85,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,85,flutelevel);
   
     //Measure 3   
     cout << "\nMeasure " << measure++;   
     play_note(flutechannel,82,flutelevel);   
     cout << " 1 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 2 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 3 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 4 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   

     kill_note(flutechannel,82,flutelevel);
   
     //Measure 4   
     cout << "\nMeasure " << measure++;   
     play_note(flutechannel,83,flutelevel);   
     cout << " 1 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 2 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 3 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 4 " ;
     kill_note(flutechannel,83,flutelevel);
   
     play_note(flutechannel,85,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,85,flutelevel);
   
     //Measure 5   
     cout << "\nMeasure " << measure++;   
     play_note(flutechannel,82,flutelevel);   
     cout << " 1 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,82,flutelevel);
   
     play_note(flutechannel,85,flutelevel);   
     cout << " 2 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,85,flutelevel);
   
     play_note(flutechannel,92,flutelevel);   
     cout << " 3 " ;
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,92,flutelevel);
   
     cout << " 4 " ;
     play_note(flutechannel,89,flutelevel);
     delay2(nspeed);
     delay2(nspeed);   
     kill_note(flutechannel,89,flutelevel);
   
     play_note(flutechannel,90,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);      

     //Measure 6
     cout << "\nMeasure " << measure++;   
     cout << " 1 " ;
     delay2(nspeed);
     delay2(nspeed);   
     kill_note(flutechannel,90,flutelevel);
   
     delay2(nspeed);        
     delay2(nspeed);           
     cout << " 2 " ;
     delay2(nspeed);
     delay2(nspeed);        

     play_note(flutechannel,90,flutelevel);
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 3 " ;
     kill_note(flutechannel,90,flutelevel);
        
     play_note(flutechannel,89,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,89,flutelevel);
   
     play_note(flutechannel,87,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,87,flutelevel);
     cout << " 4 " ;   
     play_note(flutechannel,85,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,85,flutelevel);
        
     play_note(flutechannel,87,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,87,flutelevel);
   
     //Measure 7   
     cout << "\nMeasure " << measure++;   
     cout << " 1 " ;   
     delay2(nspeed);
     delay2(nspeed);      
     play_note(flutechannel,82,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,82,flutelevel);
     cout << " 2 " ;      
     play_note(flutechannel,80,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,80,flutelevel);
   
     play_note(flutechannel,78,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 3 " ;   
     delay2(nspeed);
     kill_note(flutechannel,78,flutelevel);
   
     delay2(nspeed);   
   
     play_note(flutechannel,78,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,78,flutelevel);
     cout << " 4 " ;      
     play_note(flutechannel,77,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,77,flutelevel);
   
     play_note(flutechannel,78,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,78,flutelevel);
   
     //Measure 8   
     cout << "\nMeasure " << measure++;   
     play_note(flutechannel,85,flutelevel);   
     cout << " 1 " ;      
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 2 " ;      
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 3 " ;      
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     cout << " 4 " ;      
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   

     kill_note(flutechannel,85,flutelevel);
   
     //Measure 9   
     cout << "\nMeasure " << measure++;   
     play_note(flutechannel,87,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,87,flutelevel);
   
     play_note(flutechannel,85,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,85,flutelevel);   
   
     play_note(flutechannel,83,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(flutechannel,83,flutelevel);
   
     //Measure 10   
     cout << "\nMeasure " << measure++;   
     play_note(flutechannel,89,flutelevel);   
     delay2(nspeed*6);   
     kill_note(flutechannel,89,flutelevel);   
   
     play_note(flutechannel,87,flutelevel);   
     delay2(nspeed*6);   
     kill_note(flutechannel,87,flutelevel);   
   
     play_note(flutechannel,85,flutelevel);   
     delay2(nspeed*4);   
     kill_note(flutechannel,85,flutelevel);   
   
     //Measure 11   
     cout << "\nMeasure " << measure++;   
     play_note(flutechannel,89,flutelevel);   
     delay2(nspeed*6);   
     kill_note(flutechannel,89,flutelevel);   
   
     play_note(flutechannel,87,flutelevel);   
     delay2(nspeed*6);   
     kill_note(flutechannel,87,flutelevel);   
   
     play_note(flutechannel,86,flutelevel);   
     delay2(nspeed*4);   
     kill_note(flutechannel,86,flutelevel);   
   
     //Measure 12   
     cout << "\nMeasure " << measure++;   
     play_note(flutechannel,90,flutelevel);   
     delay2(nspeed*6);   
     kill_note(flutechannel,90,flutelevel);   
   
     play_note(flutechannel,89,flutelevel);   
     delay2(nspeed*6);   
     kill_note(flutechannel,89,flutelevel);   
   
     play_note(flutechannel,87,flutelevel);   
     delay2(nspeed*4);   
     kill_note(flutechannel,87,flutelevel);   
   
     //Measure 13   
     cout << "\nMeasure " << measure++;   
     play_note(flutechannel,90,flutelevel);   
     delay2(nspeed*9);   
     kill_note(flutechannel,90,flutelevel);   
   
     nspeed = 110;   
     play_note(flutechannel,A4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,A4,flutelevel);   
   
     play_note(flutechannel,B4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,B4,flutelevel);   
   
     play_note(flutechannel,CS5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,CS5,flutelevel);   
   
     play_note(flutechannel,D5,flutelevel);   
     delay2(nspeed*4);   
     kill_note(flutechannel,D5,flutelevel);   
   
     play_note(flutechannel,D5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,D5,flutelevel);   
   
     play_note(flutechannel,D5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,D5,flutelevel);   
   
     play_note(flutechannel,CS5,flutelevel);   
     delay2(nspeed*4);   
     kill_note(flutechannel,CS5,flutelevel);   
   
     play_note(flutechannel,D5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,D5,flutelevel);   
   
     play_note(flutechannel,B4,flutelevel);   
     delay2(nspeed*10);   
     kill_note(flutechannel,B4,flutelevel);   
   
     play_note(flutechannel,B4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,B4,flutelevel);   
   
     play_note(flutechannel,GS4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,GS4,flutelevel);   
   
     play_note(flutechannel,B4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,B4,flutelevel);   
   
     play_note(flutechannel,E5,flutelevel);   
     delay2(nspeed*4);   
     kill_note(flutechannel,E5,flutelevel);   
   
     play_note(flutechannel,D5,flutelevel);   
     delay2(nspeed*4);   
     kill_note(flutechannel,D5,flutelevel);   
   
     play_note(flutechannel,CS5,flutelevel);   
     delay2(nspeed*4);   
     kill_note(flutechannel,CS5,flutelevel);   
   
     play_note(flutechannel,B4,flutelevel);   
     delay2(nspeed*4);   
     kill_note(flutechannel,B4,flutelevel);   
   
     play_note(flutechannel,C5,flutelevel);   
     delay2(nspeed*6);   
     kill_note(flutechannel,C5,flutelevel);   
   
     play_note(flutechannel,C5,flutelevel);   
     delay2(nspeed*1);   
     kill_note(flutechannel,C5,flutelevel);   
   
     play_note(flutechannel,C5,flutelevel);   
     delay2(nspeed*1);   
     kill_note(flutechannel,C5,flutelevel);   
   
     play_note(flutechannel,C5,flutelevel);   
     delay2(nspeed*3);   
     kill_note(flutechannel,C5,flutelevel);   
   
     play_note(flutechannel,B4,flutelevel);   
     delay2(nspeed*3);   
     kill_note(flutechannel,B4,flutelevel);   
   
     play_note(flutechannel,C5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,C5,flutelevel);   
   
     play_note(flutechannel,A4,flutelevel);   
     delay2(nspeed*6);   
     kill_note(flutechannel,A4,flutelevel);   
   
     play_note(flutechannel,A4,flutelevel);   
     delay2(nspeed*1);   
     kill_note(flutechannel,A4,flutelevel);   
   
     play_note(flutechannel,A4,flutelevel);   
     delay2(nspeed*1);   
     kill_note(flutechannel,A4,flutelevel);   
   
     delay2(nspeed*1);   
   
     play_note(flutechannel,A4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,A4,flutelevel);   
   
     play_note(flutechannel,B4,flutelevel);   
     delay2(nspeed*3);   
     kill_note(flutechannel,B4,flutelevel);   
   
     play_note(flutechannel,C5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(flutechannel,C5,flutelevel);   
   
     play_note(flutechannel,D5,flutelevel);   
     delay2(nspeed*16);   
     kill_note(flutechannel,D5,flutelevel);   
     delay2(nspeed*2);
     cout << "\nLET GO";
     drums(92);
}   
   
void dobass()   
{   
        if ((notes[INDEX_SPACE] == 0) && (key_table[INDEX_SPACE]==1))   
        {   
          notes[INDEX_SPACE]=1;   
          play_note(3,42,127);   
        }   
        if ((notes[INDEX_SPACE] == 1) && (key_table[INDEX_SPACE]==0))   
        {   
          kill_note(3,42,127);   
          notes[INDEX_SPACE]=0;   
        }   
   
        if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))   
        {   
          notes[INDEX_UP]=1;   
          play_note(3,41,127);   
        }   
        if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))   
        {   
          kill_note(3,41,127);   
          notes[INDEX_UP]=0;   
        }   
   
        if ((notes[INDEX_RIGHT] == 0) && (key_table[INDEX_RIGHT]==1))   
        {   
          notes[INDEX_RIGHT]=1;   
          play_note(3,39,127);   
        }   
        if ((notes[INDEX_RIGHT] == 1) && (key_table[INDEX_RIGHT]==0))   
        {   
          kill_note(3,39,127);   
          notes[INDEX_RIGHT]=0;   
        }   
   
        if ((notes[INDEX_Y] == 0) && (key_table[INDEX_Y]==1))   
        {   
          notes[INDEX_Y]=1;   
          play_note(3,38,127);   
        }   
        if ((notes[INDEX_Y] == 1) && (key_table[INDEX_Y]==0))   
        {   
          kill_note(3,38,127);   
          notes[INDEX_Y]=0;   
        }   
   
        if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))   
        {   
          notes[INDEX_DOWN]=1;   
          play_note(3,37,127);   
        }   
        if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))   
        {   
          kill_note(3,37,127);   
          notes[INDEX_DOWN]=0;   
        }   
   
        if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))   
        {   
          notes[INDEX_LEFT]=1;   
          play_note(3,36,127);   
        }   
        if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))   
        {   
          kill_note(3,36,127);   
          notes[INDEX_LEFT]=0;   
        }   
   
        if ((notes[INDEX_N] == 0) && (key_table[INDEX_N]==1))   
        {   
          notes[INDEX_N]=1;   
          play_note(3,35,127);   
        }   
   
        if ((notes[INDEX_N] == 1) && (key_table[INDEX_N]==0))   
        {   
          kill_note(3,35,127);   
          notes[INDEX_N]=0;   
        }   
   
        if ((notes[INDEX_I] == 0) && (key_table[INDEX_I]==1))   
        {   
          notes[INDEX_I]=1;   
          play_note(3,34,127);   
        }   
        if ((notes[INDEX_I] == 1) && (key_table[INDEX_I]==0))   
        {   
          kill_note(3,34,127);   
          notes[INDEX_I]=0;   
        }   
   
        if ((notes[INDEX_ENTER] == 0) && (key_table[INDEX_ENTER]==1))   
        {   
          notes[INDEX_ENTER]=1;   
          play_note(3,39,127);   
        }   
        if ((notes[INDEX_ENTER] == 1) && (key_table[INDEX_ENTER]==0))   
        {   
          kill_note(3,39,127);   
          notes[INDEX_ENTER]=0;   
        }   
   
        //old 33
        if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
        {   
          notes[INDEX_Q]=1;   
          play_note(3,33,127);   
        }   
        if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))   
        {   
          kill_note(3,33,127);   
          notes[INDEX_Q]=0;   
        }   
   
        if ((notes[INDEX_D] == 0) && (key_table[INDEX_D]==1))   
        {   
          notes[INDEX_D]=1;   
          play_note(3,44,127);   
        }   
        if ((notes[INDEX_D] == 1) && (key_table[INDEX_D]==0))   
        {   
          kill_note(3,44,127);   
          notes[INDEX_D]=0;   
        }   
   
        if ((notes[INDEX_V] == 0) && (key_table[INDEX_V]==1))   
        {   
          notes[INDEX_V]=1;   
          play_note(3,40,127);   
        }   
        if ((notes[INDEX_V] == 1) && (key_table[INDEX_V]==0))   
        {   
          kill_note(3,40,127);   
          notes[INDEX_V]=0;   
        }   
   
        if ((notes[INDEX_CTRL] == 0) && (key_table[INDEX_CTRL]==1))   
        {   
          notes[INDEX_CTRL]=1;   
          play_note(3,45,127);   
        }   
        if ((notes[INDEX_CTRL] == 1) && (key_table[INDEX_CTRL]==0))   
        {   
          kill_note(3,45,127);   
          notes[INDEX_CTRL]=0;   
        }   
   
}   
   
void wilys_castle(int speed)   
{   
   clrscr();   
   cout << "Dr. Wily's castle!";   
   cout << "\nPress ESC to quit";   
   int measure = -1;
   change_volume(2,99);
   change_program(2,98,2); //screamer!   
   //Intro drums
   play_note(10,36,127);
   delay(speed*4);
   kill_note(10,36,127);

   play_note(10,38,127);
   delay(speed*4);
   kill_note(10,38,127);

   play_note(10,36,127);
   delay(speed*4);
   kill_note(10,36,127);

   play_note(10,38,127);
   delay(speed*4);
   kill_note(10,38,127);

   play_note(10,36,127);
   delay(speed*4);
   kill_note(10,36,127);

   play_note(10,38,127);
   delay(speed*4);
   kill_note(10,38,127);

   play_note(10,36,127);
   delay(speed*4);
   kill_note(10,36,127);

   play_note(10,38,127);
   delay(speed*4);
   kill_note(10,38,127);

   measure = -1;
   change_light_level(1,50);
   change_light_level(2,75);
   change_light_level(3,25);
   change_light_level(4,50);

   while (1)
   {   
           
           if (measure == 55)
           {
              measure = -1;
           }

           if (measure == 22)
              change_volume(2,85);

           if (measure == 39)
              change_volume(2,99);
           cout << "\nMeasure " << (++measure)+1;
           play_note(10,36,127);   
   
           play_note(basschannel,bassnotes[measure][0],127);   
           if (delay_skull(speed)) break;   
           if (delay_skull(speed)) break;   
           kill_note(basschannel,bassnotes[measure][0],127);   
   
           play_note(basschannel,bassnotes[measure][1],127);   
           if (delay_skull(speed)) break;   
           kill_note(basschannel,bassnotes[measure][1],127);   
           play_note(basschannel,bassnotes[measure][2],127);   
           if (delay_skull(speed)) break;   
           kill_note(basschannel,bassnotes[measure][2],127);   
           play_note(basschannel,bassnotes[measure][3],127);   
           kill_note(10,36,127);   
           play_note(10,38,127);   
           if (delay_skull(speed)) break;   
           if (delay_skull(speed)) break;   
   
           kill_note(basschannel,bassnotes[measure][3],127);   
           play_note(basschannel,bassnotes[measure][4],127);   
   
           if (delay_skull(speed)) break;   
           kill_note(basschannel,bassnotes[measure][4],127);   
           play_note(basschannel,bassnotes[measure][5],127);   
           if (delay_skull(speed)) break;   
           kill_note(basschannel,bassnotes[measure][5],127);   
           play_note(basschannel,bassnotes[measure][6],127);   
   
           kill_note(10,38,127);   
           play_note(10,36,127);   
           if (delay_skull(speed)) break;   
           if (delay_skull(speed)) break;   
   
           kill_note(basschannel,bassnotes[measure][6],127);   
           play_note(basschannel,bassnotes[measure][7],127);   
           if (delay_skull(speed)) break;   
           kill_note(basschannel,bassnotes[measure][7],127);   
           play_note(basschannel,bassnotes[measure][8],127);   
           if (delay_skull(speed)) break;   
           kill_note(basschannel,bassnotes[measure][8],127);   
           play_note(basschannel,bassnotes[measure][9],127);   
   
           kill_note(10,36,127);   
           play_note(10,38,127);   
   
           if (delay_skull(speed)) break;   
           if (delay_skull(speed)) break;   
           kill_note(basschannel,bassnotes[measure][9],127);   
           play_note(basschannel,bassnotes[measure][10],127);   
           if (delay_skull(speed)) break;   
           kill_note(basschannel,bassnotes[measure][10],127);   
           play_note(basschannel,bassnotes[measure][11],127);   
           if (delay_skull(speed)) break;   
           kill_note(basschannel,bassnotes[measure][11],127);   
           kill_note(10,38,127);   
   }   
   wait_for_no(INDEX_ESC);   
   menu();   
}   
   
   
void menu()   
{   
 clrscr();   
 cout << "Mega Man 2" << endl;   
 cout << "Press ESC to quit...";   
 cout << "\nF1: Start the intro";   
 cout << "\nF2: Flashman";   
 cout << "\nF3: Dr. Wily's Castle";   
}   
   
void flashman(int speed)   
{   
   change_program(2,11,2); 
   clrscr();
   cout << "Flashman...";
   cout << "\nPlaying intro, tap ESC to continue on in the song...";
   for (int index=0;index<4;index++)
   {   
      play_note(10,36,127);   
      delay(speed*4);   
      kill_note(10,36,127);   
   }   
   
   while (1)   
   {   
      cout << "\nNew measure...";
      play_note(10,DS1,127);
      play_note(10,FS1,127);   
      if (delay_flash(speed*1)) break;   
      if (delay_flash(speed*1)) break;   
      kill_note(10,DS1,127);   
      play_note(10,AS1,127);   
      if (delay_flash(speed*1)) break;   
      kill_note(10,DS1,127);   
      if (delay_flash(speed*1)) break;   
      kill_note(10,AS1,127);   
   
      play_note(10,DS1,127);   
      play_note(10,FS1,127);   
      if (delay_flash(speed*1)) break;   
      if (delay_flash(speed*1)) break;   
      kill_note(10,FS1,127);   
      play_note(10,AS1,127);   
      if (delay_flash(speed*1)) break;   
      kill_note(10,DS1,127);   
      if (delay_flash(speed*1)) break;   
      kill_note(10,AS1,127);   
   
      play_note(10,DS1,127);   
      play_note(10,FS1,127);   
      if (delay_flash(speed*1)) break;   
      if (delay_flash(speed*1)) break;   
      kill_note(10,FS1,127);   
      play_note(10,AS1,127);   
      if (delay_flash(speed*1)) break;   
      kill_note(10,DS1,127);   
      if (delay_flash(speed*1)) break;   
      kill_note(10,AS1,127);   
   
      play_note(10,DS1,127);   
      play_note(10,FS1,127);   
      if (delay_flash(speed*1)) break;   
      if (delay_flash(speed*1)) break;   
      kill_note(10,FS1,127);   
      play_note(10,AS1,127);   
      if (delay_flash(speed*1)) break;   
      kill_note(10,DS1,127);   
      if (delay_flash(speed*1)) break;   
      kill_note(10,AS1,127);   
   }   
   wait_for_no(INDEX_ESC);
   cout << "\nPlaying main theme... Press ESC to end";
   for (index=0;index<4;index++)
   {
      play_note(10,D1,127);
      if (delay_flash(speed)) break;
      kill_note(10,D1,127);
   }
   int measure = 17;

   while (1)
   {
      cout << "\nMeasure " << ++measure;
      if (measure == 18) play_note(10,A2,127); else
                         play_note(10,AS1,127);
      play_note(10,C1,127);
      if (delay_flash(speed)) break;
      if (measure == 18) kill_note(10,A2,127); else
                         kill_note(10,AS1,127);
      kill_note(10,C1,127);
      if (delay_flash(speed)) break;
      if (delay_flash(speed)) break;
      if (delay_flash(speed)) break;
      play_note(10,FS1,127);
      play_note(10,D1,127);
      if (delay_flash(speed)) break;
      kill_note(10,FS1,127);
      kill_note(10,D1,127);
      if (delay_flash(speed)) break;
      if (delay_flash(speed)) break;
      play_note(10,FS1,127);
      if (delay_flash(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_flash(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_flash(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,AS1,127);
      play_note(10,C1,127);
      if (delay_flash(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,C1,127);
      if (delay_flash(speed)) break;
      play_note(10,FS1,127);
      play_note(10,D1,127);
      if (delay_flash(speed)) break;
      kill_note(10,FS1,127);
      kill_note(10,D1,127);
      if (delay_flash(speed)) break;
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_flash(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      if (delay_flash(speed)) break;
   }
   wait_for_no(INDEX_ESC);
   menu();
}
   
void metro()
{
   clrscr();
   int speed = 150;
   while (1)
   {
      cout << "\nONE";
//      sound(500);
      if (delay2(speed)==1) break;
//      nosound();
      if (delay2(speed)==1) break;

      cout << " and";
//      sound(250);
      if (delay2(speed)==1) break;
//      nosound();
      if (delay2(speed)==1) break;

      cout << " TWO";
//      sound(500);
      if (delay2(speed)==1) break;
//      nosound();
      if (delay2(speed)==1) break;

      cout << " and";
//      sound(250);
      if (delay2(speed)==1) break;
//      nosound();
      if (delay2(speed)==1) break;

      cout << " THREE";
//      sound(500);
      if (delay2(speed)==1) break;
//      nosound();
      if (delay2(speed)==1) break;

      cout << " and";
//      sound(250);
      if (delay2(speed)==1) break;
//      nosound();
      if (delay2(speed)==1) break;

      cout << " FOUR";
//      sound(500);
      if (delay2(speed)==1) break;
//      nosound();
      if (delay2(speed)==1) break;

      cout << " and";
//      sound(250);
      if (delay2(speed)==1) break;
//      nosound();
      if (delay2(speed)==1) break;
   }
}

void metro1()
{
   clrscr();
   int speed = 150;
   while (1)
   {
      cout << "\nONE";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " and";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " TWO";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " and";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " THREE";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " and";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " FOUR";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " and";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      //measure 1
      for (int index=0;index<4;index++)
      {
         cout << "\nONE";
         play_note(basschannel,FS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,FS2,127);

         cout << " and";
         play_note(basschannel,FS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,FS2,127);

         cout << " THREE";
         play_note(basschannel,FS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " FOUR";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,FS2,127);
      }

      play_note(basschannel,FS2,127);
      if (delay2(speed*8)==1) break;      
      play_note(basschannel,F2,127);
      if (delay2(speed*8)==1) break;      

      play_note(basschannel,DS2,127);
      if (delay2(speed*8)==1) break;      
      play_note(basschannel,CS2,127);
      if (delay2(speed*8)==1) break;      

      play_note(basschannel,C2,127);
      if (delay2(speed*8)==1) break;      
      play_note(basschannel,DS2,127);
      if (delay2(speed*8)==1) break;      

         cout << "\nONE";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         cout << " and";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         cout << " THREE";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " FOUR";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         //four notes
         cout << "\nONE";
         play_note(basschannel,B1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,B1,127);

         cout << " and";
         play_note(basschannel,B1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,B1,127);

         cout << " THREE";
         play_note(basschannel,B1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,B1,127);

         cout << " FOUR";
         play_note(basschannel,C2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,C2,127);


         cout << "\nONE";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         cout << " and";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         cout << " THREE";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " FOUR";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         //four notes
         cout << "\nONE";
         play_note(basschannel,AS1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,AS1,127);

         cout << " and";
         play_note(basschannel,AS1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,AS1,127);

         cout << " THREE";
         play_note(basschannel,AS1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,AS1,127);

         cout << " FOUR";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << "\nONE";
         play_note(basschannel,DS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,DS2,127);

         cout << " and";
         play_note(basschannel,DS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,DS2,127);

         cout << " THREE";
         play_note(basschannel,DS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " FOUR";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,DS2,127);

         speed = 100;
         //eigth without rest
         cout << "\nONE";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " THREE";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,A1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,A1,127);

         cout << " FOUR";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,FS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,FS2,127);

         //eigth with rest
         cout << "\nONE";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);
         if (delay2(speed)==1) break;

         cout << " THREE";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,A1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,A1,127);

         cout << " FOUR";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,FS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,FS2,127);

         //eigth without rest
         cout << "\nONE";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " THREE";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,B1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,B1,127);

         cout << " FOUR";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,GS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,GS2,127);

         //eigth with rest
         cout << "\nONE";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);
         if (delay2(speed)==1) break;

         cout << " THREE";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,B1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,B1,127);

         cout << " FOUR";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,GS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,GS2,127);

         //eigth without rest
         cout << "\nONE";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " THREE";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,C2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,C2,127);

         cout << " FOUR";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,A2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,A2,127);

         //eigth with rest
         cout << "\nONE";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);
         if (delay2(speed)==1) break;

         cout << " THREE";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,C2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,C2,127);

         cout << " FOUR";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,A2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         kill_note(basschannel,A2,127);

   }
}

void metro2()
{
   clrscr();
   int speed = 150;
   while (1)
   {
      cout << "\nONE";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " and";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " TWO";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " and";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " THREE";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " and";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " FOUR";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      cout << " and";
      if (delay2(speed)==1) break;
      if (delay2(speed)==1) break;

      //measure 1
      for (int index=0;index<4;index++)
      {
         cout << "\nONE";
         play_note(basschannel,FS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,FS2,127);

         cout << " and";
         play_note(basschannel,FS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,FS2,127);

         cout << " THREE";
         play_note(basschannel,FS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " FOUR";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,FS2,127);
      }

      play_note(basschannel,FS2,127);
      if (delay2(speed*8)==1) break;      
      play_note(basschannel,F2,127);
      if (delay2(speed*8)==1) break;      

      play_note(basschannel,DS2,127);
      if (delay2(speed*8)==1) break;      
      play_note(basschannel,CS2,127);
      if (delay2(speed*8)==1) break;      

      play_note(basschannel,C2,127);
      if (delay2(speed*8)==1) break;      
      play_note(basschannel,DS2,127);
      if (delay2(speed*8)==1) break;      

         cout << "\nONE";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         cout << " and";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         cout << " THREE";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " FOUR";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         //four notes
         cout << "\nONE";
         play_note(basschannel,B1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,B1,127);

         cout << " and";
         play_note(basschannel,B1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,B1,127);

         cout << " THREE";
         play_note(basschannel,B1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,B1,127);

         cout << " FOUR";
         play_note(basschannel,C2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,C2,127);


         cout << "\nONE";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         cout << " and";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         cout << " THREE";
         play_note(basschannel,CS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " FOUR";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,CS2,127);

         //four notes
         cout << "\nONE";
         play_note(basschannel,AS1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,AS1,127);

         cout << " and";
         play_note(basschannel,AS1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,AS1,127);

         cout << " THREE";
         play_note(basschannel,AS1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,AS1,127);

         cout << " FOUR";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << "\nONE";
         play_note(basschannel,DS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,DS2,127);

         cout << " and";
         play_note(basschannel,DS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,DS2,127);

         cout << " THREE";
         play_note(basschannel,DS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " FOUR";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,DS2,127);

         speed = 125;
         //eigth without rest
         cout << "\nONE";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " THREE";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,A1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,A1,127);

         cout << " FOUR";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,FS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,FS2,127);

         //eigth with rest
         cout << "\nONE";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);
         if (delay2(speed)==1) break;

         cout << " THREE";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,A1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,A1,127);

         cout << " FOUR";
         play_note(basschannel,D2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,D2,127);

         cout << " and";
         play_note(basschannel,FS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,FS2,127);

         //eigth without rest
         cout << "\nONE";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " THREE";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,B1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,B1,127);

         cout << " FOUR";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,GS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,GS2,127);

         //eigth with rest
         cout << "\nONE";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);
         if (delay2(speed)==1) break;

         cout << " THREE";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,B1,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,B1,127);

         cout << " FOUR";
         play_note(basschannel,E2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,E2,127);

         cout << " and";
         play_note(basschannel,GS2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,GS2,127);

         //eigth without rest
         cout << "\nONE";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " THREE";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,C2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,C2,127);

         cout << " FOUR";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,A2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,A2,127);

         //eigth with rest
         cout << "\nONE";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " TWO";
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         cout << " and";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);
         if (delay2(speed)==1) break;

         cout << " THREE";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,C2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,C2,127);

         cout << " FOUR";
         play_note(basschannel,F2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;
         kill_note(basschannel,F2,127);

         cout << " and";
         play_note(basschannel,A2,127);
         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         if (delay2(speed)==1) break;
         if (delay2(speed)==1) break;

         kill_note(basschannel,A2,127);
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
 for (index=0;index<127;index++)   
  notes[index] = 0;   
   
 for (index=0;index<12;index++)   
    bassnotes[0][index] = CS2;   
 for (index=0;index<12;index++)   
    bassnotes[1][index] = CS2;   
 for (index=0;index<12;index++)   
    bassnotes[2][index] = A2;   
 for (index=0;index<12;index++)   
    bassnotes[3][index] = A2;   
 for (index=0;index<12;index++)   
    bassnotes[4][index] = B2;   
 for (index=0;index<12;index++)   
    bassnotes[5][index] = B2;   
 for (index=0;index<12;index++)   
    bassnotes[6][index] = CS2;   
 for (index=0;index<12;index++)   
    bassnotes[7][index] = CS2;   
    bassnotes[7][10] = B2;       
    bassnotes[7][11] = CS2;   
   
 for (int measure=8;measure<16;measure++)   
  for (int note=0;note<12;note++)   
  bassnotes[measure][note] = bassnotes[measure-8][note];   
   
 for (index=0;index<12;index++)   
    bassnotes[16][index] = D2;   
 for (index=0;index<12;index++)   
    bassnotes[17][index] = D2;   
   
 for (index=0;index<12;index++)   
    bassnotes[18][index] = CS2;   
 for (index=0;index<12;index++)   
    bassnotes[19][index] = CS2;   
   
 for (index=0;index<12;index++)   
    bassnotes[20][index] = D2;   
 for (index=0;index<12;index++)   
    bassnotes[21][index] = D2;   
   
 for (index=0;index<12;index++)   
    bassnotes[22][index] = B2;   
 for (index=0;index<12;index++)   
    bassnotes[23][index] = C2;   
   
 for (index=0;index<24;index++)
      for (int index1=0;index1<12;index1++)
          bassnotes[24+index][index1] = bassnotes[index][index1];

 for (index=0;index<12;index++)
    bassnotes[48][index] = A2;   
   
 for (index=0;index<11;index++)   
    bassnotes[49][index] = B2;   
    bassnotes[49][11] = CS2;   
   
 for (index=0;index<12;index++)   
    bassnotes[50][index] = 0;   
    bassnotes[50][0] = CS2;   
    bassnotes[50][3] = CS2;   
    bassnotes[50][4] = DS2;   
    bassnotes[50][6] = E2;   
    bassnotes[50][9] = DS2;   
    bassnotes[50][11] = CS2;   
   
 for (index=0;index<12;index++)   
    bassnotes[51][index] = 0;   
    bassnotes[51][0] = CS2;   
    bassnotes[51][3] = CS2;   
    bassnotes[51][4] = DS2;   
    bassnotes[51][6] = E2;   
    bassnotes[51][9] = DS2;   
//  bassnotes[51][11] = CS1;   
   
 for (index=0;index<12;index++)   
    bassnotes[52][index] = A2;   
   
 for (index=0;index<12;index++)   
    bassnotes[53][index] = B2;   
   
 for (index=0;index<12;index++)   
    bassnotes[54][index] = CS2;   
   
 for (index=0;index<12;index++)   
    bassnotes[55][index] = CS2;   
   
 for (index=0;index<8;index++)
    drumbassnotes[22][index] = C2;

 for (index=0;index<8;index++)
    drumbassnotes[23][index] = C2;

 for (index=0;index<8;index++)
    drumbassnotes[24][index] = C2;

 for (index=0;index<8;index++)
    drumbassnotes[25][index] = G2;

 for (index=0;index<8;index++)
    drumbassnotes[26][index] = C2;

 for (index=0;index<8;index++)
    drumbassnotes[27][index] = C2;

 for (index=0;index<4;index++)
    drumbassnotes[28][index] = GS1;
 for (index=4;index<8;index++)
    drumbassnotes[28][index] = AS1;

 for (index=0;index<8;index++)
    drumbassnotes[29][index] = C2;
 for (index=0;index<8;index++)
    drumbassnotes[30][index] = C2;
 for (index=0;index<8;index++)
    drumbassnotes[31][index] = C2;
 for (index=0;index<8;index++)
    drumbassnotes[32][index] = C2;
 for (index=0;index<8;index++)
    drumbassnotes[33][index] = G2;

 for (index=0;index<8;index++)
    drumbassnotes[34][index] = C2;
 for (index=0;index<8;index++)
    drumbassnotes[35][index] = C2;

 for (index=0;index<4;index++)
    drumbassnotes[36][index] = GS1;
 for (index=4;index<8;index++)
    drumbassnotes[36][index] = AS1;

 for (index=0;index<8;index++)
    drumbassnotes[37][index] = C2;
   change_volume(2,99); //old 70
   change_volume(4,85);
   mix_mode();
   menu();
   while (1)   
   {   
      dobass();   
      //delay_flash(1);
      if (key_table[INDEX_F1])
      {
         go();
         change_volume(2,70);
         all_lights_off(0);
         change_light_level(3,127);
      }
      if (key_table[INDEX_F2])
         flashman(115);
      if (key_table[INDEX_F3])
      {
         wilys_castle(85);
         all_lights_off(0);
         change_light_level(3,127);
      }
      if (key_table[INDEX_UP])
         metro1();
      if (key_table[INDEX_9])
         drums(92);
      if (key_table[INDEX_ESC])
         break;
   }   
   change_volume(2,99);
   Exit_MIDI();
   kill_keyboard();   
   clrscr();   
   cout << "Hope Mega Man went well!";   
}
