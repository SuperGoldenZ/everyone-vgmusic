(function($){
$.fn.everyoneConsole = function(options){

$( "#target" ).keydown(function() {
  alert( "Handler for .keydown() called." );
});

return this.each(function(){
	$(this).addClass('everyoneConsole');
	$(document).keydown(function (ev) {
		if (ev.keyCode >= 65 && ev.keyCode <= 90 || ev.keyCode == 32) {
			$(".everyoneConsole").append(ev.key);
		} else if (ev.keyCode == 8) {
			$('.everyoneConsole').html(function (_,txt) {
				if (txt.substr(txt.length-1) != ">") {
					return txt.slice(0, -1);	
				}
    			return txt;
			});
		} else if (ev.keyCode == 13) {
			let command = $('.everyoneConsole').html();
			commands = command.split(";");
			command = commands[commands.length-1];
			command = command.toUpperCase().trim();
			if (command == "DIR") {
				$(".everyoneConsole").append("<br/>&nbsp;Volume in drive C has no label");
				$(".everyoneConsole").append("<br/>&nbsp;Volume Serial Number is XXXX-200X");				
				$(".everyoneConsole").append("<br/>&nbsp;Directory of C:\\EVERYONE");
				$(".everyoneConsole").append("<br/> ");
				$(".everyoneConsole").append("<br/>MEGAMAN2&nbsp;EXE&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;65,012&nbsp;&nbsp;09-28-2002&nbsp;&nbsp;8:00p");
				$(".everyoneConsole").append("<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1 File(s)");
				$(".everyoneConsole").append("<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 Dir(s)");
			} else if (command == "CLS") {
				$(".everyoneConsole").html("");
			} else if (command != "") {
				$(".everyoneConsole").append("<br/>Command not found");
			}

			$(".everyoneConsole").append("<br/>C:\\EVERYONE\\>");
		}
		
		console.log(ev);
		}
	);

	// function onKeyDown(ev){
		
	// }
	/*
	this.opt = $.extend({
		octave:3,
		octaves:2,
		waveType:'square',
		envelope:{
			attack:0.05,
			decay:0.1,
			sustain:0.1,
			release:0.5,
			level:0.5
		},
		onClick:null,
		highlightMiddleC:false,
	},options);
	let base = this;
	//let AudioContext =  null;
	//this.audioContext = null;	

	this.highlightMiddleC = this.opt.highlightMiddleC;
	
	this.Render = function(){
		$(this).empty();
		let w = $(this).width();
		w = w / (this.opt.octaves * 7);
		$(this).addClass('rapPiano').height(w * 5);
		let i = 12 * (this.opt.octave + 1);
		for(let o = 0;o < this.opt.octaves;o++)
			for(let x = 0;x < 7;x++){
				let k = $('<div>').addClass('divKey').css({width:w}).appendTo(this);
				let majorDiv = $('<div>').addClass('major');
				if (this.highlightMiddleC && i == 60) {
					majorDiv.addClass('middleC');
				}
				majorDiv.prop('index',i++).appendTo(k);
				if((x % 7 == 2) || (x % 7 == 6))continue;
				$('<div>').addClass('minor').prop('index',i++).appendTo(k);
			}
		$('.major,.minor',this).bind({
			mousedown:function(e){
				let i = $(this).prop('index');
				//Will move to MIDI interface
				//base.jsSynth.PlaySound(f);
				if(base.opt.onClick)
					base.opt.onClick.call(base, i);
			}
		});	
	}
		
	this.jsSynth = {
		InitSynth: function(waveType = 'square', envelope = {
				attack:0.05,
				decay:0.1,
				sustain:0.1,
				release:0.5,
				level:0.5}
		) {
			this.AudioContext = window.AudioContext || window.webkitAudioContext;
			this.audioContext = new AudioContext();
			this.oscillator = this.audioContext.createOscillator();
			this.gainMain = this.audioContext.createGain();
			this.gainMain.gain.value = 1;
			this.gainMain.connect(this.audioContext.destination);
			this.oscillator.start(0);			
			this.oscillator.frequency.value = 50;
			this.envelope = envelope;
		},

		PlaySound: function(frequency) {
			if (this.audioContext == null) {
				return;
			}

			let t = this.audioContext.currentTime;
			gainNode = this.audioContext.createGain();
			gainNode.connect(this.gainMain);
			this.oscillator.connect(gainNode);
			gainNode.gain.setValueAtTime(0,t);
			this.oscillator.frequency.value = frequency;
			t += this.envelope.attack;
			gainNode.gain.linearRampToValueAtTime(1,t);
			t += this.envelope.decay;
			gainNode.gain.linearRampToValueAtTime(this.envelope.level,t);
			t += this.envelope.sustain;
			gainNode.gain.linearRampToValueAtTime(this.envelope.level,t);
			t += this.envelope.release;
			gainNode.gain.linearRampToValueAtTime(0,t);
		},
		
		send: function (notes) {
			//let f =440 * Math.pow(2,(i - 69) / 12);
			let f =440 * Math.pow(2,(notes[1] - 69) / 12);
			this.PlaySound(f);
		}
	};

	this.Render();*/

})

}})(jQuery);
