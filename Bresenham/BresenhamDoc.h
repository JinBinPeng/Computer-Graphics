// BresenhamDoc.h : interface of the CBresenhamDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRESENHAMDOC_H__09EBFA5F_4D2D_4462_AEB3_8C5663DB49D8__INCLUDED_)
#define AFX_BRESENHAMDOC_H__09EBFA5F_4D2D_4462_AEB3_8C5663DB49D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBresenhamDoc : public CDocument
{
protected: // create from serialization only
	CBresenhamDoc();
	DECLARE_DYNCREATE(CBresenhamDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBresenhamDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBresenhamDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBresenhamDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRESENHAMDOC_H__09EBFA5F_4D2D_4462_AEB3_8C5663DB49D8__INCLUDED_)
