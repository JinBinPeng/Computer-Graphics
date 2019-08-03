// BezierCurveDoc.h : interface of the CBezierCurveDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BEZIERCURVEDOC_H__581BDF3F_643C_4F8B_8D05_2649A77D1AF2__INCLUDED_)
#define AFX_BEZIERCURVEDOC_H__581BDF3F_643C_4F8B_8D05_2649A77D1AF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBezierCurveDoc : public CDocument
{
protected: // create from serialization only
	CBezierCurveDoc();
	DECLARE_DYNCREATE(CBezierCurveDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBezierCurveDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBezierCurveDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBezierCurveDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BEZIERCURVEDOC_H__581BDF3F_643C_4F8B_8D05_2649A77D1AF2__INCLUDED_)
