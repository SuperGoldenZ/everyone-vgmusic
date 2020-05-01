#include "keyboard.h"
#include "midi.h"
#include "crystals.h"
#include <dos.h>
#include <conio.h>

#define drumlevel 127
#define drumchannel 10

#define chordchannel 2

#define autochordchannel 3
#define autochordlevel  100
int     chordvelocity = 100;
const int speed = 95;

void dostuff();

int delay1(int speed)
{
        for (int index=0;index<speed;index++)
        {
                if (key_table[INDEX_ESC]) return 1;
                delay (1);
                dostuff();
        }
        return 0;
}

void drumfill1(double speed, int velocity);

void playchord1(char channel, char velocity)
{
        play_note(channel,74,velocity);
        play_note(channel,71,velocity);
}

void killchord1(char channel, char velocity)
{
        kill_note(channel,74,velocity);
        kill_note(channel,71,velocity);
}

void playchord2(char channel, char velocity)
{
        play_note(channel,78,velocity);
        play_note(channel,74,velocity);
}

void killchord2(char channel, char velocity)
{
        kill_note(channel,78,velocity);
        kill_note(channel,74,velocity);
}

void playchord3(char channel, char velocity)
{
        play_note(channel,76,velocity);
        play_note(channel,71,velocity);
}

void killchord3(char channel, char velocity)
{
        kill_note(channel,76,velocity);
        kill_note(channel,71,velocity);
}

void playchord4(char channel, char velocity)
{
        play_note(channel,79,velocity);
        play_note(channel,76,velocity);
}

void killchord4(char channel, char velocity)
{
        kill_note(channel,79,velocity);
        kill_note(channel,76,velocity);
}

void playchord5(char channel, char velocity)
{
        play_note(channel,74,velocity);
        play_note(channel,71,velocity);
}

void killchord5(char channel, char velocity)
{
        kill_note(channel,74,velocity);
        kill_note(channel,71,velocity);
}

void playchord6(char channel, char velocity)
{
        play_note(channel,74,velocity);
        play_note(channel,79,velocity);
}

void killchord6(char channel, char velocity)
{
        kill_note(channel,74,velocity);
        kill_note(channel,79,velocity);
}

void playchord7(char channel, char velocity)
{
        play_note(channel,73,velocity);
        play_note(channel,76,velocity);
}

void killchord7(char channel, char velocity)
{
        kill_note(channel,73,velocity);
        kill_note(channel,76,velocity);
}

void playchord8(char channel, char velocity)
{                         
        play_note(channel,81,velocity);
        play_note(channel,76,velocity);
}

void killchord8(char channel, char velocity)
{
        kill_note(channel,81,velocity);
        kill_note(channel,76,velocity);
}

//d4 f#4
void playchord9(char channel, char velocity)
{
        play_note(channel,78,velocity);
        play_note(channel,74,velocity);
}

void killchord9(char channel, char velocity)
{
        kill_note(channel,78,velocity);
        kill_note(channel,74,velocity);
}

void playchord10(char channel, char velocity)
{
        play_note(channel,81,velocity);
        play_note(channel,78,velocity);
}

void killchord10(char channel, char velocity)
{
        kill_note(channel,81,velocity);
        kill_note(channel,78,velocity);
}

void playchord11(char channel, char velocity)
{
     playchord6(channel,velocity);
}

void killchord11(char channel, char velocity)
{
     killchord6(channel,velocity);
}

void playchord12(char channel, char velocity)
{
        play_note(channel,83,velocity);
        play_note(channel,79,velocity);
}

void killchord12(char channel, char velocity)
{
        kill_note(channel,83,velocity);
        kill_note(channel,79,velocity);
}

void playchord13(char channel, char velocity)
{
     playchord9(channel,velocity);
}

void killchord13(char channel, char velocity)
{
     killchord9(channel,velocity);
}

void playchord14(char channel, char velocity)
{
        play_note(channel,83,velocity);
        play_note(channel,78,velocity);
}

void killchord14(char channel, char velocity)
{
        kill_note(channel,83,velocity);
        kill_note(channel,78,velocity);
}

void playchord15(char channel, char velocity)
{
playchord7(channel,velocity);
}

void killchord15(char channel, char velocity)
{
killchord7(channel,velocity);
}

void playchord16(char channel, char velocity)
{
playchord8(channel,velocity);
}

