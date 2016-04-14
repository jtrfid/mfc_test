// MyButton.cpp : 实现文件
//

#include "stdafx.h"
#include "mfc_dialog.h"
#include "MyButton.h"


// CMyButton

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton()
{
	m_LBtnDown = false;
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
END_MESSAGE_MAP()


void CMyButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	// TODO:  添加您的代码以绘制指定项

	// 获取一个CDC指针 
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	//定义按钮区域并初始化 
	CRect rect(lpDrawItemStruct->rcItem); 

	//设置背景模式
	COLORREF oc = pDC->GetTextColor();
	int iObk = pDC->SetBkMode(TRANSPARENT); 

	//初始化按钮状态 
	UINT state = lpDrawItemStruct->itemState; 
	CFont *pOldFont = NULL; 
	int iYOffset = 0, iXOffset = 0;
	CString strText; 
	GetWindowText(strText); 
	rect.top += iYOffset; 
	rect.left += iXOffset; 

	// 按钮Disabled
	if(state & ODS_DISABLED) {
		//按钮置灰（DISABLED）
		CBrush grayBrush; 
		grayBrush.CreateSolidBrush (GetSysColor (COLOR_GRAYTEXT)); 
		CSize sz = pDC->GetTextExtent(strText); 
		int x = rect.left + (rect.Width() - sz.cx)/2; 
		int y = rect.top + (rect.Height() - sz.cy)/2; 
		rect.top += 2; 
		rect.left += 2; 
		pDC->SetTextColor(GetSysColor(COLOR_3DHIGHLIGHT)); 
		pDC->DrawText(strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
		rect.top -= 2; 
		rect.left -= 2; 
		pDC->SetTextColor(GetSysColor(COLOR_GRAYTEXT)); 
		pDC->DrawText(strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
	} 
	else if (m_LBtnDown) { // 鼠标左键被按下
		pDC->Draw3dRect(rect,GetSysColor(COLOR_3DSHADOW),GetSysColor(COLOR_3DHIGHLIGHT));
		// 字体颜色
		pDC->SetTextColor(RGB(0,0,255));
		// 加上下划线（也可以用其他字体）
		if(m_fUnderline.GetSafeHandle() == NULL) {
			CFont *pFont = GetFont();
			ASSERT(pFont);
			LOGFONT lf;
			pFont->GetLogFont(&lf);
			lf.lfUnderline = TRUE;
			m_fUnderline.CreatePointFontIndirect(&lf);
		}
		pOldFont = pDC->SelectObject(&m_fUnderline);
	}
	else
		pDC->SetTextColor(GetSysColor(COLOR_BTNTEXT));

	pDC->DrawText(strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
	if(pOldFont) pDC->SelectObject(pOldFont);
}

// CMyButton 消息处理程序
void CMyButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_LBtnDown = !m_LBtnDown;
	printf("m_LBtnDown=%d\n",m_LBtnDown);
	CButton::OnLButtonDown(nFlags, point);
}


int CMyButton::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CButton::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	return 0;
}


void CMyButton::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CButton::OnShowWindow(bShow, nStatus);

	// TODO: 在此处添加消息处理程序代码
}


void CMyButton::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CButton::OnTimer(nIDEvent);
}
