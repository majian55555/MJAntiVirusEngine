; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMJAntiVirusDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mjantivirus.h"
LastPage=0

ClassCount=21
Class1=CDlgComputerInfo
Class2=CDlgScanSet
Class3=CFileEncryDlg
Class4=CFolderEncryDlg
Class5=CLabel
Class6=CListButton
Class7=CLockDlg
Class8=CLockOrSetDlg
Class9=CMJAntiVirusApp
Class10=CMJAntiVirusAboutDlg
Class11=CMJAntiVirusDlg
Class12=COutlookList
Class13=CSetPasswordDlg
Class14=CSetProp1
Class15=CSetProp2
Class16=CSetProp3
Class17=CSetPropSheet
Class18=CSysMoniDlg

ResourceCount=17
Resource1=IDD_MJANTIVIRUS_DIALOG
Resource2=IDD_FILEENCRY_DIALOG
Resource3=IDD_FOLDERENCRY_DIALOG
Resource4=IDD_LOCK_DLG
Resource5=IDD_DLG_SCREENPROTECT
Resource6=IDD_PROP1
Resource7=IDD_DLG_NETMONI
Resource8=IDD_DLG_LOCKORSET
Resource9=IDD_DLG_SETPASSWORD
Resource10=IDD_DLG_MONITORFILE
Resource11=IDD_DLG_REG
Resource12=IDD_PROP2
Resource13=IDD_DLG_COMPUTERINFO
Resource14=IDD_DLG_SCANSET
Class19=CNetMoniDlg
Resource15=IDD_ABOUT_DIALOG
Class20=CRegDlg
Resource16=IDD_PROP3
Class21=CSreenProtectDlg
Resource17=IDR_TRAYMENU

[CLS:CDlgComputerInfo]
Type=0
BaseClass=CDialog
HeaderFile=DlgComputerInfo.h
ImplementationFile=DlgComputerInfo.cpp
LastObject=CDlgComputerInfo

[CLS:CDlgScanSet]
Type=0
BaseClass=CDialog
HeaderFile=DlgScanSet.h
ImplementationFile=DlgScanSet.cpp

[CLS:CFileEncryDlg]
Type=0
BaseClass=CDialog
HeaderFile=FileEncryDlg.h
ImplementationFile=FileEncryDlg.cpp

[CLS:CFolderEncryDlg]
Type=0
BaseClass=CDialog
HeaderFile=FolderEncryDlg.h
ImplementationFile=FolderEncryDlg.cpp

[CLS:CLabel]
Type=0
BaseClass=CStatic
HeaderFile=Label.h
ImplementationFile=Label.cpp

[CLS:CListButton]
Type=0
BaseClass=CButton
HeaderFile=ListButton.h
ImplementationFile=ListButton.cpp

[CLS:CLockDlg]
Type=0
BaseClass=CDialog
HeaderFile=LockDlg.h
ImplementationFile=LockDlg.cpp
Filter=D
VirtualFilter=dWC

[CLS:CLockOrSetDlg]
Type=0
BaseClass=CDialog
HeaderFile=LockOrSetDlg.h
ImplementationFile=LockOrSetDlg.cpp

[CLS:CMJAntiVirusApp]
Type=0
BaseClass=CWinApp
HeaderFile=MJAntiVirus.h
ImplementationFile=MJAntiVirus.cpp

