#include <midi.h>   
#include <dos.h>   
#include <keyboard.h>

#define crystalchannel 2
#define crystallevel 127

int notes[127];

void title()
{
   clrscr();
   cout << "Final Fantasy";
   cout << "\n1: Crystals";
}

void crystals()
{
   clrscr();
   cout << "The Crystals";
   cout << "\nUP:   Up an octave";
   cout << "\nDOWN: Down an octave";
   cout << "\n\nCurrent octave: 3";
   int tune = 0;

   while (1)
   {
      if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))   
      {   
        notes[INDEX_R]=1;   
        play_note(crystalchannel,G3+tune,crystallevel);                   
      }   
      if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))   
      {   
        kill_note(crystalchannel,G3+tune,crystallevel);         
        notes[INDEX_R]=0;   
      }

      if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
      {   
        notes[INDEX_Q]=1;   
        play_note(crystalchannel,C3+tune,crystallevel);                   
      }   
      if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))   
      {   
        kill_note(crystalchannel,C3+tune,crystallevel);         
        notes[INDEX_Q]=0;   
      }

      if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
      {   
        notes[INDEX_W]=1;   
        play_note(crystalchannel,D3+tune,crystallevel);                   
      }   
      if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))   
      {   
        kill_note(crystalchannel,D3+tune,crystallevel);         
        notes[INDEX_W]=0;   
      }

      if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
      {   
        notes[INDEX_E]=1;   
        play_note(crystalchannel,E3+tune,crystallevel);                   
      }   
      if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))   
      {   
        kill_note(crystalchannel,E3+tune,crystallevel);         
        notes[INDEX_E]=0;   
      }

      if ((notes[INDEX_A] == 0) && (key_table[INDEX_A]==1))
      {   
        notes[INDEX_A]=1;   
        play_note(crystalchannel,A2+tune,crystallevel);                   
      }   
      if ((notes[INDEX_A] == 1) && (key_table[INDEX_A]==0))   
      {   
        kill_note(crystalchannel,A2+tune,crystallevel);         
        notes[INDEX_A]=0;   
      }

      if ((notes[INDEX_S] == 0) && (key_table[INDEX_S]==1))
      {   
        notes[INDEX_S]=1;   
        play_note(crystalchannel,B2+tune,crystallevel);                   
      }   
      if ((notes[INDEX_S] == 1) && (key_table[INDEX_S]==0))   
      {   
        kill_note(crystalchannel,B2+tune,crystallevel);         
        notes[INDEX_S]=0;   
      }

      if ((notes[INDEX_F] == 0) && (key_table[INDEX_F]==1))
      {   
        notes[INDEX_F]=1;   
        play_note(crystalchannel,F3+tune,crystallevel);                   
      }   
      if ((notes[INDEX_F] == 1) && (key_table[INDEX_F]==0))   
      {   
        kill_note(crystalchannel,F3+tune,crystallevel);         
        notes[INDEX_F]=0;   
      }

      if ((notes[INDEX_G] == 0) && (key_table[INDEX_G]==1))
      {   
        notes[INDEX_G]=1;   
        play_note(crystalchannel,A3+tune,crystallevel);                   
      }   
      if ((notes[INDEX_G] == 1) && (key_table[INDEX_G]==0))   
      {   
        kill_note(crystalchannel,A3+tune,crystallevel);         
        notes[INDEX_G]=0;   
      }

      if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
      {   
        notes[INDEX_F1]=1;   
        play_note(crystalchannel,GS2+tune,crystallevel);                   
      }   
      if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))   
      {   
        kill_note(crystalchannel,GS2+tune,crystallevel);         
        notes[INDEX_F1]=0;   
      }

      if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
      {   
        notes[INDEX_F2]=1;   
        play_note(crystalchannel,AS2+tune,crystallevel);                   
      }   
      if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))   
      {   
        kill_note(crystalchannel,AS2+tune,crystallevel);         
        notes[INDEX_F2]=0;   
      }

      if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
      {   
        notes[INDEX_F3]=1;   
        play_note(crystalchannel,DS3+tune,crystallevel);                   
      }   
      if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))   
      {   
        kill_note(crystalchannel,DS3+tune,crystallevel);         
        notes[INDEX_F3]=0;   
      }

      if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))
      {   
        notes[INDEX_DOWN]=1;   
        tune-=12;
        gotoxy(1,5);
        cout << "Current octave: " << 3 + (tune / 12);
      }
      if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))   
      {   
        notes[INDEX_DOWN]=0;   
      }

      if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
      {   
        notes[INDEX_UP]=1;   
        tune+=12;
        gotoxy(1,5);
        cout << "Current octave: " << 3 + (tune / 12);
      }   
      if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))   
      {   
        notes[INDEX_UP]=0;   
      }

      if (key_table[INDEX_ESC]) break;
   }
   wait_for_no(INDEX_ESC);
   title();
}

void main()
{
   GetBlastInfo(&blastInfo);   
   MIDIType = SBMIDI;   
   DSPReset();   
   Init_MIDI();   
   install_keyboard();
   title();
   for (int index=0;index<127;index++)
      notes[index] = 0;
   while (1)
   {
      if (key_table[INDEX_1]) crystals();
      if (key_table[INDEX_ESC]) break;
   }   
   Exit_MIDI();   
   kill_keyboard();   
}
