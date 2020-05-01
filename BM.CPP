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
#define basslevel 127
#define basschannel 2
#define drumchannel 10
#define drumlevel 127
#define belllevel 75
#define bellchannel 3
#define clocklevel 127
#define clockchannel 4
#define rockdrumchannel 11
#define rockdrumlevel 127
#define backgroundchannel 5
#define backgroundlevel 75
#define chordchannel 6
#define chordlevel 100


int speed = 100;
int measure = 1;
int whereback = 0;
int wherebass = 1;
int leadlevel = 50;
int background [4][2];
int bassnotes [100][2];

void play1()
 {

  play_note(basschannel,D2,basslevel);
  play_note(leadchannel,D4,50);                   
 }

void kill1()
 {
  kill_note(basschannel,D2,basslevel);
  kill_note(leadchannel,D4,50);                   
 }


void play2()
 {

  play_note(basschannel,D2,basslevel);
  play_note(leadchannel,D4,65);                   
  play_note(leadchannel,G4,65);                   
 }

void kill2()
 {

  kill_note(basschannel,D2,basslevel);
  kill_note(leadchannel,D4,65);                   
  kill_note(leadchannel,G4,65);                   
 }

void play3()
 {

  play_note(basschannel,D2,basslevel);
  play_note(leadchannel,D4,80);                   
  play_note(leadchannel,G4,80);                   
  play_note(leadchannel,C5,80);                   

 }

void kill3()
 {

  kill_note(basschannel,D2,basslevel);
  kill_note(leadchannel,D4,80);                   
  kill_note(leadchannel,G4,80);                   
  kill_note(leadchannel,C5,80);                   
 }


