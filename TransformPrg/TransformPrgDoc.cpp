// TransformPrgDoc.cpp : implementation of the CTransformPrgDoc class
//

#include "stdafx.h"
#include "TransformPrg.h"

#include "TransformPrgDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransformPrgDoc

IMPLEMENT_DYNCREATE(CTransformPrgDoc, CDocument)

BEGIN_MESSAGE_MAP(CTransformPrgDoc, CDocument)
	//{{AFX_MSG_MAP(CTransformPrgDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransformPrgDoc construction/destruction

CTransformPrgDoc::CTransformPrgDoc()
{
	// TODO: add one-time construction code here
   m_degree=8;
   m_translateX=6;
   m_translateY=2;
   m_rotate=5;
   m_scale=1;


}

CTransformPrgDoc::~CTransformPrgDoc()
{
}

BOOL CTransformPrgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTransformPrgDoc serialization

void CTransformPrgDoc::Serialize(CArchive& ar)
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
// CTransformPrgDoc diagnostics

#ifdef _DEBUG
void CTransformPrgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTransformPrgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTransformPrgDoc commands
