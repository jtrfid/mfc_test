
// mfc_dialogDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "MyButton.h"
#include "MyBitmapButton.h"


// Cmfc_dialogDlg 对话框
class Cmfc_dialogDlg : public CDialogEx
{
// 构造
public:
	Cmfc_dialogDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_DIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_btnOK;
	afx_msg void OnBnClickedOk();
	// CMyButton型按钮
	CMyButton m_myBtn1;
	afx_msg void OnBnClickedButton1();
	// CBitmapButton
	CBitmapButton m_BitmapButton;
	// CMyBitmapButton
	CMyBitmapButton m_MyBitmapButton;
};