void killchord16(char channel, char velocity)
{
killchord8(channel,velocity);
}

//chord 17 C#4 F#4 A4
void playchord17(char channel, char velocity)
{
        play_note(channel,73,velocity);
        play_note(channel,78,velocity);
        play_note(channel,81,velocity);
}

void killchord17(char channel, char velocity)
{
        kill_note(channel,73,velocity);
        kill_note(channel,78,velocity);
        kill_note(channel,81,velocity);
}

//chord 18 B3  D4  FS4
void playchord18(char channel, char velocity)
{
        play_note(channel,71,velocity);
        play_note(channel,74,velocity);
        play_note(channel,78,velocity);
}

void killchord18(char channel, char velocity)
{
        kill_note(channel,71,velocity);
        kill_note(channel,74,velocity);
        kill_note(channel,78,velocity);
}

//chord 19 B3  D4  G4
void playchord19(char channel, char velocity)
{
        play_note(channel,71,velocity);
        play_note(channel,74,velocity);
        play_note(channel,79,velocity);
}

void killchord19(char channel, char velocity)
{
        kill_note(channel,71,velocity);
        kill_note(channel,74,velocity);
        kill_note(channel,79,velocity);
}

//chord 20 e4 a4  c#5
void playchord20(char channel, char velocity)
{
        play_note(channel,76,velocity);
        play_note(channel,81,velocity);
        play_note(channel,85,velocity);
}

void killchord20(char channel, char velocity)
{
        kill_note(channel,76,velocity);
        kill_note(channel,81,velocity);
        kill_note(channel,85,velocity);
}

//chord 21 c#4 f#4 a4
void playchord21(char channel, char velocity)
{
        play_note(channel,73,velocity);
        play_note(channel,78,velocity);
        play_note(channel,81,velocity);
}

void killchord21(char channel, char velocity)
{
        kill_note(channel,73,velocity);
        kill_note(channel,78,velocity);
        kill_note(channel,81,velocity);
}

//chord 22 B3  D4  FS4
void playchord22(char channel, char velocity)
{
        play_note(channel,71,velocity);
        play_note(channel,74,velocity);
        play_note(channel,78,velocity);
}

void killchord22(char channel, char velocity)
{
        kill_note(channel,71,velocity);
        kill_note(channel,74,velocity);
        kill_note(channel,78,velocity);
}

//C4 E4
void playchord23(char channel, char velocity)
{
        play_note(channel,72,velocity);
        play_note(channel,76,velocity);
}

void killchord23(char channel, char velocity)
{
        kill_note(channel,72,velocity);
        kill_note(channel,76,velocity);
}

//E4 G4
void playchord24(char channel, char velocity)
{
        play_note(channel,79,velocity);
        play_note(channel,76,velocity);
}

void killchord24(char channel, char velocity)
{
        kill_note(channel,79,velocity);
        kill_note(channel,76,velocity);
}

void playchord30(char channel, char velocity)
{
     playchord2(channel,velocity);
}

void killchord30(char channel, char velocity)
{
     killchord2(channel,velocity);
}

//A3 D4
void playchord31(char channel, char velocity)
{
        play_note(channel,69,velocity);
        play_note(channel,74,velocity);
}

void killchord31(char channel, char velocity)
{
        kill_note(channel,69,velocity);
        kill_note(channel,74,velocity);
}

void playchord32(char channel, char velocity)
{
     playchord6(channel,velocity);
}

void killchord32(char channel, char velocity)
{
     killchord6(channel,velocity);
}

void playchord33(char channel, char velocity)
{
        play_note(channel,81,velocity);
        play_note(channel,74,velocity);
}

void killchord33(char channel, char velocity)
{
        kill_note(channel,81,velocity);
        kill_note(channel,74,velocity);
}

void playchord34(char channel, char velocity)
{
     playchord7(channel,velocity);
}

void killchord34(char channel, char velocity)
{
     killchord7(channel,velocity);
}

//auto1:  B1  B2
void playautochord1(char channel, char velocity)
{
   play_note(channel,47,velocity);   
   play_note(channel,47+12,velocity);   
}

void killautochord1(char channel, char velocity)
{
   kill_note(channel,47,velocity);   
   kill_note(channel,47+12,velocity);   
}

//auto2:  E2  E3
void playautochord2(char channel, char velocity)
{
   play_note(channel,52,velocity);   
   play_note(channel,52+12,velocity);   
}

