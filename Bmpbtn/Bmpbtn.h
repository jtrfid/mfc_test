// Bmpbtn.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CBmpbtnApp:
// �йش����ʵ�֣������ Bmpbtn.cpp
//

class CBmpbtnApp : public CWinApp
{
public:
	CBmpbtnApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBmpbtnApp theApp;