void dostuff()
{
        leadlevel = 100;
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


        if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
        {   
          notes[INDEX_Q]=1;   
          play_note(chordchannel,A4,chordlevel);                   
          play_note(chordchannel,CS4,chordlevel);                   
        }
        if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))   
        {   
          kill_note(chordchannel,A4,chordlevel);                   
          kill_note(chordchannel,CS4,chordlevel);                   
          notes[INDEX_Q]=0;   
        }   


        if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
        {   
          notes[INDEX_W]=1;   
          play_note(chordchannel,E4,chordlevel);                   
          play_note(chordchannel,A3,chordlevel);                   
        }
        if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))   
        {   
          kill_note(chordchannel,E4,chordlevel);                   
          kill_note(chordchannel,A3,chordlevel);                   
          notes[INDEX_W]=0;   
        }   


        if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
        {   
          notes[INDEX_E]=1;   
          play_note(chordchannel,G4,chordlevel);                   
          play_note(chordchannel,B3,chordlevel);                   
        }
        if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))   
        {   
          kill_note(chordchannel,G4,chordlevel);                   
          kill_note(chordchannel,B3,chordlevel);                   
          notes[INDEX_E]=0;   
        }   

        if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
        {   
          notes[INDEX_R]=1;   
          play_note(chordchannel,G4,chordlevel);                   
          play_note(chordchannel,D4,chordlevel);                   
        }
        if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))   
        {   
          kill_note(chordchannel,G4,chordlevel);                   
          kill_note(chordchannel,D4,chordlevel);                   
          notes[INDEX_R]=0;   
        }   

        if ((notes[INDEX_T] == 0) && (key_table[INDEX_T]==1))
        {   
          notes[INDEX_T]=1;   
          play_note(chordchannel,FS4,chordlevel);                   
          play_note(chordchannel,D4,chordlevel);                   
        }
        if ((notes[INDEX_T] == 1) && (key_table[INDEX_T]==0))   
        {   
          kill_note(chordchannel,FS4,chordlevel);                   
          kill_note(chordchannel,D4,chordlevel);                   
          notes[INDEX_T]=0;   
        }   

        if ((notes[INDEX_A] == 0) && (key_table[INDEX_A]==1))
        {   
          notes[INDEX_A]=1;   
          play_note(chordchannel,E4,chordlevel);                   
          play_note(chordchannel,CS4,chordlevel);                   
        }
        if ((notes[INDEX_A] == 1) && (key_table[INDEX_A]==0))   
        {   
          kill_note(chordchannel,E4,chordlevel);                   
          kill_note(chordchannel,CS4,chordlevel);                   
          notes[INDEX_A]=0;   
        }   

        if ((notes[INDEX_S] == 0) && (key_table[INDEX_S]==1))
        {   
          notes[INDEX_S]=1;   
          play_note(chordchannel,D4,chordlevel);                   
          play_note(chordchannel,B3,chordlevel);                   
        }
        if ((notes[INDEX_S] == 1) && (key_table[INDEX_S]==0))   
        {   
          kill_note(chordchannel,D4,chordlevel);                   
          kill_note(chordchannel,B3,chordlevel);                   
          notes[INDEX_S]=0;   
        }   

        if ((notes[INDEX_D] == 0) && (key_table[INDEX_D]==1))
        {   
          notes[INDEX_D]=1;   
          play_note(chordchannel,E4,chordlevel);                   
          play_note(chordchannel,B3,chordlevel);                   
        }
        if ((notes[INDEX_D] == 1) && (key_table[INDEX_D]==0))   
        {   
          kill_note(chordchannel,E4,chordlevel);                   
          kill_note(chordchannel,B3,chordlevel);                   
          notes[INDEX_D]=0;   
        }   

        if ((notes[INDEX_F] == 0) && (key_table[INDEX_F]==1))
        {   
          notes[INDEX_F]=1;   
          play_note(chordchannel,F4,chordlevel);                   
          play_note(chordchannel,C4,chordlevel);                   
        }
        if ((notes[INDEX_F] == 1) && (key_table[INDEX_F]==0))
        {   
          kill_note(chordchannel,F4,chordlevel);                   
          kill_note(chordchannel,C4,chordlevel);                   
          notes[INDEX_F]=0;   
        }   


        if ((notes[INDEX_G] == 0) && (key_table[INDEX_G]==1))
        {   
          notes[INDEX_G]=1;   
          play_note(chordchannel,GS4,chordlevel);                   
          play_note(chordchannel,E4,chordlevel);                   
        }
        if ((notes[INDEX_G] == 1) && (key_table[INDEX_G]==0))
        {   
          kill_note(chordchannel,GS4,chordlevel);                   
          kill_note(chordchannel,E4,chordlevel);                   
          notes[INDEX_G]=0;   
        }   


        if ((notes[INDEX_11] == 0) && (key_table[INDEX_11]==1))
        {   
          notes[INDEX_11]=1;   
          play_note(leadchannel,D4,leadlevel);                   

        }
        if ((notes[INDEX_11] == 1) && (key_table[INDEX_11]==0))
        {   
          kill_note(leadchannel,D4,leadlevel);                   

          notes[INDEX_11]=0;   
        }   


        if ((notes[INDEX_21] == 0) && (key_table[INDEX_21]==1))
        {   
          notes[INDEX_21]=1;   
          play_note(leadchannel,D4,leadlevel);                   
          play_note(leadchannel,G4,leadlevel);                   
        }
        if ((notes[INDEX_21] == 1) && (key_table[INDEX_21]==0))
        {   
          kill_note(leadchannel,D4,leadlevel);                   
          kill_note(leadchannel,G4,leadlevel);                   
          notes[INDEX_21]=0;   
        }   


        if ((notes[INDEX_31] == 0) && (key_table[INDEX_31]==1))
        {   
          notes[INDEX_31]=1;   
          play_note(leadchannel,D4,leadlevel);                   
          play_note(leadchannel,G4,leadlevel);                   
          play_note(leadchannel,C5,leadlevel);                   
        }
        if ((notes[INDEX_31] == 1) && (key_table[INDEX_31]==0))
        {   
          kill_note(leadchannel,D4,leadlevel);                   
          kill_note(leadchannel,G4,leadlevel);                   
          kill_note(leadchannel,C5,leadlevel);                   
          notes[INDEX_31]=0;
        }   

        if ((notes[INDEX_41] == 0) && (key_table[INDEX_41]==1))
        {   
          notes[INDEX_41]=1;   
          play_note(chordchannel,E2,chordlevel);                   
          play_note(chordchannel,G2,chordlevel);                   
          play_note(chordchannel,B2,chordlevel);                   
        }
        if ((notes[INDEX_41] == 1) && (key_table[INDEX_41]==0))
        {   
          kill_note(chordchannel,E2,chordlevel);                   
          kill_note(chordchannel,G2,chordlevel);                   
          kill_note(chordchannel,B2,chordlevel);                   
          notes[INDEX_41]=0;
        }   

        if ((notes[INDEX_51] == 0) && (key_table[INDEX_51]==1))
        {   
          notes[INDEX_51]=1;   
          play_note(chordchannel,AS2,chordlevel);                   
          play_note(chordchannel,D3,chordlevel);                   
          play_note(chordchannel,G2,chordlevel);                   
        }
        if ((notes[INDEX_51] == 1) && (key_table[INDEX_51]==0))
        {   
          kill_note(chordchannel,AS2,chordlevel);                   
          kill_note(chordchannel,D3,chordlevel);                   
          kill_note(chordchannel,G2,chordlevel);                   
          notes[INDEX_51]=0;
        }   

        if ((notes[INDEX_61] == 0) && (key_table[INDEX_61]==1))
        {   
          notes[INDEX_61]=1;   
          play_note(chordchannel,AS2,chordlevel);                   
          play_note(chordchannel,D3,chordlevel);                   
          play_note(chordchannel,F3,chordlevel);                   
        }
        if ((notes[INDEX_61] == 1) && (key_table[INDEX_61]==0))
        {   
          kill_note(chordchannel,AS2,chordlevel);                   
          kill_note(chordchannel,D3,chordlevel);                   
          kill_note(chordchannel,F3,chordlevel);                   
          notes[INDEX_61]=0;
        }   

/*        if ((notes[INDEX_F1] == 0) && (key_table[INDEX_F1]==1))
        {   
          notes[INDEX_F1]=1;   
          play1();
        }   
        if ((notes[INDEX_F1] == 1) && (key_table[INDEX_F1]==0))   
        {   
          notes[INDEX_F1] = 0;
          kill1();
        }   

        if ((notes[INDEX_F2] == 0) && (key_table[INDEX_F2]==1))
        {   
          notes[INDEX_F2]=1;   
          play2();
        }   
        if ((notes[INDEX_F2] == 1) && (key_table[INDEX_F2]==0))   
        {   
          notes[INDEX_F2]=0;
          kill2();
        }   

        if ((notes[INDEX_F3] == 0) && (key_table[INDEX_F3]==1))
        {   
          notes[INDEX_F3]=1;   
          play3();
        }   
        if ((notes[INDEX_F3] == 1) && (key_table[INDEX_F3]==0))   
        {   
          notes[INDEX_F3] = 0;
          kill3();
        }   */
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

