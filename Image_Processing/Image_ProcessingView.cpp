
// Image_ProcessingView.cpp : CImage_ProcessingView 类的实现
//
#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CImage_ProcessingView 构造/析构

CImage_ProcessingView::CImage_ProcessingView()
{
	// TODO: 在此处添加构造代码

}

CImage_ProcessingView::~CImage_ProcessingView()
{
}

BOOL CImage_ProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CImage_ProcessingView 绘制

void CImage_ProcessingView::OnDraw(CDC* pDC)
{
	CImage_ProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CImage_ProcessingView 打印


void CImage_ProcessingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImage_ProcessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CImage_ProcessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CImage_ProcessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CImage_ProcessingView 诊断

#ifdef _DEBUG
void CImage_ProcessingView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImage_ProcessingView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImage_ProcessingDoc* CImage_ProcessingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImage_ProcessingDoc)));
	return (CImage_ProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CImage_ProcessingView 消息处理程序


void CImage_ProcessingView::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE);    //为打开文件创建一个变量
	if(IDOK == dlg.DoModal())    //调用函数打开一个对话框，并判断是否打开成功
	{
		if(!m_Image.IsNull()) m_Image.Destroy();//判断是否已经有图片，有的话进行清除
		m_Image.Load(dlg.GetPathName());//获得图片的地址，并且加载图片

		//获得图片的大小，并按其大小设置滚动条的初始窗口大小等参数
		CSize sizeTotal;
		int w=m_Image.GetWidth();
		int h=m_Image.GetHeight();
		sizeTotal.cx =w;
		sizeTotal.cy =h;
		SetScrollSizes(MM_TEXT, sizeTotal);

		//Window_Image_w=m_Image.GetWidth();//获得图片的初始大小，为放大缩小功能做准备
		//Window_Image_h=m_Image.GetHeight();//


		Invalidate(1); //强制调用ONDRAW函数
	}
}


void CImage_ProcessingView::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码
	if (m_Image.IsNull()) {
		MessageBox(_T("你还没有打开一个要保存的图像文件！"));
		return;
	}
	CString strFilter;
	//strFilter ="位图文件|*.bmp|JPEG 图像文件|*.jpg|GIF 图像文件|*.gif|PNG 图像文件|*.png||";   //
	strFilter ="所有文件|*.*||";   //

	CFileDialog dlg(FALSE,NULL,NULL,NULL,strFilter);
	//CFileDialog dlg(FALSE,NULL,NULL,NULL);

	if ( IDOK != dlg.DoModal()) 
		return;
	// 如果用户没有指定文件扩展名，则为其添加一个
	CString strFileName;
	//CString strExtension;
	strFileName = dlg.m_ofn.lpstrFile;   //  获得文件名
	//if(dlg.m_ofn.nFileExtension == 0)     //获得文件扩展名
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
	// 图像保存
	HRESULT hResult = m_Image.Save(strFileName);
	if (FAILED(hResult))
	{
		MessageBox(_T("保存图像文件失败！"));
	}

}



//void CImage_ProcessingView::OnViewToolbar()
//{
//	// TODO: 在此添加命令处理程序代码
//}




/////////////////////////////////////////////////////////////////////////////////////////////////
//                                   下面是我我做的作业                                        //
//                                                                                             //(图像 0:B 1:G 2:R)
//                    *注 核心的函数代码储存在 yyj.h 和 yyj.c 文件中                           //
/////////////////////////////////////////////////////////////////////////////////////////////////

//第一次作业
//1. 降低图像空间分辨率1/2
void CImage_ProcessingView::On32792()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));    //定义存储图像的容器

	for (int i = 0; i < h; ++i)         //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;
	 
	reduce_spatial_resolution(img, 2);  //降低分辨率

	for (int i = 0; i < h; ++i)         //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数绘制图像
}


//降低图像空间分辨率1/4
void CImage_ProcessingView::On32793()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_spatial_resolution(img, 4); //降低分辨率降

	for (int i = 0; i < h; ++i)        //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)   
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数绘制图像
}

//降低图像空间分辨率1/8
void CImage_ProcessingView::On32794()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_spatial_resolution(img, 8);//降低分辨率降

	for (int i = 0; i < h; ++i)       //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数绘制图像
}


//降低图像空间分辨率1/16
void CImage_ProcessingView::On32795()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)       //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_spatial_resolution(img, 16); //降低分辨率

	for (int i = 0; i < h; ++i)        //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数绘制图像
}


//降低图像灰度分辨率1/2 128级
void CImage_ProcessingView::On32785()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 2);  //降低分辨率

	for (int i = 0; i < h; ++i)           //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数绘制图像
}

