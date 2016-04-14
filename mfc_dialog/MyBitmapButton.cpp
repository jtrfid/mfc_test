// MyBitmapButton.cpp : 实现文件
//

#include "stdafx.h"
#include "mfc_dialog.h"
#include "MyBitmapButton.h"


// CMyBitmapButton

IMPLEMENT_DYNAMIC(CMyBitmapButton, CBitmapButton)

CMyBitmapButton::CMyBitmapButton()
{
	m_LButtonDown = false;
}

CMyBitmapButton::~CMyBitmapButton()
{
}


BEGIN_MESSAGE_MAP(CMyBitmapButton, CBitmapButton)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CMyBitmapButton 消息处理程序

void CMyBitmapButton::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{

	ASSERT(lpDIS != NULL); 
	// must have at least the first bitmap loaded before calling DrawItem 
	ASSERT(m_bitmap.m_hObject != NULL);     // 至少有一个正常显示的CBitmap对象 

	// use the main bitmap for up, the selected bitmap for down 
	CBitmap* pBitmap = &m_bitmap; // 第一个图片正常显示
	UINT state = lpDIS->itemState; 

	if ((state & ODS_DISABLED) && m_bitmapFocus.m_hObject != NULL) 
		pBitmap = &m_bitmapFocus;   // 第三个图片用于未使能按钮
	else if(m_LButtonDown && m_bitmapSel.m_hObject != NULL)
		pBitmap = &m_bitmapSel; // 第二个图片，左键按下后显示

	// draw the whole button 
	CDC* pDC = CDC::FromHandle(lpDIS->hDC); 
	CDC memDC; 
	memDC.CreateCompatibleDC(pDC); 
	CBitmap* pOld = memDC.SelectObject(pBitmap); 
	if (pOld == NULL) 
		return;     // destructors will clean up 

	CRect rect; 
	rect.CopyRect(&lpDIS->rcItem); 
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), 
		&memDC, 0, 0, SRCCOPY); 
	memDC.SelectObject(pOld); 
}


void CMyBitmapButton::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	ModifyStyle(0, BS_OWNERDRAW); // 自画

	CBitmapButton::PreSubclassWindow();
}


void CMyBitmapButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_LButtonDown = !m_LButtonDown;

	CBitmapButton::OnLButtonDown(nFlags, point);
}
