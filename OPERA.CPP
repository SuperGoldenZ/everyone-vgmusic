#include "midi.h"
#include "lights.h"
#include <dos.h>
#include <conio.h>
#include <keyboard.h>

const int channel = 2;

#define stringchannel 3
#define stringlevel 127

void playchord1()
{   
 play_note(stringchannel,A4,stringlevel);   
 play_note(stringchannel,D4,stringlevel);   
 play_note(stringchannel,D3,stringlevel);   
}

void killchord1()
{   
 kill_note(stringchannel,A4,stringlevel);   
 kill_note(stringchannel,D4,stringlevel);   
 kill_note(stringchannel,D3,stringlevel);   
}

void playchord2()
{   
 play_note(stringchannel,FS4,stringlevel);   
 play_note(stringchannel,CS4,stringlevel);   
 play_note(stringchannel,CS3,stringlevel);   
}

void killchord2()
{   
 kill_note(stringchannel,FS4,stringlevel);   
 kill_note(stringchannel,CS4,stringlevel);   
 kill_note(stringchannel,CS3,stringlevel);   
}

void playchord3()
{   
 play_note(stringchannel,G4,stringlevel);   
 play_note(stringchannel,D4,stringlevel);   
 play_note(stringchannel,B2,stringlevel);   
}

void killchord3()
{   
 kill_note(stringchannel,G4,stringlevel);   
 kill_note(stringchannel,D4,stringlevel);   
 kill_note(stringchannel,B2,stringlevel);   
}

void playchord4()
{   
 play_note(stringchannel,FS4,stringlevel);   
 play_note(stringchannel,CS4,stringlevel);   
 play_note(stringchannel,CS3,stringlevel);   
}

void killchord4()
{   
 kill_note(stringchannel,FS4,stringlevel);   
 kill_note(stringchannel,CS4,stringlevel);   
 kill_note(stringchannel,CS3,stringlevel);   
}

void playchord5()
{   
 play_note(stringchannel,E4,stringlevel);   
 play_note(stringchannel,B3,stringlevel);   
 play_note(stringchannel,B2,stringlevel);   
}

void killchord5()
{   
 kill_note(stringchannel,E4,stringlevel);   
 kill_note(stringchannel,B3,stringlevel);   
 kill_note(stringchannel,B2,stringlevel);   
}

void playchord6()
{   
 play_note(stringchannel,D4,stringlevel);   
 play_note(stringchannel,A3,stringlevel);   
 play_note(stringchannel,A2,stringlevel);   
}

void killchord6()
{   
 kill_note(stringchannel,D4,stringlevel);   
 kill_note(stringchannel,A3,stringlevel);   
 kill_note(stringchannel,A2,stringlevel);   
}

void playchord7()
{   
 play_note(stringchannel,CS4,stringlevel);   
 play_note(stringchannel,GS3,stringlevel);   
 play_note(stringchannel,GS2,stringlevel);   
}

void killchord7()
{   
 kill_note(stringchannel,CS4,stringlevel);   
 kill_note(stringchannel,GS3,stringlevel);   
 kill_note(stringchannel,GS2,stringlevel);   
}

void playchord8()
{   
 play_note(stringchannel,F4,stringlevel);   
 play_note(stringchannel,B3,stringlevel);   
}

void killchord8()
{   
 kill_note(stringchannel,F4,stringlevel);   
 kill_note(stringchannel,B3,stringlevel);   
}

void playchord9()
{   
 play_note(stringchannel,FS4,stringlevel);   
 play_note(stringchannel,A3,stringlevel);   
 play_note(stringchannel,A2,stringlevel);   
}

void killchord9()
{   
 kill_note(stringchannel,FS4,stringlevel);   
 kill_note(stringchannel,A3,stringlevel);   
 kill_note(stringchannel,A2,stringlevel);   
}

void playchord10()
{   
 play_note(stringchannel,A4,stringlevel);   
 play_note(stringchannel,E4,stringlevel);   
}

void killchord10()
{   
 kill_note(stringchannel,A4,stringlevel);   
 kill_note(stringchannel,E4,stringlevel);   
}

void playchorda()
{   
 play_note(stringchannel,FS4,stringlevel);   
 play_note(stringchannel,D4,stringlevel);   
 play_note(stringchannel,B3,stringlevel);   
}

void killchorda()
{   
 kill_note(stringchannel,FS4,stringlevel);   
 kill_note(stringchannel,D4,stringlevel);   
 kill_note(stringchannel,B3,stringlevel);   
}

void playchords()
{   
 play_note(stringchannel,D4,stringlevel);   
 play_note(stringchannel,B4,stringlevel);   
 play_note(stringchannel,G3,stringlevel);   
}

void killchords()
{   
 kill_note(stringchannel,D4,stringlevel);   
 kill_note(stringchannel,B4,stringlevel);   
 kill_note(stringchannel,G3,stringlevel);   
}

void playchordd()
{   
 play_note(stringchannel,CS4,stringlevel);   
 play_note(stringchannel,A4,stringlevel);   
 play_note(stringchannel,E3,stringlevel);   
}

void killchordd()
{   
 kill_note(stringchannel,CS4,stringlevel);   
 kill_note(stringchannel,A4,stringlevel);   
 kill_note(stringchannel,E3,stringlevel);   
}

