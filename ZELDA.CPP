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
#define leadlevel 126
#define drumchannel 10
#define drumlevel 120 //old 120 
#define basschannel 2
#define basslevel 120
#define chordchannel 3
#define chordlevel 100
#define evilbasschannel 4
#define evilbasslevel 0 //old 120
#define fastchordchannel 5
#define fastchordlevel 100
#define dungeonbasschannel 9
int dungeonbasslevel = 127;

int speed = 100;
int bass1[3];
int bass2[2][4];
int bass3[2][3];
int dungeonbass[11][5];
int dungeonmeasure = 1;
int count = 0;

void dostuff()
{

       if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
        {   
          notes[INDEX_F1]=1;
          play_note(fastchordchannel,F2,chordlevel);
          play_note(fastchordchannel,AS2,chordlevel);
          play_note(fastchordchannel,D3,chordlevel);
          play_note(evilbasschannel,F2,evilbasslevel);
        }
        if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))   
        {   
          kill_note(fastchordchannel,F2,chordlevel);
          kill_note(fastchordchannel,AS2,chordlevel);
          kill_note(fastchordchannel,D3,chordlevel);
          kill_note(evilbasschannel,F2,evilbasslevel);
          notes[INDEX_F1]=0;   
        }   

       if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
        {   
          notes[INDEX_F2]=1;
          play_note(fastchordchannel,E2,chordlevel);
          play_note(fastchordchannel,GS2,chordlevel);
          play_note(fastchordchannel,C3,chordlevel);
          play_note(evilbasschannel,E2,evilbasslevel);
        }
        if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))   
        {   
          kill_note(fastchordchannel,E2,chordlevel);
          kill_note(fastchordchannel,GS2,chordlevel);
          kill_note(fastchordchannel,C3,chordlevel);
          kill_note(evilbasschannel,E2,evilbasslevel);

          notes[INDEX_F2]=0;
        }   


       if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
        {   
          notes[INDEX_F3]=1;
          play_note(chordchannel,F4,chordlevel);
          play_note(chordchannel,D4,chordlevel);
          play_note(chordchannel,F3,chordlevel);
          play_note(evilbasschannel,D3,evilbasslevel);
        }
        if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))   
        {   
          kill_note(chordchannel,F4,chordlevel);
          kill_note(chordchannel,D4,chordlevel);
          kill_note(chordchannel,F3,chordlevel);
          kill_note(evilbasschannel,D3,evilbasslevel);

          notes[INDEX_F3]=0;
        }   


       if ((notes[INDEX_F4] == 0) && (key_table[INDEX_F4]==1))
        {   
          notes[INDEX_F4]=1;
          play_note(chordchannel,F4,chordlevel);
          play_note(chordchannel,C4,chordlevel);
          play_note(chordchannel,F3,chordlevel);
          play_note(evilbasschannel,C3,evilbasslevel);
        }
        if ((notes[INDEX_F4] == 1) && (key_table[INDEX_F4]==0))   
        {   
          kill_note(chordchannel,F4,chordlevel);
          kill_note(chordchannel,C4,chordlevel);
          kill_note(chordchannel,F3,chordlevel);
          kill_note(evilbasschannel,C3,evilbasslevel);

          notes[INDEX_F4]=0;
        }   


       if ((notes[INDEX_F5] == 0) && (key_table[INDEX_F5]==1))
        {   
          notes[INDEX_F5]=1;
          play_note(chordchannel,CS4,chordlevel);
          play_note(chordchannel,AS3,chordlevel);
          play_note(chordchannel,CS3,chordlevel);
          play_note(evilbasschannel,AS2,evilbasslevel);
        }
        if ((notes[INDEX_F5] == 1) && (key_table[INDEX_F5]==0))   
        {   
          kill_note(chordchannel,CS4,chordlevel);
          kill_note(chordchannel,AS3,chordlevel);
          kill_note(chordchannel,CS3,chordlevel);
          kill_note(evilbasschannel,AS2,evilbasslevel);

          notes[INDEX_F5]=0;
        }   

       if ((notes[INDEX_F6] == 0) && (key_table[INDEX_F6]==1))
        {   
          notes[INDEX_F6]=1;
          play_note(chordchannel,GS4,chordlevel);
          play_note(chordchannel,F4,chordlevel);
          play_note(chordchannel,GS3,chordlevel);
          play_note(evilbasschannel,F3,evilbasslevel);
        }
        if ((notes[INDEX_F6] == 1) && (key_table[INDEX_F6]==0))   
        {   
          kill_note(chordchannel,GS4,chordlevel);
          kill_note(chordchannel,F4,chordlevel);
          kill_note(chordchannel,GS3,chordlevel);
          kill_note(evilbasschannel,F3,evilbasslevel);

          notes[INDEX_F6]=0;
        }   


       if ((notes[INDEX_F7] == 0) && (key_table[INDEX_F7]==1))
        {   
          notes[INDEX_F7]=1;
          play_note(chordchannel,AS4,chordlevel);
          play_note(chordchannel,FS4,chordlevel);
          play_note(chordchannel,AS3,chordlevel);
          play_note(evilbasschannel,FS3,evilbasslevel);
        }
        if ((notes[INDEX_F7] == 1) && (key_table[INDEX_F7]==0))   
        {   
          kill_note(chordchannel,AS4,chordlevel);
          kill_note(chordchannel,FS4,chordlevel);
          kill_note(chordchannel,AS3,chordlevel);
          kill_note(evilbasschannel,FS3,evilbasslevel);

          notes[INDEX_F7]=0;
        }   

       if ((notes[INDEX_F8] == 0) && (key_table[INDEX_F8]==1))
        {   
          notes[INDEX_F8]=1;
          play_note(chordchannel,F4,chordlevel);
          play_note(chordchannel,CS4,chordlevel);
          play_note(chordchannel,F3,chordlevel);
          play_note(evilbasschannel,CS3,evilbasslevel);
        }
        if ((notes[INDEX_F8] == 1) && (key_table[INDEX_F8]==0))   
        {   
          kill_note(chordchannel,F4,chordlevel);
          kill_note(chordchannel,CS4,chordlevel);
          kill_note(chordchannel,F3,chordlevel);
          kill_note(evilbasschannel,CS3,evilbasslevel);

          notes[INDEX_F8]=0;
        }   



       if ((notes[INDEX_F9] == 0) && (key_table[INDEX_F9]==1))
        {   
          notes[INDEX_F9]=1;
          play_note(chordchannel,F4,chordlevel);
          play_note(chordchannel,C4,chordlevel);
          play_note(chordchannel,AS4,chordlevel);
          play_note(chordchannel,G3,chordlevel);
          play_note(evilbasschannel,C3,evilbasslevel);
        }
        if ((notes[INDEX_F9] == 1) && (key_table[INDEX_F9]==0))   
        {   
          kill_note(chordchannel,F4,chordlevel);
          kill_note(chordchannel,C4,chordlevel);
          kill_note(chordchannel,AS4,chordlevel);
          kill_note(evilbasschannel,C3,evilbasslevel);
          kill_note(chordchannel,G3,chordlevel);
          notes[INDEX_F9]=0;
        }   


       if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
        {   
          notes[INDEX_Q]=1;
          play_note(chordchannel,A4,chordlevel);
          play_note(chordchannel,F4,chordlevel);
          play_note(chordchannel,C4,chordlevel);
        }
        if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))   
        {   
          kill_note(chordchannel,A4,chordlevel);
          kill_note(chordchannel,F4,chordlevel);
          kill_note(chordchannel,C4,chordlevel);
          notes[INDEX_Q]=0;
        }   



       if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
        {   
          notes[INDEX_W]=1;
          play_note(chordchannel,GS4,chordlevel);
          play_note(chordchannel,E4,chordlevel);
          play_note(chordchannel,B3,chordlevel);
        }
        if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))   
        {   
          kill_note(chordchannel,GS4,chordlevel);
          kill_note(chordchannel,E4,chordlevel);
          kill_note(chordchannel,B3,chordlevel);
          notes[INDEX_W]=0;
        }   

       if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
        {   
          notes[INDEX_E]=1;
          play_note(chordchannel,G4,chordlevel);
          play_note(chordchannel,DS4,chordlevel);
          play_note(chordchannel,AS3,chordlevel);
        }
        if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))   
        {   
          kill_note(chordchannel,G4,chordlevel);
          kill_note(chordchannel,DS4,chordlevel);
          kill_note(chordchannel,AS3,chordlevel);
          notes[INDEX_E]=0;
        }   


       if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
        {   
          notes[INDEX_R]=1;
          play_note(chordchannel,FS4,chordlevel);
          play_note(chordchannel,D4,chordlevel);
          play_note(chordchannel,A3,chordlevel);
        }
        if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))   
        {   
          kill_note(chordchannel,FS4,chordlevel);
          kill_note(chordchannel,D4,chordlevel);
          kill_note(chordchannel,A3,chordlevel);
          notes[INDEX_R]=0;
        }   

       if ((notes[INDEX_T] == 0) && (key_table[INDEX_T]==1))
        {   
          notes[INDEX_T]=1;
          play_note(chordchannel,F4,chordlevel);
          play_note(chordchannel,DS4,chordlevel);
          play_note(chordchannel,CS4,chordlevel);
          play_note(chordchannel,A3,chordlevel);
        }
        if ((notes[INDEX_T] == 1) && (key_table[INDEX_T]==0))   
        {   
          kill_note(chordchannel,F4,chordlevel);
          kill_note(chordchannel,DS4,chordlevel);
          kill_note(chordchannel,CS4,chordlevel);
          kill_note(chordchannel,A3,chordlevel);
          notes[INDEX_T]=0;
        }   


       if ((notes[INDEX_A] == 0) && (key_table[INDEX_A]==1))
        {   
          notes[INDEX_A]=1;
          play_note(chordchannel,C4,chordlevel);
          play_note(chordchannel,A3,chordlevel);
          play_note(chordchannel,C3,chordlevel);
        }
        if ((notes[INDEX_A] == 1) && (key_table[INDEX_A]==0))   
        {   
          kill_note(chordchannel,C4,chordlevel);
          kill_note(chordchannel,A3,chordlevel); //G or G#
          kill_note(chordchannel,C3,chordlevel);
          notes[INDEX_A]=0;
        }   

       if ((notes[INDEX_S] == 0) && (key_table[INDEX_S]==1))
        {   
          notes[INDEX_S]=1;
          play_note(chordchannel,E4,chordlevel);
          play_note(chordchannel,CS4,chordlevel);
          play_note(chordchannel,FS3,chordlevel);
        }
        if ((notes[INDEX_S] == 1) && (key_table[INDEX_S]==0))   
        {   
          kill_note(chordchannel,E4,chordlevel);
          kill_note(chordchannel,CS4,chordlevel);
          kill_note(chordchannel,FS3,chordlevel);
          notes[INDEX_S]=0;
        }   

       if ((notes[INDEX_D] == 0) && (key_table[INDEX_D]==1))
        {   
          notes[INDEX_D]=1;
          play_note(chordchannel,FS4,chordlevel);
          play_note(chordchannel,DS4,chordlevel);
          play_note(chordchannel,FS3,chordlevel);
        }
        if ((notes[INDEX_D] == 1) && (key_table[INDEX_D]==0))   
        {   
          kill_note(chordchannel,FS4,chordlevel);
          kill_note(chordchannel,DS4,chordlevel);
          kill_note(chordchannel,FS3,chordlevel);
          notes[INDEX_D]=0;
        }   
}

