#include "StdAfx.h"
#include "MyImage_.h"


MyImage_::MyImage_(void)
{
	m_pBits=NULL;
}


MyImage_::~MyImage_(void)
{

	if ( m_pBits!=NULL)
	{
		int h=m_CImage.GetHeight();
		for   (int   i=0;   i<2;   i++)   
		{          
			for   (int   j=0;   j<h;   j++)         
			{   

				delete[] m_pBits[i][j];   
				m_pBits[i][j]=NULL;
			}
		}
		for (int   i=0;   i<2;   i++)
		{
			delete[] m_pBits[i];  
			m_pBits[i]=NULL;
		}
		delete[]  m_pBits;
		m_pBits=NULL;
	}
}

HRESULT MyImage_::Load(_In_z_ LPCTSTR pszFileName) 
{
	m_CImage.Load(pszFileName);
	if(m_CImage.IsNull()) return 0;
	int w=m_CImage.GetWidth();
	int h=m_CImage.GetHeight();
	int nrow=m_CImage.GetPitch();//获得m_CImage每一行像素的RGB所占用的存储空间的大小
	BYTE *psrc=(BYTE *)m_CImage.GetBits();//获得m_CImage最后一行的像素地址
	/*创建三维数组并将m_CImage复制进三维数组*/
	m_pBits= (BYTE***)new   BYTE**[3];   
	for(int i=0;i<3;i++)  
	{ 
		m_pBits[i] = (BYTE**)new  BYTE*[h];   
	}   
	for   (int   i=0;   i<3;   i++)   
	{          
		for   (int   j=0;   j<h;   j++)         
		{   

			m_pBits[i][j]=new BYTE[w];   
		}
	}

	/*将m_CImage复制进三维数组*/

	for (int j=0;j<h;j++)
	{
		for (int k=0;k<w;k++)
		{
			m_pBits[0][j][k]=psrc[j*nrow+k*3];//B
			m_pBits[1][j][k]=psrc[j*nrow+k*3+1];//G
			m_pBits[2][j][k]=psrc[j*nrow+k*3+2];//R
		}
	}

	/*创建三维数组并将m_CImage复制进三维数组*/
	return( S_OK );//为了与CImge类的Load函数返回值相同
}
// HRESULT MyImage_::Load(_In_z_ LPCTSTR pszFileName) 
//{
//	m_CImage.Load(pszFileName);
//
//}

BOOL  MyImage_::Draw(
	_In_ HDC hDestDC,
	_In_ int xDest,
	_In_ int yDest,
	_In_ int nDestWidth,
	_In_ int nDestHeight) const 
{
	if(m_CImage.IsNull()) return 0;
	int w=m_CImage.GetWidth();
	int h=m_CImage.GetHeight();
	int nrow=m_CImage.GetPitch();//获得m_CImage每一行像素的RGB所占用的存储空间的大小
	BYTE *psrc=(BYTE *)m_CImage.GetBits();//获得m_CImage最后一行的像素地址
	/*将三维数组复制进m_CImage*/
	for (int j=0;j<h;j++)
	{
		for (int k=0;k<w;k++)
		{
			psrc[j*nrow+k*3]=m_pBits[0][j][k];//B
			psrc[j*nrow+k*3+1]=m_pBits[1][j][k];//G
			psrc[j*nrow+k*3+2]=m_pBits[2][j][k];//R

		}
	}
	/*将三维数组复制进m_CImage*/

	return m_CImage.Draw(hDestDC,xDest, yDest,nDestWidth, nDestHeight);//调用CImage的Draw;
}
bool MyImage_::IsNull() const 
{
	return m_CImage.IsNull();
}

void MyImage_::Destroy() 
{
	m_CImage.Destroy();
}

int MyImage_::GetWidth() const 
{
	return m_CImage.GetWidth();
}
int MyImage_::GetHeight() const
{
	return m_CImage.GetHeight();
}


BOOL  MyImage_::Draw(
	_In_ HDC hDestDC,
	_In_ int xDest,
	_In_ int yDest) const
{
	if(m_CImage.IsNull()) return 0;
	int w=m_CImage.GetWidth();
	int h=m_CImage.GetHeight();
	int nrow=m_CImage.GetPitch();//获得m_CImage每一行像素的RGB所占用的存储空间的大小
	BYTE *psrc=(BYTE *)m_CImage.GetBits();//获得m_CImage最后一行的像素地址
	/*将三维数组复制进m_CImage*/

	for (int j=0;j<h;j++)
	{
		for (int k=0;k<w;k++)
		{
			psrc[j*nrow+k*3]=m_pBits[0][j][k];//B
			psrc[j*nrow+k*3+1]=m_pBits[1][j][k];//G
			psrc[j*nrow+k*3+2]=m_pBits[2][j][k];//R

		}
	}
	/*将三维数组复制进m_CImage*/
	return m_CImage.Draw(hDestDC,xDest,yDest);
}

HRESULT MyImage_::Save(
	_In_z_ LPCTSTR pszFileName,
	_In_ REFGUID guidFileType) const
{
	if(m_CImage.IsNull()) return 0;
	int w=m_CImage.GetWidth();
	int h=m_CImage.GetHeight();
	int nrow=m_CImage.GetPitch();//获得m_CImage每一行像素的RGB所占用的存储空间的大小
	BYTE *psrc=(BYTE *)m_CImage.GetBits();//获得m_CImage最后一行的像素地址
	for (int j=0;j<h;j++)
	{
	
		for (int k=0;k<w;k++)
		{
			psrc[j*nrow+k*3]=m_pBits[0][j][k];//B
			psrc[j*nrow+k*3+1]=m_pBits[1][j][k];//G
			psrc[j*nrow+k*3+2]=m_pBits[2][j][k];//R

		}
	}
	return m_CImage.Save(pszFileName,guidFileType);

}