# Microsoft Developer Studio Project File - Name="tgcLib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=tgcLib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "tgcLib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "tgcLib.mak" CFG="tgcLib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "tgcLib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "tgcLib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "tgcLib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x2c0a /d "NDEBUG"
# ADD RSC /l 0x2c0a /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "tgcLib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x2c0a /d "_DEBUG"
# ADD RSC /l 0x2c0a /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "tgcLib - Win32 Release"
# Name "tgcLib - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\GuiController.cpp
# End Source File
# Begin Source File

SOURCE=.\HighResolutionTimer.cpp
# End Source File
# Begin Source File

SOURCE=.\IntMatrix.cpp
# End Source File
# Begin Source File

SOURCE=.\TgcD3dDevice.cpp
# End Source File
# Begin Source File

SOURCE=.\TgcD3dInput.cpp
# End Source File
# Begin Source File

SOURCE=.\TgcFpsCamera.cpp
# End Source File
# Begin Source File

SOURCE=.\TGCSimpleTerrain.cpp
# End Source File
# Begin Source File

SOURCE=.\TgcText2d.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\GuiController.h
# End Source File
# Begin Source File

SOURCE=.\HighResolutionTimer.h
# End Source File
# Begin Source File

SOURCE=.\IntMatrix.h
# End Source File
# Begin Source File

SOURCE=.\IRenderObject.h
# End Source File
# Begin Source File

SOURCE=.\TgcCamera.h
# End Source File
# Begin Source File

SOURCE=.\TgcD3dDevice.h
# End Source File
# Begin Source File

SOURCE=.\TgcD3dInput.h
# End Source File
# Begin Source File

SOURCE=.\TgcFpsCamera.h
# End Source File
# Begin Source File

SOURCE=.\TGCSimpleTerrain.h
# End Source File
# Begin Source File

SOURCE=.\TgcText2d.h
# End Source File
# End Group
# Begin Group "XMLParser"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\rapidxml.hpp
# End Source File
# Begin Source File

SOURCE=.\rapidxml_iterators.hpp
# End Source File
# Begin Source File

SOURCE=.\rapidxml_print.hpp
# End Source File
# Begin Source File

SOURCE=.\rapidxml_utils.hpp
# End Source File
# End Group
# End Target
# End Project