[CLS:CMJAntiVirusAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=MJAntiVirusAboutDlg.h
ImplementationFile=MJAntiVirusAboutDlg.cpp

[CLS:CMJAntiVirusDlg]
Type=0
BaseClass=CDialog
HeaderFile=MJAntiVirusDlg.h
ImplementationFile=MJAntiVirusDlg.cpp
LastObject=IDC_LIST_OUTLOOK
Filter=D
VirtualFilter=dWC

[CLS:COutlookList]
Type=0
BaseClass=CListCtrl
HeaderFile=OutlookList.h
ImplementationFile=OutlookList.cpp

[CLS:CSetPasswordDlg]
Type=0
BaseClass=CDialog
HeaderFile=SetPasswordDlg.h
ImplementationFile=SetPasswordDlg.cpp

[CLS:CSetProp1]
Type=0
BaseClass=CPropertyPage
HeaderFile=SetProp1.h
ImplementationFile=SetProp1.cpp

[CLS:CSetProp2]
Type=0
BaseClass=CPropertyPage
HeaderFile=SetProp2.h
ImplementationFile=SetProp2.cpp

[CLS:CSetProp3]
Type=0
BaseClass=CPropertyPage
HeaderFile=SetProp3.h
ImplementationFile=SetProp3.cpp

[CLS:CSetPropSheet]
Type=0
BaseClass=CPropertySheet
HeaderFile=SetPropSheet.h
ImplementationFile=SetPropSheet.cpp

[CLS:CSysMoniDlg]
Type=0
BaseClass=CDialog
HeaderFile=SysMoniDlg.h
ImplementationFile=SysMoniDlg.cpp
Filter=D
VirtualFilter=dWC

[DLG:IDD_DLG_COMPUTERINFO]
Type=1
Class=CDlgComputerInfo
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_CPTINFO1,edit,1350631552
Control4=IDC_EDIT_CPTINFO2,edit,1350631552
Control5=IDC_EDIT_CPTINFO3,edit,1350631552
Control6=IDC_EDIT_CPTINFO4,edit,1350631552
Control7=IDC_EDIT_CPTINFO5,edit,1350631552
Control8=IDC_EDIT_CPTINFO6,edit,1350631552
Control9=IDC_EDIT_CPTINFO7,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT_CPTINFO8,edit,1350631552
Control17=IDC_STATIC,static,1342308352

[DLG:IDD_DLG_SCANSET]
Type=1
Class=CDlgScanSet
ControlCount=20
Control1=IDC_STATIC,button,1342177287
Control2=IDC_RADIO_MEMFIRST,button,1342308361
Control3=IDC_RADIO_UNMEMFIRST,button,1342177289
Control4=IDC_STATIC,button,1342177287
Control5=IDC_RADIO_DERDEL,button,1342308361
Control6=IDC_RADIO_KILLDEL,button,1342177289
Control7=IDC_RADIO_KILLNOTE,button,1342177289
Control8=IDC_RADIO_DERNOTE,button,1342177289
Control9=IDC_STATIC,button,1342177287
Control10=IDC_RADIO_ALLFILE,button,1342308361
Control11=IDC_RADIO_EXEFILE,button,1342177289
Control12=IDC_STATIC,button,1342177287
Control13=IDC_RADIO_HIGHSPEED,button,1342308361
Control14=IDC_RADIO_MIDSPEED,button,1342177289
Control15=IDC_RADIO_LOWSPEED,button,1342177289
Control16=IDC_STATIC,button,1342177287
Control17=IDC_RADIO_TURNOFFAFT,button,1342308361
Control18=IDC_RADIO_NONTURNOFF,button,1342177289
Control19=IDC_BTN_SCANSETOK,button,1342242816
Control20=IDC_BTN_SCANSETCANCEL,button,1342242816

[DLG:IDD_FILEENCRY_DIALOG]
Type=1
Class=CFileEncryDlg
ControlCount=5
Control1=IDC_EDBODY,edit,1353713860
Control2=IDC_BTOPEN,button,1342242816
Control3=IDC_BTENCRY,button,1342242816
Control4=IDC_BTUNENCRY,button,1342242816
Control5=IDC_FILEPATH,static,1342308352

[DLG:IDD_FOLDERENCRY_DIALOG]
Type=1
Class=CFolderEncryDlg
ControlCount=4
Control1=IDC_EDDIR,edit,1350568064
Control2=ID_ADD,button,1342242816
Control3=IDC_BTENCRY,button,1342242816
Control4=IDC_BTUNENCRY,button,1342242816

[DLG:IDD_LOCK_DLG]
Type=1
Class=CLockDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_LOCK_EDIT1,edit,1350631456
Control3=IDC_LOCK_BTN1,button,1342242816
Control4=IDC_LOCK_BTN_SCREEN,button,1342242816

[DLG:IDD_DLG_LOCKORSET]
Type=1
Class=CLockOrSetDlg
ControlCount=2
Control1=IDC_BTN_SETCODE,button,1342242816
Control2=IDC_BTN_LOCKCPT,button,1342242816

[DLG:IDD_ABOUT_DIALOG]
Type=1
Class=CMJAntiVirusAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342177294
Control2=IDC_LABEL1,static,1342308353
Control3=IDC_LABEL2,static,1342308353
Control4=IDC_LABEL3,static,1342308353
Control5=IDC_LABEL4,static,1342308353
Control6=IDC_LABEL5,static,1342308353
Control7=IDC_LABEL6,static,1342308353

[DLG:IDD_MJANTIVIRUS_DIALOG]
Type=1
Class=CMJAntiVirusDlg
ControlCount=11
Control1=IDC_LIST_OUTLOOK,SysListView32,1350631424
Control2=IDC_TRDISKTREE,SysTreeView32,1082196387
Control3=IDC_BTN_START,button,1073807360
Control4=IDC_LB_SHOWF,static,1073872896
Control5=IDC_BTN_PAUSE,button,1073807360
Control6=IDC_BTN_STOP,button,1073807360
Control7=IDC_EDIT_TIME,edit,1073809408
Control8=IDC_LIST_SHOWRLT,SysListView32,1073807361
Control9=IDC_LB_FILENUM,edit,1073809408
Control10=IDC_LIST_SELEICON,SysListView32,1082195980
Control11=IDC_AGENT1,{D45FD31B-5C6E-11D1-9EC1-00C04FD7081F},1342177280

[DLG:IDD_DLG_SETPASSWORD]
Type=1
Class=CSetPasswordDlg
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631456
Control3=IDC_BUTTON1,button,1342242816

[DLG:IDD_PROP1]
Type=1
Class=CSetProp1
ControlCount=6
Control1=IDC_PROP1_CHECK1,button,1342242819
Control2=IDC_STATIC,button,1342177287
Control3=IDC_PROP1_CHECK2,button,1342242819
Control4=IDC_PROP1_CHECK3,button,1342242819
Control5=IDC_PROP1_CHECK4,button,1342242819
Control6=IDC_PROP1_CHECK5,button,1342242819

[DLG:IDD_PROP2]
Type=1
Class=CSetProp2
ControlCount=8
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_PROP2_CHECK1,button,1342242819
Control4=IDC_PROP2_CHECK2,button,1342242819
Control5=IDC_PROP2_CHECK3,button,1342242819
Control6=IDC_PROP2_CHECK4,button,1342242819
Control7=IDC_PROP2_CHECK5,button,1342242819
Control8=IDC_PROP2_CHECK6,button,1342242819

[DLG:IDD_PROP3]
Type=1
Class=CSetProp3
ControlCount=5
Control1=IDC_PROP3_CHECK1,button,1342242819
Control2=IDC_STATIC,button,1342177287
Control3=IDC_PROP3_CHECK2,button,1342242819
Control4=IDC_PROP3_CHECK3,button,1342242819
Control5=IDC_PROP3_CHECK4,button,1342242819

[DLG:IDD_DLG_MONITORFILE]
Type=1
Class=CSysMoniDlg
ControlCount=5
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_STATE,edit,1350633472
Control3=IDC_START,button,1342242816
Control4=IDC_STOP,button,1342242816
Control5=IDC_CLEAR,button,1342242816

[MNU:IDR_TRAYMENU]
Type=1
Class=?
Command1=ID_MENUITEM_RESTORE
Command2=ID_MENUITEM_SHOWPROC
Command3=ID_MENUITEM_CMPINFO
Command4=ID_MENUITEM_LOCK
Command5=ID_MENUITEM_SYSMONI
Command6=ID_MENUITEM_NETMONI
Command7=ID_MENUITEM_REGISTER
Command8=ID_MENUITEM_ABOUT
Command9=ID_MENUITEM_CLOSE
CommandCount=9

[DLG:IDD_DLG_NETMONI]
Type=1
Class=CNetMoniDlg
ControlCount=3
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_BTN_BEGINLISTEN,button,1342275584
Control3=IDC_BTN_CANCEL,button,1342275584

[CLS:CNetMoniDlg]
Type=0
HeaderFile=NetMoniDlg.h
ImplementationFile=NetMoniDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CNetMoniDlg

[DLG:IDD_DLG_REG]
Type=1
Class=CRegDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_REGCODE,edit,1350631552
Control3=IDC_BTN_REG,button,1342275584
Control4=IDC_BTN_QUITREG,button,1342275584
Control5=IDC_LAB_REGSTATE,static,1342308352

[CLS:CRegDlg]
Type=0
HeaderFile=RegDlg.h
ImplementationFile=RegDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CRegDlg

[DLG:IDD_DLG_SCREENPROTECT]
Type=1
Class=CSreenProtectDlg
ControlCount=0

[CLS:CSreenProtectDlg]
Type=0
HeaderFile=SreenProtectDlg.h
ImplementationFile=SreenProtectDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSreenProtectDlg

