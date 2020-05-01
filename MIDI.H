#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream.h>

//Octave||                     Note Numbers
//   #  ||
//      || C   | C#  | D   | D#  | E   | F   | F#  | G   | G#  | A   | A#  | B
//-----------------------------------------------------------------------------
//  -2  ||   0 |   1 |   2 |   3 |   4 |   5 |   6 |   7 |   8 |   9 |  10 | 11
//  -1  ||  12 |  13 |  14 |  15 |  16 |  17 |  18 |  19 |  20 |  21 |  22 | 23
//   0  ||  24 |  25 |  26 |  27 |  28 |  29 |  30 |  31 |  32 |  33 |  34 | 35
//   1  ||  36 |  37 |  38 |  39 |  40 |  41 |  42 |  43 |  44 |  45 |  46 | 47
//   2  ||  48 |  49 |  50 |  51 |  52 |  53 |  54 |  55 |  56 |  57 |  58 | 59
//   3  ||  60 |  61 |  62 |  63 |  64 |  65 |  66 |  67 |  68 |  69 |  70 | 71
//   4  ||  72 |  73 |  74 |  75 |  76 |  77 |  78 |  79 |  80 |  81 |  82 | 83
//   5  ||  84 |  85 |  86 |  87 |  88 |  89 |  90 |  91 |  92 |  93 |  94 | 95
//   6  ||  96 |  97 |  98 |  99 | 100 | 101 | 102 | 103 | 104 | 105 | 106 | 107
//   7  || 108 | 109 | 110 | 111 | 112 | 113 | 114 | 115 | 116 | 117 | 118 | 119
//   8  || 120 | 121 | 122 | 123 | 124 | 125 | 126 | 127 |

#define C0  24
#define CS0 25
#define D0  26
#define DS0 27
#define E0  28
#define F0  29
#define FS0 30
#define G0  31
#define GS0 32
#define A0  33
#define AS0 34
#define B0  35
#define C1  36
#define CS1 37
#define D1  38
#define DS1 39
#define E1  40
#define F1  41
#define FS1 42
#define G1  43
#define GS1 44
#define A1  45
#define AS1 46
#define B1  47

#define C2  48
#define CS2 49
#define D2  50
#define DS2 51
#define E2  52
#define F2  53
#define FS2 54
#define G2  55
#define GS2 56
#define A2  57
#define AS2 58
#define B2  59

#define C3  60
#define CS3 61
#define D3  62
#define DS3 63
#define E3  64
#define F3  65
#define FS3 66
#define G3  67
#define GS3 68
#define A3  69
#define AS3 70
#define B3  71

#define C4  72
#define CS4 73
#define D4  74
#define DS4 75
#define E4  76
#define F4  77
#define FS4 78
#define G4  79
#define GS4 80
#define A4  81
#define AS4 82
#define B4  83

#define C5  84
#define CS5 85
#define D5  86
#define DS5 87
#define E5  88
#define F5  89
#define FS5 90
#define G5  91
#define GS5 92
#define A5  93
#define AS5 94
#define B5  95

#define C6  96
#define CS6 97
#define D6  98
#define DS6 99
#define E6  100
#define F6  101
#define FS6 102
#define G6  103
#define GS6 104
#define A6  105
#define AS6 106
#define B6  107
#define C7  108






#define SBMIDI          0
#define MPU401          1
#define MPU401_RESET    0xff
#define MPU401_UART     0x3f
#define MPU401_CMDOK    0xfe
#define MPU401_OK2WR    0x40
#define MPU401_OK2RD    0x80
#define MIDI_IN_P       0x30              // MIDI read (polling mode)
#define MIDI_IN_I       0x31              // MIDI read (interrupt mode)
#define MIDI_UART_P     0x34              // MIDI UART mode (polling mode)
#define MIDI_UART_I     0x35              // MIDI UART mode (interrupt mode)
#define MIDI_UART_TS_P  0x36              // same as 0x34 with timestamp
#define MIDI_UART_TS_I  0x37              // same as 0x35 with timestamp
#define MIDI_OUT_P      0x38              // MIDI write (polling mode)
#define ERROR           -1
#define OK              0
#define ON              1
#define OFF             0
extern int MIDIType;
void Write_MPU401_Cmd(unsigned char command);
void Write_MPU401_Data(unsigned char data);
void Write_SBMIDI_Data(unsigned char data);
unsigned char Read_MPU401_Data(void);
unsigned char Read_SBMIDI_Data(void);
void Send_MIDI_Message(char far *message, int size);
void Set_MIDI_Vol(char channel, char volume);
void Set_MIDI_Notes_Off(char channel);
void Set_MIDI_Pitch_Bend(char channel, int range);
int Reset_MPU401(void);
int Set_UART_Mode(int state);
int Detect_MIDI(void);
int Init_MIDI(void);
void Exit_MIDI(void);
#define ERROR       -1
#define OK           0
#define ON           1
#define OFF          0
#define MSB          0x80
#define SBC          1                    // Card types
#define SBMCV        1
#define SBPRO        2
#define SB20         3
#define SBPRO2       4
#define SBMCVPRO     5
#define SB16         6
#define DSP_RST      0x06                 // DSP reset port
#define DSP_RD_ST    0x0e                 // DSP read buffer status port
#define DSP_RD       0x0a                 // DSP read port
#define DSP_WR_ST    0x0c                 // DSP write buffer status port
#define DSP_WR       0x0c                 // DSP write port
#define DSP_RST_OK   0xaa                 // DSP reset OK
typedef struct                             // BLASTER environment record
{
  int baseAddr;
  unsigned char DSPint;
  unsigned char DMA8;
  unsigned char model;
  unsigned char DMA16;
  int midiPort;
} BLASTREC;
int GetBlastInfo(BLASTREC *blastInfo);
int DSPReset(void);

