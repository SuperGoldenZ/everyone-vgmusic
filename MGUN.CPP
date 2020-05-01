#include <dos.h>
#include <conio.h>
#include <keyboard.h>
#include <midi.h>

int drumlevel;

#define drumchannel 10
#define drummax1 127

//old 100
const int speed = 115;

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

void change_program(char channel, char prognum)
{
 channel--;
 char message[3];
 message[0] = 0xc0;
 message[0] += channel;
 message[1] = prognum;
 Send_MIDI_Message(message,2);
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

char delay1(int count)
{
        for (int index=0;index<count;index++)
        {
                delay(1);
                if (key_table[INDEX_ESC]) return 1;
                if (key_table[INDEX_SPACE]) drumlevel = drummax1;
        }
        return 0;
}

void go()
{
        clrscr();
        cout << "Bang Bang, good luck!";
        cout << "\n[SPACE]: drums full level!";
        cout << "\nPress ESC to continue...";
        drumlevel = 75;
        while (1)
        {
                cout << "\nDrumlevel: " << drumlevel;

                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;
                if (drumlevel < drummax1) drumlevel++;

                kill_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;

                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;

                kill_note(drumchannel,39,drumlevel);
                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;

                kill_note(drumchannel,39,drumlevel);
                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;
                if (drumlevel < drummax1) drumlevel++;

                kill_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;

                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;

                kill_note(drumchannel,39,drumlevel);
                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;

                kill_note(drumchannel,39,drumlevel);
                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;
                if (drumlevel < drummax1) drumlevel++;

                kill_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;

                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;

                kill_note(drumchannel,39,drumlevel);
                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;

                kill_note(drumchannel,39,drumlevel);
                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;
                if (drumlevel < drummax1) drumlevel++;

                kill_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;

                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;
                kill_note(drumchannel,39,drumlevel);

                play_note(drumchannel,39,drumlevel);
                if (delay1(speed) == 1) break;
                kill_note(drumchannel,39,drumlevel);

        }
        wait_for_no(INDEX_ESC);
        clrscr();
        cout << "Man With The Machine Gun";
        cout << "\n1: Start!";
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
        change_program(1,124,0);
        clrscr();
        cout << "Man With The Machine Gun";
        cout << "\n1: Start!";
        cout << "\nESC: Quit";

        while (1)
        {
                if (key_table[INDEX_1]) go();
                if (key_table[INDEX_ESC]) break;
        }
                kill_keyboard();
                Exit_MIDI();
    }
