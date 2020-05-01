//Test program
//by running this, hitting space will play a note

//You must have a MIDI keyboard (with sound coming from that keyboard)
//to hear the notes... Also your soundcard needs to be a Sound Blaster
//or 101% compatible... This program will not cause sound to come out of
//the sound blaster, but rather MIDI data to come out of the Sound Blaster
//joystick port ...

//any questions, e-mail ag002i@mail.rochester.edu
//please also check out the MIDI specification,
//http://www.borg.com/~jglatt/tech/midispec.htm


#include <dos.h>
#include <conio.h>
#include "keyboard.h"
#include "midi.h"
int notes[127];

#define leadchannel 1
#define leadlevel 50
#define basslevel 127
#define basschannel 2
#define drumchannel 10
#define drumlevel 127
#define belllevel 75
#define bellchannel 3
#define clocklevel 127
#define clockchannel 4

void dostuff()
{
        if ((notes[INDEX_SPACE] == 0) && (key_table[INDEX_SPACE]==1))
        {   
          notes[INDEX_SPACE]=1;   
          play_note(bellchannel,F1,belllevel);                   
        }   

        if ((notes[INDEX_SPACE] == 1) && (key_table[INDEX_SPACE]==0))
        {   
//          play_note(bellchannel,F1,belllevel);                   
            notes[INDEX_SPACE]=0;   

            change_volume(bellchannel,65);
        }

        if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
        {   
          notes[INDEX_UP]=1;   
          play_note(drumchannel,AS2,drumlevel);                   
        }   
        if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))   
        {   
          kill_note(drumchannel,AS2,drumlevel);         
          notes[INDEX_UP]=0;   
        }   
        
        if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))
        {   
          notes[INDEX_DOWN]=1;   
          play_note(clockchannel,C0,clocklevel);                   
        }   
        if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))   
        {   
          kill_note(clockchannel,C0,clocklevel);         
          notes[INDEX_DOWN]=0;
        }   


        if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))
        {   
          notes[INDEX_LEFT]=1;   
          play_note(basschannel,A1,basslevel);                   
        }   
        if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))   
        {   
          kill_note(basschannel,A1,basslevel);         
          notes[INDEX_LEFT]=0;   
        }   

        if ((notes[INDEX_RIGHT] == 0) && (key_table[INDEX_RIGHT]==1))
        {   
          notes[INDEX_RIGHT]=1;   
          play_note(basschannel,G1,basslevel);                   
        }   
        if ((notes[INDEX_RIGHT] == 1) && (key_table[INDEX_RIGHT]==0))   
        {   
          kill_note(basschannel,G1,basslevel);         
          notes[INDEX_RIGHT]=0;   
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

void showtitle()
{
   clrscr();
   cout << "Blaster Master";
   cout << "\n(intro now)";
   cout << "\n[SPACE] Start";
}

void main()
{
   GetBlastInfo(&blastInfo);
   MIDIType = SBMIDI;
   DSPReset();
   Init_MIDI();   

   install_keyboard();

   mix_mode();
    change_program(leadchannel,98,3);
    change_program(basschannel,41,3);
    change_program(drumchannel,121,0);
    change_program(bellchannel,19,3);
    change_program(clockchannel,19,1);
    change_volume(leadchannel,leadlevel);
    
   mix_name("Blaster  ");
   mix_mode();
   showtitle();

   for (int index=0;index<127;index++)
      notes[index] = 0;   
   
   while (1)
   {
      if (delay1(1)) break;
      if (key_table[INDEX_SPACE])
      {
         cout << "\n10 ";
         mix_name("Blaster 10");
         delay1(500);

         cout << "\n9 ";
         mix_name("Blaster 9");
         delay1(500);

         cout << "\n8 ";
         mix_name("Blaster 8");
         delay1(500);

         cout << "\n7 ";
         mix_name("Blaster 7");
         delay1(500);

         cout << "\n6 ";
         mix_name("Blaster 6");
         delay1(500);

         cout << "\n5 ";
         mix_name("Blaster 5");
         delay1(500);

         cout << "\n4 ";
         mix_name("Blaster 4");
         delay1(500);

         cout << "3 ";
         mix_name("Blaster 3");
         delay1(500);

         cout << "2 ";
         mix_name("Blaster 2");
         delay1(500);

         cout << "1 ";
         mix_name("Blaster 1");
         delay1(500);

         cout << "Go! ";
         mix_name("Blaster  ");
      }
   }
   Exit_MIDI();
   kill_keyboard();
}
                                      