extern BLASTREC blastInfo; 

int MIDIType = MPU401;                    // MIDI type to use flag

/************************************************************************
 * WRITE_MPU401_CMD: sends a command to the MPU401 port.
 *
 * Input: command - command byte
 *
 * Output: none
 ************************************************************************/
void Write_MPU401_Cmd(unsigned char command)
{
  // check write status
  while((inp(blastInfo.midiPort + 1) & MPU401_OK2WR));

  outp(blastInfo.midiPort + 1, command);
}

/************************************************************************
 * WRITE_MPU401_DATA: sends a data byte to the MPU401 port.
 *
 * Input: data - data byte
 *
 * Output: none
 ************************************************************************/
void Write_MPU401_Data(unsigned char data)
{
  // check write status
  while((inp(blastInfo.midiPort + 1) & MPU401_OK2WR));

  outp(blastInfo.midiPort, data);
}

/************************************************************************
 * WRITE_SBMIDI_DATA: sends a byte to the Sound Blaster MIDI port.
 *
 * Input: data - data byte
 *
 * Output: none
 ************************************************************************/
void Write_SBMIDI_Data(unsigned char data)
{
  // wait for write buffer ready
  while(inp(blastInfo.baseAddr + DSP_WR_ST) & MSB);
  // send MIDI write command
  outp(blastInfo.baseAddr + DSP_WR, MIDI_OUT_P);

  // wait for write buffer ready
  while(inp(blastInfo.baseAddr + DSP_WR_ST) & MSB);
  // send MIDI data byte
  outp(blastInfo.baseAddr + DSP_WR, data);
}

/************************************************************************
 * READ_MPU401_DATA: reads a byte from the MPU401 port.
 *
 * Input: none
 *
 * Output: data byte
 ************************************************************************/
unsigned char Read_MPU401_Data(void)
{
  // check read status
  while((inp(blastInfo.midiPort + 1) & MPU401_OK2RD));

  return(inp(blastInfo.midiPort));
}

/************************************************************************
 * READ_SBMIDI_DATA: reads a byte from the Sound Blaster MIDI port.
 *
 * Input: none
 *
 * Output: data - data byte
 ************************************************************************/
unsigned char Read_SBMIDI_Data(void)
{
  unsigned char data;

  // wait for write buffer ready
  while(inp(blastInfo.baseAddr + DSP_WR_ST) & MSB);
  // send MIDI read command
  outp(blastInfo.baseAddr + DSP_WR, MIDI_IN_P);
  // wait for read buffer ready
  while(!(inp(blastInfo.baseAddr + DSP_RD_ST) & MSB));
  // read MIDI data byte
  data = inp(blastInfo.baseAddr + DSP_RD);
  // wait for write buffer ready
  while(inp(blastInfo.baseAddr + DSP_WR_ST) & MSB);
  // stop MIDI read
  outp(blastInfo.baseAddr + DSP_WR, MIDI_IN_P);
  return(data);
}

/************************************************************************
 * SEND_MIDI_MESSAGE: Sends a MIDI message to port
 *
 * Input: message - MIDI message to send
 *        size - length of message
 *
 * Output: none
 ************************************************************************/
void Send_MIDI_Message(char far *message, int size)
{
  int i;

  if(MIDIType == MPU401)
    for(i = 0; i < size; i++)
      Write_MPU401_Data(message[i]);
  else
    for(i = 0; i < size; i++)
      Write_SBMIDI_Data(message[i]);
}

/************************************************************************
 * SET_MIDI_VOL: Sets the global volume on the requested channel
 *
 * Input: channel - set volume on this channel (1 to 16)
 *        volume - set channel to this volume (0 to 127)
 *
 * Output: none
 *
 * note: if inputs are out of range then no action occurs
 ************************************************************************/
void Set_MIDI_Vol(char channel, char volume)
{
  char message[3];

  if((channel <= 16) && (channel > 0))
    if(volume >= 0)
    {
      message[0] = 0xb0 + channel - 1;    // set channel
      message[1] = 7;                     // set global volume command
      message[2] = volume;                // set volume level
      Send_MIDI_Message(message, 3);
    }
}

