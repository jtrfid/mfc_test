
// mfc_dialogDlg.h : ͷ�ļ�
//

#pragma once


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
	DECLARE_MESSAGE_MAP()
public:
	CButton m_btnOK;
	afx_msg void OnBnClickedOk();
};
