
// mfc_dialog.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cmfc_dialogApp:
// �йش����ʵ�֣������ mfc_dialog.cpp
//

class Cmfc_dialogApp : public CWinApp
{
public:
	Cmfc_dialogApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cmfc_dialogApp theApp;