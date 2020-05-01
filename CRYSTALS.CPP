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

#define leadchannel 5
#define leadlevel 100
#define stringchordlevel 50
#define stringchordchannel 2
#define stringleadlevel 50
#define stringleadchannel 3
#define choirlevel 70
#define choirchannel 4

int leadnotes [17][6];
int leadpart = 0;

void docrystalstuff()
{
        if ((notes[INDEX_UP] == 0) && (key_table[INDEX_UP]==1))
        {   
          kill_note(leadchannel,leadnotes[0][leadpart],leadlevel);                   
          notes[INDEX_UP]=1;
          leadpart++;
          cout << leadpart << endl;
        }
        if ((notes[INDEX_UP] == 1) && (key_table[INDEX_UP]==0))   
        {   
          notes[INDEX_UP]=0;   
        }

        if ((notes[INDEX_LEFT] == 0) && (key_table[INDEX_LEFT]==1))
        {   
          kill_note(leadchannel,leadnotes[0][leadpart],leadlevel);                   
          notes[INDEX_LEFT]=1;
          leadpart = 0;
          cout << leadpart << endl;
        }
        if ((notes[INDEX_LEFT] == 1) && (key_table[INDEX_LEFT]==0))   
        {   
          notes[INDEX_LEFT]=0;
        }

        if ((notes[INDEX_DOWN] == 0) && (key_table[INDEX_DOWN]==1))
        {   
          kill_note(leadchannel,leadnotes[0][leadpart],leadlevel);                   
          notes[INDEX_DOWN]=1;
          leadpart--;
          cout << leadpart << endl;
        }
        if ((notes[INDEX_DOWN] == 1) && (key_table[INDEX_DOWN]==0))   
        {   
          notes[INDEX_DOWN]=0;   
        }

        if ((notes[INDEX_11] == 0) && (key_table[INDEX_11]==1))
        {   
          notes[INDEX_11]=1;
          play_note(leadchannel,leadnotes[0][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_11] == 1) && (key_table[INDEX_11]==0))   
        {   
          kill_note(leadchannel,leadnotes[0][leadpart],leadlevel);                   
          notes[INDEX_11]=0;   
        }

        if ((notes[INDEX_21] == 0) && (key_table[INDEX_21]==1))
        {   
          notes[INDEX_21]=1;
          play_note(leadchannel,leadnotes[1][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_21] == 1) && (key_table[INDEX_21]==0))   
        {   
          kill_note(leadchannel,leadnotes[1][leadpart],leadlevel);                   
          notes[INDEX_21]=0;   
        }   

        if ((notes[INDEX_31] == 0) && (key_table[INDEX_31]==1))
        {   
          notes[INDEX_31]=1;
          play_note(leadchannel,leadnotes[2][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_31] == 1) && (key_table[INDEX_31]==0))   
        {   
          kill_note(leadchannel,leadnotes[2][leadpart],leadlevel);                   
          notes[INDEX_31]=0;   
        }   

        if ((notes[INDEX_41] == 0) && (key_table[INDEX_41]==1))
        {   
          notes[INDEX_41]=1;
          play_note(leadchannel,leadnotes[3][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_41] == 1) && (key_table[INDEX_41]==0))   
        {   
          kill_note(leadchannel,leadnotes[3][leadpart],leadlevel);                   
          notes[INDEX_41]=0;   
        }   

        if ((notes[INDEX_Q] == 0) && (key_table[INDEX_Q]==1))
        {   
          notes[INDEX_Q]=1;
          play_note(leadchannel,leadnotes[4][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_Q] == 1) && (key_table[INDEX_Q]==0))   
        {   
          kill_note(leadchannel,leadnotes[4][leadpart],leadlevel);                   
          notes[INDEX_Q]=0;   
        }   

        if ((notes[INDEX_W] == 0) && (key_table[INDEX_W]==1))
        {   
          notes[INDEX_W]=1;
          play_note(leadchannel,leadnotes[5][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_W] == 1) && (key_table[INDEX_W]==0))   
        {   
          kill_note(leadchannel,leadnotes[5][leadpart],leadlevel);                   
          notes[INDEX_W]=0;   
        }   

        if ((notes[INDEX_E] == 0) && (key_table[INDEX_E]==1))
        {   
          notes[INDEX_E]=1;
          play_note(leadchannel,leadnotes[6][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_E] == 1) && (key_table[INDEX_E]==0))   
        {   
          kill_note(leadchannel,leadnotes[6][leadpart],leadlevel);                   
          notes[INDEX_E]=0;   
        }   

        if ((notes[INDEX_R] == 0) && (key_table[INDEX_R]==1))
        {   
          notes[INDEX_R]=1;
          play_note(leadchannel,leadnotes[7][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_R] == 1) && (key_table[INDEX_R]==0))   
        {   
          kill_note(leadchannel,leadnotes[7][leadpart],leadlevel);                   
          notes[INDEX_R]=0;   
        }   

        if ((notes[INDEX_A] == 0) && (key_table[INDEX_A]==1))
        {   
          notes[INDEX_A]=1;
          play_note(leadchannel,leadnotes[8][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_A] == 1) && (key_table[INDEX_A]==0))   
        {   
          kill_note(leadchannel,leadnotes[8][leadpart],leadlevel);                   
          notes[INDEX_A]=0;   
        }   

        if ((notes[INDEX_S] == 0) && (key_table[INDEX_S]==1))
        {   
          notes[INDEX_S]=1;
          play_note(leadchannel,leadnotes[9][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_S] == 1) && (key_table[INDEX_S]==0))   
        {   
          kill_note(leadchannel,leadnotes[9][leadpart],leadlevel);                   
          notes[INDEX_S]=0;   
        }   

        if ((notes[INDEX_D] == 0) && (key_table[INDEX_D]==1))
        {   
          notes[INDEX_D]=1;
          play_note(leadchannel,leadnotes[10][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_D] == 1) && (key_table[INDEX_D]==0))   
        {   
          kill_note(leadchannel,leadnotes[10][leadpart],leadlevel);                   
          notes[INDEX_D]=0;   
        }   

        if ((notes[INDEX_F] == 0) && (key_table[INDEX_F]==1))
        {   
          notes[INDEX_F]=1;
          play_note(leadchannel,leadnotes[11][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_F] == 1) && (key_table[INDEX_F]==0))   
        {   
          kill_note(leadchannel,leadnotes[11][leadpart],leadlevel);                   
          notes[INDEX_F]=0;   
        }   

        if ((notes[INDEX_Z] == 0) && (key_table[INDEX_Z]==1))
        {   
          notes[INDEX_Z]=1;
          play_note(leadchannel,leadnotes[12][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_Z] == 1) && (key_table[INDEX_Z]==0))   
        {   
          kill_note(leadchannel,leadnotes[12][leadpart],leadlevel);                   
          notes[INDEX_Z]=0;   
        }   

        if ((notes[INDEX_X] == 0) && (key_table[INDEX_X]==1))
        {   
          notes[INDEX_X]=1;
          play_note(leadchannel,leadnotes[13][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_X] == 1) && (key_table[INDEX_X]==0))   
        {   
          kill_note(leadchannel,leadnotes[13][leadpart],leadlevel);                   
          notes[INDEX_X]=0;   
        }   

       if ((notes[INDEX_C] == 0) && (key_table[INDEX_C]==1))
        {   
          notes[INDEX_C]=1;
          play_note(leadchannel,leadnotes[14][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_C] == 1) && (key_table[INDEX_C]==0))   
        {   
          kill_note(leadchannel,leadnotes[14][leadpart],leadlevel);                   
          notes[INDEX_C]=0;   
        }   

       if ((notes[INDEX_V] == 0) && (key_table[INDEX_V]==1))
        {   
          notes[INDEX_V]=1;
          play_note(leadchannel,leadnotes[15][leadpart],leadlevel);                   
        }   
        if ((notes[INDEX_V] == 1) && (key_table[INDEX_V]==0))   
        {   
          kill_note(leadchannel,leadnotes[15][leadpart],leadlevel);                   
          notes[INDEX_V]=0;   
        }   

    if ((notes[INDEX_SPACE] == 0) && (key_table[INDEX_SPACE]==1))
        {   
          notes[INDEX_SPACE]=1;
          play_note(leadchannel,leadnotes[16][leadpart],leadlevel);                   
        }
        if ((notes[INDEX_SPACE] == 1) && (key_table[INDEX_SPACE]==0))   
        {   
          kill_note(leadchannel,leadnotes[16][leadpart],leadlevel);                   
          notes[INDEX_SPACE]=0;
        }   


        if ((notes[INDEX_U] == 0) && (key_table[INDEX_U]==1))
        {   
          notes[INDEX_U]=1;

          kill_note(leadchannel,leadnotes[0][leadpart],leadlevel);                   
          leadpart = 0;
          cout << leadpart << " ";


          kill_note(stringchordchannel,C6,stringchordlevel);
          kill_note(stringchordchannel,C5,stringchordlevel);
          kill_note(stringchordchannel,A4,stringchordlevel);
          kill_note(stringchordchannel,E4,stringchordlevel);
          kill_note(stringchordchannel,A2,stringchordlevel);  
          kill_note(choirchannel, C5, choirlevel);

          kill_note(stringchordchannel,D6,stringchordlevel);
          kill_note(stringchordchannel,F5,stringchordlevel);
          kill_note(stringchordchannel,D5,stringchordlevel);
          kill_note(stringchordchannel,AS4,stringchordlevel);
          kill_note(stringchordchannel,AS2,stringchordlevel);  
          kill_note(choirchannel, D5, choirlevel);

          play_note(stringleadchannel,C6,stringleadlevel);
          play_note(stringchordchannel,G4,stringchordlevel);
          play_note(stringchordchannel,C3,stringchordlevel);                   
          play_note(stringchordchannel,C5,stringchordlevel);                   
          play_note(stringchordchannel,E5,stringchordlevel);                   
          play_note(choirchannel,C5,choirlevel);

        }
        if ((notes[INDEX_U] == 1) && (key_table[INDEX_U]==0))   
        {   


/*          kill_note(stringleadchannel,C6,stringleadlevel);
          kill_note(stringchordchannel,G4,stringchordlevel);
          kill_note(stringchordchannel,C3,stringchordlevel);                   
          kill_note(stringchordchannel,C5,stringchordlevel);                   
          kill_note(stringchordchannel,E5,stringchordlevel);                   
          kill_note(choirchannel,C5,choirlevel); */

          notes[INDEX_U]=0;   
        }

        if ((notes[INDEX_I] == 0) && (key_table[INDEX_I]==1))
        {   
          notes[INDEX_I]=1;
          play_note(stringleadchannel,B5,stringleadlevel);                   
          play_note(choirchannel,B4,choirlevel);

        }

        if ((notes[INDEX_I] == 1) && (key_table[INDEX_I]==0))
        {   
          kill_note(stringleadchannel,B5,stringleadlevel);                   
          kill_note(choirchannel,B4,choirlevel);

          notes[INDEX_I]=0;   
        }

        if ((notes[INDEX_O] == 0) && (key_table[INDEX_O]==1))
        {   
          notes[INDEX_O]=1;

          play_note(stringleadchannel,D6,stringleadlevel);                   
          play_note(choirchannel,D5,choirlevel);

        }
        if ((notes[INDEX_O] == 1) && (key_table[INDEX_O]==0))   
        {   
          kill_note(stringleadchannel,D6,stringleadlevel);                   
          kill_note(choirchannel,D5,choirlevel);

          notes[INDEX_O]=0;   
        }

        if ((notes[INDEX_71] == 0) && (key_table[INDEX_71]==1))
        {   
          notes[INDEX_71]=1;

          leadpart++;
          cout << leadpart << " ";
          kill_note(stringleadchannel,C6,stringleadlevel);
          kill_note(stringchordchannel,G4,stringchordlevel);
          kill_note(stringchordchannel,C3,stringchordlevel);                   
          kill_note(stringchordchannel,C5,stringchordlevel);                   
          kill_note(stringchordchannel,E5,stringchordlevel);                   
          kill_note(choirchannel,C5,choirlevel); 

          play_note(stringchordchannel,C6,stringchordlevel);
          play_note(stringchordchannel,C5,stringchordlevel);
          play_note(stringchordchannel,A4,stringchordlevel);
          play_note(stringchordchannel,E4,stringchordlevel);
          play_note(stringchordchannel,A2,stringchordlevel);  
          play_note(choirchannel, C5, choirlevel);
        }
        if ((notes[INDEX_71] == 1) && (key_table[INDEX_71]==0))   
        {   

          notes[INDEX_71]=0;   
        }

        if ((notes[INDEX_P] == 0) && (key_table[INDEX_P]==1))
        {   
          notes[INDEX_P]=1;

          play_note(stringchordchannel,C6,stringchordlevel);                   
          play_note(choirchannel,C5,choirlevel);

        }
        if ((notes[INDEX_P] == 1) && (key_table[INDEX_P]==0))   
        {   
          kill_note(stringchordchannel,C6,stringchordlevel);                   
          kill_note(choirchannel,C5,choirlevel);

          notes[INDEX_P]=0;   
        }


        if ((notes[INDEX_81] == 0) && (key_table[INDEX_81]==1))
        {                 
          notes[INDEX_81]=1;
          leadpart++;
          cout << leadpart << " ";

          kill_note(stringchordchannel,C6,stringchordlevel);
          kill_note(stringchordchannel,C5,stringchordlevel);
          kill_note(stringchordchannel,A4,stringchordlevel);
          kill_note(stringchordchannel,E4,stringchordlevel);
          kill_note(stringchordchannel,A2,stringchordlevel);  
          kill_note(choirchannel, C5, choirlevel);

          play_note(stringchordchannel,A5,stringchordlevel);
          play_note(stringchordchannel,A4,stringchordlevel);
          play_note(stringchordchannel,F4,stringchordlevel);
          play_note(stringchordchannel,C4,stringchordlevel);
          play_note(stringchordchannel,F2,stringchordlevel);  
          play_note(choirchannel, A4, choirlevel);


        }
        if ((notes[INDEX_81] == 1) && (key_table[INDEX_81]==0))   
        {   

          notes[INDEX_81]=0;   
        }

        if ((notes[INDEX_91] == 0) && (key_table[INDEX_91]==1))
        {                 
          notes[INDEX_91]=1;

          leadpart++;
          cout << leadpart << " ";

          play_note(stringchordchannel,B5,stringchordlevel);
          play_note(stringchordchannel,D5,stringchordlevel);
          play_note(stringchordchannel,B4,stringchordlevel);
          play_note(stringchordchannel,G4,stringchordlevel);
          play_note(stringchordchannel,G2,stringchordlevel);  
          play_note(choirchannel, B4, choirlevel);

          kill_note(stringchordchannel,A5,stringchordlevel);
          kill_note(stringchordchannel,A4,stringchordlevel);
          kill_note(stringchordchannel,F4,stringchordlevel);
          kill_note(stringchordchannel,C4,stringchordlevel);
          kill_note(stringchordchannel,F2,stringchordlevel);  
          kill_note(choirchannel, A4, choirlevel);
        }

        if ((notes[INDEX_91] == 1) && (key_table[INDEX_91]==0))
        {   

          notes[INDEX_91]=0;   
        }



        if ((notes[INDEX_01] == 0) && (key_table[INDEX_01]==1))
        {                 
          notes[INDEX_01]=1;

          leadpart++;
          cout << leadpart << " ";

          kill_note(stringchordchannel,B5,stringchordlevel);
          kill_note(stringchordchannel,D5,stringchordlevel);
          kill_note(stringchordchannel,B4,stringchordlevel);
          kill_note(stringchordchannel,G4,stringchordlevel);
          kill_note(stringchordchannel,G2,stringchordlevel);  
          kill_note(choirchannel, B4, choirlevel);

          play_note(stringchordchannel,A5,stringchordlevel);
          play_note(stringchordchannel,A4,stringchordlevel);
          play_note(stringchordchannel,F4,stringchordlevel);
          play_note(stringchordchannel,C4,stringchordlevel);
          play_note(stringchordchannel,F2,stringchordlevel);  
          play_note(choirchannel, A4, choirlevel);
        }

        if ((notes[INDEX_01] == 1) && (key_table[INDEX_01]==0))
        {   

          notes[INDEX_01]=0;   
        }

        if ((notes[INDEX_F9] == 0) && (key_table[INDEX_F9]==1))
        {                 
          notes[INDEX_F9]=1;

          leadpart++;
          cout << leadpart << " ";
          play_note(stringchordchannel,C6,stringchordlevel);
          play_note(stringchordchannel,DS5,stringchordlevel);
          play_note(stringchordchannel,C5,stringchordlevel);
          play_note(stringchordchannel,GS4,stringchordlevel);
          play_note(stringchordchannel,GS2,stringchordlevel);  
          play_note(choirchannel, C5, choirlevel);

          kill_note(stringchordchannel,B5,stringchordlevel);
          kill_note(stringchordchannel,D5,stringchordlevel);
          kill_note(stringchordchannel,B4,stringchordlevel);
          kill_note(stringchordchannel,G4,stringchordlevel);
          kill_note(stringchordchannel,G2,stringchordlevel);  
          kill_note(choirchannel, B4, choirlevel);


        }

        if ((notes[INDEX_F9] == 1) && (key_table[INDEX_F9]==0))
        {   


          notes[INDEX_F9]=0;
        }


        if ((notes[INDEX_F10] == 0) && (key_table[INDEX_F10]==1))
        {                 
          notes[INDEX_F10]=1;

          leadpart++;
          cout << leadpart << " ";

          play_note(stringchordchannel,D6,stringchordlevel);
          play_note(stringchordchannel,F5,stringchordlevel);
          play_note(stringchordchannel,D5,stringchordlevel);
          play_note(stringchordchannel,AS4,stringchordlevel);
          play_note(stringchordchannel,AS2,stringchordlevel);  
          play_note(choirchannel, D5, choirlevel);

          kill_note(stringchordchannel,C6,stringchordlevel);
          kill_note(stringchordchannel,DS5,stringchordlevel);
          kill_note(stringchordchannel,C5,stringchordlevel);
          kill_note(stringchordchannel,GS4,stringchordlevel);
          kill_note(stringchordchannel,GS2,stringchordlevel);  
          kill_note(choirchannel, C5, choirlevel);

        }

        if ((notes[INDEX_F10] == 1) && (key_table[INDEX_F10]==0))

        {

          notes[INDEX_F10]=0;   
        }





}

