
// Image_ProcessingView.cpp : CImage_ProcessingView ���ʵ��
//
#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Image_Processing.h"
#endif

#include "Image_ProcessingDoc.h"
#include "Image_ProcessingView.h"

#include "yyj01.h"
#include "yyj02.h"
#include "yyj03.h"
#include "yyj04.h"
#include "yyj05.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImage_ProcessingView

IMPLEMENT_DYNCREATE(CImage_ProcessingView, CScrollView)

BEGIN_MESSAGE_MAP(CImage_ProcessingView, CScrollView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImage_ProcessingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CImage_ProcessingView::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CImage_ProcessingView::OnFileSaveAs)
	
//	ON_COMMAND(ID_VIEW_TOOLBAR, &CImage_ProcessingView::OnViewToolbar)
//ON_COMMAND(ID_32776, &CImage_ProcessingView::On32776)

ON_COMMAND(ID_32792, &CImage_ProcessingView::On32792)
ON_COMMAND(ID_32793, &CImage_ProcessingView::On32793)
ON_COMMAND(ID_32794, &CImage_ProcessingView::On32794)
ON_COMMAND(ID_32795, &CImage_ProcessingView::On32795)
ON_COMMAND(ID_32785, &CImage_ProcessingView::On32785)
ON_COMMAND(ID_32786, &CImage_ProcessingView::On32786)
ON_COMMAND(ID_32787, &CImage_ProcessingView::On32787)
ON_COMMAND(ID_32788, &CImage_ProcessingView::On32788)
ON_COMMAND(ID_32789, &CImage_ProcessingView::On32789)
ON_COMMAND(ID_32790, &CImage_ProcessingView::On32790)
ON_COMMAND(ID_32791, &CImage_ProcessingView::On32791)
ON_COMMAND(ID_32797, &CImage_ProcessingView::On32797)
ON_COMMAND(ID_32798, &CImage_ProcessingView::On32798)
ON_COMMAND(ID_32799, &CImage_ProcessingView::On32799)
ON_COMMAND(ID_32800, &CImage_ProcessingView::On32800)
ON_COMMAND(ID_32801, &CImage_ProcessingView::On32801)
ON_COMMAND(ID_32802, &CImage_ProcessingView::On32802)
ON_COMMAND(ID_32803, &CImage_ProcessingView::On32803)
ON_COMMAND(ID_32804, &CImage_ProcessingView::On32804)
ON_COMMAND(ID_32805, &CImage_ProcessingView::On32805)
ON_COMMAND(ID_32806, &CImage_ProcessingView::On32806)
ON_COMMAND(ID_32807, &CImage_ProcessingView::On32807)
ON_COMMAND(ID_32808, &CImage_ProcessingView::On32808)
ON_COMMAND(ID_32809, &CImage_ProcessingView::On32809)
ON_COMMAND(ID_32810, &CImage_ProcessingView::On32810)
ON_COMMAND(ID_32811, &CImage_ProcessingView::On32811)
ON_COMMAND(ID_32812, &CImage_ProcessingView::On32812)
ON_COMMAND(ID_32813, &CImage_ProcessingView::On32813)
ON_COMMAND(ID_32814, &CImage_ProcessingView::On32814)
ON_COMMAND(ID_32816, &CImage_ProcessingView::On32816)
ON_COMMAND(ID_32817, &CImage_ProcessingView::On32817)
ON_COMMAND(ID_32818, &CImage_ProcessingView::On32818)
ON_COMMAND(ID_32820, &CImage_ProcessingView::On32820)
ON_COMMAND(ID_32821, &CImage_ProcessingView::On32821)
ON_COMMAND(ID_32822, &CImage_ProcessingView::On32822)
ON_COMMAND(ID_32823, &CImage_ProcessingView::On32823)
ON_COMMAND(ID_32825, &CImage_ProcessingView::On32825)
ON_COMMAND(ID_32826, &CImage_ProcessingView::On32826)
ON_COMMAND(ID_32827, &CImage_ProcessingView::On32827)
ON_COMMAND(ID_32828, &CImage_ProcessingView::On32828)
ON_COMMAND(ID_32829, &CImage_ProcessingView::On32829)
ON_COMMAND(ID_32831, &CImage_ProcessingView::On32831)
ON_COMMAND(ID_32833, &CImage_ProcessingView::On32833)
ON_COMMAND(ID_32834, &CImage_ProcessingView::On32834)
ON_COMMAND(ID_32835, &CImage_ProcessingView::On32835)
ON_COMMAND(ID_32836, &CImage_ProcessingView::On32836)
ON_COMMAND(ID_32837, &CImage_ProcessingView::On32837)
ON_COMMAND(ID_32838, &CImage_ProcessingView::On32838)
ON_COMMAND(ID_32839, &CImage_ProcessingView::On32839)
ON_COMMAND(ID_32842, &CImage_ProcessingView::On32842)
ON_COMMAND(ID_32843, &CImage_ProcessingView::On32843)
ON_COMMAND(ID_RGB32860, &CImage_ProcessingView::OnRgb32860)
ON_COMMAND(ID_RGB32861, &CImage_ProcessingView::OnRgb32861)
ON_COMMAND(ID_RGB32862, &CImage_ProcessingView::OnRgb32862)
ON_COMMAND(ID_RGB32863, &CImage_ProcessingView::OnRgb32863)
ON_COMMAND(ID_HSI32865, &CImage_ProcessingView::OnHsi32865)
ON_COMMAND(ID_HSI32866, &CImage_ProcessingView::OnHsi32866)
ON_COMMAND(ID_HSI32867, &CImage_ProcessingView::OnHsi32867)
ON_COMMAND(ID_HSI32868, &CImage_ProcessingView::OnHsi32868)
ON_COMMAND(ID_32870, &CImage_ProcessingView::On32870)
ON_COMMAND(ID_32871, &CImage_ProcessingView::On32871)
ON_COMMAND(ID_32872, &CImage_ProcessingView::On32872)
ON_COMMAND(ID_32874, &CImage_ProcessingView::On32874)
ON_COMMAND(ID_32875, &CImage_ProcessingView::On32875)
ON_COMMAND(ID_32876, &CImage_ProcessingView::On32876)
ON_COMMAND(ID_32877, &CImage_ProcessingView::On32877)
ON_COMMAND(ID_32878, &CImage_ProcessingView::On32878)
ON_COMMAND(ID_32879, &CImage_ProcessingView::On32879)
END_MESSAGE_MAP()

