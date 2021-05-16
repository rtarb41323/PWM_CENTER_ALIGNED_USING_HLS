# PWM_CENTER_ALIGNED_USING_HLS
There are ready-made blocks for PWM generation using Verilog or VHDL, but most of them use left-aligned (or leading-edge) PWM.

Using HLS, this repo is an attempt to show a simple example of center-aligned PWM.  The block is configured using the AXI Lite bus.

The outputs are:
1. The PWM output 
2. The counter direction output "*dir_flag_out".  This is high when the PWM counter "local_counter" is counting from 0 to "half-period_ticks_in",
and low when the counter is counting from "half-period_ticks_in" back to 0.

The "*dir_flag_out" output can be used to synchronously trigger an external ADC channel, so that the external ADC will take its measurement in the middle 
of a PWM ramp, and not on the switching edge (where hash noise and artifacts can alter the ADC reading).
