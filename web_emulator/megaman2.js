let megaman2 = {
    filename: "MEGAMAN2",
    filesize: "65,012",
    modified: new Date("September 28, 2002 20:00:00"),
    notes: [],
    bassnotes: [],
    drumbassnotes: [],
    onDone: null,
    midiOut: null,
    basschannel: 3,
    drumchannel: 10,
    state: "menu",
    chordchannel: 4,
    flutechannel: 5,
    base: null,
    main: function() {
        var index;
        this.state = "menu";
        base = this;
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

        this.generalMidiSetup();
        this.menu();
    },

    generalMidiSetup: function() {
        midi.program_change(this.basschannel, 36);
        midi.program_change(this.flutechannel, 74);
        midi.program_change(this.chordchannel, 51);
    },

    keydown: function(ev) {
        if (ev.keyCode == 27) {
            this.done();
            return;
        }

        if (this.state == "menu") {
            if (ev.keyCode == keyboard.INDEX_1) {
                this.go(92);
                //this.drums(92);
                this.state = "intro";
                return;
            }
        }

        if (this.state == "intro" || this.state == "menu") {
            this.dobass(ev);
        } else if (this.state == "drums") {
            this.dostuff(ev);
        }
    },
    keyup: function(ev) {
        if (this.state == "intro" || this.state == "menu") {
            this.dobass(ev);
        } else if (this.state == "drums") {
           this.dostuff(ev);   
        }
    },
    done: function() {
        $(".everyoneConsole").html("");
        $(".everyoneConsole").append("Hope Mega Man went well!");
        this.state = "done";
        if (this.onDone != null) {
            this.onDone();
        }
    },

    menu: function() {
        $(".everyoneConsole").html("");
        $(".everyoneConsole").append("Mega Man 2<br/>");
        $(".everyoneConsole").append("Press ESC to quit...");
        $(".everyoneConsole").append("<br/>1: Start the intro");
        //$(".everyoneConsole").append("<br/>2: Flashman");
        //$(".everyoneConsole").append("<br/>3: Dr. Wily's Castle");
    },
    clrscr: function() {
        $(".everyoneConsole").html("");
    },
    cout: function(txt) {       
        $(".everyoneConsole").append(txt);        
    },
    dobass: function(ev) {

        let mapping = [];
        mapping[keyboard.INDEX_SPACE] = 42;
        mapping[keyboard.INDEX_UP] = 41;
        mapping[keyboard.INDEX_RIGHT] = 39;
        mapping[keyboard.INDEX_Y] = 38;
        mapping[keyboard.INDEX_DOWN] = 37;
        mapping[keyboard.INDEX_LEFT] = 36;
        mapping[keyboard.INDEX_N] = 35;
        mapping[keyboard.INDEX_I] = 34;
        mapping[keyboard.INDEX_Q] = 33;
        mapping[keyboard.INDEX_ENTER] = 39;
        mapping[keyboard.INDEX_D] = 44;
        mapping[keyboard.INDEX_V] = 40;
        mapping[keyboard.INDEX_CTRL] = 45;

        if (ev.type == "keydown") {
            console.log("keydown");
            mapping.forEach(function(item, index) {
                if ((base.notes[index] == 0) && (ev.keyCode == index)) {
                    base.notes[index] = 1;
                    midi.play_note(base.basschannel, item, 127);
                }
            });
        } else if (ev.type == "keyup") {
            mapping.forEach(function(item, index) {
                if ((base.notes[index] == 1) && (ev.keyCode == index)) {
                    base.notes[index] = 0;
                    midi.kill_note(base.basschannel, item, 127);
                }
            });
        }

    },

    //***
    go: async function() {
        let = nspeed = 135;
        this.clrscr();

        // change_program(2,9,0); //tinestring
        // change_effects_channel(8);
        // all_lights_off(0);
        // change_light_level(2,127);
        // change_light_level(4,50);

        let measure = 1;
        this.cout("Playing Mega Man 2 intro...");
        let flutelevel = 127;

        this.cout("<br/>Measure " + measure++);
        midi.play_note(this.flutechannel, 82, flutelevel);

        this.cout(" 1 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 2 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 3 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 4 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);

        midi.kill_note(this.flutechannel, 82, flutelevel);

        //Measure 2   
        this.cout("<br/>Measure " + measure++);
        midi.play_note(this.flutechannel, 83, flutelevel);
        this.cout(" 1 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 2 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 3 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 4 ");
        midi.kill_note(this.flutechannel, 83, flutelevel);

        midi.play_note(this.flutechannel, 85, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 85, flutelevel);

        //Measure 3   
        this.cout("<br/>Measure " + measure++);
        midi.play_note(this.flutechannel, 82, flutelevel);
        this.cout(" 1 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 2 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 3 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 4 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);

        midi.kill_note(this.flutechannel, 82, flutelevel);

        //Measure 4   
        this.cout("<br/>Measure " + measure++);
        midi.play_note(this.flutechannel, 83, flutelevel);
        this.cout(" 1 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 2 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 3 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 4 ");
        midi.kill_note(this.flutechannel, 83, flutelevel);

        midi.play_note(this.flutechannel, 85, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 85, flutelevel);

        //Measure 5   
        this.cout("<br/>Measure " + measure++);
        midi.play_note(this.flutechannel, 82, flutelevel);
        this.cout(" 1 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 82, flutelevel);

        midi.play_note(this.flutechannel, 85, flutelevel);
        this.cout(" 2 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 85, flutelevel);

        midi.play_note(this.flutechannel, 92, flutelevel);
        this.cout(" 3 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 92, flutelevel);

        this.cout(" 4 ");
        midi.play_note(this.flutechannel, 89, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 89, flutelevel);

        midi.play_note(this.flutechannel, 90, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);

        //Measure 6
        this.cout("<br/>Measure " + measure++);
        this.cout(" 1 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 90, flutelevel);

        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 2 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);

        midi.play_note(this.flutechannel, 90, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 3 ");
        midi.kill_note(this.flutechannel, 90, flutelevel);

        midi.play_note(this.flutechannel, 89, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 89, flutelevel);

        midi.play_note(this.flutechannel, 87, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 87, flutelevel);
        this.cout(" 4 ");
        midi.play_note(this.flutechannel, 85, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 85, flutelevel);

        midi.play_note(this.flutechannel, 87, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 87, flutelevel);

        //Measure 7   
        this.cout("<br/>Measure " + measure++);
        this.cout(" 1 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.play_note(this.flutechannel, 82, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 82, flutelevel);
        this.cout(" 2 ");
        midi.play_note(this.flutechannel, 80, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 80, flutelevel);

        midi.play_note(this.flutechannel, 78, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 3 ");
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 78, flutelevel);

        await this.delay2(nspeed);

        midi.play_note(this.flutechannel, 78, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 78, flutelevel);
        this.cout(" 4 ");
        midi.play_note(this.flutechannel, 77, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 77, flutelevel);

        midi.play_note(this.flutechannel, 78, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 78, flutelevel);

        //Measure 8   
        this.cout("<br/>Measure " + measure++);
        midi.play_note(this.flutechannel, 85, flutelevel);
        this.cout(" 1 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 2 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 3 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        this.cout(" 4 ");
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);

        midi.kill_note(this.flutechannel, 85, flutelevel);

        //Measure 9   
        this.cout("<br/>Measure " + measure++);
        midi.play_note(this.flutechannel, 87, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 87, flutelevel);

        midi.play_note(this.flutechannel, 85, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 85, flutelevel);

        midi.play_note(this.flutechannel, 83, flutelevel);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        await this.delay2(nspeed);
        midi.kill_note(this.flutechannel, 83, flutelevel);

        //Measure 10   
        this.cout("<br/>Measure " + measure++);
        midi.play_note(this.flutechannel, 89, flutelevel);
        await this.delay2(nspeed * 6);
        midi.kill_note(this.flutechannel, 89, flutelevel);

        midi.play_note(this.flutechannel, 87, flutelevel);
        await this.delay2(nspeed * 6);
        midi.kill_note(this.flutechannel, 87, flutelevel);

        midi.play_note(this.flutechannel, 85, flutelevel);
        await this.delay2(nspeed * 4);
        midi.kill_note(this.flutechannel, 85, flutelevel);

        //Measure 11   
        this.cout("<br/>Measure " + measure++);
        midi.play_note(this.flutechannel, 89, flutelevel);
        await this.delay2(nspeed * 6);
        midi.kill_note(this.flutechannel, 89, flutelevel);

        midi.play_note(this.flutechannel, 87, flutelevel);
        await this.delay2(nspeed * 6);
        midi.kill_note(this.flutechannel, 87, flutelevel);

        midi.play_note(this.flutechannel, 86, flutelevel);
        await this.delay2(nspeed * 4);
        midi.kill_note(this.flutechannel, 86, flutelevel);

        //Measure 12   
        this.cout("<br/>Measure " + measure++);
        midi.play_note(this.flutechannel, 90, flutelevel);
        await this.delay2(nspeed * 6);
        midi.kill_note(this.flutechannel, 90, flutelevel);

        midi.play_note(this.flutechannel, 89, flutelevel);
        await this.delay2(nspeed * 6);
        midi.kill_note(this.flutechannel, 89, flutelevel);

        midi.play_note(this.flutechannel, 87, flutelevel);
        await this.delay2(nspeed * 4);
        midi.kill_note(this.flutechannel, 87, flutelevel);

        //Measure 13   
        this.cout("<br/>Measure " + measure++);
        midi.play_note(this.flutechannel, 90, flutelevel);
        await this.delay2(nspeed * 9);
        midi.kill_note(this.flutechannel, 90, flutelevel);

        nspeed = 110;
        midi.play_note(this.flutechannel, midi.A4, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.A4, flutelevel);

        midi.play_note(this.flutechannel, midi.B4, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.B4, flutelevel);

        midi.play_note(this.flutechannel, midi.CS5, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.CS5, flutelevel);

        midi.play_note(this.flutechannel, midi.D5, flutelevel);
        await this.delay2(nspeed * 4);
        midi.kill_note(this.flutechannel, midi.D5, flutelevel);

        midi.play_note(this.flutechannel, midi.D5, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.D5, flutelevel);

        midi.play_note(this.flutechannel, midi.D5, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.D5, flutelevel);

        midi.play_note(this.flutechannel, midi.CS5, flutelevel);
        await this.delay2(nspeed * 4);
        midi.kill_note(this.flutechannel, midi.CS5, flutelevel);

        midi.play_note(this.flutechannel, midi.D5, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.D5, flutelevel);

        midi.play_note(this.flutechannel, midi.B4, flutelevel);
        await this.delay2(nspeed * 10);
        midi.kill_note(this.flutechannel, midi.B4, flutelevel);

        midi.play_note(this.flutechannel, midi.B4, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.B4, flutelevel);

        midi.play_note(this.flutechannel, midi.GS4, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.GS4, flutelevel);

        midi.play_note(this.flutechannel, midi.B4, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.B4, flutelevel);

        midi.play_note(this.flutechannel, midi.E5, flutelevel);
        await this.delay2(nspeed * 4);
        midi.kill_note(this.flutechannel, midi.E5, flutelevel);

        midi.play_note(this.flutechannel, midi.D5, flutelevel);
        await this.delay2(nspeed * 4);
        midi.kill_note(this.flutechannel, midi.D5, flutelevel);

        midi.play_note(this.flutechannel, midi.CS5, flutelevel);
        await this.delay2(nspeed * 4);
        midi.kill_note(this.flutechannel, midi.CS5, flutelevel);

        midi.play_note(this.flutechannel, midi.B4, flutelevel);
        await this.delay2(nspeed * 4);
        midi.kill_note(this.flutechannel, midi.B4, flutelevel);

        midi.play_note(this.flutechannel, midi.C5, flutelevel);
        await this.delay2(nspeed * 6);
        midi.kill_note(this.flutechannel, midi.C5, flutelevel);

        midi.play_note(this.flutechannel, midi.C5, flutelevel);
        await this.delay2(nspeed * 1);
        midi.kill_note(this.flutechannel, midi.C5, flutelevel);

        midi.play_note(this.flutechannel, midi.C5, flutelevel);
        await this.delay2(nspeed * 1);
        midi.kill_note(this.flutechannel, midi.C5, flutelevel);

        midi.play_note(this.flutechannel, midi.C5, flutelevel);
        await this.delay2(nspeed * 3);
        midi.kill_note(this.flutechannel, midi.C5, flutelevel);

        midi.play_note(this.flutechannel, midi.B4, flutelevel);
        await this.delay2(nspeed * 3);
        midi.kill_note(this.flutechannel, midi.B4, flutelevel);

        midi.play_note(this.flutechannel, midi.C5, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.C5, flutelevel);

        midi.play_note(this.flutechannel, midi.A4, flutelevel);
        await this.delay2(nspeed * 6);
        midi.kill_note(this.flutechannel, midi.A4, flutelevel);

        midi.play_note(this.flutechannel, midi.A4, flutelevel);
        await this.delay2(nspeed * 1);
        midi.kill_note(this.flutechannel, midi.A4, flutelevel);

        midi.play_note(this.flutechannel, midi.A4, flutelevel);
        await this.delay2(nspeed * 1);
        midi.kill_note(this.flutechannel, midi.A4, flutelevel);

        await this.delay2(nspeed * 1);

        midi.play_note(this.flutechannel, midi.A4, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.A4, flutelevel);

        midi.play_note(this.flutechannel, midi.B4, flutelevel);
        await this.delay2(nspeed * 3);
        midi.kill_note(this.flutechannel, midi.B4, flutelevel);

        midi.play_note(this.flutechannel, midi.C5, flutelevel);
        await this.delay2(nspeed * 2);
        midi.kill_note(this.flutechannel, midi.C5, flutelevel);

        midi.play_note(this.flutechannel, midi.D5, flutelevel);
        await this.delay2(nspeed * 16);
        midi.kill_note(this.flutechannel, midi.D5, flutelevel);
        await this.delay2(nspeed * 2);
        this.cout("<br/>LET GO");
        this.drums(92);
    },

    //DRUMS!   
    drums: async function(speed) {
        this.state = "drums";
        this.clrscr();
        let basslevel = 127;
        this.cout("Drum mode activated!");
        this.cout("<br/>SPACE returns to Bass Blaster Mode!");

        let measure = 21; //old = 21
        for (index = 0; index < 127; index++)
            this.notes[index] = 0;

        let count = 0;

        while (1) {
            if ((count == 1) && (measure == 35))
                break;

            //Begin measure
            if (measure == 46) {
                measure = 21;
                count++;
            }
            if (measure == 35) {
                // change_light_level(1,50);
                // change_light_level(2,75);
                // change_light_level(3,25);
                // change_light_level(3,50);
                // change_light_level(9,0);

                this.cout("<br/>Measure: " + ++measure + " (pre solo 1)");
                midi.play_note(this.basschannel, midi.GS1, 127);
                midi.play_note(this.drumchannel, midi.D2, 127);
                midi.play_note(this.drumchannel, midi.E1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.D2, 127);
                midi.kill_note(this.drumchannel, midi.E1, 127);
                midi.kill_note(this.basschannel, midi.GS1, 127);
                midi.play_note(this.basschannel, midi.GS1, 127);
                midi.play_note(this.drumchannel, midi.C2, 127);
                midi.play_note(this.drumchannel, midi.E1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.C2, 127);
                midi.kill_note(this.drumchannel, midi.E1, 127);
                midi.kill_note(this.basschannel, midi.GS1, 127);
                midi.play_note(this.basschannel, midi.GS1, 127);
                midi.play_note(this.drumchannel, midi.B1, 127);
                midi.play_note(this.drumchannel, midi.E1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.B1, 127);
                midi.kill_note(this.drumchannel, midi.E1, 127);
                midi.kill_note(this.basschannel, midi.GS1, 127);
                midi.play_note(this.basschannel, midi.GS1, 127);
                midi.play_note(this.drumchannel, midi.E1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.E1, 127);
                midi.kill_note(this.basschannel, midi.GS1, 127);
                midi.play_note(this.basschannel, midi.AS1, 127);
                midi.play_note(this.drumchannel, midi.A2, 127);
                midi.play_note(this.drumchannel, midi.E1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.AS1, 127);
                midi.kill_note(this.drumchannel, midi.A2, 127);
                midi.kill_note(this.drumchannel, midi.E1, 127);
                midi.play_note(this.basschannel, midi.AS1, 127);

                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.AS1, 127);
                midi.play_note(this.basschannel, midi.AS1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.AS1, 127);
                midi.play_note(this.basschannel, midi.AS1, 127);
                midi.play_note(this.drumchannel, midi.E1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.AS1, 127);
                midi.kill_note(this.drumchannel, midi.E1, 127);
            } else
            if (measure == 36) {
                this.cout("<br/>Measure: " + ++measure + " (pre solo 2)");
                midi.play_note(this.basschannel, midi.C2, 127);
                midi.play_note(this.drumchannel, midi.DS1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.C2, 127);
                midi.play_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.DS1, 127);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.play_note(this.drumchannel, midi.DS1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.basschannel, midi.C2, 127);
                midi.play_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.C2, 127);
                midi.play_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.DS1, 127);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.play_note(this.drumchannel, midi.DS1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.basschannel, midi.C2, 127);
                midi.play_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.C2, 127);
                midi.play_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.DS1, 127);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.play_note(this.drumchannel, midi.DS1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.basschannel, midi.C2, 127);
                midi.play_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.C2, 127);
                midi.play_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.DS1, 127);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.basschannel, midi.C2, 127);
            } else
            if ((measure == 37) || (measure == 38)) {
                //Measures 38 and 39
                this.cout("<br/>Measure: " + ++measure);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                midi.play_note(this.drumchannel, midi.G1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.drumchannel, midi.G1, 127);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.C2, 127);
                midi.play_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.drumchannel, midi.G1, 127);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                midi.kill_note(this.drumchannel, midi.G1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.C2, 127);
                await this.delay1(speed);
            } else
            if ((measure == 39) || (measure == 40)) {
                this.cout("<br/>Measure: " + ++measure);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.basschannel, midi.AS1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.AS1, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                midi.play_note(this.drumchannel, midi.G1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.drumchannel, midi.G1, 127);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.basschannel, midi.AS1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.AS1, 127);
                midi.play_note(this.basschannel, midi.AS1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.drumchannel, midi.G1, 127);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.AS1, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                midi.kill_note(this.drumchannel, midi.G1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.basschannel, midi.AS1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.AS1, 127);
                await this.delay1(speed);
            } else
            if ((measure == 41) || (measure == 42)) {
                this.cout("<br/>Measure: " + ++measure);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.basschannel, midi.A1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.A1, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                midi.play_note(this.drumchannel, midi.G1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.drumchannel, midi.G1, 127);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.basschannel, midi.A1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.A1, 127);
                midi.play_note(this.basschannel, midi.A1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.drumchannel, midi.G1, 127);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.A1, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                midi.kill_note(this.drumchannel, midi.G1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.basschannel, midi.A1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.A1, 127);
                await this.delay1(speed);
            } else
            if ((measure == 43)) {
                this.cout("<br/>Measure: " + ++measure);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.basschannel, midi.GS2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.GS2, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                midi.play_note(this.drumchannel, midi.G1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.drumchannel, midi.G1, 127);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.basschannel, midi.GS2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.GS2, 127);
                midi.play_note(this.basschannel, midi.GS2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.drumchannel, midi.G1, 127);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.GS2, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                midi.kill_note(this.drumchannel, midi.G1, 127);
                midi.play_note(this.drumchannel, midi.C1, 127);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.basschannel, midi.GS2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.C1, 127);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.GS2, 127);
                await this.delay1(speed);
            } else
            if ((measure == 44)) // end?
            {
                this.cout("<br/>Measure: " + ++measure);
            } else
            if ((measure == 45)) {
                this.cout("<br/>Measure: " + ++measure);
                midi.play_note(this.basschannel, midi.GS2, 127);
                midi.play_note(this.drumchannel, midi.D2, 127);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.D1, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.D2, 127);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.kill_note(this.drumchannel, midi.D1, 127);
                midi.play_note(this.drumchannel, midi.D1, 127);
                midi.play_note(this.drumchannel, midi.C2, 127);

                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.GS2, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.D1, 127);
                midi.kill_note(this.drumchannel, midi.C2, 127);
                midi.play_note(this.drumchannel, midi.D1, 127);
                midi.play_note(this.drumchannel, midi.C2, 127);
                midi.play_note(this.drumchannel, midi.G1, 127);
                midi.play_note(this.drumchannel, midi.B1, 127);
                midi.play_note(this.drumchannel, midi.DS2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.D1, 127);
                midi.kill_note(this.drumchannel, midi.C2, 127);
                midi.kill_note(this.drumchannel, midi.G1, 127);
                midi.kill_note(this.drumchannel, midi.B1, 127);
                midi.kill_note(this.drumchannel, midi.DS2, 127);
                midi.play_note(this.drumchannel, midi.F1, 127);
                midi.play_note(this.drumchannel, midi.A1, 127);
                midi.play_note(this.basschannel, midi.GS2, 127);
                await this.delay1(speed);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.GS2, 127);
                midi.play_note(this.basschannel, midi.GS2, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.F1, 127);
                midi.kill_note(this.drumchannel, midi.A1, 127);
                await this.delay1(speed);
                midi.play_note(this.drumchannel, midi.A2, 127);
                midi.play_note(this.drumchannel, midi.E1, 127);
                midi.play_note(this.drumchannel, midi.D1, 127);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, midi.GS2, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.A2, 127);
                midi.kill_note(this.drumchannel, midi.E1, 127);
                midi.kill_note(this.drumchannel, midi.D1, 127);
                midi.play_note(this.drumchannel, midi.B0, 127);
                midi.play_note(this.drumchannel, midi.D1, 127);
                midi.play_note(this.drumchannel, midi.FS1, 127);
                midi.play_note(this.basschannel, midi.AS2, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.B0, 127);
                midi.kill_note(this.drumchannel, midi.D1, 127);
                midi.kill_note(this.drumchannel, midi.FS1, 127);
                midi.play_note(this.drumchannel, midi.FS1, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.FS1, 127);
                midi.play_note(this.drumchannel, midi.FS1, 127);
                midi.play_note(this.drumchannel, midi.D1, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.FS1, 127);
                midi.kill_note(this.drumchannel, midi.D1, 127);
                midi.play_note(this.drumchannel, midi.FS1, 127);
                midi.kill_note(this.basschannel, midi.AS2, 127);
                await this.delay1(speed);
                midi.kill_note(this.drumchannel, midi.FS1, 127);
                this.cout("  end of measure 45");
                // change_light_level(9,127);
                // change_light_level(1,0);
                // change_light_level(2,0);
                // change_light_level(3,0);
                // change_light_level(4,0);
            } else //!!else  (main thing)
            {
                this.cout("<br/>Measure: " + ++measure + " !!else");
                if (((count == 0) && (measure == 22)) || (measure == 30))
                    midi.play_note(this.drumchannel, midi.CS2, 127);

                midi.play_note(10, 36, 127);
                midi.play_note(10, 42, 127);
                midi.play_note(this.basschannel, this.drumbassnotes[measure][0], basslevel);
                await this.delay1(speed);
                midi.kill_note(10, 36, 127);
                midi.kill_note(10, 42, 127);
                midi.play_note(10, 42, 127);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, this.drumbassnotes[measure][0], basslevel);
                midi.play_note(this.basschannel, this.drumbassnotes[measure][1], basslevel);
                midi.kill_note(10, 42, 127);
                midi.play_note(10, 42, 127);
                await this.delay1(speed);
                midi.kill_note(10, 42, 127);
                midi.play_note(10, 42, 127);
                await this.delay1(speed);
                midi.kill_note(10, 42, 127);
                midi.kill_note(this.basschannel, this.drumbassnotes[measure][1], basslevel);

                midi.play_note(10, 36, 127);
                midi.play_note(10, 42, 127);
                midi.play_note(this.basschannel, this.drumbassnotes[measure][2], basslevel);
                await this.delay1(speed);
                midi.kill_note(10, 36, 127);
                midi.kill_note(10, 42, 127);
                midi.play_note(10, 42, 127);
                await this.delay1(speed);
                midi.kill_note(this.basschannel, this.drumbassnotes[measure][2], basslevel);
                midi.play_note(this.basschannel, this.drumbassnotes[measure][3], basslevel);
                midi.kill_note(10, 42, 127);
                midi.play_note(10, 42, 127);
                await this.delay1(speed);
                midi.kill_note(10, 42, 127);
                midi.play_note(10, 42, 127);
                await this.delay1(speed);
                midi.kill_note(10, 42, 127);
                midi.kill_note(this.basschannel, this.drumbassnotes[measure][3], basslevel);

                midi.play_note(10, 36, 127);
                midi.play_note(10, 42, 127);
                midi.play_note(this.basschannel, this.drumbassnotes[measure][4], basslevel);
                if (measure == 29)
                    midi.play_note(this.drumchannel, midi.D2, 127);
                await this.delay1(speed);
                if (measure == 29)
                    midi.kill_note(this.drumchannel, midi.D2, 127);
                midi.kill_note(10, 36, 127);
                midi.kill_note(10, 42, 127);
                midi.play_note(10, 42, 127);
                if (measure == 29)
                    midi.play_note(this.drumchannel, midi.C2, 127);
                await this.delay1(speed);
                if (measure == 29)
                    midi.kill_note(this.drumchannel, midi.C2, 127);
                midi.kill_note(this.basschannel, this.drumbassnotes[measure][4], basslevel);
                midi.play_note(this.basschannel, this.drumbassnotes[measure][5], basslevel);
                midi.kill_note(10, 42, 127);
                midi.play_note(10, 42, 127);
                if (measure == 29)
                    midi.play_note(this.drumchannel, midi.B1, 127);
                await this.delay1(speed);
                if (measure == 29)
                    midi.kill_note(this.drumchannel, midi.B1, 127);
                midi.kill_note(10, 42, 127);
                midi.play_note(10, 42, 127);
                if (measure == 29)
                    midi.play_note(this.drumchannel, midi.A1, 127);
                await this.delay1(speed);
                if (measure == 29)
                    midi.kill_note(this.drumchannel, midi.A1, 127);
                midi.kill_note(10, 42, 127);
                midi.kill_note(this.basschannel, this.drumbassnotes[measure][5], basslevel);

                midi.play_note(10, 36, 127);
                midi.play_note(10, 42, 127);
                midi.play_note(this.basschannel, this.drumbassnotes[measure][6], basslevel);
                if (measure == 29)
                    midi.play_note(this.drumchannel, midi.C2, 127);
                await this.delay1(speed);
                if (measure == 29)
                    midi.kill_note(this.drumchannel, midi.C2, 127);
                midi.kill_note(10, 36, 127);
                midi.kill_note(10, 42, 127);
                midi.play_note(10, 42, 127);
                if (measure == 29)
                    midi.play_note(this.drumchannel, midi.B1, 127);
                await this.delay1(speed);
                if (measure == 29)
                    midi.kill_note(this.drumchannel, midi.B1, 127);
                midi.kill_note(this.basschannel, this.drumbassnotes[measure][6], basslevel);
                midi.play_note(this.basschannel, this.drumbassnotes[measure][7], basslevel);
                midi.kill_note(10, 42, 127);
                midi.play_note(10, 42, 127);
                if (measure == 29)
                    midi.play_note(this.drumchannel, midi.A1, 127);
                await this.delay1(speed);
                if (measure == 29)
                    midi.kill_note(this.drumchannel, midi.A1, 127);

                midi.kill_note(10, 42, 127);

                midi.play_note(10, 42, 127);
                if (measure == 29)
                    midi.play_note(this.drumchannel, midi.G1, 127);
                await this.delay1(speed);
                if (measure == 29)
                    midi.kill_note(this.drumchannel, midi.G1, 127);
                midi.kill_note(10, 42, 127);
                midi.kill_note(this.basschannel, this.drumbassnotes[measure][7], basslevel);


                if ((measure == 22) || (measure == 30))
                    midi.kill_note(this.drumchannel, midi.CS2, 127);
            }
        }

        for (index = 0; index < 1; index++) {
            midi.kill_note(10, 54, 127);
            // change_light_level(9,0);
            // change_light_level(1,50);
            // change_light_level(2,75);
            // change_light_level(3,25);
            // change_light_level(4,50);
            //measure one of end
            midi.play_note(10, midi.D2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.G1, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.D2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.G1, 127);
            midi.play_note(10, midi.C2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.G1, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.C2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.G1, 127);
            midi.play_note(10, midi.B2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.A1, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.B2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.A1, 127);
            midi.play_note(10, midi.A2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.C2, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.A2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.C2, 127);
            await this.delay1(speed);

            midi.play_note(10, midi.C2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.G1, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.C2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.G1, 127);
            midi.play_note(10, midi.B2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.A1, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.B2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.A1, 127);
            midi.play_note(10, midi.A2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.C2, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.A2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.C2, 127);
            await this.delay1(speed);

            midi.play_note(10, midi.C2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.G1, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.C2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.G1, 127);
            midi.play_note(10, midi.B2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.A1, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.B2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.A1, 127);
            midi.play_note(10, midi.A2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.C2, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.A2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.C2, 127);
            await this.delay1(speed);

            midi.play_note(10, midi.C2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.G2, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.C2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.G2, 127);
            midi.play_note(10, midi.B2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.A2, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.B2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.A2, 127);
            midi.play_note(10, midi.A2, 127);
            midi.play_note(10, midi.D1, 127);
            midi.play_note(this.basschannel, midi.C3, 127);
            midi.play_note(10, midi.CS1, 127);
            await this.delay1(speed);
            await this.delay1(speed);
            await this.delay1(speed);
            midi.kill_note(10, midi.CS1, 127);
            midi.kill_note(10, midi.A2, 127);
            midi.kill_note(10, midi.D1, 127);
            midi.kill_note(this.basschannel, midi.C3, 127);
            await this.delay1(speed);

        }

        //wait_for_no(INDEX_SPACE);
        //change_program(2,9,0);   
        this.menu();
    },
    //END DRUMS    
    delay2: function(ms) {
        if (this.state == "done") {
            ms = 0;
        }
        return new Promise(resolve => setTimeout(resolve, ms));
    },
    delay1: function(ms) {
        if (this.state == "done") {
            ms = 0;
        }
        return new Promise(resolve => setTimeout(resolve, ms));
    },

    dostuff: function(ev) {
        let chords = [];
        chords[keyboard.INDEX_1] = [72, 67, 63, 60];
        chords[keyboard.INDEX_2] = [70, 65, 62, 58];
        chords[keyboard.INDEX_3] = [68, 63, 60, 56];
        chords[keyboard.INDEX_4] = [67, 62, 59, 55];
        chords[keyboard.INDEX_5] = [72, 67, 64, 60];

        if (ev.type == "keydown") {
            chords.forEach(function(item, index) {
                if ((base.notes[index] == 0) && (ev.keyCode == index)) {
                    base.notes[index] = 1;
                    for (var i = 0; i < item.length; i++) {
                        midi.play_note(base.chordchannel, item[i], 127);
                    }
                }
            });
        } else if (ev.type == "keyup") {
            chords.forEach(function(item, index) {
                if ((base.notes[index] == 1) && (ev.keyCode == index)) {
                    base.notes[index] = 0;
                    for (var i = 0; i < item.length; i++) {
                        midi.kill_note(base.chordchannel, item[i], 127);
                    }
                }
            });
        }


    }
};