// CImage_ProcessingView ����/����

CImage_ProcessingView::CImage_ProcessingView()
{
	// TODO: �ڴ˴���ӹ������

}

CImage_ProcessingView::~CImage_ProcessingView()
{
}

BOOL CImage_ProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CImage_ProcessingView ����

void CImage_ProcessingView::OnDraw(CDC* pDC)
{
	CImage_ProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (!m_Image.IsNull())
	{
		m_Image.Draw(pDC->m_hDC,0,0); 
	}
	return;
}

void CImage_ProcessingView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CImage_ProcessingView ��ӡ


void CImage_ProcessingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImage_ProcessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CImage_ProcessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CImage_ProcessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CImage_ProcessingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImage_ProcessingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImage_ProcessingView ���

#ifdef _DEBUG
void CImage_ProcessingView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImage_ProcessingView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImage_ProcessingDoc* CImage_ProcessingView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImage_ProcessingDoc)));
	return (CImage_ProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CImage_ProcessingView ��Ϣ�������


void CImage_ProcessingView::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog dlg(TRUE);    //Ϊ���ļ�����һ������
	if(IDOK == dlg.DoModal())    //���ú�����һ���Ի��򣬲��ж��Ƿ�򿪳ɹ�
	{
		if(!m_Image.IsNull()) m_Image.Destroy();//�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
		m_Image.Load(dlg.GetPathName());//���ͼƬ�ĵ�ַ�����Ҽ���ͼƬ

		//���ͼƬ�Ĵ�С���������С���ù������ĳ�ʼ���ڴ�С�Ȳ���
		CSize sizeTotal;
		int w=m_Image.GetWidth();
		int h=m_Image.GetHeight();
		sizeTotal.cx =w;
		sizeTotal.cy =h;
		SetScrollSizes(MM_TEXT, sizeTotal);

		//Window_Image_w=m_Image.GetWidth();//���ͼƬ�ĳ�ʼ��С��Ϊ�Ŵ���С������׼��
		//Window_Image_h=m_Image.GetHeight();//


		Invalidate(1); //ǿ�Ƶ���ONDRAW����
	}
}


void CImage_ProcessingView::OnFileSaveAs()
{
	// TODO: �ڴ���������������
	if (m_Image.IsNull()) {
		MessageBox(_T("�㻹û�д�һ��Ҫ�����ͼ���ļ���"));
		return;
	}
	CString strFilter;
	//strFilter ="λͼ�ļ�|*.bmp|JPEG ͼ���ļ�|*.jpg|GIF ͼ���ļ�|*.gif|PNG ͼ���ļ�|*.png||";   //
	strFilter ="�����ļ�|*.*||";   //

	CFileDialog dlg(FALSE,NULL,NULL,NULL,strFilter);
	//CFileDialog dlg(FALSE,NULL,NULL,NULL);

	if ( IDOK != dlg.DoModal()) 
		return;
	// ����û�û��ָ���ļ���չ������Ϊ�����һ��
	CString strFileName;
	//CString strExtension;
	strFileName = dlg.m_ofn.lpstrFile;   //  ����ļ���
	//if(dlg.m_ofn.nFileExtension == 0)     //����ļ���չ��
	//{
	//	switch (dlg.m_ofn.nFilterIndex)
	//	{
	//	case 1:
	//		strExtension = "bmp"; break;
	//	case 2:
	//		strExtension = "jpg"; break;
	//	case 3:
	//		strExtension = "gif"; break;
	//	case 4:
	//		strExtension = "png"; break;
	//	default:
	//		break;
	//	}
	//	strFileName = strFileName + _T(".") + strExtension;
	//	//strFileName="C:\\Users\\Lenovo\\Desktop\\QSanguosha-Qingming\\abc.bmp";
	//}
	// ͼ�񱣴�
	HRESULT hResult = m_Image.Save(strFileName);
	if (FAILED(hResult))
	{
		MessageBox(_T("����ͼ���ļ�ʧ�ܣ�"));
	}

}



//void CImage_ProcessingView::OnViewToolbar()
//{
//	// TODO: �ڴ���������������
//}




/////////////////////////////////////////////////////////////////////////////////////////////////
//                                   ����������������ҵ                                        //
//                                                                                             //(ͼ�� 0:B 1:G 2:R)
//                    *ע ���ĵĺ������봢���� yyj.h �� yyj.c �ļ���                           //
/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//												��һ����ҵ
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1. ����ͼ��ռ�ֱ���1/2
void CImage_ProcessingView::On32792()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));    //����洢ͼ�������

	for (int i = 0; i < h; ++i)         //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;
	 
	reduce_spatial_resolution(img, 2);  //���ͷֱ���

	for (int i = 0; i < h; ++i)         //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW��������ͼ��
}


//����ͼ��ռ�ֱ���1/4
void CImage_ProcessingView::On32793()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_spatial_resolution(img, 4); //���ͷֱ��ʽ�

	for (int i = 0; i < h; ++i)        //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)   
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW��������ͼ��
}

//����ͼ��ռ�ֱ���1/8
void CImage_ProcessingView::On32794()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_spatial_resolution(img, 8);//���ͷֱ��ʽ�

	for (int i = 0; i < h; ++i)       //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW��������ͼ��
}


//����ͼ��ռ�ֱ���1/16
void CImage_ProcessingView::On32795()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)       //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_spatial_resolution(img, 16); //���ͷֱ���

	for (int i = 0; i < h; ++i)        //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW��������ͼ��
}


//����ͼ��Ҷȷֱ���1/2 128��
void CImage_ProcessingView::On32785()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 2);  //���ͷֱ���

	for (int i = 0; i < h; ++i)           //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW��������ͼ��
}

//����ͼ��Ҷȷֱ���1/4 64��
void CImage_ProcessingView::On32786()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 4);  //���ͷֱ���

	for (int i = 0; i < h; ++i)           //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW��������ͼ��
}

