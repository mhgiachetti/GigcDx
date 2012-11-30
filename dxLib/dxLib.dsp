# Microsoft Developer Studio Project File - Name="dxLib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=dxLib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "dxLib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dxLib.mak" CFG="dxLib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dxLib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "dxLib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "dxLib - Win32 Release"

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

!ELSEIF  "$(CFG)" == "dxLib - Win32 Debug"

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
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /YX /FD /GZ /c
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

# Name "dxLib - Win32 Release"
# Name "dxLib - Win32 Debug"
# Begin Group "Utils"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\HighTimer.cpp
# End Source File
# Begin Source File

SOURCE=.\HighTimer.h
# End Source File
# Begin Source File

SOURCE=.\MeshLoader.cpp
# End Source File
# Begin Source File

SOURCE=.\MeshLoader.h
# End Source File
# Begin Source File

SOURCE=.\SimpleDeviceWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\SimpleDeviceWindow.h
# End Source File
# Begin Source File

SOURCE=.\XMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\XMesh.h
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Caps.h
# End Source File
# Begin Source File

SOURCE=.\ColorValue.h
# End Source File
# Begin Source File

SOURCE=.\CustomVertex.h
# End Source File
# Begin Source File

SOURCE=.\Device.h
# End Source File
# Begin Source File

SOURCE=.\DeviceCaps.h
# End Source File
# Begin Source File

SOURCE=.\dxLib.h
# End Source File
# Begin Source File

SOURCE=.\Effect.h
# End Source File
# Begin Source File

SOURCE=.\ExtendedMaterial.h
# End Source File
# Begin Source File

SOURCE=.\globalDefines.h
# End Source File
# Begin Source File

SOURCE=.\IndexBuffer.h
# End Source File
# Begin Source File

SOURCE=.\Light.h
# End Source File
# Begin Source File

SOURCE=.\Manager.h
# End Source File
# Begin Source File

SOURCE=.\Material.h
# End Source File
# Begin Source File

SOURCE=.\Matrix.h
# End Source File
# Begin Source File

SOURCE=.\Mesh.h
# End Source File
# Begin Source File

SOURCE=.\Path.h
# End Source File
# Begin Source File

SOURCE=.\PresentParameters.h
# End Source File
# Begin Source File

SOURCE=.\RenderState.h
# End Source File
# Begin Source File

SOURCE=.\SurfaceDescription.h
# End Source File
# Begin Source File

SOURCE=.\Texture.h
# End Source File
# Begin Source File

SOURCE=.\TextureLoader.h
# End Source File
# Begin Source File

SOURCE=.\Transform.h
# End Source File
# Begin Source File

SOURCE=.\Vector2.h
# End Source File
# Begin Source File

SOURCE=.\Vector3.h
# End Source File
# Begin Source File

SOURCE=.\Vector4.h
# End Source File
# Begin Source File

SOURCE=.\VertexBuffer.h
# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Caps.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorValue.cpp
# End Source File
# Begin Source File

SOURCE=.\Device.cpp
# End Source File
# Begin Source File

SOURCE=.\DeviceCaps.cpp
# End Source File
# Begin Source File

SOURCE=.\Effect.cpp
# End Source File
# Begin Source File

SOURCE=.\ExtendedMaterial.cpp
# End Source File
# Begin Source File

SOURCE=.\IndexBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\Light.cpp
# End Source File
# Begin Source File

SOURCE=.\Manager.cpp
# End Source File
# Begin Source File

SOURCE=.\Material.cpp
# End Source File
# Begin Source File

SOURCE=.\Matrix.cpp
# End Source File
# Begin Source File

SOURCE=.\Mesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Path.cpp
# End Source File
# Begin Source File

SOURCE=.\PresentParameters.cpp
# End Source File
# Begin Source File

SOURCE=.\RenderState.cpp
# End Source File
# Begin Source File

SOURCE=.\SurfaceDescription.cpp
# End Source File
# Begin Source File

SOURCE=.\Texture.cpp
# End Source File
# Begin Source File

SOURCE=.\TextureLoader.cpp
# End Source File
# Begin Source File

SOURCE=.\Transform.cpp
# End Source File
# Begin Source File

SOURCE=.\Vector2.cpp
# End Source File
# Begin Source File

SOURCE=.\Vector3.cpp
# End Source File
# Begin Source File

SOURCE=.\Vector4.cpp
# End Source File
# Begin Source File

SOURCE=.\VertexBuffer.cpp
# End Source File
# End Group
# End Target
# End Project
