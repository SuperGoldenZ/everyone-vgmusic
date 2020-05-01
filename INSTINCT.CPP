#define chordchannel 3
#define drumchannel 2
#define basschannel 4

#include <dos.h>
#include "ikeys.h"

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

void bass1(char ch,char velocity, char speed)
{
        play_note(ch,E2,velocity);
        play_note(ch,E2,velocity);
        delay(speed);
        kill_note(ch,E2,velocity);
        kill_note(ch,E2,velocity);

        play_note(ch,E2,velocity);
        play_note(ch,E2,velocity);
        delay(speed);
        kill_note(ch,E2,velocity);
        kill_note(ch,E2,velocity);

        play_note(ch,E2,velocity);
        play_note(ch,E2,velocity);
        delay(speed);
        kill_note(ch,E2,velocity);
        kill_note(ch,E2,velocity);
}

void drumloop1(int speed, char velocity)
{
while (1)
{
        play_note(drumchannel,A3,velocity);
        play_note(drumchannel,F3,velocity);
        play_note(drumchannel,AS2,velocity);
        play_note(drumchannel,A2,velocity);
        play_note(drumchannel,C2,velocity);
        delay(speed);
        play_note(drumchannel,A2,velocity);
        play_note(drumchannel,C2,velocity);
        delay(speed);
        play_note(drumchannel,C2,velocity);
        delay(speed);
        play_note(drumchannel,A2,velocity);
        delay(speed);
        play_note(drumchannel,AS2,velocity);
        play_note(drumchannel,B2,velocity);
        play_note(drumchannel,D2,velocity);
        delay(speed*2);
        play_note(drumchannel,G2,velocity);
        play_note(drumchannel,C2,velocity);
        delay(speed);
        play_note(drumchannel,G2,velocity);
        play_note(drumchannel,C2,velocity);
        delay(speed);
        play_note(drumchannel,AS2,velocity);
        play_note(drumchannel,F3,velocity);
        delay(speed);
        play_note(drumchannel,C3,velocity);
        play_note(drumchannel,D2,velocity);
        delay(speed);
        play_note(drumchannel,B2,velocity);
        delay(speed);
        play_note(drumchannel,A2,velocity);
        delay(speed);
        play_note(drumchannel,AS2,velocity);
        play_note(drumchannel,C3,velocity);
        play_note(drumchannel,D2,velocity);
        delay(speed*2);
        play_note(drumchannel,D2,velocity);
        play_note(drumchannel,A2,velocity);
        delay(speed);
        play_note(drumchannel,C3,velocity);
        play_note(drumchannel,D2,velocity);
        delay(speed);
        if (key_table[INDEX_ESC]) break;
}
wait_for_no(INDEX_ESC);
}

void drumfill1(int speed, int velocity)
{
        play_note(drumchannel,B2,velocity);
        delay(speed);
        kill_note(drumchannel,B2,velocity);
        play_note(drumchannel,A2,velocity);
        delay(speed);
        kill_note(drumchannel,A2,velocity);
        delay(speed);
        play_note(drumchannel,G2,velocity);
        delay(speed);
        kill_note(drumchannel,G2,velocity);
        play_note(drumchannel,G2,velocity);
        delay(speed);
        kill_note(drumchannel,G2,velocity);
        delay(speed);
}

void main()
{
 GetBlastInfo(&blastInfo);
 MIDIType = SBMIDI;
 DSPReset();
 Init_MIDI();
 init_keyboard();
 clrscr();
 cout << "The Instinct";
 change_program(chordchannel,51,4);
 change_program(drumchannel,120,1);
 change_program(1,90,1);
 while (1)
 {
        if (key_table[INDEX_1]==1) drumfill1(135,100);
        if (key_table[INDEX_Q]==1) drumloop1(135,100);
        if (key_table[INDEX_W]==1) bass1(basschannel,127,135);
        if (key_table[INDEX_ESC]) break;
 }
 Exit_MIDI();
 kill_keyboard();
}
