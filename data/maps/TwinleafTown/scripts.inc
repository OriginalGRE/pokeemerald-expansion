TwinleafTown_MapScripts::
map_script MAP_SCRIPT_ON_RESUME, TwinleafTown_OnResume
	.byte 0

TwinleafTown_OnResume:
	setstepcallback STEP_CB_TIMED_RIPPLE
	end