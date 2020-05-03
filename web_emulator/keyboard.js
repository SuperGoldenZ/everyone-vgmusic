let keyboard = {
    // #define MAKE_BACKSPACE  14
    // #define MAKE_BACKSLASH  43

    // #define MAKE_ESC        1
    // #define MAKE_11         2
    // #define MAKE_21         3
    // #define MAKE_31         4
    // #define MAKE_41         5
    // #define MAKE_51         6
    // #define MAKE_61         7
    // #define MAKE_71         8
    // #define MAKE_81         9
    // #define MAKE_91         10
    // #define MAKE_01         11
    // #define MAKE_MINUS      12
    // #define MAKE_EQUAL      13
    // #define MAKE_Q          16
    // #define MAKE_W          17
    // #define MAKE_E          18
    // #define MAKE_R          19
    // #define MAKE_T          20
    // #define MAKE_Y          21
    // #define MAKE_U          22
    // #define MAKE_I          23
    // #define MAKE_A          30
    // #define MAKE_4          75
    // #define MAKE_5          76
    // #define MAKE_7          71
    // #define MAKE_9          73
    // #define MAKE_UP         72
    // #define MAKE_DOWN       80
    // #define MAKE_LEFT       75
    // #define MAKE_RIGHT      77
    // #define MAKE_ENTER      28
    // #define MAKE_SPACE      57
    // #define MAKE_N          49
    // #define MAKE_1          79
    // #define MAKE_2          80
    // #define MAKE_3          81
    // #define MAKE_D          32
    // #define MAKE_V          47
    // #define MAKE_CTRL       29
    // #define MAKE_P          25
    // #define MAKE_S          31
    // #define MAKE_L          38
    // #define MAKE_0          82
    // #define MAKE_F1         59
    // #define MAKE_F2         60
    // #define MAKE_F3         61
    // #define MAKE_F4         62
    // #define MAKE_F5         63
    // #define MAKE_F6         64
    // #define MAKE_F7         65
    // #define MAKE_F8         66
    // #define MAKE_F9         67
    // #define MAKE_F10        68
    // #define MAKE_F11        87
    // #define MAKE_F12        88
    // #define MAKE_F          33
    // #define MAKE_O          24
    // #define MAKE_RIGHTSQUAREBRACE          27
    // #define MAKE_LEFTSQUAREBRACE          26
    // #define MAKE_QUOTE       40
    // #define MAKE_COLIN       39
    // #define MAKE_K 37
    // #define MAKE_SLASH       53
    // #define MAKE_GREATERTHAN 52
    // #define MAKE_LESSTHAN    51
    // #define MAKE_M           50
    // #define MAKE_G           34
    // #define MAKE_H           35
    // #define MAKE_Z 44
    // #define MAKE_X 45
    // #define MAKE_C 46
    // #define BREAK_Z 44+128
    // #define BREAK_X 45+128
    // #define BREAK_C 46+128

    // #define BREAK_SLASH       53 + 128
    // #define BREAK_GREATERTHAN 52 + 128
    // #define BREAK_LESSTHAN    51 + 128
    // #define BREAK_M           50 + 128
    // #define BREAK_K 37+128
    // #define BREAK_QUOTE      40+128
    // #define BREAK_COLIN      39+128
    // #define BREAK_O          24+128
    // #define BREAK_RIGHTSQUAREBRACE          27+128
    // #define BREAK_LEFTSQUAREBRACE          26+128
    // #define BREAK_BACKSPACE  14 + 128
    // #define BREAK_BACKSLASH  43 + 128
    // #define BREAK_F11       87 + 128
    // #define BREAK_F12       88 + 128
    // #define BREAK_0         MAKE_0 + 128
    // #define BREAK_1          79+128
    // #define BREAK_3          81+128
    // #define BREAK_4          75+128
    // #define BREAK_5          76+128
    // #define BREAK_7         199
    // #define BREAK_9         201
    // #define BREAK_S         31+128
    // #define BREAK_RIGHT     205
    // #define BREAK_LEFT      203
    // #define BREAK_UP        200
    // #define BREAK_DOWN      208
    // #define BREAK_ESC       129
    // #define BREAK_ENTER     156
    // #define BREAK_SPACE     185
    // #define BREAK_N         177
    // #define BREAK_Q         16+128
    // #define BREAK_D         32+128
    // #define BREAK_V         47+128
    // #define BREAK_CTRL      29+128
    // #define BREAK_P         25+128
    // #define BREAK_F         33 + 128
    // #define BREAK_L         38+128
    // #define BREAK_F1        MAKE_F1 + 128
    // #define BREAK_F2        MAKE_F2 + 128
    // #define BREAK_F3        MAKE_F3 + 128
    // #define BREAK_F4        MAKE_F4 + 128
    // #define BREAK_F5        MAKE_F5 + 128
    // #define BREAK_F6        MAKE_F6 + 128
    // #define BREAK_F7        MAKE_F7 + 128
    // #define BREAK_11        2 + 128
    // #define BREAK_21        3 + 128
    // #define BREAK_31        4 + 128
    // #define BREAK_41        5 + 128
    // #define BREAK_51        6 + 128
    // #define BREAK_61        7 + 128
    // #define BREAK_71        8 + 128
    // #define BREAK_81        9 + 128
    // #define BREAK_91        10 + 128
    // #define BREAK_01        11 + 128
    // #define BREAK_MINUS     12 + 128
    // #define BREAK_EQUAL     13 + 128
    // #define BREAK_W         17 + 128    
    // #define BREAK_E         18 + 128    
    // #define BREAK_R         19 + 128    
    // #define BREAK_T         20 + 128    
    // #define BREAK_U         22 + 128    
    // #define BREAK_I         23 + 128    
    // #define BREAK_Y         MAKE_Y + 128
    // #define BREAK_F8         66 + 128
    // #define BREAK_F9         67 + 128
    // #define BREAK_F10        68 + 128
    // #define BREAK_A 30 + 128
    // #define BREAK_G MAKE_G + 128
    // #define BREAK_H MAKE_H + 128

    INDEX_UP: 0x26,
    INDEX_DOWN: 0x28,
    INDEX_LEFT: 0x25,
    INDEX_RIGHT: 0x27,
    INDEX_ENTER: 13,
    INDEX_SPACE: 32,
    INDEX_ESC: 6,
    INDEX_Y: 0x59,
    INDEX_N: 0x4E,
    INDEX_I: 0x49,
    INDEX_D: 0x44 ,
    INDEX_Q: 0x51 ,
    INDEX_V: 0x56,
    INDEX_CTRL: 17,
    INDEX_1: 49,
    INDEX_2: 50,
    INDEX_3: 51,
    INDEX_4: 52,
    INDEX_5: 53,
    INDEX_7: 8,
    INDEX_9: 9,    
    INDEX_P: 21,
    INDEX_S: 22,
    INDEX_L: 23,
    INDEX_0: 24,
    INDEX_F1: 25,
    INDEX_F2: 26,
    INDEX_F3: 27,
    INDEX_F4: 28,
    INDEX_F5: 29,
    INDEX_F6: 30,
    INDEX_F7: 31,
    INDEX_11: 32,
    INDEX_21: 33,
    INDEX_31: 34,
    INDEX_41: 35,
    INDEX_51: 36,
    INDEX_61: 37,
    INDEX_71: 38,
    INDEX_81: 39,
    INDEX_91: 40,
    INDEX_MINUS: 41,
    INDEX_EQUAL: 42,
    INDEX_01: 43,
    INDEX_W: 44,
    INDEX_E: 45,
    INDEX_R: 82,
    INDEX_T: 47,
    INDEX_U: 48,
    INDEX_F8: 49,
    INDEX_F9: 50,
    INDEX_F10: 51,
    INDEX_A: 65,
    INDEX_F: 53,
    INDEX_F11: 54,
    INDEX_F12: 55,
    INDEX_BACKSPACE: 56,
    INDEX_BACKSLASH: 57,
    INDEX_LEFTSQUAREBRACE: 58,
    INDEX_RIGHTSQUAREBRACE: 59,
    INDEX_O: 60,
    INDEX_QUOTE: 61,
    INDEX_COLIN: 62,
    INDEX_K: 63,
    INDEX_SLASH: 64,
    INDEX_GREATERTHAN: 65,
    INDEX_LESSTHAN: 66,
    INDEX_M: 67,
    INDEX_G: 68,
    INDEX_H: 69,
    INDEX_Z: 70,
    INDEX_X: 71,
    INDEX_C: 72,
    NUM_KEYS: 73,

    key_table: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    // //void interrupt (*Old_Key_Isr)(...);
    // //int raw_key;



    // //From Teach Yourself Game Programming by Andre LaMothe
    // void interrupt New_Key_Int(...)
    // {
    //  _asm {
    // 	sti
    // 	in al, KEY_BUFFER
    // 	xor ah, ah
    // 	mov raw_key, ax
    // 	in al, KEY_CONTROL
    // 	or al, 82h

    // 	out KEY_CONTROL, al

    // 	and al, 7fh
    // 	out KEY_CONTROL, al
    // 	mov al, 20h
    // 	out INT_CONTROL, al
    //  }
    // // cout << "\n" << raw_key;
    //  switch(raw_key)
    //  {
    //   case MAKE_UP:         key_table[INDEX_UP]=1;break;
    //   case MAKE_ESC:        key_table[INDEX_ESC]=1;break;
    //   case MAKE_RIGHT:      key_table[INDEX_RIGHT]=1;break;
    //   case MAKE_LEFT:       key_table[INDEX_LEFT]=1;break;
    //   case MAKE_SPACE:      key_table[INDEX_SPACE]=1;break;
    //   case MAKE_ENTER:      key_table[INDEX_ENTER]=1;break;
    //   case MAKE_1:          key_table[INDEX_1]=1;break;
    //   case MAKE_3:          key_table[INDEX_3]=1;break;
    //   case MAKE_5:          key_table[INDEX_5]=1;break;
    //   case MAKE_7:          key_table[INDEX_7]=1;break;
    //   case MAKE_9:          key_table[INDEX_9]=1;break;
    //   case MAKE_Y:          key_table[INDEX_Y]=1;break;
    //   case MAKE_N:          key_table[INDEX_N]=1;break;
    //   case MAKE_I:          key_table[INDEX_I]=1;break;
    //   case MAKE_Q:          key_table[INDEX_Q]=1;break;
    //   case MAKE_D:          key_table[INDEX_D]=1;break;
    //   case MAKE_V:          key_table[INDEX_V]=1;break;
    //   case MAKE_CTRL:       key_table[INDEX_CTRL]=1;break;
    //   case MAKE_DOWN:       key_table[INDEX_DOWN]=1;break;
    //   case MAKE_P:          key_table[INDEX_P]=1;break;
    //   case MAKE_S:          key_table[INDEX_S]=1;break;
    //   case MAKE_A:          key_table[INDEX_A]=1;break;
    //   case MAKE_F:          key_table[INDEX_F]=1;break;
    //   case MAKE_0:          key_table[INDEX_0]=1;break;
    //   case MAKE_L:          key_table[INDEX_L]=1;break;
    //   case MAKE_F1:         key_table[INDEX_F1]=1;break;
    //   case MAKE_F2:         key_table[INDEX_F2]=1;break;
    //   case MAKE_F3:         key_table[INDEX_F3]=1;break;
    //   case MAKE_F4:         key_table[INDEX_F4]=1;break;
    //   case MAKE_F5:         key_table[INDEX_F5]=1;break;
    //   case MAKE_F6:         key_table[INDEX_F6]=1;break;
    //   case MAKE_F7:         key_table[INDEX_F7]=1;break;
    //   case MAKE_F8:         key_table[INDEX_F8]=1;break;
    //   case MAKE_F9:         key_table[INDEX_F9]=1;break;
    //   case MAKE_F10:         key_table[INDEX_F10]=1;break;
    //   case MAKE_F11:         key_table[INDEX_F11]=1;break;
    //   case MAKE_F12:         key_table[INDEX_F12]=1;break;
    //   case MAKE_11:         key_table[INDEX_11]=1;break;
    //   case MAKE_21:         key_table[INDEX_21]=1;break;
    //   case MAKE_31:         key_table[INDEX_31]=1;break;
    //   case MAKE_41:         key_table[INDEX_41]=1;break;
    //   case MAKE_51:         key_table[INDEX_51]=1;break;
    //   case MAKE_61:         key_table[INDEX_61]=1;break;
    //   case MAKE_71:         key_table[INDEX_71]=1;break;
    //   case MAKE_81:         key_table[INDEX_81]=1;break;
    //   case MAKE_91:         key_table[INDEX_91]=1;break; 
    //   case MAKE_01:         key_table[INDEX_01]=1;break; 
    //   case MAKE_MINUS:      key_table[INDEX_MINUS]=1;break;
    //   case MAKE_EQUAL:      key_table[INDEX_EQUAL]=1;break; 
    //   case MAKE_W:          key_table[INDEX_W]=1;break;
    //   case MAKE_E:          key_table[INDEX_E]=1;break;  
    //   case MAKE_R:          key_table[INDEX_R]=1;break;
    //   case MAKE_T:          key_table[INDEX_T]=1;break;
    //   case MAKE_U:          key_table[INDEX_U]=1;break;
    //   case MAKE_RIGHTSQUAREBRACE: key_table[INDEX_RIGHTSQUAREBRACE]=1;break;
    //   case MAKE_LEFTSQUAREBRACE:  key_table[INDEX_LEFTSQUAREBRACE]=1;break;
    //   case MAKE_BACKSPACE: key_table[INDEX_BACKSPACE]=1;break;
    //   case MAKE_BACKSLASH: key_table[INDEX_BACKSLASH]=1;break;
    //   case MAKE_O: key_table[INDEX_O]=1;break;
    //   case MAKE_K: key_table[INDEX_K]=1;break;
    //   case MAKE_G: key_table[INDEX_G]=1;break;
    //   case MAKE_H: key_table[INDEX_H]=1;break;
    //   case MAKE_Z: key_table[INDEX_Z]=1;break;
    //   case MAKE_X: key_table[INDEX_X]=1;break;
    //   case MAKE_C: key_table[INDEX_C]=1;break;
    //   case MAKE_COLIN: key_table[INDEX_COLIN]=1;break;
    //   case MAKE_QUOTE: key_table[INDEX_QUOTE]=1;break;
    //   case MAKE_SLASH: key_table[INDEX_SLASH]=1;break;
    //   case MAKE_GREATERTHAN: key_table[INDEX_GREATERTHAN]=1;break;
    //   case MAKE_LESSTHAN: key_table[INDEX_LESSTHAN]=1;break;
    //   case MAKE_M: key_table[INDEX_M]=1;break;
    // }

    //  switch(raw_key)
    //  {
    //   case BREAK_SLASH: key_table[INDEX_SLASH]=0;break;
    //   case BREAK_GREATERTHAN: key_table[INDEX_GREATERTHAN]=0;break;
    //   case BREAK_LESSTHAN: key_table[INDEX_LESSTHAN]=0;break;
    //   case BREAK_M: key_table[INDEX_M]=0;break;
    //   case BREAK_K: key_table[INDEX_K]=0;break;
    //   case BREAK_COLIN: key_table[INDEX_COLIN]=0;break;
    //   case BREAK_QUOTE: key_table[INDEX_QUOTE]=0;break;
    //   case BREAK_O: key_table[INDEX_O]=0;break;
    //   case BREAK_UP:        key_table[INDEX_UP]=0;break;
    //   case BREAK_SPACE:     key_table[INDEX_SPACE]=0;break;
    //   case BREAK_DOWN:      key_table[INDEX_DOWN]=0;break;
    //   case BREAK_LEFT:      key_table[INDEX_LEFT]=0;break;
    //   case BREAK_RIGHT:     key_table[INDEX_RIGHT]=0;break;
    //   case BREAK_ESC:       key_table[INDEX_ESC]=0;break;
    //   case BREAK_ENTER:     key_table[INDEX_ENTER]=0;break;
    //   case BREAK_1:         key_table[INDEX_1]=0;break;
    //   case BREAK_3:         key_table[INDEX_3]=0;break;
    //   case BREAK_5:         key_table[INDEX_5]=0;break;
    //   case BREAK_Z:         key_table[INDEX_Z]=0;break;
    //   case BREAK_X:         key_table[INDEX_X]=0;break;
    //   case BREAK_C:         key_table[INDEX_C]=0;break;
    //   case BREAK_7:         key_table[INDEX_7]=0;break;
    //   case BREAK_9:         key_table[INDEX_9]=0;break;
    //   case BREAK_Y:         key_table[INDEX_Y]=0;break;
    //   case BREAK_N:         key_table[INDEX_N]=0;break;
    //   case BREAK_I:         key_table[INDEX_I]=0;break;
    //   case BREAK_Q:         key_table[INDEX_Q]=0;break;
    //   case BREAK_D:         key_table[INDEX_D]=0;break;
    //   case BREAK_V:         key_table[INDEX_V]=0;break;
    //   case BREAK_CTRL:      key_table[INDEX_CTRL]=0;break;
    //   case BREAK_P:         key_table[INDEX_P]=0;break;
    //   case BREAK_S:         key_table[INDEX_S]=0;break;
    //   case BREAK_0:         key_table[INDEX_0]=0;break;
    //   case BREAK_L:         key_table[INDEX_L]=0;break;
    //   case BREAK_F1:        key_table[INDEX_F1]=0;break;
    //   case BREAK_F2:        key_table[INDEX_F2]=0;break;
    //   case BREAK_F3:        key_table[INDEX_F3]=0;break;
    //   case BREAK_F4:        key_table[INDEX_F4]=0;break;
    //   case BREAK_F5:        key_table[INDEX_F5]=0;break;
    //   case BREAK_F6:        key_table[INDEX_F6]=0;break;
    //   case BREAK_F7:        key_table[INDEX_F7]=0;break;
    //   case BREAK_11:        key_table[INDEX_11]=0;break;
    //   case BREAK_21:        key_table[INDEX_21]=0;break;
    //   case BREAK_31:        key_table[INDEX_31]=0;break;
    //   case BREAK_41:        key_table[INDEX_41]=0;break;
    //   case BREAK_51:        key_table[INDEX_51]=0;break;
    //   case BREAK_61:        key_table[INDEX_61]=0;break;
    //   case BREAK_71:        key_table[INDEX_71]=0;break;
    //   case BREAK_81:        key_table[INDEX_81]=0;break;
    //   case BREAK_91:        key_table[INDEX_91]=0;break;
    //   case BREAK_MINUS:     key_table[INDEX_MINUS]=0;break;
    //   case BREAK_EQUAL:     key_table[INDEX_EQUAL]=0;break;
    //   case BREAK_01:        key_table[INDEX_01]=0;break;
    //   case BREAK_W:         key_table[INDEX_W]=0;break;
    //   case BREAK_E:         key_table[INDEX_E]=0;break;  
    //   case BREAK_R:         key_table[INDEX_R]=0;break;
    //   case BREAK_T:         key_table[INDEX_T]=0;break;
    //   case BREAK_U:         key_table[INDEX_U]=0;break;
    //   case BREAK_A:         key_table[INDEX_A]=0;break;
    //   case BREAK_F:         key_table[INDEX_F]=0;break;
    //   case BREAK_G:         key_table[INDEX_G]=0;break;
    //   case BREAK_H:         key_table[INDEX_H]=0;break;
    //   case BREAK_F8:        key_table[INDEX_F8]=0;break;
    //   case BREAK_F9:        key_table[INDEX_F9]=0;break;
    //   case BREAK_F10:       key_table[INDEX_F10]=0;break;
    //   case BREAK_F11:       key_table[INDEX_F11]=0;break;
    //   case BREAK_F12:       key_table[INDEX_F12]=0;break;
    //   case BREAK_BACKSPACE: key_table[INDEX_BACKSPACE]=0;break;
    //   case BREAK_BACKSLASH: key_table[INDEX_BACKSLASH]=0;break;
    //   case BREAK_RIGHTSQUAREBRACE: key_table[INDEX_RIGHTSQUAREBRACE]=0;break;
    //   case BREAK_LEFTSQUAREBRACE:  key_table[INDEX_LEFTSQUAREBRACE]=0;break;
    //  }
    // }

    // void install_keyboard(void)
    // {
    // Old_Key_Isr = _dos_getvect(KEYBOARD_INT);
    // _dos_setvect(KEYBOARD_INT, New_Key_Int);
    // }

    // void init_keyboard(void)
    // {
    // Old_Key_Isr = _dos_getvect(KEYBOARD_INT);
    // _dos_setvect(KEYBOARD_INT, New_Key_Int);
    // }

    // void kill_keyboard(void)
    // {
    // 	_dos_setvect(KEYBOARD_INT, Old_Key_Isr);
    // }

    // int anykey()
    // {
    //  int index;
    //  for (index=0;index<NUM_KEYS;index++)
    //   if (key_table[index]==1) return(1);
    //  return(0);
    // }

    // void wait_for_blank()
    // {
    //  while (anykey());
    // }

    // void pause()
    // {
    //  while (!(anykey()));
    // }

    // void wait_for(const int&num)
    // {
    //  while (key_table[num]==0);
    // }

    // void wait_for_no(const int&num)
    // {
    //  while (key_table[num]==1);
    // }
};
console.log("keyboard loaded");