#pragma once

#include "Setting.h"

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <memory>

// CDlgFont �Ի���

class CFontLattice
{
public:
    CFontLattice();
    ~CFontLattice();

    unsigned int	utf_8_code;
    unsigned char	width;
    unsigned char*	p_data;

    unsigned char*	p_compressed_data;
    int				p_compressed_data_length;
};

class CDlgFont : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFont)

public:
	CDlgFont(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgFont();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FONT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
protected:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedButtonFont();
    afx_msg void OnBnClickedButtonSave();
private:
    CString m_edit_source;
    CString m_edit_utf8;
    CString m_edit_font_name;
    CString m_edit_save_name;

private:
	std::shared_ptr<CSetting> m_pSetting;

    LOGFONT m_logFont;
    int m_nCurrentFontHeight;
	int m_nMaxCurrentFontWidth;
	int m_nShowLeft;
	int m_nShowTop;
    std::map<unsigned int, CFontLattice> m_mCurrentFontLatticeMap;
private:
    SIZE GetCharSize(CDC& dc, wchar_t character, LOGFONT& logFont);
    void ShowFontSample();
	void ShowFontFlush();

    int GetCharInfo(CDC& dc, wchar_t character, LOGFONT& logFont, bool bTestSample = false);
    int GetStringInfo(const wchar_t* str, LOGFONT& logFont);
    unsigned char* CompressFontLattice(unsigned char* p_data, int length, int& out_length);
    int GetCompressionRatio();

    int WriteLatticeDataInCppFile(std::fstream& file);
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

// �ַ���ת��
/**
* @brief  UNICODE�ַ���ת���ֽ��ַ���
* @param  ws [IN]  UNICODE�ַ���
* @return ���ֽ��ַ���
*/
std::string ws2s(const std::wstring& ws);
/**
* @brief  ���ֽ��ַ���תUNICODE�ַ���
* @param  s [IN]  ���ֽ��ַ���
* @return UNICODE�ַ���
*/
std::wstring s2ws(const std::string& s);
/**
* @brief  UNICODE�ַ���תutf8�ַ���
* @param  ws [IN]  UNICODE�ַ���
* @return utf8�ַ���
*/
std::string ws2utf8(const std::wstring& ws);
/**
* @brief  ���ֽ��ַ���תutf8�ַ���
* @param  s [IN]  ���ֽ��ַ���
* @return utf8�ַ���
*/
std::wstring utf82ws(const std::string& s);