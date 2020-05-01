//QWER
//QWET
//WETY
//ETYU
//ASDF
//SFGH
//FGHU

#include <dos.h>
#include <conio.h>
#include "keyboard.h"
#include "midi.h"
#include "lights.h"

#define drumlevel 127
#define drumchannel 10

#define padchannel 2
#define basschannel 3
#define chordchannel 4
#define guitarchannel 5

#define padlevel 127
#define basslevel 127
#define chordvelocity 127

#define newlevel 127
#define newchannel 6

int guitarlevel = 100;

int speed = 80;

int bassnotes[48][8];

//F1 F4 F1 F4 F5 F6 F5 F7
//F8 F9 F10 F9 F11

//G4 D#4
void playchord1(char channel, char velocity)
{
        play_note(channel,79,velocity);
        play_note(channel,75,velocity);
}

void killchord1(char channel, char velocity)
{
        kill_note(channel,79,velocity);
        kill_note(channel,75,velocity);
}

//F4 A4
void playchord2(char channel, char velocity)
{
        play_note(channel,77,velocity);
        play_note(channel,81,velocity);
}

void killchord2(char channel, char velocity)
{
        kill_note(channel,77,velocity);
        kill_note(channel,81,velocity);
}

//G4 A#4
void playchord3(char channel, char velocity)
{
        play_note(channel,79,velocity);
        play_note(channel,82,velocity);
}

void killchord3(char channel, char velocity)
{
        kill_note(channel,79,velocity);
        kill_note(channel,82,velocity);
}

//C4 D#4
void playchord4(char channel, char velocity)
{
        play_note(channel,75,velocity);
        play_note(channel,72,velocity);
}

void killchord4(char channel, char velocity)
{
        kill_note(channel,75,velocity);
        kill_note(channel,72,velocity);
}

//F4 G#4
void playchord5(char channel, char velocity)
{
        play_note(channel,77,velocity);
        play_note(channel,79,velocity);
}

void killchord5(char channel, char velocity)
{
        kill_note(channel,77,velocity);
        kill_note(channel,79,velocity);
}

//C#4 F4
void playchord6(char channel, char velocity)
{
        play_note(channel,77,velocity);
        play_note(channel,73,velocity);
}

void killchord6(char channel, char velocity)
{
        kill_note(channel,77,velocity);
        kill_note(channel,73,velocity);
}

//A#3 D4
void playchord7(char channel, char velocity)
{
        play_note(channel,74,velocity);
        play_note(channel,70,velocity);
}

void killchord7(char channel, char velocity)
{
        kill_note(channel,74,velocity);
        kill_note(channel,70,velocity);
}

//8: F#4 A#4
void playchord8(char channel, char velocity)
{
        play_note(channel,78,velocity);
        play_note(channel,82,velocity);
}

void killchord8(char channel, char velocity)
{
        kill_note(channel,78,velocity);
        kill_note(channel,82,velocity);
}

//9: D#4 F#4
void playchord9(char channel, char velocity)
{
        play_note(channel,75,velocity);
        play_note(channel,78,velocity);
}

void killchord9(char channel, char velocity)
{
        kill_note(channel,75,velocity);
        kill_note(channel,78,velocity);
}

//10: F#3 A#3
void playchord10(char channel, char velocity)
{
        play_note(channel,66,velocity);
        play_note(channel,70,velocity);
}

void killchord10(char channel, char velocity)
{
        kill_note(channel,66,velocity);
        kill_note(channel,70,velocity);
}

//11: C#4 A4
void playchord11(char channel, char velocity)
{
        play_note(channel,73,velocity);
        play_note(channel,81,velocity);
}

void killchord11(char channel, char velocity)
{
        kill_note(channel,73,velocity);
        kill_note(channel,81,velocity);
}

