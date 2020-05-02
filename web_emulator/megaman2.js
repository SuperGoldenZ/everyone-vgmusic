let megaman2 = {
    filename: "MEGAMAN2",
    filesize: "65,012",
    modified: new Date("September 28, 2002 20:00:00"),
    notes: [],
    bassnotes: [],
    drumbassnotes: [],
    onDone: null,

    main: function() {
        var index;
        for (index = 0; index < 127; index++)
            this.notes[index] = 0;

        for (index = 0; index < 56; index++) {
            this.bassnotes[index] = [];
            this.drumbassnotes[index] = [];
        }

        for (index = 0; index < 12; index++)
            this.bassnotes[0][index] = midi.CS2;
        for (index = 0; index < 12; index++)
            this.bassnotes[1][index] = midi.CS2;
        for (index = 0; index < 12; index++)
            this.bassnotes[2][index] = midi.A2;
        for (index = 0; index < 12; index++)
            this.bassnotes[3][index] = midi.A2;
        for (index = 0; index < 12; index++)
            this.bassnotes[4][index] = midi.B2;
        for (index = 0; index < 12; index++)
            this.bassnotes[5][index] = midi.B2;
        for (index = 0; index < 12; index++)
            this.bassnotes[6][index] = midi.CS2;
        for (index = 0; index < 12; index++)
            this.bassnotes[7][index] = midi.CS2;
        this.bassnotes[7][10] = midi.B2;
        this.bassnotes[7][11] = midi.CS2;

        for (var measure = 8; measure < 16; measure++)
            for (var note = 0; note < 12; note++)
                this.bassnotes[measure][note] = this.bassnotes[measure - 8][note];

        for (index = 0; index < 12; index++)
            this.bassnotes[16][index] = midi.D2;
        for (index = 0; index < 12; index++)
            this.bassnotes[17][index] = midi.D2;

        for (index = 0; index < 12; index++)
            this.bassnotes[18][index] = midi.CS2;
        for (index = 0; index < 12; index++)
            this.bassnotes[19][index] = midi.CS2;

        for (index = 0; index < 12; index++)
            this.bassnotes[20][index] = midi.D2;
        for (index = 0; index < 12; index++)
            this.bassnotes[21][index] = midi.D2;

        for (index = 0; index < 12; index++)
            this.bassnotes[22][index] = midi.B2;
        for (index = 0; index < 12; index++)
            this.bassnotes[23][index] = midi.C2;

        for (index = 0; index < 24; index++)
            for (var index1 = 0; index1 < 12; index1++)
                this.bassnotes[24 + index][index1] = this.bassnotes[index][index1];

        for (index = 0; index < 12; index++)
            this.bassnotes[48][index] = midi.A2;

        for (index = 0; index < 11; index++)
            this.bassnotes[49][index] = midi.B2;
        this.bassnotes[49][11] = midi.CS2;

        for (index = 0; index < 12; index++)
            this.bassnotes[50][index] = 0;
        this.bassnotes[50][0] = midi.CS2;
        this.bassnotes[50][3] = midi.CS2;
        this.bassnotes[50][4] = midi.DS2;
        this.bassnotes[50][6] = midi.E2;
        this.bassnotes[50][9] = midi.DS2;
        this.bassnotes[50][11] = midi.CS2;

        for (index = 0; index < 12; index++)
            this.bassnotes[51][index] = 0;
        this.bassnotes[51][0] = midi.CS2;
        this.bassnotes[51][3] = midi.CS2;
        this.bassnotes[51][4] = midi.DS2;
        this.bassnotes[51][6] = midi.E2;
        this.bassnotes[51][9] = midi.DS2;
        //  this.bassnotes[51][11] = CS1;   

        for (index = 0; index < 12; index++)
            this.bassnotes[52][index] = midi.A2;

        for (index = 0; index < 12; index++)
            this.bassnotes[53][index] = midi.B2;

        for (index = 0; index < 12; index++)
            this.bassnotes[54][index] = midi.CS2;

        for (index = 0; index < 12; index++)
            this.bassnotes[55][index] = midi.CS2;

        for (index = 0; index < 8; index++)
            this.drumbassnotes[22][index] = midi.C2;

        for (index = 0; index < 8; index++)
            this.drumbassnotes[23][index] = midi.C2;

        for (index = 0; index < 8; index++)
            this.drumbassnotes[24][index] = midi.C2;

        for (index = 0; index < 8; index++)
            this.drumbassnotes[25][index] = midi.G2;

        for (index = 0; index < 8; index++)
            this.drumbassnotes[26][index] = midi.C2;

        for (index = 0; index < 8; index++)
            this.drumbassnotes[27][index] = midi.C2;

        for (index = 0; index < 4; index++)
            this.drumbassnotes[28][index] = midi.GS1;
        for (index = 4; index < 8; index++)
            this.drumbassnotes[28][index] = midi.AS1;

        for (index = 0; index < 8; index++)
            this.drumbassnotes[29][index] = midi.C2;
        for (index = 0; index < 8; index++)
            this.drumbassnotes[30][index] = midi.C2;
        for (index = 0; index < 8; index++)
            this.drumbassnotes[31][index] = midi.C2;
        for (index = 0; index < 8; index++)
            this.drumbassnotes[32][index] = midi.C2;
        for (index = 0; index < 8; index++)
            this.drumbassnotes[33][index] = midi.G2;

        for (index = 0; index < 8; index++)
            this.drumbassnotes[34][index] = midi.C2;
        for (index = 0; index < 8; index++)
            this.drumbassnotes[35][index] = midi.C2;

        for (index = 0; index < 4; index++)
            this.drumbassnotes[36][index] = midi.GS1;
        for (index = 4; index < 8; index++)
            this.drumbassnotes[36][index] = midi.AS1;

        for (index = 0; index < 8; index++)
            this.drumbassnotes[37][index] = midi.C2;

        this.menu();
    },
    keydown: function(ev) {
        console.log("megaman2 keydown");
        console.log(event);
        if (ev.keyCode == 27) {
            this.done();
        }
    },
    done: function() {
        $(".everyoneConsole").html("");
        $(".everyoneConsole").append("Hope Mega Man went well!");
        if (this.onDone != null) {
            this.onDone();
        }
    },

    menu: function() {
        $(".everyoneConsole").html("");
        $(".everyoneConsole").append("Mega Man 2<br/>");
        $(".everyoneConsole").append("Press ESC to quit...");
        $(".everyoneConsole").append("<br/>F1: Start the intro");
        $(".everyoneConsole").append("<br/>F2: Flashman");
        $(".everyoneConsole").append("<br/>F3: Dr. Wily's Castle");
    }
};