int level2()
 {
  speed = 150;
  int measure = 1;
  for (measure = 1; measure < 50; measure++)
   {

    if (measure == 20)
     {
    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);
    play_note(rockdrumchannel,B1,rockdrumlevel);
    play_note(rockdrumchannel,F2,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,B1,rockdrumlevel);
    kill_note(rockdrumchannel,F2,rockdrumlevel);
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);

    if (delay1(speed)) break;

    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);

    if (delay1(speed)) break;
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);

    play_note(basschannel,D3,basslevel);
    play_note(basschannel,D2,basslevel);

    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);
    kill_note(basschannel,D3,basslevel);
    kill_note(basschannel,D2,basslevel);

    play_note(basschannel,B2,basslevel);
    play_note(basschannel,B1,basslevel);

    if (delay1(speed)) break;
    kill_note(basschannel,B2,basslevel);
    kill_note(basschannel,B1,basslevel);

    play_note(basschannel,D3,basslevel);
    play_note(basschannel,D2,basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,D3,basslevel);
    kill_note(basschannel,D2,basslevel);



    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);
    play_note(rockdrumchannel,F1,rockdrumlevel);
    play_note(rockdrumchannel,B0,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,F1,rockdrumlevel);
    kill_note(rockdrumchannel,B0,rockdrumlevel);
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);

    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);
    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);


    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);
    play_note(rockdrumchannel,F1,rockdrumlevel);
    play_note(rockdrumchannel,B0,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,F1,rockdrumlevel);
    kill_note(rockdrumchannel,B0,rockdrumlevel);
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);


    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);
    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);


    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);
    if (delay1(speed)) break;
    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);


    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);

    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);

     measure = 1;
     }
    else

    if (measure > 12)
     {

    cout << "Measure = 12" << endl;
    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);
    play_note(rockdrumchannel,B1,rockdrumlevel);
    play_note(rockdrumchannel,F2,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,B1,rockdrumlevel);
    kill_note(rockdrumchannel,F2,rockdrumlevel);
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);

    if (delay1(speed)) break;

    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);

    if (delay1(speed)) break;
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);


    play_note(basschannel,D3,basslevel);
    play_note(basschannel,D2,basslevel);

    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);
    kill_note(basschannel,D3,basslevel);
    kill_note(basschannel,D2,basslevel);

    play_note(basschannel,B2,basslevel);
    play_note(basschannel,B1,basslevel);

    if (delay1(speed)) break;
    kill_note(basschannel,B2,basslevel);
    kill_note(basschannel,B1,basslevel);

    play_note(basschannel,D3,basslevel);
    play_note(basschannel,D2,basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,D3,basslevel);
    kill_note(basschannel,D2,basslevel);

    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);
    play_note(rockdrumchannel,B1,rockdrumlevel);
    play_note(rockdrumchannel,F2,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,B1,rockdrumlevel);
    kill_note(rockdrumchannel,F2,rockdrumlevel);
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);

    if (delay1(speed)) break;

    play_note(basschannel,E3,basslevel);
    play_note(basschannel,E2,basslevel);

    if (delay1(speed)) break;
    kill_note(basschannel,E3,basslevel);
    kill_note(basschannel,E2,basslevel);


    play_note(basschannel,D3,basslevel);
    play_note(basschannel,D2,basslevel);

    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);
    kill_note(basschannel,D3,basslevel);
    kill_note(basschannel,D2,basslevel);

    play_note(basschannel,B2,basslevel);
    play_note(basschannel,B1,basslevel);

    if (delay1(speed)) break;
    kill_note(basschannel,B2,basslevel);
    kill_note(basschannel,B1,basslevel);

    play_note(basschannel,D3,basslevel);
    play_note(basschannel,D2,basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,D3,basslevel);
    kill_note(basschannel,D2,basslevel);


     }

    else
    if (measure == 4)
     {
    play_note(basschannel,A2,basslevel);
    play_note(rockdrumchannel,B1,rockdrumlevel);
    play_note(rockdrumchannel,F2,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,B1,rockdrumlevel);
    kill_note(rockdrumchannel,F2,rockdrumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);
    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,A2,basslevel);
    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);
    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);


    play_note(basschannel,A2,basslevel);
    play_note(rockdrumchannel,F1,rockdrumlevel);
    play_note(rockdrumchannel,B0,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,F1,rockdrumlevel);
    kill_note(rockdrumchannel,B0,rockdrumlevel);

    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);
    play_note(basschannel,A2,basslevel);
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);

    play_note(rockdrumchannel,F1,rockdrumlevel);
    play_note(rockdrumchannel,B0,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);
    kill_note(rockdrumchannel,F1,rockdrumlevel);
    kill_note(rockdrumchannel,B0,rockdrumlevel);

    play_note(basschannel,A2,basslevel);
    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);
    play_note(basschannel,A2,basslevel);
    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);
    kill_note(basschannel,A2,basslevel);


     }
    else

    if ((measure == 8) || (measure == 12))
     {
    play_note(basschannel,F2,basslevel);
    play_note(rockdrumchannel,B1,rockdrumlevel);
    play_note(rockdrumchannel,F2,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,B1,rockdrumlevel);
    kill_note(rockdrumchannel,F2,rockdrumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,F2,basslevel);
    play_note(basschannel,F2,basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,F2,basslevel);

    play_note(basschannel,F2,basslevel);
    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,F2,basslevel);
    play_note(basschannel,F2,basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,F2,basslevel);

    play_note(basschannel,G2,basslevel);
    play_note(rockdrumchannel,F1,rockdrumlevel);
    play_note(rockdrumchannel,B0,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,F1,rockdrumlevel);
    kill_note(rockdrumchannel,B0,rockdrumlevel);

    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(basschannel,G2,basslevel);
    play_note(basschannel,G2,basslevel);
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);

    play_note(rockdrumchannel,F1,rockdrumlevel);
    play_note(rockdrumchannel,B0,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(basschannel,G2,basslevel);
    kill_note(rockdrumchannel,F1,rockdrumlevel);
    kill_note(rockdrumchannel,B0,rockdrumlevel);

    play_note(basschannel,G2,basslevel);
    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,G2,basslevel);
    play_note(basschannel,G2,basslevel);
    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    play_note(basschannel,G2,basslevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);
    kill_note(basschannel,G2,basslevel);


     }
 

  if ((measure >= 1) && (measure !=4) && (measure != 8) && (measure != 12) && (measure <= 12))
    {

    play_note(basschannel,A2,basslevel);
    play_note(rockdrumchannel,B1,rockdrumlevel);
    play_note(rockdrumchannel,F2,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,B1,rockdrumlevel);
    kill_note(rockdrumchannel,F2,rockdrumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);
    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,A2,basslevel);
    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);
    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);


    play_note(basschannel,A2,basslevel);
    play_note(rockdrumchannel,B1,rockdrumlevel);
    play_note(rockdrumchannel,F2,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,B1,rockdrumlevel);
    kill_note(rockdrumchannel,F2,rockdrumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);
    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);

    play_note(basschannel,A2,basslevel);
    play_note(rockdrumchannel,FS2,rockdrumlevel);
    play_note(rockdrumchannel,E1,rockdrumlevel);
    if (delay1(speed)) break;
    kill_note(rockdrumchannel,FS2,rockdrumlevel);
    kill_note(rockdrumchannel,E1,rockdrumlevel);

    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);
    play_note(basschannel,A2,basslevel);
    if (delay1(speed)) break;
    kill_note(basschannel,A2,basslevel);
     }
   }
 }


