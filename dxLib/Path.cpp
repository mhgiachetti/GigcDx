// Path.cpp: implementation of the Path class.
//
//////////////////////////////////////////////////////////////////////

#include "Path.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Path::Path()
{

}

Path::~Path()
{

}

char Path::AltDirectorySeparatorChar()
{
	return '/';
}

char Path::DirectorySeparatorChar()
{
	//TODO: Revisar 
	return '\\';
}

char Path::PathSeparator()
{
	//TODO: Revisar
	return '\\';
}

char Path::VolumeSeparatorChar()
{
	return ':';
}

string Path::ChangeExtension( string path, string extension )
{
	int punto = path.find_last_of('.');
	if(punto == -1)
		punto = path.length();
	
	return path.substr(0,punto) + extension;
}

string Path::Combine( string path1, string path2 )
{
	return path1 + path2;
}

string Path::Combine3( string path1, string path2, string path3 )
{
	return path1 + path2 + path3;
}

string Path::GetDirectoryName( string path )
{
	int l = path.find_last_of(DirectorySeparatorChar());
	
	if(l == -1)
		l = path.find_last_of(AltDirectorySeparatorChar());
	
	if(l == -1)
		return "";
	
	return path.substr(0, l);
}

string Path::GetExtension( string path )
{
	int l = path.find_last_of('.');
	
	if(l == -1)
		return "";
	
	return path.substr(l);
}

string Path::GetFileName( string path )
{
	int l = path.find_last_of(DirectorySeparatorChar());
	
	if(l == -1)
		l = path.find_last_of(AltDirectorySeparatorChar());
	
	return path.substr(l + 1);
}

string Path::GetFileNameWithoutExtension( string path )
{
	int l = path.find_last_of(DirectorySeparatorChar());			
	
	if(l == -1)
		l = path.find_last_of(AltDirectorySeparatorChar());
	
	int extension = path.find_last_of('.');
	if(extension == -1)
		extension = path.length();
	
	return path.substr(l + 1, extension);
}

string Path::GetFullPath( string path )
{
	//TODO: falta revisar
	return path;
}

bool Path::HasExtension( string path )
{
	return GetExtension(path).length() > 1;
}

bool Path::IsPathRooted( string path )
{
	return path.find_first_of(VolumeSeparatorChar()) > -1;
}
