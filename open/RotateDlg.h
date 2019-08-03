#if !defined(AFX_ROTATEDLG_H__2A49A500_BFD4_4688_89C2_E75BAD522655__INCLUDED_)
#define AFX_ROTATEDLG_H__2A49A500_BFD4_4688_89C2_E75BAD522655__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RotateDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRotateDlg dialog

class CRotateDlg : public CDialog
{
// Construction
public:
	CRotateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRotateDlg)
	enum { IDD = IDD_DIALOG3 };
	float	m_angle;
	float	m_rx;
	float	m_ry;
	float	m_rz;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRotateDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATEDLG_H__2A49A500_BFD4_4688_89C2_E75BAD522655__INCLUDED_)
