var cursor;
var osmd;
var oldX = 0;

$(document).ready(function() {
    everyoneConsole = $('#console').everyoneConsole([megaman2]);
    navigator.requestMIDIAccess().then(onMidiAccess, onMidiFailure);
    /*
    navigator.requestMIDIAccess().then(onMidiAccess, onMidiFailure);
    jsRapPiano = $('#pianoInput').jsRapPiano({
        octave: 1,
        octaves: 7,
        onClick: onPianoClick,
        highlightMiddleC: true,
        //fullPiano: true
    });*/


    osmd = new opensheetmusicdisplay.OpenSheetMusicDisplay("score", {
        drawCredits: false,
        drawPartNames: false,
        drawTitle: false,
        renderSingleHorizontalStaffline: true,
        /*defaultColorNotehead: "#FFFFFF",
        defaultColorStem: "#FFFFFF",
        defaultColorRest: "#FFFFFF",
        defaultColorLabel: "#FFFFFF",
        defaultColorTitle: "#FFFFFF"*/
    });

    var loadPromise = osmd.load("./mm2.musicxml");
    //var loadPromise = osmd.load("./BrahWiMeSample.musicxml");
    loadPromise.then(function() {
        console.log("score rendering");
        osmd.render();
        console.log("score rendered");
        //$(".score").fadeIn(500);
        //moveScore();

//        cursor = osmd.cursor;
  //      cursor.show();        
        //oldX = cursor.cursorElement.x;
        //cursor.next();

        //setTimeout(moveScore, 500);
        //moveScore();
        //moveToMeasure(5);
    });

});

var midi_inputs = [];
var midi_outputs = [];

function onMidiFailure() {
    console.log("no midi for you");
}

//var firstPlayback = true;
var stopPlayback = false;

function playback(goNext = true) {

    if (stopPlayback === true) {
        return;
    }

    if (goNext === true) {
        cursor.next();
    } 

    var notes = cursor.NotesUnderCursor();
    //console.log(notes);

    if (typeof notes[0] === 'undefined') {
        console.error("Note was undefined");
        return;
    }

    var delay = notes[0].length.realValue * activeSong.speed * 16;

    console.log("delay = " + notes[0].length.realValue + " * " + activeSong.speed);

    if (delay == 0) {
        delay = 135 * 16;
        console.log("delay was 0!")
    }

    if (oldX === 0) {
        oldX = cursor.cursorElement.x;
    }

    var diff = oldX - cursor.cursorElement.x;
    $(".score").css({
        left: $(".score").position().left + diff + "px"
    });
    //}

    //firstPlayback = false;
    setTimeout(playback, delay);
}

function moveToMeasure(measureNumber) {
    return;
    // for (var i = 0 ; i < osmd.graphic.measureList.length; i++) {
    //     //osmd.graphic.measureList[0][0].staffEntries[0].graphicalVoiceEntries[0].notes[0].sourceNote.noteheadColor = "#FF0000" // red rest note

    //     for (var j= 0; j < osmd.graphic.measureList[i][0].staffEntries[0].graphicalVoiceEntries[0].notes.length; j++) {
    //             //console.log(osmd.graphic.measureList[i][0]);        
    //             osmd.graphic.measureList[i][0].staffEntries[0].graphicalVoiceEntries[0].notes[j].sourceNote.noteheadColor = "#FF0000" // red rest note
    //             console.log("set color");
    //     }

    // }

    //console.log(osmd.graphic.measureList[0][0].graphicalVoiceEntries[0].notes);
    while (cursor.iterator.currentMeasure.measureNumber < measureNumber - 2) {
        var notes = cursor.NotesUnderCursor();
        for (var i = 0; i < notes.length; i++) {
            //     notes[i].noteheadColor = "#FF0000";
            //     notes[i].stemColor = "#FF0000";
            console.log(notes[i]);
        }
        //osmd.updateGraphic();

        cursor.next();
        var diff = oldX - cursor.cursorElement.x;
        $(".score").css({
            left: $(".score").position().left + diff + "px"
        });

    }
}

//measure number
function moveScore() {
    if (oldX === 0) {
        oldX = cursor.cursorElement.x;
    }
    cursor.next();
    console.log(cursor.iterator.currentMeasure.measureNumber);
    var diff = oldX - cursor.cursorElement.x;
    //console.log();
    $(".score").css({
        left: $(".score").position().left + diff + "px"
    });
    //console.log("moving score");
    setTimeout(moveScore, 500);
}

function onMidiAccess(access) {
    // Get lists of available MIDI controllers
    const inputs = access.inputs.values();
    const outputs = access.outputs.values();
    var i = 1;


    midi_outputs.push(MIDI);
    out = midi_outputs[0];
    midi.midiOut = out;
    for (var output of access.outputs.values()) {
        midi_outputs.push(output);
        if (out == null) {
            out = output;
        }
        $('#midi_outputs').append("<option value = \"" + i++ + "\">" + output.name + "</option>");
    }

    i = 0;

    for (var inputIt of access.inputs.values()) {
        midi_inputs.push(inputIt);
        //inputIt.onmidimessage = getMIDIMessage;
        $('#midi_inputs').append("<option value = \"" + i++ + "\">" + output.name + "</option>");
    }

    access.onstatechange = function(e) {
        // Print information about the (dis)connected MIDI controller
        console.log(e.port.name, e.port.manufacturer, e.port.state);
    };

    $('#midi_outputs').change(onMidiOutputChange);
    $('#midi_inputs').change(onMidiOutputChange);
}

function onMidiInputChange(ev) {
    //var selectedMidiInput = $("#midi_inputs").children("option:selected").val();
    //= midi_inputs[selectedMidiInput];
}

function onMidiOutputChange(ev) {
    var selectedMidiOutput = $("#midi_outputs").children("option:selected").val();
    midi.midiOut = midi_outputs[selectedMidiOutput];
    console.log("set midi out " + selectedMidiOutput);
    console.log(midi_outputs);

    //megaman2.cleanBassChannel = 36;
}