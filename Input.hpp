#pragma once

#include "Vector.hpp"

struct UserCmd {
  int     command_number;     // 0x04 For matching server and client commands for debugging
  int     tick_count;         // 0x08 the tick the client created this command
  Vec3		viewangles;         // 0x0C Player instantaneous view angles.
	Vec3		aimdirection;       // 0x18
  float   forwardmove;        // 0x24
  float   sidemove;           // 0x28
  float   upmove;             // 0x2C
  int     buttons;            // 0x30 Attack button states
  char    impulse;            // 0x34
  int     weaponselect;       // 0x38 Current weapon id
  int     weaponsubtype;      // 0x3C
  int     random_seed;        // 0x40 For shared random functions
  short   mousedx;            // 0x44 mouse accum in x from create move
  short   mousedy;            // 0x46 mouse accum in y from create move
  bool    hasbeenpredicted;   // 0x48 Client only, tracks whether we've predicted this command at least once
  char    pad_0x4C[0x18];     // 0x4C Current sizeof( usercmd ) =  100  = 0x64
};

struct VerifiedUserCmd {
	UserCmd m_cmd;
	unsigned long  m_crc;
};

struct Input {
	char                pad_0x00[0x0C];
	bool                trackIRAvailable;
	bool                mouseInitialized;
	bool                mouseActive;
	bool                joystickAdvancedInit;
	char                pad_0x08[0x2C];
	void*								m_pKeys;
	char                pad_0x38[0x6C];
	bool                cameraInterceptingMouse;
	bool                cameraInThirdPerson;
	bool                cameraMovingWithMouse;
	Vec3								vecCameraOffset;
	bool                cameraDistanceMove;
	int                 cameraOldX;
	int                 cameraOldY;
	int                 cameraX;
	int                 cameraY;
	bool                cameraIsOrthographic;
	Vec3								angPreviousViewAngles;
	Vec3								angPreviousViewAnglesTilt;
	float               flLastForwardMove;
	int                 clearInputState;
	char                pad_0xE4[0x8];
	/// <summary>
	/// 0xF4
	/// </summary>
	UserCmd*						commands;
	/// <summary>
	/// 0xF8
	/// </summary>
	VerifiedUserCmd*		verifiedCommands;
};