/************************************************************************
 * SET_MIDI_NOTES_OFF: Turns off all notes on the given channel
 *
 * Input: channel - turns off all notes on this channel (1 to 16)
 *
 * Output: none
 *
 * note: if channel is out of range then no action occurs
 ************************************************************************/
void Set_MIDI_Notes_Off(char channel)
{
  char message[3];

  if((channel <= 16) && (channel > 0))
  {
    message[0] = 0xb0 + channel - 1;      // set channel
    message[1] = 0x7b;                    // clear all notes command
    message[2] = 0;
    Send_MIDI_Message(message, 3);
  }
}

/************************************************************************
 * SET_MIDI_PITCH_BEND: Sets pitch bend (0 = OFF).
 *
 * Input: channel - sets pitch bend on this channel (1 to 16)
 *        bend - pitch bend value (-8192 to 8191)
 *
 * Output: none
 *
 * note: if inputs are out of range then no action occurs
 ************************************************************************/
void Set_MIDI_Pitch_Bend(char channel, int range)
{
  char message[3];

  if((channel <= 16) && (channel > 0))
    if((range >= -8192) && (range < 8192))
    {
      range += 8192;
      message[0] = 0xe0 + channel - 1;    // set channel
      message[1] = range >> 7;            // set pitch bend (MSB)
      message[2] = range & 0x7f;          // set pitch bend (LSB)
      Send_MIDI_Message(message, 3);
    }
}

/************************************************************************
 * RESET_MPU401: resets the MPU401 port.
 *
 * Input: none
 *
 * Output: result - (0 = OK, -1 = ERROR)
 *
 * note: Error will occur if UART mode is not turned off first.
 ************************************************************************/
int Reset_MPU401(void)
{
  int i = 100;

  Write_MPU401_Cmd(MPU401_RESET);         // send reset command
  while((i > 0) && (Read_MPU401_Data() != MPU401_CMDOK))
    i--;                                  // offer timeout instead of lockup

  if(i == 0)
    return(ERROR);
  else
    return(OK);
}

/************************************************************************
 * SET_UART_MODE: puts the MPU401 port in UART mode.
 *
 * Input: state - ON or OFF (Reset will return error if UART mode is on
 *                when reset occurs)
 *
 * Output: result - (0 = OK, -1 = ERROR)
 ************************************************************************/
int Set_UART_Mode(int state)
{
  int i = 100;

  if(state == ON)
  {
    Write_MPU401_Cmd(MPU401_UART);        // turn on UART mode
    while((i > 0) && (Read_MPU401_Data() != MPU401_CMDOK))
      i--;                                // offer timeout instead of lockup
  }
  else
    Write_MPU401_Cmd(MPU401_RESET);       // turn off UART mode

  if(i == 0)
    return(ERROR);
  else
    return(OK);
}

/************************************************************************
 * DETECT_MIDI: Detects the presence of the MPU-401 port or the SBMIDI
 *              port.
 *
 * Input: none
 *
 * Output: result - (0 = OK if found, -1 = ERROR if not found)
 ************************************************************************/
int Detect_MIDI(void)
{
  unsigned char status;
  int result = ERROR;

  if(MIDIType == MPU401)
  {
    // check write status
    status = inp(blastInfo.midiPort + 1);

    if(!(status & MPU401_OK2WR))
    {
      Set_UART_Mode(OFF);                 // just in case it was left on
      result = Reset_MPU401();            // does reset work?
    }
  }
  else
    result = DSPReset();                  // reset the DSP

  return(result);
}

/************************************************************************
 * INIT_MIDI: Initializes the MIDI port.  If MPU-401 port then reset
 *            the port and select UART mode.  For either MPU-401 or
 *            SBMIDI ports set all master volumes to 100, turn off all
 *            notes, and reset all pitch bends.
 *
 * Input: none
 *
 * Output: result - (0 = OK, -1 = ERROR)
 ************************************************************************/
int Init_MIDI(void)
{
  int i;

  if(MIDIType == MPU401)
  {
    if(Reset_MPU401() == ERROR)           // reset port
      return(ERROR);

    if(Set_UART_Mode(ON) == ERROR)        // set UART mode
      return(ERROR);
  }

  for(i = 1; i <= 16; i++)
  {
    Set_MIDI_Vol(i, 100);                 // set channel volume
    Set_MIDI_Notes_Off(i);                // turn off all notes
//***    Set_MIDI_Pitch_Bend(i, 0);            // reset pitch bends
  }
  return(OK);
}

/************************************************************************
 * EXIT_MIDI: Terminates MIDI driver by turning off all notes (and
 *            turning off UART mode if using MPU-401 port).
 *
 * Input: none
 *
 * Output: none
 ************************************************************************/
