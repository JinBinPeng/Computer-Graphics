// KochDoc.cpp : implementation of the CKochDoc class
//

#include "stdafx.h"
#include "Koch.h"

#include "KochDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKochDoc

IMPLEMENT_DYNCREATE(CKochDoc, CDocument)

BEGIN_MESSAGE_MAP(CKochDoc, CDocument)
	//{{AFX_MSG_MAP(CKochDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKochDoc construction/destruction

CKochDoc::CKochDoc()
{
	// TODO: add one-time construction code here

}

CKochDoc::~CKochDoc()
{
}

BOOL CKochDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CKochDoc serialization

void CKochDoc::Serialize(CArchive& ar)
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
// CKochDoc diagnostics

#ifdef _DEBUG
void CKochDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKochDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKochDoc commands
