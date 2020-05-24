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
}