void killautochord2(char channel, char velocity)
{
   kill_note(channel,52,velocity);   
   kill_note(channel,52+12,velocity);   
}

//auto3:  G2  G3
void playautochord3(char channel, char velocity)
{
   play_note(channel,55,velocity);   
   play_note(channel,55+12,velocity);   
}

void killautochord3(char channel, char velocity)
{
   kill_note(channel,55,velocity);   
   kill_note(channel,55+12,velocity);   
}

//auto4:  A2  A3
void playautochord4(char channel, char velocity)
{
   play_note(channel,57,velocity);   
   play_note(channel,57+12,velocity);   
}

void killautochord4(char channel, char velocity)
{
   kill_note(channel,57,velocity);   
   kill_note(channel,57+12,velocity);   
}

//auto5:  G2  G3 (see auto 3)
void playautochord5(char channel, char velocity)
{
     playautochord3(channel,velocity);
}

void killautochord5(char channel, char velocity)
{
     killautochord3(channel,velocity);
}

//auto6:  D2  D3
void playautochord6(char channel, char velocity)
{
   play_note(channel,50,velocity);   
   play_note(channel,50+12,velocity);   
}

void killautochord6(char channel, char velocity)
{
   kill_note(channel,50,velocity);   
   kill_note(channel,50+12,velocity);   
}

//auto7:  G2  G3 (see auto 3)
void playautochord7(char channel, char velocity)
{
     playautochord3(channel,velocity);
}

void killautochord7(char channel, char velocity)
{
     killautochord3(channel,velocity);
}

//auto8:  B2  B3
void playautochord8(char channel, char velocity)
{
   play_note(channel,59,velocity);   
   play_note(channel,59+12,velocity);   
}

void killautochord8(char channel, char velocity)
{
   kill_note(channel,59,velocity);   
   kill_note(channel,59+12,velocity);   
}

//auto9:  A2  A3
void playautochord9(char channel, char velocity)
{
   play_note(channel,57,velocity);   
   play_note(channel,57+12,velocity);   
}

void killautochord9(char channel, char velocity)
{
   kill_note(channel,57,velocity);   
   kill_note(channel,57+12,velocity);   
}

//auto10: E2  E3
void playautochord10(char channel, char velocity)
{
   play_note(channel,52,velocity);   
   play_note(channel,52+12,velocity);   
}

void killautochord10(char channel, char velocity)
{
   kill_note(channel,52,velocity);   
   kill_note(channel,52+12,velocity);   
}

//auto11: C#2 C#3
void playautochord11(char channel, char velocity)
{
   play_note(channel,49,velocity);   
   play_note(channel,49+12,velocity);   
}

void killautochord11(char channel, char velocity)
{
   kill_note(channel,49,velocity);   
   kill_note(channel,49+12,velocity);   
}

//auto12: A1  A2
void playautochord12(char channel, char velocity)
{
   play_note(channel,45,velocity);   
   play_note(channel,45+12,velocity);   
}

void killautochord12(char channel, char velocity)
{
   kill_note(channel,45,velocity);   
   kill_note(channel,45+12,velocity);   
}