//降低图像灰度分辨率1/4 64级
void CImage_ProcessingView::On32786()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 4);  //降低分辨率

	for (int i = 0; i < h; ++i)           //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数绘制图像
}

//降低图像灰度分辨率1/8 32级
void CImage_ProcessingView::On32787()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 8);   //降低分辨率

	for (int i = 0; i < h; ++i)            //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数绘制图像
}

//降低图像灰度分辨率1/16 16级
void CImage_ProcessingView::On32788()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 16);   //降低分辨率

	for (int i = 0; i < h; ++i)             //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数绘制图像
}

//降低图像灰度分辨率1/32 8级
void CImage_ProcessingView::On32789()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 32);    //降低分辨率

	for (int i = 0; i < h; ++i)              //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数绘制图像
}

//降低图像灰度分辨率1/64 4级
void CImage_ProcessingView::On32790()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 64);   //降低分辨率

	for (int i = 0; i < h; ++i)             //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数绘制图像
}

//降低图像灰度分辨率1/128 2级
void CImage_ProcessingView::On32791()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	reduce_grayscale_resolution(img, 128);    //降低分辨率

	for (int i = 0; i < h; ++i)              //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数绘制图像
}


//相加去噪噪声图像1显示
void CImage_ProcessingView::On32797()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //判断是否已经有图片，有的话进行清除
	std::string file_path = "./ex1_imgs/zao1.jpg";   //指定图像文件路径
	m_Image.Load(file_path.c_str());                 //读取磁盘中的图像
	
    Invalidate(1); //强制调用ONDRAW函数

}

//相加去噪噪声图像2显示
void CImage_ProcessingView::On32798()
{
	if (!m_Image.IsNull()) m_Image.Destroy();       //判断是否已经有图片，有的话进行清除
	std::string file_path = "./ex1_imgs/zao2.jpg";  //指定图像文件路径
	m_Image.Load(file_path.c_str());                //读取磁盘中的图像
	
	Invalidate(1); //强制调用ONDRAW函数
}

//相加去噪噪声图像3
void CImage_ProcessingView::On32799()
{
	if (!m_Image.IsNull()) m_Image.Destroy();       //判断是否已经有图片，有的话进行清除
	std::string file_path = "./ex1_imgs/zao3.jpg";  //指定图像文件路径
	m_Image.Load(file_path.c_str());                //读取磁盘中的图像

	Invalidate(1); //强制调用ONDRAW函数
}

//相加去噪噪声图像4
void CImage_ProcessingView::On32800()
{
	if (!m_Image.IsNull()) m_Image.Destroy();       //判断是否已经有图片，有的话进行清除
	std::string file_path = "./ex1_imgs/zao4.jpg";  //指定图像文件路径
	m_Image.Load(file_path.c_str());                //读取磁盘中的图像

	Invalidate(1); //强制调用ONDRAW函数
}

//相加去噪噪声图像5
void CImage_ProcessingView::On32801()
{
	if (!m_Image.IsNull()) m_Image.Destroy();       //判断是否已经有图片，有的话进行清除
	std::string file_path = "./ex1_imgs/zao5.jpg";  //指定图像文件路径
	m_Image.Load(file_path.c_str());                //读取磁盘中的图像

	Invalidate(1); //强制调用ONDRAW函数

}

