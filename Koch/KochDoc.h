// KochDoc.h : interface of the CKochDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KOCHDOC_H__2FD59138_05BB_41F8_9432_8B8F284D7783__INCLUDED_)
#define AFX_KOCHDOC_H__2FD59138_05BB_41F8_9432_8B8F284D7783__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKochDoc : public CDocument
{
protected: // create from serialization only
	CKochDoc();
	DECLARE_DYNCREATE(CKochDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKochDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKochDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKochDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KOCHDOC_H__2FD59138_05BB_41F8_9432_8B8F284D7783__INCLUDED_)