void Exit_MIDI(void)
{
  int i;

  for(i = 0; i < 16; i++)
    Set_MIDI_Notes_Off(i);                // turn off all notes

  if(MIDIType == MPU401)
    Set_UART_Mode(OFF);                   // exit UART mode
}

/* -------------------------------------------------------------------------- */
/* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY      */
/* KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE        */
/* IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR      */
/* PURPOSE.                                                                   */
/*                                                                            */
/* You have a royalty-free right to use, modify, reproduce and                */
/* distribute the Sample Files (and/or any modified version) in               */
/* any way you find useful, provided that you agree that                      */
/* Creative has no warranty obligations or liability for any Sample Files.    */
/*----------------------------------------------------------------------------*/


/* ---------------------------------------------------------------------------
  Program:  Sound Blaster Utilities
  Filename: SBCUTILS.C
  Author:   Scott E. Sindorf
  Language: Borland C
  Date:     30 Jun 93
  
  Copyright (c) 1993 Creative Labs, Inc.
-----------------------------------------------------------------------------*/
BLASTREC blastInfo;

/************************************************************************
 * GETBLASTINFO: Retreives BLASTER environment variable.
 *
 * Input: blastInfo - Structure which receives information.
 *
 * Output: result - ERROR if the variable is not found..
 *                  OK if it is found.
 ************************************************************************/

int GetBlastInfo(BLASTREC *blastInfo)
	{
    char *blastStr;
    char *tempStr;
    int result = OK,
        i;

    blastInfo->baseAddr = 0;                                // clear record
    blastInfo->DSPint = 0;
    blastInfo->DMA8 = 0;
    blastInfo->model = 0;
    blastInfo->DMA16 = 0;
    blastInfo->midiPort = 0;

	blastStr = getenv("BLASTER");

	if(blastStr)
		{
        tempStr = strtok(blastStr, " ");
        switch(toupper(tempStr[0]))
            {
            case 'A':
                blastInfo->baseAddr = strtol(tempStr + 1, NULL, 16);
                break;
            case 'I':
                blastInfo->DSPint = (unsigned char) atoi(tempStr + 1);
                break;
            case 'D':
                blastInfo->DMA8 = (unsigned char) atoi(tempStr + 1);
                break;
            case 'T':
                blastInfo->model = (unsigned char) atoi(tempStr + 1);
                break;
            case 'H':
                blastInfo->DMA16 = (unsigned char) atoi(tempStr + 1);
                break;
            case 'P':
                blastInfo->midiPort = strtol(tempStr + 1, NULL, 16);
                break;
            default:
                break;
            }

        for(i = 0; i < 5; i++)
            {
            tempStr = strtok(NULL, " ");
            switch(toupper(tempStr[0]))
                {
                case 'A':
                    blastInfo->baseAddr = strtol(tempStr + 1, NULL, 16);
                    break;
                case 'I':
                    blastInfo->DSPint = (unsigned char) atoi(tempStr + 1);
                    break;
                case 'D':
                    blastInfo->DMA8 = (unsigned char) atoi(tempStr + 1);
                    break;
                case 'T':
                    blastInfo->model = (unsigned char) atoi(tempStr + 1);
                    break;
                case 'H':
                    blastInfo->DMA16 = (unsigned char) atoi(tempStr + 1);
                    break;
                case 'P':
                    blastInfo->midiPort = strtol(tempStr + 1, NULL, 16);
                    break;
                default:
                    break;
                }
            }
		}
    else
        result = ERROR;

    return(result);
	}

/************************************************************************
 * DSPReset: Resets the DSP on the Sound Blaster card.
 *
 * Input:  none
 *
 * Output: OK (0) or ERROR (-1).
 *
 ************************************************************************/
int DSPReset(void)
{
  int result = ERROR,
      i,
      j;

  outp(blastInfo.baseAddr + DSP_RST, 1);
	for(i = 0; i < 100; i++); 									 // delay more than 3us
  outp(blastInfo.baseAddr + DSP_RST, 0);

  for(i = 0; (i < 32) && (result != DSP_RST_OK); i++)
  {
    for(j = 0; (j < 512) && (inp(blastInfo.baseAddr + DSP_RD_ST) < MSB);
      j++);
    if(j < 512)
      result = inp(blastInfo.baseAddr + DSP_RD);
  }
  if(result == DSP_RST_OK)
    result = OK;

  return(result);
}

unsigned char ready_to_read()
{
 return((blastInfo.baseAddr + DSP_WR_ST) & MSB);
}