//相加去噪效果图
void CImage_ProcessingView::On32802()
{
	int img_num = 5;    //图像张数
	int w = 0;          //图像宽度
	int h = 0;          //图像高度
	vector<vector<vector<double>>> imgs;   //定义存储所有图像容器
	
	int flag = 0;                          //标志变量
	for (int v = 0; v < img_num; ++v)
	{
		++flag;
		if (!m_Image.IsNull()) m_Image.Destroy();                 //判断是否已经有图片，有的话进行清除
		std::string file_path = "./ex1_imgs/zao";                 //指定图像文件路径头
		file_path = file_path + std::to_string(v+1) + "\.jpg";    //指定图像完整文件路径
		m_Image.Load(file_path.c_str());
		w = m_Image.GetWidth();       //获得图像宽度
	    h = m_Image.GetHeight();      //获得图像高度
		if (flag == 1)
		{
			imgs.resize(img_num);                //初始化容器大小
			for (int k = 0; k < img_num; ++k)
			{
				imgs[k].resize(h);
				for (int i = 0; i < h; ++i)
					imgs[k][i].resize(w);
			}
		}
		for (int i = 0; i < h; ++i)      //转换为灰度图
			for (int j = 0; j < w; ++j)
				imgs[v][i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;
	}
	
	superimposed_denoising(imgs);       //叠加去噪

	for (int i = 0; i < h; ++i)         //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = imgs[0][i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//差分增强的模板图像显示
void CImage_ProcessingView::On32803()
{
	if (!m_Image.IsNull()) m_Image.Destroy();       //判断是否已经有图片，有的话进行清除
	std::string file_path = "./ex1_imgs/cha1.jpg";  //图像文件路径
	m_Image.Load(file_path.c_str());                //读取图像

	Invalidate(1); //强制调用ONDRAW函数
}

//需要增强的图像显示
void CImage_ProcessingView::On32804()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //判断是否已经有图片，有的话进行清除
	std::string file_path = "./ex1_imgs/cha2.jpg";   //图像文件路径
	m_Image.Load(file_path.c_str());                 //读取图像

	Invalidate(1); //强制调用ONDRAW函数
}


//差分增强后的效果
void CImage_ProcessingView::On32805()
{
	if (!m_Image.IsNull()) m_Image.Destroy();         //判断是否已经有图片，有的话进行清除
	std::string file_path = "./ex1_imgs/cha1.jpg";    //模板图像路径
	m_Image.Load(file_path.c_str());                  //读取模板图像
	const int w = m_Image.GetWidth();      //获得图像宽度
	const int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img1(h, vector<double>(w, 0)), img2(h, vector<double>(w, 0));  //定义存储图像的容器

	for (int i = 0; i < h; ++i)              //将模板图像存入容器
		for (int j = 0; j < w; ++j)
			img1[i][j] = m_Image.m_pBits[0][i][j];

	if (!m_Image.IsNull()) m_Image.Destroy();     //判断是否已经有图片，有的话进行清除
	file_path = "./ex1_imgs/cha2.jpg";            //需要增强的图像路径
	m_Image.Load(file_path.c_str());              //读取需要增强的图像
	for (int i = 0; i < h; ++i)                   //将需要增强的图像存入容器
		for (int j = 0; j < w; ++j)
			img2[i][j] = m_Image.m_pBits[0][i][j];

	differential_enhancement(img1, img2);         //差分增强

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img1[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//第二次作业
//显示直方图
vector<double> Pz(256, 0);
void CImage_ProcessingView::On32814()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<int>> img(h, vector<int>(w, 0));
	vector<vector<int>> hstgm(h, vector<int>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	Pz = histogram_display(img, hstgm);    //显示直方图

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//直方图均衡化
vector<vector<int>> img_jun, img_jun_2;          //全局变量，存储原图像，均衡化后的图像

//显示原图像直方图
void CImage_ProcessingView::On32816()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	img_jun.resize(h);
	for (auto& c : img_jun)
		c.resize(w);
	vector<vector<int>> hstgm(h, vector<int>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img_jun[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	histogram_display(img_jun, hstgm);    //显示直方图

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//均衡化后的直方图
void CImage_ProcessingView::On32817()
{
	img_jun_2 = histogram_equalization(img_jun); //均衡化直方图

	int h = img_jun_2.size();        //获得图像宽度
	int w = img_jun_2[0].size();     //获得图像高度
	vector<vector<int>> hstgm(h, vector<int>(w, 0));

	histogram_display(img_jun_2, hstgm);    //显示直方图
	
	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//均衡化后的图像显示
void CImage_ProcessingView::On32818()
{
	int h = img_jun_2.size();        //获得图像宽度
	int w = img_jun_2[0].size();     //获得图像高度

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_jun_2[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}


//直方图规格化
vector<vector<int>> img_gui, img_gui_jun, img_gui_2;        //全局变量:存储原图像，均衡化后的图像，规格化后的图像

//显示原图像直方图
void CImage_ProcessingView::On32820()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	img_gui.resize(h);
	for (auto& c : img_gui)
		c.resize(w);
	img_gui_jun = img_gui_2 = img_gui;
	auto hstgm = img_gui;

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img_gui[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	auto x = histogram_display(img_gui, hstgm);    //显示直方图

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//希望的直方图形式，使用上步均衡化的图像作为参考
void CImage_ProcessingView::On32821()
{
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<int>> hstgm(h, vector<int>(w, 0));

	histogram2(Pz, hstgm);

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//规格化后的直方图
void CImage_ProcessingView::On32822()
{
	int w = img_gui.size();        //获得图像宽度
	int h = img_gui[0].size();     //获得图像高度
	
	auto hstgm = img_gui;
	img_gui_jun = histogram_equalization(img_gui); //均衡化图像
	histogram_specification(img_gui_jun, img_gui_2, Pz);
	auto x = histogram_display(img_gui_2, hstgm);          //显示直方图
	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = hstgm[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//规定化后的图像显示
void CImage_ProcessingView::On32823()
{
	int w = img_gui.size();        //获得图像宽度
	int h = img_gui[0].size();     //获得图像高度

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_gui_2[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//均值滤波
void CImage_ProcessingView::On32806()
{
	; //程序在下面
}


//中值滤波
void CImage_ProcessingView::On32807()
{
	; //程序在下面
}

//3x3均值滤波
void CImage_ProcessingView::On32808()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	mean_filtering(img, 3);

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//5x5均值滤波
void CImage_ProcessingView::On32809()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	mean_filtering(img, 5);

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//9x9均值滤波
void CImage_ProcessingView::On32810()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	mean_filtering(img, 9);

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//15x15均值滤波
void CImage_ProcessingView::On32811()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	mean_filtering(img, 15);

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//3x3中值滤波
void CImage_ProcessingView::On32812()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	median_filtering(img, 3);

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//5x5中值滤波
void CImage_ProcessingView::On32813()
{
	if (m_Image.IsNull()) return;    //判断图像是否为空
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
	vector<vector<double>> img(h, vector<double>(w, 0));

	for (int i = 0; i < h; ++i)      //转换为灰度图
		for (int j = 0; j < w; ++j)
			img[i][j] = m_Image.m_pBits[2][i][j] * 0.299 + m_Image.m_pBits[1][i][j] * 0.587 + m_Image.m_pBits[0][i][j] * 0.114;

	median_filtering(img, 5);

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}


//第三次作业
//显示傅里叶变换原图像
void CImage_ProcessingView::On32825()   
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //判断是否已经有图片，有的话进行清除
	std::string file_path = "./imgs/img1.jpg";       //图像文件路径
	m_Image.Load(file_path.c_str());                 //读取图像

	Invalidate(1); //强制调用ONDRAW函数
}

//原图像的傅立叶变换
void CImage_ProcessingView::On32826()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //判断是否已经有图片，有的话进行清除
	std::string file_path = "./imgs/img1.jpg";       //图像文件路径
	m_Image.Load(file_path.c_str());                 //读取图像
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度

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

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_mag[i][j];

	Invalidate(1); //强制调用ONDRAW函数

}

//平移后的图像
void CImage_ProcessingView::On32827()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //判断是否已经有图片，有的话进行清除
	std::string file_path = "./imgs/img2.jpg";       //图像文件路径
	m_Image.Load(file_path.c_str());                 //读取图像

	Invalidate(1); //强制调用ONDRAW函数
}

//平移后图像的傅立叶变换
void CImage_ProcessingView::On32828()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //判断是否已经有图片，有的话进行清除
	std::string file_path = "./imgs/img2.jpg";       //图像文件路径
	m_Image.Load(file_path.c_str());                 //读取图像
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度

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

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_mag[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//旋转后的图像
void CImage_ProcessingView::On32829()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //判断是否已经有图片，有的话进行清除
	std::string file_path = "./imgs/img3.jpg";       //图像文件路径
	m_Image.Load(file_path.c_str());                 //读取图像

	Invalidate(1); //强制调用ONDRAW函数
}

//旋转后图像的傅立叶变换
void CImage_ProcessingView::On32831()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //判断是否已经有图片，有的话进行清除
	std::string file_path = "./imgs/img3.jpg";       //图像文件路径
	m_Image.Load(file_path.c_str());                 //读取图像
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度

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

	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_mag[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}

//显示用于滤波的原图像
void CImage_ProcessingView::On32833()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //判断是否已经有图片，有的话进行清除
	std::string file_path = "./imgs/img4.jpg";       //图像文件路径
	m_Image.Load(file_path.c_str());                 //读取图像

	Invalidate(1); //强制调用ONDRAW函数
}

//理想低通滤波
void CImage_ProcessingView::On32834()
{
	if (!m_Image.IsNull()) m_Image.Destroy();        //判断是否已经有图片，有的话进行清除
	std::string file_path = "./imgs/img4.jpg";       //图像文件路径
	m_Image.Load(file_path.c_str());                 //读取图像
	int w = m_Image.GetWidth();      //获得图像宽度
	int h = m_Image.GetHeight();     //获得图像高度
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
	for (int i = 0; i < h; ++i)                   //把处理的结果赋值以便显示
		for (int j = 0; j < w; ++j)
			m_Image.m_pBits[0][i][j] = m_Image.m_pBits[1][i][j] = m_Image.m_pBits[2][i][j] = img_raw[i][j];

	Invalidate(1); //强制调用ONDRAW函数
}
