/*****************************************************************************
 * Copyright (c) 2014 Ted John, Kevin Burke
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * This file is part of OpenRCT2.
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#include "../addresses.h"
#include "../platform/osinterface.h"
#include "../util/sawyercoding.h"
#include "../util/util.h"
#include "ride.h"
#include "track.h"

/**
 *
 *  rct2: 0x00997C9D
 */
const rct_trackdefinition gTrackDefinitions[] = {
    // TYPE							VANGLE END					VANGLE START				BANK END				BANK START				SPECIAL
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_END_STATION
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_BEGIN_STATION
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_MIDDLE_STATION
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_UP
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_UP
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT_TO_25_DEG_UP
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_UP_TO_60_DEG_UP
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_UP_TO_25_DEG_UP
    { TRACK_FLAT,					TRACK_NONE,					TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_UP_TO_FLAT
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT_TO_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_DOWN_TO_60_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_DOWN_TO_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_DOWN_TO_FLAT
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_5_TILES
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_5_TILES
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT_TO_LEFT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT_TO_RIGHT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_BANK_TO_FLAT
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_BANK_TO_FLAT
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_BANKED_LEFT_QUARTER_TURN_5_TILES
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_BANKED_RIGHT_QUARTER_TURN_5_TILES
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_BANK_TO_25_DEG_UP
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_BANK_TO_25_DEG_UP
    { TRACK_FLAT,					TRACK_NONE,					TRACK_UP_25,				TRACK_BANK_LEFT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_UP_TO_LEFT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_UP_25,				TRACK_BANK_RIGHT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_UP_TO_RIGHT_BANK
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_BANK_TO_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_BANK_TO_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_25,				TRACK_BANK_LEFT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_DOWN_TO_LEFT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_25,				TRACK_BANK_RIGHT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_DOWN_TO_RIGHT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_BANK
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_5_TILES_25_DEG_UP
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_5_TILES_25_DEG_UP
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_5_TILES_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_5_TILES_25_DEG_DOWN
    { TRACK_S_BEND,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_S_BEND_LEFT
    { TRACK_S_BEND,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_S_BEND_RIGHT
    { TRACK_VERTICAL_LOOP,			TRACK_DOWN_25,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_UNKNOWN_VERTICAL_LOOP	},	// ELEM_LEFT_VERTICAL_LOOP
    { TRACK_VERTICAL_LOOP,			TRACK_DOWN_25,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_UNKNOWN_VERTICAL_LOOP	},	// ELEM_RIGHT_VERTICAL_LOOP
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_3_TILES
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_3_TILES
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_3_TILES_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_3_TILES_BANK
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_3_TILES_25_DEG_UP
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_3_TILES_25_DEG_UP
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_3_TILES_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_3_TILES_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_1_TILE
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_1_TILE
    { TRACK_TWIST,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_UPSIDE_DOWN,	TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_TWIST_DOWN_TO_UP
    { TRACK_TWIST,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_UPSIDE_DOWN,	TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_TWIST_DOWN_TO_UP
    { TRACK_TWIST,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_UPSIDE_DOWN,	TRACK_NONE					},	// ELEM_LEFT_TWIST_UP_TO_DOWN
    { TRACK_TWIST,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_UPSIDE_DOWN,	TRACK_NONE					},	// ELEM_RIGHT_TWIST_UP_TO_DOWN
    { TRACK_HALF_LOOP,				TRACK_NONE,					TRACK_UP_25,				TRACK_BANK_UPSIDE_DOWN,	TRACK_BANK_NONE,		TRACK_HALF_LOOP_UP			},	// ELEM_HALF_LOOP_UP
    { TRACK_HALF_LOOP,				TRACK_DOWN_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_UPSIDE_DOWN,	TRACK_HALF_LOOP_DOWN		},	// ELEM_HALF_LOOP_DOWN
    { TRACK_CORKSCREW,				TRACK_NONE,					TRACK_NONE,					TRACK_BANK_UPSIDE_DOWN,	TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_CORKSCREW_UP
    { TRACK_CORKSCREW,				TRACK_NONE,					TRACK_NONE,					TRACK_BANK_UPSIDE_DOWN,	TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_CORKSCREW_UP
    { TRACK_CORKSCREW,				TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_UPSIDE_DOWN,	TRACK_CORKSCREW_DOWN		},	// ELEM_LEFT_CORKSCREW_DOWN
    { TRACK_CORKSCREW,				TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_UPSIDE_DOWN,	TRACK_CORKSCREW_DOWN		},	// ELEM_RIGHT_CORKSCREW_DOWN
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT_TO_60_DEG_UP
    { TRACK_FLAT,					TRACK_NONE,					TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_UP_TO_FLAT
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT_TO_60_DEG_DOWN
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_DOWN_TO_FLAT
    { TRACK_TOWER_BASE,				TRACK_VANGLE_TOWER,			TRACK_VANGLE_TOWER,			TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_TOWER_BASE
    { TRACK_TOWER_BASE,				TRACK_VANGLE_TOWER,			TRACK_VANGLE_TOWER,			TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_TOWER_SECTION
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT_COVERED
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_UP_COVERED
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_UP_COVERED
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT_TO_25_DEG_UP_COVERED
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_UP_TO_60_DEG_UP_COVERED
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_UP_TO_25_DEG_UP_COVERED
    { TRACK_FLAT,					TRACK_NONE,					TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_UP_TO_FLAT_COVERED
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_DOWN_COVERED
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_DOWN_COVERED
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT_TO_25_DEG_DOWN_COVERED
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_DOWN_TO_60_DEG_DOWN_COVERED
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_DOWN_TO_25_DEG_DOWN_COVERED
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_25_DEG_DOWN_TO_FLAT_COVERED
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_5_TILES_COVERED
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_5_TILES_COVERED
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_S_BEND_LEFT_COVERED
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_S_BEND_RIGHT_COVERED
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_3_TILES_COVERED
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_3_TILES_COVERED
    { TRACK_HELIX_SMALL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_HALF_BANKED_HELIX_UP_SMALL
    { TRACK_HELIX_SMALL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_HALF_BANKED_HELIX_UP_SMALL
    { TRACK_HELIX_SMALL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_HALF_BANKED_HELIX_DOWN_SMALL
    { TRACK_HELIX_SMALL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_HALF_BANKED_HELIX_DOWN_SMALL
    { TRACK_HELIX_SMALL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_HALF_BANKED_HELIX_UP_LARGE
    { TRACK_HELIX_SMALL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_HALF_BANKED_HELIX_UP_LARGE
    { TRACK_HELIX_SMALL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_HALF_BANKED_HELIX_DOWN_LARGE
    { TRACK_HELIX_SMALL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_HALF_BANKED_HELIX_DOWN_LARGE
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_1_TILE_60_DEG_UP
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_1_TILE_60_DEG_UP
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_1_TILE_60_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_1_TILE_60_DEG_DOWN
    { TRACK_BRAKES,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_BRAKES
    { TRACK_ROTATION_CONTROL_TOGGLE,TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_ROTATION_CONTROL_TOGGLE
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_INVERTED_90_DEG_UP_TO_FLAT_QUARTER_LOOP
    { TRACK_HELIX_LARGE,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_BANKED_HELIX_LARGE_UP
    { TRACK_HELIX_LARGE,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_BANKED_HELIX_LARGE_UP
    { TRACK_HELIX_LARGE,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_BANKED_HELIX_LARGE_DOWN
    { TRACK_HELIX_LARGE,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_BANKED_HELIX_LARGE_DOWN
    { TRACK_HELIX_LARGE_UNBANKED,	TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_HELIX_LARGE_UP
    { TRACK_HELIX_LARGE_UNBANKED,	TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_HELIX_LARGE_UP
    { TRACK_HELIX_LARGE_UNBANKED,	TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_HELIX_LARGE_DOWN
    { TRACK_HELIX_LARGE_UNBANKED,	TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_HELIX_LARGE_DOWN
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_25,				TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_25_DEG_UP_LEFT_BANKED
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_25,				TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_25_DEG_UP_RIGHT_BANKED
    { TRACK_WATERFALL,				TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_WATERFALL
    { TRACK_RAPIDS,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RAPIDS
    { TRACK_ON_RIDE_PHOTO,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_ON_RIDE_PHOTO
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_25,				TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_25_DEG_DOWN_LEFT_BANKED
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_25,				TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_25_DEG_DOWN_RIGHT_BANKED
    { TRACK_WATER_SPLASH,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_WATER_SPLASH
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT_TO_60_DEG_UP_LONG_BASE
    { TRACK_FLAT,					TRACK_NONE,					TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_UP_TO_FLAT_LONG_BASE
    { TRACK_WHIRLPOOL,				TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_WHIRLPOOL
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_FLAT_TO_60_DEG_DOWN_LONG_BASE
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_UP_TO_FLAT_LONG_BASE
    { TRACK_LIFT_HILL,				TRACK_DOWN_60,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_CABLE_LIFT_HILL
    { TRACK_WHOA_BELLY,				TRACK_VANGLE_WHOA_BELLY,	TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_REVERSE_WHOA_BELLY_SLOPE
    { TRACK_WHOA_BELLY,				TRACK_VANGLE_WHOA_BELLY,	TRACK_VANGLE_WHOA_BELLY,	TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_REVERSE_WHOA_BELLY_VERTICAL
    { TRACK_FLAT,					TRACK_UP_90,				TRACK_UP_90,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_90_DEG_UP
    { TRACK_FLAT,					TRACK_DOWN_90,				TRACK_DOWN_90,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_90_DEG_DOWN
    { TRACK_FLAT,					TRACK_UP_90,				TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_UP_TO_90_DEG_UP
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_DOWN_90,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_90_DEG_DOWN_TO_60_DEG_DOWN
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_UP_90,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_90_DEG_UP_TO_60_DEG_UP
    { TRACK_FLAT,					TRACK_DOWN_90,				TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_60_DEG_DOWN_TO_90_DEG_DOWN
    { TRACK_BRAKE_FOR_DROP,			TRACK_DOWN_60,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_BRAKE_FOR_DROP
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_EIGHTH_TO_DIAG
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_EIGHTH_TO_DIAG
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_EIGHTH_TO_ORTHOGONAL
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_EIGHTH_TO_ORTHOGONAL
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_EIGHTH_BANK_TO_DIAG
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_EIGHTH_BANK_TO_DIAG
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_EIGHTH_BANK_TO_ORTHOGONAL
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_EIGHTH_BANK_TO_ORTHOGONAL
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_FLAT
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_25_DEG_UP
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_60_DEG_UP
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_FLAT_TO_25_DEG_UP
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_25_DEG_UP_TO_60_DEG_UP
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_60_DEG_UP_TO_25_DEG_UP
    { TRACK_FLAT,					TRACK_NONE,					TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_25_DEG_UP_TO_FLAT
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_60_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_FLAT_TO_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_25_DEG_DOWN_TO_60_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_60_DEG_DOWN_TO_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_25_DEG_DOWN_TO_FLAT
    { TRACK_FLAT,					TRACK_UP_60,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_FLAT_TO_60_DEG_UP
    { TRACK_FLAT,					TRACK_NONE,					TRACK_UP_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_60_DEG_UP_TO_FLAT
    { TRACK_FLAT,					TRACK_DOWN_60,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_FLAT_TO_60_DEG_DOWN
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_60,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_60_DEG_DOWN_TO_FLAT
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_FLAT_TO_LEFT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_FLAT_TO_RIGHT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_DIAG_LEFT_BANK_TO_FLAT
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_DIAG_RIGHT_BANK_TO_FLAT
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_DIAG_LEFT_BANK_TO_25_DEG_UP
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_DIAG_RIGHT_BANK_TO_25_DEG_UP
    { TRACK_FLAT,					TRACK_NONE,					TRACK_UP_25,				TRACK_BANK_LEFT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_25_DEG_UP_TO_LEFT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_UP_25,				TRACK_BANK_RIGHT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_25_DEG_UP_TO_RIGHT_BANK
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_DIAG_LEFT_BANK_TO_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_DOWN_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_DIAG_RIGHT_BANK_TO_25_DEG_DOWN
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_25,				TRACK_BANK_LEFT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_25_DEG_DOWN_TO_LEFT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_25,				TRACK_BANK_RIGHT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_DIAG_25_DEG_DOWN_TO_RIGHT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_LEFT,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_DIAG_LEFT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_NONE,					TRACK_BANK_RIGHT,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_DIAG_RIGHT_BANK
    { TRACK_LOG_FLUME_REVERSER,		TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LOG_FLUME_REVERSER
    { TRACK_SPINNING_TUNNEL,		TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_SPINNING_TUNNEL
    { TRACK_BARREL_ROLL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_UPSIDE_DOWN,	TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_BARREL_ROLL_UP_TO_DOWN
    { TRACK_BARREL_ROLL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_UPSIDE_DOWN,	TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_BARREL_ROLL_UP_TO_DOWN
    { TRACK_BARREL_ROLL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_UPSIDE_DOWN,	TRACK_NONE					},	// ELEM_LEFT_BARREL_ROLL_DOWN_TO_UP
    { TRACK_BARREL_ROLL,			TRACK_NONE,					TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_UPSIDE_DOWN,	TRACK_NONE					},	// ELEM_RIGHT_BARREL_ROLL_DOWN_TO_UP
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_LEFT,		TRACK_NONE					},	// ELEM_LEFT_BANK_TO_LEFT_QUARTER_TURN_3_TILES_25_DEG_UP
    { TRACK_FLAT,					TRACK_UP_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_RIGHT,		TRACK_NONE					},	// ELEM_RIGHT_BANK_TO_RIGHT_QUARTER_TURN_3_TILES_25_DEG_UP
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_25,				TRACK_BANK_LEFT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_LEFT_QUARTER_TURN_3_TILES_25_DEG_DOWN_TO_LEFT_BANK
    { TRACK_FLAT,					TRACK_NONE,					TRACK_DOWN_25,				TRACK_BANK_RIGHT,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_RIGHT_QUARTER_TURN_3_TILES_25_DEG_DOWN_TO_RIGHT_BANK
    { TRACK_POWERED_LIFT,			TRACK_UP_25,				TRACK_UP_25,				TRACK_BANK_NONE,		TRACK_BANK_NONE,		TRACK_NONE					},	// ELEM_POWERED_LIFT
    { TRACK_HALF_LOOP_2,			TRACK_NONE,					TRACK_UP_25,				TRACK_BANK_UPSIDE_DOWN,	TRACK_BANK_NONE,		TRACK_HALF_LOOP_UP			},	// ELEM_LEFT_LARGE_HALF_LOOP_UP
    { TRACK_HALF_LOOP_2,			TRACK_NONE,					TRACK_UP_25,				TRACK_BANK_UPSIDE_DOWN,	TRACK_BANK_NONE,		TRACK_HALF_LOOP_UP			},	// ELEM_RIGHT_LARGE_HALF_LOOP_UP
    { TRACK_HALF_LOOP_2,			TRACK_DOWN_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_UPSIDE_DOWN,	TRACK_HALF_LOOP_DOWN		},	// ELEM_RIGHT_LARGE_HALF_LOOP_DOWN
    { TRACK_HALF_LOOP_2,			TRACK_DOWN_25,				TRACK_NONE,					TRACK_BANK_NONE,		TRACK_BANK_UPSIDE_DOWN,	TRACK_HALF_LOOP_DOWN		},	// ELEM_LEFT_LARGE_HALF_LOOP_DOWN
};

/**
 *
 *  rct2: 0x006CED50
 */
void track_load_list(ride_list_item item)
{
    RCT2_CALLPROC_X(0x006CED50, 0, 0, 0, *((uint16*)&item), 0, 0, 0);
}

static void read(void *dst, void **src, int length)
{
	memcpy(dst, *src, length);
	*((char**)src) += length;
}

/**
 *
 *  rct2: 0x0067726A
 * path: 0x0141EF68
 */
int sub_67726A(const char *path)
{
	FILE *fp;
	long fpLength;
	const char *ch;
	char trackFilename[MAX_PATH], *fpBuffer, *decoded, *src, *dst;
	int i, decodedLength;
	uint8* edi;

	RCT2_GLOBAL(0x009AAC54, uint8) = 1;
	
	// Get filename
	ch = strrchr(path, '\\');
	ch = ch == NULL ? path : ch + 1;
	dst = trackFilename;
	while (*ch != 0 && *ch != '.') {
		*dst++ = *ch++;
	}
	*dst = 0;

	fp = fopen(path, "rb");
	if (fp == NULL)
		return 0;

	// Read whole file into a buffer
	fpLength = fsize(fp);
	fpBuffer = malloc(fpLength);
	fread(fpBuffer, fpLength, 1, fp);
	fclose(fp);

	// Validate the checksum
	// Not the same checksum algorithm as scenarios and saved games
	// sub_6770C1();

	// Decode the track data
	decoded = malloc(0x10000);
	decodedLength = sawyercoding_decode_td6(fpBuffer, decoded, fpLength);
	realloc(decoded, decodedLength);
	free(fpBuffer);

	// Read decoded data
	src = decoded;
	memset((void*)0x009D81D8, 0, 67);
	read((void*)0x009D8178, &src, 32);

	uint8 al = RCT2_GLOBAL(0x009D817F, uint8) >> 2;
	if (al >= 2)
		read((void*)0x009D8198, &src, 40);

	read((void*)0x009D81C0, &src, 24);
	al = RCT2_GLOBAL(0x009D817F, uint8) >> 2;
	if (al != 0)
		read((void*)0x009D81D8, &src, al == 1 ? 140 : 67);

	read((void*)0x009D821B, &src, 24572);
	al = RCT2_GLOBAL(0x009D817F, uint8) >> 2;
	if (al < 2) {
		if (RCT2_GLOBAL(0x009D8178, uint8) == 20) {
			edi = (uint8*)0x009D821B;
			while (*edi != 0) {
				edi += 4;
			}
			edi += 4;
			memset(edi, 255, (uint8*)0x009DE217 - edi);
		} else {
			edi = (uint8*)0x009D821B;
			while (*edi != 255) {
				edi += 2;
			}
			edi++;
			memset(edi, 255, (uint8*)0x009DE217 - edi);
		}
	}
	free(decoded);

	// 
	al = RCT2_GLOBAL(0x009D817F, uint8) >> 2;
	if (al > 2)
		return 0;

	if (al <= 1) {
		edi = (uint8*)0x009D8180;
		for (i = 0; i < 67; i++)
			*edi++ = RCT2_ADDRESS(0x0097F0BC, uint8)[*edi];

		edi = (uint8*)0x009D81D8;
		for (i = 0; i < 12; i++)
			*edi++ = RCT2_ADDRESS(0x0097F0BC, uint8)[*edi];

		RCT2_GLOBAL(0x009D81D2, uint8) >>= 1;
		if (!RCT2_CALLPROC_X(0x00677530, 0, 0, 0, 0, 0, 0, 0))
			RCT2_GLOBAL(0x009D8178, uint8) = 255;

		if (RCT2_GLOBAL(0x009D8178, uint8) == 4)
			RCT2_GLOBAL(0x009D8178, uint8) = 255;

		if (RCT2_GLOBAL(0x009D8178, uint8) == 0)
			RCT2_GLOBAL(0x009D8178, uint8) = 52;

		if (RCT2_GLOBAL(0x009D8178, uint8) == 19) {
			if (RCT2_GLOBAL(0x009D817E, uint8) == 3)
				RCT2_GLOBAL(0x009D817E, uint8) = 35;
			if (RCT2_GLOBAL(0x009D8179, uint8) == 79) {
				if (RCT2_GLOBAL(0x009D817E, uint8) == 2)
					RCT2_GLOBAL(0x009D817E, uint8) = 1;
			}
		}

		int unk1 = RCT2_GLOBAL(0x009D8179, uint8);
		if (RCT2_GLOBAL(0x009D8178, uint8) == 20) {
			unk1 = 0x0097F66C;
		} else {
			if (unk1 == 3 && RCT2_GLOBAL(0x009D8178, uint8) == 3)
				unk1 = 80;
			unk1 = 0x0097F0DC + (unk1 * 16);
		}

		memcpy((void*)0x009D81E8, (void*)unk1, 16);
		for (i = 0; i < 32; i++)
			RCT2_ADDRESS(0x009D81FA, uint8)[i] = RCT2_ADDRESS(0x009D8181, uint8)[i * 2];

		RCT2_GLOBAL(0x009D81F8, uint8) = 255;
		RCT2_GLOBAL(0x009D81F9, uint8) = 255;
		RCT2_GLOBAL(0x009D821A, uint8) = 5;
	}

	RCT2_GLOBAL(0x009D81C8, uint8) = min(
		RCT2_GLOBAL(0x009D81C8, uint8),
		RCT2_GLOBAL(RCT2_ADDRESS_RIDE_FLAGS + 5 + (RCT2_GLOBAL(0x009D8178, uint8) * 8), uint8)
	);

	return 1;
}

/**
 * 
 * I don't think preview is a necessary output argument. It can be obtained easily using the track design structure.
 *  rct2: 0x006D1DEC
 */
rct_track_design *track_get_info(int index, uint8** preview)
{
	rct_track_design *trackDesign;
	uint8 *trackDesignList = (uint8*)0x00F441EC;
	int i;

	trackDesign = NULL;

	// Check if track design has already been loaded
	for (i = 0; i < 4; i++) {
		if (index == RCT2_ADDRESS(0x00F44109, uint32)[i]) {
			trackDesign = &RCT2_GLOBAL(0x00F44105, rct_track_design*)[i];
			break;
		}
	}

	if (trackDesign == NULL) {
		// Load track design
		i = RCT2_GLOBAL(0x00F44119, uint32);
		RCT2_GLOBAL(0x00F44119, uint32)++;
		if (RCT2_GLOBAL(0x00F44119, uint32) >= 4)
			RCT2_GLOBAL(0x00F44119, uint32) = 0;

		RCT2_ADDRESS(0x00F44109, uint32)[i] = index;
		subsitute_path((char*)0x0141EF68, (char*)RCT2_ADDRESS_TRACKS_PATH, trackDesignList + (index * 128));
		if (!sub_67726A((char*)0x0141EF68)) {
			if (preview != NULL) *preview = NULL;
			return NULL;
		}

		trackDesign = &RCT2_GLOBAL(0x00F44105, rct_track_design*)[i];

		memcpy(trackDesign, (void*)0x009D8178, 163);
		RCT2_CALLPROC_EBPSAFE(0x006D1EF0);

		trackDesign->cost = RCT2_GLOBAL(0x00F4411D, money32);
		trackDesign->var_06 = RCT2_GLOBAL(0x00F44151, uint8) & 7;
	}

	// Set preview to correct preview image based on rotation
	if (preview != NULL)
		*preview = trackDesign->preview[RCT2_GLOBAL(0x00F440AE, uint8)];

	return trackDesign;
}

/**
 * 
 *  rct2: 0x006D3664
 */
int track_rename(const char *text)
{
	return (RCT2_CALLPROC_X(0x006D3664, 0, 0, 0, (int)text, 0, 0, 0) & 0x100) != 0;
}

/**
 * 
 *  rct2: 0x006D3761
 */
int track_delete()
{
	return (RCT2_CALLPROC_X(0x006D3761, 0, 0, 0, 0, 0, 0, 0) & 0x100) != 0;
}