// Path.h: interface for the Path class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MGPATH_H__B6CC2FAC_64F3_4BF0_9D8C_F1E9521DA8CB__INCLUDED_)
#define AFX_MGPATH_H__B6CC2FAC_64F3_4BF0_9D8C_F1E9521DA8CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
using namespace std;

class Path  
{
private:
	Path();
	virtual ~Path();
public:

		static char AltDirectorySeparatorChar();
		static char DirectorySeparatorChar();
		static char PathSeparator();
		static char VolumeSeparatorChar();
		static string ChangeExtension(string path, string extension);
		
		//static string CombineArray(paths : Array): String
		static string Combine(string path1, string path2);
		static string Combine3(string path1, string path2, string path3);
		static string GetDirectoryName(string path);
		static string GetExtension(string path);
		static string GetFileName(string path);
		static string GetFileNameWithoutExtension(string path);
		static string GetFullPath(string path);
		//static string GetPathRoot(string path);
		//static string GetTempFileName();
		//static string GetTempPath();
		static bool HasExtension(string path);
		static bool IsPathRooted(string path);

};

#endif // !defined(AFX_MGPATH_H__B6CC2FAC_64F3_4BF0_9D8C_F1E9521DA8CB__INCLUDED_)
