// BresenhamDoc.cpp : implementation of the CBresenhamDoc class
//

#include "stdafx.h"
#include "Bresenham.h"

#include "BresenhamDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBresenhamDoc

IMPLEMENT_DYNCREATE(CBresenhamDoc, CDocument)

BEGIN_MESSAGE_MAP(CBresenhamDoc, CDocument)
	//{{AFX_MSG_MAP(CBresenhamDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBresenhamDoc construction/destruction

CBresenhamDoc::CBresenhamDoc()
{
	// TODO: add one-time construction code here

}

CBresenhamDoc::~CBresenhamDoc()
{
}

BOOL CBresenhamDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBresenhamDoc serialization

void CBresenhamDoc::Serialize(CArchive& ar)
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
// CBresenhamDoc diagnostics

#ifdef _DEBUG
void CBresenhamDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBresenhamDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBresenhamDoc commands