//����ͼ��Ҷȷֱ���1/8 32��
void CImage_ProcessingView::On32787()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 8);   //���ͷֱ���

	for (int i = 0; i < h; ++i)            //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW��������ͼ��
}

//����ͼ��Ҷȷֱ���1/16 16��
void CImage_ProcessingView::On32788()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 16);   //���ͷֱ���

	for (int i = 0; i < h; ++i)             //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW��������ͼ��
}

//����ͼ��Ҷȷֱ���1/32 8��
void CImage_ProcessingView::On32789()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 32);    //���ͷֱ���

	for (int i = 0; i < h; ++i)              //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW��������ͼ��
}

//����ͼ��Ҷȷֱ���1/64 4��
void CImage_ProcessingView::On32790()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 64);   //���ͷֱ���

	for (int i = 0; i < h; ++i)             //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW��������ͼ��
}

//����ͼ��Ҷȷֱ���1/128 2��
void CImage_ProcessingView::On32791()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 128);    //���ͷֱ���

	for (int i = 0; i < h; ++i)              //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW��������ͼ��
}


//���ȥ������ͼ��1��ʾ
void CImage_ProcessingView::On32797()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex1_imgs/zao1.jpg";   //ָ��ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡ�����е�ͼ��
	
    Invalidate(1); //ǿ�Ƶ���ONDRAW����

}

