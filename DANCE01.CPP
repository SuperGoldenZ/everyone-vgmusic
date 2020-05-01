#include "midi.h"
#include <dos.h>
#include <conio.h>
#include "gameprog\keyboard.h"

const int channel = 1;
const int channel2 = 2;
const int speed = 45;
const int drumchannel = 16;

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

//35      Acoustic Bass Drum      59      Ride Cymbal 2
//36      Bass Drum 1             60      Hi Bongo
//37      Side Stick              61      Low Bongo
//38      Acoustic Snare          62      Mute Hi Conga
//39      Hand Clap               63      Open Hi Conga
//40      Electric Snare          64      Low Conga
//41      Low Floor Tom           65      High Timbale
//42      Closed Hi Hat           66      Low Timbale
//43      High Floor Tom          67      High Agogo
//44      Pedal Hi-Hat            68      Low Agogo
//45      Low Tom                 69      Cabasa
//46      Open Hi-Hat             70      Maracas
//47      Low-Mid Tom             71      Short Whistle
//48      Hi Mid Tom              72      Long Whistle
//49      Crash Cymbal 1          73      Short Guiro
//50      High Tom                74      Long Guiro
//51      Ride Cymbal 1           75      Claves
//52      Chinese Cymbal          76      Hi Wood Block
//53      Ride Bell               77      Low Wood Block
//54      Tambourine              78      Mute Cuica
//55      Splash Cymbal           79      Open Cuica
//56      Cowbell                 80      Mute Triangle
//57      Crash Cymbal 2          81      Open Triangle
//58      Vibraslap        

#define A3 69
#define A4 81
#define A6 105

#define E3 64
#define E4 76

#define D3 62
#define D4 74

#define B3 71

#define C1 36
#define C2 48
#define C3 60
#define C4 72
#define C5 84

#define CS4 73

#define GS2 104-24-24
#define GS4 104-24
#define GS6 104

#define D6 98

#define F3 65
#define F4 F3 + 12
#define FS2 54

void change_program(char channel, char prognum)
{
 channel--;
 char message[3];
 message[0] = 0xc0;
 message[0] += channel;
 message[1] = prognum;
 Send_MIDI_Message(message,2);
}

void change_bank(char channel, char bank)
{
 channel--;
 char message[3];
 message[0] = 0xb0;
 message[0]+= channel;
 message[1] = 0;
 message[2] = bank;
 Send_MIDI_Message(message,3);
}

void change_program(char channel, char prognum, char bank)
{
 change_bank(channel,bank);
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

int delay1(const int & speed)
{
for (int index=0;index<speed;index++)
        {
                if (key_table[INDEX_ESC]) return 1;
                if (key_table[INDEX_DOWN]) return 2;
                delay(1);
        }
return 0;
}

void loop2();

void loop1()
{
        clrscr();
        cout << "Loop 1";
        int temp;
        while (1)
        {
               cout << "\n1/8... "; 
               play_note(drumchannel,C1,127);
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
//               cout << "2/8... ";
               kill_note(drumchannel,C1,127);
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();

               cout << "3/8... ";  
               play_note(drumchannel,C1,127);
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
//               cout << "4/8... ";
               kill_note(drumchannel,C1,127);
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();

               cout << "5/8... ";
               play_note(drumchannel,C1,127);
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
//               cout << "6/8... ";
               kill_note(drumchannel,C1,127);
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();

               cout << "7/8... ";
               play_note(drumchannel,C1,127);
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();

//               cout << "8/8... ";
               kill_note(drumchannel,C1,127);
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();
               temp = delay1(speed); if (temp == 1) break; else if (temp == 2) loop2();

        }
        clrscr();
        cout << "Dance 1";
        cout << "\n1: Drum Loop 1";
        cout << "\nESC: Quit";

}

void loop2()
{
        wait_for_no(INDEX_DOWN);
        clrscr();
        cout << "Loop 2";
        while (1)
        {
               cout << "\n1/8... "; 
               play_note(drumchannel,C1,127);
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
//               cout << "2/8... "; 
               kill_note(drumchannel,C1,127);
               play_note(drumchannel,46,127);                 
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               kill_note(drumchannel,FS2,127);                 
               kill_note(drumchannel,GS2,127);                 

               cout << "3/8... ";  
               play_note(drumchannel,C1,127);
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
//               cout << "4/8... ";  
               kill_note(drumchannel,C1,127);
               play_note(drumchannel,46,127);                 
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               kill_note(drumchannel,FS2,127);                 
               kill_note(drumchannel,GS2,127);                 

               cout << "5/8... ";
               play_note(drumchannel,C1,127);
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
//               cout << "6/8... ";
               kill_note(drumchannel,C1,127);
               play_note(drumchannel,46,127);                 
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               kill_note(drumchannel,46,127);                 

               cout << "7/8... ";
               play_note(drumchannel,C1,127);
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
//               cout << "8/8... ";
               kill_note(drumchannel,C1,127);
               play_note(drumchannel,46,127);                 
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               if (delay1(speed)==1) break;
               kill_note(drumchannel,46,127);                 
        }
        clrscr();
        cout << "Dance 1";
        cout << "\n1: Drum Loop 1";
        cout << "\nESC: Quit";
}

void main()
{
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        change_program(drumchannel,121,2);
        change_program(1,101,1);
        clrscr();
        for (int index=0;index<127;index++)
                notes[index] = 0;
        clrscr();
        cout << "Dance 1";
        cout << "\n1: Drum Loop 1";
        cout << "\nESC: Quit";
        while (1)
        {
                if (key_table[INDEX_ESC]) break;
                if (key_table[INDEX_1]) loop1();
                if (key_table[INDEX_DOWN]) loop2();
        }
                kill_keyboard();
                Exit_MIDI();
    }
