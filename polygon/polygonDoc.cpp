// polygonDoc.cpp : implementation of the CPolygonDoc class
//

#include "stdafx.h"
#include "polygon.h"

#include "polygonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPolygonDoc

IMPLEMENT_DYNCREATE(CPolygonDoc, CDocument)

BEGIN_MESSAGE_MAP(CPolygonDoc, CDocument)
	//{{AFX_MSG_MAP(CPolygonDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPolygonDoc construction/destruction

CPolygonDoc::CPolygonDoc()
{
	// TODO: add one-time construction code here

}

CPolygonDoc::~CPolygonDoc()
{
}

BOOL CPolygonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPolygonDoc serialization

void CPolygonDoc::Serialize(CArchive& ar)
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
// CPolygonDoc diagnostics

#ifdef _DEBUG
void CPolygonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPolygonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPolygonDoc commands