char upcase(char ch)
{
 if ((ch >= 'a') && (ch <= 'z'))
	ch = ch - 32;
return(ch);
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

void change_mix(char channel, char prognum)
{
 channel--;
 char message[3];
 message[0] = 0xc1;
 message[0] += channel;
 message[1] = prognum;
 Send_MIDI_Message(message,2);
}

unsigned char play_note(char channel, unsigned char note, char velocity)
{
 if (note == 0) return 0;
 channel--;
 if ((channel >= 0) && (channel <= 15))
 {
  char message[3];
  message[0] = 0x90;
  message[0] += channel;
  message[1] = note;
  message[2] = velocity;
  Send_MIDI_Message(message,3);
 }
 return 1;
}

unsigned char kill_note(char channel, unsigned char note, char velocity)
{
 if (note == 0) return 0;
 channel--;
 if ((channel >= 0) && (channel <= 15))
 {
  char message[3];
  message[0] = 0x80;
  message[0] += channel;
  message[1] = note;
  message[2] = velocity;
  Send_MIDI_Message(message,3);
 }
 return 1;
}

void change_bank(char channel, char bank)
{
 char message[3];
 message[0] = 0xb0;
 message[0]+= channel;
 message[1] = 0;
 message[2] = bank;
 Send_MIDI_Message(message,3);
}

void change_program(char channel, char prognum, char bank)
{
 channel--;
 change_bank(channel,bank);
 char message[3];
 message[0] = 0xc0;
 message[0] += channel;
 message[1] = prognum;
 Send_MIDI_Message(message,2);
}

void change_volume(unsigned char channel, char newvolume)
{
   if (newvolume < 0)
      return;
   channel--;
   char message[12];
   message[0] = 0xF0;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x0E;
   message[4] = 0x0E;
   message[5] = 0x10; //?
   message[6] = 33;  //0mmfffff 
   message[7] = 0;   //0ssppppp
   message[8] = 0;   //0ccccddv channel
   message[8] += channel*8;
   message[9] = newvolume;   //vvvvvvvv 
   message[10] = 0;  //vvvvvvvv
   message[11] = 0xF7;
   Send_MIDI_Message(message,12);
}

void change_pan(unsigned char channel, unsigned char newvolume)
{
   channel--;
   char message[12];
   message[0] = 0xF0;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x0E;
   message[4] = 0x0E;
   message[5] = 0x10; //?
   message[6] = 33;  //0mmfffff 
   message[7] = 0;   //0ssppppp
   message[8] = 0;   //0ccccddv channel
   message[8] += 2;  
   message[8] += channel*8;
   message[9] = newvolume;   //vvvvvvvv 
   message[10] = 0;  //vvvvvvvv

   message[11] = 0xF7;
   Send_MIDI_Message(message,12);
}

void mix_mode()
{
   char message[8];
   message[0] = 0xF0;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x0E;
   message[4] = 0x0E;
   message[5] = 0x0D;
   message[6] = 1;
   message[7] = 0xF7;
   Send_MIDI_Message(message,8);
}

void mix_name(char*newname)
{
   unsigned char nums[9];
   for (int index=0;index<9;index++)
      if (newname[index]!= ' ')
      {
         if (newname[index] == '5')
            nums[index] = 21; else
         if (newname[index] == '4')
            nums[index] = 20; else
         if (newname[index] == '3')
            nums[index] = 19; else
         if (newname[index] == '2')
            nums[index] = 18; else
         if (newname[index] == '1')
            nums[index] = 17; else
         nums[index] = (int) (newname[index]-32);
      }
      else
         nums[index] = 0;

   for (index=0;index<9;index++)
   {
      char message[12];
      message[0] = 0xF0;
      message[1] = 0x00;
      message[2] = 0x00;
      message[3] = 0x0E;
      message[4] = 0x0E;
      message[5] = 0x10; //?
      message[6] = 32;  //0mmfffff mm = 1 ffff = 6
      message[6] += 6;
      message[7] = index;   //0ssppppp //0..9
      message[8] = 0;   //0ccccddv channel
      message[9] = nums[index];
      message[10] = 0;  //vvvvvvvv
      message[11] = 0xF7;
      Send_MIDI_Message(message,12);
   }
   mix_mode();
}

void change_keyboard_input(unsigned char channel, unsigned char on)
{
   channel--;
   char message[12];
   message[0] = 0xF0;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x0E;
   message[4] = 0x0E;
   message[5] = 0x10; //?
   message[6] = 36;  //0mmfffff mm = 1 for mix, ffff = function number
   message[7] = 1;   //0ssppppp
   message[8] = 6;   //0ccccddv channel
   message[8] += channel*8;
   message[9] = 0;
   if (on == 1)
      message[9] = 1;
   else
      message[9] = 0;
   message[10] = 0;  //vvvvvvvv
   message[11] = 0xF7;
   Send_MIDI_Message(message,12);
}

void change_effects_channel(unsigned char channel)
{
   channel--;
   char message[12];
   message[0] = 0xF0;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x0E;
   message[4] = 0x0E;
   message[5] = 0x10; //?
   message[6] = 37;  //0mmfffff mm = 1 for mix, ffff = function number
   message[7] = 0;   //0ssppppp ppp = page
   message[8] = 6;   //0ccccddv channel dd = pot   
   message[8] += channel*8;
   message[9] = 0;
   message[9] += channel;
   message[10] = 0;  //vvvvvvvv
   message[11] = 0xF7;
   Send_MIDI_Message(message,12);
}

void change_low_note(unsigned char channel, unsigned char note)
{
   channel--;
   char message[12];
   message[0] = 0xF0;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x0E;
   message[4] = 0x0E;
   message[5] = 0x10; //?
   message[6] = 36;  //0mmfffff mm = 1 for mix, ffff = function number
   message[7] = 0;   //0ssppppp
   message[8] = 0;   //0ccccddv channel
   message[8] += channel*8;
   message[9] = note;
   message[10] = 0;  //vvvvvvvv
   message[11] = 0xF7;
   Send_MIDI_Message(message,12);
}

void change_high_note(unsigned char channel, unsigned char note)
{
   channel--;
   char message[12];
   message[0] = 0xF0;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x0E;
   message[4] = 0x0E;
   message[5] = 0x10; //?
   message[6] = 36;  //0mmfffff mm = 1 for mix, ffff = function number
   message[7] = 0;   //0ssppppp
   message[8] = 2;   //0ccccddv channel pot
   message[8] += channel*8;
   message[9] = note;
   message[10] = 0;  //vvvvvvvv
   message[11] = 0xF7;
   Send_MIDI_Message(message,12);
}

//***
void change_effects_level(unsigned char channel, unsigned char value)
{
   channel--;
   char message[12];
   message[0] = 0xF0;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x0E;
   message[4] = 0x0E;
   message[5] = 0x10; //?
   message[6] = 34;  //0mmfffff mm = 1 for mix, ffff = function number
   message[7] = 0;   //0ssppppp
   message[8] = 0;   //0ccccddv channel pot
   message[8] += channel*8;
   message[9] = value;
   message[10] = 0;  //vvvvvvvv
   message[11] = 0xF7;
   Send_MIDI_Message(message,12);
}

void edit_program_parameters(unsigned char function, unsigned char page, unsigned char pot, unsigned char max, unsigned char sound, unsigned char value)
{
   char message[12];
   message[0] = 0xF0;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x0E;
   message[4] = 0x0E;
   message[5] = 0x10;
   message[6] = 64;  //0mmfffff mm = 1 for mix, ffff = function number
   message[6] += function;
   message[7] = 0;
   if (sound == 2)
      message[7] += 32;
   if (sound == 3)
      message[7] += 64;
   if (sound == 4)
      message[7] += 96;
   message[7] += page;
   message[8] = 0;
   if (pot == 1)
      message[8] = 2;
   if (pot == 2)
      message[8] = 4;
   if (pot == 3)
      message[8] = 6;
   if (value > max)
      value = max;
   message[9] = value;
   message[10] = 0;
   message[11] = 0xF7;
   Send_MIDI_Message(message,12);
}

void change_pitch(unsigned char channel, unsigned char pitch)
{
   channel--;
   char message[12];
   message[0] = 0xF0;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x0E;
   message[4] = 0x0E;
   message[5] = 0x10; //?
   message[6] = 35;  //0mmfffff mm = 1 for mix, ffff = function number
   message[7] = 0;   //0ssppppp
   message[8] = 0;   //0ccccddv channel pot
   message[8] += channel*8;
   message[9] = pitch;
   message[10] = 0;  //vvvvvvvv
   message[11] = 0xF7;
   Send_MIDI_Message(message,12);
}

void random_program(unsigned char prognum)
{
   char message[408];
   message[0] = 0xF0;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x0E;
   message[4] = 0x0E;
   message[5] = 0x00;
   message[6] = prognum;  //0mmfffff mm = 1 for mix, ffff = function number
   randomize();
   for (int index=7;index<407;index++)
      message[index] = random(127);
   message[407] = 0xF7;
   Send_MIDI_Message(message,408);
}

void change_program_sample_group(unsigned char sound, unsigned char group)
{
   edit_program_parameters(0,0,0,47,sound,group);
}

void change_program_sample_number(unsigned char sound, unsigned char samplenum)
{
   edit_program_parameters(0,0,2,127,sound,samplenum);
}

void change_program_volume(unsigned char sound, unsigned char volume)
{
   edit_program_parameters(1,0,0,99,sound,volume);
}

void change_program_pan(unsigned char sound, unsigned char pan)
{
   edit_program_parameters(1,0,1,6,sound,pan);
}

void change_program_output(unsigned char sound, unsigned char out)
{
   edit_program_parameters(1,0,2,2,sound,out);
}

void change_program_sound_effect_level(unsigned char sound, unsigned char newlevel)
{
   edit_program_parameters(2,0,0,99,sound,newlevel);
}

void change_program_sound_effect_bus(unsigned char sound, unsigned char bus)
{
   edit_program_parameters(2,0,1,3,sound,bus);
}

void change_program_sound_pitch_lfo_mod(unsigned char sound, unsigned char value)
{
   edit_program_parameters(3,1,2,99,sound,value);
}

void change_program_sound_filter_frequency(unsigned char sound, unsigned char value)
{
   edit_program_parameters(4,0,0,99,sound,value);
}

void change_program_sound_amp_velocity_curve(unsigned char sound, unsigned char value)
{
   edit_program_parameters(5,0,0,12,sound,value);
}

void change_program_sound_low_note(unsigned char sound, unsigned char value)
{
   edit_program_parameters(6,0,0,127,sound,value);
}

void change_program_sound_high_note(unsigned char sound, unsigned char value)
{
   edit_program_parameters(6,0,1,127,sound,value);
}

void change_program_sound_overlap(unsigned char sound, unsigned char value)
{
   edit_program_parameters(6,0,2,99,sound,value);
}

void change_program_mod_source(unsigned char sound, unsigned char modnum, unsigned char value)
{
   modnum--;
   if (modnum > 5)
      modnum = 5;
   edit_program_parameters(7,modnum,0,24,sound,value);
}

void change_program_mod_destination(unsigned char sound, unsigned char modnum, unsigned char value)
{
   modnum--;
   if (modnum > 5)
      modnum = 5;
   edit_program_parameters(7,modnum,1,31,sound,value);
}

void change_program_mod_amp(unsigned char sound, unsigned char modnum, unsigned char value)
{
   modnum--;
   if (modnum > 5)
      modnum = 5;
   edit_program_parameters(7,modnum,3,99,sound,value);
}

void change_program_mod_gate(unsigned char sound, unsigned char modnum, unsigned char value)
{
   modnum--;
   if (modnum > 5)
      modnum = 5;
   edit_program_parameters(7,modnum,4,1,sound,value);
}

void change_pitch_lfo_waveform(unsigned char sound, unsigned char value)
{
   edit_program_parameters(9,0,0,6,sound,value);
}

void change_pitch_lfo_speed(unsigned char sound, unsigned char value)
{
   edit_program_parameters(9,0,1,99,sound,value);
}

void change_pitch_lfo_delay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(9,0,2,99,sound,value);
}

