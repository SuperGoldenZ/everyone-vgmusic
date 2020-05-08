let lights = {
    RED_CHANNEL: 1,
    BLUE_CHANNEL: 2,
    WHITE_CHANNEL: 3,
    GREEN_CHANNEL: 4,
    INDIVIDUAL_FLASH: 9,
    state: null,

    change_light_level: function(channel, level, updateState= true) {        
        var opacity = (level / 127.0) * 0.75;

        if (channel == lights.RED_CHANNEL) {
            $(".redLight").css("opacity", opacity);
            if (updateState === true) {
                this.state = "static";
            }
        } else if (channel == lights.BLUE_CHANNEL) {
            $(".blueLight").css("opacity", opacity);
            if (updateState === true) {
                this.state = "static";
            }

        } else if (channel == lights.WHITE_CHANNEL) {

        } else if (channel == lights.GREEN_CHANNEL) {
            $(".greenLight").css("opacity", opacity);
            if (updateState === true) {
                this.state = "static";
            }            
        } else if (channel == lights.INDIVIDUAL_FLASH) {
            if (level == 0 && updateState === true) {
                this.state = "static";
            } else {
                this.state = "individual_flash";
                setTimeout(lights.individual_flash, 500);
            }
        }

        console.log("change_light_level: " + channel + " " + level + " " + updateState + " " + lights.state);
    },

    all_lights_off: function(updateState = true) {
        this.change_light_level(lights.RED_CHANNEL, 0, updateState);
        this.change_light_level(lights.BLUE_CHANNEL, 0, updateState);
        this.change_light_level(lights.GREEN_CHANNEL, 0, updateState);
    },

    individual_flash : function ()
    {
        console.log("individual_flash: " + lights.state);
        if (lights.state != "static") {
            lights.all_lights_off(false);
            let channel = Math.floor(Math.random() * 4) + 1;
            lights.change_light_level(channel, 127, false);
            setTimeout(lights.individual_flash, 500);   
        }
    }
};