let everyoneSynth = {
    init: false,
    channels: [],
    everyoneSynthInstance : null,
    InitSynth: function(waveType = 'square', envelope = {
        attack: 0.05,
        decay: 0.1,
        sustain: 0.5,
        release: 0.5,
        level: 0.5
    }) {
        if (this.init == false) {
            return;
        }

        this.init = true;
        this.channels = [];
        everyoneSynthInstance = this;
    },

    send: function(bytes) {
        if (bytes[0] >= 0xC0 && bytes[0] <= 0xC0 + 16) {
            let channel = bytes[0] - 0xC0 + 1;


            this.channels[channel] = {};
            this.channels[channel].audioContext = new AudioContext();
            this.channels[channel].oscillator = this.channels[channel].audioContext.createOscillator();
            this.channels[channel].oscillator.start(0);
            this.channels[channel].gainMain = this.channels[channel].audioContext.createGain();
            this.channels[channel].gainMain.value = 1;
            this.channels[channel].gainMain.connect(this.channels[channel].audioContext.destination);
            this.channels[channel].envelope = {
                attack: 0.05,
                decay: 0.1,
                sustain: 0.5,
                release: 0.5,
                level: 0.5
            };

            this.channels[channel].playSound = function(frequency) {
                if (this.audioContext == null) {
                    return;
                }

                let t = this.audioContext.currentTime;
                this.gainNode = this.audioContext.createGain();
                this.gainNode.connect(this.gainMain);
                this.oscillator.connect(this.gainNode);
                this.gainNode.gain.setValueAtTime(0, t);
                this.oscillator.frequency.value = frequency;
                t += this.envelope.attack;
                this.gainNode.gain.linearRampToValueAtTime(1, t);
                t += this.envelope.decay;
                this.gainNode.gain.linearRampToValueAtTime(this.envelope.level, t);
                t += this.envelope.sustain;
                this.gainNode.gain.linearRampToValueAtTime(this.envelope.level, t);
                t += this.envelope.release;
                this.gainNode.gain.linearRampToValueAtTime(0, t);
            };

            this.channels[channel].killSound = function(frequency) {
                this.oscillator.stop();
                //this.gainNode.gain.setValueAtTime(0, this.audioContext.currentTime);
            };

            console.log(this.channels);
        } else if (bytes[0] >= 0x90 && bytes[0] <= 0x90 + 16) {
        	let channel = bytes[0] - 0x90 + 1;            
            //let f =440 * Math.pow(2,(i - 69) / 12);
            let f = 440 * Math.pow(2, (bytes[1] - 69) / 12);
            console.log(channel);
            console.log(everyoneSynthInstance.channels);
            everyoneSynthInstance.channels[channel].playSound(f);
        } else if (bytes[0] >= 0x80 && bytes[0] <= 0x80 + 16) {
            everyoneSynthInstance.channels[bytes[0] - 0x80 + 1].killSound(null);
        }
    }
};