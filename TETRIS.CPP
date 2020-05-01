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
#include "lights.h"

#define leadchannel 1
#define leadlevel 100
#define drumchannel 10
#define drumlevel 120
#define basschannel 2
#define basslevel 80
#define chordchannel 3
#define chordlevel 100

int bass1[2][2];


int speed = 100;


void dostuff()
{
       if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
        {   
          notes[INDEX_F1]=1;
          play_note(chordchannel,E4,chordlevel);
          play_note(chordchannel,C4,chordlevel);
        }   
        if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))   
        {   
          kill_note(chordchannel,E4,chordlevel);
          kill_note(chordchannel,C4,chordlevel);

          notes[INDEX_F1]=0;   
        }   

       if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
        {   
          notes[INDEX_F2]=1;
          play_note(chordchannel,C4,chordlevel);
          play_note(chordchannel,A3,chordlevel);
        }   
        if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))   
        {   
          kill_note(chordchannel,C4,chordlevel);
          kill_note(chordchannel,A3,chordlevel);

          notes[INDEX_F2]=0;   
        }   

       if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
        {   
          notes[INDEX_F3]=1;
          play_note(chordchannel,D4,chordlevel);
          play_note(chordchannel,B3,chordlevel);
        }   
        if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))   
        {   
          kill_note(chordchannel,D4,chordlevel);
          kill_note(chordchannel,B3,chordlevel);

          notes[INDEX_F3]=0;   
        }   

       if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
        {   
          notes[INDEX_F4]=1;
          play_note(chordchannel,B3,chordlevel);
          play_note(chordchannel,GS3,chordlevel);
        }   
        if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))   
        {   
          kill_note(chordchannel,B3,chordlevel);
          kill_note(chordchannel,GS3,chordlevel);

          notes[INDEX_F4]=0;   
        }   


       if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
        {   
          notes[INDEX_F5]=1;
          play_note(chordchannel,A3,chordlevel);
          play_note(chordchannel,E3,chordlevel);
        }   
        if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))   
        {   
          kill_note(chordchannel,A3,chordlevel);
          kill_note(chordchannel,E3,chordlevel);

          notes[INDEX_F5]=0;   
        }   

       if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
        {   
          notes[INDEX_F6]=1;
          play_note(chordchannel,GS3,chordlevel);
          play_note(chordchannel,E3,chordlevel);
        }   
        if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))   
        {   
          kill_note(chordchannel,GS3,chordlevel);
          kill_note(chordchannel,E3,chordlevel);

          notes[INDEX_F6]=0;   
        }   

       if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
        {   
          notes[INDEX_F7]=1;
          play_note(chordchannel,A4,chordlevel);
          play_note(chordchannel,E4,chordlevel);
        }   
        if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))   
        {   
          kill_note(chordchannel,A4,chordlevel);
          kill_note(chordchannel,E4,chordlevel);

          notes[INDEX_F7]=0;   
        }   


       if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
        {   
          notes[INDEX_F8]=1;
          play_note(chordchannel,GS4,chordlevel);
          play_note(chordchannel,D4,chordlevel);
        }   
        if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))   
        {   
          kill_note(chordchannel,GS4,chordlevel);
          kill_note(chordchannel,D4,chordlevel);

          notes[INDEX_F8]=0;   
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

int level1()
 {
    for (int index=0;index<4;index++)
    {
       play_note(drumchannel,FS1,127);
       if (delay1(speed)) return 0;
       if (delay1(speed)) return 0;
       if (delay1(speed)) return 0;
       if (delay1(speed)) return 0;
       kill_note(drumchannel,FS1,127);
    }

  for (int a = 0; a < 2; a++)
  {
  for (int i = 0; i < 1; i++)
  {
    //One measure
    play_note(basschannel,E2,basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,E2,basslevel);

    play_note(basschannel,E3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,E3,basslevel);

    play_note(basschannel,E2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,E2,basslevel);

    play_note(basschannel,E3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,E3,basslevel);

    play_note(basschannel,E2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,E2,basslevel);

    play_note(basschannel,E3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(basschannel,E3,basslevel);

    play_note(basschannel,E2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,E2,basslevel);

    play_note(basschannel,E3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,E3,basslevel);

    //Two Measure

    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,A3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,A3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,A3,basslevel);

    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,A3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,A3,basslevel);
    kill_note(drumchannel,FS1,drumlevel);

    play_note(basschannel,A2,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);
    kill_note(drumchannel,FS1,drumlevel);

    play_note(basschannel,A3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,A3,basslevel);
   }

  for (int j = 0; j < 1; j++)
  {
    //One measure
    play_note(basschannel,GS2,basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,GS2,basslevel);

    play_note(basschannel,GS3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,GS3,basslevel);

    play_note(basschannel,GS2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,GS2,basslevel);

    play_note(basschannel,GS3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,GS3,basslevel);

    play_note(basschannel,E2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,E2,basslevel);

    play_note(basschannel,E3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(basschannel,E3,basslevel);

    play_note(basschannel,E2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,E2,basslevel);

    play_note(basschannel,E3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,E3,basslevel);

    //Two Measure

    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,A3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,A3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,A3,basslevel);

    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,A3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,A3,basslevel);
    kill_note(drumchannel,FS1,drumlevel);

    play_note(basschannel,B2,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,B2,basslevel);
    kill_note(drumchannel,FS1,drumlevel);

    play_note(basschannel,C3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,C3,basslevel);
   }

  for (int k = 0; k < 1; k++)
   {

    //One measure
    play_note(basschannel,D3,basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,D3,basslevel);

    play_note(basschannel,D2,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,D2,basslevel);
    kill_note(drumchannel,FS1,drumlevel);

    if (delay1(speed)) break;

    play_note(basschannel,D2,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,D2,basslevel);

    if (delay1(speed)) break;

    play_note(basschannel,D2,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(basschannel,D2,basslevel);

    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,F2,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,F2,basslevel);

    //Two Measure

    play_note(basschannel,C2,basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,C2,basslevel);

    play_note(basschannel,C3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,C3,basslevel);

    if (delay1(speed)) break;

    play_note(basschannel,C3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(basschannel,C3,basslevel);

    play_note(basschannel,C2,basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,C2,basslevel);

    play_note(basschannel,G2,basslevel);
    if (delay1(speed)) break;

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(basschannel,G2,basslevel);

    play_note(basschannel,G2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,G2,basslevel);
    kill_note(drumchannel,FS1,drumlevel);

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

   }

  for (int l = 0; l < 1; l++)
    {

    //One measure
    play_note(basschannel,B2,basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,B2,basslevel);

    play_note(basschannel,B3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,B3,basslevel);

    if (delay1(speed)) break;

    play_note(basschannel,B3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,B3,basslevel);

    if (delay1(speed)) break;

    play_note(basschannel,E3,basslevel);    
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,E3,basslevel);

    if (delay1(speed)) break;

    play_note(basschannel,GS3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,GS3,basslevel);

    //Two Measure

    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,E3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,E3,basslevel);

    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,E3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,E3,basslevel);

    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,A2,basslevel);    

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
   }
  }

  for (int n = 0; n < 2; n++)
   {
  for (int m = 0; m < 2; m++)
  {
    //One measure
    play_note(basschannel,A3,basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,A3,basslevel);

    play_note(basschannel,E4,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,E4,basslevel);

    play_note(basschannel,A3,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,A3,basslevel);

    play_note(basschannel,E4,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,E4,basslevel);

    play_note(basschannel,A3,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,A3,basslevel);

    play_note(basschannel,E4,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(basschannel,E4,basslevel);

    play_note(basschannel,A3,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,A3,basslevel);

    play_note(basschannel,E4,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,E4,basslevel);

    //Two Measure

    play_note(basschannel,GS3,basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,GS3,basslevel);

    play_note(basschannel,E4,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,E4,basslevel);

    play_note(basschannel,GS3,basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;
    kill_note(basschannel,GS3,basslevel);

    play_note(basschannel,E4,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
if (m != 1)    kill_note(basschannel,E4,basslevel);

if (m != 1)    play_note(basschannel,GS3,basslevel);
    if (delay1(speed)) break;
if (m == 1)    kill_note(basschannel,E4,basslevel);
    kill_note(drumchannel,FS1,drumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,GS3,basslevel);

if (m != 1)    play_note(basschannel,E4,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,E4,basslevel);
    kill_note(drumchannel,FS1,drumlevel);

if (m != 1)    play_note(basschannel,GS3,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,GS3,basslevel);
    kill_note(drumchannel,FS1,drumlevel);

if (m != 1)    play_note(basschannel,E4,basslevel);
    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    
    kill_note(basschannel,E4,basslevel);
   }
  }


  return(1);
 }

void showtitle()
{
   clrscr();
   cout << "Tetris" << endl;
   cout << "1 to start" << endl << endl;
   cout << "F1 F2 F3 F4 F2 F5 F6 F4" << endl << "F1 F2 F3 F4 F2 F1 F7 F8" << endl;

 
}

void main()
{
   speed = 100;

   GetBlastInfo(&blastInfo);
   MIDIType = SBMIDI;
   DSPReset();
   Init_MIDI();   

   install_keyboard();

   mix_mode();
   change_program(leadchannel,99,0);
   change_program(drumchannel,120,1);
   change_program(basschannel,45,0);
   change_program(chordchannel,44,4);

   mix_name("Tetris   ");
   mix_mode();
   showtitle();

   for (int index=0;index<127;index++)
      notes[index] = 0;   
   change_volume(chordchannel,70);
   while (1)
   {
      if (delay1(1)) break;

      if (key_table[INDEX_11])
       {
        change_volume(1,99);

        change_light_level(1,50);
        change_light_level(2,75);
        change_light_level(3,25);
        change_light_level(4,50);
        level1();
        all_lights_off(0);
        change_light_level(3,127);
       }
   }
   change_volume(chordchannel,99);
   Exit_MIDI();
   kill_keyboard();
}

/*
    //One measure
    if (delay1(speed)) break;
    if (delay1(speed)) break;

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    //Two Measure

    if (delay1(speed)) break;
    if (delay1(speed)) break;

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    if (delay1(speed)) break;

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    

    play_note(drumchannel,FS1,drumlevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,FS1,drumlevel);    */




