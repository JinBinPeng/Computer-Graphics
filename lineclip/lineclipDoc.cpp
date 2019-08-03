// lineclipDoc.cpp : implementation of the CLineclipDoc class
//

#include "stdafx.h"
#include "lineclip.h"

#include "lineclipDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLineclipDoc

IMPLEMENT_DYNCREATE(CLineclipDoc, CDocument)

BEGIN_MESSAGE_MAP(CLineclipDoc, CDocument)
	//{{AFX_MSG_MAP(CLineclipDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineclipDoc construction/destruction

CLineclipDoc::CLineclipDoc()
{
	// TODO: add one-time construction code here

}

CLineclipDoc::~CLineclipDoc()
{
}

BOOL CLineclipDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLineclipDoc serialization

void CLineclipDoc::Serialize(CArchive& ar)
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
// CLineclipDoc diagnostics

#ifdef _DEBUG
void CLineclipDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLineclipDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLineclipDoc commands
