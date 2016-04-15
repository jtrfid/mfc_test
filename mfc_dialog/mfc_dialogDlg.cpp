
// mfc_dialogDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mfc_dialog.h"
#include "mfc_dialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Cmfc_dialogDlg 对话框




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


// Cmfc_dialogDlg 消息处理程序

BOOL Cmfc_dialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	// 调试信息输出printf("ok\n");
	AllocConsole();
	freopen("CONOUT$","a+",stdout);

	// 关联按钮于界面添加的CButton按钮资源IDC_BUTTON1
	m_myBtn1.SubclassDlgItem(IDC_BUTTON1,this); // 或者使用类向导添加CButton m_myBtn1，手工将其修改为CMyButton m_myBtn1
	// 设置自画窗口
	//GetDlgItem(IDC_BUTTON1)->ModifyStyle(0,BS_OWNERDRAW,0);
	// 或
	m_myBtn1.ModifyStyle(0,BS_OWNERDRAW,0);

	/////////////////////////// CBitmapButton
	m_BitmapButton.ModifyStyle(0,BS_OWNERDRAW,0); // 自绘 
	//正常显示（Up），鼠标按下（Down），获得焦点（Focused），不可用（Disabled）。
	m_BitmapButton.LoadBitmaps(IDB_up1,IDB_up2,IDB_right1,IDB_right2);
	m_BitmapButton.SizeToContent();  // 调整按钮大小为图片大小

	///////////////////////// CMyBitmapButton
	m_MyBitmapButton.LoadBitmaps(IDB_up1,IDB_up2,IDB_right1);
	m_MyBitmapButton.SizeToContent();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cmfc_dialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
