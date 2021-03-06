// Puzzle.cpp : implementation file
//

#include "stdafx.h"
#include "PuzzleDemo.h"
#include "Puzzle.h"
#include "AutoLayout.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPuzzle

IMPLEMENT_DYNCREATE(CPuzzle, CView)

CPuzzle::CPuzzle()
{
	m_NumberList = NULL;
	srand((unsigned int)time(NULL));
	SetLevel(3);
	GenerateRandomSequence();
}

CPuzzle::~CPuzzle()
{
	if (m_NumberList)
	{
		free(m_NumberList);
		m_NumberList = NULL;
	}
}


BEGIN_MESSAGE_MAP(CPuzzle, CView)
	//{{AFX_MSG_MAP(CPuzzle)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPuzzle drawing

void CPuzzle::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	DrawPuzzle(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CPuzzle diagnostics

#ifdef _DEBUG
void CPuzzle::AssertValid() const
{
	CView::AssertValid();
}

void CPuzzle::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPuzzle message handlers

void CPuzzle::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	MoveCell(point);
	Invalidate();
}

void CPuzzle::Reset()
{
	GenerateRandomSequence();
	Invalidate();
}

void CPuzzle::AutoLayout()
{
	CAutoLayout al(m_NumberList, m_Level * m_Level);
	BeginWaitCursor();
	CStringList* layouts = al.LayoutBFS();
	EndWaitCursor();
	if (layouts != NULL)
	{
		POSITION pos = layouts->GetTailPosition();
		while (pos != NULL)
		{
			CString layout = layouts->GetPrev(pos);
			int* number_list = al.LayoutStringToArray(layout);
			for (int i=0; i<m_Level*m_Level; i++)
			{
				m_NumberList[i] = number_list[i];
			}
			Invalidate();
			long ts = GetTickCount();
			while (GetTickCount() - ts < 1000)
			{
				MSG msg;  
				if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
				{  
					if (msg.message == WM_QUIT)
					{
						delete layouts;
						return;
					}
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}  
			}
		}
		delete layouts;
		MessageBox("Finished");
	}
	else
	{
		MessageBox("There is no solution !");
	}
}

void CPuzzle::GenerateRandomSequence()
{
	int i, n, t;
	int len = m_Level*m_Level;

	// init list
	for (i=0; i<len; i++)
	{
		m_NumberList[i] = i + 1;
	}

	// random change the order
	for (i=len - 1; i>0; i--)
	{
		n = rand() % i;
		t = m_NumberList[i];
		m_NumberList[i] = m_NumberList[n];
		m_NumberList[n] = t;
	}
}

void CPuzzle::MoveCell(CPoint point)
{
	CRect rect;
	GetClientRect(&rect);
	int cw = rect.Width() / m_Level; //cell width
	int ch = rect.Height() / m_Level; //cell height
	int col = point.x / cw;
	int row = point.y / ch;
	int index = row * m_Level + col;

	int near_index[4];
	near_index[0] = index - m_Level;
	near_index[1] = index + m_Level;
	near_index[2] = index - 1;
	if (near_index[2] / m_Level != index / m_Level) //fix bug, if not in the same row must be ignored 
		near_index[2] = -1;
	near_index[3] = index + 1;
	if (near_index[3] / m_Level != index / m_Level)
		near_index[3] = -1;

	for (int i=0; i<4; i++)
	{
		int probe_index = near_index[i];
		if (probe_index >=0 && probe_index < m_Level*m_Level)
		{
			if (m_NumberList[probe_index] == m_Level*m_Level)
			{
				int n = m_NumberList[index];
				m_NumberList[index] = m_NumberList[probe_index];
				m_NumberList[probe_index] = n;
				CheckFinish();
			}
		}
	}
}

void CPuzzle::DrawPuzzle(CDC *pDC)
{
	CRect rect;
	GetClientRect(&rect);

	int cw = rect.Width() / m_Level; //cell width
	int ch = rect.Height() / m_Level; //cell height

	CBrush bk_brush(RGB(190, 190, 190));
	pDC->FillRect(rect, &bk_brush);

	for (int i=0; i<m_Level*m_Level; i++)
	{
		int col = i % m_Level;
		int row = i / m_Level;
		CRect rc;
		rc.left = cw * col;
		rc.top = ch * row;
		rc.right = rc.left + cw;
		rc.bottom = rc.top + ch;
		rc.DeflateRect(1, 1);
		if (m_NumberList[i] != m_Level*m_Level)
		{
			CString title;
			title.Format("%d", m_NumberList[i]);
			CBrush tmp_brush(RGB(255, 255, 255));
			pDC->FillRect(rc, &tmp_brush);
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->SetBkMode(TRANSPARENT);
			pDC->DrawText(title, rc, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		}
	}
}

void CPuzzle::CheckFinish()
{
	bool result = true;
	for (int i=0; i<m_Level*m_Level; i++)
	{
		if (m_NumberList[i] != i+1)
		{
			result = false;
			break;
		}
	}
	if (result)
	{
		MessageBox("Finished");
	}
}

void CPuzzle::SetLevel(int level)
{
	if (level < 3 || level > 9)
	{
		return;
	}
	m_Level = level;
	if (m_NumberList)
	{
		free(m_NumberList);
	}
	m_NumberList = (int*)malloc(level * level * sizeof(int));
}
