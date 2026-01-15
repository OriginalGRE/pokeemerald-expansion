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
	delay 10
	msgbox PlayerHouse_2F_Text_Rowan, MSGBOX_DEFAULT
	closemessage
	special TurnOffTVScreen
	delay 10
	setvar VAR_TWINLEAF_INTRO_STATE, 1
	goto_if_eq VAR_TWINLEAF_INTRO_STATE, 1, PlayerHouse_2F_EventScript_Barry
	releaseall
	end

PlayerHouse_2F_EventScript_Barry::
	lockall
	addobject LOCALID_PLAYER_HOUSE_2F_BARRY
	playSE SE_EXIT
	applymovement LOCALID_PLAYER_HOUSE_2F_BARRY TwinleafTown_PlayerHouse_2F_Movement_BarryEnters
	waitmovement 0
	playse SE_WALL_HIT
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	turnobject LOCALID_PLAYER, DIR_EAST
	delay 10 
	msgbox PlayerHouse_2F_Text_Barry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER_HOUSE_2F_BARRY TwinleafTown_PlayerHouse_2F_Movement_BarryLeaves
	waitmovement 0
	playse SE_EXIT
	setvar VAR_TWINLEAF_INTRO_STATE, 2
	removeobject LOCALID_PLAYER_HOUSE_2F_BARRY
	releaseall
	end

TwinleafTown_PlayerHouse_2F_Movement_BarryEnters:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_in_place_fast_left
	step_end


TwinleafTown_PlayerHouse_2F_Movement_BarryLeaves:
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

PlayerHouse_2F_Text_Rowan:
	.string "Prof. Rowan once again denies\n"
	.string "having ties to Jeffrey Epstein.\p"
	.string "The academic has stated:\p"
	.string "”I simply prefer underage assistants\n"
	.string "because I don't have to pay them!”$"

PlayerHouse_2F_Text_Barry:
	.string "Hey, I'm totally your rival Barry!\n"
	.string "I'm just using placeholder graphics...\p"
	.string "blah blah blah get pokemon blah blah\p"
	.string "blah blah 10 kazillion dollars\n"
	.string "don't be late!$"

