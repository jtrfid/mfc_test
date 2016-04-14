// MyBitmapButton.cpp : ʵ���ļ�
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



// CMyBitmapButton ��Ϣ�������

void CMyBitmapButton::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{

	ASSERT(lpDIS != NULL); 
	// must have at least the first bitmap loaded before calling DrawItem 
	ASSERT(m_bitmap.m_hObject != NULL);     // ������һ��������ʾ��CBitmap���� 

	// use the main bitmap for up, the selected bitmap for down 
	CBitmap* pBitmap = &m_bitmap; // ��һ��ͼƬ������ʾ
	UINT state = lpDIS->itemState; 

	if ((state & ODS_DISABLED) && m_bitmapFocus.m_hObject != NULL) 
		pBitmap = &m_bitmapFocus;   // ������ͼƬ����δʹ�ܰ�ť
	else if(m_LButtonDown && m_bitmapSel.m_hObject != NULL)
		pBitmap = &m_bitmapSel; // �ڶ���ͼƬ��������º���ʾ

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
	// TODO: �ڴ����ר�ô����/����û���
	ModifyStyle(0, BS_OWNERDRAW); // �Ի�

	CBitmapButton::PreSubclassWindow();
}


void CMyBitmapButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_LButtonDown = !m_LButtonDown;

	CBitmapButton::OnLButtonDown(nFlags, point);
}
