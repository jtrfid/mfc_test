
// mfc_dialogDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "MyButton.h"
#include "MyBitmapButton.h"

#define WM_MY_MESSAGE (WM_USER+100)  

// Cmfc_dialogDlg �Ի���
class Cmfc_dialogDlg : public CDialogEx
{
// ����
public:
	Cmfc_dialogDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_DIALOG_DIALOG };

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
	afx_msg LRESULT OnMyMessage(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CButton m_btnOK;
	afx_msg void OnBnClickedOk();
	// CMyButton�Ͱ�ť
	CMyButton m_myBtn1;
	afx_msg void OnBnClickedButton1();
	// CBitmapButton
	CBitmapButton m_BitmapButton;
	// CMyBitmapButton
	CMyBitmapButton m_MyBitmapButton;
};