void dostuff()
{
                        if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
                        {
                                notes[INDEX_F1]=1;
                                playchord1(chordchannel,chordvelocity);
                        }

                        if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
                        {
                                notes[INDEX_F2]=1;
                                playchord2(chordchannel,chordvelocity);
                        }

                        if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
                        {
                                notes[INDEX_F3]=1;
                                playchord3(chordchannel,chordvelocity);
                        }

                        if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
                        {
                          notes[INDEX_F4]=1;
                          playchord4(chordchannel,chordvelocity);
                        }

        if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
        {
          notes[INDEX_F5]=1;
          playchord5(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
        {
          notes[INDEX_F6]=1;
          playchord6(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
        {
          notes[INDEX_F7]=1;
          playchord7(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
        {
          notes[INDEX_F8]=1;
          playchord8(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_F9] == 0) && (key_table[INDEX_F9]==1))
        {
          notes[INDEX_F9]=1;
          playchord9(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_F10] == 0) && (key_table[INDEX_F10]==1))
        {
          notes[INDEX_F10]=1;
          playchord10(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_F11] == 0) && (key_table[INDEX_F11]==1))
        {
          notes[INDEX_F11]=1;
          playchord11(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_F12] == 0) && (key_table[INDEX_F12]==1))
        {
          notes[INDEX_F12]=1;
          playchord12(chordchannel,chordvelocity);
        }


                        if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
                        {
                                killchord1(chordchannel,chordvelocity);
                                notes[INDEX_F1]=0;
                        }

                        if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
                        {
                                killchord2(chordchannel,chordvelocity);
                                notes[INDEX_F2]=0;
                        }

                        if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
                        {
                                killchord3(chordchannel,chordvelocity);
                                notes[INDEX_F3]=0;
                        }

        if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
        {
          killchord4(chordchannel,chordvelocity);
          notes[INDEX_F4]=0;
        }

        if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
        {
          killchord5(chordchannel,chordvelocity);
          notes[INDEX_F5]=0;
        }

        if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
        {
          killchord6(chordchannel,chordvelocity);
          notes[INDEX_F6]=0;
        }

        if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
        {
          killchord7(chordchannel,chordvelocity);
          notes[INDEX_F7]=0;
        }

        if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))
        {
          killchord8(chordchannel,chordvelocity);
          notes[INDEX_F8]=0;
        }

        if ((notes[INDEX_F9] == 1) && (key_table[INDEX_F9]==0))
        {
          killchord9(chordchannel,chordvelocity);
          notes[INDEX_F9]=0;
        }

        if ((notes[INDEX_F10] == 1) && (key_table[INDEX_F10]==0))
        {
          killchord10(chordchannel,chordvelocity);
          notes[INDEX_F10]=0;
        }

        if ((notes[INDEX_F11] == 1) && (key_table[INDEX_F11]==0))
        {
          killchord11(chordchannel,chordvelocity);
          notes[INDEX_F11]=0;
        }

        if ((notes[INDEX_F12] == 1) && (key_table[INDEX_F12]==0))
        {
          killchord12(chordchannel,chordvelocity);
          notes[INDEX_F12]=0;
        }

//NEW STUFF
        if ((notes[INDEX_11] == 0) && (key_table[INDEX_11]==1))
        {
          notes[INDEX_11]=1;
          playchord13(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_11] == 1) && (key_table[INDEX_11]==0))
        {
          killchord13(chordchannel,chordvelocity);
          notes[INDEX_11]=0;
        }

        if ((notes[INDEX_21] == 0) && (key_table[INDEX_21]==1))
        {
          notes[INDEX_21]=1;
          playchord14(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_21] == 1) && (key_table[INDEX_21]==0))
        {
          killchord14(chordchannel,chordvelocity);
          notes[INDEX_21]=0;
        }

        if ((notes[INDEX_31] == 0) && (key_table[INDEX_31]==1))
        {
          notes[INDEX_31]=1;
          playchord15(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_31] == 1) && (key_table[INDEX_31]==0))
        {
          killchord15(chordchannel,chordvelocity);
          notes[INDEX_31]=0;
        }

        if ((notes[INDEX_41] == 0) && (key_table[INDEX_41]==1))
        {
          notes[INDEX_41]=1;
          playchord16(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_41] == 1) && (key_table[INDEX_41]==0))
        {
          killchord16(chordchannel,chordvelocity);
          notes[INDEX_41]=0;
        }

        if ((notes[INDEX_51] == 0) && (key_table[INDEX_51]==1))
        {
          notes[INDEX_51]=1;
          playchord17(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_51] == 1) && (key_table[INDEX_51]==0))
        {
          killchord17(chordchannel,chordvelocity);
          notes[INDEX_51]=0;
        }

        if ((notes[INDEX_61] == 0) && (key_table[INDEX_61]==1))
        {
          notes[INDEX_61]=1;
          playchord18(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_61] == 1) && (key_table[INDEX_61]==0))
        {
          killchord18(chordchannel,chordvelocity);
          notes[INDEX_61]=0;
        }

        if ((notes[INDEX_71] == 0) && (key_table[INDEX_71]==1))
        {
          notes[INDEX_71]=1;
          playchord19(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_71] == 1) && (key_table[INDEX_71]==0))
        {
          killchord19(chordchannel,chordvelocity);
          notes[INDEX_71]=0;
        }

        if ((notes[INDEX_81] == 0) && (key_table[INDEX_81]==1))
        {
          notes[INDEX_81]=1;
          playchord20(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_81] == 1) && (key_table[INDEX_81]==0))
        {
          killchord20(chordchannel,chordvelocity);
          notes[INDEX_81]=0;
        }

        if ((notes[INDEX_91] == 0) && (key_table[INDEX_91]==1))
        {
          notes[INDEX_91]=1;
          playchord21(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_91] == 1) && (key_table[INDEX_91]==0))
        {
          killchord21(chordchannel,chordvelocity);
          notes[INDEX_91]=0;
        }

        if ((notes[INDEX_01] == 0) && (key_table[INDEX_01]==1))
        {
          notes[INDEX_01]=1;
          playchord22(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_01] == 1) && (key_table[INDEX_01]==0))
        {
          killchord22(chordchannel,chordvelocity);
          notes[INDEX_01]=0;
        }

        if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
        {
          notes[INDEX_Q]=1;
          playchord23(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))
        {
          killchord23(chordchannel,chordvelocity);
          notes[INDEX_Q]=0;
        }

        if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
        {
          notes[INDEX_W]=1;
          playchord24(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))
        {
          killchord24(chordchannel,chordvelocity);
          notes[INDEX_W]=0;
        }

        if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
        {
          notes[INDEX_E]=1;
          playchord30(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))
        {
          killchord30(chordchannel,chordvelocity);
          notes[INDEX_E]=0;
        }

        if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
        {
          notes[INDEX_R]=1;
          playchord31(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))
        {
          killchord31(chordchannel,chordvelocity);
          notes[INDEX_R]=0;
        }

        if ((notes[INDEX_T] == 0) && (key_table[INDEX_T]==1))
        {
          notes[INDEX_T]=1;
          playchord32(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_T] == 1) && (key_table[INDEX_T]==0))
        {
          killchord32(chordchannel,chordvelocity);
          notes[INDEX_T]=0;
        }

        if ((notes[INDEX_Y] == 0) && (key_table[INDEX_Y]==1))
        {
          notes[INDEX_Y]=1;
          playchord33(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_Y] == 1) && (key_table[INDEX_Y]==0))
        {
          killchord33(chordchannel,chordvelocity);
          notes[INDEX_Y]=0;
        }

        if ((notes[INDEX_U] == 0) && (key_table[INDEX_U]==1))
        {
          notes[INDEX_U]=1;
          playchord34(chordchannel,chordvelocity);
        }

        if ((notes[INDEX_U] == 1) && (key_table[INDEX_U]==0))
        {
          killchord34(chordchannel,chordvelocity);
          notes[INDEX_U]=0;
        }

}

