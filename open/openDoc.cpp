// openDoc.cpp : implementation of the COpenDoc class
//

#include "stdafx.h"
#include "open.h"

#include "openDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenDoc

IMPLEMENT_DYNCREATE(COpenDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenDoc, CDocument)
	//{{AFX_MSG_MAP(COpenDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenDoc construction/destruction

COpenDoc::COpenDoc()
{
	// TODO: add one-time construction code here

}

COpenDoc::~COpenDoc()
{
}

BOOL COpenDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COpenDoc serialization

void COpenDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// COpenDoc diagnostics

#ifdef _DEBUG
void COpenDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenDoc commands
