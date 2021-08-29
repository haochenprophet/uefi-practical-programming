
// FontMatrixToolDlg.h : ͷ�ļ�
//

#pragma once

#include "DlgFont.h"

// CFontMatrixToolDlg �Ի���
class CFontMatrixToolDlg : public CDialogEx
{
// ����
public:
	CFontMatrixToolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FontMatrixTool_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
protected:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();

private:
    void InitChildDlgRect();
    void InitDlgRect();
private:
    CDlgFont m_hDlgFont;

};