//���ȥ������ͼ��2��ʾ
void CImage_ProcessingView::On32798()
{
	if (!m_Image.IsNull()) m_Image.Destroy();       //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex1_imgs/zao2.jpg";  //ָ��ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                //��ȡ�����е�ͼ��
	
	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//���ȥ������ͼ��3
void CImage_ProcessingView::On32799()
{
	if (!m_Image.IsNull()) m_Image.Destroy();       //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex1_imgs/zao3.jpg";  //ָ��ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                //��ȡ�����е�ͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//���ȥ������ͼ��4
void CImage_ProcessingView::On32800()
{
	if (!m_Image.IsNull()) m_Image.Destroy();       //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex1_imgs/zao4.jpg";  //ָ��ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                //��ȡ�����е�ͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//���ȥ������ͼ��5
void CImage_ProcessingView::On32801()
{
	if (!m_Image.IsNull()) m_Image.Destroy();       //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex1_imgs/zao5.jpg";  //ָ��ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                //��ȡ�����е�ͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����

}

//���ȥ��Ч��ͼ
void CImage_ProcessingView::On32802()
{
	int img_num = 5;    //ͼ������
	int w = 0;          //ͼ����
	int h = 0;          //ͼ��߶�
	vector<vector<vector<double>>> imgs;   //����洢����ͼ������
	
	int flag = 0;                          //��־����
	for (int v = 0; v < img_num; ++v)
	{
		++flag;
		if (!m_Image.IsNull()) m_Image.Destroy();                 //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
		std::string file_path = "./ex1_imgs/zao";                 //ָ��ͼ���ļ�·��ͷ
		file_path = file_path + std::to_string(v+1) + "\.jpg";    //ָ��ͼ�������ļ�·��
		m_Image.Load(file_path.c_str());
		w = m_Image.GetWidth();       //���ͼ����
	    h = m_Image.GetHeight();      //���ͼ��߶�
		if (flag == 1)
		{
			imgs.resize(img_num);                //��ʼ��������С
			for (int k = 0; k < img_num; ++k)
			{
				imgs[k].resize(h);
				for (int i = 0; i < h; ++i)
					imgs[k][i].resize(w);
			}
		}
		for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
			for (int j = 0; j < w; ++j)
				imgs[v][i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;
	}
	
	superimposed_denoising(imgs);       //����ȥ��

	for (int i = 0; i < h; ++i)         //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = imgs[0][i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//�����ǿ��ģ��ͼ����ʾ
void CImage_ProcessingView::On32803()
{
	if (!m_Image.IsNull()) m_Image.Destroy();       //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex1_imgs/cha1.jpg";  //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��Ҫ��ǿ��ͼ����ʾ
void CImage_ProcessingView::On32804()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex1_imgs/cha2.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}


//�����ǿ���Ч��
void CImage_ProcessingView::On32805()
{
	if (!m_Image.IsNull()) m_Image.Destroy();         //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex1_imgs/cha1.jpg";    //ģ��ͼ��·��
	m_Image.Load(file_path.c_str());                  //��ȡģ��ͼ��
	const int w = m_Image.GetWidth();      //���ͼ����
	const int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img1(h, vector<double>(w, 0)), img2(h, vector<double>(w, 0));  //����洢ͼ�������

	for (int i = 0; i < h; ++i)              //��ģ��ͼ���������
		for (int j = 0; j < w; ++j)
			img1[i][j] = m_Image.m_pBits[0][i][j];

	if (!m_Image.IsNull()) m_Image.Destroy();     //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	file_path = "./ex1_imgs/cha2.jpg";            //��Ҫ��ǿ��ͼ��·��
	m_Image.Load(file_path.c_str());              //��ȡ��Ҫ��ǿ��ͼ��
	for (int i = 0; i < h; ++i)                   //����Ҫ��ǿ��ͼ���������
		for (int j = 0; j < w; ++j)
			img2[i][j] = m_Image.m_pBits[0][i][j];

	differential_enhancement(img1, img2);         //�����ǿ

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img1[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//												�ڶ�����ҵ
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//��ʾֱ��ͼ
vector<double> Pz(256, 0);
void CImage_ProcessingView::On32814()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<int>> img(h, vector<int>(w, 0));
	vector<vector<int>> hstgm(h, vector<int>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	Pz = histogram_display(img, hstgm);    //��ʾֱ��ͼ

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//ֱ��ͼ���⻯
vector<vector<int>> img_jun, img_jun_2;          //ȫ�ֱ������洢ԭͼ�񣬾��⻯���ͼ��

//��ʾԭͼ��ֱ��ͼ
void CImage_ProcessingView::On32816()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	img_jun.resize(h);
	for (auto& c : img_jun)
		c.resize(w);
	vector<vector<int>> hstgm(h, vector<int>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img_jun[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	histogram_display(img_jun, hstgm);    //��ʾֱ��ͼ

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//���⻯���ֱ��ͼ
void CImage_ProcessingView::On32817()
{
	img_jun_2 = histogram_equalization(img_jun); //���⻯ֱ��ͼ

	int h = img_jun_2.size();        //���ͼ����
	int w = img_jun_2[0].size();     //���ͼ��߶�
	vector<vector<int>> hstgm(h, vector<int>(w, 0));

	histogram_display(img_jun_2, hstgm);    //��ʾֱ��ͼ
	
	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//���⻯���ͼ����ʾ
void CImage_ProcessingView::On32818()
{
	int h = img_jun_2.size();        //���ͼ����
	int w = img_jun_2[0].size();     //���ͼ��߶�

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_jun_2[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}


//ֱ��ͼ���
vector<vector<int>> img_gui, img_gui_jun, img_gui_2;        //ȫ�ֱ���:�洢ԭͼ�񣬾��⻯���ͼ�񣬹�񻯺��ͼ��

//��ʾԭͼ��ֱ��ͼ
void CImage_ProcessingView::On32820()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	img_gui.resize(h);
	for (auto& c : img_gui)
		c.resize(w);
	img_gui_jun = img_gui_2 = img_gui;
	auto hstgm = img_gui;

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img_gui[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	auto x = histogram_display(img_gui, hstgm);    //��ʾֱ��ͼ

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//ϣ����ֱ��ͼ��ʽ��ʹ���ϲ����⻯��ͼ����Ϊ�ο�
void CImage_ProcessingView::On32821()
{
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<int>> hstgm(h, vector<int>(w, 0));

	histogram2(Pz, hstgm);

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��񻯺��ֱ��ͼ
void CImage_ProcessingView::On32822()
{
	int w = img_gui.size();        //���ͼ����
	int h = img_gui[0].size();     //���ͼ��߶�
	
	auto hstgm = img_gui;
	img_gui_jun = histogram_equalization(img_gui); //���⻯ͼ��
	histogram_specification(img_gui_jun, img_gui_2, Pz);
	auto x = histogram_display(img_gui_2, hstgm);          //��ʾֱ��ͼ
	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//�涨�����ͼ����ʾ
void CImage_ProcessingView::On32823()
{
	int w = img_gui.size();        //���ͼ����
	int h = img_gui[0].size();     //���ͼ��߶�

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_gui_2[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��ֵ�˲�
void CImage_ProcessingView::On32806()
{
	; //����������
}


//��ֵ�˲�
void CImage_ProcessingView::On32807()
{
	; //����������
}

//3x3��ֵ�˲�
void CImage_ProcessingView::On32808()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	mean_filtering(img, 3);

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//5x5��ֵ�˲�
void CImage_ProcessingView::On32809()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	mean_filtering(img, 5);

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//9x9��ֵ�˲�
void CImage_ProcessingView::On32810()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	mean_filtering(img, 9);

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//15x15��ֵ�˲�
void CImage_ProcessingView::On32811()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	mean_filtering(img, 15);

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//3x3��ֵ�˲�
void CImage_ProcessingView::On32812()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	median_filtering(img, 3);

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//5x5��ֵ�˲�
void CImage_ProcessingView::On32813()
{
	if (m_Image.IsNull()) return;    //�ж�ͼ���Ƿ�Ϊ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	median_filtering(img, 5);

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//												��������ҵ
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//��ʾ����Ҷ�任ԭͼ��
void CImage_ProcessingView::On32825()   
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img1.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//ԭͼ��ĸ���Ҷ�任
void CImage_ProcessingView::On32826()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img1.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�

	vector<vector<double>> img_raw(h, vector<double>(w, 0));   //��ͼ��ֵ��һ��vector����
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);       //�Ҷ�ֵ���ŵ�0-1֮��
	move2center(img_raw);           //������ҶƵ���Ƶ�ͼ������
	auto img_mag = img_raw;         //������
	auto img_ang = img_raw;         //�����

	fft(img_raw, img_mag, img_ang); //���и���Ҷ�任
	log_exp(img_mag);               //��������Ҷ�ֵ��С������
	normalize(img_mag, 0, 255);     //���Ҷ����ŵ�0-255

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_mag[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����

}

//ƽ�ƺ��ͼ��
void CImage_ProcessingView::On32827()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img2.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//ƽ�ƺ�ͼ��ĸ���Ҷ�任
void CImage_ProcessingView::On32828()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./imgs/img2.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�

	vector<vector<double>> img_raw(h, vector<double>(w, 0));   //ͼ��ֵ��vector����
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);          //��һ��
	move2center(img_raw);              //Ƶ���Ƶ�����
	auto img_mag = img_raw;            //��ֵ
	auto img_ang = img_raw;            //���

	fft(img_raw, img_mag, img_ang);    //���ٸ���Ҷ�任
	log_exp(img_mag);                  //��������
	normalize(img_mag, 0, 255);        //��һ����0-255

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_mag[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��ת���ͼ��
void CImage_ProcessingView::On32829()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img3.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��ת��ͼ��ĸ���Ҷ�任
void CImage_ProcessingView::On32831()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img3.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�

	vector<vector<double>> img_raw(h, vector<double>(w, 0)); //ͼ��ֵ��vector����
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);    //��һ��
	move2center(img_raw);        //Ƶ���Ƶ�����
	auto img_mag = img_raw;      //��ֵ
	auto img_ang = img_raw;      //���

	fft(img_raw, img_mag, img_ang);   //���ٸ���Ҷ�任
	log_exp(img_mag);                 //��������
	normalize(img_mag, 0, 255);       //��һ����0-255

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_mag[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��ʾ�����˲���ԭͼ��
void CImage_ProcessingView::On32833()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img4.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//�����ͨ�˲�
void CImage_ProcessingView::On32834()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img4.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	int P = 2 * h;                   //��0�����ĸ߶�
	int Q = 2 * w;                   //��0�����Ŀ��
	int D = 30;                      //�˲����뾶
	vector<vector<double>> img_raw(h, vector<double>(w, 0));   //ԭͼ��
	vector<vector<double>> img_exp(P, vector<double>(Q, 0));   //������ͼ��
	vector<vector<double>> img_mag(P, vector<double>(Q, 0));   //��ֵ��
	vector<vector<double>> img_ang(P, vector<double>(Q, 0));   //�����
	vector<vector<double>> H(P, vector<double>(Q, 0));         //�˲���
	vector<vector<double>> G(P, vector<double>(Q, 0));         //�˲���ķ�����

	for (int i = 0; i < h; ++i)          //ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);          //��һ����0-1֮��
	move2center(img_raw);              //������Ҷ���Ƶ�����
	img2big(img_raw, img_exp);         //��0���䵽����
	fft(img_exp, img_mag, img_ang);    //���ٸ���Ҷ�任
	make_filter(H, D, 0);              //���������ͨ�˲���
	act_filter(img_mag, H, G);         //ִ���˲�
	invfft(G, img_ang, img_exp);       //����Ҷ���仯

	for (int i = 0; i < h; ++i)        //ȡ���仯��ͼ����ķ�֮һ���Ͻ�
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = img_exp[i][j];

	move2center(img_raw);              //�ƻ�ԭ����ͼ��
	normalize(img_raw, 0, 255);        //��һ����0-255

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_raw[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//������˹��ͨ�˲�
void CImage_ProcessingView::On32835()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img4.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	int P = 2 * h;                   //��0�����ĸ߶�
	int Q = 2 * w;                   //��0�����Ŀ��
	int D = 30;                      //�˲����뾶
	vector<vector<double>> img_raw(h, vector<double>(w, 0));   //ԭͼ��
	vector<vector<double>> img_exp(P, vector<double>(Q, 0));   //������ͼ��
	vector<vector<double>> img_mag(P, vector<double>(Q, 0));   //��ֵ��
	vector<vector<double>> img_ang(P, vector<double>(Q, 0));   //�����
	vector<vector<double>> H(P, vector<double>(Q, 0));         //�˲���
	vector<vector<double>> G(P, vector<double>(Q, 0));         //�˲���ķ�����

	for (int i = 0; i < h; ++i)          //ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);          //��һ����0-1֮��
	move2center(img_raw);              //������Ҷ���Ƶ�����
	img2big(img_raw, img_exp);         //��0���䵽����
	fft(img_exp, img_mag, img_ang);    //���ٸ���Ҷ�任
	make_filter(H, D, 1);              //���ɰ�����˹��ͨ�˲���
	act_filter(img_mag, H, G);         //ִ���˲�
	invfft(G, img_ang, img_exp);       //����Ҷ���仯

	for (int i = 0; i < h; ++i)        //ȡ���仯��ͼ����ķ�֮һ���Ͻ�
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = img_exp[i][j];

	move2center(img_raw);              //�ƻ�ԭ����ͼ��
	normalize(img_raw, 0, 255);        //��һ����0-255

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_raw[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��˹��ͨ�˲�
void CImage_ProcessingView::On32836()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img4.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	int P = 2 * h;                   //��0�����ĸ߶�
	int Q = 2 * w;                   //��0�����Ŀ��
	int D = 30;                      //�˲����뾶
	vector<vector<double>> img_raw(h, vector<double>(w, 0));   //ԭͼ��
	vector<vector<double>> img_exp(P, vector<double>(Q, 0));   //������ͼ��
	vector<vector<double>> img_mag(P, vector<double>(Q, 0));   //��ֵ��
	vector<vector<double>> img_ang(P, vector<double>(Q, 0));   //�����
	vector<vector<double>> H(P, vector<double>(Q, 0));         //�˲���
	vector<vector<double>> G(P, vector<double>(Q, 0));         //�˲���ķ�����

	for (int i = 0; i < h; ++i)          //ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);          //��һ����0-1֮��
	move2center(img_raw);              //������Ҷ���Ƶ�����
	img2big(img_raw, img_exp);         //��0���䵽����
	fft(img_exp, img_mag, img_ang);    //���ٸ���Ҷ�任
	make_filter(H, D, 2);              //���ɸ�˹��ͨ�˲���
	act_filter(img_mag, H, G);         //ִ���˲�
	invfft(G, img_ang, img_exp);       //����Ҷ���仯

	for (int i = 0; i < h; ++i)        //ȡ���仯��ͼ����ķ�֮һ���Ͻ�
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = img_exp[i][j];

	move2center(img_raw);              //�ƻ�ԭ����ͼ��
	normalize(img_raw, 0, 255);        //��һ����0-255

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_raw[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//�����ͨ�˲�
void CImage_ProcessingView::On32837()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img4.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	int P = 2 * h;                   //��0�����ĸ߶�
	int Q = 2 * w;                   //��0�����Ŀ��
	int D = 50;                      //�˲����뾶
	vector<vector<double>> img_raw(h, vector<double>(w, 0));   //ԭͼ��
	vector<vector<double>> img_exp(P, vector<double>(Q, 0));   //������ͼ��
	vector<vector<double>> img_mag(P, vector<double>(Q, 0));   //��ֵ��
	vector<vector<double>> img_ang(P, vector<double>(Q, 0));   //�����
	vector<vector<double>> H(P, vector<double>(Q, 0));         //�˲���
	vector<vector<double>> G(P, vector<double>(Q, 0));         //�˲���ķ�����

	for (int i = 0; i < h; ++i)          //ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);          //��һ����0-1֮��
	move2center(img_raw);              //������Ҷ���Ƶ�����
	img2big(img_raw, img_exp);         //��0���䵽����
	fft(img_exp, img_mag, img_ang);    //���ٸ���Ҷ�任
	make_filter(H, D, 3);              //���������ͨ�˲���
	act_filter(img_mag, H, G);         //ִ���˲�
	invfft(G, img_ang, img_exp);       //����Ҷ���仯

	for (int i = 0; i < h; ++i)        //ȡ���仯��ͼ����ķ�֮һ���Ͻ�
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = img_exp[i][j];

	move2center(img_raw);              //�ƻ�ԭ����ͼ��
	normalize(img_raw, 0, 255);        //��һ����0-255

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_raw[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//������˹��ͨ�˲�
void CImage_ProcessingView::On32838()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img4.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	int P = 2 * h;                   //��0�����ĸ߶�
	int Q = 2 * w;                   //��0�����Ŀ��
	int D = 50;                      //�˲����뾶
	vector<vector<double>> img_raw(h, vector<double>(w, 0));   //ԭͼ��
	vector<vector<double>> img_exp(P, vector<double>(Q, 0));   //������ͼ��
	vector<vector<double>> img_mag(P, vector<double>(Q, 0));   //��ֵ��
	vector<vector<double>> img_ang(P, vector<double>(Q, 0));   //�����
	vector<vector<double>> H(P, vector<double>(Q, 0));         //�˲���
	vector<vector<double>> G(P, vector<double>(Q, 0));         //�˲���ķ�����

	for (int i = 0; i < h; ++i)          //ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);          //��һ����0-1֮��
	move2center(img_raw);              //������Ҷ���Ƶ�����
	img2big(img_raw, img_exp);         //��0���䵽����
	fft(img_exp, img_mag, img_ang);    //���ٸ���Ҷ�任
	make_filter(H, D, 4);              //���ɰ�����˹��ͨ�˲���
	act_filter(img_mag, H, G);         //ִ���˲�
	invfft(G, img_ang, img_exp);       //����Ҷ���仯

	for (int i = 0; i < h; ++i)        //ȡ���仯��ͼ����ķ�֮һ���Ͻ�
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = img_exp[i][j];

	move2center(img_raw);              //�ƻ�ԭ����ͼ��
	normalize(img_raw, 0, 255);        //��һ����0-255

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_raw[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��˹��ͨ�˲�
void CImage_ProcessingView::On32839()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img4.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	int P = 2 * h;                   //��0�����ĸ߶�
	int Q = 2 * w;                   //��0�����Ŀ��
	int D = 50;                      //�˲����뾶
	vector<vector<double>> img_raw(h, vector<double>(w, 0));   //ԭͼ��
	vector<vector<double>> img_exp(P, vector<double>(Q, 0));   //������ͼ��
	vector<vector<double>> img_mag(P, vector<double>(Q, 0));   //��ֵ��
	vector<vector<double>> img_ang(P, vector<double>(Q, 0));   //�����
	vector<vector<double>> H(P, vector<double>(Q, 0));         //�˲���
	vector<vector<double>> G(P, vector<double>(Q, 0));         //�˲���ķ�����

	for (int i = 0; i < h; ++i)          //ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);          //��һ����0-1֮��
	move2center(img_raw);              //������Ҷ���Ƶ�����
	img2big(img_raw, img_exp);         //��0���䵽����
	fft(img_exp, img_mag, img_ang);    //���ٸ���Ҷ�任
	make_filter(H, D, 5);              //���ɸ�˹��ͨ�˲���
	act_filter(img_mag, H, G);         //ִ���˲�
	invfft(G, img_ang, img_exp);       //����Ҷ���仯

	for (int i = 0; i < h; ++i)        //ȡ���仯��ͼ����ķ�֮һ���Ͻ�
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = img_exp[i][j];

	move2center(img_raw);              //�ƻ�ԭ����ͼ��
	normalize(img_raw, 0, 255);        //��һ����0-255

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_raw[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//�����0�ĸ�ͨ�˲�
void CImage_ProcessingView::On32842()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img4.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	int D = 50;                      //�˲����뾶
	vector<vector<double>> img_raw(h, vector<double>(w, 0));  //ԭͼ��
	vector<vector<double>> img_mag(h, vector<double>(w, 0));  //��ֵ
	vector<vector<double>> img_ang(h, vector<double>(w, 0));  //���
	vector<vector<double>> H(h, vector<double>(w, 0));        //�˲���
	vector<vector<double>> G(h, vector<double>(w, 0));        //�˲���ķ�ֵ

	for (int i = 0; i < h; ++i)              //��ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);           //��һ����0-1֮��
	move2center(img_raw);               //�ƶ�����Ҷ�׵�����
	fft(img_raw, img_mag, img_ang);     //���ٸ���Ҷ�任
	make_filter(H, D, 5);               //�����˹��ͨ�˲���
	act_filter(img_mag, H, G);          //ִ���˲�
	invfft(G, img_ang, img_raw);        //����Ҷ���仯

	move2center(img_raw);               //�ƻ�ͼ��
	normalize(img_raw, 0, 255);         //��һ����0-255

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_raw[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//�����0�ĵ�ͨ�˲�
void CImage_ProcessingView::On32843()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex3_imgs/img4.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	int D = 30;                      //�˲����뾶
	vector<vector<double>> img_raw(h, vector<double>(w, 0));  //ԭͼ��
	vector<vector<double>> img_mag(h, vector<double>(w, 0));  //��ֵ
	vector<vector<double>> img_ang(h, vector<double>(w, 0));  //���
	vector<vector<double>> H(h, vector<double>(w, 0));        //�˲���
	vector<vector<double>> G(h, vector<double>(w, 0));        //�˲���ķ�ֵ

	for (int i = 0; i < h; ++i)              //��ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);           //��һ����0-1֮��
	move2center(img_raw);               //�ƶ�����Ҷ�׵�����
	fft(img_raw, img_mag, img_ang);     //���ٸ���Ҷ�任
	make_filter(H, D, 2);               //�����˹��ͨ�˲���
	act_filter(img_mag, H, G);          //ִ���˲�
	invfft(G, img_ang, img_raw);        //����Ҷ���仯

	move2center(img_raw);               //�ƻ�ͼ��
	normalize(img_raw, 0, 255);         //��һ����0-255

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_raw[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//												���Ĵ���ҵ
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1. ͼ��RGB������ʾ
//��ʾԭͼ��
void CImage_ProcessingView::OnRgb32860()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/lena.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	
	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}


//��ʾR����
void CImage_ProcessingView::OnRgb32861()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/lena.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = 0;

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��ʾG����
void CImage_ProcessingView::OnRgb32862()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/lena.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[2][i][j] = 0;

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��ʾB����
void CImage_ProcessingView::OnRgb32863()
{
	if (!m_Image.IsNull()) m_Image.Destroy();            //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/lena.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                     //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = 0;

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//2. HSI������ʾ
//ԭͼ��
void CImage_ProcessingView::OnHsi32865()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/lena.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��ʾH����
void CImage_ProcessingView::OnHsi32866()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/lena.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<vector<double>>> img_rgb, img_hsi; //����vector�洢ͼ���RGBֵ��HSIֵ
	img_rgb.resize(3);
	for (int i = 0; i < 3; ++i)
		img_rgb[i].resize(h);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < h; ++j)
			img_rgb[i][j].resize(w);
	img_hsi = img_rgb;                      
	for (int i = 0; i < h; ++i)              //��ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
		{
			img_rgb[0][i][j] = m_Image.m_pBits[2][i][j];
			img_rgb[1][i][j] = m_Image.m_pBits[1][i][j];
			img_rgb[2][i][j] = m_Image.m_pBits[0][i][j];
		}

	rgb2hsi(img_rgb, img_hsi);                  //RGBת��ΪHSI
	normalize(img_hsi[0], 0, 255);              //H������һ����0-255

	for (int i = 0; i < h; ++i)                 //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
		{
			m_Image.m_pBits[0][i][j] = img_hsi[0][i][j];
			m_Image.m_pBits[1][i][j] = img_hsi[0][i][j];
			m_Image.m_pBits[2][i][j] = img_hsi[0][i][j];
		}
		
	Invalidate(1); //ǿ�Ƶ���ONDRAW����	
}

//��ʾS����
void CImage_ProcessingView::OnHsi32867()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/lena.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<vector<double>>> img_rgb, img_hsi;   //����vector�洢ͼ���RGBֵ��HSIֵ
	img_rgb.resize(3);
	for (int i = 0; i < 3; ++i)
		img_rgb[i].resize(h);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < h; ++j)
			img_rgb[i][j].resize(w);
	img_hsi = img_rgb;                       
	for (int i = 0; i < h; ++i)              //��ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
		{
			img_rgb[0][i][j] = m_Image.m_pBits[2][i][j];
			img_rgb[1][i][j] = m_Image.m_pBits[1][i][j];
			img_rgb[2][i][j] = m_Image.m_pBits[0][i][j];
		}

	rgb2hsi(img_rgb, img_hsi);                  //RGBת��ΪHSI
	normalize(img_hsi[1], 0, 255);              //S������һ����0-255

	for (int i = 0; i < h; ++i)                 //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
		{
			m_Image.m_pBits[0][i][j] = img_hsi[1][i][j];
			m_Image.m_pBits[1][i][j] = img_hsi[1][i][j];
			m_Image.m_pBits[2][i][j] = img_hsi[1][i][j];
		}

	Invalidate(1); //ǿ�Ƶ���ONDRAW����	
}

//��ʾI����
void CImage_ProcessingView::OnHsi32868()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/lena.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<vector<double>>> img_rgb, img_hsi;    //����vector�洢ͼ���RGBֵ��HSIֵ
	img_rgb.resize(3);
	for (int i = 0; i < 3; ++i)
		img_rgb[i].resize(h);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < h; ++j)
			img_rgb[i][j].resize(w);
	img_hsi = img_rgb;
	for (int i = 0; i < h; ++i)              //��ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
		{
			img_rgb[0][i][j] = m_Image.m_pBits[2][i][j];
			img_rgb[1][i][j] = m_Image.m_pBits[1][i][j];
			img_rgb[2][i][j] = m_Image.m_pBits[0][i][j];
		}

	rgb2hsi(img_rgb, img_hsi);                   //RGBת��ΪHSI
	//normalize(img_hsi[2], 0, 255);             //I������һ����0-255

	for (int i = 0; i < h; ++i)                  //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
		{
			m_Image.m_pBits[0][i][j] = img_rgb[2][i][j];
			m_Image.m_pBits[1][i][j] = img_rgb[2][i][j];
			m_Image.m_pBits[2][i][j] = img_rgb[2][i][j];
		}

	Invalidate(1); //ǿ�Ƶ���ONDRAW����	
}

//3. ���־��⻯�Ա�
//ԭͼ��
void CImage_ProcessingView::On32870()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/img1.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}


//RGB���⻯
void CImage_ProcessingView::On32871()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/img1.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<vector<int>>> img1, img2;          //����vector�洢ͼ���ԭʼRGBֵ�;��⻯���RGBֵ
	img1.resize(3);
	for (int i = 0; i < 3; ++i)
		img1[i].resize(h);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < h; ++j)
			img1[i][j].resize(w);
	img2 = img1;
	for (int i = 0; i < h; ++i)              //��ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
		{
			img1[0][i][j] = m_Image.m_pBits[2][i][j];
			img1[1][i][j] = m_Image.m_pBits[1][i][j];
			img1[2][i][j] = m_Image.m_pBits[0][i][j];
		}

	for (int i = 0; i < 3; ++i)
		img2[i] = histogram_equalization(img1[i]);   //��RGB�ֱ���о��⻯

	for (int i = 0; i < h; ++i)                      //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
		{
			m_Image.m_pBits[0][i][j] = img2[2][i][j];
			m_Image.m_pBits[1][i][j] = img2[1][i][j];
			m_Image.m_pBits[2][i][j] = img2[0][i][j];
		}

	Invalidate(1); //ǿ�Ƶ���ONDRAW����	

}

//HSI���⻯
void CImage_ProcessingView::On32872()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/img1.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img2(h, vector<double>(w, 0));
	vector<vector<vector<double>>> img_rgb, img_hsi;         //����vector�洢ͼ���ԭʼRGBֵ��HSIֵ
	img_rgb.resize(3);
	for (int i = 0; i < 3; ++i)
		img_rgb[i].resize(h);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < h; ++j)
			img_rgb[i][j].resize(w);
	img_hsi = img_rgb;
	for (int i = 0; i < h; ++i)              //��ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
		{
			img_rgb[0][i][j] = m_Image.m_pBits[2][i][j];
			img_rgb[1][i][j] = m_Image.m_pBits[1][i][j];
			img_rgb[2][i][j] = m_Image.m_pBits[0][i][j];
		}

	rgb2hsi(img_rgb, img_hsi);                   //RGBת��ΪHSI
	img2 = histogram_equalization(img_hsi[2]);   //��I���⻯
	img_hsi[2] = img2;           
	hsi2rgb(img_hsi, img_rgb);                   //HSIת��ΪRGB

	for (int i = 0; i < 3; ++i)                  //RGB��ÿ��������һ����0-255
		normalize(img_rgb[i], 0, 255);         

	for (int i = 0; i < h; ++i)                  //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
		{
			m_Image.m_pBits[0][i][j] = img_rgb[2][i][j];
			m_Image.m_pBits[1][i][j] = img_rgb[1][i][j];
			m_Image.m_pBits[2][i][j] = img_rgb[0][i][j];
		}

	Invalidate(1); //ǿ�Ƶ���ONDRAW����	

}

//��ɫͼ��ָ�ԭͼ��
void CImage_ProcessingView::On32874()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/img2.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��ע�ο�ɫ������
void CImage_ProcessingView::On32875()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/img2.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	int m1 = 140, m2 = 220;        //����ı߽�
	int n1 = 450, n2 = 500;
	for (int i = m1; i < m2; ++i)  //���߽��
	{
		for (int j = n1; j < n1 + 2; ++j)
		{
			m_Image.m_pBits[0][i][j] = 0;
			m_Image.m_pBits[1][i][j] = 255;
			m_Image.m_pBits[2][i][j] = 0;
		}
		for (int j = n2; j < n2 + 2; ++j)
		{
			m_Image.m_pBits[0][i][j] = 0;
			m_Image.m_pBits[1][i][j] = 255;
			m_Image.m_pBits[2][i][j] = 0;
		}
		
	}
	for (int j = n1; j < n2; ++j)
	{
		for (int i = m1; i < m1 + 2; ++i)
		{
			m_Image.m_pBits[0][i][j] = 0;
			m_Image.m_pBits[1][i][j] = 255;
			m_Image.m_pBits[2][i][j] = 0;
		}
		for (int i = m2; i< m2 + 2; ++i)
		{
			m_Image.m_pBits[0][i][j] = 0;
			m_Image.m_pBits[1][i][j] = 255;
			m_Image.m_pBits[2][i][j] = 0;
		}
	}
	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//�ָ��ֵ����Ľ��
void CImage_ProcessingView::On32876()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex4_imgs/img2.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<vector<double>>> img_rgb;          //����vector�洢ͼ���RGBֵ
	img_rgb.resize(h);
	for (int i = 0; i < h; ++i)
		img_rgb[i].resize(w);
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			img_rgb[i][j].resize(3);
	for (int i = 0; i < h; ++i)              //��ͼ���ֵ��vector����
		for (int j = 0; j < w; ++j)
		{
			img_rgb[i][j][0] = m_Image.m_pBits[2][i][j];
			img_rgb[i][j][1] = m_Image.m_pBits[1][i][j];
			img_rgb[i][j][2] = m_Image.m_pBits[0][i][j];
		}
	int m1 = 140, m2 = 220;          //�ο�ɫ�ʵı߽�
	int n1 = 450, n2 = 500;
	vector<vector<double>> img_sub;  //�洢�ο�ɫ�ʿ����������ֵ
	img_sub.resize(3);
	for (int k = 0; k < 3; ++k)
		for (int i = m1; i <= m2; ++i)
			for (int j = n1; j <= n2; ++j)
				img_sub[k].push_back(img_rgb[i][j][k]);
		
	vector<double> rgb_std_dev(3, 0);
	vector<double> rgb_mean(3, 0);
	
	for (int i = 0; i < 3; ++i)    //���ֵ�ͱ�׼��
	{
		rgb_mean[i] = mean(img_sub[i]);
		rgb_std_dev[i] = std_deviation(img_sub[i]);
	}
	
	double T = 3;                 //�����б���ֵ
	for(auto& z:img_rgb)          //���ݾ�ֵ���������ֵ��ֵ��
		for (auto& x : z)
		{
			vector<bool> a(3, 0);
			for (int i = 0; i < 3; ++i)
				a[i] = (x[i] >= (rgb_mean[i] - T * rgb_std_dev[i]) && x[i] <= (rgb_mean[i] + T * rgb_std_dev[i]));
			if (a[0] && a[1] && a[2])
			{
				x[0] = x[1] = x[2] = 255;
			}
			else
			{
				x[0] = x[1] = x[2] = 0;
			}
		}
	for (int i = 0; i < h; ++i)                 //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
		{
			m_Image.m_pBits[0][i][j] = img_rgb[i][j][2];
			m_Image.m_pBits[1][i][j] = img_rgb[i][j][1];
			m_Image.m_pBits[2][i][j] = img_rgb[i][j][0];
		}

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//												�������ҵ
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//��ʾ���ڷָ��ԭͼ��
void CImage_ProcessingView::On32877()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex5_imgs/img1.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//������ֵ�ָ�
void CImage_ProcessingView::On32878()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex5_imgs/img1.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<double>> img_raw;          //����vector�洢ͼ���RGBֵ
	img_raw.resize(h);
	for (int i = 0; i < h; ++i)
		img_raw[i].resize(w);
	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = (m_Image.m_pBits[2][i][j] + m_Image.m_pBits[1][i][j] + m_Image.m_pBits[0][i][j]) / 3;

	normalize(img_raw, 0, 1);
	int delta = 0.01;
	base_segmentation(img_raw, delta);     //���û�����ֵ�ָ�
	normalize(img_raw, 0, 255);

	for (int i = 0; i < h; ++i)                 //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
		{
			m_Image.m_pBits[0][i][j] = img_raw[i][j];
			m_Image.m_pBits[1][i][j] = img_raw[i][j];
			m_Image.m_pBits[2][i][j] = img_raw[i][j];
		}

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��󷽲�ָ�
void CImage_ProcessingView::On32879()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./ex5_imgs/img1.jpg";   //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	vector<vector<int>> img_raw;          //����vector�洢ͼ���RGBֵ
	img_raw.resize(h);
	for (int i = 0; i < h; ++i)
		img_raw[i].resize(w);
	for (int i = 0; i < h; ++i)      //ת��Ϊ�Ҷ�ͼ
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = (m_Image.m_pBits[2][i][j] + m_Image.m_pBits[1][i][j] + m_Image.m_pBits[0][i][j]) / 3;

	otsu_segmentation(img_raw);            //��󷽲�ָ�

	for (int i = 0; i < h; ++i)                 //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
		{
			m_Image.m_pBits[0][i][j] = img_raw[i][j];
			m_Image.m_pBits[1][i][j] = img_raw[i][j];
			m_Image.m_pBits[2][i][j] = img_raw[i][j];
		}

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}
