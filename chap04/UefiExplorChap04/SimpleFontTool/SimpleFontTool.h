
// SimpleFontTool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSimpleFontToolApp: 
// �йش����ʵ�֣������ SimpleFontTool.cpp
//

class CSimpleFontToolApp : public CWinApp
{
public:
	CSimpleFontToolApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSimpleFontToolApp theApp;