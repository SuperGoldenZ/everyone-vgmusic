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
    INDEX_D: 0x44,
    INDEX_Q: 0x51,
    INDEX_V: 0x56,
    INDEX_CTRL: 17,
    INDEX_1: 49,
    INDEX_2: 50,
    INDEX_3: 51,
    INDEX_4: 52,
    INDEX_5: 53,
    INDEX_7: 8,
    INDEX_9: 9,
    INDEX_P: 80,
    INDEX_S: 83,
    INDEX_L: 23,
    INDEX_0: 48,
    INDEX_F1: 25,
    INDEX_F2: 26,
    INDEX_F3: 27,
    INDEX_F4: 28,
    INDEX_F5: 29,
    INDEX_F6: 30,
    INDEX_F7: 31,
    INDEX_11: 32,
    INDEX_21: 33,
    INDEX_31: 97,
    INDEX_41: 98,
    INDEX_51: 36,
    INDEX_61: 37,
    INDEX_71: 38,
    INDEX_81: 39,
    INDEX_91: 40,
    INDEX_MINUS: 41,
    INDEX_EQUAL: 42,
    INDEX_01: 43,
    INDEX_W: 87,
    INDEX_E: 69,
    INDEX_R: 82,
    INDEX_T: 84,
    INDEX_U: 48,
    INDEX_F8: 49,
    INDEX_F9: 50,
    INDEX_F10: 51,
    INDEX_A: 65,
    INDEX_F: 70,
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
    INDEX_G: 71,
    INDEX_H: 69,
    INDEX_Z: 90,
    INDEX_X: 88,
    INDEX_C: 67,
    NUM_KEYS: 73,

    key_table: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
};