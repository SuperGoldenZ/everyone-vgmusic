let megaman2 = {
    filename: "MEGAMAN2",
    filesize: "65,012",
    modified: new Date("September 28, 2002 20:00:00"),
    notes: [],
    bassnotes: [],
    drumbassnotes: [],
    onDone: null,
    midiOut: null,
    cleanBassChannel: 3,
    drumChannel: 10,
    state: "menu",
    flutechannel : 5,
    main: function() {
        var index;
        this.state = "menu";
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
        midi.program_change(this.cleanBassChannel, 36);
        //midi.program_change(this.drumChannel, 127);
    },

    keydown: function(ev) {
	            if (ev.keyCode == 27) {
                this.done();
                return;
            }

        if (this.state == "menu") {

            if (ev.keyCode == keyboard.INDEX_1) {
                this.go();
                this.state = "intro";
                return;
            }

            
        }

        if (this.state == "intro" || this.state == "menu") {
        	this.dobass(ev);
        }
    },
    keyup: function(ev) {
        this.dobass(ev);
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
        $(".everyoneConsole").append("<br/>1: Start the intro");
        $(".everyoneConsole").append("<br/>2: Flashman");
        $(".everyoneConsole").append("<br/>3: Dr. Wily's Castle");
    },
    clrscr: function () {
		$(".everyoneConsole").html("");
    },
    cout : function (txt) {
		$(".everyoneConsole").append(txt);
    },
    dobass: function(ev) {
        if (ev.type == "keydown") {
            console.log("keydown");

            if ((this.notes[keyboard.INDEX_SPACE] == 0) && (ev.keyCode == keyboard.INDEX_SPACE)) {
                this.notes[keyboard.INDEX_SPACE] = 1;
                midi.play_note(this.cleanBassChannel, 42, 127);
            }
        } else if (ev.type == "keyup") {
            if ((this.notes[keyboard.INDEX_SPACE] == 1) && (ev.keyCode == keyboard.INDEX_SPACE)) {
                midi.kill_note(this.cleanBassChannel, 42, 127);
                this.notes[keyboard.INDEX_SPACE] = 0;
            }
        }


        // if ((this.notes[keyboard.INDEX_UP] == 0) && (keyboard.key_table[keyboard.INDEX_UP]==1))   
        // {   
        //   this.notes[keyboard.INDEX_UP]=1;   
        //   play_note(3,41,127);   
        // }   
        // if ((this.notes[keyboard.INDEX_UP] == 1) && (keyboard.key_table[keyboard.INDEX_UP]==0))   
        // {   
        //   kill_note(3,41,127);   
        //   this.notes[keyboard.INDEX_UP]=0;   
        // }   

        // if ((this.notes[keyboard.INDEX_RIGHT] == 0) && (keyboard.key_table[keyboard.INDEX_RIGHT]==1))   
        // {   
        //   this.notes[keyboard.INDEX_RIGHT]=1;   
        //   play_note(3,39,127);   
        // }   
        // if ((this.notes[keyboard.INDEX_RIGHT] == 1) && (keyboard.key_table[keyboard.INDEX_RIGHT]==0))   
        // {   
        //   kill_note(3,39,127);   
        //   this.notes[keyboard.INDEX_RIGHT]=0;   
        // }   

        // if ((this.notes[keyboard.INDEX_Y] == 0) && (keyboard.key_table[keyboard.INDEX_Y]==1))   
        // {   
        //   this.notes[keyboard.INDEX_Y]=1;   
        //   play_note(3,38,127);   
        // }   
        // if ((this.notes[keyboard.INDEX_Y] == 1) && (keyboard.key_table[keyboard.INDEX_Y]==0))   
        // {   
        //   kill_note(3,38,127);   
        //   this.notes[keyboard.INDEX_Y]=0;   
        // }   

        // if ((this.notes[keyboard.INDEX_DOWN] == 0) && (keyboard.key_table[keyboard.INDEX_DOWN]==1))   
        // {   
        //   this.notes[keyboard.INDEX_DOWN]=1;   
        //   play_note(3,37,127);   
        // }   
        // if ((this.notes[keyboard.INDEX_DOWN] == 1) && (keyboard.key_table[keyboard.INDEX_DOWN]==0))   
        // {   
        //   kill_note(3,37,127);   
        //   this.notes[keyboard.INDEX_DOWN]=0;   
        // }   

        // if ((this.notes[keyboard.INDEX_LEFT] == 0) && (keyboard.key_table[keyboard.INDEX_LEFT]==1))   
        // {   
        //   this.notes[keyboard.INDEX_LEFT]=1;   
        //   play_note(3,36,127);   
        // }   
        // if ((this.notes[keyboard.INDEX_LEFT] == 1) && (keyboard.key_table[keyboard.INDEX_LEFT]==0))   
        // {   
        //   kill_note(3,36,127);   
        //   this.notes[keyboard.INDEX_LEFT]=0;   
        // }   

        // if ((this.notes[keyboard.INDEX_N] == 0) && (keyboard.key_table[keyboard.INDEX_N]==1))   
        // {   
        //   this.notes[keyboard.INDEX_N]=1;   
        //   play_note(3,35,127);   
        // }   

        // if ((this.notes[keyboard.INDEX_N] == 1) && (keyboard.key_table[keyboard.INDEX_N]==0))   
        // {   
        //   kill_note(3,35,127);   
        //   this.notes[keyboard.INDEX_N]=0;   
        // }   

        // if ((this.notes[keyboard.INDEX_I] == 0) && (keyboard.key_table[keyboard.INDEX_I]==1))   
        // {   
        //   this.notes[keyboard.INDEX_I]=1;   
        //   play_note(3,34,127);   
        // }   
        // if ((this.notes[keyboard.INDEX_I] == 1) && (keyboard.key_table[keyboard.INDEX_I]==0))   
        // {   
        //   kill_note(3,34,127);   
        //   this.notes[keyboard.INDEX_I]=0;   
        // }   

        // if ((this.notes[keyboard.INDEX_ENTER] == 0) && (keyboard.key_table[keyboard.INDEX_ENTER]==1))   
        // {   
        //   this.notes[keyboard.INDEX_ENTER]=1;   
        //   play_note(3,39,127);   
        // }   
        // if ((this.notes[keyboard.INDEX_ENTER] == 1) && (keyboard.key_table[keyboard.INDEX_ENTER]==0))   
        // {   
        //   kill_note(3,39,127);   
        //   this.notes[keyboard.INDEX_ENTER]=0;   
        // }   

        // //old 33
        // if ((this.notes[keyboard.INDEX_Q] == 0) && (keyboard.key_table[keyboard.INDEX_Q]==1))
        // {   
        //   this.notes[keyboard.INDEX_Q]=1;   
        //   play_note(3,33,127);   
        // }   
        // if ((this.notes[keyboard.INDEX_Q] == 1) && (keyboard.key_table[keyboard.INDEX_Q]==0))   
        // {   
        //   kill_note(3,33,127);   
        //   this.notes[keyboard.INDEX_Q]=0;   
        // }   

        // if ((this.notes[keyboard.INDEX_D] == 0) && (keyboard.key_table[keyboard.INDEX_D]==1))   
        // {   
        //   this.notes[keyboard.INDEX_D]=1;   
        //   play_note(3,44,127);   
        // }   
        // if ((this.notes[keyboard.INDEX_D] == 1) && (keyboard.key_table[keyboard.INDEX_D]==0))   
        // {   
        //   kill_note(3,44,127);   
        //   this.notes[keyboard.INDEX_D]=0;   
        // }   

        // if ((this.notes[keyboard.INDEX_V] == 0) && (keyboard.key_table[keyboard.INDEX_V]==1))   
        // {   
        //   this.notes[keyboard.INDEX_V]=1;   
        //   play_note(3,40,127);   
        // }   
        // if ((this.notes[keyboard.INDEX_V] == 1) && (keyboard.key_table[keyboard.INDEX_V]==0))   
        // {   
        //   kill_note(3,40,127);   
        //   this.notes[keyboard.INDEX_V]=0;   
        // }   

        // if ((this.notes[keyboard.INDEX_CTRL] == 0) && (keyboard.key_table[keyboard.INDEX_CTRL]==1))   
        // {   
        //   this.notes[keyboard.INDEX_CTRL]=1;   
        //   play_note(3,45,127);   
        // }   
        // if ((this.notes[keyboard.INDEX_CTRL] == 1) && (keyboard.key_table[keyboard.INDEX_CTRL]==0))   
        // {   
        //   kill_note(3,45,127);   
        //   this.notes[keyboard.INDEX_CTRL]=0;   
        // }   
    },

    //***
    go: async function ()
    {
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
     midi.play_note(this.flutechannel,82,flutelevel);   
     
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

     midi.kill_note(this.flutechannel,82,flutelevel);
   
     //Measure 2   
     this.cout("<br/>Measure " + measure++);   
     midi.play_note(this.flutechannel,83,flutelevel);   
     this.cout(" 1 " );
     await this.delay2(nspeed);
     await this.delay2(nspeed);   
     await this.delay2(nspeed);   
     await this.delay2(nspeed);   
     this.cout(" 2 " );
     await this.delay2(nspeed);
     await this.delay2(nspeed);   
     await this.delay2(nspeed);   
     await this.delay2(nspeed);   
     this.cout(" 3 " );
     await this.delay2(nspeed);
     await this.delay2(nspeed);   
     await this.delay2(nspeed);   
     await this.delay2(nspeed);   
     this.cout(" 4 " );
     midi.kill_note(this.flutechannel,83,flutelevel);
   
     midi.play_note(this.flutechannel,85,flutelevel);   
     await this.delay2(nspeed);   
     await this.delay2(nspeed);   
     await this.delay2(nspeed);   
     await this.delay2(nspeed);   
     midi.kill_note(this.flutechannel,85,flutelevel);
   
     //Measure 3   
     this.cout("<br/>Measure " + measure++);   
     midi.play_note(this.flutechannel,82,flutelevel);   
     this.cout(" 1 " );
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     this.cout(" 2 " );
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     this.cout(" 3 " );
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     this.cout(" 4 " );
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   

     kill_note(this.flutechannel,82,flutelevel);
   
     //Measure 4   
     this.cout("<br/>Measure " + measure++);   
     midi.play_note(this.flutechannel,83,flutelevel);   
     this.cout(" 1 " );
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     this.cout(" 2 " );
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     this.cout(" 3 " );
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     this.cout(" 4 " );
     kill_note(this.flutechannel,83,flutelevel);
   
     midi.play_note(this.flutechannel,85,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,85,flutelevel);
   
     //Measure 5   
     this.cout("<br/>Measure " + measure++);   
     midi.play_note(this.flutechannel,82,flutelevel);   
     this.cout(" 1 " );
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,82,flutelevel);
   
     midi.play_note(this.flutechannel,85,flutelevel);   
     this.cout(" 2 " );
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,85,flutelevel);
   
     midi.play_note(this.flutechannel,92,flutelevel);   
     this.cout(" 3 " );
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,92,flutelevel);
   
     this.cout(" 4 " );
     midi.play_note(this.flutechannel,89,flutelevel);
     delay2(nspeed);
     delay2(nspeed);   
     kill_note(this.flutechannel,89,flutelevel);
   
     midi.play_note(this.flutechannel,90,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);      

     //Measure 6
     this.cout("<br/>Measure " + measure++);   
     this.cout(" 1 " );
     delay2(nspeed);
     delay2(nspeed);   
     kill_note(this.flutechannel,90,flutelevel);
   
     delay2(nspeed);        
     delay2(nspeed);           
     this.cout(" 2 " );
     delay2(nspeed);
     delay2(nspeed);        

     midi.play_note(this.flutechannel,90,flutelevel);
     delay2(nspeed);   
     delay2(nspeed);   
     this.cout(" 3 " );
     kill_note(this.flutechannel,90,flutelevel);
        
     midi.play_note(this.flutechannel,89,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,89,flutelevel);
   
     midi.play_note(this.flutechannel,87,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,87,flutelevel);
     this.cout(" 4 " );   
     midi.play_note(this.flutechannel,85,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,85,flutelevel);
        
     midi.play_note(this.flutechannel,87,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,87,flutelevel);
   
     //Measure 7   
     this.cout("<br/>Measure " + measure++);   
     this.cout(" 1 " );   
     delay2(nspeed);
     delay2(nspeed);      
     midi.play_note(this.flutechannel,82,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,82,flutelevel);
     this.cout(" 2 " );      
     midi.play_note(this.flutechannel,80,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,80,flutelevel);
   
     midi.play_note(this.flutechannel,78,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     this.cout(" 3 " );   
     delay2(nspeed);
     kill_note(this.flutechannel,78,flutelevel);
   
     delay2(nspeed);   
   
     midi.play_note(this.flutechannel,78,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,78,flutelevel);
     this.cout(" 4 " );      
     midi.play_note(this.flutechannel,77,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,77,flutelevel);
   
     midi.play_note(this.flutechannel,78,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,78,flutelevel);
   
     //Measure 8   
     this.cout("<br/>Measure " + measure++);   
     midi.play_note(this.flutechannel,85,flutelevel);   
     this.cout(" 1 " );      
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     this.cout(" 2 " );      
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     this.cout(" 3 " );      
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     this.cout(" 4 " );      
     delay2(nspeed);
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   

     kill_note(this.flutechannel,85,flutelevel);
   
     //Measure 9   
     this.cout("<br/>Measure " + measure++);   
     midi.play_note(this.flutechannel,87,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,87,flutelevel);
   
     midi.play_note(this.flutechannel,85,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,85,flutelevel);   
   
     midi.play_note(this.flutechannel,83,flutelevel);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     delay2(nspeed);   
     kill_note(this.flutechannel,83,flutelevel);
   
     //Measure 10   
     this.cout("<br/>Measure " + measure++);   
     midi.play_note(this.flutechannel,89,flutelevel);   
     delay2(nspeed*6);   
     kill_note(this.flutechannel,89,flutelevel);   
   
     midi.play_note(this.flutechannel,87,flutelevel);   
     delay2(nspeed*6);   
     kill_note(this.flutechannel,87,flutelevel);   
   
     midi.play_note(this.flutechannel,85,flutelevel);   
     delay2(nspeed*4);   
     kill_note(this.flutechannel,85,flutelevel);   
   
     //Measure 11   
     this.cout("<br/>Measure " + measure++);   
     midi.play_note(this.flutechannel,89,flutelevel);   
     delay2(nspeed*6);   
     kill_note(this.flutechannel,89,flutelevel);   
   
     midi.play_note(this.flutechannel,87,flutelevel);   
     delay2(nspeed*6);   
     kill_note(this.flutechannel,87,flutelevel);   
   
     midi.play_note(this.flutechannel,86,flutelevel);   
     delay2(nspeed*4);   
     kill_note(this.flutechannel,86,flutelevel);   
   
     //Measure 12   
     this.cout("<br/>Measure " + measure++);   
     midi.play_note(this.flutechannel,90,flutelevel);   
     delay2(nspeed*6);   
     kill_note(this.flutechannel,90,flutelevel);   
   
     midi.play_note(this.flutechannel,89,flutelevel);   
     delay2(nspeed*6);   
     kill_note(this.flutechannel,89,flutelevel);   
   
     midi.play_note(this.flutechannel,87,flutelevel);   
     delay2(nspeed*4);   
     kill_note(this.flutechannel,87,flutelevel);   
   
     //Measure 13   
     this.cout("<br/>Measure " + measure++);   
     midi.play_note(this.flutechannel,90,flutelevel);   
     delay2(nspeed*9);   
     kill_note(this.flutechannel,90,flutelevel);   
   
     nspeed = 110;   
     midi.play_note(this.flutechannel,A4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,A4,flutelevel);   
   
     midi.play_note(this.flutechannel,B4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,B4,flutelevel);   
   
     midi.play_note(this.flutechannel,CS5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,CS5,flutelevel);   
   
     midi.play_note(this.flutechannel,D5,flutelevel);   
     delay2(nspeed*4);   
     kill_note(this.flutechannel,D5,flutelevel);   
   
     midi.play_note(this.flutechannel,D5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,D5,flutelevel);   
   
     midi.play_note(this.flutechannel,D5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,D5,flutelevel);   
   
     midi.play_note(this.flutechannel,CS5,flutelevel);   
     delay2(nspeed*4);   
     kill_note(this.flutechannel,CS5,flutelevel);   
   
     midi.play_note(this.flutechannel,D5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,D5,flutelevel);   
   
     midi.play_note(this.flutechannel,B4,flutelevel);   
     delay2(nspeed*10);   
     kill_note(this.flutechannel,B4,flutelevel);   
   
     midi.play_note(this.flutechannel,B4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,B4,flutelevel);   
   
     midi.play_note(this.flutechannel,GS4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,GS4,flutelevel);   
   
     midi.play_note(this.flutechannel,B4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,B4,flutelevel);   
   
     midi.play_note(this.flutechannel,E5,flutelevel);   
     delay2(nspeed*4);   
     kill_note(this.flutechannel,E5,flutelevel);   
   
     midi.play_note(this.flutechannel,D5,flutelevel);   
     delay2(nspeed*4);   
     kill_note(this.flutechannel,D5,flutelevel);   
   
     midi.play_note(this.flutechannel,CS5,flutelevel);   
     delay2(nspeed*4);   
     kill_note(this.flutechannel,CS5,flutelevel);   
   
     midi.play_note(this.flutechannel,B4,flutelevel);   
     delay2(nspeed*4);   
     kill_note(this.flutechannel,B4,flutelevel);   
   
     midi.play_note(this.flutechannel,C5,flutelevel);   
     delay2(nspeed*6);   
     kill_note(this.flutechannel,C5,flutelevel);   
   
     midi.play_note(this.flutechannel,C5,flutelevel);   
     delay2(nspeed*1);   
     kill_note(this.flutechannel,C5,flutelevel);   
   
     midi.play_note(this.flutechannel,C5,flutelevel);   
     delay2(nspeed*1);   
     kill_note(this.flutechannel,C5,flutelevel);   
   
     midi.play_note(this.flutechannel,C5,flutelevel);   
     delay2(nspeed*3);   
     kill_note(this.flutechannel,C5,flutelevel);   
   
     midi.play_note(this.flutechannel,B4,flutelevel);   
     delay2(nspeed*3);   
     kill_note(this.flutechannel,B4,flutelevel);   
   
     midi.play_note(this.flutechannel,C5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,C5,flutelevel);   
   
     midi.play_note(this.flutechannel,A4,flutelevel);   
     delay2(nspeed*6);   
     kill_note(this.flutechannel,A4,flutelevel);   
   
     midi.play_note(this.flutechannel,A4,flutelevel);   
     delay2(nspeed*1);   
     kill_note(this.flutechannel,A4,flutelevel);   
   
     midi.play_note(this.flutechannel,A4,flutelevel);   
     delay2(nspeed*1);   
     kill_note(this.flutechannel,A4,flutelevel);   
   
     delay2(nspeed*1);   
   
     midi.play_note(this.flutechannel,A4,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,A4,flutelevel);   
   
     midi.play_note(this.flutechannel,B4,flutelevel);   
     delay2(nspeed*3);   
     kill_note(this.flutechannel,B4,flutelevel);   
   
     midi.play_note(this.flutechannel,C5,flutelevel);   
     delay2(nspeed*2);   
     kill_note(this.flutechannel,C5,flutelevel);   
   
     midi.play_note(this.flutechannel,D5,flutelevel);   
     delay2(nspeed*16);   
     kill_note(this.flutechannel,D5,flutelevel);   
     delay2(nspeed*2);
     this.cout("<br/>LET GO");
     drums(92);
    },

    delay2:function(ms) {
  		return new Promise(resolve => setTimeout(resolve, ms));
  	} 
    
};