void change_pitch_lfo_trigger(unsigned char sound, unsigned char value)
{
   edit_program_parameters(9,0,3,3,sound,value);
}

void change_pitch_lfo_level(unsigned char sound, unsigned char value)
{
   edit_program_parameters(9,1,0,99,sound,value);
}

void change_pitch_lfo_mod_wheel_mod(unsigned char sound, unsigned char value)
{
   edit_program_parameters(9,1,1,99,sound,value);
}

void change_pitch_lfo_aftertouch_mod(unsigned char sound, unsigned char value)
{
   edit_program_parameters(9,1,2,99,sound,value);
}

void change_filter_lfo_waveform(unsigned char sound, unsigned char value)
{
   edit_program_parameters(10,0,0,6,sound,value);
}

void change_filter_lfo_speed(unsigned char sound, unsigned char value)
{
   edit_program_parameters(10,0,1,99,sound,value);
}

void change_filter_lfo_delay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(10,0,2,99,sound,value);
}

void change_filter_lfo_trigger(unsigned char sound, unsigned char value)
{
   edit_program_parameters(10,0,3,3,sound,value);
}

void change_filter_lfo_level(unsigned char sound, unsigned char value)
{
   edit_program_parameters(10,1,0,99,sound,value);
}

void change_filter_lfo_mod_wheel_mod(unsigned char sound, unsigned char value)
{
   edit_program_parameters(10,1,1,99,sound,value);
}