void dostuff()
{
   if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
   {
      notes[INDEX_F1]=1;
      playchord1(chordchannel,chordvelocity);
   }

   if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
   {
      killchord1(chordchannel,chordvelocity);
      notes[INDEX_F1]=0;
   }

   if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
   {
      notes[INDEX_F2]=1;
      playchord2(chordchannel,chordvelocity);
   }

   if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
   {
      killchord2(chordchannel,chordvelocity);
      notes[INDEX_F2]=0;
   }

   if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
   {
      notes[INDEX_F3]=1;
      playchord3(chordchannel,chordvelocity);
   }

   if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
   {
      killchord3(chordchannel,chordvelocity);
      notes[INDEX_F3]=0;
   }

   if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
   {
      notes[INDEX_F4]=1;
      playchord4(chordchannel,chordvelocity);
   }

   if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
   {
      killchord4(chordchannel,chordvelocity);
      notes[INDEX_F4]=0;
   }

   if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
   {
      notes[INDEX_F5]=1;
      playchord5(chordchannel,chordvelocity);
   }

   if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
   {
      killchord5(chordchannel,chordvelocity);
      notes[INDEX_F5]=0;
   }

   if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
   {
      notes[INDEX_F6]=1;
      playchord6(chordchannel,chordvelocity);
   }

   if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
   {
      killchord6(chordchannel,chordvelocity);
      notes[INDEX_F6]=0;
   }

   if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
   {
      notes[INDEX_F7]=1;
      playchord7(chordchannel,chordvelocity);
   }

   if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
   {
      killchord7(chordchannel,chordvelocity);
      notes[INDEX_F7]=0;
   }

   if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
   {
      notes[INDEX_F8]=1;
      playchord8(chordchannel,chordvelocity);
   }

   if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))
   {
      killchord8(chordchannel,chordvelocity);
      notes[INDEX_F8]=0;
   }

   if ((notes[INDEX_F9] == 0) && (key_table[INDEX_F9]==1))
   {
      notes[INDEX_F9]=1;
      playchord9(chordchannel,chordvelocity);
   }

   if ((notes[INDEX_F9] == 1) && (key_table[INDEX_F9]==0))
   {
      killchord9(chordchannel,chordvelocity);
      notes[INDEX_F9]=0;
   }

   if ((notes[INDEX_F10] == 0) && (key_table[INDEX_F10]==1))
   {
      notes[INDEX_F10]=1;
      playchord10(chordchannel,chordvelocity);
   }

   if ((notes[INDEX_F10] == 1) && (key_table[INDEX_F10]==0))
   {
      killchord10(chordchannel,chordvelocity);
      notes[INDEX_F10]=0;
   }

   if ((notes[INDEX_F11] == 0) && (key_table[INDEX_F11]==1))
   {
      notes[INDEX_F11]=1;
      playchord11(chordchannel,chordvelocity);
   }

   if ((notes[INDEX_F11] == 1) && (key_table[INDEX_F11]==0))
   {
      killchord11(chordchannel,chordvelocity);
      notes[INDEX_F11]=0;
   }

   if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
   {
      notes[INDEX_Q]=1;
      play_note(newchannel,91,newlevel);
   }

   if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))
   {
      kill_note(newchannel,91,newlevel);
      notes[INDEX_Q]=0;
   }

   if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
   {
      notes[INDEX_W]=1;
      play_note(newchannel,93,newlevel);
   }

   if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))
   {
      kill_note(newchannel,93,newlevel);
      notes[INDEX_W]=0;
   }

   if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
   {
      notes[INDEX_E]=1;
      play_note(newchannel,94,newlevel);
   }

   if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))
   {
      kill_note(newchannel,94,newlevel);
      notes[INDEX_E]=0;
   }

   if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))
   {
      kill_note(newchannel,96,newlevel);
      notes[INDEX_R]=0;
   }

   if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
   {
      notes[INDEX_R]=1;
      play_note(newchannel,96,newlevel);
   }

   if ((notes[INDEX_T] == 1) && (key_table[INDEX_T]==0))
   {
      kill_note(newchannel,98,newlevel);
      notes[INDEX_T]=0;
   }

   if ((notes[INDEX_T] == 0) && (key_table[INDEX_T]==1))
   {
      notes[INDEX_T]=1;
      play_note(newchannel,98,newlevel);
   }

   if ((notes[INDEX_Y] == 1) && (key_table[INDEX_Y]==0))
   {
      kill_note(newchannel,99,newlevel);
      notes[INDEX_Y]=0;
   }

   if ((notes[INDEX_Y] == 0) && (key_table[INDEX_Y]==1))
   {
      notes[INDEX_Y]=1;
      play_note(newchannel,99,newlevel);
   }

   if ((notes[INDEX_U] == 1) && (key_table[INDEX_U]==0))
   {
      kill_note(newchannel,101,newlevel);
      notes[INDEX_U]=0;
   }

   if ((notes[INDEX_U] == 0) && (key_table[INDEX_U]==1))
   {
      notes[INDEX_U]=1;
      play_note(newchannel,101,newlevel);
   }

   if ((notes[INDEX_A] == 1) && (key_table[INDEX_A]==0))
   {
      kill_note(newchannel,80,newlevel);
      notes[INDEX_A]=0;
   }

   if ((notes[INDEX_A] == 0) && (key_table[INDEX_A]==1))
   {
      notes[INDEX_A]=1;
      play_note(newchannel,80,newlevel);
   }

   if ((notes[INDEX_S] == 1) && (key_table[INDEX_S]==0))
   {
      kill_note(newchannel,85,newlevel);
      notes[INDEX_S]=0;
   }

   if ((notes[INDEX_S] == 0) && (key_table[INDEX_S]==1))
   {
      notes[INDEX_S]=1;
      play_note(newchannel,85,newlevel);
   }

   if ((notes[INDEX_D] == 1) && (key_table[INDEX_D]==0))
   {
      kill_note(newchannel,87,newlevel);
      notes[INDEX_D]=0;
   }

   if ((notes[INDEX_D] == 0) && (key_table[INDEX_D]==1))
   {
      notes[INDEX_D]=1;
      play_note(newchannel,87,newlevel);
   }

   if ((notes[INDEX_F] == 1) && (key_table[INDEX_F]==0))
   {
      kill_note(newchannel,89,newlevel);
      notes[INDEX_F]=0;
   }

   if ((notes[INDEX_F] == 0) && (key_table[INDEX_F]==1))
   {
      notes[INDEX_F]=1;
      play_note(newchannel,89,newlevel);
   }

   if ((notes[INDEX_G] == 1) && (key_table[INDEX_G]==0))
   {
      kill_note(newchannel,92,newlevel);
      notes[INDEX_G]=0;
   }

   if ((notes[INDEX_G] == 0) && (key_table[INDEX_G]==1))
   {
      notes[INDEX_G]=1;
      play_note(newchannel,92,newlevel);
   }

   if ((notes[INDEX_H] == 1) && (key_table[INDEX_H]==0))
   {
      kill_note(newchannel,97,newlevel);
      notes[INDEX_H]=0;
   }

   if ((notes[INDEX_H] == 0) && (key_table[INDEX_H]==1))
   {
      notes[INDEX_H]=1;
      play_note(newchannel,97,newlevel);
   }

   if ((notes[INDEX_I] == 1) && (key_table[INDEX_I]==0))
   {
      kill_note(newchannel,102,newlevel);
      notes[INDEX_I]=0;
   }

   if ((notes[INDEX_I] == 0) && (key_table[INDEX_I]==1))
   {
      notes[INDEX_I]=1;
      play_note(newchannel,102,newlevel);
   }

   if ((notes[INDEX_SPACE] == 1) && (key_table[INDEX_SPACE]==0))
   {
      kill_note(newchannel,B5,newlevel);
      notes[INDEX_SPACE]=0;
   }

   if ((notes[INDEX_SPACE] == 0) && (key_table[INDEX_SPACE]==1))
   {
      notes[INDEX_SPACE]=1;
      play_note(newchannel,B5,newlevel);
   }

   if ((notes[INDEX_ENTER] == 1) && (key_table[INDEX_ENTER]==0))
   {
      kill_note(newchannel,FS5,newlevel);
      notes[INDEX_ENTER]=0;
   }

   if ((notes[INDEX_ENTER] == 0) && (key_table[INDEX_ENTER]==1))
   {
      notes[INDEX_ENTER]=1;
      play_note(newchannel,FS5,newlevel);
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

int mutecity()
{
        clrscr();
        cout << "Mute City!";
        int measure = 0;
        speed = 80;

        cout << "\nMeasure: " << ++measure;

        //16 measures
        play_note(drumchannel,38,drumlevel);
        if (delay1(speed)) return 0;
        kill_note(drumchannel,38,drumlevel);
        play_note(drumchannel,43,drumlevel);
        if (delay1(speed)) return 0;
        kill_note(drumchannel,43,drumlevel);
        play_note(drumchannel,53,drumlevel);
        if (delay1(speed)) return 0;
        kill_note(drumchannel,53,drumlevel);
        play_note(drumchannel,35,drumlevel);
        play_note(drumchannel,57,drumlevel);
        play_note(basschannel,48,basslevel);
        if (delay1(speed)) return 0;

        kill_note(drumchannel,35,drumlevel);
        kill_note(drumchannel,57,drumlevel);
        int count = 0;
        while (1)
        {
        while (1)
        {
             cout << "\nMeasure: " << ++measure;
             cout << " one ";
//             mix_name("F Zero 1 ");
//             mix_mode();

             if (measure != 2)
                play_note(basschannel,48,basslevel);

             if (measure == 10)
             {
                play_note(drumchannel,35,drumlevel);
                play_note(drumchannel,57,drumlevel);
                play_note(guitarchannel,84,guitarlevel);
             }

             if (measure == 14)
             {
                play_note(drumchannel,35,drumlevel);
                play_note(drumchannel,42,drumlevel);
             }

             if (delay1(speed)) break;
             if (delay1(speed)) break;

             if (measure == 10)
             {
                kill_note(drumchannel,35,drumlevel);
                kill_note(drumchannel,57,drumlevel);
             }

             if (measure == 14)
             {
                kill_note(drumchannel,35,drumlevel);
                kill_note(drumchannel,42,drumlevel);
                kill_note(guitarchannel,84,guitarlevel);
             }
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " two ";
//             mix_name("F Zero 2 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " three ";
//             mix_name("F Zero 3 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " four ";
//             mix_name("F Zero 4 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             kill_note(basschannel,48,basslevel);

             cout << "\nMeasure: " << ++measure;
             cout << " one ";
//             mix_name("F Zero 1 ");
//             mix_mode();
             play_note(basschannel,53,basslevel);
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " two ";
//             mix_name("F Zero 2 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " three ";
//             mix_name("F Zero 3 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " four ";
//             mix_name("F Zero 4 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;

             kill_note(basschannel,53,basslevel);

             if (measure == 15) break;

             cout << "\nMeasure: " << ++measure;
//             if (measure == 12)
//              after_touch(guitarchannel,84,guitarlevel);
             play_note(basschannel,51,basslevel);
             cout << " one ";
//             mix_name("F Zero 1 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " two ";
//             mix_name("F Zero 2 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " three ";
//             mix_name("F Zero 3 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " four ";
//             mix_name("F Zero 4 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;

             kill_note(basschannel,51,basslevel);

             cout << "\nMeasure: " << ++measure;
             play_note(basschannel,53,basslevel);
             cout << " one ";
//             mix_name("F Zero 1 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " two ";
//             mix_name("F Zero 2 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " three ";
//             mix_name("F Zero 3 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             kill_note(basschannel,53,basslevel);
             play_note(basschannel,50,basslevel);

             if (delay1(speed)) break;
             if (delay1(speed)) break;
             cout << " four ";
//             mix_name("F Zero 4 ");
//             mix_mode();
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             kill_note(basschannel,50,basslevel);

             if (measure == 13)
             {
                play_note(drumchannel,46,drumlevel);
                play_note(drumchannel,35,drumlevel);
             }
             play_note(basschannel,49,basslevel);
             if (delay1(speed)) break;
             if (delay1(speed)) break;
             kill_note(basschannel,49,basslevel);
             if (measure == 13)
             {
                kill_note(drumchannel,46,drumlevel);
                kill_note(drumchannel,35,drumlevel);
             }
        }
        speed = 75;
        cout << "\nFASTER!";
        cout << "\nMeasure: " << ++measure;
        play_note(basschannel,46,basslevel);
        play_note(drumchannel,35,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(drumchannel,35,drumlevel);
        kill_note(basschannel,46,basslevel);
        play_note(basschannel,46,basslevel);
        if (delay1(speed*2)) return 0;
        kill_note(basschannel,46,basslevel);
        play_note(basschannel,46,basslevel);
        play_note(drumchannel,35,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(drumchannel,35,drumlevel);
        kill_note(basschannel,46,basslevel);
        play_note(basschannel,46,basslevel);
        if (delay1(speed*2)) return 0;
        kill_note(basschannel,46,basslevel);
        play_note(basschannel,46,basslevel);
        play_note(drumchannel,35,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(drumchannel,35,drumlevel);
        kill_note(basschannel,46,basslevel);
        play_note(basschannel,46,basslevel);
        if (delay1(speed*2)) return 0;
        kill_note(basschannel,46,basslevel);
        play_note(basschannel,46,basslevel);
        play_note(drumchannel,35,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(drumchannel,35,drumlevel);
        kill_note(basschannel,46,basslevel);
        play_note(basschannel,48,basslevel);
        if (delay1(speed*2)) return 0;
        kill_note(basschannel,48,basslevel);

        cout << "\nMeasure: " << ++measure;
        play_note(basschannel,48,basslevel);
        play_note(drumchannel,35,drumlevel);
        play_note(drumchannel,42,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(drumchannel,35,drumlevel);
        kill_note(drumchannel,42,drumlevel);
        kill_note(basschannel,48,basslevel);
        play_note(basschannel,48,basslevel);
        if (delay1(speed*2)) return 0;
        kill_note(basschannel,48,basslevel);
        play_note(basschannel,48,basslevel);
        play_note(drumchannel,35,drumlevel);
        play_note(drumchannel,42,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(drumchannel,35,drumlevel);
        kill_note(drumchannel,42,drumlevel);
        kill_note(basschannel,48,basslevel);
        play_note(basschannel,48,basslevel);
        if (delay1(speed*2)) return 0;
        kill_note(basschannel,48,basslevel);
        play_note(basschannel,48,basslevel);
        play_note(drumchannel,35,drumlevel);
        play_note(drumchannel,42,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(drumchannel,35,drumlevel);
        kill_note(drumchannel,42,drumlevel);
        kill_note(basschannel,48,basslevel);
        play_note(basschannel,43,basslevel);
        play_note(drumchannel,35,drumlevel);
        if (delay1(speed)) return 0;
        kill_note(drumchannel,35,drumlevel);
        play_note(drumchannel,35,drumlevel);
        if (delay1(speed)) return 0;
        kill_note(drumchannel,35,drumlevel);
        kill_note(basschannel,43,basslevel);
        play_note(basschannel,51,basslevel);
        play_note(drumchannel,57,drumlevel);
        play_note(drumchannel,38,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(basschannel,51,basslevel);
        kill_note(drumchannel,57,drumlevel);
        kill_note(drumchannel,38,drumlevel);
        play_note(basschannel,46,basslevel);
        if (delay1(speed*2)) return 0;
        kill_note(basschannel,46,basslevel);

        while (1)
        {
        cout << "\nMeasure: " << ++measure;
        play_note(drumchannel,35,drumlevel);
        play_note(drumchannel,46,drumlevel);
        if ((measure == 18) || (measure == 26) || (measure == 34) || (measure == 42) || (measure == 46))
           play_note(drumchannel,57,drumlevel);
        play_note(basschannel,bassnotes[measure][0],basslevel);
        if (delay1(speed)) return 0;
        if (delay1(speed)) return 0;
        if ((measure == 18) || (measure == 26) || (measure == 34) || (measure == 42) || (measure == 46))
           kill_note(drumchannel,57,drumlevel);
        kill_note(basschannel,bassnotes[measure][0],basslevel);
        play_note(basschannel,bassnotes[measure][1],basslevel);
        if (delay1(speed)) return 0;
        kill_note(drumchannel,35,drumlevel);
        kill_note(drumchannel,46,drumlevel);
//        if (measure == 18) kill_note(drumchannel,49,drumlevel);
        if (delay1(speed)) return 0;
        kill_note(basschannel,bassnotes[measure][1],basslevel);
        play_note(basschannel,bassnotes[measure][2],basslevel);
        play_note(drumchannel,46,drumlevel);
        play_note(drumchannel,38,drumlevel);
        if (delay1(speed)) return 0;
        if (delay1(speed)) return 0;
        kill_note(basschannel,bassnotes[measure][2],basslevel);
        play_note(basschannel,bassnotes[measure][3],basslevel);
        if (!(measure % 2))
        {
           kill_note(drumchannel,46,drumlevel);
           kill_note(drumchannel,38,drumlevel);
           play_note(drumchannel,35,drumlevel);
        }
        if (delay1(speed)) return 0;
        if (measure % 2)
        {
           kill_note(drumchannel,46,drumlevel);
           kill_note(drumchannel,38,drumlevel);
        } else kill_note(drumchannel,35,drumlevel);
        if (delay1(speed)) return 0;
        kill_note(basschannel,bassnotes[measure][3],basslevel);
        play_note(basschannel,bassnotes[measure][4],basslevel);
        play_note(drumchannel,46,drumlevel);

        if (delay1(speed)) return 0;
        if (delay1(speed)) return 0;
        kill_note(drumchannel,46,drumlevel);
        play_note(drumchannel,35,drumlevel);
        kill_note(basschannel,bassnotes[measure][4],basslevel);
        play_note(basschannel,bassnotes[measure][5],basslevel);
        if (delay1(speed)) return 0;
        if (delay1(speed)) return 0;
        kill_note(drumchannel,35,drumlevel);
        play_note(drumchannel,38,drumlevel);
        play_note(drumchannel,46,drumlevel);
        kill_note(basschannel,bassnotes[measure][5],basslevel);
        play_note(basschannel,bassnotes[measure][6],basslevel);
        if (delay1(speed)) return 0;
        if (delay1(speed)) return 0;
        kill_note(basschannel,bassnotes[measure][6],basslevel);
        play_note(basschannel,bassnotes[measure][7],basslevel);
        if (delay1(speed)) return 0;
        kill_note(drumchannel,38,drumlevel);
        kill_note(drumchannel,46,drumlevel);
        if (delay1(speed)) return 0;
        kill_note(basschannel,bassnotes[measure][7],basslevel);
        if (measure == 46) break;
        }
          measure = 1;
          count++;
          if (count == 2) break;
          play_note(basschannel,48,basslevel);
        }
        return 1;
}

void showinfo()
{
   clrscr();
   cout << "F-Zero";
   wait_for_no(INDEX_ESC);
   cout << "\n[1    ]: Mute City";
   cout << "\nESC: Quit";
}

void main()
{
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
//      change_program(padchannel,92,3);
        change_program(drumchannel,120,1);
        change_program(chordchannel,90,1); //92 1
        change_program(padchannel,93,0); //94 4
        change_program(basschannel,45,1);
        change_program(guitarchannel,90,1);   //old 29 4
        change_program(newchannel,88,4);
        change_program(1,90,3);
        mix_name("F Zero   ");
        mix_mode();
        showinfo();
        int index;

        bassnotes[18][0] = 48;
        bassnotes[18][1] = 48;
        bassnotes[18][2] = 48;
        bassnotes[18][3] = 48;
        bassnotes[18][4] = 48;
        bassnotes[18][5] = 50;
        bassnotes[18][6] = 46;
        bassnotes[18][7] = 43;
        bassnotes[19][0] = 43;
        bassnotes[19][1] = 43;
        bassnotes[19][2] = 43;
        bassnotes[19][3] = 43;
        bassnotes[19][4] = 43;
        bassnotes[19][5] = 43;
        bassnotes[19][6] = 43;
        bassnotes[19][7] = 43;

        bassnotes[22][0] = 49;
        bassnotes[22][1] = 49;
        bassnotes[22][2] = 49;
        bassnotes[22][3] = 49;
        bassnotes[22][4] = 49;
        bassnotes[22][5] = 51;
        bassnotes[22][6] = 49;
        bassnotes[22][7] = 44;
        bassnotes[23][0] = 44;
        bassnotes[23][1] = 44;
        bassnotes[23][2] = 44;
        bassnotes[23][3] = 44;
        bassnotes[23][4] = 44;
        bassnotes[23][5] = 44;
        bassnotes[23][6] = 44;
        bassnotes[23][7] = 44;

        for (index=0;index<8;index++)
        {
           bassnotes[20][index] = bassnotes[18][index];
           bassnotes[21][index] = bassnotes[19][index];

           bassnotes[26][index] = bassnotes[18][index];
           bassnotes[27][index] = bassnotes[19][index];
           bassnotes[28][index] = bassnotes[18][index];
           bassnotes[29][index] = bassnotes[19][index];

           bassnotes[34][index] = bassnotes[18][index];
           bassnotes[35][index] = bassnotes[19][index];
           bassnotes[36][index] = bassnotes[18][index];
           bassnotes[37][index] = bassnotes[19][index];

        }

        for (index=0;index<8;index++)
        {
           bassnotes[24][index] = bassnotes[22][index];
           bassnotes[25][index] = bassnotes[23][index];

           bassnotes[30][index] = bassnotes[22][index];
           bassnotes[31][index] = bassnotes[23][index];
           bassnotes[32][index] = bassnotes[22][index];
           bassnotes[33][index] = bassnotes[23][index];
        }


        bassnotes[24][0] = 49;
        bassnotes[24][1] = 49;
        bassnotes[24][2] = 49;
        bassnotes[24][3] = 49;
        bassnotes[24][4] = 49;
        bassnotes[24][5] = 51;
        bassnotes[24][6] = 49;
        bassnotes[24][7] = 44;
        bassnotes[25][0] = 44;
        bassnotes[25][1] = 44;
        bassnotes[25][2] = 44;
        bassnotes[25][3] = 44;
        bassnotes[25][4] = 44;
        bassnotes[25][5] = 44;
        bassnotes[25][6] = 44;
        bassnotes[25][7] = 44;

        bassnotes[26][0] = 48;
        bassnotes[26][1] = 48;
        bassnotes[26][2] = 48;
        bassnotes[26][3] = 48;
        bassnotes[26][4] = 48;
        bassnotes[26][5] = 50;
        bassnotes[26][6] = 46;
        bassnotes[26][7] = 43;
        bassnotes[27][0] = 43;
        bassnotes[27][1] = 43;
        bassnotes[27][2] = 43;
        bassnotes[27][3] = 43;
        bassnotes[27][4] = 43;
        bassnotes[27][5] = 43;
        bassnotes[27][6] = 43;
        bassnotes[27][7] = 43;

        bassnotes[28][0] = 48;
        bassnotes[28][1] = 48;
        bassnotes[28][2] = 48;
        bassnotes[28][3] = 48;
        bassnotes[28][4] = 48;
        bassnotes[28][5] = 50;
        bassnotes[28][6] = 46;
        bassnotes[28][7] = 43;
        bassnotes[29][0] = 43;
        bassnotes[29][1] = 43;
        bassnotes[29][2] = 43;
        bassnotes[29][3] = 43;
        bassnotes[29][4] = 43;
        bassnotes[29][5] = 43;
        bassnotes[29][6] = 43;
        bassnotes[29][7] = 43;

        bassnotes[38][0] = 47;
        bassnotes[38][1] = 47;
        bassnotes[38][2] = 47;
        bassnotes[38][3] = 47;
        bassnotes[38][4] = 47;
        bassnotes[38][5] = 49;
        bassnotes[38][6] = 47;
        bassnotes[38][7] = 42;
        bassnotes[39][0] = 42;
        bassnotes[39][1] = 47;
        bassnotes[39][2] = 47;
        bassnotes[39][3] = 47;
        bassnotes[39][4] = 47;
        bassnotes[39][5] = 49;
        bassnotes[39][6] = 47;
        bassnotes[39][7] = 42;
        bassnotes[40][0] = 42;
        bassnotes[40][1] = 47;
        bassnotes[40][2] = 47;
        bassnotes[40][3] = 47;
        bassnotes[40][4] = 47;
        bassnotes[40][5] = 49;
        bassnotes[40][6] = 47;
        bassnotes[40][7] = 42;
        bassnotes[41][0] = 42;
        bassnotes[41][1] = 47;
        bassnotes[41][2] = 47;
        bassnotes[41][3] = 47;
        bassnotes[41][4] = 47;
        bassnotes[41][5] = 49;
        bassnotes[41][6] = 47;
        bassnotes[41][7] = 42;

        for (index=0;index<8;index++)
          bassnotes[42][index] = 39;
        for (index=0;index<8;index++)
        {
          bassnotes[43][index] = 35;
          bassnotes[45][index] = 35;
          bassnotes[46][index] = 35;
        }
        for (index=0;index<4;index++)
          bassnotes[44][index] = 54;
        for (index=4;index<8;index++)
        {
          bassnotes[44][index] = 49;
          bassnotes[46][index] = 49;
        }

        while (1)
        {
                delay1(1);
                if (key_table[INDEX_1])
                {
                   change_light_level(1,50);
                   change_light_level(2,75);
                   change_light_level(3,25);
                   change_light_level(4,50);
                   mutecity();
                   showinfo();
                   all_lights_off(0);
                   change_light_level(3,127);
                }
                if (key_table[INDEX_ESC]) break;
        }
                kill_keyboard();
                Exit_MIDI();
    }
