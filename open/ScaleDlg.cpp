// ScaleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "open.h"
#include "ScaleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScaleDlg dialog


CScaleDlg::CScaleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScaleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScaleDlg)
	m_sx = 0.0f;
	m_sy = 0.0f;
	m_sz = 0.0f;
	//}}AFX_DATA_INIT
}


void CScaleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScaleDlg)
	DDX_Text(pDX, IDC_EDIT1, m_sx);
	DDX_Text(pDX, IDC_EDIT2, m_sy);
	DDX_Text(pDX, IDC_EDIT3, m_sz);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScaleDlg, CDialog)
	//{{AFX_MSG_MAP(CScaleDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScaleDlg message handlers
