
// mfc_dialogDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mfc_dialog.h"
#include "mfc_dialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cmfc_dialogDlg �Ի���




Cmfc_dialogDlg::Cmfc_dialogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmfc_dialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc_dialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_btnOK);
	//  DDX_Control(pDX, IDC_BUTTON1, m_myBtn1);
	DDX_Control(pDX, IDC_Btn2, m_BitmapButton);
	DDX_Control(pDX, IDC_BUTTON2, m_MyBitmapButton);
}

BEGIN_MESSAGE_MAP(Cmfc_dialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Cmfc_dialogDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmfc_dialogDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cmfc_dialogDlg ��Ϣ�������

BOOL Cmfc_dialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	// ������Ϣ���printf("ok\n");
	AllocConsole();
	freopen("CONOUT$","a+",stdout);

	// ������ť�ڽ�����ӵ�CButton��ť��ԴIDC_BUTTON1
	m_myBtn1.SubclassDlgItem(IDC_BUTTON1,this); // ����ʹ���������CButton m_myBtn1���ֹ������޸�ΪCMyButton m_myBtn1
	// �����Ի�����
	//GetDlgItem(IDC_BUTTON1)->ModifyStyle(0,BS_OWNERDRAW,0);
	// ��
	m_myBtn1.ModifyStyle(0,BS_OWNERDRAW,0);

	/////////////////////////// CBitmapButton
	m_BitmapButton.ModifyStyle(0,BS_OWNERDRAW,0); // �Ի� 
	//������ʾ��Up������갴�£�Down������ý��㣨Focused���������ã�Disabled����
	m_BitmapButton.LoadBitmaps(IDB_up1,IDB_up2,IDB_right1,IDB_right2);
	m_BitmapButton.SizeToContent();  // ������ť��СΪͼƬ��С

	///////////////////////// CMyBitmapButton
	m_MyBitmapButton.LoadBitmaps(IDB_up1,IDB_up2,IDB_right1);
	m_MyBitmapButton.SizeToContent();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cmfc_dialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cmfc_dialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cmfc_dialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cmfc_dialogDlg::OnBnClickedOk()
{
	static bool b = false;
	m_myBtn1.EnableWindow(b);
	m_MyBitmapButton.EnableWindow(b);
	b = !b;
	//CDialogEx::OnOK();
}


void Cmfc_dialogDlg::OnBnClickedButton1()
{
	printf("CMyButton()\n");
	static bool b = false;
	m_BitmapButton.EnableWindow(b);
	b = !b;
}
