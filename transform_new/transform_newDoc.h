// transform_newDoc.h : interface of the CTransform_newDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSFORM_NEWDOC_H__6845E099_5F21_4DD6_885D_733556C5F5A4__INCLUDED_)
#define AFX_TRANSFORM_NEWDOC_H__6845E099_5F21_4DD6_885D_733556C5F5A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTransform_newDoc : public CDocument
{
protected: // create from serialization only
	CTransform_newDoc();
	DECLARE_DYNCREATE(CTransform_newDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransform_newDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTransform_newDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTransform_newDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFORM_NEWDOC_H__6845E099_5F21_4DD6_885D_733556C5F5A4__INCLUDED_)
