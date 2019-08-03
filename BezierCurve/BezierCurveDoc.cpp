// BezierCurveDoc.cpp : implementation of the CBezierCurveDoc class
//

#include "stdafx.h"
#include "BezierCurve.h"

#include "BezierCurveDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBezierCurveDoc

IMPLEMENT_DYNCREATE(CBezierCurveDoc, CDocument)

BEGIN_MESSAGE_MAP(CBezierCurveDoc, CDocument)
	//{{AFX_MSG_MAP(CBezierCurveDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBezierCurveDoc construction/destruction

CBezierCurveDoc::CBezierCurveDoc()
{
	// TODO: add one-time construction code here

}

CBezierCurveDoc::~CBezierCurveDoc()
{
}

BOOL CBezierCurveDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBezierCurveDoc serialization

void CBezierCurveDoc::Serialize(CArchive& ar)
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
// CBezierCurveDoc diagnostics

#ifdef _DEBUG
void CBezierCurveDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBezierCurveDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBezierCurveDoc commands
