class EveryoneEasyKeysProgram {
    constructor(filename, initialStateName, filesize) {
        this.filename = filename;
        this.state = initialStateName;
        this.filesize = filesize;

        this.notes = [];
        for (var index = 0; index < 127; index++) {
            this.notes[index] = 0;
        }

        console.log("Constructor ");
        console.log(this);
    }


    cout(txt, force = false) {
        if (force || (this.state != "done" && this.state != "done_wily")) {
            $(".everyoneConsole").append(txt);
        }
    }

    clrscr() {
        $(".everyoneConsole").html("");
    }

    keydown(ev) {
        if (ev.keyCode == 27) {
        	this.done();
        } else {
        	this.dostuff(ev);
        }
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