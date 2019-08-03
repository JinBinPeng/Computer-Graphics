// DesignDoc.h : interface of the CDesignDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESIGNDOC_H__F87859AC_71D5_4B46_82FB_B4D82AECB08E__INCLUDED_)
#define AFX_DESIGNDOC_H__F87859AC_71D5_4B46_82FB_B4D82AECB08E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDesignDoc : public CDocument
{
protected: // create from serialization only
	CDesignDoc();
	DECLARE_DYNCREATE(CDesignDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesignDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDesignDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDesignDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESIGNDOC_H__F87859AC_71D5_4B46_82FB_B4D82AECB08E__INCLUDED_)
