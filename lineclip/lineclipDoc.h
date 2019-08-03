// lineclipDoc.h : interface of the CLineclipDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINECLIPDOC_H__548A65EC_27EB_4E47_893A_73EE20D80607__INCLUDED_)
#define AFX_LINECLIPDOC_H__548A65EC_27EB_4E47_893A_73EE20D80607__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLineclipDoc : public CDocument
{
protected: // create from serialization only
	CLineclipDoc();
	DECLARE_DYNCREATE(CLineclipDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineclipDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLineclipDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLineclipDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINECLIPDOC_H__548A65EC_27EB_4E47_893A_73EE20D80607__INCLUDED_)
