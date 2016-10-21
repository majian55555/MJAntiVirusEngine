#include "stdafx.h"
#include "CVirus.h"

IMPLEMENT_SERIAL(CVirusSignature,CObject,MJVIRUSSIGNVERSION)

CVirusSignature::CVirusSignature()
{
	this->m_vsOffset=0;
	this->m_vsSize=0;
	this->m_vs;
}
DWORD CVirusSignature::GetvsOffset()
{
	return this->m_vsOffset;
}
DWORD CVirusSignature::GetvsSize()
{
	return this->m_vsSize;
}
BOOL CVirusSignature::vsCreate(DWORD offset,DWORD size,CDWordArray& vs)
{
	if(size==0 || vs.GetSize()<=0)
	{
		return FALSE;
	}
	this->m_vsOffset=offset;
	this->m_vsSize=size;
	this->m_vs.Copy(vs);
	return TRUE;
}
BOOL CVirusSignature::vsCompare(CDWordArray& vs)
{
	DWORD Count=this->m_vsSize;
	for(unsigned int i=0;i<Count;i++)
	{
		if(vs[i]!=this->m_vs[i])
		{
			return FALSE;
		}
	}
	return TRUE;
}
void CVirusSignature::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
	{
		ar<<this->m_vsOffset<<this->m_vsSize;
		this->m_vs.Serialize(ar);
	}
	else
	{
		ar>>this->m_vsOffset>>this->m_vsSize;
		this->m_vs.Serialize(ar);
	}
}
BOOL CVirusSignature::ReadVS(CArchive& ar)
{

		this->Serialize(ar);
		if(this->m_vsSize==0)
		{
			return FALSE;
		}
		return TRUE;
}
BOOL CVirusSignature::WriteVS(CArchive& ar)
{
		if(this->m_vsSize==0)
		{
			return FALSE;
		}
		this->Serialize(ar);
		return TRUE;
}

IMPLEMENT_SERIAL(CVirus,CObject,MJVIRUSVERSION)

CVirus::CVirus()
{
	this->m_vName="";
	this->m_vscount=0;
	this->m_vsArray;
}
BOOL CVirus::LoadFromFile(CString filepath)
{
	CFile *objFile=new CFile(filepath,CFile::modeRead);
	CArchive ar(objFile,CArchive::load);
	this->Serialize(ar);
	if(this->m_vscount==0)
	{
		return FALSE;
	}
	objFile->Close();
	return TRUE;
}
BOOL CVirus::WriteToFile(CString filepath)
{
	if(this->m_vscount==0)
	{
		return FALSE;
	}
	CFile *objFile=new CFile(filepath+(this->m_vName)+_T(".mjvinfo"),CFile::modeWrite | CFile::modeCreate);
	CArchive ar(objFile,CArchive::store);
	this->Serialize(ar);
	objFile->Close();
	return TRUE;
}
void CVirus::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
	{
		ar<<this->m_vName<<this->m_vscount;
		for(unsigned int i=0;i<this->m_vscount;i++)
		{
			m_vsArray[i]->Serialize(ar);
		}
	}
	else
	{
		ar>>this->m_vName>>this->m_vscount;
		for(unsigned int i=0;i<this->m_vscount;i++)
		{
			CVirusSignature *vs1=new CVirusSignature();
			vs1->Serialize(ar);
			this->m_vsArray.Add((CVirusSignature*)vs1);
		}
	}
}
CString CVirus::GetvName()
{
	return this->m_vName;
}
BOOL CVirus::vMatch(CFile& objFile)
{
	for(unsigned int i=0;i<this->m_vscount;i++)
	{
		objFile.Seek(((CVirusSignature*)this->m_vsArray[i])->GetvsOffset(),CFile::begin);
		CDWordArray dwarray;
		DWORD count=((CVirusSignature*)this->m_vsArray[i])->GetvsSize();
		for(unsigned int j=0;j<count;j++)
		{
			DWORD onevs;
			objFile.Read(&onevs,sizeof(DWORD));
			dwarray.Add(onevs);
		}
		if(!((CVirusSignature*)this->m_vsArray[i])->vsCompare(dwarray))
		{
			return FALSE;
		}
	}
	return TRUE;
}
BOOL CVirus::vCreate(CString vname,DWORD vscount,CObArray& vsarray)
{
	if(!vscount)
	{
		return FALSE;
	}
	this->m_vName=vname;
	this->m_vscount=vscount;
	this->m_vsArray.Copy(vsarray);
	return TRUE;
}
BOOL CVirus::KillVirus(CFile& objFile)
{
	//add code here
	return TRUE;
}

DWORD CVirus::GetvsCount()
{
	return this->m_vscount;
}
