// PuzzleDemo.h : main header file for the PUZZLEDEMO application
//

#if !defined(AFX_PUZZLEDEMO_H__5927F512_F22C_400B_9240_615E25C71B7A__INCLUDED_)
#define AFX_PUZZLEDEMO_H__5927F512_F22C_400B_9240_615E25C71B7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPuzzleDemoApp:
// See PuzzleDemo.cpp for the implementation of this class
//

class CPuzzleDemoApp : public CWinApp
{
public:
	CPuzzleDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPuzzleDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPuzzleDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PUZZLEDEMO_H__5927F512_F22C_400B_9240_615E25C71B7A__INCLUDED_)
