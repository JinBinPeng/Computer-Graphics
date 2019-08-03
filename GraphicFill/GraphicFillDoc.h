// GraphicFillDoc.h : interface of the CGraphicFillDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHICFILLDOC_H__E6BB82C9_F6F8_4286_9945_DCC5CB6A7441__INCLUDED_)
#define AFX_GRAPHICFILLDOC_H__E6BB82C9_F6F8_4286_9945_DCC5CB6A7441__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGraphicFillDoc : public CDocument
{
protected: // create from serialization only
	CGraphicFillDoc();
	DECLARE_DYNCREATE(CGraphicFillDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphicFillDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGraphicFillDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraphicFillDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHICFILLDOC_H__E6BB82C9_F6F8_4286_9945_DCC5CB6A7441__INCLUDED_)
