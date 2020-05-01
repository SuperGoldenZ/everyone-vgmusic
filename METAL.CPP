#include <keyboard.h>
#include <midi.h>
#include <dos.h>
#include <conio.h>

#define drumlevel 127
#define drumchannel 10

const int speed = 95;

void main()
{
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        change_program(drumchannel,120,1);
        clrscr();
        cout << "Double Bass";
        cout << "\nESC: Quit";

        while (1)
        {
                play_note(drumchannel,36,127);
                delay(100);
                kill_note(drumchannel,36,127);

                play_note(drumchannel,36,127);
                delay(100);
                kill_note(drumchannel,36,127);

                play_note(drumchannel,36,127);
                delay(100);
                kill_note(drumchannel,36,127);

                play_note(drumchannel,36,127);
                play_note(drumchannel,38,127);
                delay(100);
                kill_note(drumchannel,36,127);
                kill_note(drumchannel,38,127);

                if (key_table[INDEX_ESC]) break;
        }
                kill_keyboard();
                Exit_MIDI();
}
