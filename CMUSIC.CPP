#include <dos.h>
#include <conio.h>
#include "midi.h"
#include "lights.h"
#include "keyboard.h"

#define basschannel 6
#define basslevel 127

#define timpanilevel 127
#define timpanichannel 7

#define doomtomlevel 127
#define doomtomchannel 8

#define brasschannel 9
#define brasslevel 127

#define guitarchannel 11
#define guitarlevel 127

#define ahhchannel 12
#define ahhlevel 127

#define drumminus -4

int drumlevel = 127;

const int chordlevel = 50;
const int chordlevel1 = 75;
const int endchordlevel = 100;

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

void dostuff();
void vampire_killer(int speed);

int delay1(int speed)
{
 int index;
 for (index=1;index<speed;index++)
 {
         dostuff();
         if (key_table[INDEX_ESC]) return 1;
         delay(1);
 }
 return 0;
}

void loop(int speed, int channel)
{
        clrscr();
        cout << "(running drum loop)";
        cout << "\n\nESC: Quits";
        int measure = 2;
        all_lights_off(0);
        play_note(channel,36,127);
        delay(speed);
        kill_note(channel,36,127);
        play_note(channel,36,127);
        play_note(channel,38,127);
//        change_light_level(2,75);
        delay(speed);
        kill_note(channel,36,127);
        kill_note(channel,38,127);
        play_note(channel,38,127);
//        change_light_level(3,25);
        delay(speed);
        kill_note(channel,38,127);
        play_note(channel,38,127);
        change_light_level(1,50);
        change_light_level(2,75);
        change_light_level(3,25);
        change_light_level(4,50);
        delay(speed);
        kill_note(channel,38,127);
        int index;

        while (1)
        {
           cout << "\nMeasure " << ++measure;
           play_note(channel,36,127);
           play_note(channel,42,127);
           if (delay1(speed)) break;
           if (delay1(speed)) break;
           play_note(channel,38,127);
           play_note(channel,42,127);
           if (delay1(speed)) break;
           play_note(channel,36,127);
           if (delay1(speed)) break;
           play_note(channel,42,127);
           if (delay1(speed)) break;
           play_note(channel,36,127);
           if (delay1(speed)) break;
           play_note(channel,42,127);
           play_note(channel,38,127);
           if (delay1(speed)) break;
           if (delay1(speed)) break;
           play_note(channel,36,127);
           play_note(channel,42,127);
           if (delay1(speed)) break;
           if (delay1(speed)) break;
           play_note(channel,38,127);
           play_note(channel,42,127);
           if (delay1(speed)) break;
           if (delay1(speed)) break;
           play_note(channel,42,127);
           play_note(channel,36,127);
           if (delay1(speed)) break;
           if (delay1(speed)) break;
           play_note(channel,42,127);
           play_note(channel,38,127);
           if (delay1(speed)) break;
           if (delay1(speed)) break;
        }
//        goto zulu;
        wait_for_no(INDEX_ESC);
        return;
        while (1)
        {
                begin:
                for (index=0;index<3;index++)
                {
                cout << "\nMeasure " << ++measure;
                play_note(channel,36,127);
                play_note(channel,42,127);
                play_note(basschannel,D2,basslevel);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                play_note(channel,38,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,D2,basslevel);
                play_note(basschannel,A2,basslevel);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,A2,basslevel);
                play_note(basschannel,D3,basslevel);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                play_note(channel,38,127);
                if (delay1(speed)) break;
                kill_note(basschannel,D3,basslevel);
                if (delay1(speed)) break;
                play_note(basschannel,D2,basslevel);
                play_note(channel,36,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                play_note(channel,38,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,D2,basslevel);
                play_note(basschannel,A2,basslevel);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                kill_note(basschannel,A2,basslevel);
                play_note(basschannel,D3,basslevel);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                play_note(channel,38,127);
                if (delay1(speed)) break;
                kill_note(basschannel,D3,basslevel);
                if (delay1(speed)) break;

                cout << "\nMeasure " << ++measure;
                play_note(channel,36,127);
                play_note(channel,42,127);
                play_note(basschannel,C2,basslevel);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                play_note(channel,38,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,G2,basslevel);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,C3,basslevel);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                play_note(channel,38,127);
                if (delay1(speed)) break;
                kill_note(basschannel,C3,basslevel);
                if (delay1(speed)) break;
                play_note(basschannel,C2,basslevel);
                play_note(channel,36,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                play_note(channel,38,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,G2,basslevel);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,C3,basslevel);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                play_note(channel,38,127);
                if (delay1(speed)) break;
                kill_note(basschannel,C3,basslevel);
                if (delay1(speed)) break;

                cout << "\nMeasure " << ++measure;
                play_note(channel,36,drumlevel);
                play_note(channel,42,drumlevel);
                play_note(basschannel,AS1,basslevel);
                if (measure == 35) drumlevel += drumminus;
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                play_note(channel,38,drumlevel);
                play_note(channel,42,drumlevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                kill_note(basschannel,AS1,basslevel);
                play_note(basschannel,F2,basslevel);
                play_note(channel,36,drumlevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                play_note(channel,42,drumlevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                kill_note(basschannel,F2,basslevel);
                play_note(basschannel,AS2,basslevel);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                play_note(channel,42,drumlevel);
                play_note(channel,38,drumlevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                kill_note(basschannel,AS2,basslevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                play_note(basschannel,AS1,basslevel);
                play_note(channel,36,drumlevel);
                play_note(channel,42,drumlevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                play_note(channel,38,drumlevel);
                play_note(channel,42,drumlevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                kill_note(basschannel,AS1,basslevel);
                play_note(basschannel,F2,basslevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                play_note(channel,42,drumlevel);
                play_note(channel,36,drumlevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                kill_note(basschannel,F2,basslevel);
                play_note(basschannel,AS2,basslevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                play_note(channel,42,drumlevel);
                play_note(channel,38,drumlevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;
                kill_note(basschannel,AS2,basslevel);
                if (delay1(speed)) break;
                if (measure == 35) drumlevel += drumminus;

                cout << "\nMeasure " << ++measure;
                if (measure == 36) drumlevel += drumminus;
                play_note(channel,36,drumlevel);
                play_note(channel,42,drumlevel);
                play_note(basschannel,A2,basslevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                if (delay1(speed)) break;
                play_note(channel,38,drumlevel);
                play_note(channel,42,drumlevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                kill_note(basschannel,A2,basslevel);
                play_note(basschannel,F2,basslevel);
                play_note(channel,36,drumlevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                play_note(channel,42,drumlevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                kill_note(basschannel,F2,basslevel);
                play_note(basschannel,F2,basslevel);
                play_note(channel,36,drumlevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                kill_note(basschannel,F2,basslevel);
                play_note(basschannel,G2,basslevel);
                play_note(channel,42,drumlevel);
                play_note(channel,38,drumlevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,G2,basslevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,A2,basslevel);
                play_note(channel,36,drumlevel);
                play_note(channel,42,drumlevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                play_note(channel,38,drumlevel);
                play_note(channel,42,drumlevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                kill_note(basschannel,A2,basslevel);
                play_note(basschannel,A2,basslevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                play_note(channel,42,drumlevel);
                play_note(channel,36,drumlevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                kill_note(basschannel,A2,basslevel);
                play_note(basschannel,CS2,basslevel);
                play_note(channel,42,drumlevel);
                play_note(channel,38,drumlevel);
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                if (delay1(speed)) break;
                if (measure == 36) drumlevel += drumminus;
                kill_note(basschannel,CS2,basslevel);
                }

                if (measure > 25) goto ending;

                if (key_table[INDEX_ESC]) break;
                middle:
                for (index=0;index<4;index++)
                {

                //Four (middle part)
                cout << "\nMeasure " << ++measure;
                play_note(channel,36,127);
                play_note(channel,42,127);
                play_note(basschannel,D2,basslevel);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                play_note(channel,38,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,D2,basslevel);
                play_note(basschannel,A2,basslevel);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,A2,basslevel);
                play_note(basschannel,D3,basslevel);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                kill_note(basschannel,D3,basslevel);
                play_note(basschannel,D2,basslevel);
                play_note(channel,42,127);
                play_note(channel,38,127);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                kill_note(basschannel,D2,basslevel);
                play_note(basschannel,C2,basslevel);
                play_note(channel,36,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                play_note(channel,38,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,G2,basslevel);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,C3,basslevel);
                if (delay1(speed)) break;
                kill_note(basschannel,C3,basslevel);
                play_note(basschannel,C2,basslevel);
                play_note(channel,42,127);
                play_note(channel,38,127);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                kill_note(basschannel,C2,basslevel);

                cout << "\nMeasure " << ++measure;
                play_note(channel,36,127);
                play_note(channel,42,127);
                play_note(basschannel,AS1,basslevel);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                play_note(channel,38,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,AS1,basslevel);
                play_note(basschannel,F2,basslevel);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,F2,basslevel);
                play_note(basschannel,AS2,basslevel);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                kill_note(basschannel,AS2,basslevel);
                play_note(basschannel,AS1,basslevel);
                play_note(channel,42,127);
                play_note(channel,38,127);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                kill_note(basschannel,AS1,basslevel);
                play_note(basschannel,C2,basslevel);
                play_note(channel,36,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                play_note(channel,38,127);
                play_note(channel,42,127);
                if (delay1(speed)) break;
                kill_note(basschannel,C2,basslevel);
                play_note(basschannel,G2,basslevel);
                if (delay1(speed)) break;
                play_note(channel,42,127);
                play_note(channel,36,127);
                if (delay1(speed)) break;
                kill_note(basschannel,G2,basslevel);
                play_note(basschannel,C3,basslevel);
                if (delay1(speed)) break;
                kill_note(basschannel,C3,basslevel);
                play_note(basschannel,D2,basslevel);
                play_note(channel,42,127);
                play_note(channel,38,127);
                if (delay1(speed)) break;
                if (delay1(speed)) break;
                kill_note(basschannel,D2,basslevel);
                }

                if (measure < 40) goto begin;

                ending:
                for (index=0;index<4;index++)
                {
                cout << "\nMeasure " << ++measure;
                play_note(basschannel,E2,basslevel);
                play_note(basschannel,E3,basslevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                play_note(timpanichannel,D2,timpanilevel);
                if (delay1(speed)) break;
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                kill_note(basschannel,E2,basslevel);
                kill_note(basschannel,E3,basslevel);
                if (delay1(speed)) break;
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                play_note(basschannel,E2,basslevel);
                play_note(basschannel,E3,basslevel);
                if (delay1(speed)) break;
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                play_note(timpanichannel,D2,timpanilevel);
                play_note(10,49,0);
                if (delay1(speed)) break;
                kill_note(10,49,0);
                kill_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(basschannel,E2,basslevel);
                kill_note(basschannel,E3,basslevel);
                play_note(basschannel,D2,basslevel);
                play_note(basschannel,D3,basslevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                kill_note(basschannel,D2,basslevel);
                kill_note(basschannel,D3,basslevel);
                if (delay1(speed)) break;
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                play_note(basschannel,D3,basslevel);
                play_note(basschannel,D3,basslevel);
                if (delay1(speed)) break;
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                play_note(timpanichannel,D2,timpanilevel);
                play_note(channel,49,0);
                if (delay1(speed)) break;
                kill_note(channel,49,0);
                kill_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                kill_note(basschannel,D2,basslevel);
                kill_note(basschannel,D3,basslevel);

                cout << "\nMeasure " << ++measure;
                play_note(basschannel,C2,basslevel);
                play_note(basschannel,C3,basslevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                play_note(timpanichannel,D2,timpanilevel);
                if (delay1(speed)) break;
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                kill_note(basschannel,C2,basslevel);
                kill_note(basschannel,C3,basslevel);
                if (delay1(speed)) break;
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                play_note(basschannel,C2,basslevel);
                play_note(basschannel,C3,basslevel);
                if (delay1(speed)) break;
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                play_note(timpanichannel,D2,timpanilevel);
                play_note(10,49,0);
                if (delay1(speed)) break;
                kill_note(10,49,0);
                kill_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(basschannel,C2,basslevel);
                kill_note(basschannel,C3,basslevel);
                play_note(basschannel,D2,basslevel);
                play_note(basschannel,D3,basslevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                kill_note(basschannel,D2,basslevel);
                kill_note(basschannel,D3,basslevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                play_note(basschannel,D2,basslevel);
                play_note(basschannel,D3,basslevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                play_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                play_note(timpanichannel,D2,timpanilevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(doomtomchannel,D2,doomtomlevel);
                if (delay1(speed)) break;
                kill_note(timpanichannel,D2,timpanilevel);
                play_note(timpanichannel,D2,timpanilevel);
                kill_note(basschannel,D2,basslevel);
                kill_note(basschannel,D3,basslevel);

                }
                if (key_table[INDEX_ESC]) break;
                break;
                
        }

        zulu:
        wait_for_no(INDEX_ESC);
        kill_note(channel,36,127);
        kill_note(channel,40,127);
        kill_note(channel,42,127);
        play_note(1,38,127);
        (delay1(speed*32));
        cout << "\nAll lights off";
        all_lights_off(0);
        change_light_level(1,127);
        vampire_killer(118);
}

//D2 & D3
void playchord1()
{
 play_note(3,50,chordlevel1);
 play_note(3,62,chordlevel1);
}

void killchord1()
{
 kill_note(3,50,chordlevel1);
 kill_note(3,62,chordlevel1);
}

//C2 & C3
void playchord2()
{
 play_note(3,48,chordlevel1);
 play_note(3,60,chordlevel1);
}

void killchord2()
{
 kill_note(3,48,chordlevel1);
 kill_note(3,60,chordlevel1);
}

//A#1 A#2 A#3
void playchord3()
{
 play_note(3,46+00,chordlevel1);
 play_note(3,46+12,chordlevel1);
 play_note(3,46+24,chordlevel1);
}

void killchord3()
{
 kill_note(3,46+00,chordlevel1);
 kill_note(3,46+12,chordlevel1);
 kill_note(3,46+24,chordlevel1);
}

//A1 A2 A3
void playchord4()
{
 play_note(3,45+00,chordlevel1);
 play_note(3,45+12,chordlevel1);
 play_note(3,45+24,chordlevel1);
}

void killchord4()
{
 kill_note(3,45+00,chordlevel1);
 kill_note(3,45+12,chordlevel1);
 kill_note(3,45+24,chordlevel1);
}

//C3 C4
void playchord5()
{
 play_note(3,60+00,chordlevel);
 play_note(3,60+12,chordlevel);
}

void killchord5()
{
 kill_note(3,60,chordlevel);
 kill_note(3,60+12,chordlevel);
}

//F3 F4
void playchord6()
{
 play_note(3,65+00,chordlevel);
 play_note(3,65+12,chordlevel);
}

void killchord6()
{
 kill_note(3,65,chordlevel);
 kill_note(3,65+12,chordlevel);
}

//G3 G4
void playchord7()
{
 play_note(3,67+00,chordlevel);
 play_note(3,67+12,chordlevel);
}

void killchord7()
{
 kill_note(3,67,chordlevel);
 kill_note(3,67+12,chordlevel);
}

//A3 A4
void playchord8()
{
 play_note(3,69+00,chordlevel);
 play_note(3,69+12,chordlevel);
}

void killchord8()
{
 kill_note(3,69,chordlevel);
 kill_note(3,69+12,chordlevel);
}

//D2 & D3
void playchord0()
{
 play_note(3,62+12,chordlevel);
 play_note(3,62+24,chordlevel);
}

void killchord0()
{
 kill_note(3,62+12,chordlevel);
 kill_note(3,62+24,chordlevel);
}

//C4 C5
void playchord9()
{
 play_note(3,60+12,chordlevel);
 play_note(3,60+24,chordlevel);
}

void killchord9()
{
 kill_note(3,60+12,chordlevel);
 kill_note(3,60+24,chordlevel);
}
void playchordF1()
{
 play_note(3,E4,endchordlevel);
 play_note(3,D4,endchordlevel);
 play_note(3,E3,endchordlevel);
 play_note(3,D3,endchordlevel);
}

void killchordF1()
{
 kill_note(3,E4,endchordlevel);
 kill_note(3,D4,endchordlevel);
 kill_note(3,E3,endchordlevel);
 kill_note(3,D3,endchordlevel);
}

void playchordF2()
{
 play_note(3,D4,endchordlevel);
 play_note(3,D3,endchordlevel);
}

void killchordF2()
{
 kill_note(3,D4,endchordlevel);
 kill_note(3,D3,endchordlevel);
}

void playchordF3()
{
 play_note(3,E4,endchordlevel);
 play_note(3,C4,endchordlevel);
 play_note(3,E3,endchordlevel);
 play_note(3,C3,endchordlevel);
}

void killchordF3()
{
 kill_note(3,E4,endchordlevel);
 kill_note(3,C4,endchordlevel);
 kill_note(3,E3,endchordlevel);
 kill_note(3,C3,endchordlevel);
}

void playchordF4()
{
 play_note(3,F4,endchordlevel);
 play_note(3,C4,endchordlevel);
 play_note(3,F3,endchordlevel);
 play_note(3,C3,endchordlevel);
}

void killchordF4()
{
 kill_note(3,F4,endchordlevel);
 kill_note(3,C4,endchordlevel);
 kill_note(3,F3,endchordlevel);
 kill_note(3,C3,endchordlevel);
}

void playchordF5()
{
 play_note(3,E4,endchordlevel);
 play_note(3,E3,endchordlevel);
}

void killchordF5()
{
 kill_note(3,E4,endchordlevel);
 kill_note(3,E3,endchordlevel);
}

void playchordF6()
{
 play_note(3,C4,endchordlevel);
 play_note(3,C3,endchordlevel);
}

void killchordF6()
{
 kill_note(3,C4,endchordlevel);
 kill_note(3,C3,endchordlevel);
}

void dostuff()
{

        if ((notes[INDEX_0] == 0) && (key_table[INDEX_0]==1))
        {
          notes[INDEX_0]=1;
          playchord0();
        }
        if ((notes[INDEX_0] == 1) && (key_table[INDEX_0]==0))
        {
          killchord0();
          notes[INDEX_0]=0;
        }

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

        if ((notes[INDEX_RIGHT] == 0) && (key_table[INDEX_RIGHT]==1))
        {
          notes[INDEX_RIGHT]=1;
          playchord6();
        }
        if ((notes[INDEX_RIGHT] == 1) && (key_table[INDEX_RIGHT]==0))
        {
          killchord6();
          notes[INDEX_RIGHT]=0;
        }

        if ((notes[INDEX_7] == 0) && (key_table[INDEX_7]==1))
        {
          notes[INDEX_7]=1;
          playchord7();
        }
        if ((notes[INDEX_7] == 1) && (key_table[INDEX_7]==0))
        {
          killchord7();
          notes[INDEX_7]=0;
        }

        if ((notes[INDEX_9] == 0) && (key_table[INDEX_9]==1))
        {
          notes[INDEX_9]=1;
          playchord9();
        }
        if ((notes[INDEX_9] == 1) && (key_table[INDEX_9]==0))
        {
          killchord9();
          notes[INDEX_9]=0;
        }

        if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
        {
          notes[INDEX_UP]=1;
          playchord8();
        }
        if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))
        {
          killchord8();
          notes[INDEX_UP]=0;
        }

        if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
        {
          notes[INDEX_F1]=1;
          playchordF1();
        }
        if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
        {
          killchordF1();
          notes[INDEX_F1]=0;
        }

        if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
        {
          notes[INDEX_F2]=1;
          playchordF2();
        }
        if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
        {
          killchordF2();
          notes[INDEX_F2]=0;
        }

        if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
        {
          notes[INDEX_F3]=1;
          playchordF3();
        }
        if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
        {
          killchordF3();
          notes[INDEX_F3]=0;
        }

        if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
        {
          notes[INDEX_F4]=1;
          playchordF4();
        }
        if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
        {
          killchordF4();
          notes[INDEX_F4]=0;
        }

        if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
        {
          notes[INDEX_F5]=1;
          playchordF5();
        }
        if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
        {
          killchordF5();
          notes[INDEX_F5]=0;
        }

        if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
        {
          notes[INDEX_F6]=1;
          playchordF6();
        }
        if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
        {
          killchordF6();
          notes[INDEX_F6]=0;
        }

}

void playkillerchord1()
{
 play_note(2,D4+12,brasslevel);
 play_note(2,A3+12,brasslevel);
}

void killkillerchord1()
{
 kill_note(2,D4+12,brasslevel);
 kill_note(2,A3+12,brasslevel);
}

void playkillerchord2()
{
 play_note(2,C4+12,brasslevel);
 play_note(2,A3+12,brasslevel);
}

void killkillerchord2()
{
 kill_note(2,C4+12,brasslevel);
 kill_note(2,A3+12,brasslevel);
}

void playkillerchord3()
{
 play_note(2,G3+12,brasslevel);
 play_note(2,B3+12,brasslevel);
}

void killkillerchord3()
{
 kill_note(2,G3+12,brasslevel);
 kill_note(2,B3+12,brasslevel);
}

void playkillerchord4()
{
 play_note(guitarchannel,AS2,guitarlevel-30);
 play_note(guitarchannel,F3,guitarlevel-30);
// play_note(guitarchannel,D4,guitarlevel);
}

void killkillerchord4()
{
 kill_note(guitarchannel,AS2,guitarlevel-30);
 kill_note(guitarchannel,F3,guitarlevel-30);
// kill_note(guitarchannel,D4,guitarlevel-30);
}

void playkillerchord5()
{
 play_note(guitarchannel,C3,guitarlevel-30);
 play_note(guitarchannel,G3,guitarlevel-30);
// play_note(guitarchannel,E4,guitarlevel-30);
}

void killkillerchord5()
{
 kill_note(guitarchannel,C3,guitarlevel-30);
 kill_note(guitarchannel,G3,guitarlevel-30);
// kill_note(guitarchannel,E4,guitarlevel-30);
}

void playkillerchord6()
{
 play_note(guitarchannel,G2,guitarlevel-30);
 play_note(guitarchannel,C3,guitarlevel-30);
}

void killkillerchord6()
{
 kill_note(guitarchannel,G2,guitarlevel-30);
 kill_note(guitarchannel,C3,guitarlevel-30);
}

void playkillerchord7()
{
 play_note(brasschannel,D5,brasslevel);
 play_note(brasschannel,F5,brasslevel);
 play_note(guitarchannel,D5,brasslevel);
 play_note(guitarchannel,F5,brasslevel);
}

void killkillerchord7()
{
 kill_note(brasschannel,D5,brasslevel);
 kill_note(brasschannel,F5,brasslevel);
 kill_note(guitarchannel,D5,brasslevel);
 kill_note(guitarchannel,F5,brasslevel);
}

void playkillerchorda()
{
 play_note(guitarchannel,D3,guitarlevel);
 play_note(guitarchannel,A3,guitarlevel);
}

void killkillerchorda()
{
 kill_note(guitarchannel,D3,guitarlevel);
 kill_note(guitarchannel,A3,guitarlevel);
}

void playkillerchordb()
{
 play_note(guitarchannel,F3,guitarlevel);
 play_note(guitarchannel,AS2,guitarlevel);
}

void killkillerchordb()
{
 kill_note(guitarchannel,F3,guitarlevel);
 kill_note(guitarchannel,AS2,guitarlevel);
}

void playkillerchordc()
{
 play_note(guitarchannel,G2,guitarlevel);
 play_note(guitarchannel,D3,guitarlevel);
}

void killkillerchordc()
{
 kill_note(guitarchannel,G2,guitarlevel);
 kill_note(guitarchannel,D3,guitarlevel);
}

void playkillerchordd()
{
 play_note(guitarchannel,A2,guitarlevel);
 play_note(guitarchannel,E3,guitarlevel);
}

void killkillerchordd()
{
 kill_note(guitarchannel,A2,guitarlevel);
 kill_note(guitarchannel,E3,guitarlevel);
}

void playkillerchord8()
{
 play_note(brasschannel,E5,brasslevel);
 play_note(brasschannel,C5,brasslevel);
 play_note(guitarchannel,E5,brasslevel);
 play_note(guitarchannel,C5,brasslevel);
}

void killkillerchord8()
{
 kill_note(brasschannel,E5,brasslevel);
 kill_note(brasschannel,C5,brasslevel);
 kill_note(guitarchannel,E5,brasslevel);
 kill_note(guitarchannel,C5,brasslevel);
}

void playkillerchord9()
{
 play_note(brasschannel,D5,brasslevel);
 play_note(brasschannel,AS4,brasslevel);
 play_note(guitarchannel,D5,brasslevel);
 play_note(guitarchannel,AS4,brasslevel);
}

void killkillerchord9()
{
 kill_note(brasschannel,D5,brasslevel);
 kill_note(brasschannel,AS4,brasslevel);
 kill_note(guitarchannel,D5,brasslevel);
 kill_note(guitarchannel,AS4,brasslevel);
}

void playkillerchord10()
{
 play_note(brasschannel,AS5,brasslevel);
 play_note(brasschannel,F5,brasslevel);
 play_note(guitarchannel,AS5,brasslevel);
 play_note(guitarchannel,F5,brasslevel);
}

void killkillerchord10()
{
 kill_note(brasschannel,AS5,brasslevel);
 kill_note(brasschannel,F5,brasslevel);
 kill_note(guitarchannel,AS5,brasslevel);
 kill_note(guitarchannel,F5,brasslevel);
}

void playkillerchord11()
{
 play_note(brasschannel,G5,brasslevel);
 play_note(brasschannel,E5,brasslevel);
 play_note(guitarchannel,G5,brasslevel);
 play_note(guitarchannel,E5,brasslevel);
}

void killkillerchord11()
{
 kill_note(brasschannel,G5,brasslevel);
 kill_note(brasschannel,E5,brasslevel);
 kill_note(guitarchannel,G5,brasslevel);
 kill_note(guitarchannel,E5,brasslevel);
}

void playkillerchord12()
{
 play_note(brasschannel,C6,brasslevel);
 play_note(brasschannel,G5,brasslevel);
 play_note(guitarchannel,C6,brasslevel);
 play_note(guitarchannel,G5,brasslevel);
}

void killkillerchord12()
{
 kill_note(brasschannel,C6,brasslevel);
 kill_note(brasschannel,G5,brasslevel);
 kill_note(guitarchannel,C6,brasslevel);
 kill_note(guitarchannel,G5,brasslevel);
}

void playkillerchordq()
{
 play_note(1,E3,guitarlevel);
}

void killkillerchordq()
{
 kill_note(1,E3,guitarlevel);
}

void playkillerchordw()
{
 play_note(1,FS3,guitarlevel);
}

void killkillerchordw()
{
 kill_note(1,FS3,guitarlevel);
}

void playkillerchorde()
{
 play_note(1,G3,guitarlevel);
}

void killkillerchorde()
{
 kill_note(1,G3,guitarlevel);
}

void playkillerchordr()
{
 play_note(1,F3,guitarlevel);
}

void killkillerchordr()
{
 kill_note(1,F3,guitarlevel);
}

void do_killer_stuff()
{
        if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
        {
          notes[INDEX_F1]=1;
          playkillerchord1();
        }
        if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
        {
          killkillerchord1();
          notes[INDEX_F1]=0;
        }

        if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
        {
          notes[INDEX_F2]=1;
          playkillerchord2();
        }
        if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
        {
          killkillerchord2();
          notes[INDEX_F2]=0;
        }

        if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
        {
          notes[INDEX_F3]=1;
          playkillerchord3();
        }
        if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
        {
          killkillerchord3();
          notes[INDEX_F3]=0;
        }

        if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
        {
          notes[INDEX_F4]=1;
          playkillerchord4();
        }
        if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
        {
          killkillerchord4();
          notes[INDEX_F4]=0;
        }

        if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
        {
          notes[INDEX_F5]=1;
          playkillerchord5();
        }
        if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
        {
          killkillerchord5();
          notes[INDEX_F5]=0;
        }

        if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
        {
          notes[INDEX_F6]=1;
          playkillerchord6();
        }
        if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
        {
          killkillerchord6();
          notes[INDEX_F6]=0;
        }

        if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
        {
          notes[INDEX_F7]=1;
          playkillerchord7();
        }
        if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
        {
          killkillerchord7();
          notes[INDEX_F7]=0;
        }

        if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
        {
          notes[INDEX_F8]=1;
          playkillerchord8();
        }
        if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))
        {
          killkillerchord8();
          notes[INDEX_F8]=0;
        }

        if ((notes[INDEX_F9] == 0) && (key_table[INDEX_F9]==1))
        {
          notes[INDEX_F9]=1;
          playkillerchord9();
        }
        if ((notes[INDEX_F9] == 1) && (key_table[INDEX_F9]==0))
        {
          killkillerchord9();
          notes[INDEX_F9]=0;
        }

        if ((notes[INDEX_F10] == 0) && (key_table[INDEX_F10]==1))
        {
          notes[INDEX_F10]=1;
          playkillerchord10();
        }
        if ((notes[INDEX_F10] == 1) && (key_table[INDEX_F10]==0))
        {
          killkillerchord10();
          notes[INDEX_F10]=0;
        }

        if ((notes[INDEX_F11] == 0) && (key_table[INDEX_F11]==1))
        {
          notes[INDEX_F11]=1;
          playkillerchord11();
        }
        if ((notes[INDEX_F11] == 1) && (key_table[INDEX_F11]==0))
        {
          killkillerchord11();
          notes[INDEX_F11]=0;
        }

        if ((notes[INDEX_F12] == 0) && (key_table[INDEX_F12]==1))
        {
          notes[INDEX_F12]=1;
          playkillerchord12();
        }
        if ((notes[INDEX_F12] == 1) && (key_table[INDEX_F12]==0))
        {
          killkillerchord12();
          notes[INDEX_F12]=0;
        }

        if ((notes[INDEX_A] == 0) && (key_table[INDEX_A]==1))
        {
          notes[INDEX_A]=1;
          playkillerchorda();
        }
        if ((notes[INDEX_A] == 1) && (key_table[INDEX_A]==0))
        {
          killkillerchorda();
          notes[INDEX_A]=0;
        }

        if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
        {
          notes[INDEX_Q]=1;
          playkillerchordq();
        }
        if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))
        {
          killkillerchordq();
          notes[INDEX_Q]=0;
        }

        if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
        {
          notes[INDEX_W]=1;
          playkillerchordw();
        }
        if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))
        {
          killkillerchordw();
          notes[INDEX_W]=0;
        }

        if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
        {
          notes[INDEX_E]=1;
          playkillerchorde();
        }
        if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))
        {
          killkillerchorde();
          notes[INDEX_E]=0;
        }

        if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
        {
          notes[INDEX_R]=1;
          playkillerchordr();
        }
        if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))
        {
          killkillerchordr();
          notes[INDEX_R]=0;
        }

        if ((notes[INDEX_S] == 0) && (key_table[INDEX_S]==1))
        {
          notes[INDEX_S]=1;
          playkillerchordb();
        }
        if ((notes[INDEX_S] == 1) && (key_table[INDEX_S]==0))
        {
          killkillerchordb();
          notes[INDEX_S]=0;
        }

        if ((notes[INDEX_D] == 0) && (key_table[INDEX_D]==1))
        {
          notes[INDEX_D]=1;
          playkillerchordc();
        }
        if ((notes[INDEX_D] == 1) && (key_table[INDEX_D]==0))
        {
          killkillerchordc();
          notes[INDEX_D]=0;
        }

        if ((notes[INDEX_F] == 0) && (key_table[INDEX_F]==1))
        {
          notes[INDEX_F]=1;
          playkillerchordd();
        }
        if ((notes[INDEX_F] == 1) && (key_table[INDEX_F]==0))
        {
          killkillerchordd();
          notes[INDEX_F]=0;
        }

}

int delay_killer(int speed)
{
   for (int index=0;index<speed;index++)
   {
      do_killer_stuff();
      delay(1);
      if (key_table[INDEX_ESC]) return 1;
   }
   return 0;
}

//***
void vampire_killer(int speed)
{
   clrscr();
//   change_program(brasschannel,36,3);  //18 4 
   change_program(guitarchannel,37,2); // old 29 4
   change_program(2,22,3); //old 22 3
   change_program(2,90,1);
   cout << "Vampire Killer!";
   cout << "\nESC: Quit";
   int measure = 1;
   int index0;

   while (1)
   {
   //2
   cout << "\nMeasure: " << ++measure;
   if (delay_killer(speed*8)) break;
   kill_note(1,38,127);
   play_note(1,38,75);
   play_note(ahhchannel,D4,ahhlevel);
   play_note(D3,13,127);
   play_note(10,CS2,127);
   play_note(doomtomchannel,A2,127);
   if (delay_killer(speed*4)) break;
   kill_note(doomtomchannel,A2,127);
   kill_note(10,CS2,127);
   kill_note(ahhchannel,D4,ahhlevel);
   play_note(ahhchannel,A4,ahhlevel);
   if (delay_killer(speed*4)) break;
   kill_note(ahhchannel,A4,ahhlevel);
   //3
   cout << "\nMeasure: " << ++measure;
   play_note(ahhchannel,GS4,ahhlevel);
   if (delay_killer(speed*8)) break;
   kill_note(ahhchannel,GS4,ahhlevel);
   play_note(ahhchannel,D4,ahhlevel);
   play_note(doomtomchannel,A2,127);
   if (delay_killer(speed*4)) break;
   kill_note(doomtomchannel,A2,127);
   kill_note(ahhchannel,D4,ahhlevel);
   play_note(ahhchannel,A4,ahhlevel);
   if (delay_killer(speed*4)) break;
   kill_note(ahhchannel,A4,ahhlevel);
   //4
   cout << "\nMeasure: " << ++measure;
   play_note(ahhchannel,B4,ahhlevel);
   play_note(ahhchannel,GS4,ahhlevel);
   if (delay_killer(speed*8)) break;
   kill_note(ahhchannel,B4,ahhlevel);
   kill_note(ahhchannel,GS4,ahhlevel);
   play_note(ahhchannel,D4,ahhlevel);
   play_note(doomtomchannel,A2,127);
   if (delay_killer(speed*4)) break;
   kill_note(doomtomchannel,A2,127);
   kill_note(ahhchannel,D4,ahhlevel);
   play_note(ahhchannel,A4,ahhlevel);
   play_note(ahhchannel,C5,ahhlevel);
   if (delay_killer(speed*4)) break;
   kill_note(ahhchannel,A4,ahhlevel);
   kill_note(ahhchannel,C5,ahhlevel);
   kill_note(1,38,75);
   change_program(1,54,3);
   //5
   all_lights_off(0);

   cout << "\nMeasure: " << ++measure;
   play_note(ahhchannel,GS4,ahhlevel);
   play_note(10,FS1,127);
   if (delay_killer(speed*4)) break;
   kill_note(ahhchannel,GS4,ahhlevel);
   kill_note(D3,13,127);
   play_note(ahhchannel,B4,ahhlevel);
   play_note(ahhchannel,D5,ahhlevel);
   play_note(ahhchannel,F5,ahhlevel);
   kill_note(10,FS1,127);
   play_note(10,FS1,127);
   if (delay_killer(speed)) break;
   if (delay_killer(speed)) break;
   if (delay_killer(speed)) break;
   if (delay_killer(speed)) break;
   kill_note(10,FS1,127);
   play_note(10,FS1,127);
   if (delay_killer(speed)) break;
   if (delay_killer(speed)) break;
   if (delay_killer(speed)) break;
   if (delay_killer(speed)) break;
   kill_note(10,FS1,127);
   play_note(10,FS1,127);
   if (delay_killer(speed)) break;
   if (delay_killer(speed)) break;
   if (delay_killer(speed)) break;
   if (delay_killer(speed)) break;
   kill_note(10,FS1,127);
   kill_note(ahhchannel,B4,ahhlevel);
   kill_note(ahhchannel,D5,ahhlevel);
   kill_note(ahhchannel,F5,ahhlevel);
   break;
   }

   change_light_level(1,50);
   change_light_level(2,75);
   change_light_level(3,25);
   change_light_level(4,50);
   
   kill_note(1,38,127);
   while (1)
   {
      for (int big=0;big<2;big++)
      {
      //6
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,A2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,A2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);

      //7
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,F2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,F2,127);
      play_note(basschannel,C2,127);
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,C2,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,C2,127);
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,G2,127);
      play_note(10,C1,127);
      play_note(10,CS2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G2,127);
      play_note(basschannel,C2,127);
      kill_note(10,C1,127);
      kill_note(10,CS2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,C2,127);

      //new 8 (6)
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,A2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,A2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);

      //9
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,F2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      play_note(10,F1,127);
      play_note(10,G1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,F2,127);
      play_note(basschannel,C2,127);
      kill_note(10,GS1,127);
      kill_note(10,F1,127);
      kill_note(10,G1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,C2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break; 
      change_program(2,102,4);

      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;

      all_lights_off(0);
      change_light_level(2,100);
      change_light_level(1,25);
      //10
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      play_note(10,CS1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,CS1,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      play_note(10,CS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,CS1,127);
      if (delay_killer(speed)) break;
      play_note(10,DS4,127);
      if (delay_killer(speed)) break;
      kill_note(10,DS4,127);
      play_note(10,DS4,127);
      if (delay_killer(speed)) break;
      kill_note(10,DS4,127);

      //11
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,GS1,127);
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      play_note(10,CS1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,CS1,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      play_note(10,CS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,CS1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;

      //12
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,GS1,127);
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      play_note(10,CS1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,CS1,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      play_note(10,CS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,CS1,127);
      if (delay_killer(speed)) break;
      play_note(10,DS4,127);
      if (delay_killer(speed)) break;
      kill_note(10,DS4,127);
      play_note(10,DS4,127);
      if (delay_killer(speed)) break;
      kill_note(10,DS4,127);

      //13
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,GS1,127);
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      play_note(10,CS1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,CS1,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      play_note(10,CS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,CS1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      all_lights_off(0);
      change_light_level(1,127);

      //14
//      change_program(2,29,4);
      change_program(2,90,1);
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(basschannel,CS2,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,CS2,127);
      play_note(basschannel,CS2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,CS2,127);
      play_note(basschannel,CS2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,CS2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      play_note(10,CS2,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,CS2,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);

      //15
      cout << "\nMeasure: " << ++measure;
      play_note(basschannel,E2,127);
      play_note(10,C1,127);
      play_note(10,A2,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,A2,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,E2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      play_note(10,CS2,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,CS2,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      kill_note(basschannel,D2,127);

      //16
      cout << "\nMeasure: " << ++measure;
      play_note(basschannel,CS2,127);
      play_note(10,C1,127);
      play_note(10,A2,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,CS2,127);
      play_note(basschannel,CS2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,CS2,127);
      play_note(basschannel,CS2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,CS2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      play_note(10,CS2,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,CS2,127);
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,C1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);

      //17
      cout << "\nMeasure: " << ++measure;
      play_note(basschannel,E2,127);
      play_note(10,A2,127);
      play_note(10,GS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,A2,127);
      kill_note(10,GS1,127);
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,E2,127);
      play_note(basschannel,E2,127);
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,E2,127);
      play_note(basschannel,A2,127);

      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A2,127);
      play_note(basschannel,B2,127);
      kill_note(10,C2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      play_note(10,A1,127);
      if (delay_killer(speed)) break;
      kill_note(10,A1,127);
      play_note(10,G1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,B2,127);
      play_note(basschannel,CS3,127);
      kill_note(10,G1,127);
      play_note(10,F1,127);
      if (delay_killer(speed)) break;
      kill_note(10,F1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      kill_note(basschannel,CS3,127);

      all_lights_off(0);
      //18
      cout << "\nMeasure: " << ++measure;
      play_note(10,AS1,127);
      if (delay_killer(speed*4)) break;
      kill_note(10,AS1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed*4)) break;
      kill_note(10,AS1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed*4)) break;
      kill_note(10,AS1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed*4)) break;
      kill_note(10,AS1,127);

      change_light_level(1,50);
      change_light_level(2,75);
      change_light_level(3,25);
      change_light_level(4,50);

      //19
      for (index0=0;index0<2;index0++)
      {
      cout << "\nMeasure: " << ++measure;
      play_note(10,D1,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,C2,127);
      kill_note(10,D1,127);
      play_note(10,B1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,D2,127);
      kill_note(10,B1,127);
      play_note(10,C1,127);
      play_note(10,CS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,CS1,127);
      kill_note(10,B1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D3,127);
      kill_note(10,D1,127);
      play_note(10,B1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D3,127);
      play_note(basschannel,A2,127);
      kill_note(10,B1,127);
      play_note(10,G1,127);
      play_note(10,A1,127);
      if (delay_killer(speed/2)) break;
      kill_note(basschannel,A2,127);
      play_note(basschannel,F2,127);
      if (delay_killer(speed/2)) break;
      kill_note(basschannel,F2,127);
      play_note(basschannel,D2,127);
      kill_note(10,G1,127);
      kill_note(10,A1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D3,127);
      play_note(10,D1,127);
      play_note(10,A1,127);
      if (delay_killer(speed)) break;
      kill_note(10,A1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,D1,127);
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      kill_note(basschannel,D3,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      kill_note(10,FS1,127);

      //20
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      kill_note(10,GS1,127);
      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,D2,127);
      kill_note(10,GS1,127);
      play_note(10,C1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,F2,127);
      kill_note(10,C1,127);
      kill_note(10,D1,127);
      play_note(10,C1,127);
      play_note(10,CS2,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,CS2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,F2,127);
      play_note(basschannel,C2,127);
      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,C2,127);
      kill_note(10,GS1,127);
      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,C2,127);
      play_note(basschannel,E2,127);
      kill_note(10,GS1,127);
      play_note(10,C1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,D1,127);
      play_note(10,C1,127);
      play_note(10,CS2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,E2,127);
      play_note(basschannel,G2,127);
      kill_note(10,C1,127);
      kill_note(10,CS2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,G2,127);
      }
      }

      te:
      all_lights_off(0);
      change_light_level(2,100);
      change_light_level(1,25);

      //40
      change_program(1,54,2);
      change_program(2,54,2);
      cout << "\nMeasure: " << ++measure;
      play_note(10,FS1,127);
      play_note(basschannel,D2,basslevel);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,basslevel);
      play_note(basschannel,D2,basslevel);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,basslevel);
      play_note(basschannel,F2,basslevel);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,F2,basslevel);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      if (delay_killer(speed)) break;
      play_note(basschannel,D2,basslevel);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,basslevel);
      play_note(basschannel,G2,basslevel);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,G2,basslevel);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;

      //41
      cout << "\nMeasure: " << ++measure;
      play_note(10,FS1,127);
      play_note(basschannel,D2,basslevel);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,basslevel);
      play_note(basschannel,D2,basslevel);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,basslevel);
      play_note(basschannel,F2,basslevel);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,F2,basslevel);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      if (delay_killer(speed)) break;
      play_note(10,FS1,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      kill_note(10,FS1,127);
      play_note(10,AS1,127);
      play_note(basschannel,C2,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,C2,127);

      //42
      cout << "\nMeasure: " << ++measure;
      play_note(10,GS1,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,F2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,F2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      if (delay_killer(speed)) break;
      play_note(10,D2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,A1,127);
      kill_note(10,D2,127);
      play_note(10,A1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,G2,127);
      kill_note(10,A1,127);
      play_note(10,G2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,G2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(10,G2,127);

      //43
      cout << "\nMeasure: " << ++measure;
      play_note(10,FS1,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,F2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,F2,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      if (delay_killer(speed)) break;
      play_note(10,FS1,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,FS1,127);
      play_note(10,FS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,C2,127);
      kill_note(10,FS1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      kill_note(basschannel,C2,127);
      all_lights_off(0);

      //44
      change_light_level(5,127);
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,A2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,A2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,AS1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,A2,127);
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,F2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,F2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,E2,127);
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,E2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,C2,127);
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,C2,127);

      //45
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      kill_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS2,127);
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS2,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,G2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G2,127);
      play_note(basschannel,AS1,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,F2,127);
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,F2,127);
      play_note(basschannel,AS1,127);
      play_note(10,C1,127);
      play_note(10,A2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,E2,127);
      kill_note(10,C1,127);
      kill_note(10,A2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,E2,127);

      //46
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,CS2,127);
      play_note(basschannel,G1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,CS2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);
      kill_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);

      //47
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,CS2,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,CS2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      kill_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      play_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,A2,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,D1,127);
      kill_note(10,A2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);

      //new 48
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,A2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,A2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      kill_note(10,AS1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,A2,127);
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A2,127);
      play_note(basschannel,D2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,F2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,F2,127);
      play_note(basschannel,D2,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,E2,127);
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,E2,127);
      play_note(basschannel,D2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,D2,127);
      play_note(basschannel,C2,127);
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,C2,127);

      //new 49 45
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      kill_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS1,127);
      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,AS2,127);
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS2,127);
      play_note(basschannel,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,G2,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G2,127);
      play_note(basschannel,AS1,127);
      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,F2,127);
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,F2,127);
      play_note(basschannel,AS1,127);
      play_note(10,C1,127);
      play_note(10,A2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,AS1,127);
      play_note(basschannel,E2,127);
      kill_note(10,C1,127);
      kill_note(10,A2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,E2,127);

      //new 50 46
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,CS2,127);
      play_note(basschannel,G1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,CS2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);
      kill_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      kill_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);
      play_note(basschannel,G1,127);

      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,G1,127);

      //new 51 47
      cout << "\nMeasure: " << ++measure;
      play_note(10,C1,127);
      play_note(10,CS2,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,CS2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      kill_note(10,C1,127);
      play_note(10,AS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      play_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,A2,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,D1,127);
      kill_note(10,A2,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      kill_note(10,C1,127);
      play_note(10,C1,127);
      play_note(10,D1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,C1,127);
      kill_note(10,D1,127);
      kill_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);
      play_note(basschannel,A1,127);
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(basschannel,A1,127);

      //52 (LAST ONE!)
      cout << "\nMeasure: " << ++measure;
      all_lights_off(0);

      change_light_level(1,20);
      change_light_level(2,100);

      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,C1,127);
      play_note(10,AS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,C1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,GS1,127);
      play_note(10,AS1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,AS1,127);
      kill_note(10,C1,127);
      play_note(10,GS1,127);
      if (delay_killer(speed)) break;
      kill_note(10,GS1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,D1,127);
      if (delay_killer(speed)) break;
      kill_note(10,D1,127);
      play_note(10,A1,127);
      if (delay_killer(speed)) break;
      kill_note(10,A1,127);
      play_note(10,G1,127);
      if (delay_killer(speed)) break;
      kill_note(10,G1,127);
      play_note(10,F1,127);
      play_note(10,C1,127);
      if (delay_killer(speed)) break;
      kill_note(10,F1,127);
      kill_note(10,C1,127);
      if (delay_killer(speed)) break;
      play_note(10,A2,127);
      play_note(10,CS1,127);
      play_note(guitarchannel,D5-12,127);
      play_note(guitarchannel,F5-12,127);
      play_note(guitarchannel,D4-12,127);
      play_note(guitarchannel,F3-12,127);
      play_note(guitarchannel,D4-12,127);
      play_note(guitarchannel,A3-12,127);
      change_light_level(1,127);
      change_light_level(2,127);
      change_light_level(3,127);
      change_light_level(4,127);

      if (delay_killer(speed*128)) break;
      kill_note(guitarchannel,D5-12,127);
      kill_note(guitarchannel,F5-12,127);
      kill_note(guitarchannel,D4-12,127);
      kill_note(guitarchannel,F3-12,127);
      kill_note(guitarchannel,D4-12,127);
      kill_note(guitarchannel,A3-12,127);
      kill_note(10,A2,127);
      kill_note(10,CS1,127);
      break;
   }
   wait_for_no(INDEX_ESC);
}

