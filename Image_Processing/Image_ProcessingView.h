
// Image_ProcessingView.h : CImage_ProcessingView 类的接口
//

#pragma once
#include "MyImage_.h"
class CImage_ProcessingView : public CScrollView
{
protected: // 仅从序列化创建
	CImage_ProcessingView();
	DECLARE_DYNCREATE(CImage_ProcessingView)

// 特性
public:
	CImage_ProcessingDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CImage_ProcessingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // Image_ProcessingView.cpp 中的调试版本
inline CImage_ProcessingDoc* CImage_ProcessingView::GetDocument() const
   { return reinterpret_cast<CImage_ProcessingDoc*>(m_pDocument); }
#endif

