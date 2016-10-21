// AntiVirusDLL2.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "AntiVirusDLL2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CAntiVirusDLL2App

BEGIN_MESSAGE_MAP(CAntiVirusDLL2App, CWinApp)
	//{{AFX_MSG_MAP(CAntiVirusDLL2App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAntiVirusDLL2App construction

CAntiVirusDLL2App::CAntiVirusDLL2App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CAntiVirusDLL2App object
#define TOLERANCE		1		// Number of MHz to allow
#define ROUND_THRESHOLD		6
CAntiVirusDLL2App theApp;
CString GetMyComputerName(void)
{
	//char str_computername[100];
	DWORD lenthofname=100;
	char str_computername[100];
	CString str;
	if(::GetComputerName(str_computername,&lenthofname)==TRUE)
	{
		CString str=str_computername;
		return str;
	}
	else
	{
		return "";
	}
}
int _stdcall CpuSpeed(void)
{
	FREQ_INFO cpu_speed;
	LARGE_INTEGER t0,t1;			// Variables for High-
									// Resolution Performance
									// Counter reads

	unsigned long freq  =0;			// Most current frequ. calculation
	unsigned long freq2 =0;			// 2nd most current frequ. calc.
	unsigned long freq3 =0;			// 3rd most current frequ. calc.
	
	unsigned long total;			// Sum of previous three frequency
									// calculations

	int tries=0;					// Number of times a calculation has
									// been made on this call to 
									// cpuspeed

	unsigned long  total_cycles=0, cycles;	// Clock cycles elapsed 
											// during test
	
	unsigned long  stamp0, stamp1;			// Time Stamp Variable 
											// for beginning and end 
											// of test
	unsigned long  total_ticks=0, ticks;	// Microseconds elapsed 
									// during test
	
	LARGE_INTEGER count_freq;		// High Resolution 
									// Performance Counter 
									// frequency

#ifdef WIN32
	int iPriority;
	HANDLE hThread = GetCurrentThread();
#endif // WIN32;
	memset(&cpu_speed, 0x00, sizeof(cpu_speed));

//		return cpu_speed;
	QueryPerformanceFrequency ( &count_freq );
	// On processors supporting the Read 
	// Time Stamp opcode, compare elapsed
	// time on the High-Resolution Counter
	// with elapsed cycles on the Time 
	// Stamp Register.
	
	do {			// This do loop runs up to 20 times or
	   				//   until the average of the previous 
	   				//   three calculated frequencies is 
	   				//   within 1 MHz of each of the 
	   				//   individual calculated frequencies. 
					//   This resampling increases the 
					//   accuracy of the results since
					//   outside factors could affect this
					//   calculation
			
		tries++;							// Increment number of times sampled
											// on this call to cpuspeed
			
		freq3 = freq2;						// Shift frequencies back to make
		freq2 = freq;						// room for new frequency 
											// measurement

    	QueryPerformanceCounter(&t0);	
    										// Get high-resolution performance 
    										// counter time
			
		t1.LowPart = t0.LowPart;			// Set Initial time
		t1.HighPart = t0.HighPart;

#ifdef WIN32
		iPriority = GetThreadPriority(hThread);
		if ( iPriority != THREAD_PRIORITY_ERROR_RETURN )
		{
			SetThreadPriority(hThread, THREAD_PRIORITY_TIME_CRITICAL);
		}
#endif // WIN32
		while ( (unsigned long)t1.LowPart - (unsigned long)t0.LowPart<50) {	  
   						// Loop until 50 ticks have 
   						//   passed	since last read of hi-
						//	 res counter. This accounts for
						//   overhead later.

			QueryPerformanceCounter(&t1);
			_asm {
				RDTSC						// Read Time Stamp
				MOV stamp0, EAX
			}
		}
		t0.LowPart = t1.LowPart;		// Reset Initial 
		t0.HighPart = t1.HighPart;		//   Time

		while ((unsigned long)t1.LowPart-(unsigned long)t0.LowPart<1000 ) {
   						// Loop until 1000 ticks have 
   						//   passed	since last read of hi-
   						//   res counter. This allows for
						//   elapsed time for sampling.
			QueryPerformanceCounter(&t1);
			__asm {
				RDTSC					// Read Time Stamp
				MOV stamp1, EAX
			}
		}
#ifdef WIN32
		// Reset priority
		if ( iPriority != THREAD_PRIORITY_ERROR_RETURN )
		{
			SetThreadPriority(hThread, iPriority);
		}
#endif // WIN32
		cycles = stamp1 - stamp0;	// Number of internal 
        							//   clock cycles is 
        							//   difference between 
        							//   two time stamp 
        							//   readings.
   		ticks = (unsigned long) t1.LowPart - (unsigned long) t0.LowPart;	
								// Number of external ticks is
								// difference between two
								// hi-res counter reads.
								// Note that some seemingly arbitrary mulitplies and
								// divides are done below. This is to maintain a 
								// high level of precision without truncating the 
								// most significant data. According to what value 
								// ITERATIIONS is set to, these multiplies and
								// divides might need to be shifted for optimal
								// precision.

		ticks = ticks * 100000;
								// Convert ticks to hundred
								// thousandths of a tick
			
		ticks = ticks / ( count_freq.LowPart/10 );		
								// Hundred Thousandths of a 
								//   Ticks / ( 10 ticks/second )
								//   = microseconds (us)
		total_ticks += ticks;
		total_cycles += cycles;

		if ( ticks%count_freq.LowPart > count_freq.LowPart/2 )
			ticks++;			// Round up if necessary
				
		freq = cycles/ticks;	// Cycles / us  = MHz
        											
   		if ( cycles%ticks > ticks/2 )
			freq++;				// Round up if necessary
          		
		total = ( freq + freq2 + freq3 );
								// Total last three frequency 
								//   calculations
	}while ( (tries < 3 ) ||
	          (tries < 20)&&
	          ((abs(3 * freq -total) > 3*TOLERANCE )||
	           (abs(3 * freq2-total) > 3*TOLERANCE )||
	           (abs(3 * freq3-total) > 3*TOLERANCE )));	
					// Compare last three calculations to 
	          		//   average of last three calculations.		
	// Try one more significant digit.
	freq3 = ( total_cycles * 10 ) / total_ticks;
	freq2 = ( total_cycles * 100 ) / total_ticks;

	if ( freq2 - (freq3 * 10) >= ROUND_THRESHOLD )
		freq3++;

	cpu_speed.raw_freq = total_cycles / total_ticks;
	cpu_speed.norm_freq = cpu_speed.raw_freq;

	freq = cpu_speed.raw_freq * 10;
	if( (freq3 - freq) >= ROUND_THRESHOLD )
		cpu_speed.norm_freq++;

	cpu_speed.ex_ticks = total_ticks;
	cpu_speed.in_cycles = total_cycles;
	
	return (int)cpu_speed.norm_freq;
}
CString GetHostIpAddr(void)
{
	WSADATA wsd;
	WSAStartup(MAKEWORD(2,2),&wsd);
	int WSAReturn;
	WSADATA wsaData;
	char Hostname[260];
	DWORD namesize=260;
	WSAReturn = WSAStartup(0x0101,&wsaData );
	if( WSAReturn == 0 )
	{
		::GetComputerName(Hostname,&namesize);
		struct hostent *pHostEnt;
		pHostEnt = gethostbyname(Hostname);
		if( pHostEnt != NULL )
		{
			CString str_ip;
			str_ip.Format("本机IP:%d.%d.%d.%d",
			( pHostEnt->h_addr_list[0][0] &0x00ff ),
			( pHostEnt->h_addr_list[0][1] &0x00ff ),
			( pHostEnt->h_addr_list[0][2] &0x00ff ),
			( pHostEnt->h_addr_list[0][3] &0x00ff ) );
			return str_ip;
		}
	}
	return "无法获取本机IP地址！！！";
}
CString GetNetCardMacAddr()
{
	CString strMac;
	NCB ncb;
	ADAPTER_STATUS adapt;
	memset(&ncb,0,sizeof(ncb));
	ncb.ncb_command = NCBRESET;	
	//首先对网卡发送一个NCBRESET命令以便进行初始化 
	Netbios(&ncb);
	ncb.ncb_command = NCBASTAT;
	strcpy((char *)ncb.ncb_callname,"*");
	// 指定返回的信息存放的变量 
	ncb.ncb_buffer = (unsigned char *)&adapt;
	ncb.ncb_length = sizeof(adapt);
	// 发送NCBASTAT命令以获取网卡的信息 
	Netbios(&ncb);
	// 把网卡MAC地址格式化成常用的16进制形式 	
	strMac.Format( "%02X%02X-%02X%02X-%02X%02X\n",
					adapt.adapter_address[0],
					adapt.adapter_address[1],
					adapt.adapter_address[2],
					adapt.adapter_address[3],
					adapt.adapter_address[4],
					adapt.adapter_address[5]);
	return strMac;
}
ComputerInfo* GetComputerInfo(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	ComputerInfo* cptinfo=new ComputerInfo;
	if(""==GetMyComputerName())
	{
		cptinfo->computername="获取计算机名未成功！！！";
	}
	else
	{
		cptinfo->computername=GetMyComputerName();
	}

	MEMORYSTATUS MemStat;
	MemStat.dwLength = sizeof(MEMORYSTATUS);
	GlobalMemoryStatus(&MemStat);
	cptinfo->totalmem.Format("物理内存总数:%d(KB)",MemStat.dwTotalPhys / 1024L);
	cptinfo->aviliblemen.Format("剩余可用内存:%d(KB)",MemStat.dwAvailPhys / 1024L);
	cptinfo->aviliblemempersent.Format("剩余内存的百分数:%d%%",100-MemStat.dwMemoryLoad);

	OSVERSIONINFO OsInfo;
	OsInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if (GetVersionEx(&OsInfo))
	{
		// platform
		switch (OsInfo.dwPlatformId)
		{
		case VER_PLATFORM_WIN32_WINDOWS:
			if(OsInfo.dwMajorVersion == 3)
				cptinfo->sysplatform="操作系统:WIN95";
			else if(OsInfo.dwMajorVersion == 4)
				cptinfo->sysplatform="操作系统:WIN98";
			break;
		case VER_PLATFORM_WIN32_NT:
			if(OsInfo.dwMajorVersion == 5)
				cptinfo->sysplatform="操作系统:WINXP";
			else
				cptinfo->sysplatform="操作系统:WINNT";
			break;
		default:
			cptinfo->sysplatform="未知系统!!";
			break;
		}
	}
	int csd=CpuSpeed();
	cptinfo->cpuspeed.Format("CPU频率为：%dMHz",csd);;
	cptinfo->ipaddress=GetHostIpAddr();
	cptinfo->macaddress="";
	return cptinfo;
}