int delaycrystals(int speed)
{

   for (int index=0;index<speed;index++)
   {
      if (key_table[INDEX_ESC]) return 1;
         docrystalstuff();
      delay (1);
   }
   return 0;
}

void showtitle()
{
   clrscr();
   cout << "FF Crystals Theme";
}

void main()
{
   GetBlastInfo(&blastInfo);
   MIDIType = SBMIDI;
   DSPReset();
   Init_MIDI();   

   install_keyboard();

   leadnotes[0][0] = C3;
   leadnotes[1][0] = D3;
   leadnotes[2][0] = E3;
   leadnotes[3][0] = G3;
   leadnotes[4][0] = C4;
   leadnotes[5][0] = D4;
   leadnotes[6][0] = E4;
   leadnotes[7][0] = G4;
   leadnotes[8][0] = C5;
   leadnotes[9][0] = D5;
   leadnotes[10][0] = E5;
   leadnotes[11][0] = G5;
   leadnotes[12][0] = C6;
   leadnotes[13][0] = D6;
   leadnotes[14][0] = E6;
   leadnotes[15][0] = G6;
   leadnotes[16][0] = G6;

   leadnotes[0][1] = A2;
   leadnotes[1][1] = B2;
   leadnotes[2][1] = C3;
   leadnotes[3][1] = E3;
   leadnotes[4][1] = A3;
   leadnotes[5][1] = B3;
   leadnotes[6][1] = C4;
   leadnotes[7][1] = E4;
   leadnotes[8][1] = A4;
   leadnotes[9][1] = B4;
   leadnotes[10][1] = C5;
   leadnotes[11][1] = E5;
   leadnotes[12][1] = A5;
   leadnotes[13][1] = B5;
   leadnotes[14][1] = C6;
   leadnotes[15][1] = E6;
   leadnotes[16][1] = A6;
                  
   leadnotes[0][2] = A2;
   leadnotes[1][2] = C3;
   leadnotes[2][2] = F3;
   leadnotes[3][2] = G3;
   leadnotes[4][2] = A3;
   leadnotes[5][2] = C4;
   leadnotes[6][2] = F4;
   leadnotes[7][2] = G4;
   leadnotes[8][2] = A4;
   leadnotes[9][2] = C5;
   leadnotes[10][2] = F5;
   leadnotes[11][2] = G5;
   leadnotes[12][2] = A5;
   leadnotes[13][2] = C6;
   leadnotes[14][2] = F6;
   leadnotes[15][2] = G6;
   leadnotes[16][2] = A6;

   leadnotes[0][3] = B2;
   leadnotes[1][3] = D3;
   leadnotes[2][3] = G3;
   leadnotes[3][3] = A3;
   leadnotes[4][3] = B3;
   leadnotes[5][3] = D4;
   leadnotes[6][3] = G4;
   leadnotes[7][3] = A4;
   leadnotes[8][3] = B4;
   leadnotes[9][3] = D5;
   leadnotes[10][3] = G5;
   leadnotes[11][3] = A5;
   leadnotes[12][3] = B5;
   leadnotes[13][3] = D6;
   leadnotes[14][3] = G6;
   leadnotes[15][3] = A6;
   leadnotes[16][3] = A6;

   leadnotes[0][4] = GS2;
   leadnotes[1][4] = C3;
   leadnotes[2][4] = DS3;
   leadnotes[3][4] = G3;
   leadnotes[4][4] = GS3;
   leadnotes[5][4] = C4;
   leadnotes[6][4] = DS4;
   leadnotes[7][4] = G4;
   leadnotes[8][4] = GS4;
   leadnotes[9][4] = C5;
   leadnotes[10][4] = DS5;
   leadnotes[11][4] = G5;
   leadnotes[12][4] = GS5;
   leadnotes[13][4] = C6;
   leadnotes[14][4] = DS6;
   leadnotes[15][4] = G6;
   leadnotes[16][4] = GS6;

   leadnotes[0][5] = AS2;
   leadnotes[1][5] = D3;
   leadnotes[2][5] = F3;
   leadnotes[3][5] = A3;
   leadnotes[4][5] = AS3;
   leadnotes[5][5] = D4;
   leadnotes[6][5] = F4;
   leadnotes[7][5] = A4;
   leadnotes[8][5] = AS4;
   leadnotes[9][5] = D5;
   leadnotes[10][5] = F5;
   leadnotes[11][5] = A5;
   leadnotes[12][5] = AS5;
   leadnotes[13][5] = D6;
   leadnotes[14][5] = F6;
   leadnotes[15][5] = A6;
   leadnotes[16][5] = AS6;

   mix_mode();
    change_program(leadchannel,98,3);
    change_program(stringchordchannel, 53, 3);
    change_program(stringleadchannel, 53, 3);      
    change_program(choirchannel, 52, 4);
    change_volume(leadchannel,leadlevel);
    change_volume(1,85);

   change_program(1,81,1);
   mix_name("Crystals ");
   mix_mode();
   showtitle();

   for (int index=0;index<127;index++)
      notes[index] = 0;   

   change_light_level(1,50);
   change_light_level(3,127);
   while (1)
   {
      if (delaycrystals(1)) break;
      do_fade_stuff();
   }

   docrystalstuff();

   Exit_MIDI();
   kill_keyboard();
}
                                      

