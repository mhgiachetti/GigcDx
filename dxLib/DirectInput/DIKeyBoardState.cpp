// DIKeyBoardState.cpp: implementation of the KeyBoardState class.
//
//////////////////////////////////////////////////////////////////////

#include "DIKeyBoardState.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

using namespace DirectInput;

DirectInput::KeyboardState::operator void*()
{
	return (void*)keys;
}

bool DirectInput::KeyboardState::operator[]( Key key ) const
{
	return keys[key];
}

bool DirectInput::KeyboardState::operator[]( int key ) const
{
	return keys[key];
}
