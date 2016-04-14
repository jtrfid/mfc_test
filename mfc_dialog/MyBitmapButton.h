#pragma once


// CMyBitmapButton

class CMyBitmapButton : public CBitmapButton
{
	DECLARE_DYNAMIC(CMyBitmapButton)

private:
	bool m_LButtonDown;
public:
	CMyBitmapButton();
	virtual ~CMyBitmapButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	virtual void PreSubclassWindow();
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


