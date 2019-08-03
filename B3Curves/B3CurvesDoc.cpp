// B3CurvesDoc.cpp : implementation of the CB3CurvesDoc class
//

#include "stdafx.h"
#include "B3Curves.h"

#include "B3CurvesDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CB3CurvesDoc

IMPLEMENT_DYNCREATE(CB3CurvesDoc, CDocument)

BEGIN_MESSAGE_MAP(CB3CurvesDoc, CDocument)
	//{{AFX_MSG_MAP(CB3CurvesDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB3CurvesDoc construction/destruction

CB3CurvesDoc::CB3CurvesDoc()
{
	// TODO: add one-time construction code here

}

CB3CurvesDoc::~CB3CurvesDoc()
{
}

BOOL CB3CurvesDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CB3CurvesDoc serialization

void CB3CurvesDoc::Serialize(CArchive& ar)
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
// CB3CurvesDoc diagnostics

#ifdef _DEBUG
void CB3CurvesDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CB3CurvesDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CB3CurvesDoc commands
