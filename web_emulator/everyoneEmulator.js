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
});

var midi_inputs = [];
var midi_outputs = [];


function onMidiFailure() {
    console.log("no midi for you");
}

function onMidiAccess(access) {
    // Get lists of available MIDI controllers
    const inputs = access.inputs.values();
    const outputs = access.outputs.values();
    var i = 1;

    //midi_outputs.push($(jsRapPiano)[0].jsSynth);
    out = midi_outputs[0];

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
    console.log("set midi out");
    console.log(midi_outputs);
}