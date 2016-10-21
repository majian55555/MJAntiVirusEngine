# Microsoft Developer Studio Project File - Name="MJAntiVirus" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MJAntiVirus - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MJAntiVirus.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MJAntiVirus.mak" CFG="MJAntiVirus - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MJAntiVirus - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MJAntiVirus - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MJAntiVirus - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 dll/HookDLL.lib dll/AntiVirusDLL2.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "MJAntiVirus - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 dll/HookDLL.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "MJAntiVirus - Win32 Release"
# Name "MJAntiVirus - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\agentctlanimationnames.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlaudioobjectex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlballoonex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcharacterex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcharacters.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcommand.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandsex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandswindow.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlex.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlpropertysheet.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlrequest.cpp
# End Source File
# Begin Source File

SOURCE=.\agentctlspeechinput.cpp
# End Source File
# Begin Source File

SOURCE=.\CVirus.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgComputerInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgScanSet.cpp
# End Source File
# Begin Source File

SOURCE=.\FileEncryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FolderEncryDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\IconMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\Label.cpp
# End Source File
# Begin Source File

SOURCE=.\ListButton.cpp
# End Source File
# Begin Source File

SOURCE=.\LockDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LockOrSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MJAntiVirus.cpp
# End Source File
# Begin Source File

SOURCE=.\MJAntiVirus.rc
# End Source File
# Begin Source File

SOURCE=.\MJAntiVirusAboutDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MJAntiVirusDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Mysocket.cpp
# End Source File
# Begin Source File

SOURCE=.\NetMoniDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\OutlookList.cpp
# End Source File
# Begin Source File

SOURCE=.\RegDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SetPasswordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SetProp1.cpp
# End Source File
# Begin Source File

SOURCE=.\SetProp2.cpp
# End Source File
# Begin Source File

SOURCE=.\SetProp3.cpp
# End Source File
# Begin Source File

SOURCE=.\SetPropSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\SreenProtectDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SysMoniDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\agentctlanimationnames.h
# End Source File
# Begin Source File

SOURCE=.\agentctlaudioobjectex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlballoonex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcharacterex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcharacters.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcommand.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandsex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlcommandswindow.h
# End Source File
# Begin Source File

SOURCE=.\agentctlex.h
# End Source File
# Begin Source File

SOURCE=.\agentctlpropertysheet.h
# End Source File
# Begin Source File

SOURCE=.\agentctlrequest.h
# End Source File
# Begin Source File

SOURCE=.\agentctlspeechinput.h
# End Source File
# Begin Source File

SOURCE=.\CVirus.h
# End Source File
# Begin Source File

SOURCE=.\DlgComputerInfo.h
# End Source File
# Begin Source File

SOURCE=.\DlgScanSet.h
# End Source File
# Begin Source File

SOURCE=.\FileEncryDlg.h
# End Source File
# Begin Source File

SOURCE=.\FolderEncryDlg.h
# End Source File
# Begin Source File

SOURCE=.\IconMenu.h
# End Source File
# Begin Source File

SOURCE=.\Label.h
# End Source File
# Begin Source File

SOURCE=.\ListButton.h
# End Source File
# Begin Source File

SOURCE=.\LockDlg.h
# End Source File
# Begin Source File

SOURCE=.\LockOrSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\MJAntiVirus.h
# End Source File
# Begin Source File

SOURCE=.\MJAntiVirusAboutDlg.h
# End Source File
# Begin Source File

SOURCE=.\MJAntiVirusDlg.h
# End Source File
# Begin Source File

SOURCE=.\Mysocket.h
# End Source File
# Begin Source File

SOURCE=.\NetMoniDlg.h
# End Source File
# Begin Source File

SOURCE=.\OutlookList.h
# End Source File
# Begin Source File

SOURCE=.\RegDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SetPasswordDlg.h
# End Source File
# Begin Source File

SOURCE=.\SetProp1.h
# End Source File
# Begin Source File

SOURCE=.\SetProp2.h
# End Source File
# Begin Source File

SOURCE=.\SetProp3.h
# End Source File
# Begin Source File

SOURCE=.\SetPropSheet.h
# End Source File
# Begin Source File

SOURCE=.\SreenProtectDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SysMoniDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\5-搬家.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\AvP PH.ico"
# End Source File
# Begin Source File

SOURCE=".\res\AvP PH2.ico"
# End Source File
# Begin Source File

SOURCE=".\res\AvP PH3.ico"
# End Source File
# Begin Source File

SOURCE=.\res\cdrom.ico
# End Source File
# Begin Source File

SOURCE=".\res\Diablo II 2.ico"
# End Source File
# Begin Source File

SOURCE=".\res\Diablo II.ico"
# End Source File
# Begin Source File

SOURCE=.\res\document.ico
# End Source File
# Begin Source File

SOURCE=.\res\harddisk.ico
# End Source File
# Begin Source File

SOURCE=.\res\ITEM.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LEFT.bmp
# End Source File
# Begin Source File

SOURCE=".\res\Max Payne XP.ico"
# End Source File
# Begin Source File

SOURCE=.\res\memory.ico
# End Source File
# Begin Source File

