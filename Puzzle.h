#if !defined(AFX_PUZZLE_H__E8914B99_2315_4269_8386_60C13C4FAD67__INCLUDED_)
#define AFX_PUZZLE_H__E8914B99_2315_4269_8386_60C13C4FAD67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Puzzle.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPuzzle view

class CPuzzle : public CView
{
protected:
	CPuzzle();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPuzzle)

// Attributes
public:

// Operations
public:
	void SetLevel(int level);
	void AutoLayout();
	void Reset();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPuzzle)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPuzzle();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CPuzzle)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int* m_NumberList;
	int m_Level;
	void CheckFinish();
	void DrawPuzzle(CDC* pDC);
	void MoveCell(CPoint point);
	void GenerateRandomSequence();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PUZZLE_H__E8914B99_2315_4269_8386_60C13C4FAD67__INCLUDED_)
