// B3CurvesDoc.h : interface of the CB3CurvesDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_B3CURVESDOC_H__51C1ABD0_3E6D_4846_AD20_E4885E1F265C__INCLUDED_)
#define AFX_B3CURVESDOC_H__51C1ABD0_3E6D_4846_AD20_E4885E1F265C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CB3CurvesDoc : public CDocument
{
protected: // create from serialization only
	CB3CurvesDoc();
	DECLARE_DYNCREATE(CB3CurvesDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB3CurvesDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CB3CurvesDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CB3CurvesDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B3CURVESDOC_H__51C1ABD0_3E6D_4846_AD20_E4885E1F265C__INCLUDED_)