int intro()
{
        clrscr();
        cout << "Welcome to Matouya's Cave!";
        play_note(drumchannel,38,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(drumchannel,38,drumlevel);
        play_note(drumchannel,38,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(drumchannel,38,drumlevel);
        play_note(drumchannel,38,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(drumchannel,38,drumlevel);
        play_note(drumchannel,38,drumlevel);
        if (delay1(speed*2)) return 0;
        kill_note(drumchannel,38,drumlevel);

/*        cout << "Intro";
                play_note(drumchannel,38,drumlevel);
                play_note(drumchannel,B3,drumlevel);
                play_note(drumchannel,B1,drumlevel);
                delay(speed); // 1  16th
                delay(speed); // 2  16th
                kill_note(drumchannel,B3,drumlevel);
                kill_note(drumchannel,B1,drumlevel);
                play_note(drumchannel,D2,drumlevel);
                delay(speed); // 3  16th
                kill_note(drumchannel,D2,drumlevel);
                play_note(drumchannel,B1,drumlevel);
                delay(speed); // 4  16th
                kill_note(drumchannel,B1,drumlevel);
                kill_note(drumchannel,38,drumlevel);
                play_note(drumchannel,38,drumlevel);
                delay(speed); // 5  16th
                delay(speed); // 6  16th
                delay(speed); // 7  16th
                delay(speed); // 8  16th
                kill_note(drumchannel,38,drumlevel);
                play_note(drumchannel,38,drumlevel);
                delay(speed); // 9  16th
                delay(speed); // 10 16th 
                delay(speed); // 11 16th
                delay(speed); // 12 16th
                kill_note(drumchannel,38,drumlevel);
                play_note(drumchannel,38,drumlevel);
                delay(speed); // 13 16th
                delay(speed); // 14 16th 
                delay(speed); // 15 16th
                delay(speed); // 16 16th
                kill_note(drumchannel,38,drumlevel);
                delay(500);
                play_note(drumchannel,38,drumlevel);
                play_note(drumchannel,B3,drumlevel);
                play_note(drumchannel,B1,drumlevel);
                delay(speed); // 1  16th
                delay(speed); // 2  16th
                kill_note(drumchannel,B3,drumlevel);
                kill_note(drumchannel,B1,drumlevel);
                play_note(drumchannel,D2,drumlevel);
                delay(speed); // 3  16th
                kill_note(drumchannel,D2,drumlevel);
                play_note(drumchannel,B1,drumlevel);
                delay(speed); // 4  16th
                kill_note(drumchannel,B1,drumlevel);
                kill_note(drumchannel,38,drumlevel);
                play_note(drumchannel,38,drumlevel);
                delay(speed); // 5  16th
                delay(speed); // 6  16th
                delay(speed); // 7  16th
                delay(speed); // 8  16th
                kill_note(drumchannel,38,drumlevel);
                play_note(drumchannel,38,drumlevel);
                delay(speed); // 9  16th
                delay(speed); // 10 16th 
                delay(speed); // 11 16th
                delay(speed); // 12 16th
                kill_note(drumchannel,38,drumlevel);
                play_note(drumchannel,38,drumlevel);
                delay(speed); // 13 16th
                delay(speed); // 14 16th 
                delay(speed); // 15 16th
                delay(speed); // 16 16th
                kill_note(drumchannel,38,drumlevel);*/
        return 0;
}

void go()
{
        intro();
        int measure = 0;
for (int index2=0;index2<3;index2++)
{
                measure = 0;
                cout << "\nMeasure " << ++measure;

                play_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,B2,drumlevel);
                playautochord1(autochordchannel,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                kill_note(drumchannel,B2,drumlevel);


                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                killautochord1(autochordchannel,autochordlevel);
                playautochord2(autochordchannel,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,C1,drumlevel);                
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th 
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                delay1(speed); // 14 16th 
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,D1,drumlevel);
                killautochord2(autochordchannel,autochordlevel);

cout << "\nMeasure " << ++measure;
                playautochord3(autochordchannel,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                killautochord3(autochordchannel,autochordlevel);
                playautochord4(autochordchannel,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                killautochord4(autochordchannel,autochordlevel);
                playautochord5(autochordchannel,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 15 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 16 16th
                killautochord5(autochordchannel,autochordlevel);
                kill_note(drumchannel,D1,drumlevel);
cout << "\nMeasure " << ++measure;

                playautochord6(autochordchannel,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,B2,drumlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                kill_note(drumchannel,B2,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                killautochord6(autochordchannel,autochordlevel);
                playautochord7(autochordchannel,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,C1,drumlevel);                
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th 
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                delay1(speed); // 14 16th 
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                killautochord7(autochordchannel,autochordlevel);
                kill_note(drumchannel,D1,drumlevel);
cout << "\nMeasure " << ++measure;
                playautochord8(autochordchannel,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                killautochord8(autochordchannel,autochordlevel);
                playautochord9(autochordchannel,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                killautochord9(autochordchannel,autochordlevel);
                playautochord10(autochordchannel,autochordlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                killautochord10(autochordchannel,autochordlevel);
                playautochord11(autochordchannel,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                delay1(speed); // 14 16th
                killautochord11(autochordchannel,autochordlevel);
                playautochord12(autochordchannel,autochordlevel);
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 15 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 16 16th
                killautochord12(autochordchannel,autochordlevel);
                kill_note(drumchannel,D1,drumlevel);

cout << "   loop";

                cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,57,drumlevel);
                play_note(autochordchannel,54,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,54,autochordlevel);
                play_note(autochordchannel,54,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                kill_note(drumchannel,57,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,54,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,54,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,54,autochordlevel);
                play_note(autochordchannel,54,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,54,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(autochordchannel,59,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,59,autochordlevel);
                play_note(autochordchannel,59,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,59,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,59,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,59,autochordlevel);
                play_note(autochordchannel,59,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,59,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

                cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,57,drumlevel);
                play_note(autochordchannel,55,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,55,autochordlevel);
                play_note(autochordchannel,55,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                kill_note(drumchannel,57,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,55,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,55,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,55,autochordlevel);
                play_note(autochordchannel,55,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,55,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(autochordchannel,57,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,57,autochordlevel);
                play_note(autochordchannel,57,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,57,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,57,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,57,autochordlevel);
                play_note(autochordchannel,57,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,57,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

                cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,57,drumlevel);
                play_note(autochordchannel,54,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,54,autochordlevel);
                play_note(autochordchannel,54,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                kill_note(drumchannel,57,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,54,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,54,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,54,autochordlevel);
                play_note(autochordchannel,54,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,54,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(autochordchannel,59,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,59,autochordlevel);
                play_note(autochordchannel,59,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,59,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,59,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,59,autochordlevel);
                play_note(autochordchannel,59,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,59,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

               cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,57,drumlevel);
                play_note(autochordchannel,60,drumlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,60,drumlevel);
                play_note(autochordchannel,60,drumlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(autochordchannel,60,drumlevel);
                play_note(autochordchannel,60,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                kill_note(drumchannel,57,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                delay1(speed); // 6  16th
                kill_note(autochordchannel,60,drumlevel);
                play_note(autochordchannel,60,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                kill_note(autochordchannel,60,drumlevel);
                play_note(autochordchannel,60,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,60,drumlevel);
                play_note(autochordchannel,60,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(autochordchannel,60,drumlevel);
                play_note(autochordchannel,60,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                delay1(speed); // 14 16th
                kill_note(autochordchannel,60,drumlevel);
                play_note(autochordchannel,60,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(autochordchannel,60,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(autochordchannel,57,drumlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,57,drumlevel);
                play_note(autochordchannel,57,drumlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(autochordchannel,57,drumlevel);
                play_note(autochordchannel,57,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                delay1(speed); // 6  16th
                kill_note(autochordchannel,57,drumlevel);
                play_note(autochordchannel,57,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                kill_note(autochordchannel,57,drumlevel);
                play_note(autochordchannel,57,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,57,drumlevel);
                play_note(autochordchannel,57,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(autochordchannel,57,drumlevel);
                play_note(autochordchannel,57,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                delay1(speed); // 14 16th
                kill_note(autochordchannel,57,drumlevel);
                play_note(autochordchannel,57,drumlevel);
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(autochordchannel,57,drumlevel);
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

                cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,57,drumlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                kill_note(drumchannel,57,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,50,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,50,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

                cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,57,drumlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                kill_note(drumchannel,57,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,50,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,50,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

                cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,57,drumlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                kill_note(drumchannel,57,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,50,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,50,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

                cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,57,drumlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                kill_note(drumchannel,57,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,50,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

cout << "\nMeasure " << ++measure;
                play_note(drumchannel,C1,drumlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 1  16th
                delay1(speed); // 2  16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 3  16th
                delay1(speed); // 4  16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 5  16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 6  16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 7  16th
                delay1(speed); // 8  16th 
                play_note(autochordchannel,50,autochordlevel);
                kill_note(drumchannel,C1,drumlevel);
                delay1(speed); // 9  16th
                delay1(speed); // 10 16th 
                kill_note(autochordchannel,50,autochordlevel);
                play_note(autochordchannel,50,autochordlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 11 16th
                delay1(speed); // 12 16th
                kill_note(drumchannel,C1,drumlevel);
                play_note(drumchannel,D1,drumlevel);
                delay1(speed); // 13 16th
                kill_note(autochordchannel,50,autochordlevel);
                delay1(speed); // 14 16th
                kill_note(drumchannel,D1,drumlevel);
                play_note(drumchannel,C1,drumlevel);
                delay1(speed); // 15 16th
                delay1(speed); // 16 16th
                kill_note(drumchannel,C1,drumlevel);
                if (key_table[INDEX_ESC]) break;

}
wait_for_no(INDEX_ESC);
        clrscr();
        cout << "1: Enter Matouya's Cave";
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
        change_program(2,51,1);
        change_program(autochordchannel,51,1);
        change_program(1,73,2);
        change_effects_level(10,0);
        change_effects_level(3,0);
        mix_name("Fantasy  ");
        mix_mode();

        clrscr();
        cout << "1: Enter Matouya's Cave";
        cout << "\nESC: Quit";

        while (1)
        {
                delay1(1);
                if (key_table[INDEX_1]) go();
                if (key_table[INDEX_ESC]) break;
        }
                kill_keyboard();
                Exit_MIDI();
    }
