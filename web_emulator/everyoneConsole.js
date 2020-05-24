let activeSong = null;

(function($) {
    $.fn.everyoneConsole = function(songs) {
        return this.each(function() {

            this.songs = songs;
            this.activeSong = null;

            $(this).addClass('everyoneConsole');
            let base = this;

            $(document).keyup(function(ev) {
                if (base.activeSong != null) {
                    base.activeSong.keyup(ev);
                    return;
                }            	
            });

            $(document).keydown(function(ev) {

            if (typeof MIDI.send === "undefined") {
                MIDI.loadPlugin({
                    instruments: ["acoustic_bass", "fretless_bass", "acoustic_grand_piano", "flute", 
                        "lead_1_square", "synth_strings_1"],
                    soundfontUrl: "https://gleitz.github.io/midi-js-soundfonts/FluidR3_GM/",
                    onsuccess: function (ev) {
                        console.log("plugin loaded!!");
                    }
                });
            }


                let commandFound = false;
                if (base.activeSong != null) {
                    base.activeSong.keydown(ev);
                    return;
                }
                if (ev.keyCode >= 65 && ev.keyCode <= 90 || ev.keyCode == 32 || (ev.keyCode >= 48 && ev.keyCode <= 57)) {
                    $(".everyoneConsole").append(ev.key);
                } else if (ev.keyCode == 8) {
                    $('.everyoneConsole').html(function(_, txt) {
                        if (txt.substr(txt.length - 1) != ">") {
                            return txt.slice(0, -1);
                        }
                        return txt;
                    });
                } else if (ev.keyCode == 13) {
                    let command = $('.everyoneConsole').html();
                    commands = command.split(";");
                    command = commands[commands.length - 1];
                    command = command.toUpperCase().trim();

                    for (var i = 0; i < base.songs.length; i++) {
                        if (command == base.songs[i].filename) {
                            base.activeSong = base.songs[i];
                            activeSong = base.songs[i];
                            base.songs[i].main();
                            base.activeSong.onDone = function() {
                                base.activeSong = null;
                                $(".everyoneConsole").append("<br/>C:\\EVERYONE\\>");
                            };
                            commandFound = true;
                            break;
                        }
                    }

                    if (command == "DIR") {
                        $(".everyoneConsole").append("<br/>&nbsp;Volume in drive C has no label");
                        $(".everyoneConsole").append("<br/>&nbsp;Volume Serial Number is XXXX-200X");
                        $(".everyoneConsole").append("<br/>&nbsp;Directory of C:\\EVERYONE");
                        $(".everyoneConsole").append("<br/> ");
                        for (var i = 0; i < base.songs.length; i++) {
                            $(".everyoneConsole").append("<br/>" + base.songs[i].filename);                                                        
                            for (var j = 0; j < 8-base.songs[i].filename.length; j++) {
                                $(".everyoneConsole").append("&nbsp;");    
                            }
                            $(".everyoneConsole").append("&nbsp;EXE&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
                            $(".everyoneConsole").append(base.songs[i].filesize);
                            $(".everyoneConsole").append("&nbsp;&nbsp;09-28-2002&nbsp;&nbsp;8:00p");
                        }

                        $(".everyoneConsole").append("<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1 File(s)");
                        $(".everyoneConsole").append("<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 Dir(s)");
                    } else if (command == "CLS") {
                        $(".everyoneConsole").html("");
                    } else if (command != "" && !commandFound && base.activeSong == null) {
                        $(".everyoneConsole").append("<br/>Command not found");
                    }
                    if (base.activeSong == null) {
                        $(".everyoneConsole").append("<br/>C:\\EVERYONE\\>");
                    }
                }

                console.log(ev);
            });
        })

    }
})(jQuery);