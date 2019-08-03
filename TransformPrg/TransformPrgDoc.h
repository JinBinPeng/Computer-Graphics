// TransformPrgDoc.h : interface of the CTransformPrgDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSFORMPRGDOC_H__711FAF34_2B3A_4995_932B_F319F0C019B9__INCLUDED_)
#define AFX_TRANSFORMPRGDOC_H__711FAF34_2B3A_4995_932B_F319F0C019B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTransformPrgDoc : public CDocument
{
protected: // create from serialization only
	CTransformPrgDoc();
	DECLARE_DYNCREATE(CTransformPrgDoc)

// Attributes
public:
   int m_degree;
   double m_translateX;
   double m_translateY;
   double m_rotate;
   double m_scale;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransformPrgDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTransformPrgDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTransformPrgDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFORMPRGDOC_H__711FAF34_2B3A_4995_932B_F319F0C019B9__INCLUDED_)
