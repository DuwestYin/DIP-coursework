
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

//��һ����ҵ
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

//�ڶ�����ҵ
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


//��������ҵ
//��ʾ����Ҷ�任ԭͼ��
void CImage_ProcessingView::On32825()   
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./imgs/img1.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//ԭͼ��ĸ���Ҷ�任
void CImage_ProcessingView::On32826()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./imgs/img1.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�

	vector<vector<double>> img_raw(h, vector<double>(w, 0));
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);
	move2center(img_raw);
	auto img_mag = img_raw;
	auto img_ang = img_raw;

	fft(img_raw, img_mag, img_ang);
	log_exp(img_mag);
	normalize(img_mag, 0, 255);

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_mag[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����

}

//ƽ�ƺ��ͼ��
void CImage_ProcessingView::On32827()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./imgs/img2.jpg";       //ͼ���ļ�·��
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

	vector<vector<double>> img_raw(h, vector<double>(w, 0));
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);
	move2center(img_raw);
	auto img_mag = img_raw;
	auto img_ang = img_raw;

	fft(img_raw, img_mag, img_ang);
	log_exp(img_mag);
	normalize(img_mag, 0, 255);

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_mag[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��ת���ͼ��
void CImage_ProcessingView::On32829()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./imgs/img3.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��ת��ͼ��ĸ���Ҷ�任
void CImage_ProcessingView::On32831()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./imgs/img3.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�

	vector<vector<double>> img_raw(h, vector<double>(w, 0));
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];

	normalize(img_raw, 0, 1);
	move2center(img_raw);
	auto img_mag = img_raw;
	auto img_ang = img_raw;

	fft(img_raw, img_mag, img_ang);
	log_exp(img_mag);
	normalize(img_mag, 0, 255);

	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_mag[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//��ʾ�����˲���ԭͼ��
void CImage_ProcessingView::On32833()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./imgs/img4.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}

//�����ͨ�˲�
void CImage_ProcessingView::On32834()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //�ж��Ƿ��Ѿ���ͼƬ���еĻ��������
	std::string file_path = "./imgs/img4.jpg";       //ͼ���ļ�·��
	m_Image.Load(file_path.c_str());                 //��ȡͼ��
	int w = m_Image.GetWidth();      //���ͼ����
	int h = m_Image.GetHeight();     //���ͼ��߶�
	int P = 2 * h;
	int Q = 2 * w;
	int D = 20;
	vector<vector<double>> img_raw(h, vector<double>(w, 0));
	vector<vector<double>> img_exp(P, vector<double>(Q, 0));
	vector<vector<double>> img_mag(P, vector<double>(Q, 0));
	vector<vector<double>> img_ang(P, vector<double>(Q, 0));
	vector<vector<double>> H(P, vector<double>(Q, 0));
	vector<vector<double>> G(P, vector<double>(Q, 0));

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = m_Image.m_pBits[0][i][j];
	normalize(img_raw, 0, 1);
	move2center(img_raw);
	img2big(img_raw, img_exp);
	fft(img_exp, img_mag, img_ang);
	make_filter(H, D, 0);
	act_filter(img_mag, H, G);
	invfft(G, img_ang, img_exp);

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			img_raw[i][j] = img_exp[i][j];

	move2center(img_raw);
	normalize(img_raw, 0, 255);
	for (int i = 0; i < h; ++i)                   //�Ѵ���Ľ����ֵ�Ա���ʾ
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_raw[i][j];

	Invalidate(1); //ǿ�Ƶ���ONDRAW����
}