void dodungeonstuff()
{
   if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))
   {
      notes[INDEX_LEFT]=1;
      play_note(dungeonbasschannel,dungeonbass[dungeonmeasure][0],dungeonbasslevel);
   }

   if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))
   {
      if (count == 0)
         kill_note(dungeonbasschannel,dungeonbass[dungeonmeasure][0],dungeonbasslevel);
      else
         kill_note(dungeonbasschannel,dungeonbass[dungeonmeasure][0],dungeonbasslevel);
      notes[INDEX_LEFT]=0;
   }

   if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))
   {
      notes[INDEX_DOWN]=1;
      play_note(dungeonbasschannel,dungeonbass[dungeonmeasure][1],dungeonbasslevel);
   }

   if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))
   {
      kill_note(dungeonbasschannel,dungeonbass[dungeonmeasure][1],dungeonbasslevel);
      notes[INDEX_DOWN]=0;
   }

   if ((notes[INDEX_RIGHT] == 0) && (key_table[INDEX_RIGHT]==1))
   {
      notes[INDEX_RIGHT]=1;
      play_note(dungeonbasschannel,dungeonbass[dungeonmeasure][2],dungeonbasslevel);
   }

   if ((notes[INDEX_RIGHT] == 1) && (key_table[INDEX_RIGHT]==0))
   {
      kill_note(dungeonbasschannel,dungeonbass[dungeonmeasure][2],dungeonbasslevel);
      notes[INDEX_RIGHT]=0;
   }

   if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
   {
      notes[INDEX_UP]=1;
      play_note(dungeonbasschannel,dungeonbass[dungeonmeasure][3],dungeonbasslevel);
      count++;
   }

   if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))
   {
      if (count == 0)
         kill_note(dungeonbasschannel,dungeonbass[dungeonmeasure][3],dungeonbasslevel);
      else
         kill_note(dungeonbasschannel,dungeonbass[dungeonmeasure][3],dungeonbasslevel);
      notes[INDEX_UP]=0;
      if ((dungeonmeasure >= 6) && (dungeonmeasure <= 10))
      {
         if (count == 1)
         {
            cout << "\nNew measure: " << ++dungeonmeasure;
            count = 0;
         }
      }
      else
         if (count == 4)
         {
            cout << "\nNew measure: " << ++dungeonmeasure;
            count = 0;
         }

      if (dungeonmeasure == 11)
         dungeonmeasure = 1;

   }

   if ((notes[INDEX_SPACE] == 0) && (key_table[INDEX_SPACE]==1))
   {
      notes[INDEX_SPACE]=1;
      dungeonmeasure++;
      cout << "\nNew measure: " << dungeonmeasure;
   }

   if ((notes[INDEX_SPACE] == 1) && (key_table[INDEX_SPACE]==0))
   {
      notes[INDEX_SPACE]=0;
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

int delaydungeon(int speed)
{
   for (int index=0;index<speed;index++)
   {
      if (key_table[INDEX_ESC]) return 1;
         dodungeonstuff();
      delay (1);
   }
   return 0;
}

int level1()
 {
  bass1[0] = AS2;
  bass1[1] = GS2;
  bass1[2] = FS2;

  bass2[0][0] = AS2;
  bass2[1][0] = GS2;
  bass2[0][1] = GS2;
  bass2[1][1] = FS2;
  bass2[0][2] = FS2;
  bass2[1][2] = E2;
  bass2[0][3] = CS3;
  bass2[1][3] = B2;

  bass3[0][0] = B2;
  bass3[1][0] = AS2;
  bass3[0][1] = AS2;
  bass3[1][1] = GS2;
  bass3[0][2] = C3;
  bass3[1][2] = AS2;

  for (int i = 0; i < 3; i++)
   {

    cout << "1" << endl;
    if (i > 0) play_note(drumchannel,CS2,drumlevel);
    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass1[i],basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,D1,drumlevel);
    kill_note(basschannel,bass1[i],basslevel);

    cout << "2" << endl;
    play_note(basschannel,bass1[i],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass1[i],basslevel);

    play_note(basschannel,bass1[i],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass1[i],basslevel);

    if (delay1(speed)) break;

    play_note(basschannel,bass1[i],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass1[i],basslevel);
    kill_note(drumchannel,CS2,drumlevel);

    cout << "3" << endl;
    play_note(basschannel,bass1[i],basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(basschannel,bass1[i],basslevel);

    cout << "4" << endl;
    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass1[i],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass1[i],basslevel);
    kill_note(drumchannel,D1,drumlevel);

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass1[i],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass1[i],basslevel);
    kill_note(drumchannel,D1,drumlevel);

    if (delay1(speed)) break;

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass1[i],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass1[i],basslevel);
    kill_note(drumchannel,D1,drumlevel);
   }