SOURCE=.\res\MJAntiVirus.ico
# End Source File
# Begin Source File

SOURCE=.\res\MJAntiVirus.rc2
# End Source File
# Begin Source File

SOURCE=.\res\mycomputer.ico
# End Source File
# Begin Source File

SOURCE=".\res\Sims XP.ico"
# End Source File
# Begin Source File

SOURCE=".\res\Spiderman - The Movie.ico"
# End Source File
# Begin Source File

SOURCE=.\res\sysfile.ico
# End Source File
# Begin Source File

SOURCE=.\res\usb.ico
# End Source File
# Begin Source File

SOURCE=".\res\遍地黄花分外香6.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\美丽的赛里木湖畔.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\美丽赛里木湖畔11.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\塞里木湖野天鹅.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\塞里木湖野鸭子.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\辛勤的摄影师.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section MJAntiVirus : {8563FF20-8ECC-11D1-B9B4-00C04FD97575}
# 	2:5:Class:CAgentCtlEx
# 	2:10:HeaderFile:agentctlex.h
# 	2:8:ImplFile:agentctlex.cpp
# End Section
# Section MJAntiVirus : {822DB1C0-8879-11D1-9EC6-00C04FD7081F}
# 	2:5:Class:CAgentCtlBalloonEx
# 	2:10:HeaderFile:agentctlballoonex.h
# 	2:8:ImplFile:agentctlballoonex.cpp
# End Section
# Section MJAntiVirus : {8B77181C-D3EF-11D1-8500-00C04FA34A14}
# 	2:5:Class:CAgentCtlAnimationNames
# 	2:10:HeaderFile:agentctlanimationnames.h
# 	2:8:ImplFile:agentctlanimationnames.cpp
# End Section
# Section MJAntiVirus : {F5BE8BE8-7DE6-11D0-91FE-00C04FD701A5}
# 	2:5:Class:CAgentCtlCharacters
# 	2:10:HeaderFile:agentctlcharacters.h
# 	2:8:ImplFile:agentctlcharacters.cpp
# End Section
# Section MJAntiVirus : {B0913410-3B44-11D1-ACBA-00C04FD97575}
# 	2:5:Class:CAgentCtlCommandEx
# 	2:10:HeaderFile:agentctlcommandex.h
# 	2:8:ImplFile:agentctlcommandex.cpp
# End Section
# Section MJAntiVirus : {F5BE8BDF-7DE6-11D0-91FE-00C04FD701A5}
# 	2:5:Class:CAgentCtlPropertySheet
# 	2:10:HeaderFile:agentctlpropertysheet.h
# 	2:8:ImplFile:agentctlpropertysheet.cpp
# End Section
# Section MJAntiVirus : {F5BE8BE3-7DE6-11D0-91FE-00C04FD701A5}
# 	2:5:Class:CAgentCtlCommand
# 	2:10:HeaderFile:agentctlcommand.h
# 	2:8:ImplFile:agentctlcommand.cpp
# End Section
# Section MJAntiVirus : {D45FD31B-5C6E-11D1-9EC1-00C04FD7081F}
# 	2:21:DefaultSinkHeaderFile:agentctlex.h
# 	2:16:DefaultSinkClass:CAgentCtlEx
# End Section
# Section MJAntiVirus : {6BA90C01-3910-11D1-ACB3-00C04FD97575}
# 	2:5:Class:CAgentCtlCommandsEx
# 	2:10:HeaderFile:agentctlcommandsex.h
# 	2:8:ImplFile:agentctlcommandsex.cpp
# End Section
# Section MJAntiVirus : {F5BE8BDD-7DE6-11D0-91FE-00C04FD701A5}
# 	2:5:Class:CAgentCtlSpeechInput
# 	2:10:HeaderFile:agentctlspeechinput.h
# 	2:8:ImplFile:agentctlspeechinput.cpp
# End Section
# Section MJAntiVirus : {6D0ECB27-9968-11D0-AC6E-00C04FD97575}
# 	2:5:Class:CAgentCtlCommandsWindow
# 	2:10:HeaderFile:agentctlcommandswindow.h
# 	2:8:ImplFile:agentctlcommandswindow.cpp
# End Section
# Section MJAntiVirus : {1DAB85C3-803A-11D0-AC63-00C04FD97575}
# 	2:5:Class:CAgentCtlRequest
# 	2:10:HeaderFile:agentctlrequest.h
# 	2:8:ImplFile:agentctlrequest.cpp
# End Section
# Section MJAntiVirus : {DE8EF600-2F82-11D1-ACAC-00C04FD97575}
# 	2:5:Class:CAgentCtlCharacterEx
# 	2:10:HeaderFile:agentctlcharacterex.h
# 	2:8:ImplFile:agentctlcharacterex.cpp
# End Section
# Section MJAntiVirus : {F5BE8BF0-7DE6-11D0-91FE-00C04FD701A5}
# 	2:5:Class:CAgentCtlAudioObjectEx
# 	2:10:HeaderFile:agentctlaudioobjectex.h
# 	2:8:ImplFile:agentctlaudioobjectex.cpp
# End Section
