// GraphicFillDoc.cpp : implementation of the CGraphicFillDoc class
//

#include "stdafx.h"
#include "GraphicFill.h"

#include "GraphicFillDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraphicFillDoc

IMPLEMENT_DYNCREATE(CGraphicFillDoc, CDocument)

BEGIN_MESSAGE_MAP(CGraphicFillDoc, CDocument)
	//{{AFX_MSG_MAP(CGraphicFillDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphicFillDoc construction/destruction

CGraphicFillDoc::CGraphicFillDoc()
{
	// TODO: add one-time construction code here

}

CGraphicFillDoc::~CGraphicFillDoc()
{
}

BOOL CGraphicFillDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGraphicFillDoc serialization

void CGraphicFillDoc::Serialize(CArchive& ar)
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
// CGraphicFillDoc diagnostics

#ifdef _DEBUG
void CGraphicFillDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGraphicFillDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraphicFillDoc commands
