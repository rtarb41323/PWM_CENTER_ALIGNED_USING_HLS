

int PWM_rmt_dual_edge(bool *pwm_out,
					  volatile bool *dir_flag_out,
					  unsigned int half_period_ticks_in,
					  unsigned int on_time_ticks_in)
{
#pragma HLS INTERFACE ap_none	port=pwm_out
#pragma HLS INTERFACE ap_none   port=dir_flag_out
#pragma HLS INTERFACE s_axilite port=half_period_ticks_in  bundle=control
#pragma HLS INTERFACE s_axilite port=on_time_ticks_in      bundle=control
#pragma HLS INTERFACE s_axilite port=return                bundle=control
static unsigned int local_counter  = 0;
static bool         direction_flag = false; //"false" is positive direction (upward counting), "true" is negative direction

	if (direction_flag == false)
	{
		local_counter++;
		if (local_counter >= half_period_ticks_in) //switch counting direction if we are at the top of the period
		{
			direction_flag = true;
		}
	}
	else //direction_flag is true
	{
		local_counter--;
		if (local_counter == 0) //switch counting direction if we are at the bottom of the period
		{
			direction_flag = false;
		}
	}

	*dir_flag_out = direction_flag;
if (local_counter >= on_time_ticks_in) *pwm_out = false;
else *pwm_out = true;

////////////////////////////////////////////
//END of function
return 0;
}