void title()
{
   clrscr();
   cout << "Castlevania Music";
   cout << "\n\n1: Bloody Tears";
   cout << "\n3: Vampire Killer";
   cout << "\nESC: Quit";
}

void main()
{                            
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        for (int index=0;index<127;index++)
                notes[index] = 0;
        title();
        all_lights_off(0);
        while (1)
        {
                if ((notes[INDEX_RIGHT] == 0) && (key_table[INDEX_RIGHT]==1))
                {
                  notes[INDEX_RIGHT]=1;
                  play_note(1,45,127);
                }
                if ((notes[INDEX_RIGHT] == 1) && (key_table[INDEX_RIGHT]==0))
                {
                  kill_note(1,45,127);
                  notes[INDEX_RIGHT]=0;
                }

                if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))
                {
                  notes[INDEX_DOWN]=1;
                  play_note(1,38,127);
                  all_lights_off(0);
                  fade_in_light(1,150,127,2);                 
                }

                if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))
                {
                  kill_note(1,38,127);
                  notes[INDEX_DOWN]=0;
                }

                if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
                {
                  notes[INDEX_UP]=1;
                  play_note(1,48,127);
                }

                if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))
                {
                  kill_note(1,48,127);
                  notes[INDEX_UP]=0;
                }

                if (key_table[INDEX_3])
                {
                   vampire_killer(118);
                   title();
                }
                delay(1);
                do_fade_stuff();
                do_killer_stuff();

                if (key_table[INDEX_LEFT])
                {
                   if (notes[CS5] != 1)
                   {
                      play_note(14,CS5,127);
                      notes[CS5] = 1;
                   }
                }

                if (key_table[INDEX_1])
                {
//                 change_light_level(1,50);
                   kill_note(1,45,127);
                   kill_note(1,48,127);
                   kill_note(1,38,127);
                   loop(125,10);
                   all_lights_off(0);
                   change_light_level(1,127);
                   play_note(1,38,127);
                   delay(2500);
                   vampire_killer(118);
                   title();
                }
                if (key_table[INDEX_ESC]) break;
        }
        kill_keyboard();
        Exit_MIDI();
}
