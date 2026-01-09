# Ambient Pond Ripples
## What is this? 
This is a feature branch of pokeemerald-expansion that implements `TimedRipplePerStepCallback` in `field_tasks.c`; a callback that periodically generates ripple animations on ponds and puddles. 

[Screencast from 07-01-26 17_21_16.webm](https://github.com/user-attachments/assets/9bcce8ef-6ed1-4c4a-8430-240d987120e7)

## How do I use it? 
Pull this branch to obtain the callback function. To enable pond ripples for a given map, set the callback through a mapscript using `setstepcallback STEP_CB_TIMED_RIPPLE`. 

As provided, the function attempts to create a ripple every 20 frames (3 times per second) in normal weather, or every 2 frames during rainy overworld weathers. These frequencies can easily be tweaked by adjusting `FREQ_RIPPLE` and `WEATHER_MULTIPLIER` in `field_tasks.c`. Note that the frame counter is reset before checking if a ripple can be generated, so the actual frequency of ripples depends on the amount of suitable water on-screen.

Finally, be aware that this feature can generate a lot of sprites on-screen - a ripple lasts around 1.5 seconds, so up to 45 could be active at once during rain. `FldEff_Ripple()` in `field_effect_helpers.c` already includes a check for the sprite limit, so I have not implemented further protections; if you need more free sprite slots it should be trivial to build in headroom there. 
