__AFXWIN_H__
// FontMatrixTool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFontMatrixToolApp: 
// �йش����ʵ�֣������ FontMatrixTool.cpp
//

class CFontMatrixToolApp : public CWinApp
{
public:
	CFontMatrixToolApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFontMatrixToolApp theApp;