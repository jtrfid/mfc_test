
// vs2013MFCApplication1Dlg.h : header file
//

#pragma once


// Cvs2013MFCApplication1Dlg dialog
class Cvs2013MFCApplication1Dlg : public CDialogEx
{
// Construction
public:
	Cvs2013MFCApplication1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_VS2013MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