void playchordf()
{   
 play_note(stringchannel,E4,stringlevel);   
 play_note(stringchannel,CS4,stringlevel);   
 play_note(stringchannel,A3,stringlevel);   
}

void killchordf()
{   
 kill_note(stringchannel,E4,stringlevel);   
 kill_note(stringchannel,CS4,stringlevel);   
 kill_note(stringchannel,A3,stringlevel);   
}

void playchordq()
{   
 play_note(stringchannel,B4,stringlevel);   
 play_note(stringchannel,FS4,stringlevel);   
 play_note(stringchannel,D4,stringlevel);   
}

void killchordq()
{   
 kill_note(stringchannel,B4,stringlevel);   
 kill_note(stringchannel,FS4,stringlevel);   
 kill_note(stringchannel,D4,stringlevel);   
}

void playchordw()
{   
 play_note(stringchannel,A4,stringlevel);   
 play_note(stringchannel,FS4,stringlevel);   
 play_note(stringchannel,D4,stringlevel);   
}

void killchordw()
{   
 kill_note(stringchannel,A4,stringlevel);   
 kill_note(stringchannel,FS4,stringlevel);   
 kill_note(stringchannel,D4,stringlevel);   
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
        all_lights_off(0);
        change_light_level(2,127);
        change_light_level(3,25);


        clrscr();
        cout << "Opera Music";
        cout << "\nESC: Quit";
        while (1)
        {
                if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
                {
                  notes[INDEX_F1]=1;
                  playchord1();
                }
                if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))
                {
                  killchord1();
                  notes[INDEX_F1]=0;
                }
        
                if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
                {
                  notes[INDEX_F2]=1;
                  playchord2();
                }
                if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))
                {
                  killchord2();
                  notes[INDEX_F2]=0;
                }
        
                if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
                {
                  notes[INDEX_F3]=1;
                  playchord3();
                }
                if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))
                {
                  killchord3();
                  notes[INDEX_F3]=0;
                }
        
                if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
                {
                  notes[INDEX_F4]=1;
                  playchord4();
                }
                if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))
                {
                  killchord4();
                  notes[INDEX_F4]=0;
                }
        
                if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
                {
                  notes[INDEX_F5]=1;
                  playchord5();
                }
                if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))
                {
                  killchord5();
                  notes[INDEX_F5]=0;
                }

                if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
                {
                  notes[INDEX_F6]=1;
                  playchord6();
                }
                if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))
                {
                  killchord6();
                  notes[INDEX_F6]=0;
                }

                if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
                {
                  notes[INDEX_F7]=1;
                  playchord7();
                }
                if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))
                {
                  killchord7();
                  notes[INDEX_F7]=0;
                }

                if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
                {
                  notes[INDEX_F8]=1;
                  playchord8();
                }
                if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))
                {
                  killchord8();
                  notes[INDEX_F8]=0;
                }

                if ((notes[INDEX_F9] == 0) && (key_table[INDEX_F9]==1))
                {
                  notes[INDEX_F9]=1;
                  playchord9();
                }
                if ((notes[INDEX_F9] == 1) && (key_table[INDEX_F9]==0))
                {
                  killchord9();
                  notes[INDEX_F9]=0;
                }

                if ((notes[INDEX_F10] == 0) && (key_table[INDEX_F10]==1))
                {
                  notes[INDEX_F10]=1;
                  playchord10();
                }
                if ((notes[INDEX_F10] == 1) && (key_table[INDEX_F10]==0))
                {
                  killchord10();
                  notes[INDEX_F10]=0;
                }

                if ((notes[INDEX_A] == 0) && (key_table[INDEX_A]==1))
                {
                  notes[INDEX_A]=1;
                  playchorda();
                }
                if ((notes[INDEX_A] == 1) && (key_table[INDEX_A]==0))
                {
                  killchorda();
                  notes[INDEX_A]=0;
                }

                if ((notes[INDEX_S] == 0) && (key_table[INDEX_S]==1))
                {
                  notes[INDEX_S]=1;
                  playchords();
                }
                if ((notes[INDEX_S] == 1) && (key_table[INDEX_S]==0))
                {
                  killchords();
                  notes[INDEX_S]=0;
                }

                if ((notes[INDEX_D] == 0) && (key_table[INDEX_D]==1))
                {
                  notes[INDEX_D]=1;
                  playchordd();
                }
                if ((notes[INDEX_D] == 1) && (key_table[INDEX_D]==0))
                {
                  killchordd();
                  notes[INDEX_D]=0;
                }

                if ((notes[INDEX_F] == 0) && (key_table[INDEX_F]==1))
                {
                  notes[INDEX_F]=1;
                  playchordf();
                }
                if ((notes[INDEX_F] == 1) && (key_table[INDEX_F]==0))
                {
                  killchordf();
                  notes[INDEX_F]=0;
                }

                if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
                {
                  notes[INDEX_Q]=1;
                  playchordq();
                }
                if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))
                {
                  killchordq();
                  notes[INDEX_Q]=0;
                }

                if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
                {
                  notes[INDEX_W]=1;
                  playchordw();
                }
                if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))
                {
                  killchordw();
                  notes[INDEX_W]=0;
                }
        
                if (key_table[INDEX_ESC]) break;
                }
                all_lights_off(0);
                change_light_level(3,127);
                kill_keyboard();
                Exit_MIDI();
    }
