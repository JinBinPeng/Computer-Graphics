// transform_newDoc.cpp : implementation of the CTransform_newDoc class
//

#include "stdafx.h"
#include "transform_new.h"

#include "transform_newDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransform_newDoc

IMPLEMENT_DYNCREATE(CTransform_newDoc, CDocument)

BEGIN_MESSAGE_MAP(CTransform_newDoc, CDocument)
	//{{AFX_MSG_MAP(CTransform_newDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransform_newDoc construction/destruction

CTransform_newDoc::CTransform_newDoc()
{
	// TODO: add one-time construction code here

}

CTransform_newDoc::~CTransform_newDoc()
{
}

BOOL CTransform_newDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTransform_newDoc serialization

void CTransform_newDoc::Serialize(CArchive& ar)
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
// CTransform_newDoc diagnostics

#ifdef _DEBUG
void CTransform_newDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTransform_newDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTransform_newDoc commands
