#include "midi.h"
#include "lights.h"
#include <dos.h>   
#include <keyboard.h>

int underground = 0;

void main()
{                            
        init_keyboard();
        GetBlastInfo(&blastInfo);
        MIDIType = SBMIDI;
        DSPReset();
        Init_MIDI();
        for (int index=0;index<127;index++)
                notes[index] = 0;
        clrscr();
        cout << "Super Sell Outs!";
        cout << "\nF1: Brick Smash";
        cout << "\nF2: Flagpole";
        cout << "\nF3: Jump";
        cout << "\nF4: Kick";
        cout << "\nF5: Pipe";
        cout << "\nF6: Jump (2)";
        cout << "\nF7: Mushroom";
        mix_name("Mario    ");
        change_volume(1,90);
        change_program(1,105,1);
        change_program(2,124,0);
        change_light_level(1,50);
        change_light_level(2,75);
        change_light_level(3,25);
        change_light_level(4,50);

        mix_mode();
        while (1)
        {
                if (key_table[INDEX_ESC])
                   break;

                if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
                {
                  notes[INDEX_F1]=1;
                  play_note(2,F4,127);
                }
                if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
                {
                  kill_note(2,F4,127);
                  notes[INDEX_F1]=0;
                }

                if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
                {
                  notes[INDEX_F2]=1;
                  play_note(2,FS4,127);
                }
                if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
                {
                  kill_note(2,FS4,127);
                  notes[INDEX_F2]=0;
                }

                if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
                {
                  notes[INDEX_F3]=1;
                  play_note(2,FS4+1,127);
                }
                if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
                {
                  kill_note(2,FS4+1,127);
                  notes[INDEX_F3]=0;
                }

                if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
                {
                  notes[INDEX_F4]=1;
                  play_note(2,FS4+2,127);
                }
                if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
                {
                  kill_note(2,FS4+2,127);
                  notes[INDEX_F4]=0;
                }

                if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
                {
                  notes[INDEX_F5]=1;
                  play_note(2,FS4+3,127);
                }
                if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
                {
                  kill_note(2,FS4+3,127);
                  notes[INDEX_F5]=0;
                  underground = !underground;
                  if (underground == 1)
                  {
                     change_program(1,44,1);
                     mix_name("Underground");
                     mix_mode();
                     all_lights_off(0);
                     change_light_level(2,75);
                     change_light_level(1,20);
                  }
                  else
                  {
                     change_program(1,105,1);
                     mix_name("Mario    ");
                     mix_mode();
                     all_lights_off(0);
                     change_light_level(1,50);
                     change_light_level(2,75);
                     change_light_level(3,25);
                     change_light_level(4,50);
                  }
                }

                if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
                {
                  notes[INDEX_F6]=1;
                  play_note(2,FS4+4,127);
                }
                if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
                {
                  kill_note(2,FS4+4,127);
                  notes[INDEX_F6]=0;
                }

                if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
                {
                  notes[INDEX_F7]=1;
                  play_note(2,FS4+5,127);
                }
                if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
                {
                  kill_note(2,FS4+5,127);
                  notes[INDEX_F7]=0;
                }

                if ((notes[INDEX_ENTER] == 0) && (key_table[INDEX_ENTER]==1))
                {
                  notes[INDEX_ENTER]=1;
                  change_light_level(5,127);
                }

        }
        all_lights_off(0);
        change_light_level(3,127);
        change_volume(1,99);
        mix_name("Multi    ");
        mix_mode();
        kill_keyboard();
        Exit_MIDI();
}
