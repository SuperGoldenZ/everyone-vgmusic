class MegaMan3 extends EveryoneEasyKeysProgram {
    constructor() {
        super("MEGAMAN3", "menu", "39,712");
        this.introbasschannel = 3;        
    }

    main() {
        this.clrscr();
        this.cout("Mega Man 3");

        this.cout("<br/>[0    ]: Intro");
        this.cout("<br/>SPACE LEFT  DOWN SPACE");
        this.cout("<br/>RIGHT SPACE UP SPACE");
        this.cout("<br/>LEFT RIGHT SPACE UP");
        this.cout("<br/>SPACE DOWN SPACE LEFT");
        this.cout("<br/>ESC: Quit");
        this.state = "menu";
        midi.program_change(this.introbasschannel, 34);
    }

    dostuff(ev) {
        let mapping = [];
        mapping[keyboard.INDEX_1] = [midi.FS1];
        mapping[keyboard.INDEX_2] = [midi.E1];
        mapping[keyboard.INDEX_LEFT] = [midi.B0];
        mapping[keyboard.INDEX_UP] = [midi.CS1];
        mapping[keyboard.INDEX_RIGHT] = [midi.D1];
        mapping[keyboard.INDEX_DOWN] = [midi.F1];
        mapping[keyboard.INDEX_ENTER] = [midi.CS2];
        mapping[keyboard.INDEX_G] = [midi.C1];
        mapping[keyboard.INDEX_T] = [midi.CS1];
        mapping[keyboard.INDEX_P] = [midi.A3];
        mapping[keyboard.INDEX_4] = [midi.CS4];
        mapping[keyboard.INDEX_5] = [midi.E3];
        mapping[keyboard.INDEX_6] = [midi.F3];
        mapping[keyboard.INDEX_O] = [midi.FS3];

        if (ev.type == "keydown") {
            mapping.forEach(function(item, index) {
                if ((activeSong.notes[index] == 0) && (ev.keyCode == index)) {
                    activeSong.notes[index] = 1;

                    item.forEach(function(item, index) {
                        console.log("Play node: " + item);
                        midi.play_note(activeSong.introbasschannel, item, 127);
                    });
                }
            });

            if (ev.keyCode == keyboard.INDEX_0 && activeSong.state == "menu") {
                console.log("INDEX_0");
                activeSong.state = "intro";
                activeSong.intro();
            }
        } else if (ev.type == "keyup") {
            mapping.forEach(function(item, index) {
                if ((activeSong.notes[index] == 1) && (ev.keyCode == index)) {
                    activeSong.notes[index] = 0;

                    item.forEach(function(item, index) {
                        midi.kill_note(activeSong.introbasschannel, item, 127);
                    });
                }
            });
        }
    }

    intro() {
        console.log("intro!");
        this.clrscr();
        lights.all_lights_off(1);        
        
        
        this.cout("1&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| 2 2 1     <br/>"); //1        
        this.cout("LEFT UP | RIGHT<br/>"); //3
        this.cout("DOWN&nbsp;&nbsp;&nbsp;&nbsp;| 1<br/>"); //4
        this.cout("2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| RIGHT<br/>"); //5                
        this.cout("RIGHT 2 (\"da da \") | 1  "); //8
        this.cout("<br/>1                    | O"); //9
        this.cout("<br/>2 2 1                | P"); //10
        this.cout("<br/>LEFT G               | 4"); //11
        this.cout("<br/>UP                   | 5 6"); //12
        this.cout("<br/>1 1 DOWN             | O"); //13
        this.cout("<br/>2 2 T                | P"); //14
        this.cout("<br/>RIGHT                | 4"); //15
        this.cout("<br/>ENTER"); //16        
        this.cout("<br/><br/>Press SPACE to start drum loop");
        lights.change_light_level(2, 127, true, "slow");


        // measure = 16;
        // cout << "5 ";
        // mix_name("5          ");
        // mix_mode();
        // delay1(200);
        // cout << "4 ";
        // mix_name("4          ");
        // mix_mode();
        // delay1(200);
        // cout << "3 ";
        // mix_name("3          ");
        // mix_mode();
        // delay1(200);
        // cout << "2 ";
        // mix_name("2          ");
        // mix_mode();
        // delay1(200);
        // cout << "1 ";
        // mix_name("1          ");
        // mix_mode();
        // delay1(200);
        // mix_name("Mega Man   ");

        // change_keyboard_input(lead2channel, 1);
        // change_program(lead3channel, 9, 1);

        // change_volume(lead3channel, 90);
        // change_keyboard_input(lead3channel, 1);

        // change_program(1, 90, 1);
        // change_program(lead2channel, 91, 1);
        // kill_note(stringchannel, CS5, introbasslevel);
        // kill_note(lead2channel, CS5, introbasslevel);
        // mix_mode();

        // while (1) {
        //     cout << "\nMeasure: " << ++measure;
        //     play_note(drumchannel, D1, 127);
        //     play_note(basschannel, D2, 127);

        //     change_light_level(1, 127);
        //     change_light_level(3, 127);
        //     cout << "\ndrum! ";
        //     if (delay1(speed)) break;
        //     kill_note(basschannel, D2, 127);
        //     play_note(basschannel, D2, 127);
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);

        //     cout << "drum! ";
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);
        //     cout << "drum! ";
        //     kill_note(basschannel, D2, 127);
        //     play_note(basschannel, D2, 127);


        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);
        //     cout << "drum! ";
        //     kill_note(basschannel, D2, 127);
        //     play_note(basschannel, D2, 127);


        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);
        //     cout << "drum! ";
        //     kill_note(basschannel, D2, 127);
        //     play_note(basschannel, D2, 127);


        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     cout << "drum! ";
        //     kill_note(basschannel, D2, 127);
        //     play_note(basschannel, D2, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     cout << "drum! ";
        //     kill_note(basschannel, D2, 127);
        //     play_note(basschannel, D2, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     cout << "drum! ";
        //     kill_note(basschannel, D2, 127);
        //     play_note(basschannel, D2, 127);
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     cout << "drum! ";
        //     kill_note(basschannel, D2, 127);
        //     play_note(basschannel, D2, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     all_lights_off(0);
        //     cout << "drum! ";
        //     kill_note(basschannel, D2, 127);
        //     play_note(basschannel, D2, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     kill_note(basschannel, D2, 127);


        //     change_light_level(2, 127);
        //     change_light_level(4, 127);

        //     cout << "\nMeasure: " << ++measure;
        //     play_note(drumchannel, D1, 127);
        //     play_note(basschannel, E2, 127);

        //     cout << "\ndrum! ";
        //     if (delay1(speed)) break;
        //     kill_note(basschannel, E2, 127);
        //     play_note(basschannel, E2, 127);
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     cout << "drum! ";
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);
        //     kill_note(basschannel, E2, 127);
        //     play_note(basschannel, E2, 127);


        //     cout << "drum! ";
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     cout << "drum! ";
        //     kill_note(basschannel, E2, 127);
        //     play_note(basschannel, E2, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     cout << "drum! ";
        //     kill_note(basschannel, E2, 127);
        //     play_note(basschannel, E2, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     cout << "drum! ";
        //     kill_note(basschannel, E2, 127);
        //     play_note(basschannel, E2, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     cout << "drum! ";
        //     kill_note(basschannel, E2, 127);
        //     play_note(basschannel, E2, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     cout << "drum! ";
        //     kill_note(basschannel, E2, 127);
        //     play_note(basschannel, E2, 127);
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);


        //     cout << "drum! ";
        //     kill_note(basschannel, E2, 127);
        //     play_note(basschannel, E2, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);

        //     all_lights_off(0);
        //     cout << "drum! ";
        //     kill_note(basschannel, E2, 127);
        //     play_note(basschannel, E2, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     kill_note(basschannel, E2, 127);


        //     cout << "\nMeasure: " << ++measure;
        //     play_note(drumchannel, D1, 127);
        //     play_note(basschannel, FS2, 127);
        //     change_light_level(1, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     kill_note(basschannel, FS2, 127);
        //     play_note(basschannel, GS2, 127);
        //     play_note(drumchannel, D1, 127);
        //     change_light_level(2, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);
        //     kill_note(basschannel, GS2, 127);
        //     play_note(basschannel, A2, 127);
        //     change_light_level(3, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, D1, 127);
        //     kill_note(basschannel, A2, 127);
        //     play_note(basschannel, B2, 127);
        //     change_light_level(4, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     kill_note(basschannel, B2, 127);

        //     cout << "\nMeasure: " << ++measure;
        //     play_note(basschannel, CS3, 127);
        //     play_note(synthdrumchannel, C3, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(synthdrumchannel, C3, 127);
        //     play_note(drumchannel, D1, 127);
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(synthdrumchannel, C3, 127);
        //     if (delay1(speed)) break;

        //     if (delay1(speed)) break;
        //     kill_note(synthdrumchannel, C3, 127);
        //     play_note(drumchannel, D1, 127);
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(synthdrumchannel, C3, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(synthdrumchannel, C3, 127);

        //     play_note(drumchannel, D1, 127);
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(synthdrumchannel, C3, 127);
        //     if (delay1(speed)) break;
        //     kill_note(synthdrumchannel, C3, 127);
        //     play_note(drumchannel, D1, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);

        //     all_lights_off(0);
        //     play_note(synthdrumchannel, C3, 127);
        //     if (delay1(speed)) break;
        //     kill_note(synthdrumchannel, C3, 127);
        //     play_note(synthdrumchannel, C3, 127);
        //     if (delay1(speed)) break;
        //     kill_note(synthdrumchannel, C3, 127);
        //     play_note(synthdrumchannel, B1, 127);
        //     if (delay1(speed)) break;
        //     kill_note(synthdrumchannel, B1, 127);
        //     play_note(synthdrumchannel, B1, 127);
        //     if (delay1(speed)) break;
        //     kill_note(synthdrumchannel, B1, 127);
        //     kill_note(basschannel, CS3, 127);
        //     break;
        // }

        // change_volume(padechochannel, 99);
        // int times = 0;
        // kill_note(16, 1, 127);
        // kill_note(stringchannel, CS5, introbasslevel);
        // kill_note(lead2channel, CS5, introbasslevel);

        // mix_mode();

        // while (1) {
        //     cout << "\nMeasure: " << ++measure;
        //     if (measure == 21) {
        //         change_light_level(10, 127);
        //     }

        //     if (measure == 29) {
        //         change_light_level(12, 0);
        //         change_light_level(1, 127);
        //         change_light_level(3, 127);
        //     }

        //     if (measure == 31) {
        //         change_light_level(1, 0);
        //         change_light_level(3, 0);
        //         change_light_level(2, 127);
        //         change_light_level(4, 127);
        //     }

        //     if (measure == 33) {
        //         change_light_level(2, 0);
        //         change_light_level(4, 0);
        //         change_light_level(1, 127);
        //         change_light_level(4, 127);
        //     }

        //     if (measure == 35) {
        //         change_light_level(1, 0);
        //         change_light_level(4, 0);
        //         change_light_level(2, 127);
        //         change_light_level(3, 127);
        //     }

        //     if (measure == 36) {
        //         change_light_level(2, 0);
        //         change_light_level(3, 0);
        //         change_light_level(1, 127);
        //         change_light_level(2, 127);
        //         change_light_level(3, 127);
        //         change_light_level(4, 127);
        //     }

        //     //begining of measure

        //     if (measure == 21)
        //         play_note(drumchannel, CS2, 127);
        //     play_note(drumchannel, C1, 127);
        //     play_note(basschannel, bassnotes[measure][0], basslevel);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(basschannel, bassnotes[measure][0], basslevel);
        //     play_note(basschannel, bassnotes[measure][1], basslevel);
        //     kill_note(drumchannel, C1, 127);
        //     play_note(drumchannel, AS1, 127);
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, AS1, 127);
        //     play_note(drumchannel, AS1, 127);
        //     kill_note(basschannel, bassnotes[measure][1], basslevel);
        //     play_note(basschannel, bassnotes[measure][2], basslevel);
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, AS1, 127);
        //     kill_note(basschannel, bassnotes[measure][2], basslevel);
        //     play_note(basschannel, bassnotes[measure][3], basslevel);
        //     if (measure == 21)
        //         kill_note(drumchannel, CS2, 127);

        //     play_note(drumchannel, D1, 127);
        //     if (delay1(speed)) break;
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, D1, 127);
        //     play_note(drumchannel, AS1, 127);
        //     kill_note(basschannel, bassnotes[measure][3], basslevel);
        //     play_note(basschannel, bassnotes[measure][4], basslevel);
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, AS1, 127);
        //     play_note(drumchannel, AS1, 127);
        //     kill_note(basschannel, bassnotes[measure][4], basslevel);
        //     play_note(basschannel, bassnotes[measure][5], basslevel);
        //     if (delay1(speed)) break;
        //     kill_note(drumchannel, AS1, 127);
        //     kill_note(basschannel, bassnotes[measure][5], basslevel);
        //     play_note(basschannel, bassnotes[measure][6], basslevel);

        //     if ((measure != 28) && (measure != 36)) {
        //         cout << " (" << measure << ")";
        //         play_note(drumchannel, C1, 127);
        //         if (delay1(speed)) break;
        //         if (delay1(speed)) break;
        //         kill_note(drumchannel, C1, 127);
        //         play_note(drumchannel, AS1, 127);
        //         kill_note(basschannel, bassnotes[measure][6], basslevel);
        //         play_note(basschannel, bassnotes[measure][7], basslevel);
        //         if (delay1(speed)) break;
        //         kill_note(drumchannel, AS1, 127);
        //         play_note(drumchannel, AS1, 127);
        //         kill_note(basschannel, bassnotes[measure][7], basslevel);
        //         play_note(basschannel, bassnotes[measure][8], basslevel);
        //         if (delay1(speed)) break;
        //         kill_note(drumchannel, AS1, 127);
        //         kill_note(basschannel, bassnotes[measure][8], basslevel);
        //         play_note(basschannel, bassnotes[measure][9], basslevel);

        //         play_note(drumchannel, D1, 127);
        //         if (delay1(speed)) break;
        //         if (delay1(speed)) break;
        //         kill_note(drumchannel, D1, 127);
        //         kill_note(basschannel, bassnotes[measure][9], basslevel);
        //         play_note(basschannel, bassnotes[measure][10], basslevel);
        //         play_note(drumchannel, AS1, 127);

        //         if (measure == 24) {
        //             change_light_level(12, 127);
        //             change_light_level(10, 0);
        //         }

        //         if (delay1(speed)) break;
        //         kill_note(drumchannel, AS1, 127);
        //         kill_note(basschannel, bassnotes[measure][10], basslevel);
        //         play_note(basschannel, bassnotes[measure][11], basslevel);
        //         play_note(drumchannel, AS1, 127);
        //         if (delay1(speed)) break;
        //         kill_note(drumchannel, AS1, 127);
        //         kill_note(basschannel, bassnotes[measure][11], basslevel);
        //     } else {
        //         if (times == 1) {
        //             cout << " (" << measure << ")";
        //             play_note(drumchannel, C1, 127);
        //             play_note(synthdrumchannel, C3, 127);
        //             if (delay1(speed)) break;
        //             if (delay1(speed)) break;
        //             kill_note(synthdrumchannel, C3, 127);
        //             play_note(synthdrumchannel, C3, 127);
        //             kill_note(basschannel, bassnotes[measure][6], basslevel);
        //             play_note(basschannel, bassnotes[measure][7], basslevel);
        //             kill_note(drumchannel, C1, 127);
        //             play_note(drumchannel, AS1, 127);
        //             if (delay1(speed)) break;
        //             kill_note(drumchannel, AS1, 127);
        //             play_note(drumchannel, AS1, 127);
        //             kill_note(basschannel, bassnotes[measure][7], basslevel);
        //             play_note(basschannel, bassnotes[measure][8], basslevel);
        //             if (delay1(speed)) break;
        //             kill_note(drumchannel, AS1, 127);
        //             kill_note(synthdrumchannel, C3, 127);
        //             kill_note(basschannel, bassnotes[measure][8], basslevel);
        //             play_note(basschannel, bassnotes[measure][9], basslevel);

        //             play_note(synthdrumchannel, C3, 127);
        //             play_note(drumchannel, D1, 127);
        //             if (delay1(speed)) break;
        //             kill_note(synthdrumchannel, C3, 127);
        //             play_note(synthdrumchannel, C3, 127);

        //             if (measure == 36) {
        //                 change_light_level(1, 0);
        //                 change_light_level(2, 0);
        //                 change_light_level(3, 0);
        //                 change_light_level(4, 0);
        //             }

        //             if (delay1(speed)) break;
        //             kill_note(synthdrumchannel, C3, 127);
        //             play_note(synthdrumchannel, B2, 127);
        //             kill_note(drumchannel, D1, 127);
        //             play_note(drumchannel, AS1, 127);
        //             kill_note(basschannel, bassnotes[measure][9], basslevel);
        //             play_note(basschannel, bassnotes[measure][10], basslevel);

        //             if (delay1(speed)) break;
        //             kill_note(synthdrumchannel, B2, 127);
        //             play_note(synthdrumchannel, B2, 127);
        //             kill_note(drumchannel, AS1, 127);
        //             play_note(drumchannel, AS1, 127);
        //             kill_note(basschannel, bassnotes[measure][10], basslevel);
        //             play_note(basschannel, bassnotes[measure][11], basslevel);
        //             if (delay1(speed)) break;
        //             kill_note(synthdrumchannel, B2, 127);
        //             kill_note(drumchannel, AS1, 127);
        //             kill_note(basschannel, bassnotes[measure][11], basslevel);
        //             play_note(drumchannel, CS2, 127);
        //         } else {
        //             cout << " (" << measure << ")";
        //             play_note(drumchannel, C1, 127);
        //             play_note(synthdrumchannel, C3, 127);
        //             if (delay1(speed)) break;
        //             if (delay1(speed)) break;
        //             kill_note(synthdrumchannel, C3, 127);
        //             play_note(synthdrumchannel, C3, 127);
        //             kill_note(basschannel, bassnotes[measure][6], basslevel);
        //             play_note(basschannel, bassnotes[measure][7], basslevel);
        //             kill_note(drumchannel, C1, 127);
        //             play_note(drumchannel, AS1, 127);
        //             if (delay1(speed)) break;
        //             kill_note(drumchannel, AS1, 127);
        //             play_note(drumchannel, AS1, 127);
        //             kill_note(basschannel, bassnotes[measure][7], basslevel);
        //             play_note(basschannel, bassnotes[measure][8], basslevel);
        //             if (delay1(speed)) break;
        //             kill_note(drumchannel, AS1, 127);
        //             kill_note(synthdrumchannel, C3, 127);
        //             kill_note(basschannel, bassnotes[measure][8], basslevel);
        //             play_note(basschannel, bassnotes[measure][9], basslevel);

        //             play_note(synthdrumchannel, C3, 127);
        //             play_note(drumchannel, D1, 127);
        //             if (delay1(speed)) break;
        //             kill_note(synthdrumchannel, C3, 127);
        //             play_note(synthdrumchannel, C3, 127);

        //             if (measure == 36) {
        //                 change_light_level(1, 0);
        //                 change_light_level(2, 0);
        //                 change_light_level(3, 0);
        //                 change_light_level(4, 0);
        //             }

        //             if (delay1(speed)) break;
        //             kill_note(synthdrumchannel, C3, 127);
        //             play_note(synthdrumchannel, B2, 127);
        //             kill_note(drumchannel, D1, 127);
        //             play_note(drumchannel, AS1, 127);
        //             kill_note(basschannel, bassnotes[measure][9], basslevel);
        //             play_note(basschannel, bassnotes[measure][10], basslevel);

        //             if (delay1(speed)) break;
        //             kill_note(synthdrumchannel, B2, 127);
        //             play_note(synthdrumchannel, B2, 127);
        //             kill_note(drumchannel, AS1, 127);
        //             play_note(drumchannel, AS1, 127);
        //             kill_note(basschannel, bassnotes[measure][10], basslevel);
        //             play_note(basschannel, bassnotes[measure][11], basslevel);
        //             if (delay1(speed)) break;
        //             kill_note(synthdrumchannel, B2, 127);
        //             kill_note(drumchannel, AS1, 127);
        //             kill_note(basschannel, bassnotes[measure][11], basslevel);
        //         }
        //     }

        //     //end special measure

        //     if (measure == 36) {
        //         times++;
        //         if (times == 2)
        //             break;
        //         measure = 20;
        //     }
        // }
        return 1;
    }
}