for (int j = 0; j < 1; j++)
 {

  play_note(drumchannel,CS2,drumlevel);
  play_note(drumchannel,D1,drumlevel);
  play_note(basschannel,FS2,basslevel);
  if (delay1(speed*2)) break;
  kill_note(drumchannel,D1,drumlevel);
  kill_note(basschannel,FS2,basslevel);

  if (delay1(speed*2)) break;

  kill_note(drumchannel,CS2,drumlevel);

  play_note(drumchannel,CS2,drumlevel);
  play_note(drumchannel,D1,drumlevel);
  play_note(basschannel,F2,basslevel);
  if (delay1(speed*2)) break;
  kill_note(drumchannel,D1,drumlevel);
  kill_note(basschannel,F2,basslevel);

  if (delay1(speed*2)) break;

  kill_note(drumchannel,CS2,drumlevel);
  play_note(drumchannel,CS2,drumlevel);
  play_note(drumchannel,D1,drumlevel);
  play_note(basschannel,F2,basslevel);
  if (delay1(speed*2)) break;
  kill_note(drumchannel,D1,drumlevel);
  kill_note(basschannel,F2,basslevel);

  if (delay1(speed*2)) break;

  kill_note(drumchannel,CS2,drumlevel);
  play_note(drumchannel,CS2,drumlevel);
  play_note(drumchannel,D1,drumlevel);
  play_note(basschannel,G2,basslevel);
  if (delay1(speed*2)) break;
  kill_note(drumchannel,D1,drumlevel);
  kill_note(basschannel,G2,basslevel);
  kill_note(drumchannel,CS2,drumlevel);

  play_note(drumchannel,CS2,drumlevel);
  play_note(drumchannel,D1,drumlevel);
  play_note(basschannel,A2,basslevel);
  if (delay1(speed*2)) break;
  kill_note(drumchannel,D1,drumlevel);
  kill_note(basschannel,A2,basslevel);
  kill_note(drumchannel,CS2,drumlevel);


 }


  for (int a = 0; a < 4; a++)
   {

      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[0][a], basslevel);
      if (delay1(speed*2)) break;
      kill_note(basschannel,bass2[0][a], basslevel);
      kill_note(drumchannel,D1,drumlevel);

      if (delay1(speed*2)) break;

      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[0][a], basslevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,drumlevel);
      kill_note(basschannel,bass2[0][a], basslevel);

      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[0][a], basslevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,drumlevel);
      kill_note(basschannel,bass2[0][a], basslevel);


      if (delay1(speed)) break;

      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[1][a], basslevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,drumlevel);
      kill_note(basschannel,bass2[1][a], basslevel);

      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[0][a], basslevel);
      if (delay1(speed*2)) break;
      kill_note(basschannel,bass2[0][a], basslevel);
      kill_note(drumchannel,D1,drumlevel);

      if (delay1(speed*2)) break;


      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[0][a], basslevel);
      if (delay1(speed*2)) break;
      kill_note(basschannel,bass2[0][a], basslevel);
      kill_note(drumchannel,D1,drumlevel);

      if (delay1(speed*2)) break;

     }

  for (int b = 0; b <= 2; b++)
   {

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][b],basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,D1,drumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][b],basslevel);

    if (delay1(speed)) break;

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][b],basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,D1,drumlevel);
    kill_note(basschannel,bass3[0][b],basslevel);

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][b],basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,D1,drumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][b],basslevel);

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[1][b],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass3[1][b],basslevel);
    kill_note(drumchannel,D1,drumlevel);


    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][b],basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,D1,drumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][b],basslevel);

    if (delay1(speed)) break;

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][b],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][b],basslevel);

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][b],basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,D1,drumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][b],basslevel);

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][b],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][b],basslevel);
    kill_note(drumchannel,D1,drumlevel);


   }

 for (int u = 0; u < 1; u++) 
  {

   play_note(basschannel,F2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(basschannel,F2,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   if (delay1(speed)) break;
   if (delay1(speed)) break;

   play_note(basschannel,F2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;
   kill_note(drumchannel,D1,drumlevel);

   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;
   kill_note(drumchannel,D1,drumlevel);
   kill_note(basschannel,F2,basslevel);   

   if (delay1(speed)) break;
   if (delay1(speed)) break;

   play_note(basschannel,F2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(basschannel,F2,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   if (delay1(speed)) break;
   if (delay1(speed)) break;

   play_note(basschannel,G2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(basschannel,G2,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   play_note(basschannel,A2,basslevel);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(basschannel,A2,basslevel);   

  }


  for (int c = 0; c < 4; c++)
   {

      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[0][c], basslevel);
      if (delay1(speed*2)) break;
      kill_note(basschannel,bass2[0][c], basslevel);
      kill_note(drumchannel,D1,drumlevel);

      if (delay1(speed*2)) break;

      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[0][c], basslevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,drumlevel);
      kill_note(basschannel,bass2[0][c], basslevel);

      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[0][c], basslevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,drumlevel);
      kill_note(basschannel,bass2[0][c], basslevel);


      if (delay1(speed)) break;

      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[1][c], basslevel);
      if (delay1(speed)) break;
      kill_note(drumchannel,D1,drumlevel);
      kill_note(basschannel,bass2[1][c], basslevel);

      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[0][c], basslevel);
      if (delay1(speed*2)) break;
      kill_note(basschannel,bass2[0][c], basslevel);
      kill_note(drumchannel,D1,drumlevel);

      if (delay1(speed*2)) break;


      play_note(drumchannel,D1,drumlevel);
      play_note(basschannel,bass2[0][c], basslevel);
      if (delay1(speed*2)) break;
      kill_note(basschannel,bass2[0][c], basslevel);
      kill_note(drumchannel,D1,drumlevel);

      if (delay1(speed*2)) break;

     }

  for (int z = 0; z < 2; z++)
  {

   play_note(basschannel,E2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   kill_note(basschannel,E2,basslevel);

   play_note(basschannel,AS2,basslevel);
   if (delay1(speed)) break;
   kill_note(basschannel,AS2,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   if (delay1(speed)) break;   

   play_note(basschannel,CS3,basslevel);
   if (delay1(speed)) break;
   kill_note(basschannel,CS3,basslevel);

   play_note(basschannel,E3,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   kill_note(basschannel,E3,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   play_note(basschannel,AS3,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   kill_note(basschannel,AS3,basslevel);
   kill_note(drumchannel,D1,drumlevel);
   
   if (delay1(speed)) break;   

   play_note(basschannel,CS4,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   kill_note(basschannel,CS4,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   play_note(basschannel,E4,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   if (delay1(speed)) break;   
   kill_note(basschannel,E4,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   if (delay1(speed)) break;   
   if (delay1(speed)) break;   

   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   if (delay1(speed)) break;   
   kill_note(drumchannel,D1,drumlevel);   

   if (delay1(speed)) break;   
   if (delay1(speed)) break;   


   //Secnod part

   play_note(basschannel,F4,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   if (delay1(speed)) break;   
   kill_note(basschannel,F4,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   if (delay1(speed)) break;   
   if (delay1(speed)) break;   

   play_note(basschannel,F2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   kill_note(basschannel,F2,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   play_note(basschannel,F2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   kill_note(basschannel,F2,basslevel);
   kill_note(drumchannel,D1,drumlevel);
   
   if (delay1(speed)) break;   

   play_note(basschannel,F2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   kill_note(basschannel,F2,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   play_note(basschannel,F2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   if (delay1(speed)) break;   
   kill_note(drumchannel,D1,drumlevel);   
   kill_note(basschannel,F2,basslevel);

   if (delay1(speed)) break;   
   if (delay1(speed)) break;   

   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;   
   if (delay1(speed)) break;   
   kill_note(drumchannel,D1,drumlevel);   

   if (delay1(speed)) break;   
   if (delay1(speed)) break;   


  }


  for (int d = 0; d <= 2; d++)
   {

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][d],basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,D1,drumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][d],basslevel);

    if (delay1(speed)) break;

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][d],basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,D1,drumlevel);
    kill_note(basschannel,bass3[0][d],basslevel);

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][d],basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,D1,drumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][d],basslevel);

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[1][d],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass3[1][d],basslevel);
    kill_note(drumchannel,D1,drumlevel);


    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][d],basslevel);
    if (delay1(speed)) break;
    if (delay1(speed)) break;
    kill_note(drumchannel,D1,drumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][d],basslevel);

    if (delay1(speed)) break;

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][d],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][d],basslevel);

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][d],basslevel);
    if (delay1(speed)) break;
    kill_note(drumchannel,D1,drumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][d],basslevel);

    play_note(drumchannel,D1,drumlevel);
    play_note(basschannel,bass3[0][d],basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,bass3[0][d],basslevel);
    kill_note(drumchannel,D1,drumlevel);
   }

 for (int x = 0; x < 1; x++) 
  {

   play_note(basschannel,F2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(basschannel,F2,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   if (delay1(speed)) break;
   if (delay1(speed)) break;

   play_note(basschannel,F2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;
   kill_note(drumchannel,D1,drumlevel);

   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;
   kill_note(drumchannel,D1,drumlevel);
   kill_note(basschannel,F2,basslevel);   

   if (delay1(speed)) break;
   if (delay1(speed)) break;

   play_note(basschannel,F2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(basschannel,F2,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   if (delay1(speed)) break;
   if (delay1(speed)) break;

   play_note(basschannel,G2,basslevel);
   play_note(drumchannel,D1,drumlevel);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(basschannel,G2,basslevel);
   kill_note(drumchannel,D1,drumlevel);

   play_note(basschannel,A2,basslevel);
   if (delay1(speed)) break;
   if (delay1(speed)) break;
   kill_note(basschannel,A2,basslevel);   

  }
  return(1);
 }

void dungeon()
{
   clrscr();
   cout << "Zelda dungeon... Press ESC to quit";
   while (1)
   {
      if (delaydungeon(1)) break;
   }
}

void showtitle()
{
   clrscr();
   cout << "Zelda";
   cout << "\n1 to start";
   cout << "\nSPACE to dungeon\n\n";
   cout << "F3 F4 F5 F6 F7 F8 F9 Q W E R T" << endl;
   cout << "F3 F4 F5 A S A S A D F8 F9 Q W E R T " << endl;
}

void main()
{
   speed = 100;

   int measure = 1;
   GetBlastInfo(&blastInfo);
   MIDIType = SBMIDI;
   DSPReset();
   Init_MIDI();   

   install_keyboard();

   mix_mode();
   change_program(drumchannel,120,1);
   change_program(basschannel,41,1);
   change_program(chordchannel,53,2);
   change_program(evilbasschannel,49,2);
   change_program(fastchordchannel,54,3);

   mix_name("Zelda    ");
   mix_mode();
   showtitle();

   for (int index=0;index<127;index++)
      notes[index] = 0;   
   dungeonbass[0][0] = G3;
   dungeonbass[0][3] = DS4;

   dungeonbass[1][0] = G3;
   dungeonbass[1][1] = AS3;
   dungeonbass[1][2] = D4;
   dungeonbass[1][3] = DS4;

   dungeonbass[2][0] = FS3;
   dungeonbass[2][1] = A3;
   dungeonbass[2][2] = D4;
   dungeonbass[2][3] = DS4;

   dungeonbass[3][0] = F3;
   dungeonbass[3][1] = GS3;
   dungeonbass[3][2] = D4;
   dungeonbass[3][3] = DS4;

   dungeonbass[4][0] = E3;
   dungeonbass[4][1] = G3;
   dungeonbass[4][2] = D4;
   dungeonbass[4][3] = DS4;

   dungeonbass[5][0] = DS3;
   dungeonbass[5][1] = G3;
   dungeonbass[5][2] = C4;
   dungeonbass[5][3] = D4;

   dungeonbass[6][0] = D3;
   dungeonbass[6][1] = FS3;
   dungeonbass[6][2] = A3;
   dungeonbass[6][3] = C4;

   dungeonbass[7][0] = FS3;
   dungeonbass[7][1] = A3;
   dungeonbass[7][2] = C4;
   dungeonbass[7][3] = DS4;

   dungeonbass[8][0] = A3;
   dungeonbass[8][1] = C4;
   dungeonbass[8][2] = DS4;
   dungeonbass[8][3] = 0;

   dungeonbass[9][0] = DS4;
   dungeonbass[9][1] = FS4;
   dungeonbass[9][2] = 0;
   dungeonbass[9][3] = FS4;

   dungeonbass[10][0] = A4;
   dungeonbass[10][1] = 0;
   dungeonbass[10][2] = A4;
   dungeonbass[10][3] = C5;
   change_program(leadchannel,90,0);
   change_volume(1,leadlevel);
   change_program(dungeonbasschannel,101,1);
   change_program(chordchannel,53,0);

   while (1)
   {
      if (delay1(1)) break;
      if (key_table[INDEX_SPACE])
      {
         wait_for_no(INDEX_SPACE);
         dungeon();
         showtitle();
      }

      if (key_table[INDEX_11])
       {
        change_light_level(1,50);
        change_light_level(2,75);
        change_light_level(3,25);
        change_light_level(4,50);

        for (int index=0;index<4;index++)
        {
           play_note(drumchannel,FS1,127);
           if (delay1(speed)) break;
           if (delay1(speed)) break;
           if (delay1(speed)) break;
           if (delay1(speed)) break;
           kill_note(drumchannel,FS1,127);
        }

        level1();
       }
   }
//   all_lights_off(0);
   Exit_MIDI();
   kill_keyboard();
}
                                      
