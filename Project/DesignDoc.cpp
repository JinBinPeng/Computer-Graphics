// DesignDoc.cpp : implementation of the CDesignDoc class
//

#include "stdafx.h"
#include "Design.h"

#include "DesignDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDesignDoc

IMPLEMENT_DYNCREATE(CDesignDoc, CDocument)

BEGIN_MESSAGE_MAP(CDesignDoc, CDocument)
	//{{AFX_MSG_MAP(CDesignDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDesignDoc construction/destruction

CDesignDoc::CDesignDoc()
{
	// TODO: add one-time construction code here

}

CDesignDoc::~CDesignDoc()
{
}

BOOL CDesignDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDesignDoc serialization

void CDesignDoc::Serialize(CArchive& ar)
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
// CDesignDoc diagnostics

#ifdef _DEBUG
void CDesignDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDesignDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDesignDoc commands
