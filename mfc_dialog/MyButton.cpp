// MyButton.cpp : ʵ���ļ�
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

	// TODO:  ������Ĵ����Ի���ָ����

	// ��ȡһ��CDCָ�� 
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	// ��ȡ��ť���򲢳�ʼ�� 
	CRect rect(lpDrawItemStruct->rcItem); 

	// ��ȡ��ť״̬ 
	UINT state = lpDrawItemStruct->itemState; 
	
	CString strText; 
	GetWindowText(strText); 
	
	// draw the control edges 
	if(state & ODS_DISABLED) // ��ťDisabled
		pDC->DrawFrameControl(rect, DFC_BUTTON, DFCS_BUTTONPUSH | DFCS_PUSHED);
	else // ��ťʹ��
		pDC->DrawFrameControl(rect, DFC_BUTTON, DFCS_BUTTONPUSH); 
	
	// Deflate the drawing rect by the size of the button's edges     
	rect.DeflateRect( CSize(GetSystemMetrics(SM_CXEDGE), GetSystemMetrics(SM_CYEDGE)));

	// ������������
	if (m_LBtnDown) { 
		 pDC->FillSolidRect(rect, RGB(255, 255, 0)); // yellow     
	}
	// Draw the text           
	if (!strText.IsEmpty()) {         
		CSize Extent = pDC->GetTextExtent(strText); 
		CPoint pt( rect.CenterPoint().x - Extent.cx/2,rect.CenterPoint().y - Extent.cy/2 );          
		if (state & ODS_SELECTED) pt.Offset(1,1);          
		int nMode = pDC->SetBkMode(TRANSPARENT);          
		if (state & ODS_DISABLED)             
			pDC->DrawState(pt, Extent, strText, DSS_DISABLED, TRUE, 0, (HBRUSH)NULL);
		else {
			pDC->DrawState(pt, Extent, strText, DSS_NORMAL, TRUE, 0, (HBRUSH)NULL);
			pDC->TextOut(pt.x, pt.y, strText);     
		}	     
		pDC->SetBkMode(nMode);     
	} 

}

// CMyButton ��Ϣ�������
void CMyButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_LBtnDown = !m_LBtnDown;
	printf("m_LBtnDown=%d\n",m_LBtnDown);
	CButton::OnLButtonDown(nFlags, point);
}


int CMyButton::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CButton::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}


void CMyButton::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CButton::OnShowWindow(bShow, nStatus);

	// TODO: �ڴ˴������Ϣ����������
}


void CMyButton::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CButton::OnTimer(nIDEvent);
}
