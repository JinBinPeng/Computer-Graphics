// RotateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "open.h"
#include "RotateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRotateDlg dialog


CRotateDlg::CRotateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRotateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRotateDlg)
	m_angle = 0.0f;
	m_rx = 0.0f;
	m_ry = 0.0f;
	m_rz = 0.0f;
	//}}AFX_DATA_INIT
}


void CRotateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRotateDlg)
	DDX_Text(pDX, IDC_EDIT1, m_angle);
	DDX_Text(pDX, IDC_EDIT2, m_rx);
	DDX_Text(pDX, IDC_EDIT3, m_ry);
	DDX_Text(pDX, IDC_EDIT4, m_rz);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRotateDlg, CDialog)
	//{{AFX_MSG_MAP(CRotateDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotateDlg message handlers
