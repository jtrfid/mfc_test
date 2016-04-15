#pragma once


/******************************************************************************************************
 * CMyBitmapButton
 * CBitmapButton的4个bitmap：正常显示（Up），鼠标按下（Down），获得焦点（Focused），不可用（Disabled）。
 * 本扩展类使用前三个：
 * 鼠标按下左键后，显示第二个图片，再次按下，恢复到正常显示第一个图片
 * 控件失效，即未使能，显示第三幅图片。
 * 使用：
 * 在对话框窗体拖动一个Button，它的ID是IDC_BUTTON1
 * 对话框.h文件，定义一个成员变量，CMyBitmapButton m_MyBitmapButton; 
 * 对话框.cpp文件,OnInitDialog()中 
 *  m_MyBitmapButton.SubclassDlgItem(IDC_BUTTON1,this);       // 关联m_MyBitmapButton与IDC_BUTTON1 
 * 	m_MyBitmapButton.LoadBitmaps(IDB_bmp1,IDB_bmp2,IDB_bmp3); // IDB_bmp1...是导入的bitmap图片资源 
	m_MyBitmapButton.SizeToContent();   // 使按钮于图形同大小 
 ******************************************************************************************************/ 
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
	virtual void PreSubclassWindow();  // 按钮被关联到现有窗口之前 
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


