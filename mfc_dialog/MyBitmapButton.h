#pragma once


/******************************************************************************************************
 * CMyBitmapButton
 * CBitmapButton��4��bitmap��������ʾ��Up������갴�£�Down������ý��㣨Focused���������ã�Disabled����
 * ����չ��ʹ��ǰ������
 * ��갴���������ʾ�ڶ���ͼƬ���ٴΰ��£��ָ���������ʾ��һ��ͼƬ
 * �ؼ�ʧЧ����δʹ�ܣ���ʾ������ͼƬ��
 * ʹ�ã�
 * �ڶԻ������϶�һ��Button������ID��IDC_BUTTON1
 * �Ի���.h�ļ�������һ����Ա������CMyBitmapButton m_MyBitmapButton; 
 * �Ի���.cpp�ļ�,OnInitDialog()�� 
 *  m_MyBitmapButton.SubclassDlgItem(IDC_BUTTON1,this);       // ����m_MyBitmapButton��IDC_BUTTON1 
 * 	m_MyBitmapButton.LoadBitmaps(IDB_bmp1,IDB_bmp2,IDB_bmp3); // IDB_bmp1...�ǵ����bitmapͼƬ��Դ 
	m_MyBitmapButton.SizeToContent();   // ʹ��ť��ͼ��ͬ��С 
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
	virtual void PreSubclassWindow();  // ��ť�����������д���֮ǰ 
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


