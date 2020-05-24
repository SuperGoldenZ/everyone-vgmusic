let lights = {
    RED_CHANNEL: 1,
    BLUE_CHANNEL: 2,
    WHITE_CHANNEL: 3,
    GREEN_CHANNEL: 4,
    INDIVIDUAL_FLASH: 9,
    state: null,
    flashSpeed: 500,
    channel: null,

    change_light_level: function(channel, level, updateState = true, speed = "fast") {
        var opacity = (level / 127.0) * 0.75;

        if (channel == lights.RED_CHANNEL) {
            $(".redLight").fadeTo(speed, opacity);
            if (updateState === true) {
                this.state = "static";
            }
        } else if (channel == lights.BLUE_CHANNEL) {
            $(".blueLight").fadeTo(speed, opacity);
            if (updateState === true) {
                this.state = "static";
            }
        } else if (channel == lights.WHITE_CHANNEL) {
            $(".whiteLight").fadeTo(speed, opacity);
            //$(".whiteLight").css("opacity", opacity);
            if (updateState === true) {
                this.state = "static";
            }
        } else if (channel == lights.GREEN_CHANNEL) {
            $(".greenLight").fadeTo(speed, opacity);
            //$(".greenLight").css("opacity", opacity);
            if (updateState === true) {
                this.state = "static";
            }
        } else if (channel == lights.INDIVIDUAL_FLASH) {
            if (level == 0 && updateState === true) {
                this.state = "static";
            } else {
                this.state = "individual_flash";
                setTimeout(lights.individual_flash, lights.flashSpeed);
            }
        }        
    },

    all_lights_off: function(updateState = true) {
        this.change_light_level(lights.RED_CHANNEL, 0, updateState);
        this.change_light_level(lights.BLUE_CHANNEL, 0, updateState);
        this.change_light_level(lights.GREEN_CHANNEL, 0, updateState);
        this.change_light_level(lights.WHITE_CHANNEL, 0, updateState);
    },

    individual_flash: function() {        
        if (lights.state != "static") {
            lights.all_lights_off(false);
            let channel = Math.floor(Math.random() * 4) + 1;
            lights.change_light_level(channel, 127, false);
            setTimeout(lights.individual_flash, lights.flashSpeed);
        }
    },

    panic_flash: function() {
        if (lights.state != "static") {
            console.log("in panic!");
            if (lights.channel == null) {
                lights.channel = 1;
            } else {
                lights.channel++;
                if (lights.channel == 5) {
                    lights.channel = 1;
                }
            }

            lights.all_lights_off(false);
            lights.change_light_level(lights.channel, 127, false);
            setTimeout(lights.panic_flash, lights.flashSpeed);
        }
    }
};