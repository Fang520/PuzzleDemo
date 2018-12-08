// PuzzleDemoDlg.h : header file
//

#if !defined(AFX_PUZZLEDEMODLG_H__CE3333D4_C157_4CFC_9A38_044C03D8372D__INCLUDED_)
#define AFX_PUZZLEDEMODLG_H__CE3333D4_C157_4CFC_9A38_044C03D8372D__INCLUDED_

#include "Puzzle.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPuzzleDemoDlg dialog

class CPuzzleDemoDlg : public CDialog
{
// Construction
public:
	CPuzzleDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPuzzleDemoDlg)
	enum { IDD = IDD_PUZZLEDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPuzzleDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPuzzleDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReset();
	afx_msg void OnAutoLayout();
	afx_msg void OnLevel1();
	afx_msg void OnLevel2();
	afx_msg void OnLevel3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CPuzzle* m_pPuzzle;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PUZZLEDEMODLG_H__CE3333D4_C157_4CFC_9A38_044C03D8372D__INCLUDED_)
