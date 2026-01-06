PlayerHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PlayerHouse_2F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerHouse_2F_OnFrame
		.byte 0

PlayerHouse_2F_OnWarp:
	map_script_2 VAR_TWINLEAF_INTRO_STATE, 0, PlayerHouse_2F_EventScript_WatchTVIntro
	.2byte 0

PlayerHouse_2F_EventScript_WatchTVIntro::
	turnobject LOCALID_PLAYER, DIR_NORTH
	special TurnOnTVScreen
	end

PlayerHouse_2F_OnFrame:
	map_script_2 VAR_TWINLEAF_INTRO_STATE, 0, PlayerHouse_2F_EventScript_TV
	.2byte 0 

PlayerHouse_2F_EventScript_TV::
	lockall
	msgbox PlayerHouse_2F_Text_Rowan, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TWINLEAF_INTRO_STATE, 1
	special TurnOffTVScreen
	releaseall
	end

PlayerHouse_2F_Text_Rowan:
	.string "Prof. Rowan once again denies\n"
	.string "having ties to Jeffrey Epstein.$"