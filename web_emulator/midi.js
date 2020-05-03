let midi = {
    C0: 24,
    CS0: 25,
    D0: 26,
    DS0: 27,
    E0: 28,
    F0: 29,
    FS0: 30,
    G0: 31,
    GS0: 32,
    A0: 33,
    AS0: 34,
    B0: 35,
    C1: 36,
    CS1: 37,
    D1: 38,
    DS1: 39,
    E1: 40,
    F1: 41,
    FS1: 42,
    G1: 43,
    GS1: 44,
    A1: 45,
    AS1: 46,
    B1: 47,

    C2: 48,
    CS2: 49,
    D2: 50,
    DS2: 51,
    E2: 52,
    F2: 53,
    FS2: 54,
    G2: 55,
    GS2: 56,
    A2: 57,
    AS2: 58,
    B2: 59,

    C3: 60,
    CS3: 61,
    D3: 62,
    DS3: 63,
    E3: 64,
    F3: 65,
    FS3: 66,
    G3: 67,
    GS3: 68,
    A3: 69,
    AS3: 70,
    B3: 71,

    C4: 72,
    CS4: 73,
    D4: 74,
    DS4: 75,
    E4: 76,
    F4: 77,
    FS4: 78,
    G4: 79,
    GS4: 80,
    A4: 81,
    AS4: 82,
    B4: 83,

    C5: 84,
    CS5: 85,
    D5: 86,
    DS5: 87,
    E5: 88,
    F5: 89,
    FS5: 90,
    G5: 91,
    GS5: 92,
    A5: 93,
    AS5: 94,
    B5: 95,

    C6: 96,
    CS6: 97,
    D6: 98,
    DS6: 99,
    E6: 100,
    F6: 101,
    FS6: 102,
    G6: 103,
    GS6: 104,
    A6: 105,
    AS6: 106,
    B6: 107,
    C7: 108,

    midiOut: null,
    play_note: function(channel, note, velocity) {
        //console.log("play note: " + channel + ", " + note + ", " + velocity);
        if (note == 0) return 0;
        channel--;
        if ((channel >= 0) && (channel <= 15)) {
            let message = [];
            message[0] = 0x90;
            message[0] += channel;
            message[1] = note;
            message[2] = velocity;
            if (this.midiOut == null) {
                console.log("midiOut is null");
                return -1;
            }
            //console.log(message);
            this.midiOut.send(message);
        }
        return 1;
    },

    kill_note: function(channel, note, velocity) {
        //console.log("kill note: " + channel + ", " + note + ", " + velocity);
        if (note == 0) return 0;
        channel--;
        if ((channel >= 0) && (channel <= 15)) {
            let message = [];
            message[0] = 0x80;
            message[0] += channel;
            message[1] = note;
            message[2] = velocity;

            if (this.midiOut == null) {
                console.log("midiOut is null");
                return -1;
            }

            this.midiOut.send(message);

        }
        return 1;
    },

    program_change: function(channel, programNumber) {
        channel--;
        if (this.midiOut != null) {
            this.midiOut.send([0xC0 + channel, programNumber - 1]);
        }
    },

    change_volume: function(channel, newvolume) {
        //not implemented yet
        return;
        if (newvolume < 0)
            return;
        channel--;
        let message= [];
        message[0] = 0xF0;
        message[1] = 0x00;
        message[2] = 0x00;
        message[3] = 0x0E;
        message[4] = 0x0E;
        message[5] = 0x10; //?
        message[6] = 33; //0mmfffff 
        message[7] = 0; //0ssppppp
        message[8] = 0; //0ccccddv channel
        message[8] += channel * 8;
        message[9] = newvolume; //vvvvvvvv 
        message[10] = 0; //vvvvvvvv
        message[11] = 0xF7;
        if (this.midiOut != null) {
            this.midiOut.send(message);
        }
    }
};