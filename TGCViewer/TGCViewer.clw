; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTGCViewerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TGCViewer.h"

ClassCount=3
Class1=CTGCViewerApp
Class2=CTGCViewerDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TGCVIEWER_DIALOG
Resource4=IDD_TGCVIEWER_DIALOG (Spanish (Modern))
Resource5=IDD_ABOUTBOX (Spanish (Modern))
Resource6=IDR_MENU1

[CLS:CTGCViewerApp]
Type=0
HeaderFile=TGCViewer.h
ImplementationFile=TGCViewer.cpp
Filter=N

[CLS:CTGCViewerDlg]
Type=0
HeaderFile=TGCViewerDlg.h
ImplementationFile=TGCViewerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_VER_WIREFRAME

[CLS:CAboutDlg]
Type=0
HeaderFile=TGCViewerDlg.h
ImplementationFile=TGCViewerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_TGCVIEWER_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CTGCViewerDlg

[DLG:IDD_TGCVIEWER_DIALOG (Spanish (Modern))]
Type=1
Class=CTGCViewerDlg
ControlCount=1
Control1=IDC_PANEL3D,static,1342177287

[DLG:IDD_ABOUTBOX (Spanish (Modern))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_VER_WIREFRAME
Command2=ID_VER_CAMARAPRIMERAPERSONA
Command3=ID_VER_CONTADORFPS
Command4=ID_VER_EJESCARTESIANOS
Command5=ID_VER_EJECUTARENFULLSCREEN
Command6=ID_VER_MOSTRARPOSICIONDELACAMARA
Command7=IDM_ABOUTBOX
CommandCount=7

