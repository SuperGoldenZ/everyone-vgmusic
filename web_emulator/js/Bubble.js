class Bubble extends EveryoneEasyKeysProgram {
    constructor() {
        super("BUBBLE", "menu", "26,120");
        this.basschannel = 2;
    }

    main() {
        this.clrscr();
        this.cout("Bubble Bobble Bass Blaster!");
        this.cout("<br/>Press ESC to quit...");
        this.cout("<br/>//DOWN SPACE LEFT ENTER");
        this.cout("<br/>");
        this.cout("<br/>//Q W     Q    W");
        this.cout("<br/>//Q SPACE LEFT Q");
        this.cout("<br/>");
        this.cout("<br/>//DOWN RIGHT DOWN RIGHT");
        this.cout("<br/>//DOWN SPACE LEFT ENTER");
        this.cout("<br/>");
        this.cout("<br/>//MEASURE 9 ?");
        this.cout("<br/>//Q W     Q    W");
        this.cout("<br/>//Q SPACE LEFT Q");
        this.cout("<br/>");
        this.cout("<br/>//DOWN RIGHT DOWN RIGHT");
        this.cout("<br/>//DOWN DOWN  R    T");
        this.cout("<br/>");
        this.cout("<br/>//1 2 (4 times )");
        this.cout("<br/>//T  Y  (6 times)");
        this.cout("<br/>//LEFT UP (2 times)");
        this.cout("<br/>//R T     (2 times)");
        this.cout("<br/>//R SPACE LEFT ENTER //end measure 16, begin 17 ... back to measure 9");

        lights.change_light_level(1, 50);
        lights.change_light_level(2, 75);
        lights.change_light_level(3, 25);
        lights.change_light_level(4, 50);
        midi.program_change(this.basschannel, 34);
    }

    dostuff(ev) {
        let mapping = [];
        mapping[keyboard.INDEX_Q] = [midi.A1];
        mapping[keyboard.INDEX_W] = [midi.A2];
        mapping[keyboard.INDEX_R] = [midi.C2];
        mapping[keyboard.INDEX_1] = [midi.DS2];
        mapping[keyboard.INDEX_2] = [midi.DS3];

        mapping[keyboard.INDEX_T] = [midi.D2];
        mapping[keyboard.INDEX_Y] = [midi.D3];

        mapping[keyboard.INDEX_F3] = [midi.D2];
        mapping[keyboard.INDEX_F4] = [midi.D3];

        mapping[keyboard.INDEX_0] = [midi.CS5];

        mapping[keyboard.INDEX_DOWN] = [midi.AS1];
        mapping[keyboard.INDEX_RIGHT] = [midi.AS2];

        mapping[keyboard.INDEX_LEFT] = [midi.G1];
        mapping[keyboard.INDEX_UP] = [midi.G2];

        mapping[keyboard.INDEX_SPACE] = [midi.F1];
        mapping[keyboard.INDEX_ENTER] = [midi.GS1];

        if (ev.type == "keydown") {
            mapping.forEach(function(item, index) {
                if ((activeSong.notes[index] == 0) && (ev.keyCode == index)) {
                    activeSong.notes[index] = 1;

                    item.forEach(function(item, index) {
                        midi.play_note(activeSong.basschannel, item, 127);
                    });

                    if (index == keyboard.INDEX_0) {
                        lights.change_light_level(1, 0, true, 50);
                        lights.change_light_level(2, 0, true, 50);
                        lights.change_light_level(3, 0, true, 50);
                        lights.change_light_level(4, 0, true, 50);
                        lights.flashSpeed = 250;
                        lights.state = "panic";
                        lights.panic_flash();
                    }
                }
            });
        } else if (ev.type == "keyup") {
            mapping.forEach(function(item, index) {
                if ((activeSong.notes[index] == 1) && (ev.keyCode == index)) {
                    activeSong.notes[index] = 0;

                    item.forEach(function(item, index) {
                        midi.kill_note(activeSong.basschannel, item, 127);
                    });

                    if (index == keyboard.INDEX_0) {                        
                        lights.state = "static";
                        lights.change_light_level(1, 50);
                        lights.change_light_level(2, 75);
                        lights.change_light_level(3, 25);
                        lights.change_light_level(4, 50);
                    }
                }
            });
        }
    }
}