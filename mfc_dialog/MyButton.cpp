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
	//���尴ť���򲢳�ʼ�� 
	CRect rect(lpDrawItemStruct->rcItem); 

	//���ñ���ģʽ
	COLORREF oc = pDC->GetTextColor();
	int iObk = pDC->SetBkMode(TRANSPARENT); 

	//��ʼ����ť״̬ 
	UINT state = lpDrawItemStruct->itemState; 
	CFont *pOldFont = NULL; 
	int iYOffset = 0, iXOffset = 0;
	CString strText; 
	GetWindowText(strText); 
	rect.top += iYOffset; 
	rect.left += iXOffset; 

	// ��ťDisabled
	if(state & ODS_DISABLED) {
		//��ť�ûң�DISABLED��
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
	else if (m_LBtnDown) { // ������������
		pDC->Draw3dRect(rect,GetSysColor(COLOR_3DSHADOW),GetSysColor(COLOR_3DHIGHLIGHT));
		// ������ɫ
		pDC->SetTextColor(RGB(0,0,255));
		// �����»��ߣ�Ҳ�������������壩
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
