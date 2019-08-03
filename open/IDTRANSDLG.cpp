// IDTRANSDLG.cpp : implementation file
//

#include "stdafx.h"
#include "open.h"
#include "IDTRANSDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// IDTRANSDLG dialog


IDTRANSDLG::IDTRANSDLG(CWnd* pParent /*=NULL*/)
	: CDialog(IDTRANSDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(IDTRANSDLG)
	m_tx = 0.0f;
	m_ty = 0.0f;
	m_tz = 0.0f;
	//}}AFX_DATA_INIT
}


void IDTRANSDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(IDTRANSDLG)
	DDX_Text(pDX, IDC_EDIT1, m_tx);
	DDX_Text(pDX, IDC_EDIT2, m_ty);
	DDX_Text(pDX, IDC_EDIT3, m_tz);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(IDTRANSDLG, CDialog)
	//{{AFX_MSG_MAP(IDTRANSDLG)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// IDTRANSDLG message handlers
