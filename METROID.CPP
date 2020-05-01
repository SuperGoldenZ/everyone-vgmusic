#include <midi.h>
#include <dos.h>
#include <conio.h>
#include <keyboard.h>

const int channel = 1;
const int channel2 = 2;
const int speed = 280;

int notes[127];

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

#define A3 69
#define A4 81
#define A6 105

#define E3 64
#define E4 76

#define D3 62
#define D4 74

#define B3 71

#define C3 60
#define C4 72
#define C5 84

#define CS4 73

#define GS6 104
#define GS4 104-24

#define D6 98

#define F3 65
#define F4 F3 + 12


void change_program(char channel, char prognum)
{
 channel--;
 char message[3];
 message[0] = 0xc0;
 message[0] += channel;
 message[1] = prognum;
 Send_MIDI_Message(message,2);
}

void play_note(char channel, unsigned char note, char velocity)
{
 channel--;
 if ((channel >= 0) && (channel <= 15))
 {
  char message[3];
  message[0] = 0x90;
  message[0] += channel;
  message[1] = note;
  message[2] = velocity;
  Send_MIDI_Message(message,3);
 }
}

void kill_note(char channel, unsigned char note, char velocity)
{
 channel--;
         if ((channel >= 0) && (channel <= 15))
 {
  char message[3];
  message[0] = 0x80;
  message[0] += channel;
  message[1] = note;
  message[2] = velocity;
  Send_MIDI_Message(message,3);
 }
}

void dostuff1();

int delay2(const int &speed)
{
 int index;
 for (index=0;index<speed;index++)
 {
        delay(1);
        dostuff1();
        if (key_table[INDEX_ESC]) return 1;
 }
 return 0;
}

void introloop()
{
        clrscr();
        cout << "Metroid intro loop running PHASE 1...";
        cout << "\nPress ESC go to next phase...";
        for (int index=0;index<127;index++)
                notes[index] = 0;
        while(1)
        {

        cout << "\nOne... ";
        play_note(channel,C5,127);
        if (delay2(speed)) break;

        if (delay2(speed)) break;

        cout << "two... ";
        if (delay2(speed)) break;
        kill_note(channel,C5,127);
        if (delay2(speed)) break;

        cout << "three... ";
        play_note(channel,C5,127);
        if (delay2(speed)) break;

        if (delay2(speed)) break;

        cout << "four... ";

        if (delay2(speed)) break;
        kill_note(channel,C5,127);
        if (delay2(speed)) break;
        }
        wait_for_no(INDEX_ESC);
}

void dostuff1()
{
                if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
                {
                  notes[INDEX_F1]=1;
                  play_note(channel2,A6,127);
                }
                if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
                {
                  kill_note(channel2,A6,127);
                  notes[INDEX_F1]=0;
                }
        
                if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
                {
                  notes[INDEX_F2]=1;
                  play_note(channel2,GS6,127);
                }
                if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
                {
                  kill_note(channel2,GS6,127);
                  notes[INDEX_F2]=0;
                }
        
                if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
                {
                  notes[INDEX_F3]=1;
                  play_note(channel2,D6,127);
                }
                if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
                {
                  kill_note(channel2,D6,127);
                  notes[INDEX_F3]=0;
                }

                if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
                {
                  notes[INDEX_F4]=1;
                  play_note(channel2,A4,127);
                }
                if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
                {
                  kill_note(channel2,A4,127);
                  notes[INDEX_F4]=0;
                }
        
                if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
                {
                  notes[INDEX_F5]=1;
                  play_note(channel2,GS4,127);
                }
                if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
                {
                  kill_note(channel2,GS4,127);
                  notes[INDEX_F5]=0;
                }

}

void main()
{
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        clrscr();
        for (int index=0;index<127;index++)
                notes[index] = 0;
        introloop();
        clrscr();
        cout << "Metroid!!";
        cout << "\nESC: Quit";
        while (1)
        {
                if (key_table[INDEX_ESC]) break;
        }
                kill_keyboard();
                Exit_MIDI();
    }