void change_filter_lfo_aftertouch_mod(unsigned char sound, unsigned char value)
{
   edit_program_parameters(10,1,2,99,sound,value);
}

void change_amp_lfo_waveform(unsigned char sound, unsigned char value)
{
   edit_program_parameters(11,0,0,6,sound,value);
}

void change_amp_lfo_speed(unsigned char sound, unsigned char value)
{
   edit_program_parameters(11,0,1,99,sound,value);
}

void change_amp_lfo_delay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(11,0,2,99,sound,value);
}

void change_amp_lfo_trigger(unsigned char sound, unsigned char value)
{
   edit_program_parameters(11,0,3,3,sound,value);
}

void change_amp_lfo_level(unsigned char sound, unsigned char value)
{
   edit_program_parameters(11,1,0,99,sound,value);
}

void change_amp_lfo_mod_wheel_mod(unsigned char sound, unsigned char value)
{
   edit_program_parameters(11,1,1,99,sound,value);
}

void change_amp_lfo_aftertouch_mod(unsigned char sound, unsigned char value)
{
   edit_program_parameters(11,1,2,99,sound,value);
}

void change_pitch_env_attack(unsigned char sound, unsigned char value)
{
   edit_program_parameters(12,0,0,99,sound,value);
}

void change_pitch_env_decay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(12,0,1,99,sound,value);
}

