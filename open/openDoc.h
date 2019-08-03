// openDoc.h : interface of the COpenDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENDOC_H__10C820D6_D693_4EFF_9D6F_6190E9071FF5__INCLUDED_)
#define AFX_OPENDOC_H__10C820D6_D693_4EFF_9D6F_6190E9071FF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COpenDoc : public CDocument
{
protected: // create from serialization only
	COpenDoc();
	DECLARE_DYNCREATE(COpenDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COpenDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpenDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENDOC_H__10C820D6_D693_4EFF_9D6F_6190E9071FF5__INCLUDED_)
