class Act extends EveryoneEasyKeysProgram {
    constructor() {
        super("ACT", "menu", "26,636");
    }

    main() {
        this.clrscr();
        //    mix_mode();
        //    mix_name("Actraiza");
        //    change_program(1,88,1);
        //    change_program(2,9,3);
        //    change_program(3,52,1);
        // //   change_program(4,51,1);
        // //   change_program(5,51,1);
        //    change_program(4,20,6);
        //    change_program(5,20,6);
        //    change_program(6,56,0);
        //    change_program(7,52,3);
        //    change_volume(3,52);
        //    change_keyboard_input(2,1);
        //    change_keyboard_input(3,1);
        //    change_low_note(1,C4);
        //    change_high_note(2,B3);
        //    change_high_note(3,B3);
        //    mix_mode();

        this.cout("Actraiser<br/><br/>");
        this.cout("F1: Fade out second part<br/>");;
        this.cout("F2: Set level back to normal<br/><br/>");
        this.cout("R A S D F S E S Q E W<br/>");;
        this.cout("W E R A S E Q E 3 Q 4<br/>");;
        this.cout("W E R A S R Q R Q<br/><br/>");
        this.cout("S A R A Z Q<br/>");;
        this.cout("D S A S R Q<br/>");;
        this.cout("F D S D X F S D<br/>");;
        this.cout("F X C V X D S A R A<br/>");;
        // change_light_level(1,50);
        // change_light_level(2,75);
        // change_light_level(3,25);
        // change_light_level(4,50);
        // while (1 == 1)
        // {
        //    dostuff();
        //    if (key_table[INDEX_F1])
        //    {
        //       this.cout("\nFading out part...";
        //       for (int level = 99; level >=0; level-=1)
        //       {
        //          this.cout(".";
        //          change_volume(4,level);
        //          change_volume(6,level);
        //          delay1(60);
        //       }
        //       this.cout(" (done)";
        //    }
        //    if (key_table[INDEX_F2])
        //    {
        //       this.cout("\nVolume set to LOUD!";
        //       change_volume(4,99);
        //       delay1(100);
        //       change_volume(6,99);
        //    }
        //    if (key_table[INDEX_ESC]) break;
        // }
        // all_lights_off(0);
        // change_light_level(3,127);
    }

    dostuff(ev) {
        let mapping = [];
        mapping[keyboard.INDEX_Q] = [midi.A4];
        mapping[keyboard.INDEX_W] = [midi.AS4];
        mapping[keyboard.INDEX_E] = [midi.C5];
        mapping[keyboard.INDEX_R] = [midi.D5];
        mapping[keyboard.INDEX_A] = [midi.E5];
        mapping[keyboard.INDEX_S] = [midi.F5];
        mapping[keyboard.INDEX_D] = [midi.G5];
        mapping[keyboard.INDEX_F] = [midi.A5];
        mapping[keyboard.INDEX_Z] = [midi.CS5];
        mapping[keyboard.INDEX_X] = [midi.AS5];
        mapping[keyboard.INDEX_C] = [midi.C6];
        mapping[keyboard.INDEX_V] = [midi.D6];

        mapping[keyboard.INDEX_4] = [midi.G4];
        mapping[keyboard.INDEX_3] = [midi.F4];

        mapping[keyboard.INDEX_LEFT] = [midi.A3, midi.D4];
        mapping[keyboard.INDEX_UP] = [midi.A3, midi.CS4];
        mapping[keyboard.INDEX_RIGHT] = [midi.G3, midi.C4];
        mapping[keyboard.INDEX_DOWN] = [midi.D4, midi.F3];
        mapping[keyboard.INDEX_0] = [midi.G3, midi.D4];
        mapping[keyboard.INDEX_1] = [midi.E3, midi.CS4];

        if (ev.type == "keydown") {
            mapping.forEach(function(item, index) {
                if ((activeSong.notes[index] == 0) && (ev.keyCode == index)) {
                    activeSong.notes[index] = 1;

                    item.forEach(function(item, index) {
                        midi.play_note(1, item, 127);
                    });
                }
            });
        } else if (ev.type == "keyup") {
            mapping.forEach(function(item, index) {
                if ((activeSong.notes[index] == 1) && (ev.keyCode == index)) {
                    activeSong.notes[index] = 0;

                    item.forEach(function(item, index) {
                        midi.kill_note(1, item, 127);
                    });
                }
            });
        }
    }

    keydown(ev) {
        if (ev.keyCode == 27) {
        	this.done();
        }
        this.dostuff(ev);
    }

    keyup(ev) {
        this.dostuff(ev);
    }

    done() {
        $(".everyoneConsole").css("flex-direction", "column-reverse");        
        // this.state = "done";
        // $(".score").fadeOut(500);
        if (this.onDone != null) {
            lights.change_light_level(1, 127);
            lights.change_light_level(2, 127);
            lights.change_light_level(3, 127);
            lights.change_light_level(4, 127);
            this.onDone();
        }
    }
}