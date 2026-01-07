LakeVerity_MapScripts::
map_script MAP_SCRIPT_ON_RESUME, LakeVerity_OnResume
	.byte 0

LakeVerity_OnResume:
	setstepcallback STEP_CB_TIMED_RIPPLE
	end