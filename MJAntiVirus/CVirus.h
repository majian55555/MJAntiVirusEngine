#include <afxcoll.h> //CDWordArra类和CObArray类的头文件
#define MJVIRUSSIGNVERSION  585
#define MJVIRUSVERSION  595
class CVirusSignature: public CObject  //病毒特征码类
{
	DECLARE_SERIAL(CVirusSignature)//Serialize方法必须用此宏
	//IMPLEMENT_SERIAL(CVirusSignature, CObject, 1 ) 该宏放在//VirusSignature.cpp文件当中
private:
	DWORD m_vsOffset;  //自文件起始位置的偏移量
	DWORD m_vsSize;   //特征码字节长度
	CDWordArray m_vs;        //特征码串
public:
	CVirusSignature();     //构造函数
	DWORD GetvsOffset();  //获取偏移量
	DWORD GetvsSize();    //获取特征码长度
	BOOL vsCreate(DWORD, DWORD, CDWordArray&);//创造一个特征码。0不成功，1成功 注意此处必须用CDWordArray&，此类没有=拷贝
	BOOL vsCompare(CDWordArray&);  //判断从文件提取出的字节串是否与特征码匹配。0不匹配，1匹配
	void Serialize(CArchive&);  //重写Serialize方法
	BOOL WriteVS(CArchive&);  //把对象写入文件。0不成功，1成功
	BOOL ReadVS(CArchive&);  //从文件读取对象。0不成功，1成功
};
class CVirus: public CObject  //病毒类
{
	DECLARE_SERIAL(CVirus )
	//IMPLEMENT_SERIAL(CVirus, CObject, 1 ) 该宏放在Virus.cpp文件当中
private:
	CString m_vName; //该病毒名
	DWORD m_vscount; //该病毒特征码数量
	CObArray m_vsArray; //特征码对象数组
public:
	
	CVirus();	//构造函数
	BOOL LoadFromFile(CString);  //从文件中读取病毒信息及特征码。0不成功，1成功
	BOOL WriteToFile(CString);  //向文件写入该病毒对象。0不成功，1成功
	BOOL vMatch(CFile&); //与目标文件比较，判断是否为病毒。0不是，1是
	CString GetvName();  //返回该病毒的病毒名称。
	DWORD GetvsCount(); //返回该病毒的特征码数量。
	BOOL vCreate(CString,DWORD,CObArray&); //创造一个病毒对象。0不成功，1成功
	BOOL KillVirus(CFile&); //将目标文件病毒码破坏掉。0不成功，1成功
	void Serialize(CArchive&);  //重写Serialize方法
};