void change_pitch_env_sustain(unsigned char sound, unsigned char value)
{
   edit_program_parameters(12,0,2,99,sound,value);
}

void change_pitch_env_release(unsigned char sound, unsigned char value)
{
   edit_program_parameters(12,0,3,99,sound,value);
}

void change_pitch_env_delay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(12,1,0,99,sound,value);
}

void change_pitch_env_sustain_decay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(12,1,1,99,sound,value);
}

void change_pitch_env_trig_type(unsigned char sound, unsigned char value)
{
   edit_program_parameters(12,1,3,3,sound,value);
}

void change_pitch_env_time_track(unsigned char sound, unsigned char value)
{
   edit_program_parameters(12,2,0,1,sound,value);
}

void change_pitch_env_sustain_pedal(unsigned char sound, unsigned char value)
{
   edit_program_parameters(12,2,1,1,sound,value);
}

void change_pitch_env_level(unsigned char sound, unsigned char value)
{
   edit_program_parameters(12,2,2,99,sound,value);
}

void change_pitch_env_velocity_mod(unsigned char sound, unsigned char value)
{
   edit_program_parameters(12,2,3,99,sound,value);
}

void change_filter_env_attack(unsigned char sound, unsigned char value)
{
   edit_program_parameters(13,0,0,99,sound,value);
}

void change_filter_env_decay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(13,0,1,99,sound,value);
}

void change_filter_env_sustain(unsigned char sound, unsigned char value)
{
   edit_program_parameters(13,0,2,99,sound,value);
}

void change_filter_env_release(unsigned char sound, unsigned char value)
{
   edit_program_parameters(13,0,3,99,sound,value);
}

void change_filter_env_delay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(13,1,0,99,sound,value);
}

void change_filter_env_sustain_decay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(13,1,1,99,sound,value);
}

void change_filter_env_trig_type(unsigned char sound, unsigned char value)
{
   edit_program_parameters(13,1,3,3,sound,value);
}

void change_filter_env_time_track(unsigned char sound, unsigned char value)
{
   edit_program_parameters(13,2,0,1,sound,value);
}

void change_filter_env_sustain_pedal(unsigned char sound, unsigned char value)
{
   edit_program_parameters(13,2,1,1,sound,value);
}

void change_filter_env_level(unsigned char sound, unsigned char value)
{
   edit_program_parameters(13,2,2,99,sound,value);
}

void change_filter_env_velocity_mod(unsigned char sound, unsigned char value)
{
   edit_program_parameters(13,2,3,99,sound,value);
}

void change_amp_env_attack(unsigned char sound, unsigned char value)
{
   edit_program_parameters(14,0,0,99,sound,value);
}

void change_amp_env_decay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(14,0,1,99,sound,value);
}

void change_amp_env_sustain(unsigned char sound, unsigned char value)
{
   edit_program_parameters(14,0,2,99,sound,value);
}
void change_amp_env_release(unsigned char sound, unsigned char value)
{
   edit_program_parameters(14,0,3,99,sound,value);
}

void change_amp_env_delay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(14,1,0,99,sound,value);
}

void change_amp_env_sustain_decay(unsigned char sound, unsigned char value)
{
   edit_program_parameters(14,1,1,99,sound,value);
}

void change_amp_env_trig_type(unsigned char sound, unsigned char value)
{
   edit_program_parameters(14,1,3,3,sound,value);
}

void change_amp_env_time_track(unsigned char sound, unsigned char value)
{
   edit_program_parameters(14,2,0,1,sound,value);
}

void change_amp_env_sustain_pedal(unsigned char sound, unsigned char value)
{
   edit_program_parameters(14,2,1,1,sound,value);
}

void change_amp_env_level(unsigned char sound, unsigned char value)
{
   edit_program_parameters(14,2,2,99,sound,value);
}

void change_amp_env_velocity_mod(unsigned char sound, unsigned char value)
{
   edit_program_parameters(14,2,3,99,sound,value);
}

void change_sound_enable(unsigned char sound, unsigned char value)
{
   edit_program_parameters(16,0,3,1,sound,value);
}

void edit_jp_parameter(char address, char value)
{
   char message[13];
   message[0] = 0xF0;   //Start system exclusive

   message[1] = 0x41;   //Start manufact ID
   message[2] = 0x10;
   message[3] = 0x00;
   message[4] = 0x06;

   message[5] = 0x12;   //Take this message, bitch

   //Memory adderss
   message[6] = 0x01;   
   message[7] = 0x00;   
   message[8] = 0x40;   
   message[9] = address;

   message[10] = value;

   //Value
   int checksum = 0;
   checksum += (message[6] + message[7] + message[8] + message[9] + message[10]);
   checksum %= 128;
   checksum = (128-checksum);
   message[11] = checksum;
   message[12] = 0xF7;
   Send_MIDI_Message(message,13);
}
