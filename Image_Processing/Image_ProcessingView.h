
// Image_ProcessingView.h : CImage_ProcessingView ��Ľӿ�
//

#pragma once
#include "MyImage_.h"
class CImage_ProcessingView : public CScrollView
{
protected: // �������л�����
	CImage_ProcessingView();
	DECLARE_DYNCREATE(CImage_ProcessingView)

// ����
public:
	CImage_ProcessingDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CImage_ProcessingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
public:
	MyImage_ m_Image;

	afx_msg void OnDrawline();
	afx_msg void OnFileSaveAs();
	afx_msg void OnShowred();
//	afx_msg void OnViewToolbar();
	afx_msg void On32780();
	afx_msg void On32792();
	afx_msg void On32793();
	afx_msg void On32794();
	afx_msg void On32795();
	afx_msg void On32785();
	afx_msg void On32786();
	afx_msg void On32787();
	afx_msg void On32788();
	afx_msg void On32789();
	afx_msg void On32790();
	afx_msg void On32791();
	afx_msg void On32796();
	afx_msg void On32797();
	afx_msg void On32798();
	afx_msg void On32799();
	afx_msg void On32800();
	afx_msg void On32801();
	afx_msg void On32802();
	afx_msg void On32803();
	afx_msg void On32804();
	afx_msg void On32805();
	afx_msg void On32806();
	afx_msg void On32807();
	afx_msg void On32808();
	afx_msg void On32809();
	afx_msg void On32810();
	afx_msg void On32811();
	afx_msg void On32812();
	afx_msg void On32813();
	afx_msg void On32814();
	afx_msg void On32816();
	afx_msg void On32817();
	afx_msg void On32818();
};

#ifndef _DEBUG  // Image_ProcessingView.cpp �еĵ��԰汾
inline CImage_ProcessingDoc* CImage_ProcessingView::GetDocument() const
   { return reinterpret_cast<CImage_ProcessingDoc*>(m_pDocument); }
#endif

