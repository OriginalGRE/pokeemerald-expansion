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
	msgbox PlayerHouse_2F_Text_Barry_1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER_HOUSE_2F_BARRY TwinleafTown_PlayerHouse_2F_Movement_BarryChecksPC
	waitmovement 0
	msgbox PlayerHouse2F_Text_Barry_2, MSGBOX_DEFAULT
	closemessage
	delay 10
	waitmovement 0 
	msgbox PlayerHouse2F_Text_Barry_3, MSGBOX_DEFAULT
	delay 10
	applymovement LOCALID_PLAYER_HOUSE_2F_BARRY TwinleafTown_PlayerHouse_2F_Movement_BarryReturn
	waitmovement 0
	msgbox PlayerHouse2F_Text_Barry_4, 
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

TwinleafTown_PlayerHouse_2F_Movement_BarryChecksPC:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

TwinleafTown_PlayerHouse_2F_Movement_BarryReturn:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	face_player
	step_end

TwinleafTown_PlayerHouse_2F_Movement_BarryLeaves:
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

PlayerHouse_2F_Text_Rowan:
	.string "That concludes our special program,\n"
	.string "“Let’s Ask Prof. Rowan!”\p"
	.string "Brought to you by Jubilife TV on\n"
	.string "Nationwide Net!$"

PlayerHouse_2F_Text_Barry_1:
	.string "Barry: There you are!\p"
	.string "Hey, {PLAYER}!\n"
	.string "Did you just see the TV? Sure you did!\p"
	.string "Prof. Rowan’s that really important\n"
	.string "guy who studies Pokémon, right?\p"
	.string "That means he must have lots and lots\n"
	.string "of Pokémon.\p"
	.string "So, if we ask him, I bet he’d give us\n"
	.string "some Pokémon!$"

PlayerHouse2F_Text_Barry_2:
	.string "Oh, hey!\n"
	.string "Is this a new PC?!$"

PlayerHouse2F_Text_Barry_3:
	.string "Barry: Uh...\n"
	.string "Where was I?$"

PlayerHouse2F_Text_Barry_4:
	.string "Oh, right, right!, We're going to go see\n"
	.string "Prof. Rowan and get some Pokémon.\p"
	.string "I'll be waiting outside.\p"
	.string "OK, {PLAYER}? If you're late, I'm\n"
	.string "Fining you ¥10 million!$"