int level1()
{
   change_light_level(1,50);
   change_light_level(2,75);
   change_light_level(3,25);
   change_light_level(4,50);

  while(1 == 1)
     {
      cout << "\nMeasure " << measure;

      if (measure == 34)
       
       {
        cout << "actual 34";
        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);

        if (delay1(speed)) break;
        kill_note(rockdrumchannel,GS1,rockdrumlevel);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(rockdrumchannel,C1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        play_note(rockdrumchannel,D1,rockdrumlevel);
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,C1,rockdrumlevel);
        kill_note(rockdrumchannel,D1,rockdrumlevel);
        kill_note(rockdrumchannel,GS1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        play_note(rockdrumchannel,D1,rockdrumlevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,C1,rockdrumlevel);
        kill_note(rockdrumchannel,D1,rockdrumlevel);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(rockdrumchannel,GS1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,D1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,D1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        play_note(rockdrumchannel,D1,rockdrumlevel);
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,C1,rockdrumlevel);
        kill_note(rockdrumchannel,D1,rockdrumlevel);
        kill_note(rockdrumchannel,GS1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,D1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,D1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,D1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,D1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,D1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,D1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        wherebass = 1;
        whereback = 0;

        measure = 1;

       }
      

      if ((measure >= 31) && (measure < 35))
       {
        cout << "31";
        if (measure == 32)
        play_note(rockdrumchannel,CS2,rockdrumlevel);
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        play_note(basschannel,G1,basslevel);
        if (delay1(speed)) break;
        kill_note(basschannel,G1,basslevel);
        kill_note(rockdrumchannel,CS2,rockdrumlevel);
        kill_note(rockdrumchannel,GS1,rockdrumlevel);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(rockdrumchannel,C1,rockdrumlevel);

        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(basschannel,G1,basslevel);
        if (delay1(speed)) break;
        kill_note(basschannel,G1,basslevel);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);

        play_note(rockdrumchannel,AS1,rockdrumlevel);
        play_note(basschannel,G2,basslevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        play_note(rockdrumchannel,D1,rockdrumlevel);
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,C1,rockdrumlevel);
        kill_note(rockdrumchannel,D1,rockdrumlevel);
        kill_note(rockdrumchannel,GS1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,GS1,rockdrumlevel);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(rockdrumchannel,C1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        play_note(rockdrumchannel,D1,rockdrumlevel);
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,C1,rockdrumlevel);
        kill_note(rockdrumchannel,D1,rockdrumlevel);
        kill_note(rockdrumchannel,GS1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G1,basslevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(basschannel,G1,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

        play_note(basschannel,G2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,G2,basslevel);

       measure++;
       }


      if ((measure > 26) && (measure < 31))
       {
      

        if (measure == 27)
         {
         change_program(leadchannel,33,0);
         leadlevel = 99;
         change_volume(1,99);

         cout << endl << "Q W Q E    R T A S A" << endl;
         cout << "DD FF R RFD DD FF RR G" << endl;
     

        kill_note(bellchannel,F1,belllevel);

        play_note(rockdrumchannel,DS2,rockdrumlevel);
        delay1(speed*4);
        kill_note(rockdrumchannel,DS2,rockdrumlevel);

        play_note(rockdrumchannel,DS2,rockdrumlevel);
        delay1(speed*4);
        kill_note(rockdrumchannel,DS2,rockdrumlevel);


          level2();
          all_lights_off(0);
          change_light_level(3,127);

         }

         play_note(rockdrumchannel,GS1,rockdrumlevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(basschannel,DS1,basslevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,GS1,rockdrumlevel);
        kill_note(rockdrumchannel,C1,rockdrumlevel);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(basschannel,DS1,basslevel);

        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(basschannel,DS1,basslevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(basschannel,DS1,basslevel);

        play_note(basschannel,DS2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,DS2,basslevel);

        play_note(basschannel,DS2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,DS2,basslevel);

        play_note(basschannel,F1,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        play_note(rockdrumchannel,CS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(rockdrumchannel,CS1,rockdrumlevel);
        kill_note(basschannel,F1,basslevel);

        play_note(basschannel,F1,basslevel);
        play_note(rockdrumchannel,DS1,rockdrumlevel);
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,GS1,rockdrumlevel);
        kill_note(rockdrumchannel,DS1,rockdrumlevel);
        kill_note(basschannel,F1,basslevel);

        play_note(basschannel,F2,basslevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(basschannel,F2,basslevel);

        play_note(basschannel,F2,basslevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(basschannel,F2,basslevel);

        play_note(basschannel,DS1,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        play_note(rockdrumchannel,CS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(rockdrumchannel,CS1,rockdrumlevel);
        kill_note(basschannel,DS1,basslevel);

        play_note(basschannel,DS1,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,DS1,basslevel);

        play_note(basschannel,DS2,basslevel);
        play_note(rockdrumchannel,AS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
        kill_note(basschannel,DS2,basslevel);

        play_note(basschannel,DS2,basslevel);
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,GS1,rockdrumlevel);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(basschannel,DS2,basslevel);

        play_note(basschannel,F1,basslevel);
        play_note(rockdrumchannel,D1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumchannel,D1,rockdrumlevel);
        kill_note(basschannel,F1,basslevel);

        play_note(basschannel,F2,basslevel);
        play_note(rockdrumlevel,FS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumlevel,FS1,rockdrumlevel);
        kill_note(basschannel,F2,basslevel);

        play_note(basschannel,F2,basslevel);
        play_note(rockdrumlevel,FS1,rockdrumlevel);
        if (delay1(speed)) break;
        kill_note(rockdrumlevel,FS1,rockdrumlevel);
        kill_note(basschannel,F2,basslevel);
  
       measure++;

       }

      if (measure == 25)
       {

      play_note(rockdrumchannel,FS1,rockdrumlevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(backgroundchannel,AS3,backgroundlevel);
      play_note(basschannel,FS1,basslevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,A2,rockdrumlevel);
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(backgroundchannel,AS3,backgroundlevel);

      play_note(backgroundchannel,CS4,backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,CS4,backgroundlevel);

      play_note(backgroundchannel,FS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,FS4,backgroundlevel);

      play_note(backgroundchannel,AS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(basschannel,FS1,basslevel);
      kill_note(backgroundchannel,AS4,backgroundlevel);

      play_note(backgroundchannel,AS3,backgroundlevel);
      play_note(basschannel,FS1,basslevel);
      play_note(rockdrumchannel,CS1,rockdrumlevel);
      play_note(rockdrumchannel,D1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(backgroundchannel,AS3,backgroundlevel);      
      kill_note(rockdrumchannel,CS1,rockdrumlevel);
      kill_note(rockdrumchannel,D1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);

      play_note(backgroundchannel,CS4,backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,CS4,backgroundlevel);

      play_note(backgroundchannel,FS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,FS4,backgroundlevel);

      play_note(backgroundchannel,AS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,AS4,backgroundlevel);
      kill_note(basschannel,FS1,basslevel);

      play_note(backgroundchannel,AS3,backgroundlevel);
      play_note(basschannel,FS1,basslevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(backgroundchannel,AS3,backgroundlevel);      
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);
      kill_note(rockdrumchannel,FS1,rockdrumlevel);

      play_note(backgroundchannel,CS4,backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,CS4,backgroundlevel);

      play_note(backgroundchannel,FS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,FS4,backgroundlevel);

      play_note(backgroundchannel,A4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,A4,backgroundlevel);
      kill_note(basschannel,FS1,basslevel);

      play_note(backgroundchannel,AS3,backgroundlevel);
      play_note(basschannel,FS1,basslevel);
      play_note(rockdrumchannel,CS1,rockdrumlevel);
      play_note(rockdrumchannel,D1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(backgroundchannel,AS3,backgroundlevel);      
      kill_note(rockdrumchannel,CS1,rockdrumlevel);
      kill_note(rockdrumchannel,D1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);

      play_note(backgroundchannel,CS4,backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,CS4,backgroundlevel);

      play_note(backgroundchannel,FS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,FS4,backgroundlevel);

      play_note(backgroundchannel,AS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,AS4,backgroundlevel);
      kill_note(basschannel,FS1,basslevel);

      measure++;
      cout << "Measure: " << measure << endl;

      play_note(rockdrumchannel,D1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(backgroundchannel,AS3,backgroundlevel);
      play_note(basschannel,FS1,basslevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,D1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(backgroundchannel,AS3,backgroundlevel);

      play_note(backgroundchannel,CS4,backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,CS4,backgroundlevel);

      play_note(backgroundchannel,FS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,FS4,backgroundlevel);

      play_note(backgroundchannel,AS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(basschannel,FS1,basslevel);
      kill_note(backgroundchannel,AS4,backgroundlevel);

      play_note(backgroundchannel,CS4,backgroundlevel);
      play_note(basschannel,FS1,basslevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(backgroundchannel,CS4,backgroundlevel);      
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);

      play_note(backgroundchannel,FS4,backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,FS4,backgroundlevel);

      play_note(backgroundchannel,AS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,AS4,backgroundlevel);

      play_note(backgroundchannel,CS5,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,CS5,backgroundlevel);
      kill_note(basschannel,FS1,basslevel);

      play_note(backgroundchannel,FS5,backgroundlevel);
      play_note(basschannel,FS1,basslevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(backgroundchannel,FS5,backgroundlevel);      
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);

      play_note(backgroundchannel,CS5,backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,CS5,backgroundlevel);

      play_note(backgroundchannel,AS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,AS4,backgroundlevel);

      play_note(backgroundchannel,FS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,FS4,backgroundlevel);
      kill_note(basschannel,FS1,basslevel);


      play_note(backgroundchannel,AS4,backgroundlevel);
      play_note(basschannel,FS1,basslevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(backgroundchannel,AS4,backgroundlevel);      
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);

      play_note(backgroundchannel,FS4,backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,FS4,backgroundlevel);

      play_note(backgroundchannel,CS4,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,CS4,backgroundlevel);

      play_note(backgroundchannel,AS3,backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,AS3,backgroundlevel);
      kill_note(basschannel,FS1,basslevel);
      measure++;
       }


      if (measure <= 18)
       {

      play_note(basschannel,bassnotes[wherebass][0],basslevel);
      if (measure == 1)
      play_note(rockdrumchannel,A2,rockdrumlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(basschannel,bassnotes[wherebass][0],basslevel);
      kill_note(rockdrumchannel,A2,rockdrumlevel);
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(rockdrumchannel,C1,rockdrumlevel);

      play_note(basschannel,bassnotes[wherebass][0],basslevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][0],basslevel);


      play_note(basschannel,bassnotes[wherebass][1],basslevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][1],basslevel);

      play_note(basschannel,bassnotes[wherebass][1],basslevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][1],basslevel);

      play_note(basschannel,bassnotes[wherebass][0],basslevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      play_note(rockdrumchannel,D1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);
      kill_note(rockdrumchannel,D1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][0],basslevel);

      play_note(basschannel,bassnotes[wherebass][0],basslevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][0],basslevel);

      play_note(basschannel,bassnotes[wherebass][1],basslevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][1],basslevel);

      play_note(basschannel,bassnotes[wherebass][1],basslevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][1],basslevel);
      
      play_note(basschannel,bassnotes[wherebass][0],basslevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][0],basslevel);

      play_note(basschannel,bassnotes[wherebass][0],basslevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][0],basslevel);

      play_note(basschannel,bassnotes[wherebass][1],basslevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][1],basslevel);

      play_note(basschannel,bassnotes[wherebass][1],basslevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][1],basslevel);

      if (measure == 18)
       {
      play_note(basschannel,bassnotes[wherebass][0],basslevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(rockdrumchannel,D1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,GS1,rockdrumlevel);
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(rockdrumchannel,D1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][0],basslevel);

      play_note(basschannel,bassnotes[wherebass][0],basslevel);
      play_note(rockdrumchannel,D1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,D1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][0],basslevel);

      play_note(basschannel,bassnotes[wherebass][1],basslevel);
      play_note(rockdrumchannel,D1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,D1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][1],basslevel);

      play_note(basschannel,bassnotes[wherebass][1],basslevel);
      play_note(rockdrumchannel,D1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,D1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][1],basslevel);
       }

      else

       {

      play_note(basschannel,bassnotes[wherebass][0],basslevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      play_note(rockdrumchannel,D1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);
      kill_note(rockdrumchannel,D1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][0],basslevel);

      play_note(basschannel,bassnotes[wherebass][0],basslevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][0],basslevel);

      play_note(basschannel,bassnotes[wherebass][1],basslevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][1],basslevel);

      play_note(basschannel,bassnotes[wherebass][1],basslevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(basschannel,bassnotes[wherebass][1],basslevel);

     }
      measure++;
    }

    if ((measure > 18) && (measure < 26))

     {


      if (measure == 19)
       play_note(rockdrumchannel,A2,rockdrumlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(backgroundchannel,background[0][whereback],backgroundlevel);
      play_note(basschannel,A1,basslevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,A2,rockdrumlevel);
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(backgroundchannel,background[0][whereback],backgroundlevel);

      play_note(backgroundchannel,background[1][whereback],backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,background[1][whereback],backgroundlevel);

      play_note(backgroundchannel,background[2][whereback],backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,background[2][whereback],backgroundlevel);

      play_note(backgroundchannel,background[3][whereback],backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(basschannel,A1,basslevel);
      kill_note(backgroundchannel,background[3][whereback],backgroundlevel);

      play_note(backgroundchannel,background[0][whereback],backgroundlevel);
      play_note(basschannel,A1,basslevel);
      play_note(rockdrumchannel,CS1,rockdrumlevel);
      play_note(rockdrumchannel,D1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(backgroundchannel,background[0][whereback],backgroundlevel);      
      kill_note(rockdrumchannel,CS1,rockdrumlevel);
      kill_note(rockdrumchannel,D1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);

      play_note(backgroundchannel,background[1][whereback],backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,background[1][whereback],backgroundlevel);

      play_note(backgroundchannel,background[2][whereback],backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,background[2][whereback],backgroundlevel);

      play_note(backgroundchannel,background[2][whereback],backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,background[2][whereback],backgroundlevel);
      kill_note(basschannel,A1,basslevel);

      play_note(backgroundchannel,background[0][whereback],backgroundlevel);
      play_note(basschannel,A1,basslevel);
      play_note(rockdrumchannel,C1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(backgroundchannel,background[0][whereback],backgroundlevel);      
      kill_note(rockdrumchannel,C1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);
      kill_note(rockdrumchannel,FS1,rockdrumlevel);

      play_note(backgroundchannel,background[1][whereback],backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,background[1][whereback],backgroundlevel);

      play_note(backgroundchannel,background[2][whereback],backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,background[2][whereback],backgroundlevel);

      play_note(backgroundchannel,background[2][whereback],backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,background[2][whereback],backgroundlevel);
      kill_note(basschannel,A1,basslevel);

      play_note(backgroundchannel,background[0][whereback],backgroundlevel);
      play_note(basschannel,A1,basslevel);
      play_note(rockdrumchannel,CS1,rockdrumlevel);
      play_note(rockdrumchannel,D1,rockdrumlevel);
      play_note(rockdrumchannel,GS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(backgroundchannel,background[0][whereback],backgroundlevel);      
      kill_note(rockdrumchannel,CS1,rockdrumlevel);
      kill_note(rockdrumchannel,D1,rockdrumlevel);
      kill_note(rockdrumchannel,GS1,rockdrumlevel);

      play_note(backgroundchannel,background[1][whereback],backgroundlevel);
      play_note(rockdrumchannel,FS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,FS1,rockdrumlevel);
      kill_note(backgroundchannel,background[1][whereback],backgroundlevel);

      play_note(backgroundchannel,background[2][whereback],backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,background[2][whereback],backgroundlevel);

      play_note(backgroundchannel,background[2][whereback],backgroundlevel);
      play_note(rockdrumchannel,AS1,rockdrumlevel);
      if (delay1(speed)) break;
      kill_note(rockdrumchannel,AS1,rockdrumlevel);
      kill_note(backgroundchannel,background[2][whereback],backgroundlevel);
      kill_note(basschannel,A1,basslevel);

      if (whereback == 0)
       whereback++;
       else whereback=0;
      measure++;
     }
     if (wherebass < 4)
      wherebass++;
     else wherebass=1;
     }
     wait_for_no(INDEX_ESC);
 }

void showtitle()
{
   clrscr();
   cout << "Blaster Master";
   cout << "\nF1: Level 1";
   cout << "\nF2: Level 2";
   cout << "\nF12: Count Down Intro";
   cout << "\n(intro now)";
   cout << "\n[SPACE] Start";
}

void main()
{
   speed = 120;
   wherebass = 1;
   whereback = 0;

   bassnotes[1][0] = G1;
   bassnotes[1][1] = G2;
   bassnotes[2][0] = G1;
   bassnotes[2][1] = G2;
   bassnotes[3][0] = G1;
   bassnotes[3][1] = G2;
   bassnotes[4][0] = DS1;
   bassnotes[4][1] = DS2;

   background[0][0] = A3;
   background[1][0] = CS4;
   background[2][0] = E4;
   background[3][0] = A4;

   background[0][1] = G3;
   background[1][1] = B3;
   background[2][1] = D4;
   background[3][1] = G4;

   int measure = 1;
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
    change_program(rockdrumchannel,120,0);
    change_program(backgroundchannel,13,3);
    change_program(chordchannel,52,2);
    change_volume(leadchannel,leadlevel);

   mix_name("Blaster  ");
   mix_mode();
   showtitle();

   for (int index=0;index<127;index++)
      notes[index] = 0;   
   
   while (1)
   {
      if (delay1(1)) break;

      if (key_table[INDEX_F12])
      {
         all_lights_off(0);
         cout << "9 ";
         mix_name("9          ");
         mix_mode();
         delay1(200);
         cout << "8 ";
         mix_name("8          ");
         mix_mode();
         delay1(200);
         cout << "7 ";
         mix_name("7          ");
         mix_mode();
         delay1(200);
         cout << "6 ";
         mix_name("6          ");
         mix_mode();
         delay1(200);
         cout << "5 ";
         mix_name("5          ");
         mix_mode();
         delay1(200);
         cout << "4 ";
         mix_name("4          ");
         mix_mode();
         delay1(200);
         cout << "3 ";
         mix_name("3          ");
         mix_mode();
         delay1(200);
         cout << "2 ";
         mix_name("2          ");
         mix_mode();
         delay1(200);
         cout << "1 ";
         mix_name("1          ");
         mix_mode();
         delay1(200);
         mix_name("Blaster   ");
         mix_mode();
         change_light_level(1,50);
         change_light_level(2,50);
      }

      if (key_table[INDEX_F2])
      {
         change_program(leadchannel,33,0);
         leadlevel = 99;
         change_volume(1,99);

         cout << endl << "Q W Q E    R T A S A" << endl;
         cout << "DD FF R RFD DD FF RR G" << endl;
     

        kill_note(bellchannel,F1,belllevel);

        play_note(rockdrumchannel,DS2,rockdrumlevel);
        delay1(speed*4);
        kill_note(rockdrumchannel,DS2,rockdrumlevel);

        play_note(rockdrumchannel,DS2,rockdrumlevel);
        delay1(speed*4);
        kill_note(rockdrumchannel,DS2,rockdrumlevel);

        play_note(rockdrumchannel,DS2,rockdrumlevel);
        delay1(speed*4);
        kill_note(rockdrumchannel,DS2,rockdrumlevel);

        play_note(rockdrumchannel,DS2,rockdrumlevel);
        delay1(speed*4);
        kill_note(rockdrumchannel,DS2,rockdrumlevel);

          level2();
          all_lights_off(0);
          change_light_level(3,127);
       }

      if (key_table[INDEX_F1])
       {
        change_program(leadchannel,90,0);
        leadlevel = 99;
        change_volume(1,99);

        clrscr();
        cout << "Level 1!";
        mix_name("Four  ");
        mix_mode();
        cout << "\n1 ";
        delay(speed);
        delay(speed);
        delay(speed);
        delay(speed);


        cout << "\nMeasure 1";
        play1();
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        delay1(speed);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(rockdrumchannel,C1,rockdrumlevel);

        play_note(rockdrumchannel,FS1,rockdrumlevel);
        delay1(speed);
        kill1();
        kill_note(rockdrumchannel,FS1,rockdrumlevel);

        play_note(rockdrumchannel,AS1,rockdrumlevel);
        play1();
        delay1(speed);
        kill1();
        play1();

        delay1(speed);
        kill1();
        kill_note(rockdrumchannel,AS1,rockdrumlevel);

        for (int ii = 0; ii < 3; ii++)
         {
        play1();
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        delay1(speed);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(rockdrumchannel,C1,rockdrumlevel);
        kill_note(rockdrumchannel,GS1,rockdrumlevel);

        if (ii == 2)
         {
          kill1();
          play1();
         }

        play_note(rockdrumchannel,FS1,rockdrumlevel);
        delay1(speed);
        kill1();
        kill_note(rockdrumchannel,FS1,rockdrumlevel);

        play_note(rockdrumchannel,AS1,rockdrumlevel);
        play1();
        delay1(speed);
        kill1();
        play1();
        delay1(speed);
        kill1();
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
       }
       

        cout << "\nMeasure 2";
        for (ii = 0; ii < 4; ii++)
         {

        play2();
        play_note(rockdrumchannel,GS1,rockdrumlevel);
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        delay1(speed);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(rockdrumchannel,C1,rockdrumlevel);
        kill_note(rockdrumchannel,GS1,rockdrumlevel);

        if (ii == 3)
         {
          kill2();
          play2();
         }


        play_note(rockdrumchannel,FS1,rockdrumlevel);
        delay1(speed);
        kill2();
        kill_note(rockdrumchannel,FS1,rockdrumlevel);

        play_note(rockdrumchannel,AS1,rockdrumlevel);
        play2();
        delay1(speed);
        kill2();
        play2();
        delay1(speed);
        kill2();
        kill_note(rockdrumchannel,AS1,rockdrumlevel);

         }

       cout << "\nMeasure 3";
       kill_note(bellchannel,F1,belllevel);
       for (ii = 0; ii < 4; ii++)
       {
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        play3();
        delay1(speed);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(rockdrumchannel,C1,rockdrumlevel);

        if (ii == 3)
         {
          kill3();
          play3();
         }

        play_note(rockdrumchannel,FS1,rockdrumlevel);
        delay1(speed);
        kill3();
        kill_note(rockdrumchannel,FS1,rockdrumlevel);

        play_note(rockdrumchannel,AS1,rockdrumlevel);
        play3(); 
        delay1(speed);
        kill3();
        play3();
        delay1(speed);
        kill3();
        kill_note(rockdrumchannel,AS1,rockdrumlevel);
       }

       cout << "\nMeasure 4";
       for (ii = 0; ii < 3; ii++)
       {
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play_note(rockdrumchannel,C1,rockdrumlevel);
        play3();
        delay1(speed);
        kill3();
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill_note(rockdrumchannel,C1,rockdrumlevel);

        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play3();
        delay1(speed);
        kill3();
        kill_note(rockdrumchannel,FS1,rockdrumlevel);

        play_note(rockdrumchannel,E1,rockdrumlevel);
        play3();
        delay1(speed);
        kill3();
        kill_note(rockdrumchannel,E1,rockdrumlevel);

        play_note(rockdrumchannel,FS1,rockdrumlevel);
        play3();
        delay1(speed);
        kill3();
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
       }

        play_note(rockdrumchannel,C1,rockdrumlevel);
        play_note(rockdrumchannel,E1,rockdrumlevel);
        play3();
        delay1(speed);
        kill3();
        kill_note(rockdrumchannel,C1,rockdrumlevel);
        kill_note(rockdrumchannel,E1,rockdrumlevel);

        play3();
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        delay1(speed);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill3();

        play3();
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        delay1(speed);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill3();

        play3();
        play_note(rockdrumchannel,FS1,rockdrumlevel);
        delay1(speed);
        kill_note(rockdrumchannel,FS1,rockdrumlevel);
        kill3();


        level1();
        showtitle();
       }
   }

   Exit_MIDI();
   kill_keyboard();
}
                                      
